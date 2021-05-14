#include "databaseread.h"

DataBaseRead::DataBaseRead(QObject *parent)
{
    this->setParent(parent);
}

DataBaseRead::~DataBaseRead()
{
    //QSqlDatabase::removeDatabase(connectName);
}

QString DataBaseRead::InterfaceType()
{
    return QString("SQLITE_READ");
}

void DataBaseRead::initDataBaseSlot(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType)
{
    /*  创建插件目录  */
    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    dir.mkdir(pluginPath);
    dir.cd(pluginPath);

    this->connectName=QString("DataBaseRead_").append(connectName);
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

    if(db.open()){

        QSqlQuery query(db);
        query.prepare(QString("CREATE TABLE `Containers` (\
                      `ID`	INTEGER PRIMARY KEY AUTOINCREMENT,\
                      `Timer`	TEXT,\
                      `Channel`	INTEGER NOT NULL,\
                       'Type' INTEGER,\
                      `ContainerFront`	TEXT,\
                      `CheckFront`	INTEGER,\
                      `ISOFront`	TEXT,\
                      `ContainerAfter`	TEXT,\
                      `CheckAfter`	INTEGER,\
                      `ISOAfter`	TEXT,\
                      `ImgFront`	TEXT,\
                      'ImgFrontCheck'  INTEGER,\
                      `ImgFrontNumber`	TEXT,\
                      `ImgLeftFront`	TEXT,\
                      'ImgLeftFrontCheck'  INTEGER,\
                      `ImgLeftFrontNumber`	TEXT,\
                      `ImgRightFront`	TEXT,\
                      'ImgRightFrontCheck'  INTEGER,\
                      `ImgRightFrontNumber`	TEXT,\
                      `ImgLeftAfter`	TEXT,\
                      'ImgLeftAfterCheck'  INTEGER,\
                      `ImgLeftAfterNumber`	TEXT,\
                      `ImgRightAfter`	TEXT,\
                      'ImgRightAfterCheck'  INTEGER,\
                      `ImgRightAfterNumber`	TEXT,\
                      `ImgAfter`	TEXT,\
                      'ImgAfterCheck'  INTEGER,\
                      `ImgAfterNumber`	TEXT,\
                      `Plate`	 TEXT,\
                      `PlateTimer` 	TEXT,\
                      `PlateImg`	TEXT,\
                      `ImgFrontISO` TEXT,\
                      `ImgLeftFrontISO` TEXT,\
                      `ImgRightFrontISO` TEXT,\
                      `ImgLeftAfterISO` TEXT,\
                      `ImgRightAfterISO` TEXT,\
                      `ImgAfterISO` TEXT,\
                      `ImgProspects` TEXT,\
                      `ImgForeground` TEXT,\
                      `ImgTop1` TEXT,\
                      `ImgTop2` TEXT,\
                      `PlateColor`	TEXT\
                  )"));
        if(!query.exec()){
                          qWarning().noquote()<<QString("Create table containers error<errorCode=%1>").arg(query.lastError().text());
                      }
                      else {
                          qInfo().noquote()<<QString("Create table Containers sucess");
                      }
                      query.clear();
    }
    else {
        qWarning().noquote()<<QString("Open databse  error<errorCode=%1>").arg(db.lastError().text());
    }
    db.close();
}

void DataBaseRead::setDataBaseFilterSlot(const QString &filter)
{
    locker.lockForRead();

    if(db.open()){
        QScopedPointer<QSqlTableModel> model(new QSqlTableModel(this,db));
        //QSqlTableModel* model=new  QSqlTableModel(this,db);/* 在数据库界面已做删除 */
        qDebug().noquote()<<"Query database:"<<filter;
        model->setTable(QString("Containers"));
        model->setFilter(filter);
        model->select();
        while (model->canFetchMore()) {
            model->fetchMore();
        }
\
        /* 统计数据 */
        statisticalData(model.data());
        emit returnModelSingal(model.take());
    }
    else {
        qWarning().noquote()<<QString("Open databse  error<errorCode=%1>").arg(db.lastError().text());
    }
    db.close();
    locker.unlock();
}

void DataBaseRead::statisticalData(QSqlTableModel* model)
{
    QSqlRecord record;

    double correct=0;    double error=0;
    int rows= model->rowCount();

    for(int i=0;i<rows;i++){
        record=model->record(i);
        if(record.value("CheckFront").toBool()||record.value("CheckAfter").toBool()){
            correct++;
        }
        else {
            error++;
        }
    }
    record.clear();

    emit statisticalDataSignal(rows,correct,error,correct/rows*100);
}
