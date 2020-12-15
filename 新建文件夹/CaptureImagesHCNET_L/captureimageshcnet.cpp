#include "captureimageshcnet.h"

CaptureImagesHCNET* CaptureImagesHCNET::pThis=nullptr;

CaptureImagesHCNET::CaptureImagesHCNET(QObject *parent)
{
    this->setParent(parent);

    lUserID=-1;
    streamID=-1;
    dwResult=0;

    isSDKInit=false;

    CaptureImagesHCNET::pThis=this;
    pDLL=nullptr;
    pTimerCameraState=nullptr;

    NET_DVR_SetExceptionCallBack_V30_L=nullptr;
    NET_DVR_SetSDKInitCfg_L=nullptr;
    NET_DVR_Cleanup_L=nullptr;
    NET_DVR_Init_L=nullptr;
    NET_DVR_Login_V40_L=nullptr;
    NET_DVR_Logout_L=nullptr;
    NET_DVR_ChangeWndResolution_L=nullptr;
    NET_DVR_CaptureJPEGPicture_NEW_L=nullptr;
    NET_DVR_RealPlay_V40_L=nullptr;
    NET_DVR_GetLastError_L=nullptr;
    NET_DVR_SetLogToFile_L=nullptr;
    NET_DVR_GetLocalIP_L=nullptr;
    NET_DVR_SetValidIP_L=nullptr;
    NET_DVR_StopRealPlay_L=nullptr;
    NET_DVR_RemoteControl_L=nullptr;
    NET_DVR_GetRealPlayerIndex_L=nullptr;
    NET_DVR_SetConnectTime_L=nullptr;
    NET_DVR_SetRecvTimeOut_L=nullptr;    
    NET_DVR_CaptureJPEGPicture_L=nullptr;

    /*****************************
    * @brief:交通系列
    ******************************/
    NET_DVR_SetupAlarmChan_V41_L=nullptr;
    NET_DVR_CloseAlarmChan_V30_L=nullptr;
    NET_DVR_SetDVRMessageCallBack_V31_L=nullptr;
    NET_DVR_ContinuousShoot_L=nullptr;
    NET_DVR_ManualSnap_L=nullptr;
}

CaptureImagesHCNET::~CaptureImagesHCNET()
{
    CaptureImagesHCNET::pThis=nullptr;

    if(pDLL!=nullptr){
        pDLL->unload();
        delete pDLL;
        pDLL=nullptr;
    }
}

void CaptureImagesHCNET::releaseResourcesSlot()
{
    if(nullptr!=NET_DVR_SetConnectTime_L){
        /*****************************
        * @brief:设置网络连接超时时间和连接尝试次数,防止相机重连,阻止程序退出
        ******************************/
         NET_DVR_SetConnectTime_L(75000,0);
    }

    if(nullptr!=pTimerCameraState){
         pTimerCameraState->stop();
         delete  pTimerCameraState;
         pTimerCameraState=nullptr;
    }

    if(-1!=lUserID){
        if(-1!=streamID && nullptr!=NET_DVR_StopRealPlay_L){
            NET_DVR_StopRealPlay_L(streamID);
        }
        if(nullptr!=NET_DVR_Logout_L){
            NET_DVR_Logout_L(lUserID);
        }
    }

    if(NET_DVR_Cleanup_L!=nullptr){
        NET_DVR_Cleanup_L();
    }
}

void CaptureImagesHCNET::exceptionCallBack_V30(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
    Q_UNUSED(dwType);
    Q_UNUSED(lUserID);
    Q_UNUSED(lHandle);
    Q_UNUSED(pUser);
    
    QByteArray msg=tr("Camrea:%1 exception<errorCode=%2>").arg(pThis->camerIp).arg(QString::number(pThis->NET_DVR_GetLastError_L())).toLocal8Bit();
    qWarning("%s", msg.data());
}

void CaptureImagesHCNET::loginResultCallBack(LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo, void *pUser)
{
    Q_UNUSED(lpDeviceInfo);
    Q_UNUSED(pUser);

    if(0==dwResult){
        QByteArray msg=tr("IP=%1 Camera login error<errorCode=%2>").arg(pThis->camerIp).arg(pThis->NET_DVR_GetLastError_L()).toLocal8Bit();
        qWarning("%s",msg.data());
    }
    else if (1==dwResult) {
        pThis->lUserID=lUserID;
        pThis->dwResult=dwResult;

        QByteArray msg=tr("IP=%1 Camera login sucess").arg(pThis->camerIp).toLocal8Bit();
        qInfo("%s",msg.data());
    }
}

