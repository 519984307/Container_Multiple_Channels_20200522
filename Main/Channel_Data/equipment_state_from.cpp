#include "equipment_state_from.h"
#include "ui_equipment_state_from.h"

Equipment_State_From::Equipment_State_From(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Equipment_State_From)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-4,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-3,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-2,QHeaderView::ResizeToContents);
}

Equipment_State_From::~Equipment_State_From()
{
    delete ui;
}

void Equipment_State_From::initializesTheDeviceStateListSlot(uint count, QStringList rowLabels)
{
    ui->tableWidget->setRowCount(static_cast<int>(count));
    ui->tableWidget->setVerticalHeaderLabels(rowLabels);

    for (int row=0;row<ui->tableWidget->rowCount();++row) {
        for (int column=0;column<ui->tableWidget->columnCount();++column) {
            QString state=tr("%1").arg("ON");
            if(column<6){
               state=tr("%1").arg("XX");
            }
            else if(column==12 || column==13){
                state="MSDU1234567";
            }
            else if(column==14){
                state="粤B050CS";
            }
            else if(column==15){
                state=tr("%1").arg("This is the test data");
            }
            ui->tableWidget->setItem(row,column,new QTableWidgetItem (state));
            ui->tableWidget->setStyleSheet("background-color:#a8a8a8");
            ui->tableWidget->item(row,column)->setBackgroundColor(QColor(255,0,0));
            ui->tableWidget->item(row,column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }
}

void Equipment_State_From::setDeviceStatusSlot(uint channel, int equipment, QString state)
{

}
