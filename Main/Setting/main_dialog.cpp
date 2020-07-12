#include "main_dialog.h"
#include "ui_main_dialog.h"

Main_Dialog::Main_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Dialog)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Main_Dialog::~Main_Dialog()
{
    delete ui;
}

void Main_Dialog::on_pushButton_clicked()
{
    this->done(10);
}
