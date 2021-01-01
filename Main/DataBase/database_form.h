#ifndef DATABASE_FORM_H
#define DATABASE_FORM_H

#include <QWidget>
#include <QEvent>
#include <QPixmap>
#include <QMouseEvent>
#include <QSqlTableModel>
#include <QPointer>
#include <QSharedPointer>
#include <QDir>
#include <QtConcurrent>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>

#include "image_dialog.h"
#include "filterdialog.h"
#include "Parameter/parameter.h"

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
    bool eventFilter(QObject *target, QEvent *event);

private:

    Ui::DataBase_Form *ui;

    ///
    /// \brief imgMap 图片集
    ///
    QMap<int,QString> imgMap;

    ///
    /// \brief InitializationWindow 初始化窗口
    ///
    void InitializationWindow();

    void showImgaes(const QModelIndex &index);

    enum{
        ID=0,
        Timer=1,
        Channel=2,
        Type=3,
        ContainerFront=4,
        CheckFront=5,
        ISOFront=6,
        ContainerAfter=7,
        CheckAfter=8,
        ISOAfter=9,
        ImgFront=10,
        ImgFrontCheck=11,
        ImgFrontNumber=12,
        ImgLeftFront=13,
        ImgLeftFrontCheck=14,
        ImgLeftFrontNumber=15,
        ImgRightFront=16,
        ImgRightFrontCheck=17,
        ImgRightFrontNumber=18,
        ImgLeftAfter=19,
        ImgLeftAfterCheck=20,
        ImgLeftAfterNumber=21,
        ImgRightAfter=22,
        ImgRightAfterCheck=23,
        ImgRightAfterNumber=24,
        ImgAfter=25,
        ImgAfterCheck=26,
        ImgAfterNumber=27,
        Plate=28,
        PlateTimer=29,
        PlateImg=30
    };

private slots:

    ///
    /// \brief slot_filterData 数据库筛选条件
    /// \param data
    ///
    void slot_filterData(QString data);

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
    /// \brief on_pushButton_5_clicked 查询数据库
    ///
    void on_pushButton_5_clicked();

    ///
    /// \brief on_tableView_doubleClicked 双击显示图片
    /// \param index
    ///
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_clicked(const QModelIndex &index);

signals:

    ///
    /// \brief set_image_dialog_pixmap_signal 设置对话框图片
    ///
    void set_image_dialog_pixmap_signal(QString jpg);

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
    void slot_returnModel(QSqlTableModel *ml);

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
