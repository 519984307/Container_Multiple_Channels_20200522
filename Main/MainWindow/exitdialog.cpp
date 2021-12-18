#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->label->setText("Software exit, releasing internal resources, please wait!");

}

ExitDialog::~ExitDialog()
{
    delete ui;
}
