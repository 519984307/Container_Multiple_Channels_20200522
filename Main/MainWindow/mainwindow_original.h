#ifndef MAINWINDOW_ORIGINAL_H
#define MAINWINDOW_ORIGINAL_H

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
#include "ChannelData/channel_data_form.h"
#include "ChannelData/equipment_state_from.h"
#include "Setting/setting_form.h"
#include "CameraTest/camera_list_form.h"
#include "DataBase/database_form.h"
#include "Log/data_log_form.h"
#include "Log/info_log_form.h"

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

    ///
    /// \brief initializationParameter 初始化参数
    ///
    void initializationParameter();

    ///
    /// \brief hideTheWindow 隐藏窗口
    ///
    void hideTheWindow();

    ///
    /// \brief setStatusBar 设置状态栏信息
    ///
    void setStatusBar(QString msg);

    ///
    /// \brief initStatusBar 初始化状态栏
    ///
    void initStatusBar();

private:/* attribute */

    Ui::MainWindow *ui;

    ///
    /// \brief permanentWidget 状态栏永久信息
    ///
    QLabel *permanentWidget;

    ///
    /// \brief channelCount 通道数
    ///
    int channelCount;

    ///
    /// \brief channelSelect 数据界面，预览通道号
    ///
    int channelSelect;

    ///
    /// \brief channelLabels 通道名称列表
    ///
    QStringList channelLabels;

    ///
    /// \brief channelParCount 通道配置文件个数
    ///
    int channelParCount;

    ///
    /// \brief pointer_Processing 参数加载
    ///
    QSharedPointer<Processing> pointer_Processing;

    ///
    /// \brief Channel_Data_From_Map 数据窗口字典集
    ///
    QMap<int,QObject*> Channel_Data_From_Map;

    ///
    /// \brief Channel_Data_Action_Map 数据窗口工具栏字典集
    ///
    QMap<QAction*,int> Channel_Data_Action_Map;

private slots:

    ///
    /// \brief actionTiggeredSlot 工具栏按钮事件
    ///
    void actionTiggeredSlot();

    ///
    /// \brief on_actionMainWindow_triggered 显示主页面
    ///
    void on_actionMainWindow_triggered();

    ///
    /// \brief on_actionSystem_Settings_triggered 系统设置
    ///
    void on_actionSystem_Settings_triggered();

    void on_actiontest_triggered();

signals:

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
};

#endif // MAINWINDOW_ORIGINAL_H
