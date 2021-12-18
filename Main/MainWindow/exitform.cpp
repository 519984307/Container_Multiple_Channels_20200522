#include "exitform.h"
#include "ui_exitform.h"

ExitForm::ExitForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitForm)
{
    ui->setupUi(this);
}

ExitForm::~ExitForm()
{
    delete ui;
}
