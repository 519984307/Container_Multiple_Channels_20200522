#ifndef DATABASE_FORM_H
#define DATABASE_FORM_H

#include <QWidget>
#include <QEvent>
#include <QPixmap>
#include <QMouseEvent>
#include <QSqlTableModel>
#include <QPointer>

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
    /// \brief eventFilter 动作事件
    /// \param obj
    /// \param event
    /// \return
    ///
    bool eventFilter(QObject *obj, QEvent *event);

private:

    Ui::DataBase_Form *ui;

    ///
    /// \brief p_Image_Dialog 图片对话框
    ///
    QPointer<Image_Dialog> p_Image_Dialog;

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


signals:

    ///
    /// \brief set_image_dialog_pixmap_signal 设置对话框图片
    ///
    void set_image_dialog_pixmap_signal(QPixmap pix);

    /*****************************
    * @brief:数据库读取
    ******************************/

    ///
    /// \brief signal_initDataBaseR 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    void signal_initDataBaseR(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType);

    ///
    /// \brief signal_setDataBaseFilter 设置数据库筛选条件
    /// \param filter 筛选条件
    ///
    void signal_setDataBaseFilter(const QString &filter);

public slots:

    /*****************************
    * @brief:数据库读取
    ******************************/

    ///
    /// \brief slot_returnModel 返回数据模型
    /// \param model 数据模型
    ///
    void slot_returnModel( QSqlTableModel *model);

    ///
    /// \brief slot_statisticalData
    /// \param total 总计
    /// \param correct 正确
    /// \param error 错误
    /// \param statistical 统计
    ///
    void slot_statisticalData(int total,double correct,double error,double statistical);
};

#endif // DATABASE_FORM_H
