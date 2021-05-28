#ifndef IDENTIFYIMAGES_H
#define IDENTIFYIMAGES_H

#include "identifyimages_global.h"
#include "recognizerinterface.h"
#include "recognition.h"

class IDENTIFYIMAGESSHARED_EXPORT IdentifyImages:public RecognizerInterface
{
    Q_OBJECT
    Q_INTERFACES(RecognizerInterface)
    Q_PLUGIN_METADATA(IID RecognizerInterfaceIID)

public:
    IdentifyImages(QObject* parent=nullptr);
    ~IdentifyImages()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

private:
    QThreadPool* pPool;

    ///
    /// \brief dogStatus 加密状态
    ///
    bool dogStatus;

public:

    ///
    /// \brief identifyStreamSlot 图片流
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    ///
    void identifyStreamSlot(const QByteArray &jpgStream,const int &imgNumber)Q_DECL_OVERRIDE;

    ///
    /// \brief identifyResults 识别图片
    /// \param imgName  图片名
    /// \param imgNumber 图片编号
    ///
    void identifyImagesSlot(const QString &imgName,const int &imgNumber)Q_DECL_OVERRIDE;

    ///
    /// \brief identifyDogStatusSlot 识别器加密狗状态
    /// \param status
    ///
    void identifyDogStatusSlot(bool status)Q_DECL_OVERRIDE;
};

#endif // IDENTIFYIMAGES_H
