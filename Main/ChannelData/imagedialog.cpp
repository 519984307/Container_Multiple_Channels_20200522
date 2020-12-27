﻿#include "imagedialog.h"
#include "ui_imagedialog.h"

#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QGuiApplication>
#include<QScreen>

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    imgArr=nullptr;

    //QRect screenRect =QGuiApplication::screens().at(0)->geometry();
    this->setWindowState(Qt::WindowMaximized);
    //resize(screenRect.width(),screenRect.height()-100);

    ui->label->installEventFilter(this);
}

ImageDialog::~ImageDialog()
{
    delete ui;
}

bool ImageDialog::eventFilter(QObject *target, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonDblClick){
        if(target==ui->label){
            this->close();
        }
    }
    return  QWidget::eventFilter(target,event);
}

void ImageDialog::slot_enlargeImages(QByteArray arry)
{   
    if(nullptr != arry){
        imgArr=arry;
        QSharedPointer<QPixmap> pix(new QPixmap());
        pix->loadFromData(arry);
        ui->label->setPixmap(*pix);
    }
}

void ImageDialog::on_savePushButton_clicked()
{
    QString file=QFileDialog::getSaveFileName(this,tr("Save Image"),QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF");
    if(!file.isEmpty()){
        if(nullptr != imgArr){
            QSharedPointer<QPixmap> pix(new QPixmap());
            pix->loadFromData(imgArr);
            if(pix->save(file)){
                QMessageBox::information(this,tr("Info"),tr("Save picture Chen successfully"));
            }
        }
        else {
            QMessageBox::information(this,tr("Error"),tr("Save image does not exist"));
        }
    }
}
