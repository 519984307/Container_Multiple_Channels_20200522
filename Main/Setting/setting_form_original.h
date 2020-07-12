#ifndef SETTING_FORM_H
#define SETTING_FORM_H

#include <QWidget>
#include <QScrollArea>
#include <QMap>
#include <QShowEvent>
#include <QHideEvent>
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

    ///
    /// \brief hideWindows 隐藏窗口
    ///
    void hideWindows();

private slots:

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
    Ui::Setting_Form *ui;

    ///
    /// \brief p_System_Setting_From 系统设置窗口
    ///
    System_Setting_Form *p_System_Setting_From=nullptr;

    ///
    /// \brief WindowsVector 窗口集
    ///
    QVector<QObject*> WindowsVector;

    ///
    /// \brief channel_setting_from_map 通道设置窗口
    ///
    QMap<int,QObject*> channel_setting_from_map;
};

#endif // SETTING_FORM_H
