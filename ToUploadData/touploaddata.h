#ifndef TOUPLOADDATA_H
#define TOUPLOADDATA_H

#include "touploaddata_global.h"
#include "touploaddata_interface.h"

class TOUPLOADDATASHARED_EXPORT ToUploadData:public ToUploadData_Interface
{
    Q_OBJECT
    Q_INTERFACES(ToUploadData_Interface)
    Q_PLUGIN_METADATA(IID ToUploadData_InterfaceIID)

public:

    ToUploadData(QObject *parent=nullptr);
    ~ToUploadData()Q_DECL_OVERRIDE;

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param host 地址
    /// \param port 端口
    /// \param path 路径
    /// \param user 用户名
    /// \param pass 密码
    ///
    void InitializationParameterSlot(const QString &user, const QString &pass, const QString &path, const QString &host,const int &port=21)Q_DECL_OVERRIDE;

    ///
    /// \brief uploadDataSlot 上传数据
    /// \param data 数据
    ///
    void uploadDataSlot(const QString &data)Q_DECL_OVERRIDE;

private slots:

    ///
    /// \brief replyFinishedSlot 上传完成
    ///
    void replyFinishedSlot(QNetworkReply* reply);

private:

    QString dataName;
    QString remotePath;
    QUrl url;
    QNetworkAccessManager *pManager;
};

#endif // TOUPLOADDATA_H
