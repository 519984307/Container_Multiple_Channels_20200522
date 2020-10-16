#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageLogger>
#include <QtGlobal>
#include <QResizeEvent>
#include <QDesktopWidget>
#include <QMap>
#include <QAction>
#include <QLabel>
#include <QScreen>
#include <QScopedPointer>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QCloseEvent>

/*****************************
* UI
******************************/
#include "Channel_Data/channel_data_form.h"
#include "Channel_Data/equipment_state_from.h"
#include "Setting/setting_form.h"
#include "Camera_Test/camera_list_form.h"
#include "DataBase/database_form.h"
#include "LogForm/data_log_form.h"
#include "LogForm/info_log_form.h"


#include "Parameter/processing.h"
#include "Parameter/parameter.h"
#include "Parameter/LocalPar.h"

#include "Processing/loadinglibaray.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()Q_DECL_OVERRIDE;

protected:
    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;

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

    ///
    /// \brief createSystemTrayMenu 设置任务栏菜单
    ///
    void createSystemTrayMenu();

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
    /// \brief on_actionInfo_log_triggered 系统日志
    ///
    void on_actionInfo_log_triggered();

    ///
    /// \brief on_actionData_log_triggered 数据通讯日志
    ///
    void on_actionData_log_triggered();

    ///
    /// \brief systemTrayAction 任务栏菜单
    ///
    void systemTrayAction();

    ///
    /// \brief systemTrayTriggered 任务栏点击事件
    ///
    void systemTrayTriggered(QSystemTrayIcon::ActivationReason reason);

public slots:

    ///
    /// \brief showMainWindowSlot 显示主页面
    ///
    void showMainWindowSlot();


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
    int channelCount;

    ///
    /// \brief channelLabels 通道名称列表
    ///
    QStringList channelLabels;

    ///
    /// \brief pointerCount 通道配置文件个数
    ///
    int pointerCount;

    /*****************************
    * object
    ******************************/

    Ui::MainWindow *ui;

    ///
    /// \brief actionShow 任务栏显示主页面
    ///
    QAction* actionShow;

    ///
    /// \brief actionExit 任务栏退出
    ///
    QAction* actionExit;

    ///
    /// \brief Pointer_Processing 参数加载
    ///
    QSharedPointer<Processing> Pointer_Processing;

    ///
    /// \brief SystemTray 任务栏
    ///
    QPointer<QSystemTrayIcon> SystemTray;

    ///
    /// \brief pLoadingLibaray 加载插件
    ///
    LoadingLibaray *pLoadingLibaray;

    /*****************************
    * @brief:UI
    ******************************/

    ///
    /// \brief pFrom 数据窗口
    ///
    Channel_Data_Form *p_Channel_Data_Form;

    ///
    /// \brief p_Equipment_State_Form 设备列表窗口
    ///
    Equipment_State_From *p_Equipment_State_Form;

    ///
    /// \brief p_Setting_Form 设置窗口
    ///
    Setting_Form *p_Setting_Form;

    ///
    /// \brief p_Camera_List_Form 相机窗口
    ///
    Camera_List_Form *p_Camera_List_Form;

    ///
    /// \brief p_DataBase_Form 数据库窗口
    ///
    DataBase_Form *p_DataBase_Form;

    ///
    /// \brief p_Data_Log_Form TCP数据流窗口
    ///
    Data_Log_Form *p_Data_Log_Form;

    ///
    /// \brief p_Info_Log_Form 运行日志窗口
    ///
    Info_Log_Form *p_Info_Log_Form;

    ///
    /// \brief permanentWidget 状态栏永久信息
    ///
    QLabel *permanentWidget;
};

#endif // MAINWINDOW_H
