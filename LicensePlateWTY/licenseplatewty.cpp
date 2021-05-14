#include "licenseplatewty.h"

LicensePlateWTY *LicensePlateWTY::pThis=nullptr;

LicensePlateWTY::LicensePlateWTY(QObject *parent)
{
    this->setParent(parent);

    LicensePlateWTY::pThis=this;

    pDLL=nullptr;
    isSDKinit=false;
    isPlay=false;

    localAddr="";
    camerIP="";
    camerUser="";
    camerPow="";
    signature="";
    camerPort=0;
    
    linkTimer=nullptr;

    CLIENT_LPRC_RegCLIENTConnEvent=nullptr;
    CLIENT_LPRC_RegDataEx2Event=nullptr;
    CLIENT_LPRC_RegJpegEvent=nullptr;
    CLIENT_LPRC_RegWTYGetGpioState=nullptr;
    CLIENT_LPRC_RegSerialDataEvent=nullptr;
    CLIENT_LPRC_InitSDK=nullptr;
    CLIENT_LPRC_SetSavePath=nullptr;
    CLIENT_LPRC_SetTrigger=nullptr;
    CLIENT_LPRC_SetJpegStreamPlayOrStop=nullptr;
    CLIENT_LPRC_SetRelayClose=nullptr;
    CLIENT_LPRC_DropRod=nullptr;
    CLIENT_LPRC_SetNetworkCardBind=nullptr;
    CLIENT_LPRC_RS485Send=nullptr;
    CLIENT_LPRC_QuitDevice=nullptr;
    CLIENT_LPRC_QuitSDK=nullptr;
}

LicensePlateWTY::~LicensePlateWTY()
{
}

QString LicensePlateWTY::InterfaceType()
{
    return QString("WTY_PLATE");
}

bool LicensePlateWTY::initializationParameter()
{
    pDLL=new QLibrary ("WTY",this) ;/* windows*/
    //pDLL=new QLibrary (QDir::toNativeSeparators(QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("Plugins/WTY/linux/libwty")),this) ;/* linux */

    if(pDLL->load()){

        qDebug().noquote()<<QString("load WTY sucess");

        CLIENT_LPRC_RegCLIENTConnEvent=reinterpret_cast<CLIENT_LPRC_RegCLIENTConnEventFUN>(pDLL->resolve("CLIENT_LPRC_RegCLIENTConnEvent"));
        CLIENT_LPRC_RegDataEx2Event=reinterpret_cast<CLIENT_LPRC_RegDataEx2EventFUN>(pDLL->resolve("CLIENT_LPRC_RegDataEx2Event"));
        CLIENT_LPRC_RegJpegEvent=reinterpret_cast<CLIENT_LPRC_RegJpegEventFUN>(pDLL->resolve("CLIENT_LPRC_RegJpegEvent"));
        CLIENT_LPRC_RegWTYGetGpioState=reinterpret_cast<CLIENT_LPRC_RegWTYGetGpioStateFUN>(pDLL->resolve("CLIENT_LPRC_RegWTYGetGpioState"));
        CLIENT_LPRC_RegSerialDataEvent=reinterpret_cast<CLIENT_LPRC_RegSerialDataEventFUN>(pDLL->resolve("CLIENT_LPRC_RegSerialDataEvent"));
        CLIENT_LPRC_InitSDK=reinterpret_cast<CLIENT_LPRC_InitSDKFUN>(pDLL->resolve("CLIENT_LPRC_InitSDK"));
        CLIENT_LPRC_SetSavePath=reinterpret_cast<CLIENT_LPRC_SetSavePathFUN>(pDLL->resolve("CLIENT_LPRC_SetSavePath"));
        CLIENT_LPRC_SetTrigger=reinterpret_cast<CLIENT_LPRC_SetTriggerFUN>(pDLL->resolve("CLIENT_LPRC_SetTrigger"));
        CLIENT_LPRC_SetJpegStreamPlayOrStop=reinterpret_cast<CLIENT_LPRC_SetJpegStreamPlayOrStopFUN>(pDLL->resolve("CLIENT_LPRC_SetJpegStreamPlayOrStop"));
        CLIENT_LPRC_SetRelayClose=reinterpret_cast<CLIENT_LPRC_SetRelayCloseFUN>(pDLL->resolve("CLIENT_LPRC_SetRelayClose"));
        CLIENT_LPRC_DropRod=reinterpret_cast<CLIENT_LPRC_DropRodFUN>(pDLL->resolve("CLIENT_LPRC_DropRod"));
        CLIENT_LPRC_SetNetworkCardBind=reinterpret_cast<CLIENT_LPRC_SetNetworkCardBindFUN>(pDLL->resolve("CLIENT_LPRC_SetNetworkCardBind"));
        CLIENT_LPRC_RS485Send=reinterpret_cast<CLIENT_LPRC_RS485SendFUN>(pDLL->resolve("CLIENT_LPRC_RS485Send"));
        CLIENT_LPRC_QuitDevice=reinterpret_cast<CLIENT_LPRC_QuitDeviceFUN>(pDLL->resolve("CLIENT_LPRC_QuitDevice"));
        CLIENT_LPRC_QuitSDK=reinterpret_cast<CLIENT_LPRC_QuitSDKFUN>(pDLL->resolve("CLIENT_LPRC_QuitSDK"));

        CLIENT_LPRC_RegCLIENTConnEvent(LicensePlateWTY::connectCallback);
        CLIENT_LPRC_RegDataEx2Event(LicensePlateWTY::dataEx2Callback);
        CLIENT_LPRC_RegJpegEvent(LicensePlateWTY::jpegCallback);
        CLIENT_LPRC_RegWTYGetGpioState(LicensePlateWTY::getGpioStateCallback);
        CLIENT_LPRC_RegSerialDataEvent(LicensePlateWTY::serialDataCallback);
        
        linkTimer=new QTimer(this);
        linkTimer->setSingleShot(false);
        connect(linkTimer,SIGNAL(timeout()),this,SLOT(autoLinkCamer()));
        
        qDebug().noquote()<<QString("WTY Load sucess");
        return true;
    }

    qWarning().noquote()<<QString("WTY Load error<errorCode=%1>").arg(pDLL->errorString());

    return  false;
}

