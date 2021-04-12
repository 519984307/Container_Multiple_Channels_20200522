#include "data_log_form.h"
#include "ui_data_log_form.h"

#include <QDebug>
Data_Log_Form::Data_Log_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data_Log_Form)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setVisible(false);
    textCount=0;
    ServiceCount=0;

    ui->tabWidget->setCurrentIndex(0);
}

Data_Log_Form::~Data_Log_Form()
{
    qDebug()<<"~Data_Log_Form()";
    delete ui;
}

void Data_Log_Form::slot_newLogText(QtMsgType type,QDateTime time,QString value)
{
    QString msgType=QString("");
    switch (type) {
    case QtDebugMsg:
        msgType="Debug";
        break;
    case QtInfoMsg:
        msgType="Info";
        break;
    case QtWarningMsg:
        msgType="Warning";
        break;
    case QtCriticalMsg:
        msgType="Critical";
        break;
    case QtFatalMsg:
        msgType="Fatal";
        abort();
    }

    if(ui->logTableWidget->rowCount()>=100){
        ui->logTableWidget->removeRow(0);
        //ui->logTableWidget->clearContents();
    }
    int row=ui->logTableWidget->rowCount();
    ui->logTableWidget->insertRow(row);
    ui->logTableWidget->setItem(row,1,new QTableWidgetItem(msgType));
    ui->logTableWidget->setItem(row,0,new QTableWidgetItem(time.toString("yyyy-MM-dd hh:mm:ss zzz")));
    ui->logTableWidget->setItem(row,2,new QTableWidgetItem(value));
    if(msgType=="Info"){
        ui->logTableWidget->item(row,2)->setBackgroundColor(QColor(Qt::green));
    }
    ui->logTableWidget->scrollToBottom();
}

void Data_Log_Form::slot_sendLogToUi(int channel_number,  QString msg)
{
    if(textCount==30){
        ui->plainTextEdit->clear();
    }
    textCount++;
    ui->plainTextEdit->appendPlainText(QString("%1|%2").arg(channel_number).arg(msg));
}

void Data_Log_Form::slot_linkState(const QString &address,quint16 port, bool state)
{
    int RowCont=ui->tableWidget->rowCount();
    if(RowCont>1000){
        ui->tableWidget->clearContents();
        RowCont=ui->tableWidget->rowCount();
    }

    ui->tableWidget->insertRow(RowCont);

    ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz")));
    ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(address));
    ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(QString::number(port)));
    ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(state?"YES":"NO"));

    if(state){
        ui->tableWidget->item(RowCont, 3)->setBackground(Qt::green);
    }
    else {
        ui->tableWidget->item(RowCont, 3)->setBackground(Qt::red);
    }
}

void Data_Log_Form::slot_connectCount(int count)
{
    ServiceCount+=count;
    if(ServiceCount<0){
        ServiceCount=0;
    }
    ui->tabWidget->setTabText(1,QString("Service [ %1 ]").arg(ServiceCount));
    if(ServiceCount==0){
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(170,0,0);font:13pt '宋体';color: white;};");
    }
    else {
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(0,85,0);font:13pt '宋体';color: white;};");
    }
}
