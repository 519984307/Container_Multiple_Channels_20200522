#include "filterdialog.h"
#include "ui_filterdialog.h"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setFixedSize(this->size());

    ui->start_dateTimeEdit->setDate(QDate::currentDate());
    ui->start_dateTimeEdit->setTime(QTime(0,0,0));

    ui->end_dateTimeEdit->setDate(QDate::currentDate());
    ui->end_dateTimeEdit->setTime(QTime(23,59,59));

}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Ok)){
        QStringList filterList;

        if(ui->channel_checkBox->isChecked()){
            filterList.append(QString("Channel='%1'").arg(ui->channel_spinBox->value()));
        }
        if(ui->dateTime_groupBox->isChecked()){
            //filterList.append(QString("((Timer>='%1' AND Timer<='%2') OR (PlateTimer>='%1' AND PlateTimer<='%2'))").arg(ui->start_dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss")).arg(ui->end_dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss")));
            filterList.append(QString("((Timer>='%1' AND Timer<='%2'))").arg(ui->start_dateTimeEdit->dateTime().toString("yyyy/MM/dd HH:mm:ss")).arg(ui->end_dateTimeEdit->dateTime().toString("yyyy/MM/dd HH:mm:ss")));
        }
        if(ui->logic_checkBox->isChecked()){
            if(ui->logic_comboBox->currentIndex()==3){/* 重箱 */
                filterList.append(QString("(Type='%1' OR Type='%2' OR Type='%3')").arg(0).arg(1).arg(2));
            }
            else if (ui->logic_comboBox->currentIndex()==4) {/* 空车 */
                filterList.append(QString("Type='%1'").arg(-1));
            }
            else {
                filterList.append(QString("Type='%1'").arg(ui->logic_comboBox->currentIndex()));
            }
        }
        if(ui->container_groupBox->isChecked()){
            if(ui->front_lineEdit->text()!=""){
                filterList.append(QString("ContainerFront='%1'").arg(ui->front_lineEdit->text()));
            }
            if(ui->after_lineEdit->text()!=""){
                filterList.append(QString("ContainerAfter='%1'").arg(ui->after_lineEdit->text()));
            }
        }
        if(ui->plate_checkBox->isChecked()){
            filterList.append(QString("Plate='%1'").arg(ui->plate_lineEdit->text()));
        }
        if(ui->check_checkBox->isChecked()){
            if(ui->correct_radioButton->isChecked()){
                filterList.append(QString("(CheckFront='%1' AND CheckAfter='%1'))").arg(1));
            }
            if(ui->error_radioButton->isChecked()){
                filterList.append(QString("(CheckFront='%1' OR CheckAfter='%1')").arg(0));
            }
        }

        emit signal_filterData(filterList.join(" AND "));
    }
}
