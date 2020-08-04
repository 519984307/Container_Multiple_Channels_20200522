#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPixmap>
#include <QCloseEvent>

namespace Ui {
class Image_Dialog;
}

class Image_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Image_Dialog(QWidget *parent = nullptr);
    ~Image_Dialog();

    void closeEvent(QCloseEvent *event);

private:
    Ui::Image_Dialog *ui;

signals:

    ///
    /// \brief image_dialog_close_signal 窗口关闭信号
    ///
    void image_dialog_close_signal();

public slots:

    ///
    /// \brief set_image_dialog_pixmap_slot 设置对话框图片
    ///
    void set_image_dialog_pixmap_slot(QPixmap pix);
};

#endif // IMAGE_DIALOG_H
