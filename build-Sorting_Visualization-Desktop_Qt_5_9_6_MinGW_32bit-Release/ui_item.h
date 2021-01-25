/********************************************************************************
** Form generated from reading UI file 'item.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEM_H
#define UI_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Item
{
public:

    void setupUi(QWidget *Item)
    {
        if (Item->objectName().isEmpty())
            Item->setObjectName(QStringLiteral("Item"));
        Item->resize(66, 360);

        retranslateUi(Item);

        QMetaObject::connectSlotsByName(Item);
    } // setupUi

    void retranslateUi(QWidget *Item)
    {
        Item->setWindowTitle(QApplication::translate("Item", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Item: public Ui_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEM_H