void LicensePlateWTY::initCamerSlot(const QString &localAddr, const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &signature)
{
    if(!isSDKinit){
        if(!initializationParameter()){
            return;
        }
        isSDKinit=true;
    }

    if(camerIP.isEmpty() || camerIP=="..."){
        return;
    }

    this->localAddr=localAddr;
    this->camerPort=camerPort;
    this->camerIP=camerIP;
    this->camerUser=CamerUser;
    this->camerPow=CamerPow;
    this->signature=signature;

    arrAddr=localAddr.toLatin1();
    if(CLIENT_LPRC_SetNetworkCardBind(arrAddr.data())==0){
        qDebug().noquote()<<QString("IP:%1 Bind network card successfully %2").arg(camerIP).arg(localAddr);
    }
    else {
        qWarning().noquote()<<QString("IP:%1 Failed to bind network card %2").arg(camerIP).arg(localAddr);
    }

    arrAddr=camerIP.toLatin1();
    if(CLIENT_LPRC_InitSDK(static_cast<uint>(camerPort),nullptr,0,arrAddr.data(),0)==0){
        qDebug().noquote()<<QString("IP:%1 License plate camera link successful").arg(camerIP);
    }
    else {
        qWarning().noquote()<<QString("IP:%1 License plate camera link error").arg(camerIP);
        linkTimer->start(15000);
    }
}

void LicensePlateWTY::autoLinkCamer()
{
    if(isSDKinit){
        /*****************************
        * @brief:链接失败重新链接
        ******************************/
        if(CLIENT_LPRC_InitSDK(static_cast<uint>(camerPort),nullptr,0,arrAddr.data(),0)==1){
            qDebug().noquote()<<QString("IP:%1 License plate camera linking").arg(camerIP);
        }
        else {
            pThis->linkTimer->stop();
            qDebug().noquote()<<QString("IP:%1 License plate camera link successful").arg(camerIP);
        }
    }
}


void LicensePlateWTY::connectCallback(char *chWTYIP, UINT nStatus, LDWORD dwUser)
{
    Q_UNUSED(dwUser);

    emit pThis->equipmentStateSignal(QString::fromUtf8(chWTYIP),nStatus?true:false);

    if(1!=nStatus){
        if(pThis->CLIENT_LPRC_QuitDevice!=nullptr){
            pThis->CLIENT_LPRC_QuitDevice(pThis->arrAddr.data());
        }
        pThis->linkTimer->start(10000);
        qWarning().noquote()<<QString("IP:%1 License plate camera link error").arg(pThis->camerIP);
    }
}

void LicensePlateWTY::dataEx2Callback(CLIENT_LPRC_PLATE_RESULTEX *recResultEx, LDWORD dwUser)
{
    Q_UNUSED(dwUser);

    QByteArray arrImg(reinterpret_cast<const char*>(recResultEx->pFullImage.pBuffer),recResultEx->pFullImage.nLen);

    /* 车牌相机时间，部分出现异常 */
    //QString dateTime= QString("%1-%2-%3 %4:%5:%6").arg(recResultEx->shootTime.Year).arg(recResultEx->shootTime.Month).arg(recResultEx->shootTime.Day).arg(recResultEx->shootTime.Hour).arg(recResultEx->shootTime.Minute).arg(recResultEx->shootTime.Second);

    /* 系统时间 */
    QString dateTime=QDateTime::currentDateTime().toString("yyyy-M-d h:m:s");
    qDebug().noquote()<<QString("License Plate recognition results:%1-%2").arg(QString::fromLocal8Bit(recResultEx->chLicense)).arg(dateTime);

    emit pThis->resultsTheLicensePlateSignal(QString::fromLocal8Bit(recResultEx->chLicense),QString::fromLocal8Bit(recResultEx->chColor),dateTime,arrImg);
    emit pThis->imageFlowSignal(arrImg);

    arrImg.clear();
}

