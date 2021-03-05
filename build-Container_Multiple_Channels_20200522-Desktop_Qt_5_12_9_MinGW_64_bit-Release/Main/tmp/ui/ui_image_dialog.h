/********************************************************************************
** Form generated from reading UI file 'image_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_DIALOG_H
#define UI_IMAGE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Image_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *image_label;

    void setupUi(QDialog *Image_Dialog)
    {
        if (Image_Dialog->objectName().isEmpty())
            Image_Dialog->setObjectName(QString::fromUtf8("Image_Dialog"));
        Image_Dialog->resize(1360, 800);
        Image_Dialog->setMinimumSize(QSize(0, 0));
        Image_Dialog->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Image_Dialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        image_label = new QLabel(Image_Dialog);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setMinimumSize(QSize(768, 576));
        image_label->setMaximumSize(QSize(16777215, 16777215));
        image_label->setFrameShape(QFrame::Box);
        image_label->setScaledContents(false);

        gridLayout->addWidget(image_label, 0, 0, 1, 1);


        retranslateUi(Image_Dialog);

        QMetaObject::connectSlotsByName(Image_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Image_Dialog)
    {
        Image_Dialog->setWindowTitle(QApplication::translate("Image_Dialog", "Dialog", nullptr));
        image_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Image_Dialog: public Ui_Image_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_DIALOG_H
