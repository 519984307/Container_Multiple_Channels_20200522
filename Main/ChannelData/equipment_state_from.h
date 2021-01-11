#ifndef EQUIPMENT_STATE_FROM_H
#define EQUIPMENT_STATE_FROM_H

#include <QWidget>
#include <QDebug>
#include <QTableWidgetItem>

#include "Parameter/LocalPar.h"

namespace Ui {
class Equipment_State_From;
}

class Equipment_State_From : public QWidget
{
    Q_OBJECT

public:
    explicit Equipment_State_From(QWidget *parent = nullptr);
    ~Equipment_State_From();

private:
    Ui::Equipment_State_From *ui; 

public slots:

    ///
    /// \brief initializesTheDeviceStateListSlot 初始化设备状态列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceStateListSlot(int count,QStringList rowLabels);

    ///
    /// \brief setDeviceStatusSlot 设置设备表状态
    /// \param channel 通道
    /// \param equipment 设备
    /// \param state 状态
    ///
    void setDeviceStatusSlot(int channel, int equipment,bool state);
};

#endif // EQUIPMENT_STATE_FROM_H
