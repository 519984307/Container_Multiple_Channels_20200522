﻿#ifndef ICAPTUREIMAGES_H
#define ICAPTUREIMAGES_H

#include <QObject>

class ICaptureImages:public QObject
{
    Q_OBJECT

public:
    virtual ~ICaptureImages(){}

signals:

    ///
    /// \brief camerStateSingals 相机连接状态信号
    /// \param camerIP 相机地址
    /// \param state 相机连接状态
    ///
    void camerStateSingal(const QString &camerIP,bool state);

    ///
    /// \brief pictureStreamSignals 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void pictureStreamSignal(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");

    ///
    /// \brief videoStreamSignal 视频流信号
    /// \param jpgStream 视频流
    ///
    void videoStreamSignal(const QByteArray &jpgStream);

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief initCamerSlots 初始化相机
    /// \param camerIP 相机地址
    /// \param camerPort 相机端口
    /// \param CamerUser 用户名
    /// \param CamerPow 密码
    /// \param signature 特征码
    ///
    virtual void initCamerSlot(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)=0;

    ///
    /// \brief putCommandSlots 抓取图片
    /// \param command 图片编号
    /// \param imgTime 时间戳
    /// \param signature 特征码
    ///
    virtual bool putCommandSlot( int imgNumber, QString imgTime,const QString &signature)=0;

    ///
    /// \brief playViedoStreamSlot 预览实时视频
    /// \param winID 窗口句柄
    /// \param play 播放状态
    /// \param signature 特征码
    /// 海康相机：多次实时预览,linux出现内存不释放
    ///
    virtual void playStreamSlot(quint64 winID,bool play,const QString &signature)=0;

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
    /// \brief resizeEventSlot 调整窗口通知动态库刷新窗口
    /// 海康相机：linux需要通知窗口变化，window自适应
    ///
    virtual void resizeEventSlot()=0;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    virtual void releaseResourcesSlot()=0;

    ///
    /// \brief InitializationSlot 初始化参数
    ///
    virtual bool InitializationSlot()=0;


    /*****************************
    * @brief:相机中间件接口
    ******************************/
public slots:
    ///
    /// \brief slot_pictureStream 分发图片数据
    /// \param ID
    /// \param arrJpg
    ///
    virtual void slot_pictureStream(int ID,QByteArray arrJpg)=0;

    ///
    /// \brief slot_setCameraID 设置通道登录相机ID
    /// \param ID 登录ID
    /// \param cameraIP 相机地址
    ///
    virtual void slot_setCameraID(int ID,QString cameraIP)=0;

    ///
    /// \brief slot_resultsTheLicensePlate 车牌结果
    /// \param plate
    ///
    virtual void slot_resultsTheLicensePlate(int ID,const QString &plate,const QString &color,const QString &time,QByteArray arrImg)=0;

    ///
    /// \brief slot_equipmentState  设备额在线状态
    /// \param state
    ///
    virtual void slot_equipmentState(int ID, bool state)=0;

signals:

    ///
    /// \brief signal_initCamera 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 地址
    /// \param port 端口
    /// \param user 用户
    /// \param pow  密码
    ///
    void signal_initCamera(const QString &localAddr, const QString &addr, const int &port, const QString &user, const QString &pow);

    ///
    /// \brief signal_openTheVideo 打开视频/关闭视频
    /// \param play
    ///
    void signal_openTheVideo(int ID, bool play,quint64 winID);

    ///
    /// \brief signal_simulationCapture 模拟抓拍
    ///
    void signal_simulationCapture(int ID);


    ///
    /// \brief signal_liftingElectronicRailing 抬杆/落杆
    ///
    void signal_liftingElectronicRailing(bool gate);

    ///
    /// \brief signal_transparentTransmission485 透明传输
    /// \param dmsg
    ///
    void signal_transparentTransmission485(const QString &msg);

    ///
    /// \brief signal_bindingCameraID 绑定相机地址和ID号
    /// \param cameraAddr
    /// \param ID
    ///
    void signal_bindingCameraID(QString cameraAddr,int ID);
};

#define ICaptureImagesIID "ZBY.ContainerServer.ICaptureImages/1.1.1.2"
Q_DECLARE_INTERFACE(ICaptureImages,ICaptureImagesIID);

#endif // ICAPTUREIMAGES_H
