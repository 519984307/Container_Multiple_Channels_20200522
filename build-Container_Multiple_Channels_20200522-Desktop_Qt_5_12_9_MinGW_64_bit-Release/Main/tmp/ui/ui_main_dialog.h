/********************************************************************************
** Form generated from reading UI file 'main_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_DIALOG_H
#define UI_MAIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Main_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter;
    QLabel *label;
    QSpinBox *ChannelNumber;
    QSpacerItem *horizontalSpacer_3;
    QSplitter *splitter_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QSplitter *splitter_3;
    QLabel *label_7;
    QComboBox *language_comboBox;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *verLabel;

    void setupUi(QDialog *Main_Dialog)
    {
        if (Main_Dialog->objectName().isEmpty())
            Main_Dialog->setObjectName(QString::fromUtf8("Main_Dialog"));
        Main_Dialog->resize(762, 350);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Dialog->setWindowIcon(icon);
        Main_Dialog->setModal(true);
        gridLayout_2 = new QGridLayout(Main_Dialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(Main_Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 80));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(101, 101, 102, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(152, 152, 153, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(126, 126, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(50, 50, 51, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(67, 67, 68, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(255, 255, 255, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        groupBox->setPalette(palette);
        groupBox->setAutoFillBackground(true);
        groupBox->setFlat(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 80));
        label_6->setMaximumSize(QSize(80, 80));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico")));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 0, 2, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 1, 2, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        splitter = new QSplitter(Main_Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        ChannelNumber = new QSpinBox(splitter);
        ChannelNumber->setObjectName(QString::fromUtf8("ChannelNumber"));
        ChannelNumber->setMinimum(1);
        ChannelNumber->setMaximum(199);
        splitter->addWidget(ChannelNumber);

        gridLayout_2->addWidget(splitter, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        splitter_2 = new QSplitter(Main_Dialog);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        splitter_2->addWidget(label_2);
        comboBox = new QComboBox(splitter_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        splitter_2->addWidget(comboBox);

        gridLayout_2->addWidget(splitter_2, 3, 1, 1, 1);

        splitter_3 = new QSplitter(Main_Dialog);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        splitter_3->addWidget(label_7);
        language_comboBox = new QComboBox(splitter_3);
        language_comboBox->addItem(QString());
        language_comboBox->addItem(QString());
        language_comboBox->setObjectName(QString::fromUtf8("language_comboBox"));
        language_comboBox->setEditable(false);
        splitter_3->addWidget(language_comboBox);

        gridLayout_2->addWidget(splitter_3, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 5, 1, 1, 1);

        pushButton = new QPushButton(Main_Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 0);"));
        pushButton->setIconSize(QSize(20, 20));
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);

        gridLayout_2->addWidget(pushButton, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(Main_Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(12);
        label_4->setFont(font2);

        horizontalLayout_3->addWidget(label_4);

        verLabel = new QLabel(Main_Dialog);
        verLabel->setObjectName(QString::fromUtf8("verLabel"));
        verLabel->setFont(font2);
        verLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(verLabel);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_3, 8, 0, 1, 3);

        QWidget::setTabOrder(pushButton, ChannelNumber);
        QWidget::setTabOrder(ChannelNumber, comboBox);
        QWidget::setTabOrder(comboBox, language_comboBox);

        retranslateUi(Main_Dialog);

        language_comboBox->setCurrentIndex(1);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Main_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Main_Dialog)
    {
        Main_Dialog->setWindowTitle(QApplication::translate("Main_Dialog", "ZBY", nullptr));
        groupBox->setTitle(QString());
        label_6->setText(QString());
        label_5->setText(QApplication::translate("Main_Dialog", "Shenzhen zhongbaiyuan technology co. LTD", nullptr));
        label->setText(QApplication::translate("Main_Dialog", "The channel number", nullptr));
        label_2->setText(QApplication::translate("Main_Dialog", "System  mode", nullptr));
        comboBox->setItemText(0, QApplication::translate("Main_Dialog", "Single page mode", nullptr));
        comboBox->setItemText(1, QApplication::translate("Main_Dialog", "Multi-page mode", nullptr));

#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("Main_Dialog", "Single-page mode saves memory, switching pages can only show subsequent captures. Previous captures do not show.\n"
"\n"
"As memory increases in multi-page mode, switching pages will display a full snapshot of the flow, so records will remain the same.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_7->setText(QApplication::translate("Main_Dialog", "Language", nullptr));
        language_comboBox->setItemText(0, QApplication::translate("Main_Dialog", "\344\270\255\346\226\207", nullptr));
        language_comboBox->setItemText(1, QApplication::translate("Main_Dialog", "English", nullptr));

        pushButton->setText(QApplication::translate("Main_Dialog", "OK", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton->setShortcut(QApplication::translate("Main_Dialog", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        label_4->setText(QApplication::translate("Main_Dialog", "version:", nullptr));
        verLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Main_Dialog: public Ui_Main_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_DIALOG_H
