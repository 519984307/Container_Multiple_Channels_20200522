#ifndef CAPTUREIMAGES_H
#define CAPTUREIMAGES_H

#include "captureimages_global.h"
#include "ICaptureImages.h"

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

class CAPTUREIMAGESSHARED_EXPORT CaptureImages:public ICaptureImages
{
    Q_OBJECT
    Q_INTERFACES(ICaptureImages)
    Q_PLUGIN_METADATA(IID  ICaptureImagesIID)

public:
    CaptureImages(QObject *parent = nullptr);
    ~CaptureImages()Q_DECL_OVERRIDE;

public:

    ///
    /// \brief initCamerSlot 初始化相机
    /// \param camerIP 地址
    /// \param camerPort 端口
    /// \param user 用户名
    /// \param pow 密码
    ///
    void initCamerSlot(const QString &camerIP, const int & camerPort, const QString &CamerUser, const QString &CamerPow) Q_DECL_OVERRIDE;

    ///
    /// \brief putCommandSlot 抓取图片
    /// \param imgNumber 图片编号
    /// \return
    ///
    bool putCommandSlot(int imgNumber, QString imgTime) Q_DECL_OVERRIDE;

    ///
    /// \brief playStreamSlot 播放视频流
    /// \param winID 窗口句柄
    /// \param play 播放状态
    ///
    void playStreamSlot(quint64 winID, bool play) Q_DECL_OVERRIDE;

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
    /// \brief releaseResourcesSlot 释放资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief resizeEventSlot 通知动态库调整窗口
    ///
    void resizeEventSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief InitializationSlot 初始化参数
    ///
    bool InitializationSlot()Q_DECL_OVERRIDE;

private slots:
    ///
    /// \brief getDeviceStatusSlot 获取设备运行状态
    /// \param lUserID 登录ID
    /// \return
    ///
    void getDeviceStatusSlot();

    ///
    /// \brief slot_imgGetTimeOut 去图片超时
    ///
    void slot_imgGetTimeOut();


    /*****************************
    * @brief:相机中间件接口
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
    void slot_resultsTheLicensePlate(int ID,const QString &plate,const QString &color,const QString &time,QByteArray arrImg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_equipmentState  设备额在线状态
    /// \param state
    ///
    void slot_equipmentState(int ID, bool state)Q_DECL_OVERRIDE;

    int camerID;
    int imgNumber;
    QString camerIP,imgTime;
    bool put;
    QTimer *imgGetTimeOut;
};

#endif // CAPTUREIMAGES_H