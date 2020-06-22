#ifndef IDENTIFYIMAGES_H
#define IDENTIFYIMAGES_H

#include "identifyimages_global.h"
#include "recognizer_interface.h"
#include "recognition.h"

class IDENTIFYIMAGESSHARED_EXPORT IdentifyImages:public Recognizer_Interface
{
    Q_OBJECT
    Q_INTERFACES(Recognizer_Interface)
    Q_PLUGIN_METADATA(IID Recognizer_InterfaceIID)

public:
    IdentifyImages(QObject* parent=nullptr);
    ~IdentifyImages()Q_DECL_OVERRIDE;

private:
    QThreadPool* pPool;

public:

    ///
    /// \brief pictureStreamSlot 图片流
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    ///
    void pictureStreamSlot(const QByteArray &jpgStream,const int &imgNumber)Q_DECL_OVERRIDE;

    ///
    /// \brief identifyResults 识别图片
    /// \param image  图片名
    ///
    void identifyImagesSlot(const QString &image)Q_DECL_OVERRIDE;
};

#endif // IDENTIFYIMAGES_H
