#ifndef PUTCOMMAND_H
#define PUTCOMMAND_H

#include <QObject>
#include <QTcpSocket>

class PutCommand : public QObject
{
    Q_OBJECT
public:
    explicit PutCommand(QObject *parent = nullptr);
    ~PutCommand()Q_DECL_OVERRIDE;

private:

    ///
    /// \brief tcpSocket Socket
    ///
    QTcpSocket *tcpSocket;

    ///
    /// \brief capNo 抓拍编号
    ///
    int capNo;

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief linktoServerSlot
    /// \param addr
    /// \param port
    ///
    void linktoServerSlot(QString addr, quint16 port);

    ///
    /// \brief putCommandSlot
    ///
    bool putCommandSlot();

};

#endif // PUTCOMMAND_H
