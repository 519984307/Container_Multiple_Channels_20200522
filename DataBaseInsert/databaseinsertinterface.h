#ifndef DATABASELOGICINTERFACE_H
#define DATABASELOGICINTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>
#include <QMap>
#include <QSqlTableModel>

class DataBaseInsertInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~DataBaseInsertInterface() {}

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    virtual QString InterfaceType()=0;

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief initDataBaseSlot 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    virtual void initDataBaseSlot(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType)=0;

    ///
    /// \brief insertDataBaseSlot 插入数据库
    /// \param data 数据字典
    ///
    virtual void insertDataBaseSlot(QMap<QString, QString> data)=0;

    ///
    /// \brief updateDataBaseSlot 更新数据
    /// \param data 数据字典
    ///
    virtual void updateDataBaseSlot(QMap<QString, QString> data)=0;
};

#define DataBaseInsertInterfaceIID "ZBY.ContainerServer.DataBaseInsertInterface/1.2.2"
Q_DECLARE_INTERFACE(DataBaseInsertInterface,DataBaseInsertInterfaceIID);

#endif // DATABASELOGICINTERFACE_H
