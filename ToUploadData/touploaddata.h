#ifndef TOUPLOADDATA_H
#define TOUPLOADDATA_H

#include "touploaddata_global.h"
#include "touploaddatainterface.h"

class TOUPLOADDATASHARED_EXPORT ToUploadData:public ToUploadDataInterface
{
    Q_OBJECT
    Q_INTERFACES(ToUploadDataInterface)
    Q_PLUGIN_METADATA(IID ToUploadDataInterfaceIID)

public:

    ToUploadData(QObject *parent=nullptr);
    ~ToUploadData()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param host 地址
    /// \param port 端口
    /// \param path 路径
    /// \param user 用户名
    /// \param pass 密码
    ///
    void InitializationParameterSlot(const QString &user, const QString &pass, const QString &path, const QString &host, const int &port=21)Q_DECL_OVERRIDE;

    ///
    /// \brief uploadDataSlot 上传数据
    /// \param data 数据
    ///
    void uploadDataSlot(const QString &data)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

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
    /// \brief slot_uploadProgress 上传进度
    /// \param bytesSent
    /// \param bytesTotal
    ///
    void slot_uploadProgress(qint64 bytesSent, qint64 bytesTotal);

signals:

    ///
    /// \brief theProgressOfSignal 上传进度
    /// \param bytesSent 上传大小
    /// \param bytesTotal 上传总量
    ///
    void theProgressOfSignal(qint64 bytesSent, qint64 bytesTotal);

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);


private:

    QString dataName;
    QNetworkRequest request;
    QMutex mutex;
    QUrl url;
    QString remotePath;
    QNetworkAccessManager *pManager;
};

#endif // TOUPLOADDATA_H
