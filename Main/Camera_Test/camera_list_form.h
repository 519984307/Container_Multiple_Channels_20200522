#ifndef CAMERA_LIST_FORM_H
#define CAMERA_LIST_FORM_H

#include <QWidget>
#include <QDebug>
#include <QModelIndex>

#include "Camera_Test/camera_test_form.h"

namespace Ui {
class Camera_List_Form;
}

class Camera_List_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Camera_List_Form(QWidget *parent = nullptr);
    ~Camera_List_Form();

private:

    /*****************************
     * func
     ******************************/

    ///
    /// \brief initializingObject 初始化对象
    ///
    void initializingObject();

    ///
    /// \brief removeTheWindow 删除窗口
    ///
    void removeTheWindow();

private:
    Ui::Camera_List_Form *ui;

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

    ///
    /// \brief on_CameraList_clicked 数据项切换
    /// \param index
    ///
    void on_CameraList_clicked(const QModelIndex &index);

private:

    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 设置界面组中,当前预览的通道号
    ///
    int channelSelect;

    ///
    /// \brief CamerNameList  相机列表
    ///
    QStringList CamerNameList;

    /*****************************
     * object
     ******************************/

    ///
    /// \brief p_Camera_Test_Form 相机预览窗口
    ///
    Camera_Test_Form* p_Camera_Test_Form=nullptr;
};

#endif // CAMERA_LIST_FORM_H
