#ifndef THELICENSEPLATE_WTY_INTERFACE_H
#define THELICENSEPLATE_WTY_INTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>

class TheLicensePlate_WTY_Interface : public QObject
{
    Q_OBJECT

public:
    virtual ~ TheLicensePlate_WTY_Interface(){}

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

    ///
    /// \brief imageFlowSignal 图片流
    /// \param img
    ///
    void imageFlowSignal(QByteArray img);

    ///
    /// \brief theVideoStreamSignal 视频流
    /// \param stream
    ///
    void theVideoStreamSignal(QByteArray arrImg);

    ///
    /// \brief resultsTheLicensePlateSignal 车牌结果
    /// \param plate
    ///
    void resultsTheLicensePlateSignal(const QString &plate,const QString &color,const QString &time,QByteArray arrImg);

    ///
    /// \brief equipmentState  设备在线状态
    /// \param state
    ///
    void equipmentStateSignal( bool state);

public slots:

    ///
    /// \brief initCameraSlot 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 相机地址
    /// \param port 端口
    /// \param imgPath 图片地址
    /// \param channel 通道号
    ///
    virtual void initCameraSlot(const QString &localAddr,const QString &addr, const int &port, const QString &imgPath, int imgFormat,const int &channel)=0;

    ///
    /// \brief simulationCaptureSlot 模拟抓拍
    ///
    virtual void simulationCaptureSlot()=0;

    ///
    /// \brief liftingElectronicRailingSlot 抬杆/落杆
    ///
    virtual void liftingElectronicRailingSlot(bool gate)=0;

    ///
    /// \brief transparentTransmission485Slot 透明传输
    /// \param dmsg
    ///
    virtual void transparentTransmission485Slot(const QString &msg)=0;

    ///
    /// \brief openTheVideoSlot 打开视频/关闭视频
    /// \param play
    ///
    virtual void openTheVideoSlot(bool play)=0;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    virtual void releaseResourcesSlot()=0;
};

#define TheLicensePlate_WTY_InterfaceIID "ZBY.ContainerServer.TheLicensePlate_WTY_Interface/1.0"
Q_DECLARE_INTERFACE(TheLicensePlate_WTY_Interface,TheLicensePlate_WTY_InterfaceIID);

#endif // THELICENSEPLATE_WTY_INTERFACE_H
