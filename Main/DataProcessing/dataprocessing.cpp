#include "dataprocessing.h"

#include <QStandardPaths>

DataProcessing::DataProcessing(QObject *parent) : QObject(parent)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString stringDateTime = dateTime.toString( "yyyy_MM_dd_hh_mm_ss" );
    QString path = QStandardPaths::writableLocation( QStandardPaths::AppConfigLocation );

    QString logFolderName =QDir::toNativeSeparators(path + "/" + "send_log");
    if( !QDir( logFolderName ).exists() )
    {
        QDir().mkpath( logFolderName );
    }

    logFile.setFileName( QDir::toNativeSeparators(logFolderName+ "/" + stringDateTime + ".log" ));

    // If more 30 files, remove the last.
    QDir dir( logFolderName );
    dir.setFilter( QDir::Files );
    dir.setSorting( QDir::Name );
    QList<QFileInfo> list = dir.entryInfoList();
    if ( list.count() > 30 )
    {
        QFile file( list.at(0).absoluteFilePath() );
        file.remove();
    }

}

void DataProcessing::writeDataToLog(int channel_number, const QString &result)
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

}

void DataProcessing::slot_containerResult(int channel, const QString &result)
{        
    if(result.startsWith("[") && result.endsWith("]")){        
        QString tmpMsg=result.mid(1,result.size()-2);
        QStringList msgList=tmpMsg.split("|");

        if(msgList.size()>=5){
            /*****************************
            * @brief:数据流量统计到主页面
            ******************************/
            emit signal_trafficStatistics(msgList.at(5)=="Y"?true:false);
        }

        if(Parameter::DataChange_Format==0){
            emit signal_toSendData(channel,result);
            writeDataToLog(channel,result);
            return;
        }

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
            writeDataToLog(channel,QString(QJsonDocument(jsonChild).toJson()));
        }

        return;
    }
    qCritical().noquote()<<QString("If the data of box number is abnormal, it will not be processed.");
}
