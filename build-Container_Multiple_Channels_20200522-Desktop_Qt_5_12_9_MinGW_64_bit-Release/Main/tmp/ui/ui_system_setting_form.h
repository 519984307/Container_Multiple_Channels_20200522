/********************************************************************************
** Form generated from reading UI file 'system_setting_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_SETTING_FORM_H
#define UI_SYSTEM_SETTING_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_System_Setting_Form
{
public:
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Channel;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *ImgPathlineEdit;
    QPushButton *CheckPathPushButton;
    QLabel *label_4;
    QCheckBox *save_image_checkBox;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *ImgPathlineEdit_2;
    QPushButton *CheckPathPushButton_2;
    QComboBox *ImageFormat_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *camera_id_lineEdit;
    QLabel *label_40;
    QComboBox *ImageNamingRules;
    QLabel *label_26;
    QLabel *label_39;
    QLabel *label_27;
    QComboBox *ImageFormat;
    QLabel *label_24;
    QSpinBox *ChannelNumber;
    QLabel *label_25;
    QSpacerItem *verticalSpacer;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *channel_id_lineEdit;
    QLabel *label_41;
    QWidget *Model;
    QGridLayout *gridLayout_16;
    QComboBox *Camera_Load_Plugin_comboBox;
    QLabel *label_42;
    QComboBox *HCNET_Capture_Type_comboBox;
    QLabel *label_43;
    QComboBox *LogicType_comboBox;
    QLabel *label_49;
    QComboBox *PlateType_comboBox;
    QLabel *label_50;
    QSpacerItem *verticalSpacer_9;
    QWidget *Recognizer;
    QGridLayout *gridLayout_6;
    QLabel *label_28;
    QGridLayout *gridLayout_4;
    QRadioButton *ColorDisplay;
    QRadioButton *AutomaticCorrection;
    QPushButton *Contains_pushButton;
    QLineEdit *Contains_lineEdit;
    QLabel *label_19;
    QLineEdit *Eliminate_lineEdit;
    QPushButton *Eliminate_pushButton;
    QLabel *label_29;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_55;
    QComboBox *picture_size_comboBox;
    QWidget *Service;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    QRadioButton *ServerModel;
    QRadioButton *ClientModel;
    QStackedWidget *Service_Type_stackedWidget;
    QWidget *page_6;
    QGridLayout *gridLayout_28;
    QTextEdit *Address_Many_textEdit;
    QWidget *page_5;
    QGridLayout *gridLayout_11;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *Address_Singleton_lineEdit;
    QWidget *page;
    QGridLayout *gridLayout_17;
    QTextEdit *Address_Many_MQ_textEdit;
    QWidget *page_2;
    QGridLayout *gridLayout_18;
    QLineEdit *Address_Singleton_MQ_lineEdit;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_31;
    QSpacerItem *verticalSpacer_7;
    QComboBox *Identify_Protocol_comboBox_2;
    QLabel *label_32;
    QComboBox *DataChaneType_combox;
    QLabel *label_16;
    QComboBox *DataChange_Format_comboBox;
    QLabel *label_17;
    QSpinBox *plate_timeout_spinBox;
    QLabel *label_52;
    QSpinBox *container_timeout_spinBox;
    QLabel *label_53;
    QCheckBox *plate_color_checkBox;
    QLabel *label_54;
    QCheckBox *newline_checkBox;
    QLabel *label_51;
    QCheckBox *Hearbeat_checkBox;
    QLabel *label_44;
    QCheckBox *Resulting_checkBox;
    QLabel *label_45;
    QCheckBox *ShortLink_checkBox;
    QLabel *label_46;
    QCheckBox *checkBox;
    QLabel *label_48;
    QCheckBox *checkBox_2;
    QLabel *label_47;
    QComboBox *Service_Type_comboBox;
    QLabel *label_30;
    QWidget *Upload;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_8;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QComboBox *database_Type_comboBox;
    QLineEdit *database_Addr_lineEdit;
    QLineEdit *database_User_lineEdit;
    QLineEdit *database_Pass_lineEdit;
    QGroupBox *Ftp;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *FtpUser;
    QLineEdit *FtpPassword;
    QLineEdit *FtpAddress;
    QLineEdit *FtpPort;
    QLineEdit *FtpRemote;
    QLineEdit *FtpLocal;
    QCheckBox *ReduceImage;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *label_18;
    QLabel *label_10;
    QWidget *Storage;
    QGridLayout *gridLayout_10;
    QCheckBox *storageSpaceShow_checkBox;
    QCheckBox *storageSpace_monitoring_checkBox;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *storage_spinBox;
    QSlider *horizontalSlider;
    QLabel *label_34;
    QCheckBox *saveImageDay_checkBox;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *saveImageDay_spinBox;
    QSlider *horizontalSlider_2;
    QLabel *label_35;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_33;
    QSpacerItem *verticalSpacer_5;
    QWidget *Additional;
    QGridLayout *gridLayout_12;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_6;
    QLabel *label_38;
    QLabel *label_9;
    QLabel *label_36;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QSpacerItem *verticalSpacer_8;
    QSpinBox *spinBox_4;
    QLabel *label_12;
    QSpinBox *spinBox_5;
    QWidget *Other;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_14;
    QSlider *horizontalSlider_3;
    QCheckBox *DebugLog;
    QCheckBox *CaptureLog;
    QCheckBox *InfoLog;
    QSpinBox *spinBox_3;
    QCheckBox *InterfaceLog;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_15;
    QCheckBox *StartupMinimization;
    QSpinBox *DelayStart;
    QCheckBox *FullScreen;
    QCheckBox *AutomaticStart;
    QLabel *label_14;
    QComboBox *Language;
    QLabel *label_37;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *System_Setting_Form)
    {
        if (System_Setting_Form->objectName().isEmpty())
            System_Setting_Form->setObjectName(QString::fromUtf8("System_Setting_Form"));
        System_Setting_Form->setEnabled(true);
        System_Setting_Form->resize(959, 625);
        gridLayout_3 = new QGridLayout(System_Setting_Form);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(System_Setting_Form);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 914, 1009));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        Channel = new QWidget();
        Channel->setObjectName(QString::fromUtf8("Channel"));
        gridLayout_2 = new QGridLayout(Channel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(50);
        gridLayout_2->setVerticalSpacing(20);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ImgPathlineEdit = new QLineEdit(Channel);
        ImgPathlineEdit->setObjectName(QString::fromUtf8("ImgPathlineEdit"));

        horizontalLayout_6->addWidget(ImgPathlineEdit);

        CheckPathPushButton = new QPushButton(Channel);
        CheckPathPushButton->setObjectName(QString::fromUtf8("CheckPathPushButton"));
        CheckPathPushButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(CheckPathPushButton);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 0, 1, 3);

        label_4 = new QLabel(Channel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(400, 0));
        label_4->setMaximumSize(QSize(400, 16777215));
        label_4->setWordWrap(true);

        gridLayout_2->addWidget(label_4, 6, 4, 1, 1);

        save_image_checkBox = new QCheckBox(Channel);
        save_image_checkBox->setObjectName(QString::fromUtf8("save_image_checkBox"));

        gridLayout_2->addWidget(save_image_checkBox, 5, 0, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ImgPathlineEdit_2 = new QLineEdit(Channel);
        ImgPathlineEdit_2->setObjectName(QString::fromUtf8("ImgPathlineEdit_2"));
        ImgPathlineEdit_2->setEnabled(false);

        horizontalLayout_7->addWidget(ImgPathlineEdit_2);

        CheckPathPushButton_2 = new QPushButton(Channel);
        CheckPathPushButton_2->setObjectName(QString::fromUtf8("CheckPathPushButton_2"));
        CheckPathPushButton_2->setEnabled(false);
        CheckPathPushButton_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(CheckPathPushButton_2);


        gridLayout_2->addLayout(horizontalLayout_7, 6, 0, 1, 3);

        ImageFormat_2 = new QComboBox(Channel);
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->addItem(QString());
        ImageFormat_2->setObjectName(QString::fromUtf8("ImageFormat_2"));
        ImageFormat_2->setEnabled(false);
        ImageFormat_2->setEditable(false);

        gridLayout_2->addWidget(ImageFormat_2, 7, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(30);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        camera_id_lineEdit = new QLineEdit(Channel);
        camera_id_lineEdit->setObjectName(QString::fromUtf8("camera_id_lineEdit"));
        camera_id_lineEdit->setMaximumSize(QSize(50, 16777215));
        camera_id_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(camera_id_lineEdit);

        label_40 = new QLabel(Channel);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_4->addWidget(label_40);

        horizontalLayout_4->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        ImageNamingRules = new QComboBox(Channel);
        ImageNamingRules->addItem(QString());
        ImageNamingRules->addItem(QString());
        ImageNamingRules->setObjectName(QString::fromUtf8("ImageNamingRules"));
        ImageNamingRules->setEditable(false);

        gridLayout_2->addWidget(ImageNamingRules, 1, 0, 1, 3);

        label_26 = new QLabel(Channel);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(400, 0));
        label_26->setMaximumSize(QSize(400, 16777215));
        label_26->setWordWrap(true);

        gridLayout_2->addWidget(label_26, 4, 4, 1, 1);

        label_39 = new QLabel(Channel);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(400, 0));
        label_39->setMaximumSize(QSize(400, 16777215));
        label_39->setWordWrap(true);

        gridLayout_2->addWidget(label_39, 2, 4, 1, 1);

        label_27 = new QLabel(Channel);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(400, 0));
        label_27->setMaximumSize(QSize(400, 16777215));
        label_27->setWordWrap(true);

        gridLayout_2->addWidget(label_27, 7, 4, 1, 1);

        ImageFormat = new QComboBox(Channel);
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->addItem(QString());
        ImageFormat->setObjectName(QString::fromUtf8("ImageFormat"));
        ImageFormat->setEditable(false);

        gridLayout_2->addWidget(ImageFormat, 4, 0, 1, 3);

        label_24 = new QLabel(Channel);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(400, 0));
        label_24->setMaximumSize(QSize(400, 16777215));
        label_24->setWordWrap(true);

        gridLayout_2->addWidget(label_24, 1, 4, 1, 1);

        ChannelNumber = new QSpinBox(Channel);
        ChannelNumber->setObjectName(QString::fromUtf8("ChannelNumber"));
        ChannelNumber->setEnabled(true);
        ChannelNumber->setMaximumSize(QSize(16777215, 16777215));
        ChannelNumber->setFrame(true);
        ChannelNumber->setAlignment(Qt::AlignCenter);
        ChannelNumber->setMinimum(1);
        ChannelNumber->setMaximum(99);
        ChannelNumber->setValue(1);

        gridLayout_2->addWidget(ChannelNumber, 0, 0, 1, 3);

        label_25 = new QLabel(Channel);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(400, 0));
        label_25->setMaximumSize(QSize(400, 16777215));
        label_25->setWordWrap(true);

        gridLayout_2->addWidget(label_25, 3, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 276, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 1, 1, 1);

        label_15 = new QLabel(Channel);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(400, 0));
        label_15->setMaximumSize(QSize(400, 16777215));
        label_15->setWordWrap(true);

        gridLayout_2->addWidget(label_15, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(614, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 5, 2, 1, 3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        channel_id_lineEdit = new QLineEdit(Channel);
        channel_id_lineEdit->setObjectName(QString::fromUtf8("channel_id_lineEdit"));
        channel_id_lineEdit->setMaximumSize(QSize(50, 16777215));
        channel_id_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(channel_id_lineEdit);

        label_41 = new QLabel(Channel);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_5->addWidget(label_41);

        horizontalLayout_5->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_5, 2, 2, 1, 1);

        tabWidget->addTab(Channel, QString());
        Model = new QWidget();
        Model->setObjectName(QString::fromUtf8("Model"));
        gridLayout_16 = new QGridLayout(Model);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setHorizontalSpacing(50);
        gridLayout_16->setVerticalSpacing(20);
        Camera_Load_Plugin_comboBox = new QComboBox(Model);
        Camera_Load_Plugin_comboBox->addItem(QString());
        Camera_Load_Plugin_comboBox->addItem(QString());
        Camera_Load_Plugin_comboBox->setObjectName(QString::fromUtf8("Camera_Load_Plugin_comboBox"));

        gridLayout_16->addWidget(Camera_Load_Plugin_comboBox, 0, 0, 1, 1);

        label_42 = new QLabel(Model);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setMinimumSize(QSize(400, 0));
        label_42->setMaximumSize(QSize(400, 16777215));
        label_42->setWordWrap(true);

        gridLayout_16->addWidget(label_42, 0, 1, 1, 1);

        HCNET_Capture_Type_comboBox = new QComboBox(Model);
        HCNET_Capture_Type_comboBox->addItem(QString());
        HCNET_Capture_Type_comboBox->addItem(QString());
        HCNET_Capture_Type_comboBox->addItem(QString());
        HCNET_Capture_Type_comboBox->addItem(QString());
        HCNET_Capture_Type_comboBox->addItem(QString());
        HCNET_Capture_Type_comboBox->setObjectName(QString::fromUtf8("HCNET_Capture_Type_comboBox"));

        gridLayout_16->addWidget(HCNET_Capture_Type_comboBox, 1, 0, 1, 1);

        label_43 = new QLabel(Model);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMinimumSize(QSize(400, 0));
        label_43->setMaximumSize(QSize(400, 16777215));
        label_43->setWordWrap(true);

        gridLayout_16->addWidget(label_43, 1, 1, 1, 1);

        LogicType_comboBox = new QComboBox(Model);
        LogicType_comboBox->addItem(QString());
        LogicType_comboBox->addItem(QString());
        LogicType_comboBox->setObjectName(QString::fromUtf8("LogicType_comboBox"));

        gridLayout_16->addWidget(LogicType_comboBox, 2, 0, 1, 1);

        label_49 = new QLabel(Model);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMinimumSize(QSize(400, 0));
        label_49->setMaximumSize(QSize(400, 16777215));
        label_49->setWordWrap(true);

        gridLayout_16->addWidget(label_49, 2, 1, 1, 1);

        PlateType_comboBox = new QComboBox(Model);
        PlateType_comboBox->addItem(QString());
        PlateType_comboBox->addItem(QString());
        PlateType_comboBox->setObjectName(QString::fromUtf8("PlateType_comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlateType_comboBox->sizePolicy().hasHeightForWidth());
        PlateType_comboBox->setSizePolicy(sizePolicy);

        gridLayout_16->addWidget(PlateType_comboBox, 3, 0, 1, 1);

        label_50 = new QLabel(Model);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMinimumSize(QSize(400, 0));
        label_50->setMaximumSize(QSize(400, 16777215));
        label_50->setWordWrap(true);

        gridLayout_16->addWidget(label_50, 3, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_9, 4, 0, 1, 1);

        tabWidget->addTab(Model, QString());
        Recognizer = new QWidget();
        Recognizer->setObjectName(QString::fromUtf8("Recognizer"));
        gridLayout_6 = new QGridLayout(Recognizer);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(50);
        gridLayout_6->setVerticalSpacing(20);
        label_28 = new QLabel(Recognizer);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(400, 0));
        label_28->setMaximumSize(QSize(400, 16777215));
        label_28->setWordWrap(true);

        gridLayout_6->addWidget(label_28, 1, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        ColorDisplay = new QRadioButton(Recognizer);
        ColorDisplay->setObjectName(QString::fromUtf8("ColorDisplay"));
        ColorDisplay->setChecked(true);

        gridLayout_4->addWidget(ColorDisplay, 0, 0, 1, 1);

        AutomaticCorrection = new QRadioButton(Recognizer);
        AutomaticCorrection->setObjectName(QString::fromUtf8("AutomaticCorrection"));

        gridLayout_4->addWidget(AutomaticCorrection, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 0, 1, 2);

        Contains_pushButton = new QPushButton(Recognizer);
        Contains_pushButton->setObjectName(QString::fromUtf8("Contains_pushButton"));
        Contains_pushButton->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(Contains_pushButton, 1, 1, 1, 1);

        Contains_lineEdit = new QLineEdit(Recognizer);
        Contains_lineEdit->setObjectName(QString::fromUtf8("Contains_lineEdit"));

        gridLayout_6->addWidget(Contains_lineEdit, 1, 0, 1, 1);

        label_19 = new QLabel(Recognizer);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(400, 0));
        label_19->setMaximumSize(QSize(400, 16777215));
        label_19->setWordWrap(true);

        gridLayout_6->addWidget(label_19, 0, 2, 1, 1);

        Eliminate_lineEdit = new QLineEdit(Recognizer);
        Eliminate_lineEdit->setObjectName(QString::fromUtf8("Eliminate_lineEdit"));

        gridLayout_6->addWidget(Eliminate_lineEdit, 2, 0, 1, 1);

        Eliminate_pushButton = new QPushButton(Recognizer);
        Eliminate_pushButton->setObjectName(QString::fromUtf8("Eliminate_pushButton"));
        Eliminate_pushButton->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(Eliminate_pushButton, 2, 1, 1, 1);

        label_29 = new QLabel(Recognizer);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(400, 0));
        label_29->setMaximumSize(QSize(400, 16777215));
        label_29->setWordWrap(true);

        gridLayout_6->addWidget(label_29, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 4, 2, 1, 1);

        label_55 = new QLabel(Recognizer);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setMinimumSize(QSize(400, 0));
        label_55->setMaximumSize(QSize(400, 16777215));
        label_55->setWordWrap(true);

        gridLayout_6->addWidget(label_55, 3, 2, 1, 1);

        picture_size_comboBox = new QComboBox(Recognizer);
        picture_size_comboBox->addItem(QString());
        picture_size_comboBox->addItem(QString());
        picture_size_comboBox->addItem(QString());
        picture_size_comboBox->setObjectName(QString::fromUtf8("picture_size_comboBox"));

        gridLayout_6->addWidget(picture_size_comboBox, 3, 0, 1, 2);

        tabWidget->addTab(Recognizer, QString());
        Service = new QWidget();
        Service->setObjectName(QString::fromUtf8("Service"));
        gridLayout_7 = new QGridLayout(Service);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(50);
        gridLayout_7->setVerticalSpacing(20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ServerModel = new QRadioButton(Service);
        ServerModel->setObjectName(QString::fromUtf8("ServerModel"));
        ServerModel->setChecked(true);

        horizontalLayout->addWidget(ServerModel);

        ClientModel = new QRadioButton(Service);
        ClientModel->setObjectName(QString::fromUtf8("ClientModel"));
        ClientModel->setEnabled(true);

        horizontalLayout->addWidget(ClientModel);


        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 1);

        Service_Type_stackedWidget = new QStackedWidget(Service);
        Service_Type_stackedWidget->setObjectName(QString::fromUtf8("Service_Type_stackedWidget"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        gridLayout_28 = new QGridLayout(page_6);
        gridLayout_28->setSpacing(0);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        Address_Many_textEdit = new QTextEdit(page_6);
        Address_Many_textEdit->setObjectName(QString::fromUtf8("Address_Many_textEdit"));

        gridLayout_28->addWidget(Address_Many_textEdit, 0, 0, 1, 1);

        Service_Type_stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_11 = new QGridLayout(page_5);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_6, 1, 0, 1, 1);

        Address_Singleton_lineEdit = new QLineEdit(page_5);
        Address_Singleton_lineEdit->setObjectName(QString::fromUtf8("Address_Singleton_lineEdit"));

        gridLayout_11->addWidget(Address_Singleton_lineEdit, 0, 0, 1, 1);

        Service_Type_stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_17 = new QGridLayout(page);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        Address_Many_MQ_textEdit = new QTextEdit(page);
        Address_Many_MQ_textEdit->setObjectName(QString::fromUtf8("Address_Many_MQ_textEdit"));

        gridLayout_17->addWidget(Address_Many_MQ_textEdit, 0, 0, 1, 1);

        Service_Type_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_18 = new QGridLayout(page_2);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        Address_Singleton_MQ_lineEdit = new QLineEdit(page_2);
        Address_Singleton_MQ_lineEdit->setObjectName(QString::fromUtf8("Address_Singleton_MQ_lineEdit"));

        gridLayout_18->addWidget(Address_Singleton_MQ_lineEdit, 0, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_10, 1, 0, 1, 1);

        Service_Type_stackedWidget->addWidget(page_2);

        gridLayout_7->addWidget(Service_Type_stackedWidget, 2, 0, 1, 1);

        label_31 = new QLabel(Service);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(400, 0));
        label_31->setMaximumSize(QSize(400, 16777215));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_31->setWordWrap(true);

        gridLayout_7->addWidget(label_31, 2, 1, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_7, 3, 2, 1, 1);

        Identify_Protocol_comboBox_2 = new QComboBox(Service);
        Identify_Protocol_comboBox_2->addItem(QString());
        Identify_Protocol_comboBox_2->addItem(QString());
        Identify_Protocol_comboBox_2->addItem(QString());
        Identify_Protocol_comboBox_2->setObjectName(QString::fromUtf8("Identify_Protocol_comboBox_2"));

        gridLayout_7->addWidget(Identify_Protocol_comboBox_2, 4, 0, 1, 1);

        label_32 = new QLabel(Service);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(400, 0));
        label_32->setMaximumSize(QSize(400, 16777215));
        label_32->setWordWrap(true);

        gridLayout_7->addWidget(label_32, 4, 1, 1, 2);

        DataChaneType_combox = new QComboBox(Service);
        DataChaneType_combox->addItem(QString());
        DataChaneType_combox->addItem(QString());
        DataChaneType_combox->setObjectName(QString::fromUtf8("DataChaneType_combox"));

        gridLayout_7->addWidget(DataChaneType_combox, 5, 0, 1, 1);

        label_16 = new QLabel(Service);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(400, 0));
        label_16->setMaximumSize(QSize(400, 16777215));
        label_16->setWordWrap(true);

        gridLayout_7->addWidget(label_16, 5, 1, 1, 2);

        DataChange_Format_comboBox = new QComboBox(Service);
        DataChange_Format_comboBox->addItem(QString());
        DataChange_Format_comboBox->addItem(QString());
        DataChange_Format_comboBox->addItem(QString());
        DataChange_Format_comboBox->setObjectName(QString::fromUtf8("DataChange_Format_comboBox"));

        gridLayout_7->addWidget(DataChange_Format_comboBox, 6, 0, 1, 1);

        label_17 = new QLabel(Service);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(400, 0));
        label_17->setMaximumSize(QSize(400, 16777215));
        label_17->setWordWrap(true);

        gridLayout_7->addWidget(label_17, 6, 1, 1, 2);

        plate_timeout_spinBox = new QSpinBox(Service);
        plate_timeout_spinBox->setObjectName(QString::fromUtf8("plate_timeout_spinBox"));
        plate_timeout_spinBox->setMinimum(0);

        gridLayout_7->addWidget(plate_timeout_spinBox, 7, 0, 1, 1);

        label_52 = new QLabel(Service);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMinimumSize(QSize(400, 0));
        label_52->setMaximumSize(QSize(400, 16777215));
        label_52->setWordWrap(true);

        gridLayout_7->addWidget(label_52, 7, 1, 1, 2);

        container_timeout_spinBox = new QSpinBox(Service);
        container_timeout_spinBox->setObjectName(QString::fromUtf8("container_timeout_spinBox"));
        container_timeout_spinBox->setValue(15);

        gridLayout_7->addWidget(container_timeout_spinBox, 8, 0, 1, 1);

        label_53 = new QLabel(Service);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setMinimumSize(QSize(400, 0));
        label_53->setMaximumSize(QSize(400, 16777215));
        label_53->setWordWrap(true);

        gridLayout_7->addWidget(label_53, 8, 1, 1, 2);

        plate_color_checkBox = new QCheckBox(Service);
        plate_color_checkBox->setObjectName(QString::fromUtf8("plate_color_checkBox"));

        gridLayout_7->addWidget(plate_color_checkBox, 9, 0, 1, 1);

        label_54 = new QLabel(Service);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setMinimumSize(QSize(400, 0));
        label_54->setMaximumSize(QSize(400, 16777215));

        gridLayout_7->addWidget(label_54, 9, 1, 1, 1);

        newline_checkBox = new QCheckBox(Service);
        newline_checkBox->setObjectName(QString::fromUtf8("newline_checkBox"));

        gridLayout_7->addWidget(newline_checkBox, 10, 0, 1, 1);

        label_51 = new QLabel(Service);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(400, 0));
        label_51->setMaximumSize(QSize(400, 16777215));
        label_51->setWordWrap(true);

        gridLayout_7->addWidget(label_51, 10, 1, 1, 2);

        Hearbeat_checkBox = new QCheckBox(Service);
        Hearbeat_checkBox->setObjectName(QString::fromUtf8("Hearbeat_checkBox"));
        Hearbeat_checkBox->setChecked(true);

        gridLayout_7->addWidget(Hearbeat_checkBox, 11, 0, 1, 1);

        label_44 = new QLabel(Service);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMinimumSize(QSize(400, 0));
        label_44->setMaximumSize(QSize(400, 16777215));
        label_44->setWordWrap(true);

        gridLayout_7->addWidget(label_44, 11, 1, 1, 2);

        Resulting_checkBox = new QCheckBox(Service);
        Resulting_checkBox->setObjectName(QString::fromUtf8("Resulting_checkBox"));
        Resulting_checkBox->setChecked(true);

        gridLayout_7->addWidget(Resulting_checkBox, 12, 0, 1, 1);

        label_45 = new QLabel(Service);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMinimumSize(QSize(400, 0));
        label_45->setMaximumSize(QSize(400, 16777215));
        label_45->setWordWrap(true);

        gridLayout_7->addWidget(label_45, 12, 1, 1, 2);

        ShortLink_checkBox = new QCheckBox(Service);
        ShortLink_checkBox->setObjectName(QString::fromUtf8("ShortLink_checkBox"));

        gridLayout_7->addWidget(ShortLink_checkBox, 13, 0, 1, 1);

        label_46 = new QLabel(Service);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMinimumSize(QSize(400, 0));
        label_46->setMaximumSize(QSize(400, 16777215));
        label_46->setWordWrap(true);

        gridLayout_7->addWidget(label_46, 13, 1, 1, 2);

        checkBox = new QCheckBox(Service);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_7->addWidget(checkBox, 14, 0, 1, 1);

        label_48 = new QLabel(Service);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setMinimumSize(QSize(400, 0));
        label_48->setMaximumSize(QSize(400, 16777215));
        label_48->setWordWrap(true);

        gridLayout_7->addWidget(label_48, 14, 1, 1, 2);

        checkBox_2 = new QCheckBox(Service);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_7->addWidget(checkBox_2, 15, 0, 1, 1);

        label_47 = new QLabel(Service);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMinimumSize(QSize(400, 0));
        label_47->setMaximumSize(QSize(400, 16777215));
        label_47->setWordWrap(true);

        gridLayout_7->addWidget(label_47, 15, 1, 1, 2);

        Service_Type_comboBox = new QComboBox(Service);
        Service_Type_comboBox->addItem(QString());
        Service_Type_comboBox->addItem(QString());
        Service_Type_comboBox->setObjectName(QString::fromUtf8("Service_Type_comboBox"));

        gridLayout_7->addWidget(Service_Type_comboBox, 1, 0, 1, 1);

        label_30 = new QLabel(Service);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(400, 0));
        label_30->setMaximumSize(QSize(400, 16777215));
        label_30->setWordWrap(true);

        gridLayout_7->addWidget(label_30, 0, 1, 1, 2);

        tabWidget->addTab(Service, QString());
        Upload = new QWidget();
        Upload->setObjectName(QString::fromUtf8("Upload"));
        gridLayout_9 = new QGridLayout(Upload);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(50);
        gridLayout_9->setVerticalSpacing(20);
        verticalSpacer_4 = new QSpacerItem(15, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_4, 2, 0, 1, 1);

        groupBox_15 = new QGroupBox(Upload);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_8 = new QGridLayout(groupBox_15);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(50);
        gridLayout_8->setVerticalSpacing(15);
        label_20 = new QLabel(groupBox_15);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_8->addWidget(label_20, 0, 0, 1, 1);

        label_21 = new QLabel(groupBox_15);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_8->addWidget(label_21, 1, 0, 1, 1);

        label_22 = new QLabel(groupBox_15);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_8->addWidget(label_22, 2, 0, 1, 1);

        label_23 = new QLabel(groupBox_15);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_8->addWidget(label_23, 3, 0, 1, 1);

        database_Type_comboBox = new QComboBox(groupBox_15);
        database_Type_comboBox->addItem(QString());
        database_Type_comboBox->addItem(QString());
        database_Type_comboBox->setObjectName(QString::fromUtf8("database_Type_comboBox"));

        gridLayout_8->addWidget(database_Type_comboBox, 0, 1, 1, 2);

        database_Addr_lineEdit = new QLineEdit(groupBox_15);
        database_Addr_lineEdit->setObjectName(QString::fromUtf8("database_Addr_lineEdit"));

        gridLayout_8->addWidget(database_Addr_lineEdit, 1, 1, 1, 2);

        database_User_lineEdit = new QLineEdit(groupBox_15);
        database_User_lineEdit->setObjectName(QString::fromUtf8("database_User_lineEdit"));

        gridLayout_8->addWidget(database_User_lineEdit, 2, 1, 1, 2);

        database_Pass_lineEdit = new QLineEdit(groupBox_15);
        database_Pass_lineEdit->setObjectName(QString::fromUtf8("database_Pass_lineEdit"));

        gridLayout_8->addWidget(database_Pass_lineEdit, 3, 1, 1, 2);

        gridLayout_8->setColumnStretch(2, 1);

        gridLayout_9->addWidget(groupBox_15, 1, 0, 1, 1);

        Ftp = new QGroupBox(Upload);
        Ftp->setObjectName(QString::fromUtf8("Ftp"));
        Ftp->setFlat(false);
        Ftp->setCheckable(true);
        Ftp->setChecked(false);
        gridLayout_5 = new QGridLayout(Ftp);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(50);
        gridLayout_5->setVerticalSpacing(15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        FtpUser = new QLineEdit(Ftp);
        FtpUser->setObjectName(QString::fromUtf8("FtpUser"));

        verticalLayout_2->addWidget(FtpUser);

        FtpPassword = new QLineEdit(Ftp);
        FtpPassword->setObjectName(QString::fromUtf8("FtpPassword"));

        verticalLayout_2->addWidget(FtpPassword);

        FtpAddress = new QLineEdit(Ftp);
        FtpAddress->setObjectName(QString::fromUtf8("FtpAddress"));

        verticalLayout_2->addWidget(FtpAddress);

        FtpPort = new QLineEdit(Ftp);
        FtpPort->setObjectName(QString::fromUtf8("FtpPort"));

        verticalLayout_2->addWidget(FtpPort);

        FtpRemote = new QLineEdit(Ftp);
        FtpRemote->setObjectName(QString::fromUtf8("FtpRemote"));

        verticalLayout_2->addWidget(FtpRemote);

        FtpLocal = new QLineEdit(Ftp);
        FtpLocal->setObjectName(QString::fromUtf8("FtpLocal"));

        verticalLayout_2->addWidget(FtpLocal);


        gridLayout_5->addLayout(verticalLayout_2, 0, 1, 1, 1);

        ReduceImage = new QCheckBox(Ftp);
        ReduceImage->setObjectName(QString::fromUtf8("ReduceImage"));

        gridLayout_5->addWidget(ReduceImage, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Ftp);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Ftp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Ftp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(Ftp);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(Ftp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(Ftp);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);

        comboBox = new QComboBox(Ftp);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);

        gridLayout_5->addWidget(comboBox, 1, 1, 1, 1);


        gridLayout_9->addWidget(Ftp, 0, 0, 1, 1);

        label_18 = new QLabel(Upload);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(400, 0));
        label_18->setMaximumSize(QSize(400, 16777215));
        label_18->setWordWrap(true);

        gridLayout_9->addWidget(label_18, 0, 1, 1, 1);

        label_10 = new QLabel(Upload);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(400, 0));
        label_10->setMaximumSize(QSize(400, 16777215));
        label_10->setWordWrap(true);

        gridLayout_9->addWidget(label_10, 1, 1, 1, 1);

        tabWidget->addTab(Upload, QString());
        Storage = new QWidget();
        Storage->setObjectName(QString::fromUtf8("Storage"));
        gridLayout_10 = new QGridLayout(Storage);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setHorizontalSpacing(50);
        gridLayout_10->setVerticalSpacing(20);
        storageSpaceShow_checkBox = new QCheckBox(Storage);
        storageSpaceShow_checkBox->setObjectName(QString::fromUtf8("storageSpaceShow_checkBox"));

        gridLayout_10->addWidget(storageSpaceShow_checkBox, 0, 0, 1, 1);

        storageSpace_monitoring_checkBox = new QCheckBox(Storage);
        storageSpace_monitoring_checkBox->setObjectName(QString::fromUtf8("storageSpace_monitoring_checkBox"));

        gridLayout_10->addWidget(storageSpace_monitoring_checkBox, 1, 0, 1, 1);

        label_11 = new QLabel(Storage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(400, 0));
        label_11->setMaximumSize(QSize(400, 16777215));
        label_11->setWordWrap(true);

        gridLayout_10->addWidget(label_11, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        storage_spinBox = new QSpinBox(Storage);
        storage_spinBox->setObjectName(QString::fromUtf8("storage_spinBox"));
        storage_spinBox->setEnabled(false);
        storage_spinBox->setMaximumSize(QSize(80, 16777215));
        storage_spinBox->setFrame(false);
        storage_spinBox->setReadOnly(true);
        storage_spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        storage_spinBox->setMinimum(50);
        storage_spinBox->setValue(85);

        horizontalLayout_8->addWidget(storage_spinBox);

        horizontalSlider = new QSlider(Storage);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setMinimum(50);
        horizontalSlider->setValue(85);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(0);

        horizontalLayout_8->addWidget(horizontalSlider);


        gridLayout_10->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        label_34 = new QLabel(Storage);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(400, 0));
        label_34->setMaximumSize(QSize(400, 16777215));
        label_34->setWordWrap(true);

        gridLayout_10->addWidget(label_34, 2, 1, 1, 1);

        saveImageDay_checkBox = new QCheckBox(Storage);
        saveImageDay_checkBox->setObjectName(QString::fromUtf8("saveImageDay_checkBox"));

        gridLayout_10->addWidget(saveImageDay_checkBox, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        saveImageDay_spinBox = new QSpinBox(Storage);
        saveImageDay_spinBox->setObjectName(QString::fromUtf8("saveImageDay_spinBox"));
        saveImageDay_spinBox->setEnabled(false);
        saveImageDay_spinBox->setMaximumSize(QSize(80, 16777215));
        saveImageDay_spinBox->setFrame(false);
        saveImageDay_spinBox->setReadOnly(true);
        saveImageDay_spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        saveImageDay_spinBox->setMinimum(30);
        saveImageDay_spinBox->setMaximum(1000);
        saveImageDay_spinBox->setValue(30);

        horizontalLayout_9->addWidget(saveImageDay_spinBox);

        horizontalSlider_2 = new QSlider(Storage);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(false);
        horizontalSlider_2->setMinimum(30);
        horizontalSlider_2->setMaximum(1000);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setInvertedAppearance(false);
        horizontalSlider_2->setInvertedControls(false);
        horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_2->setTickInterval(0);

        horizontalLayout_9->addWidget(horizontalSlider_2);


        gridLayout_10->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        label_35 = new QLabel(Storage);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(400, 0));
        label_35->setMaximumSize(QSize(400, 16777215));
        label_35->setWordWrap(true);

        gridLayout_10->addWidget(label_35, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton = new QRadioButton(Storage);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(Storage);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_2);


        gridLayout_10->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        label_33 = new QLabel(Storage);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(400, 0));
        label_33->setMaximumSize(QSize(400, 16777215));
        label_33->setWordWrap(true);

        gridLayout_10->addWidget(label_33, 5, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 365, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_5, 6, 1, 1, 1);

        tabWidget->addTab(Storage, QString());
        Additional = new QWidget();
        Additional->setObjectName(QString::fromUtf8("Additional"));
        Additional->setEnabled(true);
        gridLayout_12 = new QGridLayout(Additional);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setHorizontalSpacing(50);
        gridLayout_12->setVerticalSpacing(20);
        lineEdit = new QLineEdit(Additional);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        gridLayout_12->addWidget(lineEdit, 1, 0, 1, 3);

        checkBox_6 = new QCheckBox(Additional);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_12->addWidget(checkBox_6, 4, 0, 1, 1);

        label_38 = new QLabel(Additional);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(400, 0));
        label_38->setMaximumSize(QSize(400, 16777215));
        label_38->setWordWrap(true);

        gridLayout_12->addWidget(label_38, 4, 3, 1, 2);

        label_9 = new QLabel(Additional);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(400, 0));
        label_9->setMaximumSize(QSize(400, 16777215));
        label_9->setWordWrap(true);

        gridLayout_12->addWidget(label_9, 2, 3, 1, 2);

        label_36 = new QLabel(Additional);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(400, 0));
        label_36->setMaximumSize(QSize(400, 16777215));
        label_36->setWordWrap(true);

        gridLayout_12->addWidget(label_36, 5, 3, 1, 2);

        checkBox_5 = new QCheckBox(Additional);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_12->addWidget(checkBox_5, 5, 0, 1, 1);

        checkBox_7 = new QCheckBox(Additional);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setEnabled(true);

        gridLayout_12->addWidget(checkBox_7, 0, 0, 1, 1);

        label_8 = new QLabel(Additional);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(400, 0));
        label_8->setMaximumSize(QSize(400, 16777215));
        label_8->setWordWrap(true);

        gridLayout_12->addWidget(label_8, 1, 3, 1, 2);

        lineEdit_6 = new QLineEdit(Additional);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);

        gridLayout_12->addWidget(lineEdit_6, 2, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_3 = new QRadioButton(Additional);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(Additional);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout_3->addWidget(radioButton_4);


        gridLayout_12->addLayout(horizontalLayout_3, 3, 0, 1, 3);

        verticalSpacer_8 = new QSpacerItem(20, 273, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_8, 6, 1, 1, 1);

        spinBox_4 = new QSpinBox(Additional);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setEnabled(false);
        spinBox_4->setMinimum(1);

        gridLayout_12->addWidget(spinBox_4, 5, 1, 1, 2);

        label_12 = new QLabel(Additional);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(400, 0));
        label_12->setMaximumSize(QSize(400, 16777215));
        label_12->setWordWrap(true);

        gridLayout_12->addWidget(label_12, 3, 3, 1, 2);

        spinBox_5 = new QSpinBox(Additional);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setEnabled(false);
        spinBox_5->setMinimum(1);

        gridLayout_12->addWidget(spinBox_5, 4, 1, 1, 2);

        tabWidget->addTab(Additional, QString());
        Other = new QWidget();
        Other->setObjectName(QString::fromUtf8("Other"));
        gridLayout_13 = new QGridLayout(Other);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setHorizontalSpacing(50);
        gridLayout_13->setVerticalSpacing(20);
        groupBox_11 = new QGroupBox(Other);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setFlat(false);
        gridLayout_14 = new QGridLayout(groupBox_11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setHorizontalSpacing(50);
        horizontalSlider_3 = new QSlider(groupBox_11);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMinimum(30);
        horizontalSlider_3->setMaximum(180);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setInvertedAppearance(false);
        horizontalSlider_3->setInvertedControls(false);
        horizontalSlider_3->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_3->setTickInterval(0);

        gridLayout_14->addWidget(horizontalSlider_3, 4, 1, 1, 1);

        DebugLog = new QCheckBox(groupBox_11);
        DebugLog->setObjectName(QString::fromUtf8("DebugLog"));
        DebugLog->setChecked(true);

        gridLayout_14->addWidget(DebugLog, 2, 0, 1, 2);

        CaptureLog = new QCheckBox(groupBox_11);
        CaptureLog->setObjectName(QString::fromUtf8("CaptureLog"));
        CaptureLog->setChecked(true);

        gridLayout_14->addWidget(CaptureLog, 1, 0, 1, 2);

        InfoLog = new QCheckBox(groupBox_11);
        InfoLog->setObjectName(QString::fromUtf8("InfoLog"));
        InfoLog->setChecked(true);

        gridLayout_14->addWidget(InfoLog, 0, 0, 1, 2);

        spinBox_3 = new QSpinBox(groupBox_11);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximumSize(QSize(100, 16777215));
        spinBox_3->setMinimum(30);
        spinBox_3->setMaximum(180);

        gridLayout_14->addWidget(spinBox_3, 4, 0, 1, 1);

        InterfaceLog = new QCheckBox(groupBox_11);
        InterfaceLog->setObjectName(QString::fromUtf8("InterfaceLog"));

        gridLayout_14->addWidget(InterfaceLog, 3, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_11, 0, 0, 1, 2);

        label_13 = new QLabel(Other);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(400, 0));
        label_13->setMaximumSize(QSize(400, 16777215));
        label_13->setWordWrap(true);

        gridLayout_13->addWidget(label_13, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(Other);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        gridLayout_15 = new QGridLayout(groupBox_2);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        StartupMinimization = new QCheckBox(groupBox_2);
        StartupMinimization->setObjectName(QString::fromUtf8("StartupMinimization"));

        gridLayout_15->addWidget(StartupMinimization, 0, 0, 1, 1);

        DelayStart = new QSpinBox(groupBox_2);
        DelayStart->setObjectName(QString::fromUtf8("DelayStart"));
        DelayStart->setMinimum(1);
        DelayStart->setValue(10);

        gridLayout_15->addWidget(DelayStart, 3, 0, 1, 1);

        FullScreen = new QCheckBox(groupBox_2);
        FullScreen->setObjectName(QString::fromUtf8("FullScreen"));

        gridLayout_15->addWidget(FullScreen, 2, 0, 1, 1);

        AutomaticStart = new QCheckBox(groupBox_2);
        AutomaticStart->setObjectName(QString::fromUtf8("AutomaticStart"));

        gridLayout_15->addWidget(AutomaticStart, 1, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_2, 1, 0, 1, 2);

        label_14 = new QLabel(Other);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(400, 0));
        label_14->setMaximumSize(QSize(400, 16777215));
        label_14->setWordWrap(true);

        gridLayout_13->addWidget(label_14, 1, 2, 1, 1);

        Language = new QComboBox(Other);
        Language->addItem(QString());
        Language->addItem(QString());
        Language->setObjectName(QString::fromUtf8("Language"));

        gridLayout_13->addWidget(Language, 2, 0, 1, 1);

        label_37 = new QLabel(Other);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(400, 0));
        label_37->setMaximumSize(QSize(400, 16777215));
        label_37->setWordWrap(true);

        gridLayout_13->addWidget(label_37, 2, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 292, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_3, 3, 1, 1, 1);

        tabWidget->addTab(Other, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        QWidget::setTabOrder(scrollArea, ImageNamingRules);
        QWidget::setTabOrder(ImageNamingRules, ImgPathlineEdit);
        QWidget::setTabOrder(ImgPathlineEdit, CheckPathPushButton);
        QWidget::setTabOrder(CheckPathPushButton, ImageFormat);
        QWidget::setTabOrder(ImageFormat, ImgPathlineEdit_2);
        QWidget::setTabOrder(ImgPathlineEdit_2, CheckPathPushButton_2);
        QWidget::setTabOrder(CheckPathPushButton_2, ImageFormat_2);
        QWidget::setTabOrder(ImageFormat_2, Contains_lineEdit);
        QWidget::setTabOrder(Contains_lineEdit, Eliminate_lineEdit);
        QWidget::setTabOrder(Eliminate_lineEdit, Identify_Protocol_comboBox_2);
        QWidget::setTabOrder(Identify_Protocol_comboBox_2, ShortLink_checkBox);
        QWidget::setTabOrder(ShortLink_checkBox, DataChaneType_combox);
        QWidget::setTabOrder(DataChaneType_combox, Resulting_checkBox);
        QWidget::setTabOrder(Resulting_checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox);
        QWidget::setTabOrder(checkBox, Hearbeat_checkBox);
        QWidget::setTabOrder(Hearbeat_checkBox, DataChange_Format_comboBox);
        QWidget::setTabOrder(DataChange_Format_comboBox, Ftp);
        QWidget::setTabOrder(Ftp, FtpUser);
        QWidget::setTabOrder(FtpUser, FtpPassword);
        QWidget::setTabOrder(FtpPassword, FtpAddress);
        QWidget::setTabOrder(FtpAddress, FtpPort);
        QWidget::setTabOrder(FtpPort, FtpRemote);
        QWidget::setTabOrder(FtpRemote, FtpLocal);
        QWidget::setTabOrder(FtpLocal, storageSpaceShow_checkBox);
        QWidget::setTabOrder(storageSpaceShow_checkBox, InfoLog);
        QWidget::setTabOrder(InfoLog, CaptureLog);
        QWidget::setTabOrder(CaptureLog, DebugLog);
        QWidget::setTabOrder(DebugLog, spinBox_3);
        QWidget::setTabOrder(spinBox_3, horizontalSlider_3);
        QWidget::setTabOrder(horizontalSlider_3, DelayStart);
        QWidget::setTabOrder(DelayStart, AutomaticStart);
        QWidget::setTabOrder(AutomaticStart, StartupMinimization);
        QWidget::setTabOrder(StartupMinimization, FullScreen);
        QWidget::setTabOrder(FullScreen, database_Type_comboBox);
        QWidget::setTabOrder(database_Type_comboBox, database_Addr_lineEdit);
        QWidget::setTabOrder(database_Addr_lineEdit, database_User_lineEdit);
        QWidget::setTabOrder(database_User_lineEdit, database_Pass_lineEdit);
        QWidget::setTabOrder(database_Pass_lineEdit, ChannelNumber);
        QWidget::setTabOrder(ChannelNumber, save_image_checkBox);

        retranslateUi(System_Setting_Form);
        QObject::connect(storage_spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), storage_spinBox, SLOT(setValue(int)));
        QObject::connect(saveImageDay_spinBox, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), saveImageDay_spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), horizontalSlider_3, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(save_image_checkBox, SIGNAL(clicked(bool)), ImageFormat_2, SLOT(setEnabled(bool)));
        QObject::connect(save_image_checkBox, SIGNAL(clicked(bool)), ImgPathlineEdit_2, SLOT(setEnabled(bool)));
        QObject::connect(save_image_checkBox, SIGNAL(clicked(bool)), CheckPathPushButton_2, SLOT(setEnabled(bool)));
        QObject::connect(Service_Type_comboBox, SIGNAL(currentIndexChanged(int)), Service_Type_stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(ReduceImage, SIGNAL(clicked(bool)), comboBox, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_6, SIGNAL(clicked(bool)), spinBox_5, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_5, SIGNAL(clicked(bool)), spinBox_4, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_7, SIGNAL(clicked(bool)), lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_7, SIGNAL(clicked(bool)), lineEdit_6, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_7, SIGNAL(clicked(bool)), radioButton_3, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_7, SIGNAL(clicked(bool)), radioButton_4, SLOT(setEnabled(bool)));
        QObject::connect(storageSpace_monitoring_checkBox, SIGNAL(clicked(bool)), storage_spinBox, SLOT(setEnabled(bool)));
        QObject::connect(storageSpace_monitoring_checkBox, SIGNAL(clicked(bool)), horizontalSlider, SLOT(setEnabled(bool)));
        QObject::connect(saveImageDay_checkBox, SIGNAL(clicked(bool)), saveImageDay_spinBox, SLOT(setEnabled(bool)));
        QObject::connect(saveImageDay_checkBox, SIGNAL(clicked(bool)), horizontalSlider_2, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);
        Camera_Load_Plugin_comboBox->setCurrentIndex(1);
        Service_Type_stackedWidget->setCurrentIndex(0);
        Language->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(System_Setting_Form);
    } // setupUi

    void retranslateUi(QWidget *System_Setting_Form)
    {
        System_Setting_Form->setWindowTitle(QApplication::translate("System_Setting_Form", "Form", nullptr));
        ImgPathlineEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "/home/cc/", nullptr));
        CheckPathPushButton->setText(QApplication::translate("System_Setting_Form", "...", nullptr));
        label_4->setText(QApplication::translate("System_Setting_Form", "he picture saves the path, for the software third party use.", nullptr));
        save_image_checkBox->setText(QApplication::translate("System_Setting_Form", "Save Image Two", nullptr));
        ImgPathlineEdit_2->setPlaceholderText(QApplication::translate("System_Setting_Form", "/home/cc/", nullptr));
        CheckPathPushButton_2->setText(QApplication::translate("System_Setting_Form", "...", nullptr));
        ImageFormat_2->setItemText(0, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/MM/DD/", nullptr));
        ImageFormat_2->setItemText(1, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/MM/", nullptr));
        ImageFormat_2->setItemText(2, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/", nullptr));
        ImageFormat_2->setItemText(3, QApplication::translate("System_Setting_Form", "CHANNEL/", nullptr));
        ImageFormat_2->setItemText(4, QApplication::translate("System_Setting_Form", "YYYY/MM/DD/", nullptr));
        ImageFormat_2->setItemText(5, QApplication::translate("System_Setting_Form", "YYYY/MM/", nullptr));
        ImageFormat_2->setItemText(6, QApplication::translate("System_Setting_Form", "YYYY/", nullptr));
        ImageFormat_2->setItemText(7, QApplication::translate("System_Setting_Form", "/", nullptr));

        camera_id_lineEdit->setInputMask(QApplication::translate("System_Setting_Form", "D", nullptr));
        camera_id_lineEdit->setText(QApplication::translate("System_Setting_Form", "2", nullptr));
        label_40->setText(QApplication::translate("System_Setting_Form", "Camera", nullptr));
        ImageNamingRules->setItemText(0, QApplication::translate("System_Setting_Form", "DateTime-Channel-Number", nullptr));
        ImageNamingRules->setItemText(1, QApplication::translate("System_Setting_Form", "DateTime-Number-Channel", nullptr));

        label_26->setText(QApplication::translate("System_Setting_Form", "Image save format, for software use, can only save local", nullptr));
        label_39->setText(QApplication::translate("System_Setting_Form", "Number of camera number and channel number occupied (compatible with older versions)", nullptr));
        label_27->setText(QApplication::translate("System_Setting_Form", "Image saving format for software third party use.", nullptr));
        ImageFormat->setItemText(0, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/MM/DD/", nullptr));
        ImageFormat->setItemText(1, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/MM/", nullptr));
        ImageFormat->setItemText(2, QApplication::translate("System_Setting_Form", "CHANNEL/YYYY/", nullptr));
        ImageFormat->setItemText(3, QApplication::translate("System_Setting_Form", "CHANNEL/", nullptr));
        ImageFormat->setItemText(4, QApplication::translate("System_Setting_Form", "YYYY/MM/DD/", nullptr));
        ImageFormat->setItemText(5, QApplication::translate("System_Setting_Form", "YYYY/MM/", nullptr));
        ImageFormat->setItemText(6, QApplication::translate("System_Setting_Form", "YYYY/", nullptr));
        ImageFormat->setItemText(7, QApplication::translate("System_Setting_Form", "/", nullptr));

        label_24->setText(QApplication::translate("System_Setting_Form", "Set save image naming rules", nullptr));
        ChannelNumber->setPrefix(QString());
        label_25->setText(QApplication::translate("System_Setting_Form", "Image save path, for software use, can only save local", nullptr));
        label_15->setText(QApplication::translate("System_Setting_Form", "Set control channel number, quantity limit requires purchase of license from supplier", nullptr));
        channel_id_lineEdit->setInputMask(QApplication::translate("System_Setting_Form", "D", nullptr));
        channel_id_lineEdit->setText(QApplication::translate("System_Setting_Form", "2", nullptr));
        label_41->setText(QApplication::translate("System_Setting_Form", "Channel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Channel), QApplication::translate("System_Setting_Form", "Channel", nullptr));
        Camera_Load_Plugin_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "A single instance", nullptr));
        Camera_Load_Plugin_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "Multiple instances", nullptr));

        label_42->setText(QApplication::translate("System_Setting_Form", "Haikang Camera Snap Plug-in Mode, some modes require a single class.", nullptr));
        HCNET_Capture_Type_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "Catch the memory", nullptr));
        HCNET_Capture_Type_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "Manual trigger snap (test)", nullptr));
        HCNET_Capture_Type_comboBox->setItemText(2, QApplication::translate("System_Setting_Form", "CallBack Take the result(An instance)", nullptr));
        HCNET_Capture_Type_comboBox->setItemText(3, QApplication::translate("System_Setting_Form", "Video take figure", nullptr));
        HCNET_Capture_Type_comboBox->setItemText(4, QApplication::translate("System_Setting_Form", "The underlying capture", nullptr));

        label_43->setText(QApplication::translate("System_Setting_Form", "Haikang camera capture mode, this option and plug-in mode associated", nullptr));
        LogicType_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "Standard logic", nullptr));
        LogicType_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "Nanjing sanbao", nullptr));

        label_49->setText(QApplication::translate("System_Setting_Form", "Infrared logic setting, different logic infrared trigger sequence is not the same, this option needs to consult the developer!", nullptr));
        PlateType_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "hikvision", nullptr));
        PlateType_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "WTY", nullptr));

        label_50->setText(QApplication::translate("System_Setting_Form", "Type of license plate camera", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Model), QApplication::translate("System_Setting_Form", "Model", nullptr));
        label_28->setText(QApplication::translate("System_Setting_Form", "Add the prefix of container number. If the container number is clear and the prefix is wrong, the response prefix can be added for identification.", nullptr));
        ColorDisplay->setText(QApplication::translate("System_Setting_Form", "Color display", nullptr));
        AutomaticCorrection->setText(QApplication::translate("System_Setting_Form", "Automatic correction", nullptr));
        Contains_pushButton->setText(QApplication::translate("System_Setting_Form", "ADD", nullptr));
        Contains_lineEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "WDFU", nullptr));
        label_19->setText(QApplication::translate("System_Setting_Form", "Identify validation rules for results. Color displays the original result output, automatic calibration according to the algorithm, calibration (completion) the last bit.", nullptr));
        Eliminate_lineEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "CCAU", nullptr));
        Eliminate_pushButton->setText(QApplication::translate("System_Setting_Form", "DEL", nullptr));
        label_29->setText(QApplication::translate("System_Setting_Form", "Add the prefix of container number. If the container number is clear and the prefix is wrong, the response prefix can be deleted.", nullptr));
        label_55->setText(QApplication::translate("System_Setting_Form", "Identify the size of the picture, according to the machine performance selection, the larger the picture recognition speed is slower.", nullptr));
        picture_size_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "1280*720", nullptr));
        picture_size_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "1960*1080", nullptr));
        picture_size_comboBox->setItemText(2, QApplication::translate("System_Setting_Form", "768*576", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(Recognizer), QApplication::translate("System_Setting_Form", "Recognizer", nullptr));
        ServerModel->setText(QApplication::translate("System_Setting_Form", "Tcp Server", nullptr));
        ClientModel->setText(QApplication::translate("System_Setting_Form", "Tcp Client", nullptr));
        Address_Many_textEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "if(server)192.168.1.100:5000,192.168.1.100:5001,192.168.1.100:5002 if(client)192.168.1.100:5000,192.168.1.101:5000,192.168.1.102:5000", nullptr));
        Address_Singleton_lineEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "127.0.0.1:5000", nullptr));
        Address_Many_MQ_textEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "If the data interface pattern MQ: 127.0.0.1|user|pass|vhost:5672, 127.0.0.1|user|pass|vhost:", nullptr));
        Address_Singleton_MQ_lineEdit->setPlaceholderText(QApplication::translate("System_Setting_Form", "If the data interface pattern MQ: 127.0.0.1|user|pass|vhost:5672", nullptr));
        label_31->setText(QApplication::translate("System_Setting_Form", "One to one:One service corresponds to one channel, and either server mode or client mode can be set.\n"
"\n"
"\n"
"More than pair of:One service corresponds to all channels, and only the server mode can be set, One service corresponds to all channels (Need to respond to channel instruction [L|Number])", nullptr));
        Identify_Protocol_comboBox_2->setItemText(0, QApplication::translate("System_Setting_Form", "Container_number", nullptr));
        Identify_Protocol_comboBox_2->setItemText(1, QApplication::translate("System_Setting_Form", "Container_number+Plate", nullptr));
        Identify_Protocol_comboBox_2->setItemText(2, QApplication::translate("System_Setting_Form", "Container_number+Plate+Weight", nullptr));

        label_32->setText(QApplication::translate("System_Setting_Form", "Identify the data docking protocol", nullptr));
        DataChaneType_combox->setItemText(0, QApplication::translate("System_Setting_Form", "TCP", nullptr));
        DataChaneType_combox->setItemText(1, QApplication::translate("System_Setting_Form", "MQ", nullptr));

        label_16->setText(QApplication::translate("System_Setting_Form", "Identify the data docking interface", nullptr));
        DataChange_Format_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "TEXT", nullptr));
        DataChange_Format_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "JSON", nullptr));
        DataChange_Format_comboBox->setItemText(2, QApplication::translate("System_Setting_Form", "XML", nullptr));

        label_17->setText(QApplication::translate("System_Setting_Form", "Web service data format", nullptr));
        label_52->setText(QApplication::translate("System_Setting_Form", "License plate result receives timeout time", nullptr));
        label_53->setText(QApplication::translate("System_Setting_Form", "Container identification result receiving timeout", nullptr));
        plate_color_checkBox->setText(QApplication::translate("System_Setting_Form", "not plate color", nullptr));
        label_54->setText(QApplication::translate("System_Setting_Form", "The interface protocol does not require a license plate color", nullptr));
        newline_checkBox->setText(QApplication::translate("System_Setting_Form", "A newline", nullptr));
        label_51->setText(QApplication::translate("System_Setting_Form", "A newline character is added to each piece of data to form a complete line.", nullptr));
        Hearbeat_checkBox->setText(QApplication::translate("System_Setting_Form", "The heartbeat packets", nullptr));
        label_44->setText(QApplication::translate("System_Setting_Form", "The heartbeat packet is [H] and is sent every 3 seconds. Data processing needs to pay attention to the heartbeat packet!", nullptr));
        Resulting_checkBox->setText(QApplication::translate("System_Setting_Form", "Send an intermediate result set", nullptr));
        label_45->setText(QApplication::translate("System_Setting_Form", "The intermediate result set starts with [I, and is opened as required, not as the final result.", nullptr));
        ShortLink_checkBox->setText(QApplication::translate("System_Setting_Form", "Short link", nullptr));
        label_46->setText(QApplication::translate("System_Setting_Form", "The first active link to the service, a subsequent recognition result, triggering the link to the service, sending the result completed, and disconnecting again.", nullptr));
        checkBox->setText(QApplication::translate("System_Setting_Form", "Send a car signal", nullptr));
        label_48->setText(QApplication::translate("System_Setting_Form", "Vehicle entry will trigger the incoming vehicle signal, which generally works with the front-end reset processing process", nullptr));
        checkBox_2->setText(QApplication::translate("System_Setting_Form", "Send astern signal", nullptr));
        label_47->setText(QApplication::translate("System_Setting_Form", "The reversing signal will be triggered by the vehicle reversing, which is generally used with the front-end reset processing process", nullptr));
        Service_Type_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "One to one", nullptr));
        Service_Type_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "More than a pair of", nullptr));

        label_30->setText(QApplication::translate("System_Setting_Form", "Identify data docking patterns", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Service), QApplication::translate("System_Setting_Form", "Service", nullptr));
        groupBox_15->setTitle(QApplication::translate("System_Setting_Form", "Database", nullptr));
        label_20->setText(QApplication::translate("System_Setting_Form", "Database type    ", nullptr));
        label_21->setText(QApplication::translate("System_Setting_Form", "Address", nullptr));
        label_22->setText(QApplication::translate("System_Setting_Form", "User", nullptr));
        label_23->setText(QApplication::translate("System_Setting_Form", "Pass", nullptr));
        database_Type_comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "SQLite", nullptr));
        database_Type_comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "MySQL", nullptr));

        Ftp->setTitle(QApplication::translate("System_Setting_Form", "Ftp", nullptr));
        ReduceImage->setText(QApplication::translate("System_Setting_Form", "Reduce image", nullptr));
        label->setText(QApplication::translate("System_Setting_Form", "User:", nullptr));
        label_2->setText(QApplication::translate("System_Setting_Form", "Password:", nullptr));
        label_3->setText(QApplication::translate("System_Setting_Form", "Address:", nullptr));
        label_5->setText(QApplication::translate("System_Setting_Form", "Port:", nullptr));
        label_6->setText(QApplication::translate("System_Setting_Form", "remote directory:", nullptr));
        label_7->setText(QApplication::translate("System_Setting_Form", "Local directory:", nullptr));
        comboBox->setItemText(0, QApplication::translate("System_Setting_Form", "288*384", nullptr));
        comboBox->setItemText(1, QApplication::translate("System_Setting_Form", "576*768", nullptr));
        comboBox->setItemText(2, QApplication::translate("System_Setting_Form", "1024*768", nullptr));
        comboBox->setItemText(3, QApplication::translate("System_Setting_Form", "1920*1080", nullptr));

        label_18->setText(QApplication::translate("System_Setting_Form", "Upload identification picture", nullptr));
        label_10->setText(QApplication::translate("System_Setting_Form", "Software database, network database needs to be installed and started independently.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Upload), QApplication::translate("System_Setting_Form", "Upload", nullptr));
        storageSpaceShow_checkBox->setText(QApplication::translate("System_Setting_Form", "The main interface shows the storage space", nullptr));
        storageSpace_monitoring_checkBox->setText(QApplication::translate("System_Setting_Form", "Storage space monitoring", nullptr));
        label_11->setText(QApplication::translate("System_Setting_Form", "Monitor the remaining capacity of image storage hard disk space", nullptr));
        storage_spinBox->setSuffix(QApplication::translate("System_Setting_Form", "%", nullptr));
        storage_spinBox->setPrefix(QString());
        label_34->setText(QApplication::translate("System_Setting_Form", "Save the percentage of file path capacity occupied", nullptr));
        saveImageDay_checkBox->setText(QApplication::translate("System_Setting_Form", "Days to save image", nullptr));
        saveImageDay_spinBox->setSuffix(QApplication::translate("System_Setting_Form", " Day", nullptr));
        saveImageDay_spinBox->setPrefix(QString());
        label_35->setText(QApplication::translate("System_Setting_Form", "Number of days to save the file, exceeding the set value to actively delete the file", nullptr));
        radioButton->setText(QApplication::translate("System_Setting_Form", "Release the space", nullptr));
        radioButton_2->setText(QApplication::translate("System_Setting_Form", "The software prompts", nullptr));
        label_33->setText(QApplication::translate("System_Setting_Form", "Software prompts the system administrator to change hardware or manually release space", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Storage), QApplication::translate("System_Setting_Form", "Storage", nullptr));
        checkBox_6->setText(QApplication::translate("System_Setting_Form", "Display information", nullptr));
        label_38->setText(QApplication::translate("System_Setting_Form", "Provide display screen to display vehicle or specified information, and develop access equipment separately according to the situation of field equipment.", nullptr));
        label_9->setText(QApplication::translate("System_Setting_Form", "Gate control board port", nullptr));
        label_36->setText(QApplication::translate("System_Setting_Form", "To receive vehicle weight information, separate access equipment shall be developed according to the situation of field equipment.", nullptr));
        checkBox_5->setText(QApplication::translate("System_Setting_Form", "Load the pound", nullptr));
        checkBox_7->setText(QApplication::translate("System_Setting_Form", "The brake control", nullptr));
        label_8->setText(QApplication::translate("System_Setting_Form", "Address of gate control panel", nullptr));
        radioButton_3->setText(QApplication::translate("System_Setting_Form", "camera control", nullptr));
        radioButton_4->setText(QApplication::translate("System_Setting_Form", "The mainboard control", nullptr));
        spinBox_4->setSuffix(QString());
        spinBox_4->setPrefix(QApplication::translate("System_Setting_Form", "COM", nullptr));
        label_12->setText(QApplication::translate("System_Setting_Form", "Camera control gate, need hardware support.", nullptr));
        spinBox_5->setSuffix(QString());
        spinBox_5->setPrefix(QApplication::translate("System_Setting_Form", "COM", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Additional), QApplication::translate("System_Setting_Form", "Additional", nullptr));
        groupBox_11->setTitle(QApplication::translate("System_Setting_Form", "Log", nullptr));
        DebugLog->setText(QApplication::translate("System_Setting_Form", "save debug log", nullptr));
        CaptureLog->setText(QApplication::translate("System_Setting_Form", "save capture log", nullptr));
        InfoLog->setText(QApplication::translate("System_Setting_Form", "save logic log", nullptr));
        spinBox_3->setSuffix(QApplication::translate("System_Setting_Form", " Batch", nullptr));
        spinBox_3->setPrefix(QString());
        InterfaceLog->setText(QApplication::translate("System_Setting_Form", "save intrface log", nullptr));
        label_13->setText(QApplication::translate("System_Setting_Form", "Save the log days and the timeout is automatically overwritten", nullptr));
        groupBox_2->setTitle(QApplication::translate("System_Setting_Form", "Start", nullptr));
        StartupMinimization->setText(QApplication::translate("System_Setting_Form", "Startup minimization", nullptr));
        DelayStart->setSuffix(QApplication::translate("System_Setting_Form", " seconds", nullptr));
        DelayStart->setPrefix(QString());
        FullScreen->setText(QApplication::translate("System_Setting_Form", "Full screen", nullptr));
        AutomaticStart->setText(QApplication::translate("System_Setting_Form", "Automatic start", nullptr));
        label_14->setText(QApplication::translate("System_Setting_Form", "Delay startup time to ensure the loading of field equipment is completed.", nullptr));
        Language->setItemText(0, QApplication::translate("System_Setting_Form", "English", nullptr));
        Language->setItemText(1, QApplication::translate("System_Setting_Form", "Chinese", nullptr));

        label_37->setText(QApplication::translate("System_Setting_Form", "Set the system language, temporarily support Chinese and English.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Other), QApplication::translate("System_Setting_Form", "Other", nullptr));
    } // retranslateUi

};

namespace Ui {
    class System_Setting_Form: public Ui_System_Setting_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_SETTING_FORM_H
