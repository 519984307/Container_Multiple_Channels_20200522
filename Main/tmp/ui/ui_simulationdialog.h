/********************************************************************************
** Form generated from reading UI file 'simulationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONDIALOG_H
#define UI_SIMULATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_SimulationDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *con_before_lineEdit;
    QLineEdit *box_type_lineEdit;
    QLineEdit *con_after_lineEdit;
    QLineEdit *plate_color_lineEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *iso_before_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *iso_after_lineEdit;
    QLineEdit *plate_lineEdit;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QComboBox *Simulatiion_comboBox;
    QPushButton *capturePushButton;
    QCheckBox *while_cycle_capture_checkBox;
    QPushButton *plateCapPushButton;
    QPushButton *liftingLeverPushButton;
    QPushButton *fallRodPushButton;
    QToolButton *toolButton;
    QGroupBox *manualGroupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *send_con_before_lineEdit;
    QLineEdit *send_con_after_lineEdit;
    QLineEdit *send_plate_lineEdit;
    QLineEdit *send_plate_color_lineEdit;
    QSplitter *splitter_3;
    QCheckBox *container_checkBox;
    QCheckBox *plate_checkBox;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *send_iso_before_lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *send_iso_after_lineEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendPlate_pushButton;
    QPushButton *sendCon_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitPushButton;

    void setupUi(QDialog *SimulationDialog)
    {
        if (SimulationDialog->objectName().isEmpty())
            SimulationDialog->setObjectName(QString::fromUtf8("SimulationDialog"));
        SimulationDialog->resize(600, 600);
        SimulationDialog->setMinimumSize(QSize(600, 600));
        SimulationDialog->setMaximumSize(QSize(600, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SimulationDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(SimulationDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(SimulationDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        con_before_lineEdit = new QLineEdit(groupBox);
        con_before_lineEdit->setObjectName(QString::fromUtf8("con_before_lineEdit"));
        con_before_lineEdit->setMinimumSize(QSize(0, 33));
        con_before_lineEdit->setMaximumSize(QSize(16777215, 16777213));
        QFont font;
        font.setPointSize(20);
        con_before_lineEdit->setFont(font);
        con_before_lineEdit->setReadOnly(true);

        gridLayout->addWidget(con_before_lineEdit, 0, 0, 2, 2);

        box_type_lineEdit = new QLineEdit(groupBox);
        box_type_lineEdit->setObjectName(QString::fromUtf8("box_type_lineEdit"));
        box_type_lineEdit->setMinimumSize(QSize(0, 33));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        box_type_lineEdit->setFont(font1);
        box_type_lineEdit->setReadOnly(true);

        gridLayout->addWidget(box_type_lineEdit, 4, 0, 2, 1);

        con_after_lineEdit = new QLineEdit(groupBox);
        con_after_lineEdit->setObjectName(QString::fromUtf8("con_after_lineEdit"));
        con_after_lineEdit->setMinimumSize(QSize(0, 33));
        con_after_lineEdit->setMaximumSize(QSize(16777215, 16777213));
        con_after_lineEdit->setFont(font);
        con_after_lineEdit->setReadOnly(true);

        gridLayout->addWidget(con_after_lineEdit, 2, 0, 2, 2);

        plate_color_lineEdit = new QLineEdit(groupBox);
        plate_color_lineEdit->setObjectName(QString::fromUtf8("plate_color_lineEdit"));
        plate_color_lineEdit->setMaximumSize(QSize(90, 16777215));
        QFont font2;
        font2.setPointSize(10);
        plate_color_lineEdit->setFont(font2);
        plate_color_lineEdit->setReadOnly(true);

        gridLayout->addWidget(plate_color_lineEdit, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(17, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(17, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 2, 1, 1);

        iso_before_lineEdit = new QLineEdit(groupBox);
        iso_before_lineEdit->setObjectName(QString::fromUtf8("iso_before_lineEdit"));
        iso_before_lineEdit->setMaximumSize(QSize(90, 16777215));
        iso_before_lineEdit->setFont(font2);
        iso_before_lineEdit->setReadOnly(true);

        gridLayout->addWidget(iso_before_lineEdit, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(17, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 2, 1, 1);

        iso_after_lineEdit = new QLineEdit(groupBox);
        iso_after_lineEdit->setObjectName(QString::fromUtf8("iso_after_lineEdit"));
        iso_after_lineEdit->setMaximumSize(QSize(90, 16777215));
        iso_after_lineEdit->setFont(font2);
        iso_after_lineEdit->setReadOnly(true);

        gridLayout->addWidget(iso_after_lineEdit, 3, 2, 1, 1);

        plate_lineEdit = new QLineEdit(groupBox);
        plate_lineEdit->setObjectName(QString::fromUtf8("plate_lineEdit"));
        plate_lineEdit->setMinimumSize(QSize(0, 33));
        plate_lineEdit->setMaximumSize(QSize(16777215, 16777213));
        plate_lineEdit->setFont(font);
        plate_lineEdit->setReadOnly(true);

        gridLayout->addWidget(plate_lineEdit, 4, 1, 2, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(SimulationDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        Simulatiion_comboBox = new QComboBox(groupBox_3);
        Simulatiion_comboBox->addItem(QString());
        Simulatiion_comboBox->addItem(QString());
        Simulatiion_comboBox->addItem(QString());
        Simulatiion_comboBox->addItem(QString());
        Simulatiion_comboBox->addItem(QString());
        Simulatiion_comboBox->setObjectName(QString::fromUtf8("Simulatiion_comboBox"));
        Simulatiion_comboBox->setEditable(false);

        gridLayout_6->addWidget(Simulatiion_comboBox, 0, 0, 1, 3);

        capturePushButton = new QPushButton(groupBox_3);
        capturePushButton->setObjectName(QString::fromUtf8("capturePushButton"));

        gridLayout_6->addWidget(capturePushButton, 0, 3, 1, 1);

        while_cycle_capture_checkBox = new QCheckBox(groupBox_3);
        while_cycle_capture_checkBox->setObjectName(QString::fromUtf8("while_cycle_capture_checkBox"));

        gridLayout_6->addWidget(while_cycle_capture_checkBox, 1, 0, 1, 2);

        plateCapPushButton = new QPushButton(groupBox_3);
        plateCapPushButton->setObjectName(QString::fromUtf8("plateCapPushButton"));

        gridLayout_6->addWidget(plateCapPushButton, 2, 0, 1, 1);

        liftingLeverPushButton = new QPushButton(groupBox_3);
        liftingLeverPushButton->setObjectName(QString::fromUtf8("liftingLeverPushButton"));

        gridLayout_6->addWidget(liftingLeverPushButton, 2, 1, 1, 1);

        fallRodPushButton = new QPushButton(groupBox_3);
        fallRodPushButton->setObjectName(QString::fromUtf8("fallRodPushButton"));

        gridLayout_6->addWidget(fallRodPushButton, 2, 2, 1, 1);

        toolButton = new QToolButton(groupBox_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setCheckable(false);
        toolButton->setAutoRepeat(false);
        toolButton->setAutoExclusive(false);
        toolButton->setPopupMode(QToolButton::DelayedPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::DownArrow);

        gridLayout_6->addWidget(toolButton, 2, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 2);

        manualGroupBox = new QGroupBox(SimulationDialog);
        manualGroupBox->setObjectName(QString::fromUtf8("manualGroupBox"));
        manualGroupBox->setEnabled(true);
        gridLayout_2 = new QGridLayout(manualGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        send_con_before_lineEdit = new QLineEdit(manualGroupBox);
        send_con_before_lineEdit->setObjectName(QString::fromUtf8("send_con_before_lineEdit"));

        gridLayout_2->addWidget(send_con_before_lineEdit, 0, 0, 1, 1);

        send_con_after_lineEdit = new QLineEdit(manualGroupBox);
        send_con_after_lineEdit->setObjectName(QString::fromUtf8("send_con_after_lineEdit"));

        gridLayout_2->addWidget(send_con_after_lineEdit, 0, 1, 1, 1);

        send_plate_lineEdit = new QLineEdit(manualGroupBox);
        send_plate_lineEdit->setObjectName(QString::fromUtf8("send_plate_lineEdit"));

        gridLayout_2->addWidget(send_plate_lineEdit, 2, 0, 1, 1);

        send_plate_color_lineEdit = new QLineEdit(manualGroupBox);
        send_plate_color_lineEdit->setObjectName(QString::fromUtf8("send_plate_color_lineEdit"));

        gridLayout_2->addWidget(send_plate_color_lineEdit, 2, 1, 1, 1);

        splitter_3 = new QSplitter(manualGroupBox);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        container_checkBox = new QCheckBox(splitter_3);
        container_checkBox->setObjectName(QString::fromUtf8("container_checkBox"));
        splitter_3->addWidget(container_checkBox);
        plate_checkBox = new QCheckBox(splitter_3);
        plate_checkBox->setObjectName(QString::fromUtf8("plate_checkBox"));
        splitter_3->addWidget(plate_checkBox);

        gridLayout_2->addWidget(splitter_3, 3, 0, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        send_iso_before_lineEdit = new QLineEdit(manualGroupBox);
        send_iso_before_lineEdit->setObjectName(QString::fromUtf8("send_iso_before_lineEdit"));

        horizontalLayout->addWidget(send_iso_before_lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        send_iso_after_lineEdit = new QLineEdit(manualGroupBox);
        send_iso_after_lineEdit->setObjectName(QString::fromUtf8("send_iso_after_lineEdit"));

        horizontalLayout_2->addWidget(send_iso_after_lineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        sendPlate_pushButton = new QPushButton(manualGroupBox);
        sendPlate_pushButton->setObjectName(QString::fromUtf8("sendPlate_pushButton"));

        gridLayout_2->addWidget(sendPlate_pushButton, 2, 2, 1, 1);

        sendCon_pushButton = new QPushButton(manualGroupBox);
        sendCon_pushButton->setObjectName(QString::fromUtf8("sendCon_pushButton"));

        gridLayout_2->addWidget(sendCon_pushButton, 0, 2, 2, 1);


        gridLayout_3->addWidget(manualGroupBox, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(488, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 4, 0, 1, 1);

        exitPushButton = new QPushButton(SimulationDialog);
        exitPushButton->setObjectName(QString::fromUtf8("exitPushButton"));

        gridLayout_3->addWidget(exitPushButton, 4, 1, 1, 1);


        retranslateUi(SimulationDialog);
        QObject::connect(exitPushButton, SIGNAL(clicked()), SimulationDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(SimulationDialog);
    } // setupUi

    void retranslateUi(QDialog *SimulationDialog)
    {
        SimulationDialog->setWindowTitle(QApplication::translate("SimulationDialog", "Simulation", nullptr));
        groupBox->setTitle(QApplication::translate("SimulationDialog", "Data", nullptr));
        con_before_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Container Before", nullptr));
        box_type_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "logic", nullptr));
        con_after_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Container After", nullptr));
        plate_color_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Color", nullptr));
        iso_before_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "ISO1", nullptr));
        iso_after_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "ISO2", nullptr));
        plate_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Plate", nullptr));
        groupBox_3->setTitle(QApplication::translate("SimulationDialog", "Simulation", nullptr));
        Simulatiion_comboBox->setItemText(0, QApplication::translate("SimulationDialog", "A small container", nullptr));
        Simulatiion_comboBox->setItemText(1, QApplication::translate("SimulationDialog", "A large container", nullptr));
        Simulatiion_comboBox->setItemText(2, QApplication::translate("SimulationDialog", "front of two small containers", nullptr));
        Simulatiion_comboBox->setItemText(3, QApplication::translate("SimulationDialog", "after of two small containers", nullptr));
        Simulatiion_comboBox->setItemText(4, QApplication::translate("SimulationDialog", "Clear pictures", nullptr));

        capturePushButton->setText(QApplication::translate("SimulationDialog", "Capture", nullptr));
        while_cycle_capture_checkBox->setText(QApplication::translate("SimulationDialog", "Circular capture of containers", nullptr));
        plateCapPushButton->setText(QApplication::translate("SimulationDialog", "Plate cap", nullptr));
        liftingLeverPushButton->setText(QApplication::translate("SimulationDialog", "Lifting lever", nullptr));
        fallRodPushButton->setText(QApplication::translate("SimulationDialog", "Fall rod", nullptr));
        toolButton->setText(QApplication::translate("SimulationDialog", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        toolButton->setShortcut(QApplication::translate("SimulationDialog", "Alt+T", nullptr));
#endif // QT_NO_SHORTCUT
        manualGroupBox->setTitle(QApplication::translate("SimulationDialog", "Manual data", nullptr));
        send_con_before_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Container Before", nullptr));
        send_con_after_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Container After", nullptr));
        send_plate_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Plate", nullptr));
        send_plate_color_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "Plate color", nullptr));
        container_checkBox->setText(QApplication::translate("SimulationDialog", "Have A container", nullptr));
        plate_checkBox->setText(QApplication::translate("SimulationDialog", "Have a license plate", nullptr));
        send_iso_before_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "ISO1", nullptr));
        send_iso_after_lineEdit->setPlaceholderText(QApplication::translate("SimulationDialog", "ISO2", nullptr));
        sendPlate_pushButton->setText(QApplication::translate("SimulationDialog", "SendPla", nullptr));
        sendCon_pushButton->setText(QApplication::translate("SimulationDialog", "SendCon", nullptr));
        exitPushButton->setText(QApplication::translate("SimulationDialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulationDialog: public Ui_SimulationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONDIALOG_H
