#ifndef IDECODINGVIDEO_H
#define IDECODINGVIDEO_H

#include <QObject>

class IDecodingVideo : public QObject
{
    Q_OBJECT

public:
    virtual ~IDecodingVideo() {}

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    virtual QString InterfaceType()=0;

    ///
    /// \brief getCallBack 获取解码回调函数
    /// \return
    ///
    virtual void *getCallBack()=0;

    ///
    /// \brief getReadHanlde 获取播放ID
    /// \return
    ///
    virtual long getReadHanlde()=0;

    ///
    /// \brief setReadHanlde 设置播放ID
    /// \param handle
    ///
    virtual void setReadHanlde(long handle)=0;

signals:

    ///
    /// \brief signal_pictureStream 分发图片数据
    /// \param ID
    /// \param arrJpg
    ///
    void signal_pictureStream(int ID,QByteArray arrJpg);


public slots:

    ///
    /// \brief slot_getPictureStream 抓取图片
    /// \param putID
    ///
    virtual void slot_getPictureStream(int putID,long lReadHandle)=0;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    virtual void releaseResourcesSlot(int ID)=0;
};

#define IDecodingVideoIID "ZBY.ContainerServer.IDecodingVideo/1.0.0.4"
Q_DECLARE_INTERFACE(IDecodingVideo,IDecodingVideoIID);

#endif // IDECODINGVIDEO_H
