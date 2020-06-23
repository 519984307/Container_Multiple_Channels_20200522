#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QResizeEvent>
#include <QMap>
#include <QAction>

/* UI */
#include "Channel_Data/channel_data_form.h"

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

private slots:

    ///
    /// \brief actionTiggeredSlot 工具栏按钮事件
    ///
    void actionTiggeredSlot();

private:

    Ui::MainWindow *ui;

    ///
    /// \brief channelCount 通道数
    ///
    uint channelCount;

    /* QMap */
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
