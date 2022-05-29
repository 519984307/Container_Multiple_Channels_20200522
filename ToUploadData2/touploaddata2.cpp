#include "touploaddata2.h"

ToUploadData2::ToUploadData2(QObject *parent)
{
    this->setParent(parent);
    pFtp=nullptr;
    linkT=nullptr;
}

ToUploadData2::~ToUploadData2()
{
}

void ToUploadData2::releaseResourcesSlot()
{
    if(linkT!=nullptr){
        linkT->stop();

        delete linkT;
        linkT=nullptr;
    }

    if(nullptr!=pFtp){
        pFtp->close();
        pFtp->abort();
        delete  pFtp;
        pFtp=nullptr;
    }

    qDebug().noquote()<<QString("[%1] releaseResourcesSlot").arg(this->metaObject()->className());
}

void ToUploadData2::slot_commandFinished(int id, bool error)
{
    if(nullptr==pFtp){
        return;
    }

    QFtp::Command command = pFtp->currentCommand();
    switch (command) {
    case QFtp::ConnectToHost: {  // 连接 FTP 服务器
        if (error) { // 发生错误
            qDebug().noquote()<<QString("[%1] ConnectToHost failde<errCode=%2>").arg(this->metaObject()->className(),pFtp->errorString());
            pFtp->abort();
        } else {
            qDebug().noquote()<<QString("[%1] ConnectToHost sucess").arg(this->metaObject()->className());
        }
        break;
    }
    case QFtp::Login: {  // 连接 FTP 服务器
        if (error) { // 发生错误
            qDebug().noquote()<<QString("[%1] Login failde<errCode=%2>").arg(this->metaObject()->className(),pFtp->errorString());
            pFtp->abort();
        } else {
            qDebug().noquote()<<QString("[%1] Login sucess").arg(this->metaObject()->className());
        }
        break;
    }
    case QFtp::Put: {  // 连接 FTP 服务器
        if (error) { // 发生错误
            qDebug().noquote()<<QString("[%1] upload data failde<errCode=%2>").arg(this->metaObject()->className(),pFtp->errorString());
            pFtp->abort();
        } else {
            qDebug().noquote()<<QString("[%1] upload data sucess").arg(this->metaObject()->className());
        }
        break;
    }
    default:
        if(error){
            qCritical().noquote()<<QString("[%1] upload cmd=%2 error<errorCode=%3>").arg(pFtp->errorString(),QString::number(id),this->metaObject()->className());
        }
        else {
            qDebug().noquote()<<QString("[%1] upload cmd=%2 sucess").arg(this->metaObject()->className(),QString::number(id));
        }
        break;
    }
}

void ToUploadData2::slot_commandStarted(int id)
{
    Q_UNUSED(id)
    if(nullptr==pFtp){
        return;
    }

    QFtp::Command cmd=pFtp->currentCommand();
    switch (cmd) {
    case QFtp::Put:
        qDebug().noquote()<<QString("[%1] start upload data").arg(this->metaObject()->className());
        break;
    case QFtp::ConnectToHost:
        qDebug().noquote()<<QString("[%1] start ConnectToHost").arg(this->metaObject()->className());
        break;
    case QFtp::Login:
        qDebug().noquote()<<QString("[%1] start Login").arg(this->metaObject()->className());
        break;
    default:
        qDebug().noquote()<<QString("[%1] upload cmd=%2 start").arg(this->metaObject()->className());
    }
}

void ToUploadData2::slot_done(bool error)
{
    if(nullptr==pFtp){
        return;
    }

    if(error){
        qCritical().noquote()<<QString("[%2] Data upload error<errorCode=%1>").arg(pFtp->errorString(),this->metaObject()->className());
    }
    else {
        qDebug().noquote()<<QString("[%1] Data upload sucess").arg(this->metaObject()->className());
    }
}

QString ToUploadData2::InterfaceType()
{
    return QString("FTP_2");
}

