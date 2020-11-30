#include "imagedialog.h"
#include "ui_imagedialog.h"

#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
}

ImageDialog::~ImageDialog()
{
    delete ui;
}

void ImageDialog::slot_enlargeImages(QByteArray arry)
{
    imgArr=arry;
    QPixmap pix(arry);
    ui->label->setPixmap(pix);
}

void ImageDialog::on_savePushButton_clicked()
{
    QString file=QFileDialog::getSaveFileName(this,tr("Save Image"),QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF");
    if(!file.isEmpty()){
        QPixmap pix(imgArr);
        if(pix.save(file)){
            QMessageBox::information(this,tr("Error"),tr("Failed to save image"));
        }
    }
}
