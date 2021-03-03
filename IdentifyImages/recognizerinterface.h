#ifndef RECOGNIZERINTERFACE_H
#define RECOGNIZERINTERFACE_H

#include <QObject>

class RecognizerInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~RecognizerInterface() {}

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    virtual QString InterfaceType()=0;

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

    ///
    /// \brief recognitionResult 识别结果
    /// \param result 识别结果
    /// \param imgName 图片名
    /// \param imgNumber 图片编号
    ///
    void recognitionResultSignal(const QString &result,const QString& imgName,const int& imgNumber);

public slots:

    ///
    /// \brief identifyStreamSlot 图片流
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    ///
    virtual void identifyStreamSlot(const QByteArray &jpgStream,const int &imgNumber)=0;

    ///
    /// \brief identifyResults 识别图片
    /// \param imgName  图片名
    /// \param imgNumber 图片编号
    ///
    virtual void identifyImagesSlot(const QString &imgName,const int &imgNumber)=0;
};

#define RecognizerInterfaceIID "ZBY.ContainerServer.RecognizerInterface/1.1.1"
Q_DECLARE_INTERFACE(RecognizerInterface,RecognizerInterfaceIID);

#endif // RECOGNIZERINTERFACE_H
