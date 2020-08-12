#include "operational_log_form.h"
#include "ui_operational_log_form.h"

Operational_Log_Form::Operational_Log_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Operational_Log_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Operational_Log_Form::~Operational_Log_Form()
{
    delete ui;
}
