#include "communication_logs_form.h"
#include "ui_communication_logs_form.h"

Communication_Logs_Form::Communication_Logs_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Communication_Logs_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Communication_Logs_Form::~Communication_Logs_Form()
{
    delete ui;
}
