#include "datainterrabbitmq.h"
#include <QDebug>

DataInterRabbitMQ::DataInterRabbitMQ(QObject *parent)
{
    this->setParent(parent);
}

DataInterRabbitMQ::~DataInterRabbitMQ()
{
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
    this->address="127.0.0.1";
    QString user="zby";
    QString pass="ABCabc123";
    QString vhost="/zby";
    quint16 lport=5672;

    if(port!=0){
        lport=port;
    }
    if(addrList.size()==4){
        this->address=addrList[0];
        user=addrList[1];
        pass=addrList[2];
        vhost=addrList[3];
    }
    else {
        qCritical().noquote()<<QString("Error setting MQ parameters, load default parameters.");
    }

    m_client.setHost(this->address);
    m_client.setPort(lport);
    m_client.setUsername(user);
    m_client.setPassword(pass);
    m_client.setVirtualHost(vhost);
    m_client.setAutoReconnect(false);

    qDebug()<<this->address;
    qDebug()<<vhost;
    qDebug()<<lport;

    connect(&m_client, SIGNAL(connected()), this, SLOT(clientConnected()));
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    /* 发送识别结果 */
    connect(this,&DataInterRabbitMQ::toSendDataSignal,this,&DataInterRabbitMQ::toSendDataSlot);
}

void DataInterRabbitMQ::toSendDataSlot(int channel_number, const QString &data)
{
    Q_UNUSED(channel_number);
    m_client.connectToHost();
    sendData=data;
}

void DataInterRabbitMQ::releaseResourcesSlot()
{
    m_client.disconnected();
    m_client.abort();
}

void DataInterRabbitMQ::disconnected()
{
    emit linkStateSingal(address,false);
//    QAmqpQueue *queue = qobject_cast<QAmqpQueue*>(sender());
//    delete queue;
//    queue=nullptr;
}

void DataInterRabbitMQ::clientConnected()
{
    emit linkStateSingal(address,true);

    QAmqpQueue* queue = m_client.createQueue("zby");
    connect(queue, SIGNAL(declared()), this, SLOT(queueDeclared()));
    queue->declare();
}

void DataInterRabbitMQ::queueDeclared()
{
    QAmqpQueue *queue = qobject_cast<QAmqpQueue*>(sender());
    if (!queue)
        return;
    QAmqpExchange *defaultExchange = m_client.createExchange();
    defaultExchange->publish(sendData, "zby");
    qDebug() << " [x] Sent 'Hello World!'";
    m_client.disconnectFromHost();

    //queue->deleteLater();
    //defaultExchange->deleteLater();
}
