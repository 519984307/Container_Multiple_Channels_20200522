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

}

void MiddlewareCLINET::simulationCaptureSlot(int ID)
{

}

void MiddlewareCLINET::openTheVideoSlot(int ID, bool play, quint64 winID)
{

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
            * @brief:登录成功绑定相机ID
            ******************************/
            cameraBingMap.insert(signature,loginHandle);
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

    qWarning().noquote()<<QString("[%1] %2:camera disconnect errCode=<%3>").arg(pThis->metaObject()->className(),QString::fromLatin1(pchDVRIP),QString::number(CLIENT_GetLastError()&(0x7fffffff)));
}

void MiddlewareCLINET::HaveReConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
    Q_UNUSED(lLoginID)
    Q_UNUSED(nDVRPort)
    Q_UNUSED(dwUser)

    qWarning().noquote()<<QString("[%1] %2:camera connected").arg(pThis->metaObject()->className(),QString::fromLatin1(pchDVRIP));
}

void MiddlewareCLINET::SubHaveReConnectFunc(EM_INTERFACE_TYPE emInterfaceType, int bOnline, long lOperateHandle, long lLoginID, long dwUser)
{
    qDebug()<<"SubHaveReConnectFunc";
}

int MiddlewareCLINET::DVRMessCallBack(int lCommand, long lLoginID, char *pBuf, unsigned int dwBufLen, char *pchDVRIP, int nDVRPort, long dwUser)
{

}

void MiddlewareCLINET::SnapRevCallBack(long lLoginID, unsigned char *pBuf, unsigned int RevLen, unsigned int EncodeType, unsigned int CmdSerial, long dwUser)
{

}