void LicensePlateWTY::jpegCallback(CLIENT_LPRC_DEVDATA_INFO *JpegInfo, LDWORD dwUser)
{
    Q_UNUSED(dwUser);

    QCoreApplication::processEvents();

    if(pThis->isPlay){
        QThread::msleep(200);
        if(strcmp(JpegInfo->chIp,pThis->arrAddr.data())==0 && JpegInfo->nStatus==0 && JpegInfo->nLen>0){
            QByteArray arrImg(reinterpret_cast<const char*>(JpegInfo->pchBuf),JpegInfo->nLen);
            emit pThis->theVideoStreamSignal(arrImg);
            arrImg.clear();
        }
    }
}

void LicensePlateWTY::getGpioStateCallback(char *chWTYIP, CLIENT_LPRC_GPIO_In_Statue *pGpioState)
{
    Q_UNUSED(chWTYIP);
    Q_UNUSED(pGpioState);
}

void LicensePlateWTY::serialDataCallback(char *chCLIENTIP, CLIENT_LPRC_DEVSERIAL_DATA *pSerialData, LDWORD dwUser)
{
    Q_UNUSED(chCLIENTIP);
    Q_UNUSED(pSerialData);
    Q_UNUSED(dwUser);
}

void LicensePlateWTY::simulationCaptureSlot()
{
    if(CLIENT_LPRC_SetTrigger!=nullptr && CLIENT_LPRC_SetTrigger(arrAddr.data(),camerPort)==0){
        qDebug().noquote()<<QString("IP:%1 The simulated snapshot was successful").arg(camerIP);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Simulation capture failed").arg(camerIP);
    }
}

void LicensePlateWTY::liftingElectronicRailingSlot(bool gate)
{
    if(gate){
        CLIENT_LPRC_SetRelayClose(arrAddr.data(),9110);
    }
    else {
        CLIENT_LPRC_DropRod(arrAddr.data(),9110);
    }
}

void LicensePlateWTY::transparentTransmission485Slot(const QString &msg)
{
    QByteArray arrMsg=msg.toLatin1();
    if(CLIENT_LPRC_RS485Send!=nullptr && CLIENT_LPRC_RS485Send(arrAddr.data(),9110,arrMsg.data(),arrMsg.length())==0){
        qDebug().noquote()<<QString("IP:%1 485 data forwarding was successful").arg(camerIP);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 485 data forwarding was successful").arg(camerIP);
    }
}

void LicensePlateWTY::openTheVideoSlot(bool play,quint64 winID)
{
    Q_UNUSED(winID);

    isPlay=play;

    /*****************************
    * @brief:最新版本不支持关闭流
    ******************************/
    if(CLIENT_LPRC_SetJpegStreamPlayOrStop!=nullptr && CLIENT_LPRC_SetJpegStreamPlayOrStop(arrAddr.data(),play?1:0)==0){
        qDebug().noquote()<<QString("IP:%1 Video streaming operation successful").arg(camerIP);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Video streaming operation error").arg(camerIP);
    }
}

void LicensePlateWTY::releaseResourcesSlot()
{
    if(linkTimer!=nullptr){
        //linkTimer->setSingleShot(true);
        linkTimer->stop();
    }

    if(CLIENT_LPRC_QuitDevice!=nullptr){
        //CLIENT_LPRC_QuitDevice(arrAddr.data());
        CLIENT_LPRC_QuitSDK();
    }
    
//    if(pDLL!=nullptr){
//        pDLL->unload();
//    }
    
    qDebug().noquote()<<QString("LicensePlateWTY::releaseResourcesSlot");
}

/*****************************
* @brief:海康相机其它实现
******************************/

void LicensePlateWTY::slot_pictureStream(int ID, QByteArray arrJpg)
{
    Q_UNUSED(ID);
    Q_UNUSED(arrJpg);
}

void LicensePlateWTY::slot_setCameraID(int ID, QString cameraIP)
{
    Q_UNUSED(ID);
    Q_UNUSED(cameraIP);
}

void LicensePlateWTY::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time,const QByteArray &arrImg)
{
    Q_UNUSED(ID);
    Q_UNUSED(plate);
    Q_UNUSED(color);
    Q_UNUSED(time);
    Q_UNUSED(arrImg);
}

void LicensePlateWTY::slot_equipmentState(int ID, bool state)
{
    Q_UNUSED(ID);
    Q_UNUSED(state);
}
