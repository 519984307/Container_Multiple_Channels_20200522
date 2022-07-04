#ifndef LICENSEPLATETCP_H
#define LICENSEPLATETCP_H

#include "licensePlateTCP_global.h"
#include "licenseplateinterface.h"
#include "tcpserver.h"

class LICENSEPLATETCP_EXPORT LicensePlateTCP:public LicensePlateInterface
{
    Q_OBJECT
    Q_INTERFACES(LicensePlateInterface)
    Q_PLUGIN_METADATA(IID LicensePlateInterfaceIID)

public:
    LicensePlateTCP(QObject *parent=nullptr);
    ~LicensePlateTCP()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

private:

    TcpServer* pTcpServer;

public:

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
    /// \brief getLastPlateSlot 获取最后一次车牌数据
    ///
    void getLastPlateSlot()Q_DECL_OVERRIDE;

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

private slots:

    ///
    /// \brief slot_ResultPlate 接收车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    /// \param time
    ///
    void slot_ResultPlate(int channel, QString plate, QString color, QString time, QString addr);

    ///
    /// \brief slot_EquipmentState  设备额在线状态
    /// \param state
    ///
    void slot_EquipmentState(const QString &camerIP, bool state);
};

#endif // LICENSEPLATETCP_H
