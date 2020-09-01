#ifndef ICAPTUREIMAGESHCNET_H
#define ICAPTUREIMAGESHCNET_H

#define IMG_BYTE 1920*1080+1

#include <QObject>

class ICaptureImagesHCNET : public QObject
{
    Q_OBJECT

public:
    virtual ~ ICaptureImagesHCNET(){}

signals:

    /// \brief camerStateSingals 相机连接状态信号
    /// \param camerIP 相机地址
    /// \param state 相机连接状态
    ///
    void camerStateSingal(const QString &camerIP,bool state,const QString& alias);

    ///
    /// \brief pictureStreamSignals 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void pictureStreamSignal(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");

public slots:

    ///
    /// \brief initCamerSlots 初始化相机
    /// \param camerIP 相机地址
    /// \param camerPort 相机端口
    /// \param 用户名
    /// \param 密码
    ///
    virtual void initCamerSlot(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString& alias)=0;

    ///
    /// \brief putCommandSlots 抓取图片
    /// \param command 图片编号
    /// \param imgTime 时间戳
    ///
    virtual bool putCommandSlot(const int &imgNumber,const QString &imgTime)=0;

    ///
    /// \brief playViedoStreamSlot 预览实时视频
    /// \param winID 窗口句柄
    /// \param play 播放状态
    /// 多次实时预览,在LINUX下会出现内存不释放
    ///
    virtual void playStreamSlot(quint64 winID,bool play)=0;

    ///
    /// \brief resizeEventSlot 调整窗口通知动态库刷新窗口
    /// linux下需要,windows不需要
    ///
    virtual void resizeEventSlot()=0;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    virtual void releaseResourcesSlot()=0;
};

#define ICaptureImagesHCNET_IID "ZBY.ContainerServer.ICaptureImagesHCNET/1.1"
Q_DECLARE_INTERFACE(ICaptureImagesHCNET,ICaptureImagesHCNET_IID);


#endif // ICAPTUREIMAGESHCNET_H