#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
    this->setParent(parent);
}

void TcpClient::receiveDataSlot()
{
    QByteArray buf=readAll();

    if(buf.trimmed().startsWith('[')){
        QList<QByteArray> tmp=buf.split('|');
        if(tmp.count()==5){
            if(tmp.at(0).indexOf('U')!=-1){/* 找到车牌结果标标志位 */
                //channel_number=tmp[1].split(']')[0].toInt();
                //emit setClientChannelNumberSignal(channel_number,this->socketDescriptor());
                QString plate=QString::fromLocal8Bit(tmp.at(3));
                QString color=QString::fromLocal8Bit(tmp.at(4).split(']').at(0));
                QString time=QDateTime::fromString(tmp.at(1),"yyyyMMddhhmmss").toString("yyyy-M-d h:m:s");
                emit signal_ResultPlate(tmp.at(2).toInt(),plate,color,time,this->peerAddress().toString());
            }
        }
    }
    buf.clear();
}