bool CaptureImagesHCNET::InitializationParameter()
{

#ifdef Q_OS_WIN
    pDLL=new QLibrary("HCNetSDK.dll",this);/* windows下不支持设置动态库路径 */
#endif

#ifdef Q_OS_LINUX
    pDLL=new QLibrary (QDir::toNativeSeparators(QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("Plugins/HCNetSDK/libhcnetsdk")),this) ;
#endif

    if(pDLL->load()){
        NET_DVR_SetExceptionCallBack_V30_L=reinterpret_cast<NET_DVR_SetExceptionCallBack_V30FUN>(pDLL->resolve("NET_DVR_SetExceptionCallBack_V30"));
        NET_DVR_SetSDKInitCfg_L=reinterpret_cast<NET_DVR_SetSDKInitCfgFUN>(pDLL->resolve("NET_DVR_SetSDKInitCfg"));
        NET_DVR_Cleanup_L=reinterpret_cast<NET_DVR_CleanupFUN>(pDLL->resolve("NET_DVR_Cleanup"));
        NET_DVR_Init_L=reinterpret_cast<NET_DVR_InitFUN>(pDLL->resolve("NET_DVR_Init"));
        NET_DVR_Login_V40_L=reinterpret_cast<NET_DVR_Login_V40FUN>(pDLL->resolve("NET_DVR_Login_V40"));
        NET_DVR_Logout_L=reinterpret_cast<NET_DVR_LogoutFUN>(pDLL->resolve("NET_DVR_Logout"));
        NET_DVR_ChangeWndResolution_L=reinterpret_cast<NET_DVR_ChangeWndResolutionFUN>(pDLL->resolve("NET_DVR_ChangeWndResolution"));
        NET_DVR_CaptureJPEGPicture_NEW_L=reinterpret_cast<NET_DVR_CaptureJPEGPicture_NEWFUN>(pDLL->resolve("NET_DVR_CaptureJPEGPicture_NEW"));
        NET_DVR_RealPlay_V40_L=reinterpret_cast<NET_DVR_RealPlay_V40FUN>(pDLL->resolve("NET_DVR_RealPlay_V40"));
        NET_DVR_GetLastError_L=reinterpret_cast<NET_DVR_GetLastErrorFUN>(pDLL->resolve("NET_DVR_GetLastError"));
        NET_DVR_SetLogToFile_L=reinterpret_cast<NET_DVR_SetLogToFileFUN>(pDLL->resolve("NET_DVR_SetLogToFile"));
        NET_DVR_GetLocalIP_L=reinterpret_cast<NET_DVR_GetLocalIPFUN>(pDLL->resolve("NET_DVR_GetLocalIP"));
        NET_DVR_SetValidIP_L=reinterpret_cast<NET_DVR_SetValidIPFUN>(pDLL->resolve("NET_DVR_SetValidIP"));
        NET_DVR_StopRealPlay_L=reinterpret_cast<NET_DVR_StopRealPlayFUN>(pDLL->resolve("NET_DVR_StopRealPlay"));
        NET_DVR_RemoteControl_L=reinterpret_cast<NET_DVR_RemoteControlFUN>(pDLL->resolve("NET_DVR_RemoteControl"));
        NET_DVR_GetRealPlayerIndex_L=reinterpret_cast<NET_DVR_GetRealPlayerIndexFUN>(pDLL->resolve("NET_DVR_GetRealPlayerIndex"));
        NET_DVR_SetConnectTime_L=reinterpret_cast<NET_DVR_SetConnectTimeFUN>(pDLL->resolve("NET_DVR_SetConnectTime"));
        NET_DVR_SetReconnect_L=reinterpret_cast<NET_DVR_SetReconnectFUN>(pDLL->resolve("NET_DVR_SetReconnect"));
        NET_DVR_SetRecvTimeOut_L=reinterpret_cast<NET_DVR_SetRecvTimeOutFUN>(pDLL->resolve("NET_DVR_SetRecvTimeOut"));

        if(nullptr==pTimerCameraState){
            pTimerCameraState=new QTimer (this);
            connect(pTimerCameraState,SIGNAL(timeout()),this,SLOT(getDeviceStatusSlot()));
            pTimerCameraState->start(10000);/* 10秒检测一次相机状态 */
        }
        return  true;
    }
    else {
        QByteArray msg=tr("Load the dynamic error<errorCode=%1>").arg(pDLL->errorString()).toLocal8Bit();
        qWarning("%s",msg.data());
    }
    return false;
}

