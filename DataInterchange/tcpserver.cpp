#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer (parent)
{    
    this->setParent(parent);
    pTimerSendHeartPack=nullptr;
}

void TcpServer::InitializationParameter()
{
    isHeartPack=false;
    pTimerSendHeartPack=new QTimer (this);
    connect(pTimerSendHeartPack,&QTimer::timeout,this,&TcpServer::heartbeatSlot);

    if(!pTimerSendHeartPack->isActive()){
        pTimerSendHeartPack->start(15000);
    }
}

void TcpServer::setServiceType(int serviceType)
{
    this->serviceType=serviceType;
}

void TcpServer::incomingConnection(qintptr socketID)
{
    QSharedPointer<TcpClient> pClient(new TcpClient (this));
    pClient->setSocketDescriptor(socketID);
    clientSocketIdMap.insert(socketID,pClient);

    emit connectCountSignal(1);
    emit messageSignal(ZBY_LOG("INFO"),tr("New client in join<IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()));
    qInfo().noquote()<<QString("New client in join<IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    connect(pClient.data(),&TcpClient::disconnected,this,&TcpServer::disconnectedSlot);
    connect(pClient.data(),&TcpClient::setClientChannelNumberSignal,this,&TcpServer::setClientChannelNumberSlot);
    connect(pClient.data(),&TcpClient::getLastResultSignal,this,&TcpServer::getLastResultSlot);
}

void TcpServer::disconnectedSlot()
{
    QSharedPointer<TcpClient> pClient(qobject_cast<TcpClient*>(sender()));

    emit connectCountSignal(-1);
    emit messageSignal(ZBY_LOG("INFO"),tr("Client offline <IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()));
    qInfo().noquote()<<QString("Client offline <IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    qintptr socketID= clientSocketIdMap.key(pClient);
    clientSocketIdMap.remove(socketID);
    clientChannelMap.remove(clientChannelMap.key(socketID));
}

void TcpServer::setClientChannelNumberSlot(int channel_number, qintptr socketID)
{
    clientChannelMap.insert(channel_number,socketID);
}

void TcpServer::getLastResultSlot(qintptr socktID)
{
    QPointer<TcpClient> pClient(clientSocketIdMap.value(socktID).data());
    if(pClient!=nullptr && pClient->isOpen()){
        pClient ->write(resultOfMemory.toLocal8Bit());
        messageSignal(ZBY_LOG("INFO"),tr("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(resultOfMemory));
        qInfo().noquote()<<QString("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(resultOfMemory);
    }
}

void TcpServer::toSendDataSlot(int channel_number, const QString &result)
{
    resultOfMemory=result;

    if(serviceType==1){/* 多模发送到所有链接的客户端 */
        foreach (auto tcp, clientSocketIdMap.values()) {
            tcp->write(result.toLocal8Bit());
        }
    }
    else if (serviceType==0) {/* 单模只发送对应通道客户端 */
        foreach (auto tcp, clientChannelMap.values(channel_number)) {
            QPointer<TcpClient> pClient=clientSocketIdMap.value(tcp,nullptr).data();
            if(pClient!=nullptr){
                pClient->write(result.toLocal8Bit());
                messageSignal(ZBY_LOG("INFO"),tr("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(result));
                qInfo().noquote()<<QString("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(result);
            }
        }
    }
}

void TcpServer::heartbeatSlot()
{
    if(isHeartPack){
        foreach (auto client, clientSocketIdMap.values()) {
            client->write("[H]");
            messageSignal(ZBY_LOG("INFO"),tr("Send HeartPackets"));
            qInfo().noquote()<<QString("Send HeartPackets");
        }
    }
}

void TcpServer::setHeartPacketStateSlot(bool state)
{
    isHeartPack=state;
}

void TcpServer::releaseResourcesSlot()
{
    this->close();

    if(pTimerSendHeartPack!=nullptr){
        pTimerSendHeartPack->stop();
    }

    foreach (auto tcp, clientSocketIdMap.values()) {
        tcp->disconnected();
    }

    clientChannelMap.clear();
    clientSocketIdMap.clear();
}
