#include "captureunderlying.h"

CaptureUnderlying::CaptureUnderlying(QObject *parent)
{
    this->setParent(parent);
    tcpSocket=nullptr;
    pTimerLinkCamer=nullptr;
    pPutCommand=nullptr;

    streamState=false;
    putState=false;
    ID=-1;
}

CaptureUnderlying::~CaptureUnderlying()
{
    qDebug().noquote()<<"~CaptureUnderlying";
}

QString CaptureUnderlying::InterfaceType()
{
    return "Underlying";
}

void CaptureUnderlying::connected()
{
    qDebug().noquote()<<QString("IP:%1 Camera Link Success").arg(camerIP);

    ID=tcpSocket->localPort();
    if(0==ID){
        ID=-1;
    }
    emit signal_setCameraID(ID,camerIP);
    emit equipmentStateSignal(ID,true);

    if(pTimerLinkCamer->isActive())    /* 防止出现链接完成后,物理线路断开 */
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(15000);
}

void CaptureUnderlying::readFortune()
{    
    if(pTimerLinkCamer->isActive())
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(10000);

    if(!putState){
        /*****************************
        * @brief: 不是当前库抓拍，不处理。防止同一相机多次接收
        ******************************/
        tcpSocket->readAll().clear();
        return;
    }

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
            emit signal_pictureStream(ID,jpgStream);
            putState=false;
            jpgStream.clear();
            //QThread::msleep(10);

            qDebug().noquote()<<QString("IP:%1 Get Camera Image Data").arg(camerIP);
        }
        else {
            emit signal_pictureStream(ID,nullptr);
            putState=false;
        }       
    }

    if(tmpStream.count()>1){
        /*****************************
        * @brief: 防止相机异常，没有结果输出
        ******************************/
         streamState=true;
    }
    //tmpStream.clear();
    //qDebug().noquote()<<"Get camera stream:"<<tmpStream.count();
}

void CaptureUnderlying::disconnected()
{
    emit equipmentStateSignal(ID,false);
    qWarning().noquote()<<QString("%1 Camera Disconnected").arg(camerIP);
}

void CaptureUnderlying::displayError(QAbstractSocket::SocketError socketError)
{
    emit equipmentStateSignal(ID,false);
    qWarning().noquote()<<QString("IP:%1 Camera Link Error<errorCode=%2>").arg(camerIP).arg(socketError);

    if(pTimerLinkCamer->isActive())
    {
        pTimerLinkCamer->stop();
    }
    pTimerLinkCamer->start(20000);
}

void CaptureUnderlying::startLinkCamer()
{
    if(tcpSocket->state()==QAbstractSocket:: UnconnectedState){
        tcpSocket->close();
        tcpSocket->abort();
        tcpSocket->connectToHost(camerIP,static_cast<quint16>(camerPort));
        pPutCommand->linktoServerSlot(camerIP,23000);
    }
}

void CaptureUnderlying::cameraState()
{
    if(!streamState)
    {
        /*****************************
        * @brief:保证流程完成
        ******************************/
        emit signal_pictureStream(ID,nullptr);
        if(pTimerLinkCamer->isActive()){
            pTimerLinkCamer->stop();
        }
        tcpSocket->close();
        tcpSocket->abort();
        startLinkCamer();
    }
}

void CaptureUnderlying::initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow)
{
    Q_UNUSED(localAddr);
    Q_UNUSED(user);
    Q_UNUSED(pow);
    Q_UNUSED(port);
    
    this->camerIP=addr;
    this->camerPort=23001;

    initialization();
    startLinkCamer();
}

void CaptureUnderlying::setCaptureTypeSlot(const int &capType,const int &msgCallBackInd)
{
    Q_UNUSED(capType);
    Q_UNUSED(msgCallBackInd);
}

void CaptureUnderlying::openTheVideoSlot(int ID, bool play, quint64 winID)
{
    Q_UNUSED(ID);
    Q_UNUSED(play);
    Q_UNUSED(winID);
}

void CaptureUnderlying::simulationCaptureSlot(int ID)
{
    putState=true;
    streamState=false;
    jpgStream.clear();

    if(!pPutCommand->putCommandSlot())
    {
        /*****************************
        * @brief:保证流程完成
        ******************************/
        emit signal_pictureStream(ID,nullptr);
        return;
    }

    QTimer::singleShot(1500,this,SLOT(cameraState()));
}

void CaptureUnderlying::liftingElectronicRailingSlot(bool gate)
{
    Q_UNUSED(gate);
}

void CaptureUnderlying::transparentTransmission485Slot(const QString &msg)
{
    Q_UNUSED(msg);
}

void CaptureUnderlying::releaseResourcesSlot()
{
    if(pTimerLinkCamer !=nullptr && pTimerLinkCamer->isActive()){
        pTimerLinkCamer->stop();
    }
    if(nullptr != tcpSocket){
        tcpSocket->close();
        tcpSocket->abort();
    }
    delete tcpSocket;
    delete pTimerLinkCamer;
    delete pPutCommand;
}

void CaptureUnderlying::initialization()
{
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QIODevice::readyRead,this,&CaptureUnderlying::readFortune);
    connect(tcpSocket,&QAbstractSocket::connected,this,&CaptureUnderlying::connected);
    connect(tcpSocket,&QAbstractSocket::disconnected,this,&CaptureUnderlying::disconnected);
    //connect(tcpSocket,&QAbstractSocket::stateChanged,this,&UnderlyingGetImages::stateChanged);
    connect(tcpSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&CaptureUnderlying::displayError);

    pTimerLinkCamer=new QTimer (this);
    connect(pTimerLinkCamer,&QTimer::timeout,this,&CaptureUnderlying::startLinkCamer);

    pPutCommand=new PutCommand (this);
}
