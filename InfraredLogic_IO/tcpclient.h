#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "InfraredLogic_IO_global.h"

class TcpClient : public QTcpSocket
{
    Q_OBJECT

public:
    explicit TcpClient(QObject *parent=nullptr);

private:

    ///
    /// \brief tmpStatus 临时红外信号
    ///
    int tmpStatus[8];

    ///
    /// \brief eol 信息结束符
    ///
    QString eol;

signals:

    ///
    /// \brief logicStatus 红外信号状态
    /// \param status 状态码
    ///
    void logicStatusSignal(int* status);

public slots:

    ///
    /// \brief receiveClientDataSlot 接收数据
    ///
    void receiveDataSlot();
};

#endif // TCPCLIENT_H
