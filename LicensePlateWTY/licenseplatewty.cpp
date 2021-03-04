#include "licenseplatewty.h"

LicensePlateWTY *LicensePlateWTY::pThis=nullptr;
bool LicensePlateWTY::complate=false;

LicensePlateWTY::LicensePlateWTY(QObject *parent)
{
    this->setParent(parent);

    LicensePlateWTY::pThis=this;

    pDLL=nullptr;
    isSDKinit=false;
    address="";
    port=0;
    channel=0;
    imgPath="";
    arrAddr="";

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
}

LicensePlateWTY::~LicensePlateWTY()
{
    LicensePlateWTY::pThis=nullptr;

    if(pDLL!=nullptr && pDLL->isLoaded()){
        pDLL->unload();
        delete pDLL;
        pDLL=nullptr;
    }
}

QString LicensePlateWTY::InterfaceType()
{
    return QString("WTY");
}

bool LicensePlateWTY::initializationParameter()
{
    pDLL=new QLibrary ("WTY",this) ;/* windows*/
    //pDLL=new QLibrary (QDir::toNativeSeparators(QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("Plugins/WTY/linux/libwty")),this) ;/* linux */
    if(pDLL->load()){
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

        emit messageSignal(ZBY_LOG("INFO"),"WTY Load sucessful");
        return true;
    }
    emit messageSignal(ZBY_LOG("ERROR"),QString("WTY Load error<errorCode=%1>").arg(pDLL->errorString()));
    delete pDLL;
    pDLL=nullptr;

    return  false;
}

void initCamerSlot(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)
{
    if(!isSDKinit){
        if(!initializationParameter()){
            return;
        }
        this->address=addr;
        this->port=port;
        this->imgPath=imgPath;
        this->channel=channel;
        this->imgFormat=imgFormat;

        CLIENT_LPRC_RegCLIENTConnEvent(LicensePlateWTY::connectCallback);
        CLIENT_LPRC_RegDataEx2Event(LicensePlateWTY::dataEx2Callback);
        CLIENT_LPRC_RegJpegEvent(LicensePlateWTY::jpegCallback);
        CLIENT_LPRC_RegWTYGetGpioState(LicensePlateWTY::getGpioStateCallback);
        CLIENT_LPRC_RegSerialDataEvent(LicensePlateWTY::serialDataCallback);

        //QByteArray arr=imgPath.toLatin1();
        //CLIENT_LPRC_SetSavePath(arr.data());

        arrAddr=localAddr.toLatin1();
        if(CLIENT_LPRC_SetNetworkCardBind(arrAddr.data())==0){
            messageSignal(ZBY_LOG("INFO"),tr("IP:%1 Bind network card successfully %2").arg(address).arg(localAddr));
        }
        else {
            messageSignal(ZBY_LOG("ERROR"),tr("Failed to bind network card"));
        }

        isSDKinit=true;
        arrAddr=addr.toLatin1();
        if(CLIENT_LPRC_InitSDK(static_cast<uint>(port),nullptr,0,arrAddr.data(),0)==0){
            messageSignal(ZBY_LOG("INFO"),tr("IP:%1 License plate camera link successful").arg(addr));
        }
        else {
            messageSignal(ZBY_LOG("ERROR"),QString("IP:%1 License plate camera link error").arg(addr));
        }
    }
}

void LicensePlateWTY::autoLinkCamer()
{
    if(isSDKinit){
        /*****************************
        * @brief:链接失败重新链接
        ******************************/
        CLIENT_LPRC_InitSDK(static_cast<uint>(port),nullptr,0,arrAddr.data(),0);
    }
}


void LicensePlateWTY::connectCallback(char *chWTYIP, UINT nStatus, LDWORD dwUser)
{
    bool state=false;
    if(nStatus==1){
        state=true;
    }
    emit pThis->equipmentStateSignal(state);

    if(!state){
        QTimer::singleShot(10000,pThis,SLOT(autoLinkCamer()));
    }
}

void LicensePlateWTY::dataEx2Callback(CLIENT_LPRC_PLATE_RESULTEX *recResultEx, LDWORD dwUser)
{
    QByteArray arrImg(reinterpret_cast<const char*>(recResultEx->pFullImage.pBuffer),recResultEx->pFullImage.nLen);

    /* 车牌相机时间，部分出现异常 */
    //QString dateTime= QString("%1-%2-%3 %4:%5:%6").arg(recResultEx->shootTime.Year).arg(recResultEx->shootTime.Month).arg(recResultEx->shootTime.Day).arg(recResultEx->shootTime.Hour).arg(recResultEx->shootTime.Minute).arg(recResultEx->shootTime.Second);

    /* 系统时间 */
    QString dateTime=QDateTime::currentDateTime().toString("yyyy-M-d h:m:s");

    emit pThis->resultsTheLicensePlateSignal(QString::fromLocal8Bit(recResultEx->chLicense),QString::fromLocal8Bit(recResultEx->chColor),dateTime,arrImg);
    emit pThis->messageSignal(ZBY_LOG("INFO"),tr("License Plate recognition results:%1-%2").arg(QString::fromLocal8Bit(recResultEx->chLicense)).arg(dateTime));

    pThis->saveImg(arrImg,dateTime);
    arrImg.clear();
}

void LicensePlateWTY::jpegCallback(CLIENT_LPRC_DEVDATA_INFO *JpegInfo, LDWORD dwUser)
{
    QThread::msleep(20);
    if(strcmp(JpegInfo->chIp,pThis->arrAddr.data())==0 && JpegInfo->nStatus==0 && JpegInfo->nLen>0){
        QByteArray arrImg(reinterpret_cast<const char*>(JpegInfo->pchBuf),JpegInfo->nLen);
        emit pThis->theVideoStreamSignal(arrImg);
        arrImg.clear();
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
    if(CLIENT_LPRC_SetTrigger!=nullptr && CLIENT_LPRC_SetTrigger(arrAddr.data(),port)==0){
        qDebug().noquote()<<QString("IP:%1 The simulated snapshot was successful").arg(address);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Simulation capture failed").arg(address);
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
        qDebug().noquote()<<QString("IP:%1 485 data forwarding was successful").arg(address);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 485 data forwarding was successful").arg(address);
    }
}

void LicensePlateWTY::openTheVideoSlot(bool play,quint64 winID)
{
    Q_UNUSED(winID);

    if(CLIENT_LPRC_SetJpegStreamPlayOrStop!=nullptr && CLIENT_LPRC_SetJpegStreamPlayOrStop(arrAddr.data(),play?1:0)==0){
        qDebug().noquote()<<QString("IP:%1 Video streaming operation successful").arg(address);
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Video streaming operation error").arg(address);
    }
}

void LicensePlateWTY::releaseResourcesSlot()
{
    if(CLIENT_LPRC_QuitDevice!=nullptr){
        CLIENT_LPRC_QuitDevice(arrAddr.data());
    }
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
