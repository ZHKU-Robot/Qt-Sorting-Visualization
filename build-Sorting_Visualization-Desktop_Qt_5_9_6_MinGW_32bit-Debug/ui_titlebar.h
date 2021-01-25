/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_minimizeButton;
    QPushButton *m_maximizeButton;
    QPushButton *m_closeButton;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->resize(1010, 220);
        TitleBar->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(TitleBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TitleBar);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(546, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_minimizeButton = new QPushButton(TitleBar);
        m_minimizeButton->setObjectName(QStringLiteral("m_minimizeButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\234\200\345\260\217\345\214\226\347\273\210\346\236\201\344\270\215\346\224\271.svg"), QSize(), QIcon::Normal, QIcon::Off);
        m_minimizeButton->setIcon(icon);
        m_minimizeButton->setFlat(true);

        horizontalLayout->addWidget(m_minimizeButton);

        m_maximizeButton = new QPushButton(TitleBar);
        m_maximizeButton->setObjectName(QStringLiteral("m_maximizeButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\346\234\200\345\244\247\345\214\226.svg"), QSize(), QIcon::Normal, QIcon::Off);
        m_maximizeButton->setIcon(icon1);
        m_maximizeButton->setFlat(true);

        horizontalLayout->addWidget(m_maximizeButton);

        m_closeButton = new QPushButton(TitleBar);
        m_closeButton->setObjectName(QStringLiteral("m_closeButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\345\205\263 \351\227\255.svg"), QSize(), QIcon::Normal, QIcon::Off);
        m_closeButton->setIcon(icon2);
        m_closeButton->setFlat(true);

        horizontalLayout->addWidget(m_closeButton);


        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QApplication::translate("TitleBar", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("TitleBar", "CK\347\232\204\344\270\200\344\270\252\346\216\222\345\272\217\347\256\227\346\263\225\345\217\257\350\247\206\345\214\226\347\232\204\345\260\217\350\275\257\344\273\266 blingbling", Q_NULLPTR));
        m_minimizeButton->setText(QString());
        m_maximizeButton->setText(QString());
        m_closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
