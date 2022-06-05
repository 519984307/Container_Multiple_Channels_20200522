#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QCloseEvent>

#include "Parameter/parameter.h"

namespace Ui {
class SimulationDialog;
}

class SimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationDialog(int channelNumber,QWidget *parent = nullptr);
    ~SimulationDialog();

    void closeEvent(QCloseEvent* event)Q_DECL_OVERRIDE;

private slots:
    void on_capturePushButton_clicked();

    void on_plateCapPushButton_clicked();

    void on_liftingLeverPushButton_clicked();

    void on_fallRodPushButton_clicked();

    void on_toolButton_clicked();

    void on_while_cycle_capture_checkBox_stateChanged(int arg1);

    void slot_timerCap();

    void slot_whileCap();

    void on_sendCon_pushButton_clicked();

    void on_sendPlate_pushButton_clicked();

    void on_plate_checkBox_toggled(bool checked);

    void on_container_checkBox_toggled(bool checked);

public slots:

    ///
    /// \brief slot_container 结果集
    /// \param type
    /// \param result1
    /// \param resultCheck1
    /// \param iso1
    /// \param result2
    /// \param resultCheck2
    /// \param iso2
    ///
    void slot_container(const int &channelID,const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2);

    ///
    /// \brief slot_plate 车牌结果写入主页面
    /// \param channelID
    /// \param plate
    /// \param color
    /// \param time
    ///
    void slot_plate(const int &channelID, const QString &plate, const QString &color, const QString &time, const bool &isConCar);

private:
    Ui::SimulationDialog *ui;
    QTimer *timer;

    int col;
    int channelNumber;

    QString plateTime;

    ///
    /// \brief startCap 起始抓拍状态
    ///
    bool startCap;

signals:

    ///
    /// \brief signal_setSimulationStatus 设置模拟数据，箱号和车牌状态
    /// \param con
    /// \param plate
    ///
    void signal_setSimulationStatus(bool con,bool plate);

    ///
    /// \brief signal_logicPutImage 模拟抓拍
    /// \param putCommnd
    ///
    void signal_logicPutImage(const int &putCommnd);

    ///
    /// \brief sendResultSignal 模拟发送箱号识别结果
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void sendResultSignal(int channel,const QString& result);

    ///
    /// \brief signal_plateResult 模拟发送车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    /// \param time
    ///
    void signal_plateResult(int channel, bool isConCar, const QString &plate, const QString &color, const QString &plateTime);

    /*****************************
    * @brief:车牌
    ******************************/

    ///
    /// \brief signal_simulationCapture 模拟抓拍
    ///
    void signal_simulationCapture();

    ///
    /// \brief signal_liftingElectronicRailing 抬杆/落杆
    ///
    void signal_liftingElectronicRailing(bool gate);

    ///
    /// \brief signal_transparentTransmission485 透明传输
    /// \param dmsg
    ///
    void signal_transparentTransmission485(const QString &msg);

    ///
    /// \brief signal_dialogCloseState 窗口关闭状态
    ///
    void signal_dialogCloseState();
};

#endif // SIMULATIONDIALOG_H
