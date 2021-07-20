#ifndef LICENSEPLATEHCNET_H
#define LICENSEPLATEHCNET_H

#include "LicensePlateHCNET_global.h"
#include "licenseplateinterface.h"

class LICENSEPLATEHCNET_EXPORT LicensePlateHCNET:public LicensePlateInterface
{
    Q_OBJECT
    Q_INTERFACES(LicensePlateInterface)
    Q_PLUGIN_METADATA(IID LicensePlateInterfaceIID)

public:
    LicensePlateHCNET(QObject *parent=nullptr);
    ~LicensePlateHCNET()Q_DECL_OVERRIDE;

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
    ///
    void initCamerSlot(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief getLastPlateSlot 获取最后一次车牌数据
    ///
    void getLastPlateSlot()Q_DECL_OVERRIDE;

private:

    ///
    /// \brief initializationParameter 初始化参数
    /// \param addr 地址
    /// \param port 端口
    /// \param imgPath 图片路径
    /// \param channel 通道号
    ///
    bool initializationParameter();

//private slots:
//    ///
//    /// \brief getDeviceStatusSlot 获取设备运行状态
//    /// \param lUserID 登录ID
//    /// \return
//    ///
//    void getDeviceStatusSlot();

//    ///
//    /// \brief slot_imgGetTimeOut 取图片超时
//    ///
//    void slot_imgGetTimeOut();

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
    void slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_equipmentState  设备额在线状态
    /// \param state
    ///
    void slot_equipmentState(int ID, bool state)Q_DECL_OVERRIDE;

    int camerID;
    int imgNumber;
    QString camerIP,imgTime;
    QString signature;
    QString localAddr;

    bool put;
    //QTimer *imgGetTimeOut;
};

#endif // LICENSEPLATEHCNET_H
