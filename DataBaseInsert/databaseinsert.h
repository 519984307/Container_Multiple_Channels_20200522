﻿#ifndef DATABASEINSERT_H
#define DATABASEINSERT_H

#include "databaseinsert_global.h"
#include "databaseinsertinterface.h"

class DATABASEINSERTSHARED_EXPORT DataBaseInsert:public DataBaseInsertInterface
{
    Q_OBJECT
    Q_INTERFACES(DataBaseInsertInterface)
    Q_PLUGIN_METADATA(IID DataBaseInsertInterfaceIID)

public:
    DataBaseInsert(QObject* parent=nullptr);
    ~DataBaseInsert()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

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
    /// \brief insertDataBaseSlot 写入数据
    /// \param dataHash 数据字典
    ///
    void insertDataBaseSlot(QMap<QString, QString> data)Q_DECL_OVERRIDE;

    ///
    /// \brief updateDataBaseSlot 更新数据库
    /// \param data 数据字典
    ///
    void updateDataBaseSlot(QMap<QString, QString> data)Q_DECL_OVERRIDE;

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

#endif // DATABASEINSERT_H
