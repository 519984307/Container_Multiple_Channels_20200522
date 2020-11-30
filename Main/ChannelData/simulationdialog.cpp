#include "simulationdialog.h"
#include "ui_simulationdialog.h"

SimulationDialog::SimulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulationDialog)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
}

SimulationDialog::~SimulationDialog()
{
    delete ui;
}

void SimulationDialog::on_capturePushButton_clicked()
{

}

void SimulationDialog::on_plateCapPushButton_clicked()
{

}

void SimulationDialog::on_liftingLeverPushButton_clicked()
{

}

void SimulationDialog::on_fallRodPushButton_clicked()
{

}
