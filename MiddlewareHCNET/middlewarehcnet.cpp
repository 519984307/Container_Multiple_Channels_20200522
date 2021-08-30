#include "middlewarehcnet.h"

MiddlewareHCNET* MiddlewareHCNET::pThis=nullptr;

MiddlewareHCNET::MiddlewareHCNET(QObject *parent)
{
    this->setParent(parent);

    MiddlewareHCNET::pThis=this;

    MSGID=0;
    CAMERA_TYPE=1;
    streamID=-1;
    putID=-1;

    isSDKInit=false;
    charLen=IMG_BYTE;

    imgBuff=nullptr;
    pTimerState=nullptr;

    pJpegFile.wPicSize=0xff;
    pJpegFile.wPicQuality=0;

    snapcfg.dwSize=sizeof (NET_DVR_SNAPCFG);
    snapcfg.byRelatedDriveWay=1;
    snapcfg.bySnapTimes=1;
    snapcfg.wSnapWaitTime =0;
    snapcfg.struJpegPara=pJpegFile;

    manualsnap.byOSDEnable=1;
    manualsnap.byLaneNo=1;

    watcher=nullptr;
}

MiddlewareHCNET::~MiddlewareHCNET()
{
    if(imgBuff!=nullptr){
         free(imgBuff);
    }

    foreach (auto thread, tdList) {
        thread->quit();
        thread->wait();
    }

    if(nullptr != watcher){
        watcher->cancel();
        watcher->deleteLater();
    }
}

QString MiddlewareHCNET::InterfaceType()
{
    return QString("HCNET_SDK");
}

void MiddlewareHCNET::MSGCallBack(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void *pUser)
{
    Q_UNUSED((dwBufLen);
    Q_UNUSED(pUser);)
    /* 系统时间 */
    QString dateTime=QDateTime::currentDateTime().toString("yyyy-M-d h:m:s");

    if(lCommand == COMM_UPLOAD_PLATE_RESULT){
        NET_DVR_PLATE_RESULT struPlateResult={};
        memcpy(&struPlateResult, pAlarmInfo, sizeof(struPlateResult));

        QString plate=QString::fromLocal8Bit(struPlateResult.struPlateInfo.sLicense);
        if(plate!="无车牌" && !plate.isEmpty()){
            plate=plate.mid(1);
        }

        /* 场景图 */
        if (struPlateResult.dwPicLen != 0 && struPlateResult.byResultType == 1 )
        {
            pThis->imgBuff=reinterpret_cast<char*>(struPlateResult.pBuffer1);
            QByteArray arrayJpg(pThis->imgBuff,struPlateResult.dwPicLen);

            QString color="";
            switch(struPlateResult.struPlateInfo.byColor)/* 车牌颜色 */
            {
            case VCA_BLUE_PLATE:
                color=QString("蓝");
                break;
            case VCA_YELLOW_PLATE:
                color=QString("黄");
                break;
            case VCA_WHITE_PLATE:
                color=QString("白");
                break;
            case VCA_BLACK_PLATE:
                color=QString("黑");
                break;
            default:
                break;
            }
            emit pThis->resultsTheLicensePlateSignal(pAlarmer->lUserID, plate,color,dateTime,arrayJpg);
            emit pThis->signal_pictureStream(pAlarmer->lUserID,arrayJpg);
            qDebug().noquote()<<QString("[%1] License Plate recognition results:%2-%3").arg(pThis->metaObject()->className(),plate,dateTime);
            arrayJpg.clear();
        }
    }
    else if(lCommand==COMM_ITS_PLATE_RESULT){
        NET_ITS_PLATE_RESULT struITSPlateResult={};
        memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));

        QString plate=QString::fromLocal8Bit(struITSPlateResult.struPlateInfo.sLicense);
        if(plate!="无车牌" && !plate.isEmpty()){
            plate=plate.mid(1);
        }

        /* 场景图 */
        if (((struITSPlateResult.struPicInfo[0].dwDataLen != 0)&&(struITSPlateResult.struPicInfo[0].byType== 1))||(struITSPlateResult.struPicInfo[0].byType == 2))
        {
            pThis->imgBuff=reinterpret_cast<char*>(struITSPlateResult.struPicInfo[0].pBuffer);
            QByteArray arrayJpg(pThis->imgBuff,struITSPlateResult.struPicInfo[0].dwDataLen);

            QString color="";
            switch(struITSPlateResult.struPlateInfo.byColor)/* 车牌颜色 */
            {
            case VCA_BLUE_PLATE:
                color=QString("蓝");
                break;
            case VCA_YELLOW_PLATE:
                color=QString("黄");
                break;
            case VCA_WHITE_PLATE:
                color=QString("白");
                break;
            case VCA_BLACK_PLATE:
                color=QString("黑");
                break;
            default:
                break;
            }

            emit pThis->resultsTheLicensePlateSignal(pAlarmer->lUserID,plate,color,dateTime,arrayJpg);
            emit pThis->signal_pictureStream(pAlarmer->lUserID,arrayJpg);
            qDebug().noquote()<<QString("[%1] License Plate recognition results:%2-%3").arg(pThis->metaObject()->className(),plate,dateTime);
            arrayJpg.clear();
        }
    }
}

