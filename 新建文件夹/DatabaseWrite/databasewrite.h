#ifndef DATABASEWRITE_H
#define DATABASEWRITE_H

#include "databasewrite_global.h"
#include "databasewrite_interface.h"

class DATABASEWRITESHARED_EXPORT DatabaseWrite:public DatabaseWrite_Interface
{
    Q_OBJECT
    Q_INTERFACES(DatabaseWrite_Interface)
    Q_PLUGIN_METADATA(IID DatabaseWrite_InterfaceIID)

public:
    DatabaseWrite(QObject *parent=nullptr);
    ~DatabaseWrite()Q_DECL_OVERRIDE;

    ///
    /// \brief initDatabaseSlot 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    ///
    void initDatabaseSlot(const QString &connectName,const QString &user="admin",const QString &pass="Zby123456",const QString &ip="127.0.0.1")Q_DECL_OVERRIDE;

    ///
    /// \brief insertDatabaseSlot 写入数据
    /// \param dataHash 数据字典
    ///
    void insertDatabaseSlot(QMap<QString, QString> data)Q_DECL_OVERRIDE;

    ///
    /// \brief updateDatabaseSlot 更新数据库
    /// \param data 数据字典
    ///
    void updateDatabaseSlot(QMap<QString, QString> data)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief locker 数据锁
    ///
    QReadWriteLock locker;

    ///
    /// \brief connectName 数据库链接名称
    ///
    QString connectName;

    ///
    /// \brief db 数据库对象
    ///
    QSqlDatabase db;
};

#endif // DATABASEWRITE_H
