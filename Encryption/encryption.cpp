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
    dogType=0;

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
    /* 福建达远
     * ed302361196401966c72f116402e9297
     * ae68c66368a8e943bc260ae97003747f
    */
    /* 辽宁锦州
     * 2895743a6f3c423adfc444d16076e085
    */
    /* 惠州key
     * 5e8d317e83c2f7ace3584a929961fcb4
    */
    /*沈阳安信
     * f19d15dec81584b5ce4f9edb0aae1789
    */
    /*福建平潭
     * ae68c66368a8e943bc260ae97003747f
    */
    /* 烟台贝奇
     * f19d15dec81584b5ce4f9edb0aae1789
    */
    if(SmartX3Find!=nullptr && SmartX3Find(appID,keyHandles,&keyNumber)==0){
        if(SmartX3GetUid!=nullptr && SmartX3GetUid(keyHandles[0],UID)==0){
            //qDebug()<<"UID:"<<UID;
            if(strncmp(UID,"f19d15dec81584b5ce4f9edb0aae1789",33)==0){
                dogState=true;
            }
            else {
                dogState=false;
            }

            /*****************************
            * @brief:单通道不需要加密狗号
            ******************************/
            if(0==dogType){
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
    if(0==dogType){
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
