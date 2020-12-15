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

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-4,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-3,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(ui->tableWidget->columnCount()-2,QHeaderView::ResizeToContents);
}

Equipment_State_From::~Equipment_State_From()
{
    delete ui;
}

void Equipment_State_From::initializesTheDeviceStateListSlot(int count, QStringList rowLabels)
{
    ui->tableWidget->setRowCount(count);
    ui->tableWidget->setVerticalHeaderLabels(rowLabels);

    for (int row=0;row<ui->tableWidget->rowCount();++row) {
        for (int column=0;column<ui->tableWidget->columnCount();++column) {
            QString state=QString("%1").arg("ON");
            if(column<8){
               state=QString("%1").arg("XX");
            }
            else if(column==14 || column==15){
                state="MSDU1234567";
            }
            else if(column==16){
                state="粤B050CS";
            }
            else if(column==17){
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

    if(equipment<6){
        text=state?"OK":"XX";
        color=state?Qt::green:Qt::red;
    }
    else if (6< equipment and equipment<12) {
        text=state?"OFF":"NO";
        color=state?Qt::green:Qt::red;
    }

    ui->tableWidget->item(channel-1,equipment-1)->setText(text);
    ui->tableWidget->item(channel-1,equipment-1)->setTextColor(color);
}
