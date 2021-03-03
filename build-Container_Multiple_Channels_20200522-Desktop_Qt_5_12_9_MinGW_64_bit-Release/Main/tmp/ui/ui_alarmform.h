/********************************************************************************
** Form generated from reading UI file 'alarmform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMFORM_H
#define UI_ALARMFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AlarmForm)
    {
        if (AlarmForm->objectName().isEmpty())
            AlarmForm->setObjectName(QString::fromUtf8("AlarmForm"));
        AlarmForm->resize(37, 45);
        AlarmForm->setMaximumSize(QSize(16777215, 45));
        gridLayout = new QGridLayout(AlarmForm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        toolButton = new QToolButton(AlarmForm);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(30, 30));
        toolButton->setAutoRepeat(false);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);

        gridLayout->addWidget(toolButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(AlarmForm);

        QMetaObject::connectSlotsByName(AlarmForm);
    } // setupUi

    void retranslateUi(QWidget *AlarmForm)
    {
        AlarmForm->setWindowTitle(QApplication::translate("AlarmForm", "Form", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AlarmForm: public Ui_AlarmForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMFORM_H
