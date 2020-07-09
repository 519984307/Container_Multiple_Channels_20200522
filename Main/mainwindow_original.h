#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QResizeEvent>
#include <QMap>
#include <QAction>
#include <QLabel>

/* UI */
#include "Channel_Data/channel_data_form.h"
#include "Channel_Data/equipment_state_from.h"
#include "Setting/setting_form.h"

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

    ///
    /// \brief initializationParameter 初始化参数
    ///
    void initializationParameter();

    ///
    /// \brief initializesTheDataWindow 初始化数据窗口
    ///
    void initializesTheDataWindow();

    ///
    /// \brief clearnMap 清除字典集
    ///
    void clearnMap();

    ///
    /// \brief hideTheWindow 隐藏窗口
    ///
    void hideTheWindow();

    ///
    /// \brief setStatusBar 设置状态栏信息
    ///
    void setStatusBar(QString msg);

    ///
    /// \brief initializingAttribute 初始化属性
    ///
    void initializingAttribute();

    ///
    /// \brief mainWindow 主界面窗口信号与槽
    ///
    void mainWindowConnect();

    ///
    /// \brief initStatusBar 初始化状态栏
    ///
    void initStatusBar();

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

private:/* attribute */

    //Channel_Data_Form *pFrom=nullptr;

    Ui::MainWindow *ui;

    ///
    /// \brief p_Equipment_State_From 设备状态窗口
    ///
    Equipment_State_From *p_Equipment_State_From=nullptr;

    ///
    /// \brief p_Setting_From 设置窗口
    ///
    Setting_Form *p_Setting_From=nullptr;

    ///
    /// \brief permanentWidget 状态栏永久信息
    ///
    QLabel *permanentWidget=nullptr;

    ///
    /// \brief channelCount 通道数
    ///
    int channelCount=1;

    ///
    /// \brief channelLabels 通道名称列表
    ///
    QStringList channelLabels;

private:    /* QMap */

    ///
    /// \brief WindowsVector 窗口集
    ///
    QVector<QObject*> WindowsVector;

    ///
    /// \brief Channel_Data_From_Map 数据窗口字典集
    ///
    QMap<int,QObject*> Channel_Data_From_Map;

    ///
    /// \brief Channel_Data_Action_Map 数据窗口工具栏字典集
    ///
    QMap<QAction*,QObject*> Channel_Data_Action_Map;

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

#endif // MAINWINDOW_H