QStringList CaptureImagesHCNET::effect()const
{

}

void CaptureImagesHCNET::initCamerSlot(const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow)
{
    if(!isSDKInit){
        if(!InitializationParameter()){/* 动态库初始化失败就不登录相机 */
            isSDKInit=false;
            return;
        }

        this->camerIp=camerIP;
        this->port=camerPort;
        this->camerName=CamerUser;
        this->camerPow=CamerPow;

        /* 设置动态库路径 */
        NET_SDK_INIT_CFG_TYPE cfgType=NET_SDK_INIT_CFG_SDK_PATH;
        strcpy(SDKPath.sPath,QDir::toNativeSeparators(QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("Plugins/HCNetSDK")).toLocal8Bit().data());
        if(nullptr!=NET_DVR_SetSDKInitCfg_L && !NET_DVR_SetSDKInitCfg_L(cfgType,&SDKPath)){
            QByteArray msg=tr("SDK path set error<errorCode=%1>").arg(NET_DVR_GetLastError_L()).toLocal8Bit();
            qWarning("%s",msg.data());
        }

        strcpy(LoginInfo.sDeviceAddress,camerIP.toLatin1().data());
        strcpy(LoginInfo.sUserName,CamerUser.toLatin1().data());
        strcpy(LoginInfo.sPassword,CamerPow.toLatin1().data());
        LoginInfo.wPort=static_cast<quint16>(camerPort);
        LoginInfo.bUseAsynLogin=1;
        LoginInfo.cbLoginResult=CaptureImagesHCNET::loginResultCallBack;
        LoginInfo.pUser=nullptr;

        if(nullptr!=NET_DVR_Init_L){
            if(NET_DVR_Init_L()){
                isSDKInit=true;
                if(nullptr!=NET_DVR_SetExceptionCallBack_V30_L){
                    NET_DVR_SetExceptionCallBack_V30_L(0,nullptr,CaptureImagesHCNET::exceptionCallBack_V30,nullptr);
                    // NET_DVR_SetLogToFile_L(3, QString(".\\Log\\sdkLog").toLatin1().data(), true);
                    NET_DVR_SetConnectTime_L(10000,0);
                    NET_DVR_SetReconnect_L(10000,0);
                    NET_DVR_SetRecvTimeOut_L(1000);
                }
                if(nullptr!=NET_DVR_Login_V40_L){
                    NET_DVR_Login_V40_L(&LoginInfo,&DeviceInfo);
                }

                QByteArray msg=tr("IP=%1 Camera init sucess").arg(this->camerIp).toLocal8Bit();
                qInfo("%s",msg.data());
            }
            else {
                QByteArray msg=tr("IP=%1 Camera Iinit error<errorCode=%2>").arg(this->camerIp).arg(NET_DVR_GetLastError_L()).toLocal8Bit();
                qWarning("%s",msg.data());
            }
        }
        else {
            QByteArray msg=tr("The dynamic init error<errorCode=%1>").arg(pDLL->errorString()).toLocal8Bit();
            qWarning("%s",msg.data());

            if(nullptr!=pDLL && pDLL->isLoaded()){
                pDLL->unload();
                delete pDLL;
            }
            pDLL=nullptr;

            /*****************************
            * @brief:重新初始化动态库
            ******************************/
            initCamerSlot(camerIP, camerPort,CamerUser,CamerPow);
        }
    }
    else {
        NET_DVR_Login_V40_L(&LoginInfo,&DeviceInfo);
    }
}

