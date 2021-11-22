#ifndef MIDDLEWARECLINET_H
#define MIDDLEWARECLINET_H

#define IMG_BYTE 1920*1080+1

#include "MiddlewareCLINET_global.h"
#include "IMiddleware.h"
#include "dhnetsdk.h"

class MIDDLEWARECLINET_EXPORT MiddlewareCLINET:public IMiddleware
{
    Q_OBJECT
    Q_INTERFACES(IMiddleware)
    Q_PLUGIN_METADATA(IID IMiddlewareIID)

public:
    MiddlewareCLINET(QObject* parent=nullptr );
    ~MiddlewareCLINET()Q_DECL_OVERRIDE;

    QString InterfaceType()Q_DECL_OVERRIDE;

    static MiddlewareCLINET* pThis;

    ///
    /// \brief DisConnectFunc 链接断开回调函数
    /// \param lLoginID
    /// \param pchDVRIP
    /// \param nDVRPort
    /// \param dwUser
    ///
    static void __stdcall DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

    ///
    /// \brief HaveReConnectFunc 自动重连回调函数
    /// \param lLoginID
    /// \param pchDVRIP
    /// \param nDVRPort
    /// \param dwUser
    ///
    static void __stdcall HaveReConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

    ///
    /// \brief SubHaveReConnectFunc 子链接重连回调函数
    /// \param emInterfaceType
    /// \param bOnline
    /// \param lOperateHandle
    /// \param lLoginID
    /// \param dwUser
    ///
    static void __stdcall SubHaveReConnectFunc(EM_INTERFACE_TYPE emInterfaceType, BOOL bOnline, LLONG lOperateHandle, LLONG lLoginID, LDWORD dwUser);

    ///
    /// \brief DVRMessCallBack 报警消息回调函数
    /// \param lCommand
    /// \param lLoginID
    /// \param pBuf
    /// \param dwBufLen
    /// \param pchDVRIP
    /// \param nDVRPort
    /// \param dwUser
    /// \return
    ///
    static BOOL __stdcall DVRMessCallBack(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

    ///
    /// \brief SnapRevCallBack 抓图回调函数
    /// \param lLoginID
    /// \param pBuf
    /// \param RevLen
    /// \param EncodeType
    /// \param CmdSerial
    /// \param dwUser
    ///
    static void __stdcall SnapRevCallBack(LLONG  lLoginID,  BYTE   *pBuf,UINT   RevLen,  UINT   EncodeType,  DWORD  CmdSerial,  LDWORD dwUser);

private:
    
    ///
    /// \brief initSDk SDK初始化状态
    ///
    bool initSDk;

    ///
    /// \brief cameraBingMap 相机ID和标志绑定
    ///
    QMap<QString,long> cameraBingMap;

    ///
    /// \brief liftingElectronicRailingSlot 抬杆/落杆
    ///
    void liftingElectronicRailingSlot(bool gate)Q_DECL_OVERRIDE;

    ///
    /// \brief transparentTransmission485Slot 透明传输
    /// \param dmsg
    ///
    void transparentTransmission485Slot(const QString &msg)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief simulationCaptureSlot 模拟抓拍
    ///
    void simulationCaptureSlot(int ID)Q_DECL_OVERRIDE;

    ///
    /// \brief openTheVideoSlot 打开视频/关闭视频
    /// \param play
    ///
    void openTheVideoSlot(int ID,bool play,quint64 winID=0)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_initializationParameter 初始化动态库参数
    ///
    void slot_initializationParameter()Q_DECL_OVERRIDE;

    ///
    /// \brief initCameraSlot 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 地址
    /// \param port 端口
    /// \param user 用户
    /// \param pow  密码
    /// \param signature 特征码
    ///
    void initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow ,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief setCaptureTypeSlot 设置抓拍模式
    /// \param capType 相机抓拍模式
    /// \param msgCallBackInd 数据回调函数ID
    ///
    void setCaptureTypeSlot(const int &capType, const int &msgCallBackInd)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_exceptionCode 相机异常
    /// \param dwType 错误码
    /// \param lUserID 相机ID
    ///
    void slot_exceptionCode(unsigned long dwType,  long lUserID)Q_DECL_OVERRIDE;
};

#endif // MIDDLEWARECLINET_H
