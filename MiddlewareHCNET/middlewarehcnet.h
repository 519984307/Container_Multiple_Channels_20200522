#ifndef MIDDLEWAREHCNET_H
#define MIDDLEWAREHCNET_H

#define IMG_BYTE 1920*1080+1

#include "MiddlewareHCNET_global.h"
#include "IMiddleware.h"
#include "IDecodingVideo.h"

#include "HCNetSDK.h"

class MIDDLEWAREHCNET_EXPORT MiddlewareHCNET:public IMiddleware
{
    Q_OBJECT
    Q_INTERFACES(IMiddleware)
    Q_PLUGIN_METADATA(IID IMiddlewareIID)

public:
    MiddlewareHCNET(QObject *parent=nullptr);
    ~MiddlewareHCNET()Q_DECL_OVERRIDE;

    QString InterfaceType()Q_DECL_OVERRIDE;

    static MiddlewareHCNET *pThis;

    /*****************************
    * @brief:交通系列（2CD9），抓图需要布防
    ******************************/
    ///
    /// \brief MSGCallBack  注册回调函数，接收设备报警消息等。
    /// \param lCommand 上传的消息类型，不同的报警信息对应不同的类型，通过类型区分是什么报警信息，详见“Remarks”中列表
    /// \param pAlarmer 报警设备信息，包括设备序列号、IP地址、登录IUserID句柄等
    /// \param pAlarmInfo 报警信息，通过lCommand值判断pAlarmer对应的结构体，详见“Remarks”中列表
    /// \param dwBufLen 报警信息缓存大小
    /// \param pUser 用户数据
    /// \return TRUE表示成功，FALSE表示失败。接口返回失败请调用NET_DVR_GetLastError获取错误码，通过错误码判断出错原因
    ///
    static void MSGCallBack(LONG lCommand,NET_DVR_ALARMER *pAlarmer,char *pAlarmInfo,DWORD dwBufLen,void *pUser);

    ///
    /// \brief exceptionCallBack_V30 接收异常、重连等消息的窗口句柄或回调函数。
    /// \param dwType 异常或重连等消息的类型
    /// \param lUserID 登录ID
    /// \param lHandle 出现异常的相应类型的句柄
    /// \param pUser 用户数据
    ///
    static void CALLBACK exceptionCallBack_V30(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);

    ///
    /// \brief fLoginResultCallBack 登录状态回调函数
    /// \param lUserID 用户ID，NET_DVR_Login_V40的返回值
    /// \param dwResult 登录状态：0- 异步登录失败，1- 异步登录成功
    /// \param lpDeviceInfo 设备信息，设备序列号、通道、能力等参数
    /// \param pUser 用户数据
    ///
    static void CALLBACK loginResultCallBack(LONG lUserID,DWORD dwResult,LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo,void *pUser);

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
    /// \brief initCameraSlot 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 地址
    /// \param port 端口
    /// \param user 用户
    /// \param pow  密码
    /// \param signature 特征码
    ///
    void initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief setCaptureTypeSlot 设置抓拍模式
    /// \param capType 相机抓拍模式
    /// \param msgCallBackInd 数据回调函数ID
    ///
    void setCaptureTypeSlot(const int &capType, const int &msgCallBackInd)Q_DECL_OVERRIDE;

    ///
    /// \brief initializationParameter 初始化动态库
    ///
    void slot_initializationParameter()Q_DECL_OVERRIDE;

    ///
    /// \brief slot_exceptionCode 相机异常
    /// \param dwType 错误码
    /// \param lUserID 相机ID
    ///
    void slot_exceptionCode(unsigned long dwType,  long lUserID)Q_DECL_OVERRIDE;
    
private:

    ///
    /// \brief initVideoStream 视频流抓图
    /// \param ID
    /// \param play
    ///
    void initVideoStream(int ID, bool play);

    ///
    /// \brief loadDecodingPlugin 加载视频解码插件
    ///
    void loadDecodingPlugin();

private slots:

    ///
    /// \brief getDeviceStatusSlot 获取设备运行状态
    /// \param lUserID 登录ID
    /// \return
    ///
    void getDeviceStatusSlot();

    ///
    /// \brief slot_handleFinished 异步打开解码完成
    ///
    void slot_handleFinished();

    ///
    /// \brief resizeEventSlot 通知动态库调整窗口
    ///
    void resizeEventSlot();//Q_DECL_OVERRIDE;

signals:

    ///
    /// \brief signal_getPictureStream 抓取图片
    /// \param putID
    ///
    void signal_getPictureStream(int putID,long lReadHandle);

    ///
    /// \brief signal_releaseResources 释放动态库资源
    ///
    void signal_releaseResources(int ID);

private:

    QString localAddr;
    long streamID;

    QMap<int,LONG> playInfoMap;
    QMap<int,LONG> alarmInfoMap;
    QMap<LPNET_DVR_USER_LOGIN_INFO,int> logInfoMap;

    ///
    /// \brief isSDKInit 动态库初始化状态
    ///
    bool isSDKInit;

    ///
    /// \brief imgBuff 图片流内存(主动申请和释放)
    ///
    char* imgBuff;

    ///
    /// \brief charLen 图片缓冲区大小
    ///
    uint32_t charLen;

    ///
    /// \brief pTimerState 相机状态定时器
    ///
    QTimer* pTimerState;

    ///
    /// \brief DeviceInfo 相机参数
    ///
    NET_DVR_DEVICEINFO_V40 DeviceInfo={};

    ///
    /// \brief manualsnap 手动抓拍参数
    ///
    NET_DVR_MANUALSNAP manualsnap={};

    ///
    /// \brief pJpegFile 图像信息
    ///
    NET_DVR_JPEGPARA   pJpegFile={};

    ///
    /// \brief snapcfg 触发参数结构体
    ///
    NET_DVR_SNAPCFG snapcfg={};

    ///
    /// \brief putID 当前抓图ID
    ///
    int putID;

    ///
    /// \brief CAMERA_TYPE 抓拍模式
    ///
    int CAMERA_TYPE;

    ///
    /// \brief MSGID 回调函数ID
    ///
    int MSGID;

    ///
    /// \brief InfraredlogicLit 视频解码插件库
    ///
    QList<QSharedPointer<IDecodingVideo>> IDecodingVideoLit;

    ///
    /// \brief tdList 子线程集
    ///
    QList<QThread*> tdList;

    ///
    /// \brief plateAddrList 车牌地址列表
    ///
    QStringList plateAddrList;

    ///
    /// \brief platePutIDList 车牌绑定ID
    ///
    QList<int> platePutIDList;

    ///
    /// \brief watcher 监视异步加载插件完成状态
    ///
    QFutureWatcher<void> *watcher;

    ///
    /// \brief initVidoeMap 初始化解码器列表
    ///
    QMap<long,bool> initVidoeMap;
};

#endif // MIDDLEWAREHCNET_H
