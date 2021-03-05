/********************************************************************************
** Form generated from reading UI file 'errorform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORFORM_H
#define UI_ERRORFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorForm
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *ErrorForm)
    {
        if (ErrorForm->objectName().isEmpty())
            ErrorForm->setObjectName(QString::fromUtf8("ErrorForm"));
        ErrorForm->resize(800, 50);
        ErrorForm->setMinimumSize(QSize(0, 50));
        ErrorForm->setMaximumSize(QSize(16777215, 50));
        ErrorForm->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        gridLayout_3 = new QGridLayout(ErrorForm);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolButton = new QToolButton(ErrorForm);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setAutoRaise(true);

        gridLayout_2->addWidget(toolButton, 0, 2, 1, 1);

        label = new QLabel(ErrorForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(20, 20));
        label->setPixmap(QPixmap(QString::fromUtf8(":/UI_ICO/ICO/error.svg")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ErrorForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(ErrorForm);
        QObject::connect(toolButton, SIGNAL(clicked()), ErrorForm, SLOT(hide()));

        QMetaObject::connectSlotsByName(ErrorForm);
    } // setupUi

    void retranslateUi(QWidget *ErrorForm)
    {
        ErrorForm->setWindowTitle(QApplication::translate("ErrorForm", "Form", nullptr));
        toolButton->setText(QApplication::translate("ErrorForm", "X", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("ErrorForm", "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorForm: public Ui_ErrorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORM_H
