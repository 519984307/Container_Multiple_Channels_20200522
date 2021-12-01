#include "middlewareclinet.h"

///
/// \brief MiddlewareCLINET::pThis 初始化类对象指针
///
MiddlewareCLINET* MiddlewareCLINET::pThis=nullptr;

MiddlewareCLINET::MiddlewareCLINET(QObject* parent)
{
    this->setParent(parent);

    MiddlewareCLINET::pThis=this;
}

MiddlewareCLINET::~MiddlewareCLINET()
{

}

QString MiddlewareCLINET::InterfaceType()
{
    return QString("CLINET_SDK");
}

void MiddlewareCLINET::liftingElectronicRailingSlot(bool gate)
{

}

void MiddlewareCLINET::transparentTransmission485Slot(const QString &msg)
{

}

void MiddlewareCLINET::releaseResourcesSlot()
{
    if(initSDk){
        CLIENT_Cleanup();
    }
}

void MiddlewareCLINET::simulationCaptureSlot(int ID)
{

}

void MiddlewareCLINET::openTheVideoSlot(int ID, bool play, quint64 winID)
{
#ifdef Q_OS_LINUX
    HWND  hPlayWnd=static_cast<HWND>(winID);
#endif
#ifdef Q_OS_WIN
    HWND  hPlayWnd=reinterpret_cast<HWND>(winID);
#endif

    if(play){
         lRealHandle=CLIENT_RealPlayEx(ID,0,hPlayWnd);
    }
    else {
        if(CLIENT_StopRealPlayEx(lRealHandle)){
            qInfo().noquote()<<QString("[%1] %2:Camera open Stream sucess").arg(pThis->metaObject()->className(),pThis->cameraBingIDMap.value(ID));
        }
        else {
            qCritical().noquote()<<QString("[%1] %2:Camera close Stream failed").arg(pThis->metaObject()->className(),pThis->cameraBingIDMap.value(ID));
        }
    }

}

void MiddlewareCLINET::slot_initializationParameter()
{
    initSDk = CLIENT_Init(MiddlewareCLINET::DisConnectFunc,0);
    CLIENT_SetAutoReconnect(MiddlewareCLINET::HaveReConnectFunc,0);
    CLIENT_SetSubconnCallBack(MiddlewareCLINET::SubHaveReConnectFunc,0);
    CLIENT_SetSnapRevCallBack(MiddlewareCLINET::SnapRevCallBack,0);
    CLIENT_SetDVRMessCallBack(MiddlewareCLINET::DVRMessCallBack,0);

    CLIENT_SetConnectTime(3000,0);

    if(!initSDk){
        qCritical().noquote()<<QString("[%1] CLINET_SDK init failde").arg(pThis->metaObject()->className());
        CLIENT_Cleanup();
    }
}

void MiddlewareCLINET::initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow, const QString &signature)
{
    Q_UNUSED(localAddr)

    if(initSDk){
        NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY stInparam;
        memset(&stInparam, 0, sizeof(stInparam));
        stInparam.dwSize = sizeof(stInparam);
        strncpy(stInparam.szIP, addr.toLatin1().data(), sizeof(stInparam.szIP) - 1);
        strncpy(stInparam.szUserName, user.toLatin1().data(), sizeof(stInparam.szUserName) - 1);
        strncpy(stInparam.szPassword, pow.toLatin1().data(), sizeof(stInparam.szPassword) - 1);
        stInparam.nPort = port;
        stInparam.emSpecCap = EM_LOGIN_SPEC_CAP_TCP;
        NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY stOutparam;
        memset(&stOutparam, 0, sizeof(stOutparam));
        stOutparam.dwSize = sizeof(stOutparam);

        long loginHandle = CLIENT_LoginWithHighLevelSecurity(&stInparam,&stOutparam);
        if(loginHandle!=0){
            /*****************************
            * @brief:登录成功绑定相机ID和标志
            ******************************/
            cameraBingSigMap.insert(signature,loginHandle);

            /*****************************
            * @brief:登录成功绑定相机ID和地址
            ******************************/
            cameraBingIDMap.insert(loginHandle,addr);

            /*****************************
            * @brief:绑定登录ID和特征码
            ******************************/
            emit signal_setCameraID(loginHandle,signature);

            qInfo().noquote()<<QString("[%1] %2:camera login sucess").arg(pThis->metaObject()->className(),addr);
        }
        else {
            CLIENT_Logout(loginHandle);
            qWarning().noquote()<<QString("[%1] %2:camera login failde errCode=<%3>").arg(pThis->metaObject()->className(),addr,QString::number(CLIENT_GetLastError()&(0x7fffffff)));
        }
    }
}

void MiddlewareCLINET::setCaptureTypeSlot(const int &capType, const int &msgCallBackInd)
{

}

void MiddlewareCLINET::slot_exceptionCode(unsigned long dwType, long lUserID)
{

}

void MiddlewareCLINET::DisConnectFunc(long lLoginID, char *pchDVRIP, int nDVRPort, long dwUser)
{
    Q_UNUSED(lLoginID)
    Q_UNUSED(nDVRPort)
    Q_UNUSED(dwUser)

    emit pThis->equipmentStateSignal(lLoginID,false);

    qWarning().noquote()<<QString("[%1] %2:camera disconnect errCode=<%3>").arg(pThis->metaObject()->className(),QString::fromLatin1(pchDVRIP),QString::number(CLIENT_GetLastError()&(0x7fffffff)));
}

void MiddlewareCLINET::HaveReConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
    Q_UNUSED(lLoginID)
    Q_UNUSED(nDVRPort)
    Q_UNUSED(dwUser)

    emit pThis->equipmentStateSignal(lLoginID,true);

    qInfo().noquote()<<QString("[%1] %2:camera connected").arg(pThis->metaObject()->className(),QString::fromLatin1(pchDVRIP));
}

void MiddlewareCLINET::SubHaveReConnectFunc(EM_INTERFACE_TYPE emInterfaceType, int bOnline, long lOperateHandle, long lLoginID, long dwUser)
{
    Q_UNUSED(emInterfaceType)
    Q_UNUSED(bOnline)
    Q_UNUSED(lOperateHandle)
    Q_UNUSED(lLoginID)
    Q_UNUSED(dwUser)

    qDebug()<<"SubHaveReConnectFunc";
}

int MiddlewareCLINET::DVRMessCallBack(int lCommand, long lLoginID, char *pBuf, unsigned int dwBufLen, char *pchDVRIP, int nDVRPort, long dwUser)
{

}

void MiddlewareCLINET::SnapRevCallBack(long lLoginID, unsigned char *pBuf, unsigned int RevLen, unsigned int EncodeType, unsigned int CmdSerial, long dwUser)
{

}
