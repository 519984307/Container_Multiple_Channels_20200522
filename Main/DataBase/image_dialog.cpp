#include "image_dialog.h"
#include "ui_image_dialog.h"

Image_Dialog::Image_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Image_Dialog)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setParent(parent);
    this->setVisible(false);

    ui->image_label->installEventFilter(this);
}

Image_Dialog::~Image_Dialog()
{
    delete ui;
}

bool Image_Dialog::eventFilter(QObject *target, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonDblClick){
        if(target==ui->image_label){
            this->close();
        }
    }
    return QWidget::eventFilter(target,event);
}

void Image_Dialog::set_image_dialog_pixmap_slot(QString jpg)
{
    QScopedPointer<QPixmap> labelPix(new QPixmap());
    if(labelPix->load(jpg)){
        ui->image_label->setPixmap(*labelPix.data());
    }
}
