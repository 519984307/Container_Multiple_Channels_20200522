/********************************************************************************
** Form generated from reading UI file 'database_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_FORM_H
#define UI_DATABASE_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBase_Form
{
public:
    QGridLayout *gridLayout_9;
    QStackedWidget *database_stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_6;
    QTableView *tableView;
    QWidget *page_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_8;
    QLineEdit *result_lineEdit_6;
    QLineEdit *result_lineEdit_1;
    QLineEdit *result_lineEdit_5;
    QLineEdit *result_lineEdit_4;
    QLineEdit *result_lineEdit_2;
    QLabel *image_label_7;
    QLabel *image_label_11;
    QLabel *image_label_6;
    QLabel *image_label_2;
    QLabel *image_label_5;
    QLabel *image_label_3;
    QLabel *image_label_1;
    QLabel *image_label_12;
    QLineEdit *result_lineEdit_8;
    QLabel *image_label_8;
    QLabel *image_label_9;
    QLineEdit *result_lineEdit_7;
    QLabel *image_label_10;
    QLineEdit *result_lineEdit_3;
    QLabel *image_label_4;
    QLineEdit *result_lineEdit_12;
    QLineEdit *result_lineEdit_11;
    QLineEdit *result_lineEdit_10;
    QLineEdit *result_lineEdit_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_7;
    QPushButton *database_imageOrData_pushButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *result_lineEdit_front;
    QLineEdit *iso_lineEdit_front;
    QLineEdit *plate_lineEdit_front;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *result_lineEdit_before;
    QLineEdit *iso_lineEdit_before;
    QLineEdit *lineEdit_5;
    QLineEdit *type_lineEdit;

    void setupUi(QWidget *DataBase_Form)
    {
        if (DataBase_Form->objectName().isEmpty())
            DataBase_Form->setObjectName(QString::fromUtf8("DataBase_Form"));
        DataBase_Form->resize(1000, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DataBase_Form->setWindowIcon(icon);
        gridLayout_9 = new QGridLayout(DataBase_Form);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        database_stackedWidget = new QStackedWidget(DataBase_Form);
        database_stackedWidget->setObjectName(QString::fromUtf8("database_stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(database_stackedWidget->sizePolicy().hasHeightForWidth());
        database_stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_6 = new QGridLayout(page);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, -1, 0, 0);
        tableView = new QTableView(page);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_6->addWidget(tableView, 0, 0, 1, 1);

        database_stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_7 = new QGridLayout(page_2);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        result_lineEdit_6 = new QLineEdit(page_2);
        result_lineEdit_6->setObjectName(QString::fromUtf8("result_lineEdit_6"));
        result_lineEdit_6->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_6, 5, 4, 1, 1);

        result_lineEdit_1 = new QLineEdit(page_2);
        result_lineEdit_1->setObjectName(QString::fromUtf8("result_lineEdit_1"));
        result_lineEdit_1->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_1, 3, 2, 1, 1);

        result_lineEdit_5 = new QLineEdit(page_2);
        result_lineEdit_5->setObjectName(QString::fromUtf8("result_lineEdit_5"));
        result_lineEdit_5->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_5, 5, 3, 1, 1);

        result_lineEdit_4 = new QLineEdit(page_2);
        result_lineEdit_4->setObjectName(QString::fromUtf8("result_lineEdit_4"));
        result_lineEdit_4->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_4, 5, 2, 1, 1);

        result_lineEdit_2 = new QLineEdit(page_2);
        result_lineEdit_2->setObjectName(QString::fromUtf8("result_lineEdit_2"));
        result_lineEdit_2->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_2, 3, 3, 1, 1);

        image_label_7 = new QLabel(page_2);
        image_label_7->setObjectName(QString::fromUtf8("image_label_7"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        image_label_7->setFont(font);
        image_label_7->setAutoFillBackground(true);
        image_label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_7->setFrameShape(QFrame::StyledPanel);
        image_label_7->setLineWidth(1);
        image_label_7->setScaledContents(true);
        image_label_7->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_7, 2, 5, 1, 1);

        image_label_11 = new QLabel(page_2);
        image_label_11->setObjectName(QString::fromUtf8("image_label_11"));
        image_label_11->setFont(font);
        image_label_11->setAutoFillBackground(true);
        image_label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_11->setFrameShape(QFrame::StyledPanel);
        image_label_11->setLineWidth(1);
        image_label_11->setScaledContents(true);
        image_label_11->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_11, 6, 3, 1, 1);

        image_label_6 = new QLabel(page_2);
        image_label_6->setObjectName(QString::fromUtf8("image_label_6"));
        image_label_6->setFont(font);
        image_label_6->setAutoFillBackground(true);
        image_label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_6->setFrameShape(QFrame::StyledPanel);
        image_label_6->setLineWidth(1);
        image_label_6->setScaledContents(true);
        image_label_6->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_6, 4, 4, 1, 1);

        image_label_2 = new QLabel(page_2);
        image_label_2->setObjectName(QString::fromUtf8("image_label_2"));
        image_label_2->setFont(font);
        image_label_2->setAutoFillBackground(true);
        image_label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_2->setFrameShape(QFrame::StyledPanel);
        image_label_2->setLineWidth(1);
        image_label_2->setScaledContents(true);
        image_label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_2, 2, 3, 1, 1);

        image_label_5 = new QLabel(page_2);
        image_label_5->setObjectName(QString::fromUtf8("image_label_5"));
        image_label_5->setFont(font);
        image_label_5->setAutoFillBackground(true);
        image_label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_5->setFrameShape(QFrame::StyledPanel);
        image_label_5->setLineWidth(1);
        image_label_5->setScaledContents(true);
        image_label_5->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_5, 4, 3, 1, 1);

        image_label_3 = new QLabel(page_2);
        image_label_3->setObjectName(QString::fromUtf8("image_label_3"));
        image_label_3->setFont(font);
        image_label_3->setAutoFillBackground(true);
        image_label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_3->setFrameShape(QFrame::StyledPanel);
        image_label_3->setLineWidth(1);
        image_label_3->setScaledContents(true);
        image_label_3->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_3, 2, 4, 1, 1);

        image_label_1 = new QLabel(page_2);
        image_label_1->setObjectName(QString::fromUtf8("image_label_1"));
        image_label_1->setFont(font);
        image_label_1->setAutoFillBackground(true);
        image_label_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_1->setFrameShape(QFrame::StyledPanel);
        image_label_1->setLineWidth(1);
        image_label_1->setScaledContents(true);
        image_label_1->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_1, 2, 2, 1, 1);

        image_label_12 = new QLabel(page_2);
        image_label_12->setObjectName(QString::fromUtf8("image_label_12"));
        image_label_12->setFont(font);
        image_label_12->setAutoFillBackground(true);
        image_label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_12->setFrameShape(QFrame::StyledPanel);
        image_label_12->setLineWidth(1);
        image_label_12->setScaledContents(true);
        image_label_12->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_12, 6, 2, 1, 1);

        result_lineEdit_8 = new QLineEdit(page_2);
        result_lineEdit_8->setObjectName(QString::fromUtf8("result_lineEdit_8"));
        result_lineEdit_8->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_8, 5, 5, 1, 1);

        image_label_8 = new QLabel(page_2);
        image_label_8->setObjectName(QString::fromUtf8("image_label_8"));
        image_label_8->setFont(font);
        image_label_8->setAutoFillBackground(true);
        image_label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_8->setFrameShape(QFrame::StyledPanel);
        image_label_8->setLineWidth(1);
        image_label_8->setScaledContents(true);
        image_label_8->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_8, 4, 5, 1, 1);

        image_label_9 = new QLabel(page_2);
        image_label_9->setObjectName(QString::fromUtf8("image_label_9"));
        image_label_9->setFont(font);
        image_label_9->setAutoFillBackground(true);
        image_label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_9->setFrameShape(QFrame::StyledPanel);
        image_label_9->setLineWidth(1);
        image_label_9->setScaledContents(true);
        image_label_9->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_9, 6, 5, 1, 1);

        result_lineEdit_7 = new QLineEdit(page_2);
        result_lineEdit_7->setObjectName(QString::fromUtf8("result_lineEdit_7"));
        result_lineEdit_7->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_7, 3, 5, 1, 1);

        image_label_10 = new QLabel(page_2);
        image_label_10->setObjectName(QString::fromUtf8("image_label_10"));
        image_label_10->setFont(font);
        image_label_10->setAutoFillBackground(true);
        image_label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_10->setFrameShape(QFrame::StyledPanel);
        image_label_10->setLineWidth(1);
        image_label_10->setScaledContents(true);
        image_label_10->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_10, 6, 4, 1, 1);

        result_lineEdit_3 = new QLineEdit(page_2);
        result_lineEdit_3->setObjectName(QString::fromUtf8("result_lineEdit_3"));
        result_lineEdit_3->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_3, 3, 4, 1, 1);

        image_label_4 = new QLabel(page_2);
        image_label_4->setObjectName(QString::fromUtf8("image_label_4"));
        image_label_4->setFont(font);
        image_label_4->setAutoFillBackground(true);
        image_label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        image_label_4->setFrameShape(QFrame::StyledPanel);
        image_label_4->setLineWidth(1);
        image_label_4->setScaledContents(true);
        image_label_4->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_8->addWidget(image_label_4, 4, 2, 1, 1);

        result_lineEdit_12 = new QLineEdit(page_2);
        result_lineEdit_12->setObjectName(QString::fromUtf8("result_lineEdit_12"));
        result_lineEdit_12->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_12, 7, 2, 1, 1);

        result_lineEdit_11 = new QLineEdit(page_2);
        result_lineEdit_11->setObjectName(QString::fromUtf8("result_lineEdit_11"));
        result_lineEdit_11->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_11, 7, 3, 1, 1);

        result_lineEdit_10 = new QLineEdit(page_2);
        result_lineEdit_10->setObjectName(QString::fromUtf8("result_lineEdit_10"));
        result_lineEdit_10->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_10, 7, 4, 1, 1);

        result_lineEdit_9 = new QLineEdit(page_2);
        result_lineEdit_9->setObjectName(QString::fromUtf8("result_lineEdit_9"));
        result_lineEdit_9->setReadOnly(true);

        gridLayout_8->addWidget(result_lineEdit_9, 7, 5, 1, 1);


        gridLayout_7->addLayout(gridLayout_8, 3, 3, 1, 1);

        database_stackedWidget->addWidget(page_2);

        gridLayout_9->addWidget(database_stackedWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(DataBase_Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 130));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/database/ICO/find.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/database/ICO/frist.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/database/ICO/before.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/database/ICO/front.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/database/ICO/last.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_11);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/database/ICO/excel.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButton_7);

        database_imageOrData_pushButton = new QPushButton(groupBox);
        database_imageOrData_pushButton->setObjectName(QString::fromUtf8("database_imageOrData_pushButton"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        database_imageOrData_pushButton->setFont(font1);
        database_imageOrData_pushButton->setAutoFillBackground(true);
        database_imageOrData_pushButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_5->addWidget(database_imageOrData_pushButton);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        result_lineEdit_front = new QLineEdit(groupBox);
        result_lineEdit_front->setObjectName(QString::fromUtf8("result_lineEdit_front"));
        result_lineEdit_front->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setPointSize(20);
        result_lineEdit_front->setFont(font2);
        result_lineEdit_front->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(result_lineEdit_front);

        iso_lineEdit_front = new QLineEdit(groupBox);
        iso_lineEdit_front->setObjectName(QString::fromUtf8("iso_lineEdit_front"));
        iso_lineEdit_front->setMaximumSize(QSize(100, 50));
        iso_lineEdit_front->setFont(font2);
        iso_lineEdit_front->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(iso_lineEdit_front);


        gridLayout_5->addLayout(horizontalLayout, 0, 2, 2, 1);

        plate_lineEdit_front = new QLineEdit(groupBox);
        plate_lineEdit_front->setObjectName(QString::fromUtf8("plate_lineEdit_front"));
        plate_lineEdit_front->setMaximumSize(QSize(150, 50));
        QFont font3;
        font3.setPointSize(14);
        plate_lineEdit_front->setFont(font3);
        plate_lineEdit_front->setAutoFillBackground(true);
        plate_lineEdit_front->setAlignment(Qt::AlignCenter);
        plate_lineEdit_front->setReadOnly(true);

        gridLayout_5->addWidget(plate_lineEdit_front, 0, 3, 2, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_5);


        gridLayout_5->addLayout(horizontalLayout_3, 1, 0, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        result_lineEdit_before = new QLineEdit(groupBox);
        result_lineEdit_before->setObjectName(QString::fromUtf8("result_lineEdit_before"));
        result_lineEdit_before->setMaximumSize(QSize(16777215, 50));
        result_lineEdit_before->setFont(font2);
        result_lineEdit_before->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(result_lineEdit_before);

        iso_lineEdit_before = new QLineEdit(groupBox);
        iso_lineEdit_before->setObjectName(QString::fromUtf8("iso_lineEdit_before"));
        iso_lineEdit_before->setMaximumSize(QSize(100, 50));
        iso_lineEdit_before->setFont(font2);
        iso_lineEdit_before->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(iso_lineEdit_before);


        gridLayout_5->addLayout(horizontalLayout_2, 2, 2, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(150, 50));
        lineEdit_5->setFont(font3);
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);

        gridLayout_5->addWidget(lineEdit_5, 2, 3, 1, 1);

        type_lineEdit = new QLineEdit(groupBox);
        type_lineEdit->setObjectName(QString::fromUtf8("type_lineEdit"));
        type_lineEdit->setMaximumSize(QSize(250, 100));
        type_lineEdit->setFont(font2);
        type_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(type_lineEdit, 1, 1, 2, 1);


        gridLayout_9->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(DataBase_Form);

        database_stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DataBase_Form);
    } // setupUi

    void retranslateUi(QWidget *DataBase_Form)
    {
        DataBase_Form->setWindowTitle(QApplication::translate("DataBase_Form", "History", nullptr));
        image_label_7->setText(QApplication::translate("DataBase_Form", "7", nullptr));
        image_label_11->setText(QApplication::translate("DataBase_Form", "11", nullptr));
        image_label_6->setText(QApplication::translate("DataBase_Form", "6", nullptr));
        image_label_2->setText(QApplication::translate("DataBase_Form", "2", nullptr));
        image_label_5->setText(QApplication::translate("DataBase_Form", "5", nullptr));
        image_label_3->setText(QApplication::translate("DataBase_Form", "3", nullptr));
        image_label_1->setText(QApplication::translate("DataBase_Form", "1", nullptr));
        image_label_12->setText(QApplication::translate("DataBase_Form", "12", nullptr));
        image_label_8->setText(QApplication::translate("DataBase_Form", "8", nullptr));
        image_label_9->setText(QApplication::translate("DataBase_Form", "9", nullptr));
        image_label_10->setText(QApplication::translate("DataBase_Form", "10", nullptr));
        image_label_4->setText(QApplication::translate("DataBase_Form", "4", nullptr));
        groupBox->setTitle(QString());
        pushButton_5->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_7->setText(QString());
        database_imageOrData_pushButton->setText(QApplication::translate("DataBase_Form", "Image", nullptr));
        result_lineEdit_front->setText(QApplication::translate("DataBase_Form", "***********", nullptr));
        iso_lineEdit_front->setText(QApplication::translate("DataBase_Form", "****", nullptr));
        plate_lineEdit_front->setText(QApplication::translate("DataBase_Form", "*******", nullptr));
        plate_lineEdit_front->setPlaceholderText(QApplication::translate("DataBase_Form", "Plate", nullptr));
        groupBox_2->setTitle(QApplication::translate("DataBase_Form", "total", nullptr));
        label_13->setText(QApplication::translate("DataBase_Form", "0", nullptr));
        groupBox_3->setTitle(QApplication::translate("DataBase_Form", "correct", nullptr));
        label_14->setText(QApplication::translate("DataBase_Form", "0", nullptr));
        groupBox_4->setTitle(QApplication::translate("DataBase_Form", "error", nullptr));
        label_15->setText(QApplication::translate("DataBase_Form", "0", nullptr));
        groupBox_5->setTitle(QApplication::translate("DataBase_Form", "ratio", nullptr));
        label_16->setText(QApplication::translate("DataBase_Form", "0%", nullptr));
        result_lineEdit_before->setText(QApplication::translate("DataBase_Form", "***********", nullptr));
        iso_lineEdit_before->setText(QApplication::translate("DataBase_Form", "****", nullptr));
        lineEdit_5->setText(QApplication::translate("DataBase_Form", "0KG", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("DataBase_Form", "weight ", nullptr));
        type_lineEdit->setText(QApplication::translate("DataBase_Form", "****", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBase_Form: public Ui_DataBase_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_FORM_H
