#ifndef EQUIPMENT_STATE_FROM_H
#define EQUIPMENT_STATE_FROM_H

#include <QWidget>
#include <QDebug>
#include <QTableWidgetItem>

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

    enum equipment{
        B_C=0,             /* 前相机 */
        A_C=1,             /* 后相机 */
        L_C=2,             /* 左相机 */
        R_C=3,             /* 右相机 */
        T_C=4,             /* 顶相机 */
        P_C=5,             /* 车牌相机 */
        A1=6,              /*  红外A1 */
        A2=7,              /*  红外A2 */
        B1=8,              /*  红外B1 */
        B2=9,              /*  红外B2 */
        D1=10,            /*  红外D1 */
        D2=11,            /*  红外D2 */
        R_F=12,           /*  前箱号 */
        R_A=13,           /*  后箱号 */
        PLATE=14,       /*  车牌 */
        MSG=15          /*  日志信息 */
    };

    //Q_ENUM(equipment)

public slots:

    ///
    /// \brief initializesTheDeviceStateListSlot 初始化设备状态列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceStateListSlot(uint count,QStringList rowLabels);

    ///
    /// \brief setDeviceStatusSlot 设置设备表
    /// \param equipment
    ///
    void setDeviceStatusSlot(uint channel, int equipment,QString state);
};

#endif // EQUIPMENT_STATE_FROM_H
