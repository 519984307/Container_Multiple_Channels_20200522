#ifndef LICENSEPLATEVZ_H
#define LICENSEPLATEVZ_H

#include "LicensePlateVZ_global.h"
#include "licenseplateinterface.h"
#include "VzLPRClientSDK.h"

class LICENSEPLATEVZ_EXPORT LicensePlateVZ:public LicensePlateInterface
{
    Q_OBJECT
    Q_INTERFACES(LicensePlateInterface)
    Q_PLUGIN_METADATA(IID LicensePlateInterfaceIID)

public:
    LicensePlateVZ(QObject *parent=nullptr);
    ~LicensePlateVZ()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

    ///
    /// \brief simulationCaptureSlot 模拟抓拍
    ///
    void simulationCaptureSlot()Q_DECL_OVERRIDE;

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
    /// \brief openTheVideoSlot 打开视频/关闭视频
    /// \param play
    ///
    void openTheVideoSlot(bool play,quint64 winID=0)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief initCameraSlot 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 相机地址
    /// \param port 端口
    /// \param imgPath 图片地址
    /// \param channel 通道号
    /// \param signature 相机特征码
    ///
    void initCamerSlot(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief initializationParameter 初始化参数
    /// \param addr 地址
    /// \param port 端口
    /// \param imgPath 图片路径
    /// \param channel 通道号
    ///
    bool initializationParameter();

private:

    /*****************************
    * @brief:[IN] handle                   由VzLPRClient_Open函数获得的句柄
    [IN] pUserData             回调函数的上下文
    [IN] pResult            车牌信息数组首地址
    [IN] uNumPlates         车牌数组中的车牌个数
    [IN] eResultType        车牌识别结果类型
    [IN] pImgFul            当前帧的图像内容
    [IN] pImgPlateClip      当前帧中车牌区域的图像内容数组，其中的元素与车牌信息数组中的对应
    0表示成功，-1表示失败
    如果需要该回调函数返回截图内容 pImgFull 和pImgPlateClip，需要在设置回调函数（VzLPRClient_SetPlateInfoCallBack）时允许截图内容，否则该回调函数返回的这两个指针为空；,实时结果（VZ_LPRC_RESULT_REALTIME）的回调是不带截图内容的
    ******************************/
    static int PLATE_INFO_CALLBACK(VzLPRClientHandle handle, void *pUserData, const TH_PlateResult *pResult, unsigned  uNumPlates, VZ_LPRC_RESULT_TYPE  eResultType, const VZ_LPRC_IMAGE_INFO  *pImgFull, const VZ_LPRC_IMAGE_INFO  *pImgPlateClip);

    /*****************************
    * @brief:[IN] nSerialHandle VzLPRClient_SerialStart返回的句柄
    [IN] pRecvData      接收的数据的首地址
    [IN] uRecvSize            接收的数据的尺寸
    [IN] pUserData      回调函数上下文
    ******************************/
    static void SERIAL_RECV_DATA_CALLBACK(int nSerialHandle, const unsigned char *pRecvData, unsigned uRecvSize, void *pUserData);

    /*****************************
    * @brief:
    * [IN] handle            由VzLPRClient_Open函数获得的句柄
    [IN] pUserData      回调函数上下文
    [IN] eNotify           通用信息反馈类型
    [IN] pStrDetail            详细描述字符串
    ******************************/
    static void COMMON_NOTIFY_CALLBACK(VzLPRClientHandle handle, void *pUserData, VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail );

    /*****************************
    * @brief:[IN] handle 由VzLPRClient_Open函数获得的句柄
    0表示成功，-1表示失败
    ******************************/
    typedef int (*VzLPRClient_ForceTriggerExFUN)(VzLPRClientHandle handle);
    ///
    /// \brief VzLPRClient_ForceTriggerEx_L 扩展接口，以Tcp方式发送软件触发信号，强制处理当前时刻的数据并输出结果
    ///
    VzLPRClient_ForceTriggerExFUN VzLPRClient_ForceTriggerEx_L;

    /*****************************
    * @brief:[IN] handle    由VzLPRClient_Open函数获得的句柄
    [IN] func       识别结果回调函数，如果为NULL，则表示关闭该回调函数的功能
    [IN] pUserData 回调函数中的上下文
    [IN] bEnableImage 指定识别结果的回调是否需要包含截图信息：1为需要，0为不需要
    0表示成功，-1表示失败
    ******************************/
    typedef int (*VzLPRClient_SetPlateInfoCallBackFUN)(VzLPRClientHandle handle, VZLPRC_PLATE_INFO_CALLBACK func, void *pUserData, int bEnableImage);
    ///
    /// \brief VzLPRClient_SetPlateInfoCallBack_L 设置识别结果的回调函数
    ///
    VzLPRClient_SetPlateInfoCallBackFUN VzLPRClient_SetPlateInfoCallBack_L;

    /*****************************
    * @brief:[IN] handle 由VzLPRClient_Open函数获得的句柄
    [IN] hWnd 窗口的句柄
    播放的句柄，-1表示失败
    ******************************/
    typedef int (*VzLPRClient_StartRealPlayFUN)(VzLPRClientHandle handle, void *hWnd);
    ///
    /// \brief VzLPRClient_StartRealPlay_L 播放实时视频
    ///
    VzLPRClient_StartRealPlayFUN VzLPRClient_StartRealPlay_L;

    /*****************************
    * @brief:[IN] nPlayHandle 播放的句柄
    0表示成功，-1表示失败
    可用来停止播放来自函数VzLPRClient_StartRealPlay和VzLPRClient_StartRealPlayFrameCallBack的播放句柄,停止播放以后，该播放句柄就失效了
    ******************************/
    typedef int (*VzLPRClient_StopRealPlayFUN)(int nPlayHandle);
    ///
    /// \brief VzLPRClient_StopRealPlay_L 停止播放指定的播放句柄
    ///
    VzLPRClient_StopRealPlayFUN VzLPRClient_StopRealPlay_L;

    /*****************************
    * @brief:[IN] func 设备连接结果和状态，通过该回调函数返回
    [IN] pUserData 回调函数中的上下文
    0表示成功，-1表示失败
    ******************************/
    typedef int (*VZLPRClient_SetCommonNotifyCallBackFUN)(VZLPRC_COMMON_NOTIFY_CALLBACK func, void *pUserData);
    ///
    /// \brief VZLPRClient_SetCommonNotifyCallBack_L 设置设备连接反馈结果相关的回调函数
    ///
    VZLPRClient_SetCommonNotifyCallBackFUN VZLPRClient_SetCommonNotifyCallBack_L;

    /*****************************
    * @brief:[IN] nSerialHandle 由VzLPRClient_SerialStart函数获得的句柄
    [IN] pData         将要传输的数据块的首地址
    [IN] uSizeData     将要传输的数据块的字节数
    0表示成功，其他值表示失败
    ******************************/
    typedef int (*VzLPRClient_SerialSendFUN)(int nSerialHandle, const unsigned char *pData, unsigned uSizeData);
    ///
    /// \brief VzLPRClient_SerialSend_L 透明通道发送数据
    ///
    VzLPRClient_SerialSendFUN VzLPRClient_SerialSend_L;

    /*****************************
    * @brief:0表示成功，-1表示失败
    ******************************/
    typedef int (*VzLPRClient_CloseFUN)(VzLPRClientHandle handle);
    ///
    /// \brief VzLPRClient_Close_L 关闭一个设备
    ///
    VzLPRClient_CloseFUN VzLPRClient_Close_L;

    /*****************************
    * @brief:[IN] pStrIP 设备的IP地址
    [IN] wPort 设备的端口号
    [IN] pStrUserName 访问设备所需用户名
    [IN] pStrPassword  访问设备所需密码
    [IN] wRtspPort 流媒体的端口号,为0表示使用默认
    返回设备的操作句柄，当打开失败时，返回0
    ******************************/
    typedef VzLPRClientHandle  (*VzLPRClient_OpenExFUN)(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword, WORD wRtspPort);
    ///
    /// \brief VzLPRClient_OpenEx_L 打开一个设备
    ///
    VzLPRClient_OpenExFUN VzLPRClient_OpenEx_L;

    /*****************************
    * @brief:[IN] handle 由VzLPRClient_Open函数获得的句柄
    [IN/OUT] pStatus 输入获取状态的变量地址，输出内容为 1已连上，0未连上
    0表示成功，-1表示失败
    ******************************/
    typedef int (*VzLPRClient_IsConnectedFUN)(VzLPRClientHandle handle, BYTE *pStatus);
    ///
    /// \brief VzLPRClient_IsConnected_L 获取连接状态
    ///
    VzLPRClient_IsConnectedFUN VzLPRClient_IsConnected_L;

    typedef void (*VzLPRClient_CleanupFUN)();
    ///
    /// \brief VzLPRClient_Cleanup_L 在程序结束时调用，释放SDK的资源
    ///
    VzLPRClient_CleanupFUN VzLPRClient_Cleanup_L;

    typedef int (*VzLPRClient_SetupFUN)();
    ///
    /// \brief VzLPRClient_Setup_L 全局初始化
    /// 0表示成功，-1表示失败
    ///
    VzLPRClient_SetupFUN VzLPRClient_Setup_L;

    /*****************************
    * @brief:返回值：返回值为0表示成功，返回其他值表示失败
    ******************************/
    typedef int (*VzLPRClient_GetLastErrorFUN)();
    ///
    /// \brief VzLPRClient_GetLastError_L 获取错误信息
    ///
    VzLPRClient_GetLastErrorFUN VzLPRClient_GetLastError_L;

    QString localAddr;
    QString camerIP;
    QString camerUser;
    QString camerPow;
    QString signature;
    int camerPort;

    bool isSDKinit;
    QLibrary* pDLL;

    QByteArray arrAddr;
    QMutex mutex;

    static LicensePlateVZ *pThis;

private slots:

    ///
    /// \brief autoLinkCamer 链接事变自动重连
    ///
    void autoLinkCamer();

    /*****************************
    * @brief:海康相机其它实现
    ******************************/
public:
    ///
    /// \brief slot_pictureStream 分发图片数据
    /// \param ID
    /// \param arrJpg
    ///
    void slot_pictureStream(int ID,QByteArray arrJpg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_setCameraID 设置通道登录相机ID
    /// \param ID 登录ID
    /// \param cameraIP 相机地址
    ///
    void slot_setCameraID(int ID,QString cameraIP)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_resultsTheLicensePlate 车牌结果
    /// \param plate
    ///
    void slot_resultsTheLicensePlate(int ID,const QString &plate,const QString &color,const QString &time,const QByteArray &arrImg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_equipmentState  设备额在线状态
    /// \param state
    ///
    void slot_equipmentState(int ID, bool state)Q_DECL_OVERRIDE;

    /*****************************
    * @brief:海康相机其它实现
    ******************************/
};

#endif // LICENSEPLATEVZ_H
