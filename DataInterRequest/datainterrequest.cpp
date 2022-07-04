#include "datainterrequest.h"

DataInterRequest::DataInterRequest(QObject *parent)
{
    this->setParent(parent);

    pManager=nullptr;

    /*****************************
    * @brief:上传图片
    ******************************/
    connect(this,&DataInterRequest::signal_upLoadImg,this,&DataInterRequest::slot_upLoadImg);
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
    Q_UNUSED(port)
    Q_UNUSED(serviceType)
    Q_UNUSED(heartBeat)
    Q_UNUSED(serviceMode)
    Q_UNUSED(shortLink)
    Q_UNUSED(newline)

    if(address.indexOf("https")){
        QSslConfiguration config=QSslConfiguration::defaultConfiguration();
        config.setPeerVerifyMode(QSslSocket::VerifyNone);
        config.setProtocol(QSsl::TlsV1_1);
        request.setSslConfiguration(config);
    }

    pManager=new QNetworkAccessManager (this);

    connect(this,&DataInterRequest::toSendDataSignal,this,&DataInterRequest::toSendDataSlot);
    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));
    QString path=address;
    request.setUrl(QUrl::fromEncoded(path.toUtf8()));

    pTcpClient=new TcpClient (this,"192.168.1.103",65000);
    ///
    /// \brief connect 发送数据内部调用
    ///
    connect(this,&DataInterRequest::signalSendData,pTcpClient,&TcpClient::toSendDataSlot);

    /*****************************
    * @brief:传送图片
    ******************************/
    requestImg.setUrl(QUrl::fromEncoded(path.toUtf8()));
    pManagerImg=new QNetworkAccessManager(this);
    connect(pManagerImg, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestImgFinished(QNetworkReply*)));
}

void DataInterRequest::toSendDataSlot(int channel_number, const QString &data)
{
    this->channel_number=channel_number;

    //[标志|时间戳|通道号(2位)|逻辑|车牌|颜色|拖箱状态]
    //[U|20020919114100|01|粤B050CS|黄]
    //[C|20220606004231|01|0|WDFU1234567|N|22G1|粤B050CS]
    //[C|20220606004231|01|0|WDFU1234567|N|22G1|粤B050CS|黄]
    //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1|粤B050CS]
    //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1|粤B050CS|黄]
    //[C|20220608112014|01|0||N|22G1|_无_|未知]
    //[C|20220608112111|01|2||N||N|22G1|22G1|_无_|未知]

    if(!data.endsWith("黄]")){
        qCritical().noquote()<<QString("[%1] License plate data does not meet requirements, request data is not executed<%2>").arg(this->metaObject()->className(),data);
        return;
    }

    QJsonDocument jsonDoc;
    QJsonObject jsonObj,jsonObjChild;

    jsonObj.insert("action", "InOutAction");
    jsonObj.insert("method", "Verification");
    jsonObj.insert("service", "container");

    tmpData=data;
    QStringList tmpL=tmpData.split("|");
    if(tmpL.length()<5){
        return;
    }

    jsonObjChild.insert("currentDate", QDateTime::fromString(tmpL.at(1), "yyyyMMddhhmmss").toString("yyyy-MM-dd hh:mm:ss"));
    jsonObjChild.insert("doorNumber","2");
    jsonObjChild.insert("laneNumber",tmpL.at(2));
    jsonObjChild.insert("goodsType",tmpL.at(3).toInt());
    jsonObjChild.insert("goodsList","");
    if(tmpData.indexOf("[U")!=-1){
        jsonObjChild.insert("carNumber",tmpL.at(3).toUtf8().data());
        jsonObjChild.insert("goodsType",-1);
    }
    else if (tmpData.indexOf("[C")!=-1 && tmpL.length()>=8 && tmpL.at(3).toInt()<2) {
        jsonObjChild.insert("goodsList",tmpL.at(4));
        jsonObjChild.insert("carNumber",tmpL.at(7).toUtf8().data());
    }
    else if (tmpData.indexOf("[C")!=-1 && tmpL.length()>=11 && tmpL.at(3).toInt()==2) {
        jsonObjChild.insert("goodsList",QString("%1,%2").arg(tmpL.at(4),tmpL.at(6)));
        jsonObjChild.insert("carNumber",tmpL.at(10).toUtf8().data());
    }

    jsonObj.insert("dto",QJsonValue(jsonObjChild));
    jsonDoc.setObject(jsonObj);

    qInfo().noquote()<<QString("[%1] HTTP request data<%2>").arg(this->metaObject()->className(),QString(jsonDoc.toJson()));

    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("applocation/json"));
    QNetworkReply* reply=pManager->post(request,jsonDoc.toJson(QJsonDocument::Compact));
    connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
}

