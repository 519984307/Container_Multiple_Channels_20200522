 
#ifndef ENCRYPTION_INTERFACE_H
#define ENCRYPTION_INTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)
#include <QObject>

class Encryption_Interface : public QObject
{
    Q_OBJECT

public:
    virtual ~Encryption_Interface(){}

signals:

    ///
    /// \brief GetEncryptedInformation 获取加密信息
    /// \param data 数据
    ///
    void GetEncryptedInformationSignal(const QString& data);

    ///
    /// \brief GetTheEncryptedState 获取加密状态
    /// \param state
    ///
    void GetTheEncryptedStateSignal(bool state);

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief InitializationSlot 初始化参数
    ///
    virtual void InitializationSlot()=0;

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    virtual void releaseResourcesSlot()=0;

};

#define Encryption_InterfaceIID "ZBY.ContainerServer.Encryption_Interface/1.0"
Q_DECLARE_INTERFACE(Encryption_Interface,Encryption_InterfaceIID);

#endif // ENCRYPTIONINTERFACE_H
