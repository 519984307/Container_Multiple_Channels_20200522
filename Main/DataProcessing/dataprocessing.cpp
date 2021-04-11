#include "dataprocessing.h"

#include <QStandardPaths>

DataProcessing::DataProcessing(QObject *parent) : QObject(parent)
{

}

void DataProcessing::slot_sendDataToLog(int channel_number, const QString &result)
{
    lock.lockForWrite();

#ifdef Q_OS_LINUX
    QString eol = "\n";
#endif
#ifdef Q_OS_WIN
    QString eol = "\r\n";
#endif
    logFile.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    logFile.write( QString("[%1   Channel   :   %2]    ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz")).arg(channel_number).toUtf8()+result.toUtf8() );
    logFile.write( eol.toUtf8() );
    logFile.close();

    lock.unlock();

    emit signal_sendLogToUi(channel_number,result);
}

void DataProcessing::slot_containerResult(int channel, const QString &result)
{
    if(Parameter::DataChange_Format==0){
        emit signal_toSendData(channel,result);
        return;
    }

    if(result.startsWith("[") && result.endsWith("]")){
        QString tmpMsg=result.mid(1,result.size()-2);
        QStringList msgList=tmpMsg.split("|");
        if(msgList.size()>=3){

            today=QDateTime::fromString(msgList.at(1).mid(0,8),"yyyyMMdd").toString("yyyy-MM-dd");
            time=QDateTime::fromString(msgList.at(1),"yyyyMMddhhmmss").toString("yyyy-MM-dd hh:mm:ss");
            roadindex=msgList.at(2);
            cartype=msgList.at(0);
            SOURCE="XAQ";
            type=msgList.at(3);
            isguard="1";
            content="";
            discern="";

            if(msgList.at(0)=="C"){
                if(msgList.at(3).toInt()<2){
                    XH=msgList.at(4);
                    if(msgList.size()==9 &&Parameter::Identify_Protocol==1){
                        CPH=msgList.at(7);
                        if(!msgList.at(7).isEmpty()){
                            discern="Y";
                        }
                        else {
                            discern="N";
                        }
                    }
                    discern.append(msgList.at(5));
                    boxtype=msgList.at(6);
                }
                else {
                    XH=QString("%1/%2").arg(msgList.at(4)).arg(msgList.at(6));
                    if(msgList.size()==12 &&Parameter::Identify_Protocol==1){
                        CPH=msgList.at(10);
                        if(!msgList.at(10).isEmpty()){
                            discern="Y";
                        }
                        else {
                            discern="N";
                        }
                    }
                    discern.append(msgList.at(5));
                    discern.append(msgList.at(7));
                    boxtype=QString("%1/%2").arg(msgList.at(8)).arg(msgList.at(9));
                }
            }
            else if (msgList.at(0)=="U" && msgList.size()>=5) {
                CPH=msgList.at(3);
            }
        }

        jsonChild.insert("today",today);
        jsonChild.insert("time",time);
        jsonChild.insert("content",content);
        jsonChild.insert("CPH",CPH);
        jsonChild.insert("XH",XH);
        jsonChild.insert("roadindex",roadindex);
        jsonChild.insert("cartype",cartype);
        jsonChild.insert("boxtype",boxtype);
        jsonChild.insert("discern",discern);
        jsonChild.insert("SOURCE",SOURCE);
        jsonChild.insert("type",type);
        jsonChild.insert("isguard",isguard);

        if (Parameter::DataChange_Format==1) {
            emit signal_toSendData(channel,QString(QJsonDocument(jsonChild).toJson()));
        }

        return;
    }
    qCritical().noquote()<<QString("If the data of box number is abnormal, it will not be processed.");
}