void MiddlewareHCNET::exceptionCallBack_V30(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
    Q_UNUSED(pUser);
    Q_UNUSED(dwType);
    Q_UNUSED(lHandle);

    LPNET_DVR_USER_LOGIN_INFO LoginInfo=pThis->logInfoMap.key(lUserID,nullptr);

    if(nullptr != LoginInfo && NET_DVR_GetLastError()>0){

        qWarning().noquote()<<QString("[%1] %2:Camrea Exception<errorCode=%3>").arg(pThis->metaObject()->className(),LoginInfo->sDeviceAddress,QString::number(NET_DVR_GetLastError()));

        /*****************************
        * @brief:出现异常，关闭视频流和登出相机
        ******************************/

        long stream=pThis->playInfoMap.value(lUserID,-1);
        if(stream!=-1){
            if(NET_DVR_StopRealPlay(stream)){
                qDebug().noquote()<<QString("[%1] %2:Stop Stream Sucess").arg(pThis->metaObject()->className(),QString::fromLocal8Bit(pThis->logInfoMap.key(lUserID)->sDeviceAddress));
                pThis->playInfoMap.remove(lUserID);

                emit pThis->signal_releaseResources(lUserID);
            }
            else {
                qWarning().noquote()<<QString("[%1] %2:Stop Stream failed<code=%3>").arg(pThis->metaObject()->className(),QString::fromLocal8Bit(pThis->logInfoMap.key(lUserID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
            }
        }

        emit pThis->equipmentStateSignal(lUserID,false);

        /*****************************
        * @brief:出现异常,删除车牌抓拍ID（重新登录会分配ID）
        ******************************/
        int pos=pThis->platePutIDList.indexOf(lUserID);
        if(-1 != pos){
            pThis->platePutIDList.removeAt(pos);
        }

        NET_DVR_Logout(lUserID);

        //NET_DVR_Login_V40(pThis->logInfoMap.key(lUserID),&pThis->DeviceInfo);
    }
}

void MiddlewareHCNET::loginResultCallBack(LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo, void *pUser)
{
    Q_UNUSED(lpDeviceInfo)

    LPNET_DVR_USER_LOGIN_INFO pLoginInfo=reinterpret_cast<LPNET_DVR_USER_LOGIN_INFO>(pUser);

    pThis->logInfoMap.insert(pLoginInfo,lUserID);

    if(1==dwResult){

        qDebug().noquote()<<QString("[%1] %2:Camera login succeeded<code=%3>").arg(pThis->metaObject()->className(),pLoginInfo->sDeviceAddress,QString::number(lUserID));

        emit pThis->signal_setCameraID(lUserID,pLoginInfo->sDeviceAddress);
        emit pThis->equipmentStateSignal(lUserID,true);

        if(3 == pThis->CAMERA_TYPE || -1 != pThis->plateAddrList.indexOf(pLoginInfo->sDeviceAddress)){
            /*****************************
            * @brief:交通系列相机
            ******************************/
            NET_DVR_SETUPALARM_PARAM alarm={};
            alarm.dwSize=sizeof (NET_DVR_SETUPALARM_PARAM);
            alarm.byAlarmInfoType=1;
            alarm.byLevel=1;
            long lHandle= NET_DVR_SetupAlarmChan_V41(lUserID,&alarm);
            if(lHandle>0){
                pThis->alarmInfoMap.insert(lUserID,lHandle);
            }
        }

        if(4 == pThis->CAMERA_TYPE){
            /*****************************
            * @brief:视频流相机
            ******************************/
            if(pThis->watcher->isRunning()){
                pThis->initVidoeMap.insert(lUserID,true);
            }
            else {
                QFuture<void> future =QtConcurrent::run(pThis,&MiddlewareHCNET::initVideoStream,lUserID,true);
                pThis->watcher->setFuture(future);
            }
        }

        /*****************************
        * @brief:所有车牌相机ID放入单独列表
        ******************************/
        foreach (auto addr,pThis->plateAddrList) {
            if(addr == pLoginInfo->sDeviceAddress){
                pThis->platePutIDList.append(lUserID);
            }
        }
    }
    else {        
        NET_DVR_Logout(lUserID);
        qWarning().noquote()<<QString("[%1] %2:login failed <errorCode=%3>").arg(pThis->metaObject()->className(),pLoginInfo->sDeviceAddress,QString::number(NET_DVR_GetLastError()));
    }
}

void MiddlewareHCNET::liftingElectronicRailingSlot(bool gate)
{
    Q_UNUSED(gate);

}

void MiddlewareHCNET::transparentTransmission485Slot(const QString &msg)
{
    Q_UNUSED(msg);
}

void MiddlewareHCNET::releaseResourcesSlot()
{
    if(pTimerState!=nullptr){
        pTimerState->stop();
    }
    foreach ( auto handID, alarmInfoMap.values()) {
        NET_DVR_CloseAlarmChan_V30(handID);
    }
    if(4==CAMERA_TYPE){
        foreach (auto lReadHanlde, playInfoMap.values()) {
            if(-1!=lReadHanlde){
                NET_DVR_StopRealPlay(lReadHanlde);
            }
        }
    }
    foreach ( auto userID, logInfoMap.values()) {
        NET_DVR_Logout(userID);

    }
    NET_DVR_Cleanup();
}

void MiddlewareHCNET::simulationCaptureSlot(int ID)
{
//    if(!NET_DVR_RemoteControl(ID,NET_DVR_CHECK_USER_STATUS,nullptr,4)){
//        emit signal_pictureStream(ID,nullptr);
//        qWarning().noquote()<<QString("[%1] %2:Put Command Error<errorCode=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
//        return;
//    }

    bool cap=true;

    /*****************************
    * @brief:车牌相机单独触发
    ******************************/
    if(-1 != platePutIDList.indexOf(ID)){
        if(NET_DVR_ContinuousShoot(ID,&snapcfg)){/* 网络触发抓拍 */
            qDebug().noquote()<<QString("[%1] %2:Put Command Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
        }
        else {
            cap=false;
        }
    }
    else {
        switch (CAMERA_TYPE) {
        case 1:
            {
                LPDWORD dataLen=nullptr;
                /* 手动触发抓拍保存到内存 */
                if(NET_DVR_CaptureJPEGPicture_NEW(ID,1,&pJpegFile,imgBuff,charLen,dataLen)){
                    QByteArray arrayJpg(imgBuff,IMG_BYTE);
                    emit signal_pictureStream(ID,arrayJpg);
                    qDebug().noquote()<<QString("[%1] %2:Put Command Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
                    arrayJpg.clear();
                    delete  dataLen;
                    dataLen=nullptr;
                }
                else {
                    cap=false;
                }
            }
            break;
        case 2:
            {
                NET_DVR_PLATE_RESULT result={};
                result.dwSize=sizeof (result);
                result.pBuffer1=reinterpret_cast<unsigned char*>(imgBuff);
                /* 手动触发抓拍，SDK提示做测试使用 */
                if(NET_DVR_ManualSnap(ID,&manualsnap,&result)){
                    QByteArray arrayJpg(imgBuff,IMG_BYTE);
                    emit signal_pictureStream(ID,arrayJpg);
                    qDebug().noquote()<<QString("[%1] %2:Put Command Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
                    arrayJpg.clear();
                }
                else {
                    cap=false;
                }
            }
            break;
        case 3:
            {
                if(NET_DVR_ContinuousShoot(ID,&snapcfg)){/* 网络触发抓拍 */
                    qDebug().noquote()<<QString("[%1] %2:Put Command Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
                }
                else {
                    cap=false;
                }
            }
            break;
        case 4:
            {
            putID=ID;
            qDebug().noquote()<<QString("[%1] %2:Start Put Command ").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));

            /*****************************
            * @brief:视频流解码抓拍图片
            ******************************/
            emit signal_getPictureStream(putID,-1);
            }
            break;
        }
    }

    if(!cap){
        emit pThis->signal_pictureStream(ID,nullptr);/* 保证识别流程完成(识别流程需要完整图片编号) */
        qWarning().noquote()<<QString("[%1] %2:Put Command Error<errorCode=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
    }
}

void MiddlewareHCNET::openTheVideoSlot(int ID, bool play, quint64 winID)
{
    if(play){
        NET_DVR_PREVIEWINFO struPlayInfo = {};
        //struPlayInfo.hPlayWnd    =static_cast<HWND>(winID); /* linux */
        struPlayInfo.hPlayWnd= reinterpret_cast<HWND>(winID);/* windows */
        struPlayInfo.lChannel     = 1;       /* 预览通道号 */
        struPlayInfo.dwStreamType = 0;       /* 0-主码流，1-子码流，2-码流3，3-码流4，以此类推 */
        struPlayInfo.dwLinkMode   = 1;       /* 0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP */
        struPlayInfo.bBlocked     = 0;       /* 0- 非阻塞取流，1- 阻塞取流 */

        streamID =NET_DVR_RealPlay_V40(ID,&struPlayInfo,nullptr,nullptr);
        if(streamID==-1){
            qWarning().noquote()<<QString("[%1] %2:Open Stream Error<errorCode=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
        }
        else {
            qDebug().noquote()<<QString("[%1] %2:Open Stream Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
        }
    }
    else {
        if(streamID!=-1 && NET_DVR_StopRealPlay(streamID)){
            qDebug().noquote()<<QString("[%1] %2:Stop Stream sSucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
        }
    }
}

void MiddlewareHCNET::initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow,const QString &signature)
{
    Q_UNUSED(localAddr)

    if(!isSDKInit){
        return;
    }

    /*****************************
    * @brief:所有海康相机使用一个插件，车牌插排方式不一样。单独处理
    ******************************/
    if(QString("Plate") == signature){
        plateAddrList.append(addr);
    }

    LPNET_DVR_USER_LOGIN_INFO pLoginInfo = new NET_DVR_USER_LOGIN_INFO();
    strcpy(pLoginInfo->sDeviceAddress,addr.toLatin1().data());
    strcpy(pLoginInfo->sUserName,user.toLatin1().data());
    strcpy(pLoginInfo->sPassword,pow.toLatin1().data());
    pLoginInfo->wPort=static_cast<quint16>(port);
    pLoginInfo->bUseAsynLogin=1;
    pLoginInfo->cbLoginResult=MiddlewareHCNET::loginResultCallBack;
    pLoginInfo->pUser=pLoginInfo;

    NET_DVR_Login_V40(pLoginInfo,&DeviceInfo);
}

void MiddlewareHCNET::setCaptureTypeSlot(const int &capType, const int &msgCallBackInd)
{
    CAMERA_TYPE=capType;
    MSGID=msgCallBackInd;
}

void MiddlewareHCNET::slot_initializationParameter()
{
    NET_DVR_LOCAL_SDK_PATH SDKPath={};
    NET_SDK_INIT_CFG_TYPE cfgType=NET_SDK_INIT_CFG_SDK_PATH;

    QString path= QDir::toNativeSeparators(QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg("Plugins/HCNetSDK"));
    strcpy(SDKPath.sPath,path.toLocal8Bit().data());

    NET_DVR_SetSDKInitCfg(cfgType,&SDKPath);
    if(NET_DVR_Init()){
        isSDKInit=true;

        if(imgBuff==nullptr){
            imgBuff=static_cast<char*>(malloc(charLen* sizeof(char)));
        }

        if(pTimerState==nullptr){
            pTimerState=new QTimer (this);
            connect(pTimerState,SIGNAL(timeout()),this,SLOT(getDeviceStatusSlot()));
            pTimerState->start(10000);/* 15秒检测一次相机状态 */
        }

        watcher=new QFutureWatcher<void>(this);
        connect(watcher, SIGNAL(finished()), this, SLOT(slot_handleFinished()));

        qDebug().noquote()<<QString("[%1] The dynamic library is successfully loaded").arg(this->metaObject()->className());
    }
    else {
        qCritical().noquote()<<QString("[%1] Dynamic library loading failed").arg(this->metaObject()->className());
    }
    NET_DVR_SetExceptionCallBack_V30(0,nullptr,MiddlewareHCNET::exceptionCallBack_V30,this);
    NET_DVR_SetConnectTime(3000,1);
    NET_DVR_SetReconnect(3000,1);
    NET_DVR_SetRecvTimeOut(1000);
    NET_DVR_SetDVRMessageCallBack_V50(MSGID,MiddlewareHCNET::MSGCallBack,this);

    /*****************************
    * @brief:加载视频解码插件
    ******************************/
    loadDecodingPlugin();
}

void MiddlewareHCNET::slot_exceptionCode(unsigned long dwType, long lUserID)
{
    Q_UNUSED(dwType)
    Q_UNUSED(lUserID)
}

void MiddlewareHCNET::initVideoStream(int ID, bool play)
{
    /*****************************
    * @brief:降低码流减少CPU占用资源
    ******************************/
    if(play){
        NET_DVR_PREVIEWINFO struPlayInfo = {};
        struPlayInfo.hPlayWnd= nullptr;
        struPlayInfo.lChannel     = 1;       /* 预览通道号 */
        struPlayInfo.dwStreamType = 1;       /* 0-主码流，1-子码流，2-码流3，3-码流4，以此类推 */
        struPlayInfo.dwLinkMode   = 0;       /* 0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP */
        struPlayInfo.bBlocked     = 0;       /* 0- 非阻塞取流，1- 阻塞取流 */

        foreach (auto DecodingCallBack, IDecodingVideoLit) {
            if(-1 == DecodingCallBack->getReadHanlde()){
                long stream =NET_DVR_RealPlay_V40(ID,&struPlayInfo,reinterpret_cast<REALDATACALLBACK>(DecodingCallBack->getCallBack()),nullptr);
                if(stream==-1){
                    qWarning().noquote()<<QString("[%1] %2:Open Stream Error<errorCode=%3>").arg(pThis->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));

                    DecodingCallBack->setReadHanlde(-1);

                    NET_DVR_Logout(ID);
                }
                else {
                    DecodingCallBack->setReadHanlde(ID);

                    playInfoMap.insert(ID,stream);
                    qDebug().noquote()<<QString("[%1] %2:binding [cameraID:%3][streamID:%4]").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(ID),QString::number(stream));
                    qDebug().noquote()<<QString("[%1] %2:Open Stream Sucess <Code=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(stream));
                }
                break;
            }
        }
    }
//    else {
//        long stream=playInfoMap.value(ID,-1);
//        if(stream!=-1){
//            /*****************************
//            * @brief:关闭播放库
//            ******************************/
//            emit signal_releaseResources(ID);

//            if(NET_DVR_StopRealPlay(stream)){
//                qDebug().noquote()<<QString("[%1] %2:Stop Stream Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));
//            }
//            else {
//                qWarning().noquote()<<QString("[%1] %2:Stop Stream failed<code=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
//            }

//            playInfoMap.remove(ID);
//        }
//    }
}

void MiddlewareHCNET::loadDecodingPlugin()
{
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("Plugins");
    QString pluginName=QString("");

    for(const QString fileName :pluginsDir.entryList(QDir::Files,QDir::Name)){
        QPluginLoader  pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        if(plugin){
            if(IDecodingVideo *pIDecodingVideo=qobject_cast<IDecodingVideo*>(plugin)){
                pluginName=fileName;
                pIDecodingVideo=nullptr;
                pluginLoader.unload();
                break;
            }
        }
    }

    pluginsDir.cd(pluginName.split('.').at(0));

    for(const QString fileName :pluginsDir.entryList(QDir::Files,QDir::Name)){
        QPluginLoader  pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        if(plugin){
            if(IDecodingVideo *pIDecodingVideo=qobject_cast<IDecodingVideo*>(plugin)){
                QThread *th=new QThread();
                tdList.append(th);
                pIDecodingVideo->moveToThread(th);
                th->start();
                IDecodingVideoLit.append(QSharedPointer<IDecodingVideo>(pIDecodingVideo));

                connect(pIDecodingVideo,&IDecodingVideo::signal_pictureStream,this,&MiddlewareHCNET::signal_pictureStream);
                connect(this,&MiddlewareHCNET::signal_getPictureStream,pIDecodingVideo,&IDecodingVideo::slot_getPictureStream);
                connect(this,&MiddlewareHCNET::signal_releaseResources,pIDecodingVideo,&IDecodingVideo::releaseResourcesSlot);
            }
        }
    }
}

void MiddlewareHCNET::getDeviceStatusSlot()
{
    foreach (auto ID,logInfoMap.values()){
        if(NET_DVR_RemoteControl(ID,NET_DVR_CHECK_USER_STATUS,nullptr,4)){
            emit equipmentStateSignal(ID,true);
        }
        else {
            emit equipmentStateSignal(ID,false);

//            /*****************************
//            * @brief:出现异常,删除车牌抓拍ID（重新登录会分配ID）
//            ******************************/
//            int pos=pThis->platePutIDList.indexOf(ID);
//            if(-1 != pos){
//                pThis->platePutIDList.removeAt(pos);
//            }

//            /*****************************
//            * @brief:关掉布防
//            ******************************/
//            long handle=alarmInfoMap.value(ID,-1);
//            if(handle!=-1){
//                NET_DVR_CloseAlarmChan_V30(handle);
//                alarmInfoMap.remove(ID);
//            }

//            long stream=playInfoMap.value(ID,-1);
//            if(stream!=-1){
//                if(NET_DVR_StopRealPlay(stream)){
//                    qDebug().noquote()<<QString("[%1] %2:Stop Stream Sucess").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress));

//                    /*****************************
//                    * @brief:关闭播放库
//                    ******************************/
//                    emit signal_releaseResources(ID);

//                    playInfoMap.remove(ID);
//                }
//                else {
//                    qWarning().noquote()<<QString("[%1] %2:Stop Stream failed<code=%3>").arg(this->metaObject()->className(),QString::fromLocal8Bit(logInfoMap.key(ID)->sDeviceAddress),QString::number(NET_DVR_GetLastError()));
//                }
//            }

//            NET_DVR_Logout(ID);
            NET_DVR_Login_V40(logInfoMap.key(ID),&DeviceInfo);
        }
    }
}

void MiddlewareHCNET::slot_handleFinished()
{
    foreach (long id, initVidoeMap.keys()) {
        initVideoStream(id,initVidoeMap.value(id));
    }
    initVidoeMap.clear();
}

void MiddlewareHCNET::resizeEventSlot()
{
    //    if(dwResult){/* window不需要 */
    //        if(NET_DVR_ChangeWndResolution_L !=nullptr){
    //            NET_DVR_ChangeWndResolution_L(this->streamID);
    //        }
    //    }
}
