#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QResizeEvent>
#include <QDesktopWidget>
#include <QMap>
#include <QAction>
#include <QLabel>
#include <QScreen>

/*****************************
* UI
******************************/
#include "Channel_Data/channel_data_form.h"
#include "Channel_Data/equipment_state_from.h"
#include "Setting/setting_form.h"
#include "Camera_Test/camera_list_form.h"
#include "DataBase/database_form.h"
#include "Log/communication_logs_form.h"
#include "Log/operational_log_form.h"
#include "Log/identify_the_log_form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()Q_DECL_OVERRIDE;

private:

    /*****************************
    * func
    ******************************/

    ///
    /// \brief removeTheWindow 显示窗口之前要删除其他窗口
    ///
    void removeTheWindow();

    ///
    /// \brief initializingObject 初始化对象
    ///
    void initializingObject();

    ///
    /// \brief initializationParameter 初始化参数
    ///
    void initializationParameter();

    ///
    /// \brief clearnMap 清除容器
    ///
    void clearnContainer();

    ///
    /// \brief setStatusBar 设置状态栏信息
    ///
    void setStatusBar(const QString &msg);

    ///
    /// \brief mainWindow 主窗口信号与槽
    ///
    void mainConnect();

    ///
    /// \brief formConnet 子窗口信号与槽
    ///
    void formConnet();

    ///
    /// \brief initStatusBar 初始化状态栏
    ///
    void initStatusBar();

    ///
    /// \brief getScreenInfo 获取和设置系统屏幕大小
    ///
    void getScreenInfo();

private slots:

    /*****************************
    * triggerd
    ******************************/

    ///
    /// \brief actionTiggeredSlot 工具栏按钮事件
    ///
    void actionTiggeredSlot();

    ///
    /// \brief on_actionMainWindow_triggered 显示主页面
    ///
    void on_actionMainWindow_triggered();

    ///
    /// \brief on_actionParameter_Settings_triggered 系统参数设置
    ///
    void on_actionParameter_Settings_triggered();

    ///
    /// \brief on_actionCamera_Test_triggered 相机调试
    ///
    void on_actionCamera_Test_triggered();

    ///
    /// \brief on_actionHistory_Sqlite_triggered 查找历史记录
    ///
    void on_actionHistory_Sqlite_triggered();

    ///
    /// \brief on_actionOperational_log_triggered 系统运维日志
    ///
    void on_actionOperational_log_triggered();

    ///
    /// \brief on_actioncommunication_triggered 数据通讯日志
    ///
    void on_actionCommunication_log_triggered();

    ///
    /// \brief on_actionIdentify_the_log_triggered 识别日志
    ///
    void on_actionIdentify_the_log_triggered();

signals:

    /*****************************
    * signal
    ******************************/

    ///
    /// \brief initializesTheDeviceStateListSignal 初始化设备状态列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceStateListSignal(int count,QStringList rowLabels);

    ///
    /// \brief setDeviceStatusSignal 设置设备表状态
    /// \param channel 通道
    /// \param equipment 设备
    /// \param state 状态
    ///
    void setDeviceStatusSignal(int channel, int equipment,bool state);

private:

    /*****************************
    * container
    ******************************/

    ///
    /// \brief Channel_Data_Action_Map 数据窗口工具栏字典集
    ///
    QMap<QAction*,int> Channel_Data_Action_Map;

    ///
    /// \brief Form_Map 窗口类对象合集
    ///
    QList<QObject*> Form_Map;

    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 数据界面组中,当前预览的通道号
    ///
    int channelSelect;

    ///
    /// \brief channelCount 通道数
    ///
    int channelCount=1;

    ///
    /// \brief channelLabels 通道名称列表
    ///
    QStringList channelLabels;

    /*****************************
    * object
    ******************************/

    Ui::MainWindow *ui;

    ///
    /// \brief pFrom 数据窗口
    ///
    Channel_Data_Form *p_Channel_Data_Form=nullptr;

    ///
    /// \brief p_Equipment_State_Form 设备列表窗口
    ///
    Equipment_State_From *p_Equipment_State_Form=nullptr;

    ///
    /// \brief p_Setting_Form 设置窗口
    ///
    Setting_Form *p_Setting_Form=nullptr;

    ///
    /// \brief p_Camera_List_Form 相机窗口
    ///
    Camera_List_Form *p_Camera_List_Form=nullptr;

    ///
    /// \brief p_DataBase_Form 数据库窗口
    ///
    DataBase_Form *p_DataBase_Form=nullptr;

    ///
    /// \brief permanentWidget 状态栏永久信息
    ///
    QLabel *permanentWidget=nullptr;

    ///
    /// \brief p_Communication_Logs_Form 通信日志窗口
    ///
    Communication_Logs_Form *p_Communication_Logs_Form=nullptr;

    ///
    /// \brief p_Operational_Log_Form 运维日志窗口
    ///
    Operational_Log_Form *p_Operational_Log_Form=nullptr;

    ///
    /// \brief p_Identify_The_Log_Form 识别器日志窗口
    ///
    Identify_The_Log_Form *p_Identify_The_Log_Form=nullptr;
};

#endif // MAINWINDOW_H
