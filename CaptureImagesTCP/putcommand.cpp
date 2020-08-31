#include "putcommand.h"

PutCommand::PutCommand(QObject *parent) : QObject(parent)
{
    tcpSocket=new  QTcpSocket (this);
    capNo=1;
}

PutCommand::~PutCommand()
{
    if(tcpSocket!=nullptr){
        tcpSocket->abort();
    }
    delete  tcpSocket;
    tcpSocket=nullptr;
}

void PutCommand::linktoServerSlot(QString addr, quint16 port)
{
    if(!tcpSocket->isValid()){
            tcpSocket->connectToHost(addr,port);
    }
}

bool PutCommand::putCommandSlot()
{
    if(capNo>100){
        capNo=1;
    }
    else {
        ++capNo;
    }

    QByteArray capTm=QString("capture %1\n").arg(capNo,2,10,QLatin1Char('0')).toLatin1();

    qInfo()<<capTm;

    if(tcpSocket->isValid()){
        const char * str_data=capTm.data();
        if(tcpSocket->write(str_data)!=-1){
            return tcpSocket->flush();
        }
    }
    return false;
}