void DataInterRequest::releaseResourcesSlot()
{
    if(nullptr!=pManager){
        pManager->deleteLater();
    }

    if(nullptr!=pManagerImg){
        pManagerImg->deleteLater();
    }
}

void DataInterRequest::setImagePathSlot(const QString &imgPath,int ImageFormat,int ImageNamingRules,int channel_id_placeholder,int camera_id_placeholder)
{
    this->imgPath=imgPath;
    this->ImageFormat=ImageFormat;
    this->ImageNamingRules=ImageNamingRules;
    this->channel_id_placeholder=channel_id_placeholder;
    this->camera_id_placeholder=camera_id_placeholder;
}

void DataInterRequest::replyFinishedSlot(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("[%1] Data transfer failure<errorCode=%2>").arg(this->metaObject()->className(),reply->errorString());
        emit signalSendData(channel_number,QString("%1@%2@@-1").arg(QString::number(channel_number),tmpData));
    }
    reply->close();
    reply->abort();
    reply->deleteLater();
}

void DataInterRequest::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("[%1] An error found during processing the request:%2").arg(this->metaObject()->className(),err.errorString());
    }
    emit signalSendData(channel_number,QString("%1@%2@@-1").arg(QString::number(channel_number),tmpData));
}

void DataInterRequest::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("[%1] An error found during processing the request:%2").arg(this->metaObject()->className(),err);
    emit signalSendData(channel_number,QString("%1@%2@@-1").arg(QString::number(channel_number),tmpData));
}

void DataInterRequest::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();

    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("[%1] Data transfer failure<errorCode=%2>").arg(this->metaObject()->className(),reply->errorString());
        emit signalSendData(channel_number,QString("%1@%2@@-1").arg(QString::number(channel_number),tmpData));
    }

    QByteArray arr=reply->readAll();

    //qDebug()<<QString::fromUtf8(arr);
    //QString str=QString::fromUtf8(arr);
    QJsonDocument doc =QJsonDocument::fromJson(arr);

    int code=-1;
    QString msg="";
    if(!doc.isNull()){
        QJsonObject obj=doc.object();
        if(obj.contains("message")){
            QJsonValue val=obj.value("message");
            msg=val.toString();
            qInfo().noquote()<<QString("[%1] The request data:%2").arg(this->metaObject()->className(),val.toString());
        }
        if(obj.contains("code")){
            QJsonValue val=obj.value("code");
            code=val.toInt();
            if(code==0){

                /*****************************
                * @brief:收到抬杆指令，发送抬杆信号
                ******************************/
                emit signal_lifting();
            }
        }
        /*****************************
        * @brief:解析返回的数据，使用返回的ID上传图片
        ******************************/
        if(obj.contains("data")){
            QJsonObject dataObj=obj.value("data").toObject();

            QMap<QString,QString> msgMap;

            if(dataObj.contains("id")){
                msgMap.insert("id",dataObj.value("id").toString());
            }
            if(dataObj.contains("currentDate")){
                msgMap.insert("currentDate",dataObj.value("currentDate").toString());
            }
            if(dataObj.contains("laneNumber")){
                //qDebug()<<dataObj.value("laneNumber").toString();
                msgMap.insert("laneNumber",dataObj.value("laneNumber").toString());
            }
            emit signal_upLoadImg(msgMap);
        }
        emit signalSendData(channel_number,QString("%1@%2@%3@%4").arg(QString::number(channel_number),tmpData,msg,QString::number(code)));
        emit signal_sendDataSuccToLog(channel_number,  QString("%1@%2@%3@%4").arg(QString::number(channel_number),tmpData,msg,QString::number(code)));
    }

    reply->abort();
    reply->close();
    reply->deleteLater();
}

