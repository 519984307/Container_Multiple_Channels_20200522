#ifndef SETTING_FORM_H
#define SETTING_FORM_H

#include <QWidget>
#include <QMap>
#include <QShowEvent>
#include <QDebug>

#include "channel_setting_form.h"
#include "system_setting_form.h"

namespace Ui {
class Setting_Form;
}

class Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Setting_Form(QWidget *parent = nullptr);
    ~Setting_Form();

    void showEvent(QShowEvent *event);

private:

    /*****************************
     * func
     ******************************/

    ///
    /// \brief removeTheWindow 隐藏窗口
    ///
    void removeTheWindow();

    ///
    /// \brief initializingObject 初始化对象
    ///
    void initializingObject();

private:

    /*****************************
    * The container
    ******************************/

    ///
    /// \brief From_Map 窗口类对象合集
    ///
    QList<QObject*> From_Map;

private slots:

    /*****************************
     *  slot
     ******************************/

    ///
    /// \brief initializesTheDeviceListSlot 初始化设备列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceListSlot(int count, QStringList rowLabels);

    ///
    /// \brief on_channel_pushButton_clicked 通道设定
    ///
    void on_channel_pushButton_clicked();

    ///
    /// \brief on_system_pushButton_clicked 系统设定
    ///
    void on_system_pushButton_clicked();

    ///
    /// \brief on_listWidget_currentRowChanged 通道切换
    /// \param currentRow
    ///
    void on_listWidget_currentRowChanged(int currentRow);

private:

    /*****************************
     * object
     ******************************/

    Ui::Setting_Form *ui;

    ///
    /// \brief p_System_Setting_From 系统设置窗口
    ///
    System_Setting_Form *p_System_Setting_From=nullptr;

    ///
    /// \brief p_Channel_Setting_From 通道设置窗口
    ///
    Channel_Setting_Form *p_Channel_Setting_From=nullptr;


    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 设置界面组中,当前预览的通道号
    ///
    int channelSelect;
};

#endif // SETTING_FORM_H
