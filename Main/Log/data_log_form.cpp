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
