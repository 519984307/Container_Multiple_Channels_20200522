/********************************************************************************
** Form generated from reading UI file 'setting_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_FORM_H
#define UI_SETTING_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting_Form
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QPushButton *system_pushButton;
    QPushButton *channel_pushButton;
    QListWidget *listWidget;

    void setupUi(QWidget *Setting_Form)
    {
        if (Setting_Form->objectName().isEmpty())
            Setting_Form->setObjectName(QString::fromUtf8("Setting_Form"));
        Setting_Form->resize(1024, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Setting_Form->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Setting_Form);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(Setting_Form);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ignore|QDialogButtonBox::Save);

        gridLayout_2->addWidget(buttonBox, 4, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 1, 4, 1);

        system_pushButton = new QPushButton(Setting_Form);
        system_pushButton->setObjectName(QString::fromUtf8("system_pushButton"));
        system_pushButton->setMinimumSize(QSize(150, 0));
        system_pushButton->setMaximumSize(QSize(150, 37));

        gridLayout_2->addWidget(system_pushButton, 0, 0, 1, 1);

        channel_pushButton = new QPushButton(Setting_Form);
        channel_pushButton->setObjectName(QString::fromUtf8("channel_pushButton"));
        channel_pushButton->setMinimumSize(QSize(150, 0));
        channel_pushButton->setMaximumSize(QSize(150, 37));

        gridLayout_2->addWidget(channel_pushButton, 1, 0, 1, 1);

        listWidget = new QListWidget(Setting_Form);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(listWidget, 2, 0, 3, 1);


        retranslateUi(Setting_Form);

        QMetaObject::connectSlotsByName(Setting_Form);
    } // setupUi

    void retranslateUi(QWidget *Setting_Form)
    {
        Setting_Form->setWindowTitle(QApplication::translate("Setting_Form", "Setting", nullptr));
        system_pushButton->setText(QApplication::translate("Setting_Form", "System Settings", nullptr));
        channel_pushButton->setText(QApplication::translate("Setting_Form", "Channel Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting_Form: public Ui_Setting_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_FORM_H