void DataInterRequest::slot_upLoadImg(QMap<QString, QString> msgMap)
{
    QString suffixPath;

    switch (ImageFormat) {
    case 0:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channel_number).arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 1:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channel_number).arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 2:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channel_number).arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 3:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(channel_number));
        break;
    case 4:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 5:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 6:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 7:
        suffixPath=QDir::toNativeSeparators(QString("./"));
        break;
    }

    QDir dir(imgPath);
    dir.mkpath(suffixPath);
    dir.cd(suffixPath);

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QMap<QString, QString>::iterator it1;
    QMap<QString, QString>::iterator it2;

    QMap<QString, QString> param1;
    param1.insert("action","FileMsgAction");
    param1.insert("method","uploadInOutImage");
    param1.insert("app","app");
    param1.insert("service","container");
    param1.insert("id",msgMap.value("id"));

    /*****************************
    * @brief:只传送3张图片
    ******************************/
    QVector<int> numBer;
    numBer.append(1);
    numBer.append(6);
    numBer.append(7);

    QMap<QString, QString> param3;

    QString datetime=QDateTime::fromString(msgMap.value("currentDate"),"yyyy-MM-dd hh:mm:ss").toString("yyyyMMddhhmmss");

    foreach (auto key, numBer) {
        QString imgName="";
        switch (ImageNamingRules) {
        case 0:
            imgName=QString("%1%2%3.jpg").arg(datetime).arg(channel_number,channel_id_placeholder,10,QLatin1Char('0')).arg(key,camera_id_placeholder,10,QLatin1Char('0'));
            break;
        case 1:
            imgName=QString("%1%2%3.jpg").arg(datetime).arg(key,camera_id_placeholder,10,QLatin1Char('0')).arg(channel_number,channel_id_placeholder,10,QLatin1Char('0'));
            break;
        }

        param3.insertMulti("file",imgName);

        //QString imgPath=QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgName));
    }

    //QVector<QFile*> qFiles;

    foreach(QString val,param3.values("file")){        
        /* 有多个文件时不能直接使用QFile file（path），for代码块结束的时候就会被析构，导致数据无法发送，程序crash */
        /* 单个文件可以不用for遍历，直接QFile file（path）本接口结束时才会析构 */
        QFile* file = new QFile(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(val)));
        if(file && file->open(QFile::ReadOnly)){
            qDebug().noquote()<<QString("Upload images to the server:%1").arg(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(val)));
            qFiles.push_back(file);

            QHttpPart filePart;
            filePart.setBodyDevice(file);
            filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));/* 这里我们上传的是图片 */
            filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"" + param3.key(val) + "\"; filename=\""+val+"\""));
            multiPart->append(filePart);

            //file->close();
        }
    }

    for(it1 = param1.begin(); it1 != param1.end(); ++it1){
        QHttpPart dataPart;
        dataPart.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
        dataPart.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"" + it1.key() + "\""));
        dataPart.setBody(it1.value().toUtf8());
        multiPart->append(dataPart);
    }

    pManagerImg->post(requestImg,multiPart);
}

void DataInterRequest::requestImgFinished(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("[%1] Data transfer failure<errorCode=%2>").arg(this->metaObject()->className(),reply->errorString());
    }

    QByteArray arr=reply->readAll();
    QJsonDocument doc =QJsonDocument::fromJson(arr);

    if(!doc.isNull()){
        QJsonObject obj=doc.object();
        if(obj.contains("message")){
            QJsonValue val=obj.value("message");
            qInfo().noquote()<<QString("[%1] The request data:%2").arg(this->metaObject()->className(),val.toString());
        }
//        if(obj.contains("code")){
//            QJsonValue val=obj.value("code");
//            if(val.toInt()==0){

//            }
//        }
    }

    reply->abort();
    reply->close();
    reply->deleteLater();

    qDeleteAll(qFiles.begin(),qFiles.end());
    qFiles.clear();
}