void ToUploadData2::InitializationParameterSlot(const QString &user, const QString &pass, const QString &path,const bool &time, const QString &host, const int &port)
{
    linkT=new QTimer(this);
    linkT->setSingleShot(true);
    connect(linkT,&QTimer::timeout,this,&ToUploadData2::slot_linkTime);

    pFtp=new QFtp();
    connect(pFtp,SIGNAL(stateChanged(int )),this,SLOT(slot_stateChanged(int )));
    connect(pFtp,SIGNAL(commandFinished(int, bool  )),this,SLOT(slot_commandFinished(int, bool )));
    connect(pFtp,SIGNAL(commandStarted( int)),this,SLOT(slot_commandStarted( int)));
    connect(pFtp,SIGNAL(done(bool)),this,SLOT(slot_done(bool)));
    connect(pFtp,SIGNAL(dataTransferProgress(qint64, qint64)) ,this,SLOT(slot_uploadProgress(qint64, qint64)));

    remotePath=path;
    this->user=user;
    this->pass=pass;
    this->host=host;
    this->port=port;
    this->time=time;

    pFtp->connectToHost(host,port);
    pFtp->login(user,pass);
}

void ToUploadData2::uploadDataSlot(const QString &data)
{
    QMutexLocker locker(&mutex);

    if(nullptr==pFtp){
        return;
    }

    QFile file(data);
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    QStringList dataList=data.split(QDir::toNativeSeparators("/"));
    if(dataList.count()<1){
        return;
    }

    QByteArray tmpR=file.readAll();

    if(time){
        /*****************************
        * @brief:使用日期文件夹
        ******************************/
        pFtp->mkdir(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
        pFtp->put(tmpR,(QDir::toNativeSeparators(QString("%1/%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"),dataList[dataList.count()-1]))));
    }
    else {
        if(!remotePath.isEmpty()){
            /*****************************
            * @brief:创建文件夹
            ******************************/
            pFtp->mkdir(remotePath);
            pFtp->put(tmpR,(QDir::toNativeSeparators(QString("%1/%2").arg(remotePath,dataList[dataList.count()-1]))));
        }
        else {
            pFtp->put(tmpR,(QDir::toNativeSeparators(QString("%1").arg(dataList[dataList.count()-1]))));
        }
    }

    file.close();
    tmpR.clear();
}

void ToUploadData2::slot_uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    emit theProgressOfSignal(bytesSent,bytesTotal);
}

void ToUploadData2::slot_stateChanged(int state)
{
    if(linkT==nullptr){
        return;
    }

    QString msg;
    switch (state) {
    case 0:
        msg="There is no connection to the host";
        linkT->start(10000);
//        if(!linkT->isActive()){
//            pFtp->close();
//            pFtp->abort();
//            linkT->start(10000);
//        }
        break;
    case 1:
        msg="A host name lookup is in progress.";
        break;
    case 2:
        msg="An attempt to connect to the host is in progress.";
        break;
    case 3:
        msg="Connection to the host has been achieved.";
        //pFtp->login(user,pass);
        //linkT->stop();
        break;
    case 4:
        msg="Connection and user login have been achieved.";
        //linkT->stop();
        break;
    case 5:
        msg="The connection is closing down, but it is not yet closed. (The state will be Unconnected when the connection is closed.";
//        pFtp->close();
//        pFtp->abort();
//        if(!linkT->isActive()){
//            pFtp->close();
//            pFtp->abort();
//            linkT->start(10000);
//        }
        break;
    }
    qDebug().noquote()<<QString("[%1] %2").arg(this->metaObject()->className(),msg);
}

void ToUploadData2::slot_linkTime()
{
    pFtp->close();
    pFtp->abort();

    delete  pFtp;
    pFtp=nullptr;

    pFtp=new QFtp();
    connect(pFtp,SIGNAL(stateChanged(int )),this,SLOT(slot_stateChanged(int )));
    connect(pFtp,SIGNAL(commandFinished(int, bool  )),this,SLOT(slot_commandFinished(int, bool )));
    connect(pFtp,SIGNAL(commandStarted( int)),this,SLOT(slot_commandStarted( int)));
    connect(pFtp,SIGNAL(done(bool)),this,SLOT(slot_done(bool)));
    connect(pFtp,SIGNAL(dataTransferProgress(qint64, qint64)) ,this,SLOT(slot_uploadProgress(qint64, qint64)));

    pFtp->connectToHost(host,port);
    pFtp->login(user,pass);
}
