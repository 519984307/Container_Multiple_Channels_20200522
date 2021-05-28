/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *appLabel;
    QLabel *label_11;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *verLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *copyrightLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLabel *ID_label;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(628, 403);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(AboutDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 100));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));
        label->setFrameShape(QFrame::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 3, 1);

        appLabel = new QLabel(AboutDialog);
        appLabel->setObjectName(QString::fromUtf8("appLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        appLabel->setFont(font);

        gridLayout->addWidget(appLabel, 0, 1, 1, 1);

        label_11 = new QLabel(AboutDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 271, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 7, 1);

        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 1, 1, 1);

        label_7 = new QLabel(AboutDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 1, 1, 1);

        label_6 = new QLabel(AboutDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(10);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_6->setWordWrap(true);

        gridLayout->addWidget(label_6, 8, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(396, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 1, 1, 1);

        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 9, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        verLabel = new QLabel(AboutDialog);
        verLabel->setObjectName(QString::fromUtf8("verLabel"));

        horizontalLayout->addWidget(verLabel);

        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        copyrightLabel = new QLabel(AboutDialog);
        copyrightLabel->setObjectName(QString::fromUtf8("copyrightLabel"));

        horizontalLayout_2->addWidget(copyrightLabel);

        horizontalLayout_2->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(AboutDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        ID_label = new QLabel(AboutDialog);
        ID_label->setObjectName(QString::fromUtf8("ID_label"));

        horizontalLayout_3->addWidget(ID_label);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_3, 5, 1, 1, 2);


        retranslateUi(AboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AboutDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About", nullptr));
        label->setText(QString());
        appLabel->setText(QString());
        label_11->setText(QApplication::translate("AboutDialog", "Base on Qt 5.14.2 (MinGW 7.3.0 64 bit)", nullptr));
        label_2->setText(QApplication::translate("AboutDialog", "Built on December 8, 2020 11:43", nullptr));
        label_4->setText(QApplication::translate("AboutDialog", "Technical hotline:18565659070", nullptr));
        label_7->setText(QApplication::translate("AboutDialog", "Sales hotline:15989899192", nullptr));
        label_6->setText(QApplication::translate("AboutDialog", "This software integrates container number identification, electronic license plate identification, electronic gate control. Multiple channels can be managed by a single server.\n"
"\n"
"", nullptr));
        pushButton->setText(QApplication::translate("AboutDialog", "Exit", nullptr));
        label_3->setText(QApplication::translate("AboutDialog", "vision", nullptr));
        verLabel->setText(QString());
        label_5->setText(QApplication::translate("AboutDialog", "Copyright Reserved 2010-2020 ", nullptr));
        copyrightLabel->setText(QString());
        label_8->setText(QApplication::translate("AboutDialog", "id", nullptr));
        ID_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
