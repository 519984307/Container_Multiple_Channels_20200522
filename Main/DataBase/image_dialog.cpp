#include "image_dialog.h"
#include "ui_image_dialog.h"

Image_Dialog::Image_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Image_Dialog)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
}

Image_Dialog::~Image_Dialog()
{
    delete ui;
}

void Image_Dialog::closeEvent(QCloseEvent *event)
{
    if(event->type()==QEvent::Close){
         emit image_dialog_close_signal();
    }
}

void Image_Dialog::set_image_dialog_pixmap_slot(QPixmap pix)
{
    ui->image_label->setPixmap(pix);
}
