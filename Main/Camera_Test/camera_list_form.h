#ifndef CAMERA_LIST_FORM_H
#define CAMERA_LIST_FORM_H

#include <QWidget>

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
    Ui::Camera_List_Form *ui;
};

#endif // CAMERA_LIST_FORM_H
