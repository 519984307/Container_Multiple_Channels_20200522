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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()Q_DECL_OVERRIDE;

    void resizeEvent(QResizeEvent *szie)Q_DECL_OVERRIDE;

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
    void setStatusBar();

    ///
    /// \brief initializingAttribute 初始化属性
    ///
    void initializingAttribute();

    ///
    /// \brief mainWindow 主界面窗口
    ///
    void mainWindow();

private slots:

    ///
    /// \brief actionTiggeredSlot 工具栏按钮事件
    ///
    void actionTiggeredSlot();

private:/* attribute */

    Ui::MainWindow *ui;

    ///
    /// \brief p_Equipment_State_From 设备状态界面
    ///
    Equipment_State_From *p_Equipment_State_From;

    ///
    /// \brief permanentWidget 状态栏永久信息
    ///
    QLabel *permanentWidget;

    ///
    /// \brief channelCount 通道数
    ///
    uint channelCount;

private:    /* QMap */

    ///
    /// \brief WindowsVector 窗口集
    ///
    QVector<QObject*> WindowsVector;

    ///
    /// \brief Channel_Data_From_Map 数据窗口字典集
    ///
    QMap<uint,QObject*> Channel_Data_From_Map;

    ///
    /// \brief Channel_Data_Action_Map 数据窗口工具栏字典集
    ///
    QMap<QAction*,QObject*> Channel_Data_Action_Map;

};

#endif // MAINWINDOW_H
