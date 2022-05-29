#ifndef TOUPLOADDATA2_H
#define TOUPLOADDATA2_H

#include "ToUploadData2_global.h"
#include "touploaddatainterface.h"
#include "libs/Include/qftp.h"

class TOUPLOADDATA2_EXPORT ToUploadData2:public ToUploadDataInterface
{
    Q_OBJECT
    Q_INTERFACES(ToUploadDataInterface)
    Q_PLUGIN_METADATA(IID ToUploadDataInterfaceIID)

public:

    ToUploadData2(QObject *parent=nullptr);
    ~ToUploadData2()Q_DECL_OVERRIDE;

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
    void InitializationParameterSlot(const QString &user, const QString &pass, const QString &path,const bool &time, const QString &host, const int &port=21)Q_DECL_OVERRIDE;

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

    void slot_commandFinished ( int id, bool error );
    void slot_commandStarted ( int id );
    void slot_done ( bool error );

    ///
    /// \brief slot_uploadProgress 上传进度
    /// \param bytesSent
    /// \param bytesTotal
    ///
    void slot_uploadProgress(qint64 bytesSent, qint64 bytesTotal);

    ///
    /// \brief slot_stateChanged ftp链接状态
    /// \param state
    ///
    void slot_stateChanged(int state);

    ///
    /// \brief slot_linkTime 超时链接
    ///
    void slot_linkTime();

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

    QFtp* pFtp;
    QMutex mutex;
    QString remotePath;

    bool time;
    int port;
    QString host,user,pass;

    QTimer* linkT;
};

#endif // TOUPLOADDATA2_H
