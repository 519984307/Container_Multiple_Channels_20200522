#ifndef DATAINTERREQUEST_H
#define DATAINTERREQUEST_H

#include "DataInterRequest_global.h"
#include "datainterchangeinterface.h"

#include "tcpclinet.h"

class DATAINTERREQUEST_EXPORT DataInterRequest:public DataInterchangeInterface
{
    Q_OBJECT
    Q_INTERFACES(DataInterchangeInterface)
    Q_PLUGIN_METADATA(IID DataInterchangeInterfaceIID)

public:
    DataInterRequest(QObject* parent=nullptr);
    ~DataInterRequest()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

public:

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param address 地址
    /// \param port 端口
    /// \param serviceType 服务类型
    /// \param heartBeat 心跳包 状态
    /// \param serviceMode 服务模式
    /// \param shortLink 短链接状态
    /// \param newline 换行符
    ///
    void  InitializationParameterSlot(const QString& address, const quint16& port, const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline)Q_DECL_OVERRIDE;

    ///
    /// \brief toSendDataSlot 发送数据
    /// \param data 数据体
    ///
    void toSendDataSlot(int channel_number,const QString& data)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief setImagePathSlot 设置图片路径，用于上传图片
    /// \param imgPath
    ///
    void setImagePathSlot(const QString &imgPath,int ImageFormat,int ImageNamingRules,int channel_id_placeholder,int camera_id_placeholder)Q_DECL_OVERRIDE;

private:

    /*****************************
    * @brief:上传数据
    ******************************/
    QNetworkAccessManager* pManager;
    QNetworkRequest request;

    /*****************************
    * @brief:上传图片
    ******************************/
    QNetworkRequest requestImg;
    QNetworkAccessManager* pManagerImg;

    QUrl url;

    QVector<QFile*> qFiles;

    ///
    /// \brief channel_number 通道编号
    ///
    int channel_number;

    QString address;

    ///
    /// \brief tmpData 临时数据
    ///
    QString tmpData;

    TcpClient* pTcpClient;

    ///
    /// \brief imgPath 图片路径
    ///
    QString imgPath;

    ///
    /// \brief ImageFormat 图片格式
    ///
    int ImageFormat;

    ///
    /// \brief ImageNamingRules 图片命名方式
    ///
    int ImageNamingRules;

    ///
    /// \brief channel_id_placeholder 通道命名方式
    ///
    int channel_id_placeholder;

    ///
    /// \brief camera_id_placeholder 相机命名方式
    ///
    int camera_id_placeholder;

private slots:

    ///
    /// \brief replyFinishedSlot 上传完成
    ///
    void replyFinishedSlot(QNetworkReply* reply);

    ///
    /// \brief slot_SslErrors SSL/TLS会话在设置过程中遇到错误，包括证书验证错误
    ///
    void slot_SslErrors(QList<QSslError> sslErr);

    ///
    /// \brief slot_Error 应答在处理过程中检测到错误
    ///
    void slot_Error(QNetworkReply::NetworkError err);

    ///
    /// \brief slot_finished 应答完成
    ///
    void slot_finished();

    ///
    /// \brief slot_upLoadImg 上传图片，本地使用
    /// \param msgMap
    ///
    void slot_upLoadImg(QMap<QString,QString> msgMap);

    ///
    /// \brief requestImgFinished 上传图片
    ///
    void requestImgFinished(QNetworkReply* reply);

signals:

    ///
    /// \brief signalSendData 发送识别结果
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void signalSendData(int channel_number,const QString& result);

    ///
    /// \brief signal_upLoadImg 上传图片，本地使用
    /// \param msgMap
    ///
    void signal_upLoadImg(QMap<QString,QString> msgMap);
};

#endif // DATAINTERREQUEST_H
