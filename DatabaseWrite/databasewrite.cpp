#include "databasewrite.h"

DatabaseWrite::DatabaseWrite(QObject *parent)
{
    this->setParent(parent);
}

DatabaseWrite::~DatabaseWrite()
{
    //QSqlDatabase::removeDatabase(connectName);
}

void DatabaseWrite::initDatabaseSlot(const QString &connectName, const QString &user, const QString &pass, const QString &ip)
{
    /*  创建插件目录  */
    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    if(!dir.cd(pluginPath)){
        dir.mkdir(pluginPath);
        dir.cd(pluginPath);
    }

    this->connectName=QString("DataBaseInsert_").append(connectName);

    db=QSqlDatabase::addDatabase("QSQLITE",this->connectName);
    db.setDatabaseName(QDir::toNativeSeparators(tr("%1/%2/%3").arg(dir.path()).arg("History.db")));
    db.setUserName(user);
    db.setPassword(pass);
    db.setHostName(ip);

    if(!db.open()){
        emit messageSignal(ZBY_LOG("ERROR"),tr("Open databse  error<errorCode=%1>").arg(db.lastError().text()));
    }
    db.close();
}

void DatabaseWrite::insertDatabaseSlot(QMap<QString, QString> data)
{
    locker.lockForWrite();

    if(db.open()){
        QSqlTableModel model(this,db);
        model.setTable(tr("Containers"));
        //model.select();
        QSqlRecord record=model.record();
        record.setValue("Timer",data.value("Timer","NUL"));
        record.setValue("Channel",data.value("Channel","NUL"));
        record.setValue("Type",data.value("Type",QString::number(0)));
        //record.setValue("ContainerFront",data.value("ContainerFront"));
        //record.setValue("CheckFront",data.value("CheckFront"));
        //record.setValue("ISOFront",data.value("ISOFront"));
        //record.setValue("ContainerAfter",data.value("ContainerAfter"));
        //record.setValue("CheckAfter",data.value("CheckAfter"));
        //record.setValue("ISOAfter",data.value("ISOAfter"));
        record.setValue("ImgFront",data.value("ImgFront"));
        record.setValue("ImgLeftFront",data.value("ImgLeftFront"));
        record.setValue("ImgRightFront",data.value("ImgRightFront"));
        record.setValue("ImgLeftAfter",data.value("ImgLeftAfter"));
        record.setValue("ImgRightAfter",data.value("ImgRightAfter"));
        record.setValue("ImgAfter",data.value("ImgAfter"));
        //record.setValue("Plate",data.value("Plate"));
        //record.setValue("PlateTimer",data.value("PlateTimer"));
        //record.setValue("PlateImg",data.value("PlateImg"));

        if(!model.insertRecord(0,record)){
            emit messageSignal(ZBY_LOG("ERROR"),tr("Insert data to databse  error<errorCOde=%1>").arg(model.lastError().text()));
        }
        else {
            emit messageSignal(ZBY_LOG("INFO"),tr("Insert data to databse  sucessful time=%1").arg(data.value("Timer")));
        }
        model.submitAll();

        /*
         * 清除数据
         */
        data.clear();
        record.clear();
        model.clear();
    }
    else {
        emit messageSignal(ZBY_LOG("ERROR"),tr("Open databse  error<errorCode=%1>").arg(db.lastError().text()));
    }
    db.close();

    locker.unlock();
}

void DatabaseWrite::updateDatabaseSlot(QMap<QString, QString> data)
{
    locker.lockForWrite();

    if(db.open()){
        QSqlTableModel model(this,db);
        model.setTable(tr("Containers"));
        model.setFilter(tr("Timer='%1' AND Channel='%2'").arg(data.value("Timer")).arg(data.value("Channel")));
        model.select();
        if(model.rowCount()==1){
            QSqlRecord record=model.record(0);
            record.setValue("Type",data.value("Type"));
            record.setValue("ContainerFront",data.value("ContainerFront"));
            record.setValue("CheckFront",data.value("CheckFront"));
            record.setValue("ISOFront",data.value("ISOFront"));
            record.setValue("ContainerAfter",data.value("ContainerAfter"));
            record.setValue("CheckAfter",data.value("CheckAfter"));
            record.setValue("ISOAfter",data.value("ISOAfter"));
            record.setValue("ImgFrontNumber",data.value("ImgFrontNumber"));
            record.setValue("ImgFrontCheck",data.value("ImgFrontCheck"));
            record.setValue("ImgLeftFrontNumber",data.value("ImgLeftFrontNumber"));
            record.setValue("ImgLeftFrontCheck",data.value("ImgLeftFrontCheck"));
            record.setValue("ImgRightFrontNumber",data.value("ImgRightFrontNumber"));
            record.setValue("ImgRightFrontCheck",data.value("ImgRightFrontCheck"));
            record.setValue("ImgLeftAfterNumber",data.value("ImgLeftAfterNumber"));
            record.setValue("ImgLeftAfterCheck",data.value("ImgLeftAfterCheck"));
            record.setValue("ImgRightAfterNumber",data.value("ImgRightAfterNumber"));
            record.setValue("ImgRightAfterCheck",data.value("ImgRightAfterCheck"));
            record.setValue("ImgAfterNumber",data.value("ImgAfterNumber"));
            record.setValue("ImgAfterCheck",data.value("ImgAfterCheck"));

            if(!model.setRecord(0,record)){
                emit messageSignal(ZBY_LOG("ERROR"),tr("Update data to databse  error<errorCOde=%1>").arg(model.lastError().text()));
            }
            else {
                emit messageSignal(ZBY_LOG("INFO"),tr("Update data to databse  sucessful time=%1").arg(data.value("Timer")));
            }
            model.submitAll();

            record.clear();
        }
        model.clear();
    }
    db.close();

    locker.unlock();
}
