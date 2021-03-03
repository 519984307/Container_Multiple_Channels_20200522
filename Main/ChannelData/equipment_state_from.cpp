#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
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

    isInitload=true;
}

Equipment_State_From::~Equipment_State_From()
{
    delete ui;
}

void Equipment_State_From::initializesTheDeviceStateListSlot(int count, QStringList rowLabels)
{
    if(!isInitload){
        return;
    }
    isInitload=false;
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
                state=QString("***********");
            }
            else if(column==LocalPar::Plate1){
                state=QString("******");
            }
            else if(column==LocalPar::Msg){
                state=QString("%1").arg("");
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
        color=state?Qt::blue:Qt::red;
    }

    ui->tableWidget->item(channel-1,equipment)->setText(text);
    ui->tableWidget->item(channel-1,equipment)->setTextColor(color);
}

void Equipment_State_From::slot_container(const int &channelID, const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2)
{
    Q_UNUSED(iso1);
    Q_UNUSED(iso2);

    ui->tableWidget->item(channelID-1,LocalPar::Con1)->setText("");
    ui->tableWidget->item(channelID-1,LocalPar::Con2)->setText("");
    ui->tableWidget->item(channelID-1,LocalPar::Msg)->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));

    ui->tableWidget->item(channelID-1,LocalPar::Con1)->setTextColor(resultCheck1?Qt::blue:Qt::red);
    ui->tableWidget->item(channelID-1,LocalPar::Con2)->setTextColor(resultCheck2?Qt::blue:Qt::red);
    ui->tableWidget->item(channelID-1,LocalPar::Msg)->setTextColor(Qt::black);

    ui->tableWidget->item(channelID-1,LocalPar::Con1)->setText(result1);
    if(result1.isEmpty()){
        ui->tableWidget->item(channelID-1,LocalPar::Con1)->setText("failure");
    }
    if(2==type){
        ui->tableWidget->item(channelID-1,LocalPar::Con2)->setText(result2);
        if(result2.isEmpty()){
            ui->tableWidget->item(channelID-1,LocalPar::Con2)->setText("failure");
        }
    }
}

void Equipment_State_From::slot_plate(const int &channelID, const QString &plate, const QString &color, const QString &time)
{
    Q_UNUSED(time);

    ui->tableWidget->item(channelID-1,LocalPar::Msg)->setText(time);
    ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setText(plate);
    if("黄"==color){
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setBackgroundColor(Qt::yellow);
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setTextColor(Qt::black);
    }
    if("蓝"==color){
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setBackgroundColor(Qt::blue);
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setTextColor(Qt::white);
    }
    if("无车牌"==plate){
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setBackgroundColor("#ebebeb");
        ui->tableWidget->item(channelID-1,LocalPar::Plate1)->setTextColor(Qt::red);
    }
}

void Equipment_State_From::slot_channelState(const int &channelID, const int &state)
{
    ui->tableWidget->item(channelID-1,LocalPar::Msg)->setTextColor(state?Qt::green:Qt::red);
    if(state){
        ui->tableWidget->item(channelID-1,LocalPar::Msg)->setText(QString("Vehicles entering"));
    }
    else {
        ui->tableWidget->item(channelID-1,LocalPar::Msg)->setText(QString("Vehicle reversing"));
    }
}
