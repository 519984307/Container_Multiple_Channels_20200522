#include "errcodeform.h"
#include "ui_errcodeform.h"

#include <QtDebug>

ErrCodeForm::ErrCodeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrCodeForm)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

ErrCodeForm::~ErrCodeForm()
{
    delete ui;
}

void ErrCodeForm::closeEvent(QCloseEvent *event)
{
    emit signal_theFormExit(this->metaObject()->className());
    event->accept();
}

bool ErrCodeForm::slot_readErrCode(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        int i=0;
        while (!file.atEnd()) {
            QString msg=file.readLine();
            QStringList lt=msg.simplified().split(" ");
            ui->tableWidget->insertRow(i);
            for (int j=0;j<lt.count();j++) {
               ui->tableWidget->setItem(i,j,new QTableWidgetItem(lt[j]));
            }
            i++;
        }
        file.close();
        return  true;
    }
    return false;
}
