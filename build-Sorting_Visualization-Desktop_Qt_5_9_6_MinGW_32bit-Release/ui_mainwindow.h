/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *itemsNum;
    QLabel *label_2;
    QLineEdit *aniDuration;
    QTextBrowser *textBrowser;
    QComboBox *sortingtype;
    QCheckBox *checkBox;
    QPushButton *sortingBtn;
    QPushButton *shuffleBtn;
    QPushButton *restoreBtn;
    QPushButton *stopSortingBtn;
    QLabel *label_6;
    QLCDNumber *lcdNumber;
    QLabel *label_7;
    QLCDNumber *lcdNumber_2;
    QLabel *label_8;
    QLCDNumber *lcdNumber_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1070, 728);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        horizontalLayout->addWidget(graphicsView);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        itemsNum = new QLineEdit(frame);
        itemsNum->setObjectName(QStringLiteral("itemsNum"));
        itemsNum->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(itemsNum);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        aniDuration = new QLineEdit(frame);
        aniDuration->setObjectName(QStringLiteral("aniDuration"));
        aniDuration->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(aniDuration);

        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(textBrowser);

        sortingtype = new QComboBox(frame);
        sortingtype->setObjectName(QStringLiteral("sortingtype"));
        sizePolicy3.setHeightForWidth(sortingtype->sizePolicy().hasHeightForWidth());
        sortingtype->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(sortingtype);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox, 0, Qt::AlignHCenter);

        sortingBtn = new QPushButton(frame);
        sortingBtn->setObjectName(QStringLiteral("sortingBtn"));

        verticalLayout->addWidget(sortingBtn);

        shuffleBtn = new QPushButton(frame);
        shuffleBtn->setObjectName(QStringLiteral("shuffleBtn"));

        verticalLayout->addWidget(shuffleBtn);

        restoreBtn = new QPushButton(frame);
        restoreBtn->setObjectName(QStringLiteral("restoreBtn"));

        verticalLayout->addWidget(restoreBtn);

        stopSortingBtn = new QPushButton(frame);
        stopSortingBtn->setObjectName(QStringLiteral("stopSortingBtn"));

        verticalLayout->addWidget(stopSortingBtn);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy4);
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(5);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(0));

        verticalLayout->addWidget(lcdNumber, 0, Qt::AlignHCenter);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        lcdNumber_2 = new QLCDNumber(frame);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        sizePolicy4.setHeightForWidth(lcdNumber_2->sizePolicy().hasHeightForWidth());
        lcdNumber_2->setSizePolicy(sizePolicy4);
        lcdNumber_2->setStyleSheet(QStringLiteral("color: rgb(255, 85, 255);"));
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber_2, 0, Qt::AlignHCenter);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        lcdNumber_3 = new QLCDNumber(frame);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        sizePolicy4.setHeightForWidth(lcdNumber_3->sizePolicy().hasHeightForWidth());
        lcdNumber_3->setSizePolicy(sizePolicy4);
        lcdNumber_3->setStyleSheet(QStringLiteral("color: rgb(85, 85, 255);"));
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber_3, 0, Qt::AlignHCenter);


        horizontalLayout->addWidget(frame);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        sortingtype->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\225\260\351\207\217", Q_NULLPTR));
        itemsNum->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\344\270\200\346\254\241\347\247\273\345\212\250\347\232\204\351\200\237\345\272\246(\346\257\253\347\247\222)", Q_NULLPTR));
        aniDuration->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">i\346\230\257\347\254\254\344\270\200\345\261\202\345\276\252\347\216\257</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">j\346\230\257\347\254\254\344\272\214\345\261\202\345\276\252\347\216\257</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k\346\230\257\350\276\205\345\212\251(\344\270\264\346\227\266)\345\217\230\351\207\217</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">g\346\230\257\347\233\221\345\257\237\344\275\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\257\344\273\245\345\234\250\350\277\231\345\201\232\346\216\222\345\272\217\347\232\204\350\256\260\345\275\225\357\274\214\347\210\261\344\275"
                        "\240\344\271\210\344\271\210\345\223\222</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\276\205\346\233\264\346\226\260\357\274\214\347\233\256\345\211\215\345\217\252\345\256\236\347\216\260\345\210\260\345\277\253\351\200\237\346\216\222\345\272\217\345\211\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        sortingtype->clear();
        sortingtype->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\217\222\345\205\245\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\224\271\350\277\233\347\211\210\345\206\222\346\263\241\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\224\271\350\277\233\347\211\210\346\217\222\345\205\245\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\241\266\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\272\214\345\205\203\351\200\211\346\213\251\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\240\206\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\224\271\350\277\233\347\211\210\345\277\253\351\200\237\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\275\222\345\271\266\346\216\222\345\272\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\237\272\346\225\260\346\216\222\345\272\217", Q_NULLPTR)
        );
        checkBox->setText(QApplication::translate("MainWindow", "\346\255\243\345\272\217", Q_NULLPTR));
        sortingBtn->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\216\222\345\272\217", Q_NULLPTR));
        shuffleBtn->setText(QApplication::translate("MainWindow", "\346\264\227\347\211\214", Q_NULLPTR));
        restoreBtn->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215", Q_NULLPTR));
        stopSortingBtn->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\216\222\345\272\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\255\245\346\225\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\257\224\350\276\203\346\255\245\346\225\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\344\272\244\346\215\242\346\255\245\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
