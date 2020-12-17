#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>

#include "./Parameter/channelparameter.h"

namespace Ui {
class Channel_Data_Form;
}

class Channel_Data_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Channel_Data_Form(QString alias,int channelNumber,QWidget *parent = nullptr);
    ~Channel_Data_Form();

    void paintEvent(QPaintEvent *event)override;
    bool eventFilter(QObject *target,QEvent *event) override;    

    ///
    /// \brief slot_loadParamter 读取通道参数
    /// \param para
    ///
    void loadParamter(ChannelParameter* para);

private:
    Ui::Channel_Data_Form *ui;    

    ///
    /// \brief para 通道参数
    ///
    ChannelParameter *para;

signals:

    ///
    /// \brief signal_enlargeImages 放大图片
    /// \param arry
    ///
    void signal_enlargeImages(QByteArray arry);

    void signal_initCamer_front(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_before(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_left(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_right(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_top(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_prospects(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);
    void signal_initCamer_foreground(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow);

private slots:

    void on_SimulationPushButton_clicked();

public slots:

    ///
    /// \brief camerStateSingals 相机连接状态信号
    /// \param camerIP 相机地址
    /// \param state 相机连接状态
    ///
    void slot_camerState(const QString &camerIP,bool state);

    ///
    /// \brief slot_initCamera 初始化相机
    ///
    void slot_initCamera();

    ///
    /// \brief slot_bindingCameraID 绑定相机地址和ID号
    /// \param cameraAddr
    /// \param ID
    ///
    void slot_bindingCameraID(QString cameraAddr,int ID);
};

#endif // CHANNEL_DATA_FORM_H
