#ifndef DATABASE_FORM_H
#define DATABASE_FORM_H

#include <QWidget>
#include <QEvent>
#include <QPixmap>
#include <QMouseEvent>

#include "image_dialog.h"

namespace Ui {
class DataBase_Form;
}

class DataBase_Form : public QWidget
{
    Q_OBJECT

public:
    explicit DataBase_Form(QWidget *parent = nullptr);
    ~DataBase_Form();

    ///
    /// \brief eventFilter 过滤事件
    /// \param obj
    /// \param event
    /// \return
    ///
    bool eventFilter(QObject *obj, QEvent *event);

private:

    ///
    /// \brief InitializationWindow 初始化窗口
    ///
    void InitializationWindow();

private slots:

    ///
    /// \brief on_database_imageOrData_pushButton_clicked 数据和图片界面切换
    ///
    void on_database_imageOrData_pushButton_clicked();

    ///
    /// \brief on_database_stackedWidget_currentChanged stackedWidget切换状态
    /// \param arg1
    ///
    void on_database_stackedWidget_currentChanged(int arg1);

    ///
    /// \brief image_dialog_close_slot 图片放大窗口关闭槽
    ///
    void image_dialog_close_slot();

signals:

    ///
    /// \brief set_image_dialog_pixmap_signal 设置对话框图片
    ///
    void set_image_dialog_pixmap_signal(QPixmap pix);

private:
    Ui::DataBase_Form *ui;

    ///
    /// \brief p_Image_Dialog 图片对话框
    ///
    Image_Dialog *p_Image_Dialog;
};

#endif // DATABASE_FORM_H
