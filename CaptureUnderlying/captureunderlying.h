#ifndef CAPTUREUNDERLYING_H
#define CAPTUREUNDERLYING_H

#include "captureunderlying_global.h"
#include "ICaptureUnderlying.h"
#include "putcommand.h"
#include "IMiddleware.h"

class CAPTUREUNDERLYINGSHARED_EXPORT CaptureUnderlying:public IMiddleware
{
    Q_OBJECT
    Q_INTERFACES(IMiddleware)
    Q_PLUGIN_METADATA(IID  IMiddlewareIID)

public:
    CaptureUnderlying(QObject* parent=nullptr);
    ~CaptureUnderlying()Q_DECL_OVERRIDE;
    
    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

private:
    
    ///
    /// \brief initialization 初始化参数
    ///
    void initialization();
    
private slots:

    ///
    /// \brief connected 链接成功
    ///
    void connected();

    ///
    /// \brief readFortune 接收数据
    ///
    void readFortune();

    ///
    /// \brief disconnected 链接断开
    ///
    void disconnected();

    ///
    /// \brief displayError 链接错误
    /// \param socketError 链接状态码
    ///
    void displayError(QAbstractSocket::SocketError socketError);

    ///
    /// \brief startLinkCamer 连接相机
    ///
    void startLinkCamer();

    ///
    /// \brief cameraState 相机异常检测
    ///
    void cameraState();

private:

    ///
    /// \brief putState 接收本机抓拍指令
    ///
    bool putState;

    ///
    /// \brief stramCount 接收图片状态
    ///
    bool streamState;

    ///
    /// \brief pPutCommand 抓拍指令
    ///
    PutCommand* pPutCommand;

    ///
    /// \brief tcpSocket Socket
    ///
    QTcpSocket *tcpSocket;

    ///
    /// \brief pTimerLinkCamer 定时检测
    ///
    QTimer *pTimerLinkCamer;

    ///
    /// \brief camerIP 相机地址
    ///
    QString camerIP;

    ///
    /// \brief camerPort 相机端口
    ///
    int camerPort;

    ///
    /// \brief alias 相机名
    ///
    QString alias;

    ///
    /// \brief jpgStream 图片流
    ///
    QByteArray jpgStream;

    ///
    /// \brief imgNumber 图片编号
    ///
    int imgNumber;

    ///
    /// \brief imgTime 抓图时间戳
    ///
    QString imgTime;
    
    ///
    /// \brief ID 相机ID设置为socket本地端口
    ///
    int ID;

public:

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
    void initCameraSlot(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief setCaptureTypeSlot 设置抓拍模式
    /// \param capType
    ///
    void setCaptureTypeSlot(const int &capType,const int &msgCallBackInd)Q_DECL_OVERRIDE;

    ///
    /// \brief openTheVideoSlot 打开视频/关闭视频
    /// \param play
    ///
    void openTheVideoSlot(int ID, bool play,quint64 winID)Q_DECL_OVERRIDE;

    ///
    /// \brief simulationCaptureSlot 模拟抓拍
    ///
    void simulationCaptureSlot(int ID)Q_DECL_OVERRIDE;

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
    /// \brief closeStream 释放动态库资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

};

#endif // CAPTUREUNDERLYING_H
