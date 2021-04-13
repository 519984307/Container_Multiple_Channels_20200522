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

        if(Parameter::Identify_Protocol==0){
            CPH="";
        }
        else if(Parameter::Identify_Protocol==1){
            CPH=plate;
            if(plate!=""){
                discern="Y";
            }
            else {
                discern="N";
            }
        }

        //[C|20020919114100|01|1|TEXU7337250|Y|42G1]
        //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1]

        today=QDateTime::fromString(msgList.at(1).mid(0,8),"yyyyMMdd").toString("yyyy-MM-dd");
        time=QDateTime::fromString(msgList.at(1),"yyyyMMddhhmmss").toString("yyyy-MM-dd hh:mm:ss");
        content="";
        roadindex=QString("%1").arg(msgList.at(2).toInt(),2,10,QLatin1Char('0'));
        cartype=msgList.at(0);
        SOURCE="XAQ";
        type=msgList.at(3);
        isguard="1";

        if(msgList.size()==7){
            XH=msgList.at(4);
            boxtype=msgList.at(6);
            if(Parameter::Identify_Protocol==1){
                if(msgList.at(5)=="Y"){
                    discern.append("Y");
                }
                else {
                    discern.append("N");
                }
            }
        }
        if(msgList.size()==10){
            XH=msgList.at(4)+"/"+msgList.at(6);
            boxtype=msgList.at(8)+"/"+msgList.at(9);
            if(Parameter::Identify_Protocol==1){
                if(msgList.at(5)=="Y"){
                    discern.append("Y");
                }
                else {
                    discern.append("N");
                }
                if(msgList.at(7)=="Y"){
                    discern.append("Y");
                }
                else {
                    discern.append("N");
                }
            }
        }

        if(Parameter::DataChange_Format==0){
            if(Parameter::Identify_Protocol==1 && result.endsWith("]")){
                QString tmpR=result.mid(0,result.size()-1).append(QString("|%1|%2]").arg(plate).arg(plateColor));
                emit signal_toSendData(channel,tmpR);
                writeDataToLog(channel,tmpR);
            }
            if(Parameter::Identify_Protocol==0){
                emit signal_toSendData(channel,result);
                writeDataToLog(channel,result);
            }
        }
        if(Parameter::DataChange_Format==1){
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

            emit signal_toSendData(channel,QString(QJsonDocument(jsonChild).toJson()));
            writeDataToLog(channel,QString(QJsonDocument(jsonChild).toJson()));
        }
        discern.clear();
        plate.clear();
        plateColor.clear();
        plateTime.clear();
    }
    else {
        qCritical().noquote()<<QString("If the data of box number is abnormal, it will not be processed.");
    }
}

void DataProcessing::slot_plateResult(int channel, bool isConCar, const QString &plate, const QString &color, const QString &plateTime)
{
    /*****************************
    * @brief:车牌结果显出
    ******************************/

    QString result="";

    if(Parameter::DataChange_Format==0){
        /* 识别结果写入日志[标志|时间戳|通道号(2位)|逻辑|车牌|颜色] */
        result=QString("[U|%1|%2|%3|%4]").arg(QDateTime::fromString(plateTime,"yyyy-M-d h:m:s").toString("yyyyMMddhhmmss")).arg(channel,2,10,QLatin1Char('0')).arg(plate).arg(color);
    }
    if (Parameter::DataChange_Format==1) {

        QString tmpTime= QString("%1").arg(QDateTime::fromString(plateTime,"yyyy-M-d h:m:s").toString("yyyyMMddhhmmss"));

        today=QDateTime::fromString(tmpTime.mid(0,8),"yyyyMMdd").toString("yyyy-MM-dd");
        time=QDateTime::fromString(tmpTime,"yyyyMMddhhmmss").toString("yyyy-MM-dd hh:mm:ss");
        content="";
        CPH=plate;
        XH="";
        roadindex=QString("%1").arg(channel,2,10,QLatin1Char('0'));
        cartype="U";
        boxtype="";
        if(plate!=nullptr){
            discern="Y";
        }
        else {
            discern="N";
        }
        SOURCE="XAQ";
        type="-1";
        isguard="1";

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

        result = QString(QJsonDocument(jsonChild).toJson());
    }

    if(Parameter::Identify_Protocol==0){
        emit signal_toSendData(channel,result);
    }
    if(Parameter::Identify_Protocol==1){
        if(!isConCar){
            emit signal_toSendData(channel,result);
        }
        else {
            this->plate=plate;
            this->plateColor=color;
            this->plateTime=time;
        }
    }
    writeDataToLog(channel,result);
}
