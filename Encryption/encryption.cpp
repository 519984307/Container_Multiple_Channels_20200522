#include "encryption.h"

#include <QCryptographicHash>
#include <QProcess>

Encryption::Encryption(QObject *parent)
{
    this->setParent(parent);

    pDLL=nullptr;
    SmartX3Find=nullptr;
    SmartX3GetUid=nullptr;
    SmartX3CheckExist=nullptr;

    dogState=false;
    dogType=1;

    key1=QByteArray("cheng870888").toHex()+"0451031075c8f4a1a81913cad8c8593f";
    ind=5;

    pTimer=new QTimer(this);
    connect(pTimer,SIGNAL(timeout()),this,SLOT(SmartXCheckExistSlot()));
    //connect(pTimer,SIGNAL(timeout()),this,SLOT(checkTheKeyFunc()));
}

Encryption::~Encryption()
{
}

void Encryption::InitializationSlot(int dogType,QString dogIdd)
{   
    Q_UNUSED(dogIdd);

    this->dogType=dogType;

    pDLL=new QLibrary ("libsmart-x3",this);

    if(pDLL->load()){
        SmartX3Find=reinterpret_cast<SmartX3FindFUN>(pDLL->resolve("SmartX3Find"));
        SmartX3GetUid=reinterpret_cast<SmartX3GetUidFUN>(pDLL->resolve("SmartX3GetUid"));
        SmartX3CheckExist=reinterpret_cast<SmartX3CheckExistFUN>(pDLL->resolve("SmartX3CheckExist"));

        qCritical().noquote()<<QString("load the Smart plug-in library sucess");

        /*****************************
        * @brief: 加密狗
        ******************************/
        smartXGetUidFunc();
        pTimer->start(10000);

        /*****************************
        * @brief: KEY
        ******************************/
        //pTimer->start(10000);
    }
    else {
        qCritical().noquote()<<QString("Failed to load the Smart plug-in library!!!");
    }
}

void Encryption::releaseResourcesSlot()
{
    pTimer->stop();

    delete  pTimer;
    pTimer=nullptr;
}

void Encryption::smartXGetUidFunc()
{
    if(SmartX3Find!=nullptr && SmartX3Find(appID,keyHandles,&keyNumber)==0){
        if(SmartX3GetUid!=nullptr && SmartX3GetUid(keyHandles[0],UID)==0){
            //qDebug()<<"UID:"<<UID;
            if(strncmp(UID,"430c4bdbd03296d3f0b2080eceadbe83",33)==0){
                dogState=true;
            }
            else {
                dogState=false;
            }

            /*****************************
            * @brief:单通道不需要加密狗号
            ******************************/
            if(1==dogType){
                dogState=true;
            }

            emit GetTheEncryptedStateSignal(dogState);
        }
    }
}

void Encryption::SmartXCheckExistSlot()
{
    /*****************************
    * @brief:test
    ******************************/
    if(1==dogType){
        emit GetTheEncryptedStateSignal(true);
    }
    else {
        if(dogState && SmartX3CheckExist!=nullptr && SmartX3CheckExist(keyHandles[0])==0){
            emit GetTheEncryptedStateSignal(true);
        }
        else {
            emit GetTheEncryptedStateSignal(false);
        }
    }
}

void Encryption::checkTheKeyFunc()
{
    /*****************************
    * @brief: 15c70d2b4d36be659ce989f394170677
    *         0edc4d55539cd86b7e85b54b076d16b5
    ******************************/
    QByteArray key;
    key.append(getKey(runPro("wmic",QStringList()<<"CPU"<<"get"<<"ProcessorID")));/* CPU */
    //key.append(getKey(runPro("wmic",QStringList()<<"diskdrive"<<"get"<<"serialnumber")));/* 硬盘 */
    key.append(getKey(runPro("wmic",QStringList()<<"baseboard"<<"get"<<"serialnumber")));/* 主板 */
    key.append(getKey(runPro("wmic",QStringList()<<"csproduct"<<"get"<<"UUID")));/* UUID */

    if(QByteArray("cheng870888").toHex()+QCryptographicHash::hash(key.insert(3,"Cheng870888"),QCryptographicHash::Md5).toHex()==key1){
        emit GetTheEncryptedStateSignal(true);
        qDebug()<<"emit GetTheEncryptedStateSignal(true);";
    }
    else {
        emit GetTheEncryptedStateSignal(false);
        qDebug()<<"emit GetTheEncryptedStateSignal(false);";
    }

    if(ind==0){
        pTimer->stop();
    }
    else {
        ind--;
    }
}

QString Encryption::getKey(QByteArray arr)
{
    QString str=arr.data();
    QStringList tmp=str.simplified().split(" ");
    if(tmp.count()==2){
        return tmp[1];
    }
    return "E";
}

QByteArray Encryption::runPro(QString cmd, QStringList arg)
{
    QProcess process;
    process.setProgram(cmd);
    process.setArguments(arg);
    process.start();

    process.closeWriteChannel();
    if(process.waitForFinished()){
        return  process.readAll();
    }

    process.close();
    return "";
}
