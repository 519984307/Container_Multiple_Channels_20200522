/********************************************************************************
** Form generated from reading UI file 'version_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSION_DIALOG_H
#define UI_VERSION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Version_Dialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Version_Dialog)
    {
        if (Version_Dialog->objectName().isEmpty())
            Version_Dialog->setObjectName(QString::fromUtf8("Version_Dialog"));
        Version_Dialog->resize(596, 529);
        gridLayout = new QGridLayout(Version_Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(Version_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(Version_Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(true);

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 2);


        retranslateUi(Version_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Version_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Version_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Version_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Version_Dialog)
    {
        Version_Dialog->setWindowTitle(QApplication::translate("Version_Dialog", "Version", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Version_Dialog: public Ui_Version_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSION_DIALOG_H
