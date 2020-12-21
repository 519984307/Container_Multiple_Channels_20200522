#ifndef CAMERA_LIST_FORM_H
#define CAMERA_LIST_FORM_H

#include <QWidget>
#include <QMap>
#include <QPointer>
#include <QTreeWidgetItemIterator>
#include <QMessageBox>
#include <QCloseEvent>

#include "CameraTest/camera_test_form.h"
#include "Parameter/LocalPar.h"

namespace Ui {
class Camera_List_Form;
}

class Camera_List_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Camera_List_Form(QWidget *parent = nullptr);
    ~Camera_List_Form();

    void closeEvent(QCloseEvent *event) override;

private:

    /*****************************
     * func
     ******************************/

    ///
    /// \brief initializingObject 初始化对象
    ///
    void initializingObject();

    Ui::Camera_List_Form *ui;

    ///
    /// \brief CamerNameList  相机列表
    ///
    QStringList CamerNameList;

    QTreeWidgetItem *tmpItem;

    QPointer<Camera_Test_Form> p_Camera_Test_Form;

    QMap<QTreeWidgetItem*,int> ItemMap;

    bool play;

    quint64 winID;

private slots:

    /*****************************
     *  slot
     ******************************/

    ///
    /// \brief initializesTheDeviceListSlot 初始化设备列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceListSlot(int count, QStringList rowLabels);

    void on_CameraList_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_CameraList_itemClicked(QTreeWidgetItem *item, int column);

    ///
    /// \brief slot_capture 抓取图片
    ///
    void slot_capture();

    ///
    /// \brief slot_play 播放视频
    ///
    void slot_play(quint64 winID);

public slots:

    ///
    /// \brief slot_getCameraState 相机状态
    /// \param channelID 通道ID
    /// \param cameraID 相机ID
    ///
    void slot_getCameraState(int channelID,int cameraID);

signals:

    ///
    /// \brief signal_captureTest 相机测试抓拍
    /// \param channelID 通道ID
    /// \param cameraID 相机ID
    ///
    void signal_captureTest(int channelID,int cameraID);

    ///
    /// \brief signal_pictureStream 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void signal_pictureStream(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");

    ///
    /// \brief signal_playStream 预览实时视频
    /// \param winID 窗口句柄
    /// \param play 播放状态
    /// \param signature 特征码
    /// 海康相机：多次实时预览,linux出现内存不释放
    ///
    void signal_playStream(quint64 winID,bool play,int channelID,int cameraID);
};

#endif // CAMERA_LIST_FORM_H
