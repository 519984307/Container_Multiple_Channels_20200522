#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>

#include "./Parameter/channelparameter.h"
#include "Parameter/LocalPar.h"

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
    /// \param channelID 通道ID
    /// \param para 通道参数
    ///
    void loadParamter(int channelID, ChannelParameter* para);

private:
    Ui::Channel_Data_Form *ui;    

    ///
    /// \brief para 通道参数
    ///
    ChannelParameter *para;

    ///
    /// \brief channelID 通道ID
    ///
    int channelID;

    QList<QString> signatureList;

signals:

    ///
    /// \brief signal_enlargeImages 放大图片
    /// \param arry
    ///
    void signal_enlargeImages(QByteArray arry);

    ///
    /// \brief signal_pictureStream 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void signal_pictureStream(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");


    ///
    /// \brief signal_getCameraState 相机状态
    /// \param channelID 通道ID
    /// \param cameraID 相机ID
    ///
    void signal_getCameraState(int channelID,int cameraID);

    void signal_initCamer_front(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_before(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_left(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_right(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_top(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_prospects(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_foreground(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);

    ///
    /// \brief signal_putCommand 抓取图片
    /// \param command 图片编号
    /// \param imgTime 时间戳
    /// \param signature 特征码
    ///
    bool signal_putCommand( int imgNumber, QString imgTime,const QString &signature);

    ///
    /// \brief signal_playStream 预览实时视频
    /// \param winID 窗口句柄
    /// \param play 播放状态
    /// \param signature 特征码
    /// 海康相机：多次实时预览,linux出现内存不释放
    ///
    void signal_playStream(quint64 winID,bool play,const QString &signature);


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

    ///
    /// \brief slot_captureTest 相机测试抓拍
    /// \param channelID 通道ID
    /// \param cameraID 相机ID
    ///
    void slot_captureTest(int channelID,int cameraID);

    ///
    /// \brief slot_playStream 预览实时视频
    /// \param winID 窗口句柄
    /// \param play 播放状态
    /// \param channelID 通道号
    /// \param cameraID 相机ID
    /// 海康相机：多次实时预览,linux出现内存不释放
    ///
    void slot_playStream(quint64 winID,bool play,int channelID,int cameraID);
};

#endif // CHANNEL_DATA_FORM_H
