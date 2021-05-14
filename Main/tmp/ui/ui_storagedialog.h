/********************************************************************************
** Form generated from reading UI file 'storagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORAGEDIALOG_H
#define UI_STORAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_StorageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *storageMsg_checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StorageDialog)
    {
        if (StorageDialog->objectName().isEmpty())
            StorageDialog->setObjectName(QString::fromUtf8("StorageDialog"));
        StorageDialog->resize(441, 306);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        StorageDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(StorageDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(StorageDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        storageMsg_checkBox = new QCheckBox(StorageDialog);
        storageMsg_checkBox->setObjectName(QString::fromUtf8("storageMsg_checkBox"));

        gridLayout->addWidget(storageMsg_checkBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(StorageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(StorageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StorageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StorageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StorageDialog);
    } // setupUi

    void retranslateUi(QDialog *StorageDialog)
    {
        StorageDialog->setWindowTitle(QApplication::translate("StorageDialog", "StorageDialog", nullptr));
        label->setText(QApplication::translate("StorageDialog", "    \347\263\273\347\273\237\345\255\230\345\202\250\345\233\276\347\211\207\347\251\272\351\227\264\350\266\205\350\277\207\347\263\273\347\273\237\350\256\276\345\256\232\345\200\274\357\274\214\350\257\267\345\217\212\346\227\266\345\244\204\347\220\206\357\274\214\344\273\245\345\205\215\345\275\261\345\223\215\347\263\273\347\273\237\344\275\277\347\224\250\357\274\201\357\274\201\357\274\201", nullptr));
        storageMsg_checkBox->setText(QApplication::translate("StorageDialog", "\351\207\215\345\220\257\345\211\215\344\270\215\345\206\215\346\217\220\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StorageDialog: public Ui_StorageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORAGEDIALOG_H
