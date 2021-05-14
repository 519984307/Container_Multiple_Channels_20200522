/********************************************************************************
** Form generated from reading UI file 'camera_test_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_TEST_FORM_H
#define UI_CAMERA_TEST_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera_Test_Form
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *capture_pushButton;
    QPushButton *identify_pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *result_lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *play_pushButton;
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *Camera_Test_Form)
    {
        if (Camera_Test_Form->objectName().isEmpty())
            Camera_Test_Form->setObjectName(QString::fromUtf8("Camera_Test_Form"));
        Camera_Test_Form->resize(712, 391);
        gridLayout_2 = new QGridLayout(Camera_Test_Form);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        capture_pushButton = new QPushButton(Camera_Test_Form);
        capture_pushButton->setObjectName(QString::fromUtf8("capture_pushButton"));

        gridLayout_2->addWidget(capture_pushButton, 0, 0, 1, 1);

        identify_pushButton = new QPushButton(Camera_Test_Form);
        identify_pushButton->setObjectName(QString::fromUtf8("identify_pushButton"));

        gridLayout_2->addWidget(identify_pushButton, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Camera_Test_Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        result_lineEdit = new QLineEdit(Camera_Test_Form);
        result_lineEdit->setObjectName(QString::fromUtf8("result_lineEdit"));
        QFont font;
        font.setPointSize(10);
        result_lineEdit->setFont(font);

        horizontalLayout->addWidget(result_lineEdit);

        horizontalLayout->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(209, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        play_pushButton = new QPushButton(Camera_Test_Form);
        play_pushButton->setObjectName(QString::fromUtf8("play_pushButton"));

        gridLayout_2->addWidget(play_pushButton, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Camera_Test_Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 7);


        retranslateUi(Camera_Test_Form);

        QMetaObject::connectSlotsByName(Camera_Test_Form);
    } // setupUi

    void retranslateUi(QWidget *Camera_Test_Form)
    {
        Camera_Test_Form->setWindowTitle(QApplication::translate("Camera_Test_Form", "Form", nullptr));
        capture_pushButton->setText(QApplication::translate("Camera_Test_Form", "Capture", nullptr));
        identify_pushButton->setText(QApplication::translate("Camera_Test_Form", "Identify", nullptr));
        label_2->setText(QApplication::translate("Camera_Test_Form", "Result:", nullptr));
        play_pushButton->setText(QApplication::translate("Camera_Test_Form", "Play", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Camera_Test_Form: public Ui_Camera_Test_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_TEST_FORM_H
