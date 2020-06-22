#ifndef DATABASEWRITEINTERFACE_H
#define DATABASEWRITEINTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>
#include <QMap>
#include <QSqlTableModel>

class DatabaseWriteInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~ DatabaseWriteInterface(){}

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief initDatabaseSlot 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    ///
    virtual void initDatabaseSlot(const QString &connectName,const QString &user,const QString &pass,const QString &ip)=0;

    ///
    /// \brief insertDatabaseSlot 插入数据库
    /// \param data 数据字典
    ///
    virtual void insertDatabaseSlot(QMap<QString, QString> data)=0;

    ///
    /// \brief updateDatabaseSlot 更新数据
    /// \param data 数据字典
    ///
    virtual void updateDatabaseSlot(QMap<QString, QString> data)=0;
};

#define DatabaseWriteInterfaceIID "ZBY.ContainerServer.DatabaseWriteInterface/1.0"
Q_DECLARE_INTERFACE(DatabaseWriteInterface,DatabaseWriteInterfaceIID)

#endif // DATABASEWRITEINTERFACE_H
