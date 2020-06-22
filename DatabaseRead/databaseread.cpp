#include "databaseread.h"


DatabaseRead::DatabaseRead(QObject *parent)
{
    this->setParent(parent);
}

DatabaseRead::~DatabaseRead()
{

}

void DatabaseRead::initDatabaseSlot(const QString &connectName, const QString &user, const QString &pass, const QString &ip)
{
    /*  创建插件目录  */
    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    if(!dir.cd(pluginPath)){
        dir.mkdir(pluginPath);
        dir.cd(pluginPath);
    }

    this->connectName=connectName;

    db=QSqlDatabase::addDatabase("QSQLITE",connectName);
    db.setDatabaseName(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg("History.db")));
    db.setUserName(user);
    db.setPassword(pass);
    db.setHostName(ip);

    if(db.open()){

        QSqlQuery query(db);
        query.prepare(tr("CREATE TABLE `Containers` (\
                      `ID`	INTEGER PRIMARY KEY AUTOINCREMENT,\
                      `Timer`	TEXT NOT NULL,\
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
                      `PlateImg`	TEXT\
                  )"));
        if(!query.exec()){
                          emit messageSignal(ZBY_LOG("ERROR"),tr("Create table containers error<errorCode=%1>").arg(query.lastError().text()));
                      }
                      else {
                          emit messageSignal(ZBY_LOG("INFO"),tr("ZBY_LOG_INFO(Create table Containers sucess"));
                      }
                      query.clear();
    }
    else {
        emit messageSignal(ZBY_LOG("ERROR"),tr("Open databse  error<errorCode=%1>").arg(db.lastError().text()));
    }
    db.close();
}

void DatabaseRead::setDatabaseFilterSlot(const QString &filter)
{
    //locker.lockForRead();

    if(db.open()){

        QSqlTableModel* model=new  QSqlTableModel(this,db);/* 在数据库界面已做删除 */
        model->setTable(tr("Containers"));
        model->setFilter(filter);
        model->select();
        while (model->canFetchMore()) {
            model->fetchMore();
        }
\
        /* 统计数据 */
        statisticalData(model);
        emit returnModelSingal(model);
    }
    else {
        emit messageSignal(ZBY_LOG("ERROR"),tr("Open databse  error<errorCode=%1>").arg(db.lastError().text()));
    }
    db.close();

    //locker.unlock();
}

void DatabaseRead::statisticalData(QSqlTableModel *model)
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
