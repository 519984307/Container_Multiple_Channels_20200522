#ifndef SETTING_FORM_H
#define SETTING_FORM_H

#include <QWidget>
#include <QMap>
#include <QCloseEvent>
#include <QMessageLogger>
#include <QSettings>
#include <QDir>
#include <QCoreApplication>

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

    void closeEvent(QCloseEvent *event)override;

private:

    /*****************************
     * func
     ******************************/

    ///
    /// \brief hideTheWindow 隐藏窗口
    ///
    void hideTheWindow();

    ///
    /// \brief automaticStartup 设置开机自动启动
    ///
    void automaticStartup(bool start);

private:

    /*****************************
    * The container
    ******************************/

    ///
    /// \brief Setting_Map 窗口类对象
    ///
    QMap<int,QObject*> Setting_Map;

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
    /// \brief on_buttonBox_clicked 保存设定
    /// \param button
    ///
    void on_buttonBox_clicked(QAbstractButton *button);

    ///
    /// \brief automaticStateSlot 获取开机启动状态
    /// \param status
    ///
    void automaticStateSlot(bool status);

    ///
    /// \brief initializesTheDeviceTemporaryTableSlot 设置页面临时添加通道设置页面
    /// \param count
    /// \param rowLabels
    ///
    void initializesTheDeviceTemporaryTableSlot(int count, QStringList rowLabels);

    ///
    /// \brief on_channel_listWidget_currentRowChanged 通道切换
    /// \param currentRow
    ///
    void on_channel_listWidget_currentRowChanged(int currentRow);

    ///
    /// \brief on_system_listWidget_currentRowChanged 系统设置列表
    /// \param currentRow
    ///
    void on_system_listWidget_currentRowChanged(int currentRow);

signals:

    ///
    /// \brief writeParameterSignal 保存设置参数
    /// \return 保存状态
    ///
    bool writeParameterSignal();

    ///
    /// \brief searchEquipmentSignal 搜索网络控制器设备
    /// \param address 地址
    /// \param port 端口
    ///
    void searchEquipmentSignal(QString address,int port);

    ///
    /// \brief setEquipmentParSignal 设置网络控制器参数
    /// \param par
    ///
    void setEquipmentParSignal(QMap<QString,QMap<QString,QString>> par);

    ///
    /// \brief sendEquipmentParSignal 发送搜索的网络控制器参数
    /// \param par
    ///
    void sendEquipmentParSignal(QMap<QString,QMap<QString,QString>> par);

    ///
    /// \brief setParSucessSignal 参数设置成功信号
    ///
    void setParSucessSignal();

    ///
    /// \brief systemCurrentRowChangedSignal 系统设置页面
    /// \param currentRow
    ///
    void systemCurrentRowChangedSignal(int currentRow);

private:

    /*****************************
     * object
     ******************************/

    Ui::Setting_Form *ui;

    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 设置界面组中,当前预览的通道号
    ///
    int channelSelect;

    ///
    /// \brief automatic 开机启动状态
    ///
    bool automatic;

    ///
    /// \brief channelSelect 通道设置选中行
    ///
    int channelListSelect;

    ///
    /// \brief systemListSelect 系统设置选中行
    ///
    int systemListSelect;
};

#endif // SETTING_FORM_H
