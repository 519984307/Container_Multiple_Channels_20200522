#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QDateTime>

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

    ///
    /// \brief signatureList 特征码列表
    ///
    QList<QString> signatureList;

    ///
    /// \brief streamMap 当前显示图片列表，供放大和重绘使用
    ///
    QMap<int,QByteArray> streamMap;

    ///
    /// \brief imgTimer 抓拍时间戳
    ///
    QString imgTimer;

    ///
    /// \brief clearnPixmap 清除图片
    ///
    void clearnPixmap();

private slots:

    ///
    /// \brief on_SimulationPushButton_clicked 模拟抓拍
    ///
    void on_SimulationPushButton_clicked();

    ///
    /// \brief slot_pictureStream 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void slot_pictureStream(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");

signals:

    void signal_initCamer_front(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_before(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_left(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_right(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_top(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_prospects(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_foreground(const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);

    /*****************************
    * @brief:箱号相机
    ******************************/

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


    /*****************************
    * @brief:红外
    ******************************/

    ///
    /// \brief signal_startSlave 初始化串口
    /// \param portName1 串口1
    /// \param portName2 串口2
    /// \param channelNum 通道号
    ///
    void signal_startSlave(const QString &portName1, const QString &portName2,int channelNum);

    ///
    /// \brief signal_simulateTrigger 模拟触发
    /// \param type 逻辑类型
    /// type=1 22G1
    /// type=2 45G1
    /// type=3 Double 22G1_F
    /// type=4 Double 22G1_b
    /// type=5 while
    ///
    void signal_simulateTrigger(int type);

    ///
    /// \brief signal_setAlarmMode 设置红外模式
    /// \param mode 模式(敞开|常闭)
    ///
    void signal_setAlarmMode(bool model);

public slots:

    /*****************************
    * @brief:箱号相机
    ******************************/

    ///
    /// \brief camerStateSingals 相机连接状态信号
    /// \param camerIP 相机地址
    /// \param state 相机连接状态
    ///
    void slot_camerState(const QString &camerIP,bool state);

    ///
    /// \brief slot_initEquipment 初始化相机
    ///
    void slot_initEquipment();

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


    /*****************************
    * @brief:红外
    ******************************/

    ///
    /// \brief slot_logicStatus 红外信号状态
    /// \param status 状态码
    ///
    void slot_logicStatus(int* status);

     ///
     /// \brief slot_logicPutImage 逻辑抓图
     /// \param putCommnd 逻辑
     ///
     void slot_logicPutImage(const int &putCommnd);

     ///
     /// \brief slot_serialPortState 串口状态
     /// \param com1
     /// \param com2
     ///
     void slot_serialPortState(bool com1,bool com2);
};

#endif // CHANNEL_DATA_FORM_H
