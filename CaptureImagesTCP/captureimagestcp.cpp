#include "captureimagestcp.h"

CaptureImagesTCP::CaptureImagesTCP(QObject *parent)
{
    this->setParent(parent);
    tcpSocket=nullptr;
    pTimerLinkCamer=nullptr;
    pPutCommand=nullptr;
}

CaptureImagesTCP::~CaptureImagesTCP()
{
    delete tcpSocket;
    delete pTimerLinkCamer;
    delete pPutCommand;

    tcpSocket=nullptr;
    pTimerLinkCamer=nullptr;
    pPutCommand=nullptr;
}

void CaptureImagesTCP::connected()
{
    qInfo()<<tr("IP:%1 Camera Link Success").arg(camerIP);

    emit camerStateSingal(camerIP,true,alias);

    if(pTimerLinkCamer->isActive())    /* 防止出现链接完成后,物理线路断开 */
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(25000);
}

void CaptureImagesTCP::readFortune()
{
    if(pTimerLinkCamer->isActive())
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(20000);

    tcpSocket = qobject_cast<QTcpSocket*>(sender());
    QByteArray tmpStream = tcpSocket->readAll();
    if(tmpStream!="\x00")
    {
        jpgStream.append(tmpStream);
    }
    /* 找到结尾标记 */
    int end=jpgStream.lastIndexOf("\xFF\xD9");
    if(end!=-1)
    {
        /* 找到开头标记 */
        int start=jpgStream.indexOf("\xFF\xD8");
        if(start!=-1)
        {
            jpgStream=jpgStream.mid(start,end-start+2);
            emit pictureStreamSignal(jpgStream,imgNumber,imgTime);

            qInfo()<< tr("IP:%1 Get Camera Image Data").arg(camerIP);

            QThread::msleep(10);
        }
        else {
            emit pictureStreamSignal(nullptr,imgNumber,imgTime);
        }
        jpgStream.clear();
    }
//    else {
//        emit pictureStreamSignal(nullptr,imgNumber,imgTime);
//    }
}

void CaptureImagesTCP::disconnected()
{
    emit camerStateSingal(camerIP,false,alias);

    qWarning()<<tr("%1 Camera Disconnected").arg(camerIP);
}

void CaptureImagesTCP::displayError(QAbstractSocket::SocketError socketError)
{
    qWarning()<<tr("IP:%1 Camera Link Error<errorCode=%2>").arg(camerIP).arg(socketError);

    if(pTimerLinkCamer->isActive())
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(20000);
}

void CaptureImagesTCP::startLinkCamer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(camerIP,static_cast<quint16>(camerPort));
    pPutCommand->linktoServerSlot(camerIP,23000);
}

void CaptureImagesTCP::initCamerSlot(const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &alias)
{
    Q_UNUSED(CamerUser);
    Q_UNUSED(CamerPow);

    this->camerIP=camerIP;
    this->camerPort=camerPort;
    this->alias=alias;

    startLinkCamer();
}

bool CaptureImagesTCP::putCommandSlot(const int &imgNumber, const QString &imgTime)
{
    this->imgNumber=imgNumber;
    this->imgTime=imgTime;

    return  pPutCommand->putCommandSlot();
}

void CaptureImagesTCP::releaseResourcesSlot()
{
    if(pTimerLinkCamer !=nullptr && pTimerLinkCamer->isActive()){
        pTimerLinkCamer->stop();
    }
}

void CaptureImagesTCP::InitializationSlot()
{
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QIODevice::readyRead,this,&CaptureImagesTCP::readFortune);
    connect(tcpSocket,&QAbstractSocket::connected,this,&CaptureImagesTCP::connected);
    connect(tcpSocket,&QAbstractSocket::disconnected,this,&CaptureImagesTCP::disconnected);
    //connect(tcpSocket,&QAbstractSocket::stateChanged,this,&UnderlyingGetImages::stateChanged);
    connect(tcpSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&CaptureImagesTCP::displayError);

    pTimerLinkCamer=new QTimer (this);
    connect(pTimerLinkCamer,&QTimer::timeout,this,&CaptureImagesTCP::startLinkCamer);

    pPutCommand=new PutCommand (this);
}
