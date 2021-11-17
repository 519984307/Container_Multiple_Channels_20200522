#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QDebug>
AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    //ui->msg_groupBox->setHidden(true);

    ui->copyrightLabel->setText(LocalPar::copyright);
    ui->appLabel->setText(LocalPar::App);
    ui->verLabel->setText(LocalPar::version);
    ui->ID_label->setText(LocalPar::DogID);
    ui->Project_label->setText(LocalPar::proName);
    ui->Channel_label->setText(QString::number(LocalPar::Channels));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
