#ifndef CAMERA_TEST_FORM_H
#define CAMERA_TEST_FORM_H

#include <QWidget>

namespace Ui {
class Camera_Test_Form;
}

class Camera_Test_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Camera_Test_Form(QWidget *parent = nullptr);
    ~Camera_Test_Form();

private:
    Ui::Camera_Test_Form *ui;
};

#endif // CAMERA_TEST_FORM_H