void CaptureImagesHCNET::putCommandSlot(const int &imgNumber, const QString &imgTime)
{
    QByteArray picture=nullptr;

    if(dwResult){
        NET_DVR_JPEGPARA   pJpegFile={};
        uint32_t charLen=IMG_BYTE;
        LPDWORD dataLen=nullptr;/* 接收数据长度 */
        char* buff=static_cast<char*>(malloc( charLen* sizeof(char)));
        pJpegFile.wPicSize=0xff;
        pJpegFile.wPicQuality=0;       

        if(nullptr!=NET_DVR_CaptureJPEGPicture_NEW_L && NET_DVR_CaptureJPEGPicture_NEW_L(lUserID,1,&pJpegFile,buff,charLen,dataLen)){
            picture=QByteArray(buff,*dataLen);
            //QByteArray arrayJpg(buff,IMG_BYTE);

            QByteArray msg=tr("IP=%1 Put Command Sucess").arg(camerIp).toLocal8Bit();
            qInfo("%s",msg.data());
        }
        else if(nullptr!=NET_DVR_GetLastError_L){
            QByteArray msg=tr("IP=%1 Put Command Error<errorCode=%2>").arg(camerIp).arg(NET_DVR_GetLastError_L()).toLocal8Bit();
            qWarning("%s",msg.data());
        }

        //emit pictureStreamSignal(picture,imgNumber,imgTime);/* 保证识别流程完成(识别流程需要完整图片编号) */

        dataLen=nullptr;
        free(buff);
        buff=nullptr;
    }
    else if(nullptr!=NET_DVR_GetLastError_L){
        QByteArray msg=tr("IP=%1 Put Command Error<errorCode=%2>").arg(camerIp).arg(NET_DVR_GetLastError_L()).toLocal8Bit();
        qWarning("%s",msg.data());
    }

    emit pictureStreamSignal(picture,imgNumber,imgTime);/* 保证识别流程完成(识别流程需要完整图片编号) */
}

void CaptureImagesHCNET::playStreamSlot(quint64 winID, bool play)
{
    if(dwResult){
        if(play){
            NET_DVR_PREVIEWINFO struPlayInfo = {};

#ifdef Q_OS_LINUX
            struPlayInfo.hPlayWnd    =static_cast<HWND>(winID); /* linux */
#endif

#ifdef Q_OS_WIN
            struPlayInfo.hPlayWnd= reinterpret_cast<HWND>(winID);/* windows */
#endif

            struPlayInfo.lChannel     = 1;       /* 预览通道号 */
            struPlayInfo.dwStreamType = 0;       /* 0-主码流，1-子码流，2-码流3，3-码流4，以此类推 */
            struPlayInfo.dwLinkMode   = 1;       /* 0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP */
            struPlayInfo.bBlocked     = 0;       /* 0- 非阻塞取流，1- 阻塞取流 */

            if(nullptr!=NET_DVR_RealPlay_V40_L){
                streamID =NET_DVR_RealPlay_V40_L(lUserID,&struPlayInfo,nullptr,nullptr);
                if(-1==streamID){
                    QByteArray msg=tr("IP=%1 Open Stream Error<errorCode=%2>").arg(camerIp).arg(NET_DVR_GetLastError_L()).toLocal8Bit();
                    qWarning("%s",msg.data());
                }
                else {
                    QByteArray msg=tr("IP=%1 Open Stream Sucess").arg(camerIp).toLocal8Bit();
                    qInfo("%s",msg.data());
                }
            }
        }
        else {
            if(nullptr!=NET_DVR_StopRealPlay_L && NET_DVR_StopRealPlay_L(streamID)){
                QByteArray msg=tr("IP=%1 Stop Stream sSucess").arg(camerIp).toLocal8Bit();
                qInfo("%s",msg.data());
            }
            else {
                QByteArray msg=tr("IP=%1 Stop Stream Error<errorCode=%2>").arg(camerIp).arg(NET_DVR_GetLastError_L()).toLocal8Bit();
                qWarning("%s",msg.data());
            }
        }
    }
}

void CaptureImagesHCNET::resizeEventSlot()
{
    if(dwResult){
        if(nullptr!=NET_DVR_ChangeWndResolution_L){
            NET_DVR_ChangeWndResolution_L(this->streamID);
        }
    }
}

void CaptureImagesHCNET::getDeviceStatusSlot()
{
    if(nullptr!=NET_DVR_RemoteControl_L && !camerIp.isEmpty()){
        if(NET_DVR_RemoteControl_L(lUserID,NET_DVR_CHECK_USER_STATUS,nullptr,4)){
            emit camerStateSingal(camerIp,true);
            dwResult=1;
        }
        else {
            emit camerStateSingal(camerIp,false);
            dwResult=0;

            /*****************************
            * @brief:断开重连
            ******************************/
            if(-1!=lUserID){
                if(nullptr!=NET_DVR_Logout_L){
                    NET_DVR_Logout_L(lUserID);
                }
            }
            initCamerSlot(camerIp,port,camerName,camerPow);/* 重新登录 */
        }
    }
}
