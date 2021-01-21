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

    ///
    /// \brief isInitload 初始化加载设备状态
    ///
    bool isInitload;

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

    ///
    /// \brief slot_container 箱号分析结果,写入主页面状态
    /// \param result1 前箱
    /// \param resultCheck1 校验
    /// \param iso1 箱型
    /// \param result2 后箱
    /// \param resultCheck2 校验
    /// \param iso2 箱型
    ///
    void slot_container(const int &channelID,const int& type,const QString &result1,const int& resultCheck1,const QString &iso1,const QString &result2="",const int& resultCheck2=0,const QString &iso2="");

    ///
    /// \brief signal_channelState 通道过车状态
    /// \param channelID
    /// \param state
    ///
    void slot_channelState(const int &channelID,const int &state);
};

#endif // EQUIPMENT_STATE_FROM_H
