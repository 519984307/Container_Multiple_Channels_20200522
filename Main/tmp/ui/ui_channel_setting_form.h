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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Channel_Setting_Form
{
public:
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_9;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Camera_Front;
    QLineEdit *Camera_Left;
    QLineEdit *Camera_Top;
    QLineEdit *Camera_Prospects;
    QLineEdit *Camera_Forground;
    QLineEdit *LocalAddr;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *Camera_After;
    QLineEdit *Camera_Right;
    QLineEdit *Camera_Plate;
    QLineEdit *Camera_User;
    QLineEdit *Camera_Password;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_18;
    QSpinBox *SerialPort_Tow;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_17;
    QSpinBox *SerialPort_One;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *SerialAddr_One;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *SerialAddr_Tow;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QSpinBox *Port_One;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QSpinBox *Port_Tow;
    QWidget *page_3;
    QGridLayout *gridLayout_10;
    QLabel *label_24;
    QLineEdit *SerialAddr_One_2;
    QComboBox *ControllerSignalMode;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_23;
    QRadioButton *SerialPortOpenState;
    QRadioButton *SerialPortCloseState;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_25;
    QCheckBox *SerialPortOpenState_3;
    QCheckBox *SerialPortCloseState_3;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_24;
    QRadioButton *SerialPortOpenState_2;
    QRadioButton *SerialPortCloseState_2;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_5;
    QCheckBox *SerialPortOpenState_5;
    QCheckBox *SerialPortOpenState_7;
    QCheckBox *SerialPortOpenState_6;
    QCheckBox *SerialPortOpenState_8;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_6;
    QCheckBox *SerialPortOpenState_12;
    QCheckBox *SerialPortOpenState_13;
    QCheckBox *SerialPortOpenState_11;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSpinBox *Channel_Number;
    QComboBox *Container_Camera_Model;
    QDoubleSpinBox *doubleSpinBox_2;
    QLineEdit *Alias;
    QLabel *label_43;
    QComboBox *Camera_Load_Plugin_comboBox_2;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_20;
    QLabel *label_42;
    QLabel *label_21;
    QComboBox *Plate_Camera_Model;
    QComboBox *HCNET_Capture_Type_comboBox_2;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_19;

    void setupUi(QWidget *Channel_Setting_Form)
    {
        if (Channel_Setting_Form->objectName().isEmpty())
            Channel_Setting_Form->setObjectName(QString::fromUtf8("Channel_Setting_Form"));
        Channel_Setting_Form->resize(873, 677);
        Channel_Setting_Form->setAutoFillBackground(false);
        gridLayout_9 = new QGridLayout(Channel_Setting_Form);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        scrollArea = new QScrollArea(Channel_Setting_Form);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 828, 1102));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(7);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout->addWidget(label_16);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout->addWidget(label_25);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout->addWidget(label_26);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Camera_Front = new QLineEdit(groupBox);
        Camera_Front->setObjectName(QString::fromUtf8("Camera_Front"));

        verticalLayout_2->addWidget(Camera_Front);

        Camera_Left = new QLineEdit(groupBox);
        Camera_Left->setObjectName(QString::fromUtf8("Camera_Left"));

        verticalLayout_2->addWidget(Camera_Left);

        Camera_Top = new QLineEdit(groupBox);
        Camera_Top->setObjectName(QString::fromUtf8("Camera_Top"));

        verticalLayout_2->addWidget(Camera_Top);

        Camera_Prospects = new QLineEdit(groupBox);
        Camera_Prospects->setObjectName(QString::fromUtf8("Camera_Prospects"));

        verticalLayout_2->addWidget(Camera_Prospects);

        Camera_Forground = new QLineEdit(groupBox);
        Camera_Forground->setObjectName(QString::fromUtf8("Camera_Forground"));

        verticalLayout_2->addWidget(Camera_Forground);

        LocalAddr = new QLineEdit(groupBox);
        LocalAddr->setObjectName(QString::fromUtf8("LocalAddr"));

        verticalLayout_2->addWidget(LocalAddr);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_3->addWidget(label_15);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_3->addWidget(label_13);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);


        gridLayout->addLayout(verticalLayout_3, 0, 3, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Camera_After = new QLineEdit(groupBox);
        Camera_After->setObjectName(QString::fromUtf8("Camera_After"));

        verticalLayout_4->addWidget(Camera_After);

        Camera_Right = new QLineEdit(groupBox);
        Camera_Right->setObjectName(QString::fromUtf8("Camera_Right"));

        verticalLayout_4->addWidget(Camera_Right);

        Camera_Plate = new QLineEdit(groupBox);
        Camera_Plate->setObjectName(QString::fromUtf8("Camera_Plate"));

        verticalLayout_4->addWidget(Camera_Plate);

        Camera_User = new QLineEdit(groupBox);
        Camera_User->setObjectName(QString::fromUtf8("Camera_User"));

        verticalLayout_4->addWidget(Camera_User);

        Camera_Password = new QLineEdit(groupBox);
        Camera_Password->setObjectName(QString::fromUtf8("Camera_Password"));

        verticalLayout_4->addWidget(Camera_Password);


        gridLayout->addLayout(verticalLayout_4, 0, 4, 1, 1);


        gridLayout_8->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_7 = new QGridLayout(page);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_18 = new QLabel(page);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_6->addWidget(label_18);

        SerialPort_Tow = new QSpinBox(page);
        SerialPort_Tow->setObjectName(QString::fromUtf8("SerialPort_Tow"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialPort_Tow->sizePolicy().hasHeightForWidth());
        SerialPort_Tow->setSizePolicy(sizePolicy);
        SerialPort_Tow->setMinimum(1);
        SerialPort_Tow->setValue(2);

        horizontalLayout_6->addWidget(SerialPort_Tow);


        gridLayout_7->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_17 = new QLabel(page);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_5->addWidget(label_17);

        SerialPort_One = new QSpinBox(page);
        SerialPort_One->setObjectName(QString::fromUtf8("SerialPort_One"));
        sizePolicy.setHeightForWidth(SerialPort_One->sizePolicy().hasHeightForWidth());
        SerialPort_One->setSizePolicy(sizePolicy);
        SerialPort_One->setMinimum(1);

        horizontalLayout_5->addWidget(SerialPort_One);


        gridLayout_7->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        SerialAddr_One = new QLineEdit(page_2);
        SerialAddr_One->setObjectName(QString::fromUtf8("SerialAddr_One"));

        horizontalLayout_9->addWidget(SerialAddr_One);


        gridLayout_3->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        SerialAddr_Tow = new QLineEdit(page_2);
        SerialAddr_Tow->setObjectName(QString::fromUtf8("SerialAddr_Tow"));

        horizontalLayout_10->addWidget(SerialAddr_Tow);


        gridLayout_3->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_11->addWidget(label_3);

        Port_One = new QSpinBox(page_2);
        Port_One->setObjectName(QString::fromUtf8("Port_One"));

        horizontalLayout_11->addWidget(Port_One);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_12->addWidget(label_5);

        Port_Tow = new QSpinBox(page_2);
        Port_Tow->setObjectName(QString::fromUtf8("Port_Tow"));

        horizontalLayout_12->addWidget(Port_Tow);


        gridLayout_3->addLayout(horizontalLayout_12, 1, 1, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_10 = new QGridLayout(page_3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_24 = new QLabel(page_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_10->addWidget(label_24, 0, 0, 1, 1);

        SerialAddr_One_2 = new QLineEdit(page_3);
        SerialAddr_One_2->setObjectName(QString::fromUtf8("SerialAddr_One_2"));

        gridLayout_10->addWidget(SerialAddr_One_2, 0, 1, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout_4->addWidget(stackedWidget, 1, 0, 1, 1);

        ControllerSignalMode = new QComboBox(groupBox_2);
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->addItem(QString());
        ControllerSignalMode->setObjectName(QString::fromUtf8("ControllerSignalMode"));

        gridLayout_4->addWidget(ControllerSignalMode, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_13 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setFlat(true);
        gridLayout_23 = new QGridLayout(groupBox_13);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        SerialPortOpenState = new QRadioButton(groupBox_13);
        SerialPortOpenState->setObjectName(QString::fromUtf8("SerialPortOpenState"));
        SerialPortOpenState->setChecked(false);

        gridLayout_23->addWidget(SerialPortOpenState, 0, 0, 1, 1);

        SerialPortCloseState = new QRadioButton(groupBox_13);
        SerialPortCloseState->setObjectName(QString::fromUtf8("SerialPortCloseState"));
        SerialPortCloseState->setChecked(true);

        gridLayout_23->addWidget(SerialPortCloseState, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_13, 2, 0, 1, 1);

        groupBox_15 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setFlat(true);
        groupBox_15->setCheckable(false);
        gridLayout_25 = new QGridLayout(groupBox_15);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        SerialPortOpenState_3 = new QCheckBox(groupBox_15);
        SerialPortOpenState_3->setObjectName(QString::fromUtf8("SerialPortOpenState_3"));
        SerialPortOpenState_3->setChecked(true);

        gridLayout_25->addWidget(SerialPortOpenState_3, 0, 0, 1, 1);

        SerialPortCloseState_3 = new QCheckBox(groupBox_15);
        SerialPortCloseState_3->setObjectName(QString::fromUtf8("SerialPortCloseState_3"));
        SerialPortCloseState_3->setChecked(false);

        gridLayout_25->addWidget(SerialPortCloseState_3, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_15, 3, 0, 1, 1);

        groupBox_14 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setFlat(true);
        gridLayout_24 = new QGridLayout(groupBox_14);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        SerialPortOpenState_2 = new QRadioButton(groupBox_14);
        SerialPortOpenState_2->setObjectName(QString::fromUtf8("SerialPortOpenState_2"));
        SerialPortOpenState_2->setChecked(true);

        gridLayout_24->addWidget(SerialPortOpenState_2, 0, 0, 1, 1);

        SerialPortCloseState_2 = new QRadioButton(groupBox_14);
        SerialPortCloseState_2->setObjectName(QString::fromUtf8("SerialPortCloseState_2"));
        SerialPortCloseState_2->setChecked(false);

        gridLayout_24->addWidget(SerialPortCloseState_2, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_14, 4, 0, 1, 1);

        groupBox_16 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox_16);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(50);
        gridLayout_5->setVerticalSpacing(20);
        SerialPortOpenState_5 = new QCheckBox(groupBox_16);
        SerialPortOpenState_5->setObjectName(QString::fromUtf8("SerialPortOpenState_5"));
        SerialPortOpenState_5->setChecked(false);

        gridLayout_5->addWidget(SerialPortOpenState_5, 0, 0, 1, 1);

        SerialPortOpenState_7 = new QCheckBox(groupBox_16);
        SerialPortOpenState_7->setObjectName(QString::fromUtf8("SerialPortOpenState_7"));
        SerialPortOpenState_7->setChecked(false);

        gridLayout_5->addWidget(SerialPortOpenState_7, 0, 2, 1, 1);

        SerialPortOpenState_6 = new QCheckBox(groupBox_16);
        SerialPortOpenState_6->setObjectName(QString::fromUtf8("SerialPortOpenState_6"));
        SerialPortOpenState_6->setChecked(false);

        gridLayout_5->addWidget(SerialPortOpenState_6, 0, 1, 1, 1);

        SerialPortOpenState_8 = new QCheckBox(groupBox_16);
        SerialPortOpenState_8->setObjectName(QString::fromUtf8("SerialPortOpenState_8"));
        SerialPortOpenState_8->setChecked(false);

        gridLayout_5->addWidget(SerialPortOpenState_8, 0, 3, 1, 1);


        gridLayout_8->addWidget(groupBox_16, 5, 0, 1, 1);

        groupBox_17 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setFlat(true);
        gridLayout_6 = new QGridLayout(groupBox_17);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(50);
        gridLayout_6->setVerticalSpacing(20);
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        SerialPortOpenState_12 = new QCheckBox(groupBox_17);
        SerialPortOpenState_12->setObjectName(QString::fromUtf8("SerialPortOpenState_12"));
        SerialPortOpenState_12->setChecked(false);

        gridLayout_6->addWidget(SerialPortOpenState_12, 0, 1, 1, 1);

        SerialPortOpenState_13 = new QCheckBox(groupBox_17);
        SerialPortOpenState_13->setObjectName(QString::fromUtf8("SerialPortOpenState_13"));
        SerialPortOpenState_13->setChecked(false);

        gridLayout_6->addWidget(SerialPortOpenState_13, 0, 2, 1, 1);

        SerialPortOpenState_11 = new QCheckBox(groupBox_17);
        SerialPortOpenState_11->setObjectName(QString::fromUtf8("SerialPortOpenState_11"));
        SerialPortOpenState_11->setChecked(false);

        gridLayout_6->addWidget(SerialPortOpenState_11, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_17, 6, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(true);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(50);
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        Channel_Number = new QSpinBox(groupBox_3);
        Channel_Number->setObjectName(QString::fromUtf8("Channel_Number"));
        sizePolicy.setHeightForWidth(Channel_Number->sizePolicy().hasHeightForWidth());
        Channel_Number->setSizePolicy(sizePolicy);
        Channel_Number->setAlignment(Qt::AlignCenter);
        Channel_Number->setMinimum(0);

        gridLayout_2->addWidget(Channel_Number, 1, 0, 1, 1);

        Container_Camera_Model = new QComboBox(groupBox_3);
        Container_Camera_Model->addItem(QString());
        Container_Camera_Model->addItem(QString());
        Container_Camera_Model->addItem(QString());
        Container_Camera_Model->setObjectName(QString::fromUtf8("Container_Camera_Model"));
        sizePolicy.setHeightForWidth(Container_Camera_Model->sizePolicy().hasHeightForWidth());
        Container_Camera_Model->setSizePolicy(sizePolicy);
        Container_Camera_Model->setDuplicatesEnabled(false);
        Container_Camera_Model->setFrame(false);

        gridLayout_2->addWidget(Container_Camera_Model, 6, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_2->setDecimals(1);

        gridLayout_2->addWidget(doubleSpinBox_2, 3, 0, 1, 1);

        Alias = new QLineEdit(groupBox_3);
        Alias->setObjectName(QString::fromUtf8("Alias"));
        Alias->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Alias, 0, 0, 1, 1);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setWordWrap(true);

        gridLayout_2->addWidget(label_43, 9, 1, 1, 1);

        Camera_Load_Plugin_comboBox_2 = new QComboBox(groupBox_3);
        Camera_Load_Plugin_comboBox_2->addItem(QString());
        Camera_Load_Plugin_comboBox_2->addItem(QString());
        Camera_Load_Plugin_comboBox_2->setObjectName(QString::fromUtf8("Camera_Load_Plugin_comboBox_2"));

        gridLayout_2->addWidget(Camera_Load_Plugin_comboBox_2, 8, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(3);

        gridLayout_2->addWidget(spinBox, 4, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        doubleSpinBox->setDecimals(1);

        gridLayout_2->addWidget(doubleSpinBox, 2, 0, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setWordWrap(true);

        gridLayout_2->addWidget(label_20, 6, 1, 1, 1);

        label_42 = new QLabel(groupBox_3);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setWordWrap(true);

        gridLayout_2->addWidget(label_42, 8, 1, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setWordWrap(true);

        gridLayout_2->addWidget(label_21, 7, 1, 1, 1);

        Plate_Camera_Model = new QComboBox(groupBox_3);
        Plate_Camera_Model->addItem(QString());
        Plate_Camera_Model->addItem(QString());
        Plate_Camera_Model->setObjectName(QString::fromUtf8("Plate_Camera_Model"));
        sizePolicy.setHeightForWidth(Plate_Camera_Model->sizePolicy().hasHeightForWidth());
        Plate_Camera_Model->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Plate_Camera_Model, 7, 0, 1, 1);

        HCNET_Capture_Type_comboBox_2 = new QComboBox(groupBox_3);
        HCNET_Capture_Type_comboBox_2->addItem(QString());
        HCNET_Capture_Type_comboBox_2->addItem(QString());
        HCNET_Capture_Type_comboBox_2->addItem(QString());
        HCNET_Capture_Type_comboBox_2->addItem(QString());
        HCNET_Capture_Type_comboBox_2->addItem(QString());
        HCNET_Capture_Type_comboBox_2->setObjectName(QString::fromUtf8("HCNET_Capture_Type_comboBox_2"));

        gridLayout_2->addWidget(HCNET_Capture_Type_comboBox_2, 9, 0, 1, 1);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setWordWrap(true);

        gridLayout_2->addWidget(label_27, 0, 1, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setWordWrap(true);

        gridLayout_2->addWidget(label_28, 1, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setWordWrap(true);

        gridLayout_2->addWidget(label_8, 3, 1, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setWordWrap(true);

        gridLayout_2->addWidget(label_19, 4, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_8->addWidget(groupBox_3, 7, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_9->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Channel_Setting_Form);
        QObject::connect(ControllerSignalMode, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Channel_Setting_Form);
    } // setupUi

    void retranslateUi(QWidget *Channel_Setting_Form)
    {
        Channel_Setting_Form->setWindowTitle(QApplication::translate("Channel_Setting_Form", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Channel_Setting_Form", "Camera", nullptr));
        label_11->setText(QApplication::translate("Channel_Setting_Form", "Front", nullptr));
        label_16->setText(QApplication::translate("Channel_Setting_Form", "Left", nullptr));
        label_9->setText(QApplication::translate("Channel_Setting_Form", "Top", nullptr));
        label_25->setText(QApplication::translate("Channel_Setting_Form", "Front view", nullptr));
        label_26->setText(QApplication::translate("Channel_Setting_Form", "End view", nullptr));
        label_6->setText(QApplication::translate("Channel_Setting_Form", "Local Addr", nullptr));
        Camera_Front->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Left->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Top->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Prospects->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Forground->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        LocalAddr->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_14->setText(QApplication::translate("Channel_Setting_Form", "After", nullptr));
        label_10->setText(QApplication::translate("Channel_Setting_Form", "Right", nullptr));
        label_15->setText(QApplication::translate("Channel_Setting_Form", "Plate", nullptr));
        label_13->setText(QApplication::translate("Channel_Setting_Form", "User", nullptr));
        label_12->setText(QApplication::translate("Channel_Setting_Form", "Password", nullptr));
        Camera_After->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Right->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_Plate->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        Camera_User->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "admin", nullptr));
        Camera_Password->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "ABCabc123", nullptr));
        groupBox_2->setTitle(QApplication::translate("Channel_Setting_Form", "Serial interface mode", nullptr));
        label_18->setText(QApplication::translate("Channel_Setting_Form", "Serial port 2", nullptr));
        SerialPort_Tow->setPrefix(QApplication::translate("Channel_Setting_Form", "COM", nullptr));
        label_17->setText(QApplication::translate("Channel_Setting_Form", "Serial port 1", nullptr));
        SerialPort_One->setSuffix(QString());
        SerialPort_One->setPrefix(QApplication::translate("Channel_Setting_Form", "COM", nullptr));
        label_2->setText(QApplication::translate("Channel_Setting_Form", "Address1", nullptr));
        SerialAddr_One->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        label_4->setText(QApplication::translate("Channel_Setting_Form", "Address2", nullptr));
        SerialAddr_Tow->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        SerialAddr_Tow->setText(QApplication::translate("Channel_Setting_Form", "...", nullptr));
        label_3->setText(QApplication::translate("Channel_Setting_Form", "Port1", nullptr));
        label_5->setText(QApplication::translate("Channel_Setting_Form", "Port2", nullptr));
        label_24->setText(QApplication::translate("Channel_Setting_Form", "Address", nullptr));
        SerialAddr_One_2->setInputMask(QApplication::translate("Channel_Setting_Form", "000.000.000.000;_", nullptr));
        ControllerSignalMode->setItemText(0, QApplication::translate("Channel_Setting_Form", "Serial Port", nullptr));
        ControllerSignalMode->setItemText(1, QApplication::translate("Channel_Setting_Form", "Moxa Tcp Server", nullptr));
        ControllerSignalMode->setItemText(2, QApplication::translate("Channel_Setting_Form", "IO controller", nullptr));

        groupBox_13->setTitle(QApplication::translate("Channel_Setting_Form", "Controller signal mode", nullptr));
        SerialPortOpenState->setText(QApplication::translate("Channel_Setting_Form", "Normally open", nullptr));
        SerialPortCloseState->setText(QApplication::translate("Channel_Setting_Form", "Normally closed", nullptr));
        groupBox_15->setTitle(QApplication::translate("Channel_Setting_Form", "recognition", nullptr));
        SerialPortOpenState_3->setText(QApplication::translate("Channel_Setting_Form", "Container number", nullptr));
        SerialPortCloseState_3->setText(QApplication::translate("Channel_Setting_Form", "The license plate", nullptr));
        groupBox_14->setTitle(QApplication::translate("Channel_Setting_Form", "License plate trigger mode", nullptr));
        SerialPortOpenState_2->setText(QApplication::translate("Channel_Setting_Form", "Video identification", nullptr));
        SerialPortCloseState_2->setText(QApplication::translate("Channel_Setting_Form", "Signal trigger", nullptr));
        groupBox_16->setTitle(QApplication::translate("Channel_Setting_Form", "Infrared signal shielding", nullptr));
        SerialPortOpenState_5->setText(QApplication::translate("Channel_Setting_Form", "A1", nullptr));
        SerialPortOpenState_7->setText(QApplication::translate("Channel_Setting_Form", "B1", nullptr));
        SerialPortOpenState_6->setText(QApplication::translate("Channel_Setting_Form", "A2", nullptr));
        SerialPortOpenState_8->setText(QApplication::translate("Channel_Setting_Form", "B2", nullptr));
        groupBox_17->setTitle(QApplication::translate("Channel_Setting_Form", "Container residue inspection", nullptr));
        SerialPortOpenState_12->setText(QApplication::translate("Channel_Setting_Form", "Right", nullptr));
        SerialPortOpenState_13->setText(QApplication::translate("Channel_Setting_Form", "Top", nullptr));
        SerialPortOpenState_11->setText(QApplication::translate("Channel_Setting_Form", "Left", nullptr));
        groupBox_3->setTitle(QApplication::translate("Channel_Setting_Form", "Other", nullptr));
        Container_Camera_Model->setItemText(0, QApplication::translate("Channel_Setting_Form", "hcnet", nullptr));
        Container_Camera_Model->setItemText(1, QApplication::translate("Channel_Setting_Form", "dahua", nullptr));
        Container_Camera_Model->setItemText(2, QApplication::translate("Channel_Setting_Form", "custom", nullptr));

        Alias->setPlaceholderText(QApplication::translate("Channel_Setting_Form", "Container access gate", nullptr));
        label_43->setText(QApplication::translate("Channel_Setting_Form", "Haikang camera capture mode, this option and plug-in mode associated", nullptr));
        Camera_Load_Plugin_comboBox_2->setItemText(0, QApplication::translate("Channel_Setting_Form", "A single instance", nullptr));
        Camera_Load_Plugin_comboBox_2->setItemText(1, QApplication::translate("Channel_Setting_Form", "Multiple instances", nullptr));

        label_20->setText(QApplication::translate("Channel_Setting_Form", "Container recognition camera type", nullptr));
        label_42->setText(QApplication::translate("Channel_Setting_Form", "Haikang Camera Snap Plug-in Mode, some modes require a single class.", nullptr));
        label_21->setText(QApplication::translate("Channel_Setting_Form", "Type of license plate camera", nullptr));
        Plate_Camera_Model->setItemText(0, QApplication::translate("Channel_Setting_Form", "hikvision", nullptr));
        Plate_Camera_Model->setItemText(1, QApplication::translate("Channel_Setting_Form", "WTY", nullptr));

        HCNET_Capture_Type_comboBox_2->setItemText(0, QApplication::translate("Channel_Setting_Form", "Catch the memory", nullptr));
        HCNET_Capture_Type_comboBox_2->setItemText(1, QApplication::translate("Channel_Setting_Form", "Manual trigger snap (test)", nullptr));
        HCNET_Capture_Type_comboBox_2->setItemText(2, QApplication::translate("Channel_Setting_Form", "CallBack Take the result(An instance)", nullptr));
        HCNET_Capture_Type_comboBox_2->setItemText(3, QApplication::translate("Channel_Setting_Form", "Video take figure", nullptr));
        HCNET_Capture_Type_comboBox_2->setItemText(4, QApplication::translate("Channel_Setting_Form", "The underlying capture", nullptr));

        label_27->setText(QApplication::translate("Channel_Setting_Form", "Channel alias, the main page prompt.", nullptr));
        label_28->setText(QApplication::translate("Channel_Setting_Form", "The channel number that distinguishes the channel data.", nullptr));
        label->setText(QApplication::translate("Channel_Setting_Form", "A1 infrared release, how many seconds to capture the picture", nullptr));
        label_8->setText(QApplication::translate("Channel_Setting_Form", "B1 infrared release, how many seconds to capture the picture", nullptr));
        label_19->setText(QApplication::translate("Channel_Setting_Form", "Number of car capture recognition", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Channel_Setting_Form: public Ui_Channel_Setting_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_SETTING_FORM_H
