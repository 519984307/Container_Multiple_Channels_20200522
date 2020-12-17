#include "alarmform.h"
#include "ui_alarmform.h"

AlarmForm::AlarmForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmForm)
{
    ui->setupUi(this);
    this->setParent(parent);

    ui->toolButton->setStyleSheet("color: rgb(255, 0, 0);");
    ui->toolButton->setEnabled(false);
}

AlarmForm::~AlarmForm()
{
    delete ui;
}

void AlarmForm::slot_setAlarmMsg(int num, QString msg)
{
    ui->toolButton->setEnabled(true);

    ui->toolButton->setText(QString::number(num));
    msgList.append(msg);
}

void AlarmForm::on_toolButton_clicked()
{
#ifdef Q_OS_LINUX
    QString eol = "\n";
#endif
#ifdef Q_OS_WIN
    QString eol = "\r\n";
#endif
    QString tmp="";
    for (int var = 0; var < msgList.size(); ++var) {
        tmp.append(QString::number(var+1)+")"+msgList.at(var)+eol);
    }
    QMessageBox::critical(this,"A fatal error",tmp);
}
