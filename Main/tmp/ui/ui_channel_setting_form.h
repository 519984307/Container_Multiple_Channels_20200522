/********************************************************************************
** Form generated from reading UI file 'channel_setting_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_SETTING_FORM_H
#define UI_CHANNEL_SETTING_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Channel_Setting_Form
{
public:
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QSpinBox *identificationTimes_spinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLineEdit *Display_permanent_lineEdit;
    QLineEdit *Display_address_lineEdit;
    QLabel *label_40;
    QLineEdit *Display_temp_suffix_lineEdit;
    QLabel *label_22;
    QLineEdit *Display_temp_prefix_lineEdit;
    QLabel *label_21;
    QLabel *label_18;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout;
    QLineEdit *controllerAddr_linedit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *controllerPort_spinBox;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *interfaceModel_comboBox;
    QLineEdit *Alias;
    QLabel *label_17;
    QLabel *label_23;
    QLabel *label_30;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *SerialAddr_One;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QSpinBox *Port_One;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *SerialAddr_Tow;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QSpinBox *Port_Tow;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_10;
    QCheckBox *containerState_checkbox;
    QCheckBox *plateState_checkbox;
    QLabel *label_38;
    QLabel *label_27;
    QLabel *label_33;
    QDoubleSpinBox *A1ReleasrCap_doubleSpinBox;
    QFrame *line_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLineEdit *Camera_Left;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *Camera_Plate;
    QLineEdit *Camera_Forground;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_6;
    QLineEdit *Camera_User;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_11;
    QLineEdit *Camera_Top;
    QLineEdit *Camera_Password;
    QLineEdit *LocalAddr;
    QLineEdit *Camera_Prospects;
    QLabel *label_9;
    QLabel *label_15;
    QLineEdit *Camera_Front;
    QLabel *label_26;
    QLabel *label_13;
    QLineEdit *Camera_After;
    QLineEdit *Camera_Right;
    QLabel *label_31;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_12;
    QCheckBox *inspectionLeft_checkbox;
    QCheckBox *inspectionRight_checkbox;
    QCheckBox *inspectionTop_checkbox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_28;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_3;
    QSpinBox *SerialPort_One;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *SerialPort_Tow;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QRadioButton *SerialPortOpenState;
    QRadioButton *SerialPortCloseState;
    QLabel *label_36;
    QLabel *label_24;
    QDoubleSpinBox *B1ReleasrCap_doubleSpinBox;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_11;
    QCheckBox *PlatePageState;
    QCheckBox *ProspectsPageState;
    QCheckBox *ForegroundPageState;
    QCheckBox *TopPageState;
    QLabel *label_32;
    QLabel *label_34;
    QLabel *label_4;
    QComboBox *lifthingType_comboBox;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QComboBox *D3out_comboBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_20;
    QComboBox *D4out_comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *D1out_comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *D2out_comboBox;
    QLabel *label_39;
    QLabel *label_37;
    QComboBox *ControllerSignalMode;
    QLabel *label_29;
    QLabel *label_35;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QRadioButton *A1shielding_checkbox;
    QRadioButton *A2shielding_checkbox;
    QRadioButton *B1shielding_checkbox;
    QRadioButton *B2shielding_checkbox;
    QSpinBox *Channel_Number;
    QLabel *label_41;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_14;
    QLineEdit *Inside_addr_lineEdit;
    QLineEdit *Inside_port_lineEdit;
    QLabel *label_42;
    QLabel *label_43;

    void setupUi(QWidget *Channel_Setting_Form)
    {
        if (Channel_Setting_Form->objectName().isEmpty())
            Channel_Setting_Form->setObjectName(QString::fromUtf8("Channel_Setting_Form"));
        Channel_Setting_Form->resize(768, 576);
        Channel_Setting_Form->setAutoFillBackground(false);
        gridLayout_9 = new QGridLayout(Channel_Setting_Form);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        scrollArea = new QScrollArea(Channel_Setting_Form);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -1199, 731, 1755));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(50);
        gridLayout_2->setVerticalSpacing(20);
        identificationTimes_spinBox = new QSpinBox(scrollAreaWidgetContents);
        identificationTimes_spinBox->setObjectName(QString::fromUtf8("identificationTimes_spinBox"));
        identificationTimes_spinBox->setEnabled(false);
        identificationTimes_spinBox->setAlignment(Qt::AlignCenter);
        identificationTimes_spinBox->setMinimum(1);
        identificationTimes_spinBox->setMaximum(3);

        gridLayout_2->addWidget(identificationTimes_spinBox, 21, 1, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        Display_permanent_lineEdit = new QLineEdit(groupBox);
        Display_permanent_lineEdit->setObjectName(QString::fromUtf8("Display_permanent_lineEdit"));

        gridLayout_7->addWidget(Display_permanent_lineEdit, 1, 0, 1, 2);

        Display_address_lineEdit = new QLineEdit(groupBox);
        Display_address_lineEdit->setObjectName(QString::fromUtf8("Display_address_lineEdit"));
        Display_address_lineEdit->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(Display_address_lineEdit, 0, 0, 1, 1);

        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_7->addWidget(label_40, 0, 1, 1, 1);

        Display_temp_suffix_lineEdit = new QLineEdit(groupBox);
        Display_temp_suffix_lineEdit->setObjectName(QString::fromUtf8("Display_temp_suffix_lineEdit"));

        gridLayout_7->addWidget(Display_temp_suffix_lineEdit, 3, 0, 1, 2);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(150, 16777215));

        gridLayout_7->addWidget(label_22, 3, 2, 1, 1);

        Display_temp_prefix_lineEdit = new QLineEdit(groupBox);
        Display_temp_prefix_lineEdit->setObjectName(QString::fromUtf8("Display_temp_prefix_lineEdit"));

        gridLayout_7->addWidget(Display_temp_prefix_lineEdit, 2, 0, 1, 2);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(150, 16777215));

        gridLayout_7->addWidget(label_21, 2, 2, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(150, 16777215));

        gridLayout_7->addWidget(label_18, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 7, 1, 2, 2);

        groupBox_11 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        gridLayout_13 = new QGridLayout(groupBox_11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        controllerAddr_linedit = new QLineEdit(groupBox_11);
        controllerAddr_linedit->setObjectName(QString::fromUtf8("controllerAddr_linedit"));

        horizontalLayout->addWidget(controllerAddr_linedit);


        gridLayout_13->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_11);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);

        controllerPort_spinBox = new QSpinBox(groupBox_11);
        controllerPort_spinBox->setObjectName(QString::fromUtf8("controllerPort_spinBox"));
        controllerPort_spinBox->setMaximum(65535);
        controllerPort_spinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        controllerPort_spinBox->setValue(12011);

        horizontalLayout_2->addWidget(controllerPort_spinBox);

        horizontalLayout_2->setStretch(1, 1);

        gridLayout_13->addLayout(horizontalLayout_2, 0, 1, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(143, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_4, 0, 2, 2, 1);

        interfaceModel_comboBox = new QComboBox(groupBox_11);
        interfaceModel_comboBox->addItem(QString());
        interfaceModel_comboBox->addItem(QString());
        interfaceModel_comboBox->setObjectName(QString::fromUtf8("interfaceModel_comboBox"));

        gridLayout_13->addWidget(interfaceModel_comboBox, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_11, 2, 1, 1, 2);

        Alias = new QLineEdit(scrollAreaWidgetContents);
        Alias->setObjectName(QString::fromUtf8("Alias"));
        Alias->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Alias, 17, 1, 1, 1);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(200, 0));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 0, 0, 1, 1);

        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(200, 0));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_23, 6, 0, 1, 1);

        label_30 = new QLabel(scrollAreaWidgetContents);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(200, 0));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_30, 21, 0, 1, 1);

        groupBox_10 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        gridLayout_4 = new QGridLayout(groupBox_10);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        SerialAddr_One = new QLineEdit(groupBox_10);
        SerialAddr_One->setObjectName(QString::fromUtf8("SerialAddr_One"));

        horizontalLayout_9->addWidget(SerialAddr_One);


        gridLayout_4->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_3 = new QLabel(groupBox_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_3);

        Port_One = new QSpinBox(groupBox_10);
        Port_One->setObjectName(QString::fromUtf8("Port_One"));

        horizontalLayout_11->addWidget(Port_One);

        horizontalLayout_11->setStretch(1, 1);

        gridLayout_4->addLayout(horizontalLayout_11, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 2, 2, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        SerialAddr_Tow = new QLineEdit(groupBox_10);
        SerialAddr_Tow->setObjectName(QString::fromUtf8("SerialAddr_Tow"));

        horizontalLayout_10->addWidget(SerialAddr_Tow);


        gridLayout_4->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(groupBox_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_5);

        Port_Tow = new QSpinBox(groupBox_10);
        Port_Tow->setObjectName(QString::fromUtf8("Port_Tow"));

        horizontalLayout_12->addWidget(Port_Tow);

        horizontalLayout_12->setStretch(1, 1);

        gridLayout_4->addLayout(horizontalLayout_12, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_10, 4, 1, 1, 2);

        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setEnabled(false);
        gridLayout_10 = new QGridLayout(groupBox_7);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        containerState_checkbox = new QCheckBox(groupBox_7);
        containerState_checkbox->setObjectName(QString::fromUtf8("containerState_checkbox"));
        containerState_checkbox->setChecked(true);

        gridLayout_10->addWidget(containerState_checkbox, 0, 0, 1, 1);

        plateState_checkbox = new QCheckBox(groupBox_7);
        plateState_checkbox->setObjectName(QString::fromUtf8("plateState_checkbox"));
        plateState_checkbox->setChecked(false);

        gridLayout_10->addWidget(plateState_checkbox, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_7, 11, 1, 1, 2);

        label_38 = new QLabel(scrollAreaWidgetContents);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(200, 0));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_38, 4, 0, 1, 1);

        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(200, 0));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_27, 18, 0, 1, 1);

        label_33 = new QLabel(scrollAreaWidgetContents);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(200, 0));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_33, 12, 0, 1, 1);

        A1ReleasrCap_doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        A1ReleasrCap_doubleSpinBox->setObjectName(QString::fromUtf8("A1ReleasrCap_doubleSpinBox"));
        A1ReleasrCap_doubleSpinBox->setEnabled(true);
        A1ReleasrCap_doubleSpinBox->setWrapping(false);
        A1ReleasrCap_doubleSpinBox->setAlignment(Qt::AlignCenter);
        A1ReleasrCap_doubleSpinBox->setDecimals(1);
        A1ReleasrCap_doubleSpinBox->setSingleStep(0.100000000000000);
        A1ReleasrCap_doubleSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_2->addWidget(A1ReleasrCap_doubleSpinBox, 19, 1, 1, 1);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_7, 5, 1, 1, 2);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Camera_Left = new QLineEdit(groupBox_2);
        Camera_Left->setObjectName(QString::fromUtf8("Camera_Left"));

        gridLayout->addWidget(Camera_Left, 3, 0, 1, 1);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(100, 0));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_25, 7, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(235, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 9, 2, 1, 1);

        Camera_Plate = new QLineEdit(groupBox_2);
        Camera_Plate->setObjectName(QString::fromUtf8("Camera_Plate"));

        gridLayout->addWidget(Camera_Plate, 9, 0, 1, 1);

        Camera_Forground = new QLineEdit(groupBox_2);
        Camera_Forground->setObjectName(QString::fromUtf8("Camera_Forground"));

        gridLayout->addWidget(Camera_Forground, 8, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 5, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 14, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 12, 1, 1, 1);

        Camera_User = new QLineEdit(groupBox_2);
        Camera_User->setObjectName(QString::fromUtf8("Camera_User"));

        gridLayout->addWidget(Camera_User, 13, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 1, 1, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 0));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 0, 1, 1, 1);

        Camera_Top = new QLineEdit(groupBox_2);
        Camera_Top->setObjectName(QString::fromUtf8("Camera_Top"));

        gridLayout->addWidget(Camera_Top, 6, 0, 1, 1);

        Camera_Password = new QLineEdit(groupBox_2);
        Camera_Password->setObjectName(QString::fromUtf8("Camera_Password"));

        gridLayout->addWidget(Camera_Password, 14, 0, 1, 1);

        LocalAddr = new QLineEdit(groupBox_2);
        LocalAddr->setObjectName(QString::fromUtf8("LocalAddr"));

        gridLayout->addWidget(LocalAddr, 12, 0, 1, 1);

        Camera_Prospects = new QLineEdit(groupBox_2);
        Camera_Prospects->setObjectName(QString::fromUtf8("Camera_Prospects"));

        gridLayout->addWidget(Camera_Prospects, 7, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 6, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 9, 1, 1, 1);

        Camera_Front = new QLineEdit(groupBox_2);
        Camera_Front->setObjectName(QString::fromUtf8("Camera_Front"));

        gridLayout->addWidget(Camera_Front, 0, 0, 1, 1);

        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 8, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 13, 1, 1, 1);

        Camera_After = new QLineEdit(groupBox_2);
        Camera_After->setObjectName(QString::fromUtf8("Camera_After"));

        gridLayout->addWidget(Camera_After, 1, 0, 1, 1);

        Camera_Right = new QLineEdit(groupBox_2);
        Camera_Right->setObjectName(QString::fromUtf8("Camera_Right"));

        gridLayout->addWidget(Camera_Right, 5, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 2);

        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(200, 0));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 14, 0, 1, 1);

        groupBox_8 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setEnabled(false);
        gridLayout_12 = new QGridLayout(groupBox_8);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        inspectionLeft_checkbox = new QCheckBox(groupBox_8);
        inspectionLeft_checkbox->setObjectName(QString::fromUtf8("inspectionLeft_checkbox"));
        inspectionLeft_checkbox->setChecked(false);

        gridLayout_12->addWidget(inspectionLeft_checkbox, 0, 0, 1, 1);

        inspectionRight_checkbox = new QCheckBox(groupBox_8);
        inspectionRight_checkbox->setObjectName(QString::fromUtf8("inspectionRight_checkbox"));
        inspectionRight_checkbox->setChecked(false);

        gridLayout_12->addWidget(inspectionRight_checkbox, 1, 0, 1, 1);

        inspectionTop_checkbox = new QCheckBox(groupBox_8);
        inspectionTop_checkbox->setObjectName(QString::fromUtf8("inspectionTop_checkbox"));
        inspectionTop_checkbox->setChecked(false);

        gridLayout_12->addWidget(inspectionTop_checkbox, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_8, 15, 1, 1, 2);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(200, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 18, 2, 4, 1);

        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(200, 0));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_28, 19, 0, 1, 1);

        groupBox_9 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_3 = new QGridLayout(groupBox_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SerialPort_One = new QSpinBox(groupBox_9);
        SerialPort_One->setObjectName(QString::fromUtf8("SerialPort_One"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialPort_One->sizePolicy().hasHeightForWidth());
        SerialPort_One->setSizePolicy(sizePolicy);
        SerialPort_One->setMinimum(1);

        gridLayout_3->addWidget(SerialPort_One, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 2, 1);

        SerialPort_Tow = new QSpinBox(groupBox_9);
        SerialPort_Tow->setObjectName(QString::fromUtf8("SerialPort_Tow"));
        sizePolicy.setHeightForWidth(SerialPort_Tow->sizePolicy().hasHeightForWidth());
        SerialPort_Tow->setSizePolicy(sizePolicy);
        SerialPort_Tow->setMinimum(1);
        SerialPort_Tow->setValue(2);

        gridLayout_3->addWidget(SerialPort_Tow, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 3, 1, 1, 2);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        SerialPortOpenState = new QRadioButton(groupBox_4);
        SerialPortOpenState->setObjectName(QString::fromUtf8("SerialPortOpenState"));
        SerialPortOpenState->setChecked(false);

        gridLayout_6->addWidget(SerialPortOpenState, 0, 0, 1, 1);

        SerialPortCloseState = new QRadioButton(groupBox_4);
        SerialPortCloseState->setObjectName(QString::fromUtf8("SerialPortCloseState"));
        SerialPortCloseState->setChecked(true);

        gridLayout_6->addWidget(SerialPortCloseState, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 6, 1, 1, 2);

        label_36 = new QLabel(scrollAreaWidgetContents);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(200, 0));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 10, 0, 1, 1);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(200, 0));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_24, 17, 0, 1, 1);

        B1ReleasrCap_doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        B1ReleasrCap_doubleSpinBox->setObjectName(QString::fromUtf8("B1ReleasrCap_doubleSpinBox"));
        B1ReleasrCap_doubleSpinBox->setEnabled(false);
        B1ReleasrCap_doubleSpinBox->setAlignment(Qt::AlignCenter);
        B1ReleasrCap_doubleSpinBox->setDecimals(1);

        gridLayout_2->addWidget(B1ReleasrCap_doubleSpinBox, 20, 1, 1, 1);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_11 = new QGridLayout(groupBox_6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        PlatePageState = new QCheckBox(groupBox_6);
        PlatePageState->setObjectName(QString::fromUtf8("PlatePageState"));

        gridLayout_11->addWidget(PlatePageState, 0, 0, 1, 1);

        ProspectsPageState = new QCheckBox(groupBox_6);
        ProspectsPageState->setObjectName(QString::fromUtf8("ProspectsPageState"));

        gridLayout_11->addWidget(ProspectsPageState, 1, 0, 1, 1);

        ForegroundPageState = new QCheckBox(groupBox_6);
        ForegroundPageState->setObjectName(QString::fromUtf8("ForegroundPageState"));

        gridLayout_11->addWidget(ForegroundPageState, 2, 0, 1, 1);

        TopPageState = new QCheckBox(groupBox_6);
        TopPageState->setObjectName(QString::fromUtf8("TopPageState"));

        gridLayout_11->addWidget(TopPageState, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 12, 1, 1, 1);

        label_32 = new QLabel(scrollAreaWidgetContents);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(200, 0));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_32, 15, 0, 1, 1);

        label_34 = new QLabel(scrollAreaWidgetContents);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(200, 0));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 11, 0, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 7, 0, 2, 1);

        lifthingType_comboBox = new QComboBox(scrollAreaWidgetContents);
        lifthingType_comboBox->addItem(QString());
        lifthingType_comboBox->addItem(QString());
        lifthingType_comboBox->addItem(QString());
        lifthingType_comboBox->setObjectName(QString::fromUtf8("lifthingType_comboBox"));

        gridLayout_2->addWidget(lifthingType_comboBox, 10, 1, 1, 1);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_7->addWidget(label_19);

        D3out_comboBox = new QComboBox(groupBox_5);
        D3out_comboBox->addItem(QString());
        D3out_comboBox->addItem(QString());
        D3out_comboBox->addItem(QString());
        D3out_comboBox->setObjectName(QString::fromUtf8("D3out_comboBox"));

        horizontalLayout_7->addWidget(D3out_comboBox);

        horizontalLayout_7->setStretch(1, 1);

        gridLayout_8->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_8->addWidget(label_20);

        D4out_comboBox = new QComboBox(groupBox_5);
        D4out_comboBox->addItem(QString());
        D4out_comboBox->addItem(QString());
        D4out_comboBox->addItem(QString());
        D4out_comboBox->setObjectName(QString::fromUtf8("D4out_comboBox"));

        horizontalLayout_8->addWidget(D4out_comboBox);

        horizontalLayout_8->setStretch(1, 1);

        gridLayout_8->addLayout(horizontalLayout_8, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        D1out_comboBox = new QComboBox(groupBox_5);
        D1out_comboBox->addItem(QString());
        D1out_comboBox->addItem(QString());
        D1out_comboBox->addItem(QString());
        D1out_comboBox->setObjectName(QString::fromUtf8("D1out_comboBox"));

        horizontalLayout_3->addWidget(D1out_comboBox);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(230, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 2, 1, 2, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        D2out_comboBox = new QComboBox(groupBox_5);
        D2out_comboBox->addItem(QString());
        D2out_comboBox->addItem(QString());
        D2out_comboBox->addItem(QString());
        D2out_comboBox->setObjectName(QString::fromUtf8("D2out_comboBox"));

        horizontalLayout_4->addWidget(D2out_comboBox);

        horizontalLayout_4->setStretch(1, 1);

        gridLayout_8->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 9, 1, 1, 2);

        label_39 = new QLabel(scrollAreaWidgetContents);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(200, 0));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_39, 2, 0, 1, 1);

        label_37 = new QLabel(scrollAreaWidgetContents);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(200, 0));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_37, 3, 0, 1, 1);

        ControllerSignalMode = new QComboBox(scrollAreaWidgetContents);
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->setObjectName(QString::fromUtf8("ControllerSignalMode"));

        gridLayout_2->addWidget(ControllerSignalMode, 1, 1, 1, 1);

        label_29 = new QLabel(scrollAreaWidgetContents);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(200, 0));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_29, 20, 0, 1, 1);

        label_35 = new QLabel(scrollAreaWidgetContents);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(200, 0));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_35, 9, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        A1shielding_checkbox = new QRadioButton(groupBox_3);
        A1shielding_checkbox->setObjectName(QString::fromUtf8("A1shielding_checkbox"));
        A1shielding_checkbox->setChecked(false);

        gridLayout_5->addWidget(A1shielding_checkbox, 0, 0, 1, 1);

        A2shielding_checkbox = new QRadioButton(groupBox_3);
        A2shielding_checkbox->setObjectName(QString::fromUtf8("A2shielding_checkbox"));
        A2shielding_checkbox->setChecked(false);

        gridLayout_5->addWidget(A2shielding_checkbox, 1, 0, 1, 1);

        B1shielding_checkbox = new QRadioButton(groupBox_3);
        B1shielding_checkbox->setObjectName(QString::fromUtf8("B1shielding_checkbox"));
        B1shielding_checkbox->setChecked(false);

        gridLayout_5->addWidget(B1shielding_checkbox, 2, 0, 1, 1);

        B2shielding_checkbox = new QRadioButton(groupBox_3);
        B2shielding_checkbox->setObjectName(QString::fromUtf8("B2shielding_checkbox"));
        B2shielding_checkbox->setChecked(false);

        gridLayout_5->addWidget(B2shielding_checkbox, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 14, 1, 1, 2);

        Channel_Number = new QSpinBox(scrollAreaWidgetContents);
        Channel_Number->setObjectName(QString::fromUtf8("Channel_Number"));
        sizePolicy.setHeightForWidth(Channel_Number->sizePolicy().hasHeightForWidth());
        Channel_Number->setSizePolicy(sizePolicy);
        Channel_Number->setAlignment(Qt::AlignCenter);
        Channel_Number->setMinimum(0);

        gridLayout_2->addWidget(Channel_Number, 18, 1, 1, 1);

        label_41 = new QLabel(scrollAreaWidgetContents);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_41, 16, 0, 1, 1);

        groupBox_12 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_14 = new QGridLayout(groupBox_12);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        Inside_addr_lineEdit = new QLineEdit(groupBox_12);
        Inside_addr_lineEdit->setObjectName(QString::fromUtf8("Inside_addr_lineEdit"));

        gridLayout_14->addWidget(Inside_addr_lineEdit, 0, 0, 1, 1);

        Inside_port_lineEdit = new QLineEdit(groupBox_12);
        Inside_port_lineEdit->setObjectName(QString::fromUtf8("Inside_port_lineEdit"));

        gridLayout_14->addWidget(Inside_port_lineEdit, 1, 0, 1, 1);

        label_42 = new QLabel(groupBox_12);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_14->addWidget(label_42, 0, 1, 1, 1);

        label_43 = new QLabel(groupBox_12);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_14->addWidget(label_43, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_12, 16, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_9->addWidget(scrollArea, 0, 1, 1, 1);

        QWidget::setTabOrder(Camera_Front, Camera_Left);
        QWidget::setTabOrder(Camera_Left, Camera_Top);
        QWidget::setTabOrder(Camera_Top, LocalAddr);
        QWidget::setTabOrder(LocalAddr, Camera_Prospects);
        QWidget::setTabOrder(Camera_Prospects, Camera_User);
        QWidget::setTabOrder(Camera_User, Camera_Forground);
        QWidget::setTabOrder(Camera_Forground, Camera_Password);
        QWidget::setTabOrder(Camera_Password, Camera_Plate);
        QWidget::setTabOrder(Camera_Plate, controllerAddr_linedit);
        QWidget::setTabOrder(controllerAddr_linedit, controllerPort_spinBox);
        QWidget::setTabOrder(controllerPort_spinBox, D1out_comboBox);
        QWidget::setTabOrder(D1out_comboBox, D2out_comboBox);
        QWidget::setTabOrder(D2out_comboBox, D3out_comboBox);
        QWidget::setTabOrder(D3out_comboBox, D4out_comboBox);
        QWidget::setTabOrder(D4out_comboBox, SerialAddr_One);
        QWidget::setTabOrder(SerialAddr_One, Port_One);
        QWidget::setTabOrder(Port_One, Port_Tow);
        QWidget::setTabOrder(Port_Tow, SerialAddr_Tow);

        retranslateUi(Channel_Setting_Form);

        D3out_comboBox->setCurrentIndex(0);
        D4out_comboBox->setCurrentIndex(0);
        D1out_comboBox->setCurrentIndex(0);
        D2out_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Channel_Setting_Form);
    } // setupUi

    void retranslateUi(QWidget *Channel_Setting_Form)
    {
        Channel_Setting_Form->setWindowTitle(QApplication::translate("Channel_Setting_Form", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        identificationTimes_spinBox->setToolTip(QApplication::translate("Channel_Setting_Form", "Container number identification times", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QString());
        Display_address_lineEdit->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000", nullptr));
        Display_address_lineEdit->setText(QApplication::translate("Channel_Setting_Form", "...", nullptr));
        label_40->setText(QApplication::translate("Channel_Setting_Form", "address", nullptr));
        label_22->setText(QApplication::translate("Channel_Setting_Form", "Temporary message suffix", nullptr));
        label_21->setText(QApplication::translate("Channel_Setting_Form", "Temporary message prefix", nullptr));
        label_18->setText(QApplication::translate("Channel_Setting_Form", "Permanent stay message", nullptr));
        groupBox_11->setTitle(QString());
        controllerAddr_linedit->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_7->setText(QApplication::translate("Channel_Setting_Form", "port", nullptr));
        interfaceModel_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "tcp client", nullptr));
        interfaceModel_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "tcp server", nullptr));

#ifndef QT_NO_TOOLTIP
        Alias->setToolTip(QApplication::translate("Channel_Setting_Form", "Channel alias, the main page prompt.", nullptr));
#endif // QT_NO_TOOLTIP
        Alias->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "Container access gate", nullptr));
        label_17->setText(QApplication::translate("Channel_Setting_Form", "Address of the camera", nullptr));
        label_23->setText(QApplication::translate("Channel_Setting_Form", "Controller signal mode", nullptr));
        label_30->setText(QApplication::translate("Channel_Setting_Form", "Image repetition recognition", nullptr));
        groupBox_10->setTitle(QString());
        SerialAddr_One->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_3->setText(QApplication::translate("Channel_Setting_Form", "Port1", nullptr));
        SerialAddr_Tow->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        SerialAddr_Tow->setText(QApplication::translate("Channel_Setting_Form", "...", nullptr));
        label_5->setText(QApplication::translate("Channel_Setting_Form", "Port2", nullptr));
        groupBox_7->setTitle(QString());
        containerState_checkbox->setText(QApplication::translate("Channel_Setting_Form", "Container number", nullptr));
        plateState_checkbox->setText(QApplication::translate("Channel_Setting_Form", "The license plate", nullptr));
        label_38->setText(QApplication::translate("Channel_Setting_Form", "Moxa socket", nullptr));
        label_27->setText(QApplication::translate("Channel_Setting_Form", "The channel number", nullptr));
        label_33->setText(QApplication::translate("Channel_Setting_Form", "Display camera pictures", nullptr));
#ifndef QT_NO_TOOLTIP
        A1ReleasrCap_doubleSpinBox->setToolTip(QApplication::translate("Channel_Setting_Form", "A1 infrared release, how many seconds to capture the picture", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QString());
        Camera_Left->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_25->setText(QApplication::translate("Channel_Setting_Form", "Front view", nullptr));
        Camera_Plate->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Forground->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_10->setText(QApplication::translate("Channel_Setting_Form", "Right", nullptr));
        label_12->setText(QApplication::translate("Channel_Setting_Form", "Password", nullptr));
        label_6->setText(QApplication::translate("Channel_Setting_Form", "Local Addr", nullptr));
        Camera_User->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "admin", nullptr));
        label_14->setText(QApplication::translate("Channel_Setting_Form", "After", nullptr));
        label_16->setText(QApplication::translate("Channel_Setting_Form", "Left", nullptr));
        label_11->setText(QApplication::translate("Channel_Setting_Form", "Front", nullptr));
        Camera_Top->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Password->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "ABCabc123", nullptr));
        LocalAddr->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Prospects->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_9->setText(QApplication::translate("Channel_Setting_Form", "Top", nullptr));
        label_15->setText(QApplication::translate("Channel_Setting_Form", "Plate", nullptr));
        Camera_Front->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_26->setText(QApplication::translate("Channel_Setting_Form", "End view", nullptr));
        label_13->setText(QApplication::translate("Channel_Setting_Form", "User", nullptr));
        Camera_After->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Right->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_31->setText(QApplication::translate("Channel_Setting_Form", "Shielded infrared signal", nullptr));
        groupBox_8->setTitle(QString());
        inspectionLeft_checkbox->setText(QApplication::translate("Channel_Setting_Form", "Left Camera", nullptr));
        inspectionRight_checkbox->setText(QApplication::translate("Channel_Setting_Form", "Right Camera", nullptr));
        inspectionTop_checkbox->setText(QApplication::translate("Channel_Setting_Form", "Top Camera", nullptr));
        label_2->setText(QApplication::translate("Channel_Setting_Form", "Trigger mode", nullptr));
        label_28->setText(QApplication::translate("Channel_Setting_Form", "A2 timeout capture", nullptr));
        groupBox_9->setTitle(QString());
        SerialPort_One->setSuffix(QString());
        SerialPort_One->setPrefix(QApplication::translate("Channel_Setting_Form", "COM", nullptr));
        SerialPort_Tow->setPrefix(QApplication::translate("Channel_Setting_Form", "COM", nullptr));
        groupBox_4->setTitle(QString());
        SerialPortOpenState->setText(QApplication::translate("Channel_Setting_Form", "Normally open", nullptr));
        SerialPortCloseState->setText(QApplication::translate("Channel_Setting_Form", "Normally closed", nullptr));
        label_36->setText(QApplication::translate("Channel_Setting_Form", "Lifting lever pattern", nullptr));
        label_24->setText(QApplication::translate("Channel_Setting_Form", "Channel alias", nullptr));
#ifndef QT_NO_TOOLTIP
        B1ReleasrCap_doubleSpinBox->setToolTip(QApplication::translate("Channel_Setting_Form", "B1 infrared release, how many seconds to capture the picture", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_6->setTitle(QString());
        PlatePageState->setText(QApplication::translate("Channel_Setting_Form", "Plate ", nullptr));
        ProspectsPageState->setText(QApplication::translate("Channel_Setting_Form", "Prospects", nullptr));
        ForegroundPageState->setText(QApplication::translate("Channel_Setting_Form", "Foreground", nullptr));
        TopPageState->setText(QApplication::translate("Channel_Setting_Form", "Top", nullptr));
        label_32->setText(QApplication::translate("Channel_Setting_Form", "Container residue inspection", nullptr));
        label_34->setText(QApplication::translate("Channel_Setting_Form", "Identify the project", nullptr));
        label_4->setText(QApplication::translate("Channel_Setting_Form", "Display screen parameters", nullptr));
        lifthingType_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "Identification of lifting lever", nullptr));
        lifthingType_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "Identify successful lift rod", nullptr));
        lifthingType_comboBox->setItemText(2, QApplication::translate("Channel_Setting_Form", "Lift rod on signal", nullptr));

        groupBox_5->setTitle(QString());
        label_19->setText(QApplication::translate("Channel_Setting_Form", "D3", nullptr));
        D3out_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "NONE", nullptr));
        D3out_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "Brake machine", nullptr));
        D3out_comboBox->setItemText(2, QApplication::translate("Channel_Setting_Form", "LED", nullptr));

        label_20->setText(QApplication::translate("Channel_Setting_Form", "D4", nullptr));
        D4out_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "NONE", nullptr));
        D4out_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "Brake machine", nullptr));
        D4out_comboBox->setItemText(2, QApplication::translate("Channel_Setting_Form", "LED", nullptr));

        label->setText(QApplication::translate("Channel_Setting_Form", "D1", nullptr));
        D1out_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "NONE", nullptr));
        D1out_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "Brake machine", nullptr));
        D1out_comboBox->setItemText(2, QApplication::translate("Channel_Setting_Form", "LED", nullptr));

        label_8->setText(QApplication::translate("Channel_Setting_Form", "D2", nullptr));
        D2out_comboBox->setItemText(0, QApplication::translate("Channel_Setting_Form", "NONE", nullptr));
        D2out_comboBox->setItemText(1, QApplication::translate("Channel_Setting_Form", "Brake machine", nullptr));
        D2out_comboBox->setItemText(2, QApplication::translate("Channel_Setting_Form", "LED", nullptr));

        label_39->setText(QApplication::translate("Channel_Setting_Form", "Network controller", nullptr));
        label_37->setText(QApplication::translate("Channel_Setting_Form", "Serial Port", nullptr));
        ControllerSignalMode->setItemText(0, QApplication::translate("Channel_Setting_Form", "Serial Port", nullptr));
        ControllerSignalMode->setItemText(1, QApplication::translate("Channel_Setting_Form", "Moxa Socket", nullptr));
        ControllerSignalMode->setItemText(2, QApplication::translate("Channel_Setting_Form", "Network controller", nullptr));

        label_29->setText(QApplication::translate("Channel_Setting_Form", "B1 timeout capture", nullptr));
        label_35->setText(QApplication::translate("Channel_Setting_Form", "Network controller control", nullptr));
        groupBox_3->setTitle(QString());
        A1shielding_checkbox->setText(QApplication::translate("Channel_Setting_Form", "A1", nullptr));
        A2shielding_checkbox->setText(QApplication::translate("Channel_Setting_Form", "A2", nullptr));
        B1shielding_checkbox->setText(QApplication::translate("Channel_Setting_Form", "B1", nullptr));
        B2shielding_checkbox->setText(QApplication::translate("Channel_Setting_Form", "B2", nullptr));
#ifndef QT_NO_TOOLTIP
        Channel_Number->setToolTip(QApplication::translate("Channel_Setting_Form", "The channel number that distinguishes the channel data.", nullptr));
#endif // QT_NO_TOOLTIP
        label_41->setText(QApplication::translate("Channel_Setting_Form", "Inside the socket", nullptr));
        groupBox_12->setTitle(QString());
        label_42->setText(QApplication::translate("Channel_Setting_Form", "Address", nullptr));
        label_43->setText(QApplication::translate("Channel_Setting_Form", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Channel_Setting_Form: public Ui_Channel_Setting_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_SETTING_FORM_H
