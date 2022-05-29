#include "identifyimages.h"

IdentifyImages::IdentifyImages(QObject *parent)
{
    this->setParent(parent);

    dogStatus=false;

    pPool=new QThreadPool (this);
    pPool->setMaxThreadCount(QThread::idealThreadCount());

    client=new TcpClient(this);
    connect(this,&IdentifyImages::decectTcpImageSignal,client,&TcpClient::decectTcpImageSlot);
    connect(client,&TcpClient::decectSatusSignal,this,&IdentifyImages::decectSatusSlot);
    connect(client,&TcpClient::decectRstSignal,this,&IdentifyImages::decectRstSlot);
    connect(this,&IdentifyImages::releaseResourcesSignal,client,&TcpClient::releaseResourcesSlot);

    sendRstTime=new QTimer(this);
    connect(sendRstTime,&QTimer::timeout,this,&IdentifyImages::processDataSlot);

    timeCout=0;
}

IdentifyImages::~IdentifyImages()
{
    pPool->clear();

    delete  client;
    client=nullptr;
}

QString IdentifyImages::InterfaceType()
{
    return QString("ImageIdentify");
}

void IdentifyImages::recognitionResultSlot(const QString &result, const QString &imgName, const int &imgNumber)
{
    Q_UNUSED(imgName)

    rstMap.insert(imgNumber,result);

    if(rstMap.size()==imgMapL.size()){
        if(rstMapTcp.size()!=rstMap.size() && isDecectConnect){
            //QTimer::singleShot(5000,this,SLOT(processDataSlot()));
            sendRstTime->setSingleShot(false);
            sendRstTime->start(1000);
        }
        else {
            //QTimer::singleShot(100,this,SLOT(processDataSlot()));
            sendRstTime->setSingleShot(true);
            sendRstTime->start(100);
        }
    }
}

void IdentifyImages::decectSatusSlot(bool status)
{
    isDecectConnect=status;
}

void IdentifyImages::decectRstSlot(const QString &rst)
{
    QStringList tmpRst=rst.split(" ");
    for(int i=0;i<tmpRst.size();i++){
        QStringList tmp=tmpRst.at(i).split('-');
        if(tmp.size()==2){
            qWarning().noquote()<<QString("[%1] TCP Identify result<%2 : %3>").arg(this->metaObject()->className(),tmp.at(0),tmp.at(1));
            rstMapTcp.insert(tmp.at(0),tmp.at(1));
        }
    }
    tmpRst.clear();
}

void IdentifyImages::processDataSlot()
{
    timeCout++;

    if(rstMap.size()!=rstMapTcp.size() && timeCout!=10 && isDecectConnect){
        return;
    }
    else {
        sendRstTime->stop();
        timeCout=0;

        if(!isDecectConnect){
            foreach (int key, rstMap.keys()) {
                qDebug()<<QString("[%1] Fusion analysis data imgID<%2>").arg(this->metaObject()->className(),QString::number(key));
                emit recognitionResultSignal(rstMap.value(key),imgMapL.value(key),key);
            }
        }
        else {
            foreach (int key, rstMap.keys()) {
                QStringList tmpMsg=rstMapTcp.value(QDir::fromNativeSeparators(imgMapL.value(key)),"").split(":");
                if(tmpMsg.size()==2 && isDecectConnect){
                    QStringList tmpRst= tmpMsg.at(1).split('|');
                    if(tmpRst.size()==4 && tmpRst.at(0).size()==11){
                        emit recognitionResultSignal(rstMapTcp.value(QDir::fromNativeSeparators(imgMapL.value(key))),imgMapL.value(key),key);
                        continue;
                    }
                    else if (tmpRst.size()==4 && tmpRst.at(1).size()==4) {
                        /*****************************
                        * @brief:替换箱型 202205072132
                        ******************************/
                        QStringList tmpL=rstMap.value(key).split('|');
                        if(tmpL.size()==4){
                            QString tmpR;
                            tmpR.append(tmpL.at(0));
                            tmpR.append("|");
                            tmpR.append(tmpRst.at(1));
                            tmpR.append("|");
                            tmpR.append(tmpL.at(2));
                            tmpR.append("|");
                            tmpR.append(tmpL.at(3));

                            emit recognitionResultSignal(tmpR,imgMapL.value(key),key);
                            continue;
                        }
                    }
                }
                qDebug()<<QString("[%1] Fusion analysis data imgID<%2>").arg(this->metaObject()->className(),QString::number(key));
                emit recognitionResultSignal(rstMap.value(key),imgMapL.value(key),key);
            }
        }
    }
    rstMap.clear();
    rstMapTcp.clear();
    imgMapL.clear();
}

void IdentifyImages::identifyStreamSlot(const QByteArray &jpgStream, const int &imgNumber)
{
    Q_UNUSED(jpgStream);
    Q_UNUSED(imgNumber);
    /* Subsequent processing */
}

void IdentifyImages::identifyImagesSlot(QMap<int,QString> imgMap)
{
    rstMap.clear();
    rstMapTcp.clear();
    imgMapL.clear();
    timeCout=0;

//    if(dogStatus){
//         this->imgMapL=imgMap;
//    }
    this->imgMapL=imgMap;
//    imgMapL.insert(1,QDir::toNativeSeparators("D:/avc_image/202201010915330101.jpg"));
//    imgMapL.insert(2,"D:\\avc_image\\202201010915330102.jpg");
//    imgMapL.insert(3,"D:\\avc_image\\202201010915330103.jpg");
//    imgMapL.insert(4,"D:\\avc_image\\202201010915330104.jpg");
//    imgMapL.insert(5,"D:\\avc_image\\202201010915330105.jpg");
//    imgMapL.insert(6,"D:\\avc_image\\202201010915330106.jpg");
//    imgMapL.insert(8,"D:\\avc_image\\202201010915330108.jpg");
//    imgMapL.insert(9,"D:\\avc_image\\202201010915330109.jpg");

    QString imgS="";

    foreach (auto key, imgMapL.keys()) {
        if(!dogStatus){
            emit recognitionResultSignal("RESULT: ||0|0",imgMap.value(key),key);
        }
        else {
            if(client->isConnected){
                imgS.append(QString(" %1").arg(QDir::toNativeSeparators(imgMap.value(key))));
            }

//            imgS.append(QString(" %1").arg(imgMapL.value(key)));
//            i++;
//            if(i==3)
//            {
             //   emit decectTcpImageSignal( imgMapL.value(key),-1);
            //QThread::msleep(100);
//                imgS.clear();
//                i=0;
//            }
            Recognition* pRecognition=new Recognition(nullptr,imgMap.value(key),key);
            connect(pRecognition,&Recognition::recognitionResultSignal,this,&IdentifyImages::recognitionResultSlot);
            connect(pRecognition,&Recognition::messageSignal,this,&IdentifyImages::messageSignal);
            pPool->start(pRecognition);
        }
    }

    if(!imgS.isEmpty()){
        emit decectTcpImageSignal(imgS,-1);
    }

    imgS.clear();
}

void IdentifyImages::identifyDogStatusSlot(bool status)
{
    dogStatus=status;
}

void IdentifyImages::releaseResourcesSlot()
{
    sendRstTime->stop();
    delete  sendRstTime;
    sendRstTime=nullptr;
    emit releaseResourcesSignal();
}
