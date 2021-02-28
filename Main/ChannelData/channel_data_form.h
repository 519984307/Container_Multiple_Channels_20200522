#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>
#include <QDir>
#include <QtConcurrent>
#include <QTimer>

#include "Parameter/channelparameter.h"
#include "Parameter/LocalPar.h"
#include "Parameter/parameter.h"

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
    /// \brief channelID 通道ID,类使用
    ///
    int channelID;

    ///
    /// \brief channelNumber 通道号
    ///
    int channelNumber;

    ///
    /// \brief signatureList 特征码列表
    ///
    QList<QString> signatureList;

    ///
    /// \brief streamMap 当前显示图片列表，供放大和重绘使用
    ///
    QMap<int,QByteArray> streamMap;

    ///
    /// \brief recogMap 识别结果集
    ///
    QMap<int,QString> recogMap;

    ///
    /// \brief imgNameMap 图片名集
    ///
    QMap<int,QString> imgNameMap;

    ///
    /// \brief imgTimer 抓拍时间戳
    ///
    QString imgTimer;

    ///
    /// \brief imgTimerAf 校对时间戳
    ///
    QString imgTimerAf;

    ///
    /// \brief mutex 写入文件锁
    ///
    QMutex mutex;

    ///
    /// \brief putCount 抓图数量
    ///
    int putCount;

    ///
    /// \brief putComType 抓拍逻辑类型
    ///
    int putComType;

    ///
    /// \brief plate 电子车牌
    ///
    QString plate;

    ///
    /// \brief plateTime 电子车牌时间戳
    ///
    QString plateTime;

    ///
    /// \brief plateColor 电子车牌颜色
    ///
    QString plateColor;

    ///
    /// \brief isConCar 判断为集装箱车辆
    ///
    bool isConCar;

    ///
    /// \brief plateStream 车牌图片流
    ///
    QMap<int,QByteArray> plateStream;

    ///
    /// \brief watcher 监视异步加载插件完成状态
    ///
    QFutureWatcher<void> *watcher;

    ///
    /// \brief LogicStateTmpList  红外临时状态，判断集装箱和车牌关系
    ///
    QVector<int> LogicStateTmpList;

    ///
    /// \brief plateSendTimer 延时发送车牌数据(判断是否集装箱车辆)
    ///
    QTimer *plateSendTimer;

    ///
    /// \brief sendDataOutTimer 超时发送接口数据
    ///
    QTimer *sendDataOutTimer;

    ///
    /// \brief clearnPixmap 清除图片
    ///
    void clearnPixmap();

    ///
    /// \brief saveImages 保存图片
    /// \param stream
    /// \param datetime 图片时间戳
    /// \return
    ///
    void saveImages(QMap<int,QByteArray> stream, QString datetime);

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

    ///
    /// \brief logicStateSlot 检测红外状态
    ///
    void logicStateSlot();

    ///
    /// \brief timeOutSendData 超时发送数据
    ///
    void timeOutSendData();

