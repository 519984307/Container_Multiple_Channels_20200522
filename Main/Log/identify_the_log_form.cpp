#include "identify_the_log_form.h"
#include "ui_identify_the_log_form.h"

Identify_The_Log_Form::Identify_The_Log_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Identify_The_Log_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Identify_The_Log_Form::~Identify_The_Log_Form()
{
    delete ui;
}
