#include "datainterrequest.h"

DataInterRequest::DataInterRequest(QObject *parent)
{
    this->setParent(parent);

    pManager=nullptr;
}

DataInterRequest::~DataInterRequest()
{

}

QString DataInterRequest::InterfaceType()
{
    return QString("HTTP");
}

void DataInterRequest::InitializationParameterSlot(const QString &address, const quint16 &port, const int &serviceType, const bool &heartBeat, const int &serviceMode, const int &shortLink, const int &newline)
{
    pManager=new QNetworkAccessManager (this);

    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));
    request.setUrl(QUrl::fromEncoded("http://61.182.236.74:8062/api/gateway"));
}

void DataInterRequest::toSendDataSlot(int channel_number, const QString &data)
{
    //[C|20020919114100|01|1|TEXU7337250|Y|42G1]
    //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1]
    //[U|%1|%2|%3|%4|%5][标志|时间戳|通道号(2位)|逻辑|车牌|颜色|拖箱状态]
    QString tmp=data;
    QStringList tmpL=tmp.split("|");
    for(int i=0;i<tmpL.length();i++){

    }

    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("applocation/json"));
//    QNetworkReply* reply=pManager->post(request,data);

//    connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
//    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
//    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
}

void DataInterRequest::releaseResourcesSlot()
{
    if(nullptr!=pManager){
        pManager->deleteLater();
    }
}

void DataInterRequest::replyFinishedSlot(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
    }
    reply->close();
    reply->abort();
    reply->deleteLater();
}

void DataInterRequest::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err.errorString());
    }
}

void DataInterRequest::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err);

}

void DataInterRequest::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();

    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
    }

    QByteArray arr=reply->readAll();
    QString str=QString::fromUtf8(arr);
    qDebug()<<str;

    reply->abort();
    reply->close();
    reply->deleteLater();
}
