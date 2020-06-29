#ifndef SETTING_FORM_H
#define SETTING_FORM_H

#include <QWidget>
#include <QScrollArea>
#include <QMap>
#include <QDebug>

#include "channel_setting_form.h"

namespace Ui {
class Setting_Form;
}

class Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Setting_Form(QWidget *parent = nullptr);
    ~Setting_Form();

private:

    ///
    /// \brief hideWindows 隐藏窗口
    ///
    void hideWindows();

private slots:

    ///
    /// \brief initializesTheDeviceStateListSlot 初始化设备状态列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceStateListSlot(int count, QStringList rowLabels);

    ///
    /// \brief on_channel_pushButton_clicked 通道设定
    ///
    void on_channel_pushButton_clicked();

    ///
    /// \brief on_system_pushButton_clicked 系统设定
    ///
    void on_system_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::Setting_Form *ui;

    ///
    /// \brief channel_setting_from_map 通道设置窗口
    ///
    QMap<int,QObject*> channel_setting_from_map;
};

#endif // SETTING_FORM_H
