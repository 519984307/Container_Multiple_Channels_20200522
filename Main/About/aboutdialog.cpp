#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QDebug>
AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->copyrightLabel->setText(LocalPar::copyright);
    ui->appLabel->setText(LocalPar::App);
    ui->verLabel->setText(LocalPar::version);
    ui->ID_label->setText(LocalPar::DogID);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
