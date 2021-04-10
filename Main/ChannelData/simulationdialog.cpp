#include "simulationdialog.h"
#include "ui_simulationdialog.h"

SimulationDialog::SimulationDialog(int channelNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulationDialog)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->layout()->setSizeConstraint( QLayout::SetFixedSize );

    ui->manualGroupBox->setVisible(false);

    timer=new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,&SimulationDialog::slot_timerCap);

    col=0;
    this->channelNumber=channelNumber;
}

SimulationDialog::~SimulationDialog()
{
    timer->stop();

    delete ui;
}

void SimulationDialog::on_capturePushButton_clicked()
{
    foreach (QLineEdit* obj, ui->groupBox->findChildren<QLineEdit*>(QString(),Qt::FindChildrenRecursively)) {
        obj->setText("");
        obj->clear();
        obj->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
    }

    switch (ui->Simulatiion_comboBox->currentIndex()) {
    case 0:
        emit signal_logicPutImage(-1);
        emit signal_logicPutImage(2);
        break;
    case 1:
        if(!timer->isActive()){
            emit signal_logicPutImage(-1);
            emit signal_logicPutImage(0);
            timer->setSingleShot(true);
            timer->start(5000);
        }
        break;
    case 2:
        emit signal_logicPutImage(-1);
        emit signal_logicPutImage(0);
        break;
    case 3:
        emit signal_logicPutImage(4);
        break;
    case 4:
        emit signal_logicPutImage(-1);
        break;
    }
}

void SimulationDialog::on_plateCapPushButton_clicked()
{
    emit signal_simulationCapture();
}

void SimulationDialog::on_liftingLeverPushButton_clicked()
{
    emit signal_liftingElectronicRailing(true);
}

void SimulationDialog::on_fallRodPushButton_clicked()
{
    //emit signal_transparentTransmission485();458传输
}

void SimulationDialog::on_toolButton_clicked()
{
    if(ui->manualGroupBox->isVisible()){
        ui->manualGroupBox->setVisible(false);
        col=0;
    }
    if(col==10){
        ui->manualGroupBox->setVisible(true);
        col=0;
    }
    col++;
}

void SimulationDialog::slot_timerCap()
{
    if(ui->while_cycle_capture_checkBox->isChecked()){
        emit signal_logicPutImage(-1);
        emit signal_logicPutImage(0);
        QTimer::singleShot(10000,this,SLOT(slot_whileCap()));
    }
    else {
        emit signal_logicPutImage(1);
    }
}

void SimulationDialog::slot_whileCap()
{
    emit signal_logicPutImage(1);
    timer->start(10000);
}

void SimulationDialog::slot_container(const int &channelID, const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2)
{
    Q_UNUSED(channelID);
    ui->con_before_lineEdit->setText(result1);
    ui->iso_before_lineEdit->setText(iso1);
    ui->con_after_lineEdit->setText(result2);
    ui->iso_after_lineEdit->setText(iso2);

    if(resultCheck1){
        ui->con_before_lineEdit->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->con_before_lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }
    if(type==2){
        if(resultCheck2){
            ui->con_after_lineEdit->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
        }
        else {
            ui->con_after_lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
        }
    }

    QString logic="";

    switch (type) {
    case -1:
        logic=tr("No container");
        break;
    case 0:
        logic=tr("A small container");
        break;
    case 1:
        logic=tr("A large container");
        break;
    case 2:
        logic=tr("Two containers");
        break;
    }
    ui->box_type_lineEdit->setText(logic);
}

void SimulationDialog::slot_plate(const int &channelID, const QString &plate, const QString &color, const QString &time)
{
    Q_UNUSED(time);
    Q_UNUSED(channelID);

    ui->plate_lineEdit->setText(plate);
    if("黄"==color){
        ui->plate_lineEdit->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(0, 0, 0);");
    }
    if("蓝"==color){
        ui->plate_lineEdit->setStyleSheet("background-color: rgb(0, 0, 255);color: rgb(255, 255, 255);");
    }
    if("无车牌"==plate){
        ui->plate_lineEdit->setStyleSheet("background-color: rgb(235, 235, 235);color: rgb(255, 0, 0);");
    }
}

void SimulationDialog::on_while_cycle_capture_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        ui->capturePushButton->setEnabled(false);
        if(timer->isActive()){
            timer->stop();
        }
        timer->start(10000);
    }
    else {
        ui->capturePushButton->setEnabled(true);
        if(timer->isActive()){
            timer->stop();
        }
    }
}

void SimulationDialog::on_pushButton_clicked()
{
    QString time=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    if(ui->send_con_after_lineEdit->text().isEmpty()){
        int type=0;
        if("45G1"==ui->send_iso_after_lineEdit->text().trimmed()){
            type=1;
        }
        /* 识别结果写入日志,[标志|时间戳|通道号(2位)|逻辑|箱号|校验|箱号|校验|箱型|箱型] */
        QString result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("C").arg(time).arg(channelNumber,2,10,QLatin1Char('0')).arg(type).arg(ui->send_con_before_lineEdit->text()).arg("Y").arg(ui->send_iso_before_lineEdit->text().trimmed());
        emit sendResultSignal(channelNumber,result);
    }
    else {
        /* 识别结果写入日志,[标志|时间戳|通道号(2位)|逻辑|箱号|校验|箱型]*/
        int type=2;
        QString result=QString("[%1|%2|%3|%4|%5|%6|%7|%8|%9|%10]").arg("C").arg(time).arg(channelNumber,2,10,QLatin1Char('0')).arg(type).arg(ui->send_con_before_lineEdit->text().trimmed()).arg("Y").arg(ui->send_con_after_lineEdit->text().trimmed()).arg("Y").arg(ui->send_iso_before_lineEdit->text().trimmed()).arg(ui->send_iso_after_lineEdit->text().trimmed());
        emit sendResultSignal(channelNumber,result);
    }
}
