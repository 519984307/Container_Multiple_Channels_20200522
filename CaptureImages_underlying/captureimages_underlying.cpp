#include "captureimages_underlying.h"

CaptureImages_underlying::CaptureImages_underlying(QObject *parent)
{
    this->setParent(parent);
    tcpSocket=nullptr;
    pTimerLinkCamer=nullptr;
    pPutCommand=nullptr;
}

CaptureImages_underlying::~CaptureImages_underlying()
{
    delete  tcpSocket;
    delete pTimerLinkCamer;
    delete pPutCommand;
}

void CaptureImages_underlying::connected()
{
    emit messageSignal(ZBY_LOG("INFO"), tr("IP:%1 Camera Link Success").arg(camerIP));
    emit camerStateSingal(camerIP,true,alias);

    if(pTimerLinkCamer->isActive())    /* 防止出现链接完成后,物理线路断开 */
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(25000);
}

void CaptureImages_underlying::readFortune()
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
            emit messageSignal(ZBY_LOG("INFO"), tr("IP:%1 Get Camera Image Data").arg(camerIP));
            emit pictureStreamSignal(jpgStream,imgNumber,imgTime);
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

void CaptureImages_underlying::disconnected()
{
    emit camerStateSingal(camerIP,false,alias);
    emit messageSignal(ZBY_LOG("ERROR") ,tr("%1 Camera Disconnected").arg(camerIP));
}

void CaptureImages_underlying::displayError(QAbstractSocket::SocketError socketError)
{
    emit messageSignal(ZBY_LOG("ERROR"), tr("IP:%1 Camera Link Error<errorCode=%2>").arg(camerIP).arg(socketError));

    if(pTimerLinkCamer->isActive())
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(20000);
}

void CaptureImages_underlying::startLinkCamer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(camerIP,static_cast<quint16>(camerPort));
    pPutCommand->linktoServerSlot(camerIP,23000);
}

void CaptureImages_underlying::initCamerSlot(const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &alias)
{
    this->camerIP=camerIP;
    this->camerPort=camerPort;
    this->alias=alias;

    startLinkCamer();
}

bool CaptureImages_underlying::putCommandSlot(const int &imgNumber, const QString &imgTime)
{
    this->imgNumber=imgNumber;
    this->imgTime=imgTime;

    emit messageSignal(ZBY_LOG("DEBUG"),"capture 01");
    return  pPutCommand->putCommandSlot();
}

void CaptureImages_underlying::releaseResourcesSlot()
{
    if(pTimerLinkCamer !=nullptr && pTimerLinkCamer->isActive()){
        pTimerLinkCamer->stop();
    }
}

void CaptureImages_underlying::InitializationSlot()
{
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QIODevice::readyRead,this,&CaptureImages_underlying::readFortune);
    connect(tcpSocket,&QAbstractSocket::connected,this,&CaptureImages_underlying::connected);
    connect(tcpSocket,&QAbstractSocket::disconnected,this,&CaptureImages_underlying::disconnected);
    //connect(tcpSocket,&QAbstractSocket::stateChanged,this,&UnderlyingGetImages::stateChanged);
    connect(tcpSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&CaptureImages_underlying::displayError);

    pTimerLinkCamer=new QTimer (this);
    connect(pTimerLinkCamer,&QTimer::timeout,this,&CaptureImages_underlying::startLinkCamer);

    pPutCommand=new PutCommand (this);
}
