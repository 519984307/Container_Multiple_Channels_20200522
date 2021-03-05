/********************************************************************************
** Form generated from reading UI file 'imagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *savePushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitPushButton;
    QGridLayout *gridLayout_2;
    QLabel *label;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->resize(791, 582);
        ImageDialog->setSizeGripEnabled(false);
        ImageDialog->setModal(false);
        gridLayout = new QGridLayout(ImageDialog);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        savePushButton = new QPushButton(ImageDialog);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        gridLayout->addWidget(savePushButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(592, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        exitPushButton = new QPushButton(ImageDialog);
        exitPushButton->setObjectName(QString::fromUtf8("exitPushButton"));

        gridLayout->addWidget(exitPushButton, 1, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ImageDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 3);


        retranslateUi(ImageDialog);
        QObject::connect(exitPushButton, SIGNAL(clicked()), ImageDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QApplication::translate("ImageDialog", "Dialog", nullptr));
        savePushButton->setText(QApplication::translate("ImageDialog", "Save", nullptr));
        exitPushButton->setText(QApplication::translate("ImageDialog", "Exit", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