signals:

    ///
    /// \brief signal_setDeviceStatus 设置设备表状态
    /// \param channel 通道
    /// \param equipment 设备
    /// \param state 状态
    ///
    void signal_setDeviceStatus(int channel, int equipment,bool state);


    /*****************************
    * @brief:箱号相机
    ******************************/

    void signal_initCamer_front(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_before(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_left(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_right(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_top(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_prospects(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);
    void signal_initCamer_foreground(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);

    ///
    /// \brief signal_container 结果传入手动抓拍页面
    /// \param type
    /// \param result1
    /// \param resultCheck1
    /// \param iso1
    /// \param result2
    /// \param resultCheck2
    /// \param iso2
    ///
    void signal_container(const int &channelID,const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2);

    ///
    /// \brief signal_channelState 通道过车状态
    /// \param channelID
    /// \param state
    ///
    void signal_channelState(const int &channelID,const int &state);

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


    /*****************************
    * @brief:数据库插入
    ******************************/

    ///
    /// \brief signal_initDataBase 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    void signal_initDataBase(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType);

    ///
    /// \brief signal_insertDataBase 插入数据库
    /// \param data 数据字典
    ///
    void signal_insertDataBase(QMap<QString, QString> data);

    ///
    /// \brief signal_updateDataBase 更新数据
    /// \param data 数据字典
    ///
    void signal_updateDataBase(QMap<QString, QString> data);


    /*****************************
    * @brief:识别器
    ******************************/

    ///
    /// \brief signal_pictureStream 图片流
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    ///
    void signal_identifyStream(const QByteArray &jpgStream,const int &imgNumber);

    ///
    /// \brief signal_identifyImages 识别图片
    /// \param imgName  图片名
    /// \param imgNumber 图片编号
    ///
    void signal_identifyImages(const QString &imgName,const int &imgNumber);


    /*****************************
    * @brief:结果分析
    ******************************/

    ///
    /// \brief signal_initReAnaParameter 初始化参数
    /// \param channel
    /// \param ImageNamingRules
    /// \param check
    /// \param sendMid
    ///
    void signal_initReAnaParameter(const int &channel,const int &ImageNamingRules,bool check,bool sendMid);

    ///
    /// \brief signal_resultsOfAnalysis 分析箱号
    /// \param resultList 识别结果集
    /// \param type 逻辑类型
    /// \param imgList 图片名
    ///
    void signal_resultsOfAnalysis(QMap<int,QString> resultMap, int type,QMap<int,QString> imgNameMap);

    ///
    /// \brief sendResultSignal 发送识别结果
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void sendResultSignal(int channel,const QString& result);


    /*****************************
    * @brief:FTP上传图片
    ******************************/

    ///
    /// \brief signal_uploadData 上传数据
    /// \param data 数据
    ///
    void signal_uploadData(const QString &data);


    /*****************************
    * @brief:车牌相机
    ******************************/
    void signal_initCamer_plate(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature);

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
    /// \brief signal_openTheVideo 打开视频/关闭视频
    /// \param play
    ///
    void signal_openTheVideo(bool play,quint64 winID=0);

    ///
    /// \brief signal_plate 车牌结果写入主页面
    /// \param channelID
    /// \param plate
    /// \param color
    /// \param time
    ///
    void signal_plate(const int &channelID,const QString &plate,const QString &color,const QString &time);

    ///
    /// \brief signal_plateSendData 发送车牌数据
    /// \param Identify_Protocol
    /// \param isConCar
    /// \param channelNumber
    /// \param plate
    /// \param color
    /// \param time
    ///
    void signal_plateSendData(const int &Identify_Protocol,const bool &isConCar,const QString &plate,const QString &color,const QString &time);

public slots:

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


    /*****************************
    * @brief:箱号相机
    ******************************/

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


    /*****************************
    * @brief:识别器
    ******************************/

    ///
    /// \brief slot_recognitionResult 识别结果
    /// \param result 识别结果
    /// \param imgName 图片名
    /// \param imgNumber 图片编号
    ///
    void slot_recognitionResult(const QString &result,const QString& imgName,const int& imgNumber);

    /*****************************
    * @brief:结果分析
    ******************************/

    ///
    /// \brief slot_container 箱号分析结果
    /// \param result1 前箱
    /// \param resultCheck1 校验
    /// \param iso1 箱型
    /// \param result2 后箱
    /// \param resultCheck2 校验
    /// \param iso2 箱型
    ///
    void slot_container(const int& type,const QString &result1,const int& resultCheck1,const QString &iso1,const QString &result2="",const int& resultCheck2=0,const QString &iso2="");


    /*****************************
    * @brief:车牌
    ******************************/

    ///
    /// \brief slot_imageFlow 图片流
    /// \param img
    ///
    void slot_imageFlow(const QByteArray &jpgStream);

    ///
    /// \brief slot_theVideoStream 视频流
    /// \param stream
    ///
    void slot_theVideoStream(const QByteArray &arrImg);

    ///
    /// \brief slot_resultsTheLicensePlate 车牌结果
    /// \param plate
    ///
    void slot_resultsTheLicensePlate(const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg);
};

#endif // CHANNEL_DATA_FORM_H
