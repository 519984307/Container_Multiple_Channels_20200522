#include "errorform.h"
#include "ui_errorform.h"

ErrorForm::ErrorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorForm)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAutoFillBackground(true);
    int w = parent->width();
    this->setGeometry(w/2-400,25,w,30);

    /*****************************
    * @brief:设置背景色透明
    ******************************/
    QPalette palette;
    QColor color(0, 120, 215);
    color.setAlphaF(0.6);
    palette.setBrush(this->backgroundRole(), color);
    this->setPalette(palette);

    this->setVisible(true);
    this->setVisible(false);
}

ErrorForm::~ErrorForm()
{
    delete ui;
}

void ErrorForm::setTipInfo(QString info)
{
    ui->label_2->setText(info);
    this->setVisible(true);
}
