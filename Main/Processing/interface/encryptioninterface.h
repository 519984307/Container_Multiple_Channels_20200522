#ifndef ENCRYPTIONINTERFACE_H
#define ENCRYPTIONINTERFACE_H

#include <QObject>

class EncryptionInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~EncryptionInterface(){}

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
    virtual void InitializationSlot(int dogType,QString dogIdd)=0;

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    virtual void releaseResourcesSlot()=0;

};

#define EncryptionInterfaceIID "ZBY.ContainerServer.EncryptionInterface/0.0.0.1"
Q_DECLARE_INTERFACE(EncryptionInterface,EncryptionInterfaceIID);

#endif // ENCRYPTIONINTERFACE_H
