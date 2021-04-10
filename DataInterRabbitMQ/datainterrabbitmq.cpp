#include "datainterrabbitmq.h"
#include <QDebug>

DataInterRabbitMQ::DataInterRabbitMQ(QObject *parent)
{
    this->setParent(parent);
}

DataInterRabbitMQ::~DataInterRabbitMQ()
{
    m_client.abort();
    qDebug().noquote()<<QString("~DataInterRabbitMQ");
}

QString DataInterRabbitMQ::InterfaceType()
{
    return QString("MQ");
}

void DataInterRabbitMQ::InitializationParameterSlot(const QString &address, const quint16 &port, const int &serviceType, const bool &heartBeat, const int &serviceMode, const int &shortLink, const int &newline)
{
    Q_UNUSED(serviceType);
    Q_UNUSED(heartBeat);
    Q_UNUSED(serviceMode);
    Q_UNUSED(shortLink);
    Q_UNUSED(newline);

    QStringList addrList=address.split("|");
    QString user="zby";
    QString pass="ABCabc123";
    QString vhost="/zby";
    quint16 lport=5672;
    addr="127.0.0.1";

    if(port!=0){
        lport=port;
    }

    if(addrList.size()==4){
        addr=addrList[0];
        user=addrList[1];
        pass=addrList[2];
        vhost=addrList[3];
    }
    else {
        qCritical().noquote()<<QString("Error setting MQ parameters, load default parameters.");
    }

    m_client.setHost(addr);
    m_client.setPort(lport);
    m_client.setUsername(user);
    m_client.setPassword(pass);
    m_client.setVirtualHost(vhost);
    m_client.setAutoReconnect(true);

    connect(&m_client, SIGNAL(connected()), this, SLOT(clientConnected()));
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    /* 发送识别结果 */
    connect(this,&DataInterRabbitMQ::toSendDataSignal,this,&DataInterRabbitMQ::toSendDataSlot);

    //defaultExchange->enableConfirms();
    properties[QAmqpMessage::DeliveryMode] = "2";

}

void DataInterRabbitMQ::toSendDataSlot(int channel_number, const QString &data)
{
    this->channel_number=channel_number;

    sendData=data;
    //m_client.abort();
    m_client.connectToHost();
}

void DataInterRabbitMQ::releaseResourcesSlot()
{   
    m_client.abort();
}

void DataInterRabbitMQ::clientDisconnected()
{
    emit linkStateSingal(addr,false);
    //m_client.abort();
}

void DataInterRabbitMQ::clientConnected()
{
    emit linkStateSingal(addr,true);

    QAmqpQueue *queue = m_client.createQueue("zby_"+QString::number(channel_number));
    connect(queue, SIGNAL(declared()), this, SLOT(queueDeclared()));
    queue->declare(QAmqpExchange::Durable);
}

void DataInterRabbitMQ::queueDeclared()
{
    QAmqpQueue *queue = qobject_cast<QAmqpQueue*>(sender());
    if (!queue)
        return;

    QAmqpExchange *defaultExchange = m_client.createExchange();
    defaultExchange->publish(sendData,"zby_"+QString::number(channel_number),properties);
//    defaultExchange->enableConfirms(true);
//    if(defaultExchange->waitForConfirms()){
//        qDebug() << " [x] "<<sendData;
//    }
//    else {
//        qDebug()<<"send message failed";
//        //defaultExchange->publish(sendData, "zby",properties);
//    }

    qDebug().noquote()<< QString("[X] send:")<<sendData;
    m_client.disconnectFromHost();
    defaultExchange->deleteLater();
    queue->deleteLater();
}
