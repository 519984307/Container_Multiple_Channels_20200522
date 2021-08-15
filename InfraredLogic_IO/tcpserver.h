#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "InfraredLogic_IO_global.h"
#include "tcpclient.h"

#include <QSharedPointer>
#include <QDebug>
#include <QPointer>

class TcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent=nullptr);
    ~TcpServer();

    ///
    /// \brief InitializationParameter 初始化参数
    ///
    void InitializationParameter();

    ///
    /// \brief incomingConnection 重写客户端接入
    /// \param handle
    ///
    void incomingConnection(qintptr socketID);

private:

    ///
    /// \brief clientSocketIdMap 客户端字典
    ///
    QMap<qintptr,TcpClient*> clientSocketIdMap;

    ///
    /// \brief tmpStatus 临时红外信号
    ///
    int tmpStatus[8];

public slots:

    ///
    /// \brief disconnectedSlot 客户端断开信号(从客户端列表删除断开的客户端)
    ///
    void disconnectedSlot();

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    void releaseResourcesSlot();

    ///
    /// \brief toSendDataSlot 发送数据
    /// \param channel_number
    /// \param result
    ///
    void toSendDataSlot(int channel_number, const QString &result);

signals:

    ///
    /// \brief connectCountSignal 链接数量
    /// \param count
    ///
    void connectCountSignal(int count);

    ///
    /// \brief logicStatus 红外信号状态
    /// \param status 状态码
    ///
    void logicStatusSignal(int* status);   
};

#endif // TCPSERVER_H
