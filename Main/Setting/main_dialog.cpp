#include "main_dialog.h"
#include "ui_main_dialog.h"

#include "MainWindow/Processing/parameter.h"
#include "Setting/system_setting_form.h"

#include <QPointer>

Main_Dialog::Main_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Dialog)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    QPointer<System_Setting_Form> pForm(new System_Setting_Form(this));
    //pForm->InitializationParameterSlot();
    ui->ChannelNumber->setValue(Parameter::ChannelNumber);
}

Main_Dialog::~Main_Dialog()
{
    delete ui;
}

void Main_Dialog::on_pushButton_clicked()
{
    Parameter::ChannelNumber=ui->ChannelNumber->value();
    this->done(10);
}
