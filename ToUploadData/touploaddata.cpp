#include "touploaddata.h"

ToUploadData::ToUploadData(QObject *parent)
{
    this->setParent(parent);
    pManager=nullptr;    
}

ToUploadData::~ToUploadData()
{
}

void ToUploadData::releaseResourcesSlot()
{
    if(nullptr!=pManager){
        pManager->deleteLater();        
    }

    qDebug().noquote()<<QString("ToUploadData::releaseResourcesSlot");
}

QString ToUploadData::InterfaceType()
{
    return QString("FTP");
}

void ToUploadData::InitializationParameterSlot(const QString &user, const QString &pass, const QString &path,const bool &time,const QString &host, const int &port)
{    
    Q_UNUSED(time)

    remotePath=path;

    url.setScheme("ftp");
    url.setHost(host);
    url.setPort(port);
    url.setUserName(user);
    url.setPassword(pass);

    QSslConfiguration config=QSslConfiguration::defaultConfiguration();
//    config.setProtocol(QSsl::AnyProtocol);
//    config.setPeerVerifyMode(QSslSocket::VerifyNone);


//    QList<QSslCertificate> certs = QSslCertificate::fromPath("certificate.crt");
//    config.setCaCertificates(certs);


    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1_1);


    request.setSslConfiguration(config);

    pManager=new QNetworkAccessManager (this);

    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));
}

void ToUploadData::uploadDataSlot(const QString &data)
{   
    if(nullptr==pManager){
        return;
    }

    QMutexLocker locker(&mutex);

    QFile file(data);
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    QStringList dataList=data.split(QDir::toNativeSeparators("/"));
    if(dataList.count()<1){
        return;
    }

    url.setPath(QDir::toNativeSeparators(QString("%1/%2/%3").arg(remotePath).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd")).arg(dataList[dataList.count()-1])));

    //url.setPath(QDir::toNativeSeparators(QString("%1/%2").arg(remotePath).arg(dataList[dataList.count()-1])));

    request.setUrl(url);

    QNetworkReply* reply= pManager->put(request,file.readAll());
    //connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
    //connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
    connect(reply, SIGNAL(uploadProgress(qint64, qint64)),this,SLOT(slot_uploadProgress(qint64, qint64)));

    dataName=data;
}

void ToUploadData::replyFinishedSlot(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data upload error<errorCode=%1>").arg(reply->errorString());
    }
    reply->close();
    reply->abort();
    reply->deleteLater();
}

void ToUploadData::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err.errorString());
    }
}

void ToUploadData::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err);
}

void ToUploadData::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data upload error<errorCode=%1>").arg(reply->errorString());
    }
    reply->abort();
    reply->close();
    reply->deleteLater();
    qInfo().noquote()<<QString("Upload file completed:%1").arg(dataName);
}

void ToUploadData::slot_uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    emit theProgressOfSignal(bytesSent,bytesTotal);
}
