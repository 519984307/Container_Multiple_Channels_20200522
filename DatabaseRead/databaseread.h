#ifndef DATABASEREAD_H
#define DATABASEREAD_H

#include "databaseread_global.h"
#include "databaseread_interface.h"

class DATABASEREADSHARED_EXPORT DatabaseRead:public DatabaseRead_Interface
{
    Q_OBJECT
    Q_INTERFACES(DatabaseRead_Interface)
    Q_PLUGIN_METADATA(IID DatabaseRead_InterfaceIID)

public:    
    DatabaseRead(QObject *parent=nullptr);
    ~DatabaseRead()Q_DECL_OVERRIDE;

    ///
    /// \brief initDatabaseSlot 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    ///
    void initDatabaseSlot(const QString &connectName="DataBaseRead",const QString &user="admin",const QString &pass="Zby123456",const QString &ip="localhost")Q_DECL_OVERRIDE;

    ///
    /// \brief setDatabaseFilterSlot 设置数据库筛选条件
    /// \param filter 筛选条件
    ///
    void setDatabaseFilterSlot(const QString &filter)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief statisticalData 统计数据
    ///
    void statisticalData(QSqlTableModel *model);

private:

    //QReadWriteLock locker;

    ///
    /// \brief connectName 数据库链接名称
    ///
    QString connectName;

    ///
    /// \brief db 数据库对象
    ///
    QSqlDatabase db;
};

#endif // DATABASEREAD_H
