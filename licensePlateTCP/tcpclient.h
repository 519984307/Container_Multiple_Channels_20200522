#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include "licensePlateTCP_global.h"

class TcpClient : public QTcpSocket
{
    Q_OBJECT

public:
    explicit TcpClient(QObject *parent=nullptr);

signals:

    ///
    /// \brief signal_ResultPlate 接收车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    /// \param time
    ///
    void signal_ResultPlate(int channel,QString plate,QString color,QString time,QString addr);

public slots:

    ///
    /// \brief receiveClientDataSlot 接收数据
    ///
    void receiveDataSlot();
};


#endif // TCPCLIENT_H
