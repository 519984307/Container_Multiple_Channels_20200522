/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QGridLayout *gridLayout_3;
    QComboBox *logic_comboBox;
    QRadioButton *correct_radioButton;
    QCheckBox *logic_checkBox;
    QCheckBox *check_checkBox;
    QSpinBox *channel_spinBox;
    QGroupBox *dateTime_groupBox;
    QGridLayout *gridLayout;
    QDateTimeEdit *start_dateTimeEdit;
    QFrame *line;
    QFrame *line_2;
    QDateTimeEdit *end_dateTimeEdit;
    QRadioButton *error_radioButton;
    QGroupBox *container_groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *front_lineEdit;
    QFrame *line_3;
    QFrame *line_4;
    QLineEdit *after_lineEdit;
    QCheckBox *channel_checkBox;
    QDialogButtonBox *buttonBox;
    QCheckBox *plate_checkBox;
    QLineEdit *plate_lineEdit;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(375, 446);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FilterDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(FilterDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(20);
        logic_comboBox = new QComboBox(FilterDialog);
        logic_comboBox->addItem(QString());
        logic_comboBox->addItem(QString());
        logic_comboBox->addItem(QString());
        logic_comboBox->addItem(QString());
        logic_comboBox->addItem(QString());
        logic_comboBox->setObjectName(QString::fromUtf8("logic_comboBox"));
        logic_comboBox->setEnabled(false);

        gridLayout_3->addWidget(logic_comboBox, 4, 1, 1, 2);

        correct_radioButton = new QRadioButton(FilterDialog);
        correct_radioButton->setObjectName(QString::fromUtf8("correct_radioButton"));
        correct_radioButton->setEnabled(false);
        correct_radioButton->setChecked(true);

        gridLayout_3->addWidget(correct_radioButton, 6, 1, 1, 1);

        logic_checkBox = new QCheckBox(FilterDialog);
        logic_checkBox->setObjectName(QString::fromUtf8("logic_checkBox"));

        gridLayout_3->addWidget(logic_checkBox, 4, 0, 1, 1);

        check_checkBox = new QCheckBox(FilterDialog);
        check_checkBox->setObjectName(QString::fromUtf8("check_checkBox"));

        gridLayout_3->addWidget(check_checkBox, 6, 0, 1, 1);

        channel_spinBox = new QSpinBox(FilterDialog);
        channel_spinBox->setObjectName(QString::fromUtf8("channel_spinBox"));
        channel_spinBox->setEnabled(false);
        channel_spinBox->setAlignment(Qt::AlignCenter);
        channel_spinBox->setMinimum(1);

        gridLayout_3->addWidget(channel_spinBox, 3, 1, 1, 2);

        dateTime_groupBox = new QGroupBox(FilterDialog);
        dateTime_groupBox->setObjectName(QString::fromUtf8("dateTime_groupBox"));
        dateTime_groupBox->setCheckable(true);
        gridLayout = new QGridLayout(dateTime_groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start_dateTimeEdit = new QDateTimeEdit(dateTime_groupBox);
        start_dateTimeEdit->setObjectName(QString::fromUtf8("start_dateTimeEdit"));
        start_dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(start_dateTimeEdit, 0, 0, 1, 2);

        line = new QFrame(dateTime_groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 1, 1);

        line_2 = new QFrame(dateTime_groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        end_dateTimeEdit = new QDateTimeEdit(dateTime_groupBox);
        end_dateTimeEdit->setObjectName(QString::fromUtf8("end_dateTimeEdit"));
        end_dateTimeEdit->setAccelerated(false);
        end_dateTimeEdit->setProperty("showGroupSeparator", QVariant(false));
        end_dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(end_dateTimeEdit, 1, 1, 1, 2);


        gridLayout_3->addWidget(dateTime_groupBox, 0, 0, 1, 3);

        error_radioButton = new QRadioButton(FilterDialog);
        error_radioButton->setObjectName(QString::fromUtf8("error_radioButton"));
        error_radioButton->setEnabled(false);

        gridLayout_3->addWidget(error_radioButton, 6, 2, 1, 1);

        container_groupBox = new QGroupBox(FilterDialog);
        container_groupBox->setObjectName(QString::fromUtf8("container_groupBox"));
        container_groupBox->setCheckable(true);
        container_groupBox->setChecked(false);
        gridLayout_2 = new QGridLayout(container_groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        front_lineEdit = new QLineEdit(container_groupBox);
        front_lineEdit->setObjectName(QString::fromUtf8("front_lineEdit"));

        gridLayout_2->addWidget(front_lineEdit, 0, 0, 1, 2);

        line_3 = new QFrame(container_groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 0, 2, 1, 1);

        line_4 = new QFrame(container_groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 1, 0, 1, 1);

        after_lineEdit = new QLineEdit(container_groupBox);
        after_lineEdit->setObjectName(QString::fromUtf8("after_lineEdit"));

        gridLayout_2->addWidget(after_lineEdit, 1, 1, 1, 2);


        gridLayout_3->addWidget(container_groupBox, 1, 0, 1, 3);

        channel_checkBox = new QCheckBox(FilterDialog);
        channel_checkBox->setObjectName(QString::fromUtf8("channel_checkBox"));

        gridLayout_3->addWidget(channel_checkBox, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 7, 0, 1, 3);

        plate_checkBox = new QCheckBox(FilterDialog);
        plate_checkBox->setObjectName(QString::fromUtf8("plate_checkBox"));

        gridLayout_3->addWidget(plate_checkBox, 2, 0, 1, 1);

        plate_lineEdit = new QLineEdit(FilterDialog);
        plate_lineEdit->setObjectName(QString::fromUtf8("plate_lineEdit"));
        plate_lineEdit->setEnabled(false);

        gridLayout_3->addWidget(plate_lineEdit, 2, 1, 1, 2);

        QWidget::setTabOrder(start_dateTimeEdit, end_dateTimeEdit);
        QWidget::setTabOrder(end_dateTimeEdit, front_lineEdit);
        QWidget::setTabOrder(front_lineEdit, after_lineEdit);
        QWidget::setTabOrder(after_lineEdit, plate_lineEdit);
        QWidget::setTabOrder(plate_lineEdit, channel_spinBox);
        QWidget::setTabOrder(channel_spinBox, logic_comboBox);
        QWidget::setTabOrder(logic_comboBox, correct_radioButton);
        QWidget::setTabOrder(correct_radioButton, error_radioButton);
        QWidget::setTabOrder(error_radioButton, check_checkBox);
        QWidget::setTabOrder(check_checkBox, plate_checkBox);
        QWidget::setTabOrder(plate_checkBox, dateTime_groupBox);
        QWidget::setTabOrder(dateTime_groupBox, channel_checkBox);
        QWidget::setTabOrder(channel_checkBox, container_groupBox);
        QWidget::setTabOrder(container_groupBox, logic_checkBox);

        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterDialog, SLOT(reject()));
        QObject::connect(plate_checkBox, SIGNAL(clicked(bool)), plate_lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(channel_checkBox, SIGNAL(clicked(bool)), channel_spinBox, SLOT(setEnabled(bool)));
        QObject::connect(logic_checkBox, SIGNAL(clicked(bool)), logic_comboBox, SLOT(setEnabled(bool)));
        QObject::connect(check_checkBox, SIGNAL(clicked(bool)), correct_radioButton, SLOT(setEnabled(bool)));
        QObject::connect(check_checkBox, SIGNAL(clicked(bool)), error_radioButton, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QApplication::translate("FilterDialog", "Filter database", nullptr));
        logic_comboBox->setItemText(0, QApplication::translate("FilterDialog", "A small container", nullptr));
        logic_comboBox->setItemText(1, QApplication::translate("FilterDialog", "A large container", nullptr));
        logic_comboBox->setItemText(2, QApplication::translate("FilterDialog", "Two small containers", nullptr));
        logic_comboBox->setItemText(3, QApplication::translate("FilterDialog", "Heavy set truck", nullptr));
        logic_comboBox->setItemText(4, QApplication::translate("FilterDialog", "Empty set truck", nullptr));

        correct_radioButton->setText(QApplication::translate("FilterDialog", "correct", nullptr));
        logic_checkBox->setText(QApplication::translate("FilterDialog", "Logic", nullptr));
        check_checkBox->setText(QApplication::translate("FilterDialog", "Check", nullptr));
        dateTime_groupBox->setTitle(QApplication::translate("FilterDialog", "DateTime", nullptr));
        start_dateTimeEdit->setDisplayFormat(QApplication::translate("FilterDialog", "yyyy/MM/dd HH:mm:ss", nullptr));
        end_dateTimeEdit->setDisplayFormat(QApplication::translate("FilterDialog", "yyyy/MM/dd HH:mm:ss", nullptr));
        error_radioButton->setText(QApplication::translate("FilterDialog", "error", nullptr));
        container_groupBox->setTitle(QApplication::translate("FilterDialog", "Container", nullptr));
        channel_checkBox->setText(QApplication::translate("FilterDialog", "Channel", nullptr));
        plate_checkBox->setText(QApplication::translate("FilterDialog", "Plate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
