/********************************************************************************
** Form generated from reading UI file 'camera_list_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_LIST_FORM_H
#define UI_CAMERA_LIST_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera_List_Form
{
public:
    QGridLayout *gridLayout_2;
    QTreeWidget *CameraList;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Camera_List_Form)
    {
        if (Camera_List_Form->objectName().isEmpty())
            Camera_List_Form->setObjectName(QString::fromUtf8("Camera_List_Form"));
        Camera_List_Form->resize(1024, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Camera_List_Form->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Camera_List_Form);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        CameraList = new QTreeWidget(Camera_List_Form);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        CameraList->setHeaderItem(__qtreewidgetitem);
        CameraList->setObjectName(QString::fromUtf8("CameraList"));
        CameraList->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CameraList->sizePolicy().hasHeightForWidth());
        CameraList->setSizePolicy(sizePolicy);
        CameraList->setMinimumSize(QSize(150, 0));
        CameraList->setMaximumSize(QSize(150, 16777215));
        CameraList->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);

        gridLayout_2->addWidget(CameraList, 0, 0, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 1, 2, 2);


        retranslateUi(Camera_List_Form);

        QMetaObject::connectSlotsByName(Camera_List_Form);
    } // setupUi

    void retranslateUi(QWidget *Camera_List_Form)
    {
        Camera_List_Form->setWindowTitle(QApplication::translate("Camera_List_Form", "CameraTest", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = CameraList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Camera_List_Form", "Camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera_List_Form: public Ui_Camera_List_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_LIST_FORM_H
