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
}

Equipment_State_From::~Equipment_State_From()
{
    delete ui;
}
