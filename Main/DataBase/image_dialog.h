#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Image_Dialog;
}

class Image_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Image_Dialog(QWidget *parent = nullptr);
    ~Image_Dialog();

    ///
    /// \brief eventFilter 动作事件
    /// \param obj
    /// \param event
    /// \return
    ///
    bool eventFilter(QObject *target, QEvent *event);

private:
    Ui::Image_Dialog *ui;


public slots:

    ///
    /// \brief set_image_dialog_pixmap_slot 设置对话框图片
    ///
    void set_image_dialog_pixmap_slot(QString jpg);
};

#endif // IMAGE_DIALOG_H
