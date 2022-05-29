#ifndef IDENTIFYIMAGES_H
#define IDENTIFYIMAGES_H

#include "identifyimages_global.h"
#include "recognizerinterface.h"
#include "recognition.h"

#include "tcpclient.h"

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

    ///
    /// \brief client Socket识别箱号
    ///
    TcpClient* client;

    ///
    /// \brief rstMap 识别结果集
    ///
    QMap<int,QString> rstMap;

    ///
    /// \brief imgMap 图片集
    ///
    QMap<int,QString> imgMapL;

    ///
    /// \brief rstMapTcp socket识别器结果集
    ///
    QMap<QString,QString> rstMapTcp;

    ///
    /// \brief isDecectConnect 识别器链接状态
    ///
    bool isDecectConnect;

    ///
    /// \brief sendRstTime 延时发送识别结果
    ///
    QTimer* sendRstTime;

    ///
    /// \brief timeCout TCP识别器检测计时
    ///
    int timeCout;

private slots:

    ///
    /// \brief recognitionResultSlot 识别结果
    /// \param result 识别结果
    /// \param imgName 图片名
    ///
    void recognitionResultSlot(const QString &result,const QString& imgName,const int& imgNumber);

    ///
    /// \brief decectSatus 识别器状态
    /// \param status
    ///
    void decectSatusSlot(bool status);

    ///
    /// \brief decectRstSlot 识别结果
    /// \param rst
    ///
    void decectRstSlot(const QString& rst);

    ///
    /// \brief processDataSlot 处理结果集
    ///
    void processDataSlot();

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
    void identifyImagesSlot(QMap<int,QString> imgMap)Q_DECL_OVERRIDE;

    ///
    /// \brief identifyDogStatusSlot 识别器加密狗状态
    /// \param status
    ///
    void identifyDogStatusSlot(bool status)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

signals:

    ///
    /// \brief decectTcpImageSignal TCP识别箱号
    /// \param image
    ///
    void decectTcpImageSignal(const QString& image,const int& imgNum);

    ///
    /// \brief releaseResourcesSignal 释放资源
    ///
    void releaseResourcesSignal();
};

#endif // IDENTIFYIMAGES_H
