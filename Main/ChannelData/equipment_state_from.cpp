﻿#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
#pragma execution_character_set("utf-8")
#endif

#include "equipment_state_from.h"
#include "ui_equipment_state_from.h"

Equipment_State_From::Equipment_State_From(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Equipment_State_From)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setVisible(false);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Equipment_State_From::~Equipment_State_From()
{
    delete ui;
}

void Equipment_State_From::initializesTheDeviceStateListSlot(int count, QStringList rowLabels)
{
    ui->tableWidget->setColumnCount(LocalPar::DeviceStateList.count());
    ui->tableWidget->setHorizontalHeaderLabels(LocalPar::DeviceStateList);
    ui->tableWidget->setRowCount(count);
    ui->tableWidget->setVerticalHeaderLabels(rowLabels);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-4,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-3,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-2,QHeaderView::ResizeToContents);

    for (int row=0;row<ui->tableWidget->rowCount();++row) {
        for (int column=0;column<ui->tableWidget->columnCount();++column) {
            QString state=QString("%1").arg("ON");
            if(column<=LocalPar::Serial2){
               state=QString("%1").arg("XX");
            }
            else if (LocalPar::A1<=column && column <=LocalPar::D4) {
                state=QString::number(0);
            }
            else if(column==LocalPar::Con1 || column==LocalPar::Con2){
                state="***********";
            }
            else if(column==LocalPar::Plate1){
                state="******";
            }
            else if(column==LocalPar::Msg){
                state=tr("%1").arg("This is the test data");
            }
            ui->tableWidget->setItem(row,column,new QTableWidgetItem (state));
            //ui->tableWidget->setStyleSheet("background-color:#a8a8a8");
            ui->tableWidget->item(row,column)->setBackgroundColor("#ebebeb");
            ui->tableWidget->item(row,column)->setTextColor(Qt::red);
            ui->tableWidget->item(row,column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }
}

void Equipment_State_From::setDeviceStatusSlot(int channel, int equipment, bool state)
{
    QString text="";
    QColor color;

    if(equipment<=LocalPar::Serial2){
        text=state?"OK":"XX";
        color=state?Qt::blue:Qt::red;
    }
    else if (LocalPar::A1<= equipment && equipment<=LocalPar::D4) {
        text=state?"1":"0";
        color=state?Qt::blue:Qt::blue;
    }

    ui->tableWidget->item(channel-1,equipment)->setText(text);
    ui->tableWidget->item(channel-1,equipment)->setTextColor(color);
}
