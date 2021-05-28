#include "identifyimages.h"

IdentifyImages::IdentifyImages(QObject *parent)
{
    this->setParent(parent);

    dogStatus=false;

    pPool=new QThreadPool (this);
    pPool->setMaxThreadCount(QThread::idealThreadCount());
}

IdentifyImages::~IdentifyImages()
{
    pPool->clear();
}

QString IdentifyImages::InterfaceType()
{
    return QString("ImageIdentify");
}

void IdentifyImages::identifyStreamSlot(const QByteArray &jpgStream, const int &imgNumber)
{
    Q_UNUSED(jpgStream);
    Q_UNUSED(imgNumber);
    /* Subsequent processing */
}

void IdentifyImages::identifyImagesSlot(const QString &imgName, const int &imgNumber)
{
    if(!dogStatus){
        emit recognitionResultSignal("RESULT: ||0|0",imgName,imgNumber);
        return;
    }
    Recognition* pRecognition=new Recognition(nullptr,imgName,imgNumber);
    connect(pRecognition,&Recognition::recognitionResultSignal,this,&IdentifyImages::recognitionResultSignal);
    connect(pRecognition,&Recognition::messageSignal,this,&IdentifyImages::messageSignal);
    pPool->start(pRecognition);
}

void IdentifyImages::identifyDogStatusSlot(bool status)
{
    dogStatus=status;
}
