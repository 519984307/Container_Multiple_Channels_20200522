#include "databaseinsert.h"
#include <QDebug>

DataBaseInsert::DataBaseInsert(QObject *parent)
{
    this->setParent(parent);
}

DataBaseInsert::~DataBaseInsert()
{
    //QSqlDatabase::removeDatabase(connectName);
    qDebug().noquote()<<QString("~DataBaseInsert");
}

QString DataBaseInsert::InterfaceType()
{
    return QString("SQLITE_INSERT");
}

void DataBaseInsert::initDataBaseSlot(const QString &connectName,const QString &user, const QString &pass, const QString &ip,const int &dataBaseType)
{
    /*  创建插件目录  */
    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    dir.mkdir(pluginPath);
    dir.cd(pluginPath);

    this->connectName=QString("DataBaseInsert_").append(connectName);

    switch (dataBaseType) {
    case 0:
        db=QSqlDatabase::addDatabase("QSQLITE",this->connectName);
        break;
    case 1:
        db=QSqlDatabase::addDatabase("QMYSQL",this->connectName);
    }

    db.setDatabaseName(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg("history")));
    db.setUserName(user);
    db.setPassword(pass);
    db.setHostName(ip);
    //db.setPort(3366);

    if(!db.open()){
        qWarning().noquote()<<QString("Open databse  error<errorCode=%1>").arg(db.lastError().text());
    }
    db.close();
}

void DataBaseInsert::insertDataBaseSlot(QMap<QString, QString> data)
{
    locker.lockForWrite();

    if(db.open()){
        QScopedPointer<QSqlTableModel> model(new QSqlTableModel(this,db));
        //QSqlTableModel model(this,db);
        model->setTable(QString("Containers"));
        QSqlRecord record=model->record();

        foreach (auto key, data.keys()) {
            record.setValue(key,data.value(key));
        }

//        /*****************************
//        * @brief:只有车牌
//        ******************************/
//        if(nullptr == data.value("Timer",nullptr)){
//            record.setValue("Timer",data.value("PlateTimer"));
//            record.setValue("Channel",data.value("Channel",QString::number(99)));
//            record.setValue("Type",data.value("Type",QString::number(-1)));
//            record.setValue("Plate",data.value("Plate"));
//            record.setValue("PlateTimer",data.value("PlateTimer"));
//            record.setValue("PlateImg",data.value("PlateImg"));
//        }
//        else {
//            record.setValue("Timer",data.value("Timer",nullptr));
//            record.setValue("Channel",data.value("Channel",QString::number(99)));
//            record.setValue("Type",data.value("Type",QString::number(99)));
//            record.setValue("ImgFront",data.value("ImgFront"));
//            record.setValue("ImgLeftFront",data.value("ImgLeftFront"));
//            record.setValue("ImgRightFront",data.value("ImgRightFront"));
//            record.setValue("ImgLeftAfter",data.value("ImgLeftAfter"));
//            record.setValue("ImgRightAfter",data.value("ImgRightAfter"));
//            record.setValue("ImgAfter",data.value("ImgAfter"));
//            record.setValue("ImgProspects",data.value("ImgProspects"));
//            record.setValue("ImgForeground",data.value("ImgForeground"));
//            record.setValue("ImgTop1",data.value("ImgTop1"));
//            record.setValue("ImgTop2",data.value("ImgTop2"));
//        }
        if(!model->insertRecord(-1,record)){
            qWarning().noquote()<<QString("%1:Insert data to databse  error<errorCode=%2>").arg(record.value("Timer").toString()).arg(model->lastError().text());
        }
        else {
            qDebug().noquote()<<QString("%1:Insert data to databse  sucessful").arg(record.value("Timer").toString());
        }
        model->submitAll();

        data.clear();
        record.clearValues();
        model->clear();
    }
    else {
        qWarning().noquote()<<QString("Open databse  error<errorCode=%1>").arg(db.lastError().text());
    }
    db.close();
    locker.unlock();
}

void DataBaseInsert::updateDataBaseSlot(QMap<QString, QString> data)
{
    locker.lockForWrite();

    if(db.open()){
        QScopedPointer<QSqlTableModel> model(new QSqlTableModel(this,db));
        //QSqlTableModel model(this,db);
        model->setTable(QString("Containers"));
        model->setFilter(QString("Timer='%1' AND Channel='%2'").arg(data.value("Timer")).arg(data.value("Channel")));
        model->select();
        if(model->rowCount()==1){
            QSqlRecord record=model->record(0);

            foreach (auto key, data.keys()) {
                record.setValue(key,data.value(key));
            }

//            /*****************************
//            * @brief:有车牌
//            ******************************/
//            if(nullptr != data.value("PlateTimer",nullptr)){
//                record.setValue("Plate",data.value("Plate"));
//                record.setValue("PlateTimer",data.value("PlateTimer"));
//                record.setValue("PlateImg",data.value("PlateImg"));
//            }
//            else {
//                record.setValue("Type",data.value("Type"));
//                record.setValue("ContainerFront",data.value("ContainerFront"));
//                record.setValue("CheckFront",data.value("CheckFront"));
//                record.setValue("ISOFront",data.value("ISOFront"));
//                record.setValue("ContainerAfter",data.value("ContainerAfter"));
//                record.setValue("CheckAfter",data.value("CheckAfter"));
//                record.setValue("ISOAfter",data.value("ISOAfter"));
//                record.setValue("ImgFrontNumber",data.value("ImgFrontNumber"));
//                record.setValue("ImgFrontCheck",data.value("ImgFrontCheck"));
//                record.setValue("ImgLeftFrontNumber",data.value("ImgLeftFrontNumber"));
//                record.setValue("ImgLeftFrontCheck",data.value("ImgLeftFrontCheck"));
//                record.setValue("ImgRightFrontNumber",data.value("ImgRightFrontNumber"));
//                record.setValue("ImgRightFrontCheck",data.value("ImgRightFrontCheck"));
//                record.setValue("ImgLeftAfterNumber",data.value("ImgLeftAfterNumber"));
//                record.setValue("ImgLeftAfterCheck",data.value("ImgLeftAfterCheck"));
//                record.setValue("ImgRightAfterNumber",data.value("ImgRightAfterNumber"));
//                record.setValue("ImgRightAfterCheck",data.value("ImgRightAfterCheck"));
//                record.setValue("ImgAfterNumber",data.value("ImgAfterNumber"));
//                record.setValue("ImgAfterCheck",data.value("ImgAfterCheck"));
//                record.setValue("ImgFrontISO",data.value("ImgFrontISO"));
//                record.setValue("ImgLeftFrontISO",data.value("ImgLeftFrontISO"));
//                record.setValue("ImgRightFrontISO",data.value("ImgRightFrontISO"));
//                record.setValue("ImgLeftAfterISO",data.value("ImgLeftAfterISO"));
//                record.setValue("ImgRightAfterISO",data.value("ImgRightAfterISO"));
//                record.setValue("ImgAfterISO",data.value("ImgAfterISO"));
//            }

            if(!model->setRecord(0,record)){
                qWarning().noquote()<<QString("Update data to databse  error<errorCode=%1>").arg(model->lastError().text());
            }
            else {
                QString timer="";
                if(!data.value("Timer","").isEmpty()){
                    timer=data.value("Timer");
                }
                else {
                    timer=data.value("PlateTimer");
                }
                qDebug().noquote()<<QString("Update data to databse  sucessful time=%1").arg(timer);
            }
            model->submitAll();
            data.clear();
            record.clear();
            model->clear();
        }
    }
    db.close();
    locker.unlock();
}
