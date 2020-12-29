#ifndef DATABASEREAD_H
#define DATABASEREAD_H

#include "databaseread_global.h"
#include "databasereadinterface.h"

class DATABASEREADSHARED_EXPORT DataBaseRead:public DataBaseReadInterface
{
    Q_OBJECT
    Q_INTERFACES(DataBaseReadInterface)
    Q_PLUGIN_METADATA(IID DataBaseReadInterfaceIID)

public:    
    DataBaseRead(QObject* parent=nullptr);
    ~DataBaseRead()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

public:

    ///
    /// \brief initDataBaseSlot 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    void initDataBaseSlot(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType)Q_DECL_OVERRIDE;


    ///
    /// \brief setDataBaseFilterSlot 设置数据库筛选条件
    /// \param filter 筛选条件
    ///
    void setDataBaseFilterSlot(const QString &filter)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief statisticalData 统计数据
    ///
    void statisticalData(QSqlTableModel *model);


private:

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

#endif // DATABASEREAD_H
