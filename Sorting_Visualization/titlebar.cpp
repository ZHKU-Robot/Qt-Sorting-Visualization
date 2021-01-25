#include "titlebar.h"
#include "ui_titlebar.h"

#include <QMouseEvent>
#include <qpushbutton.h>
#include "QDebug"
TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    connect(ui->m_minimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(ui->m_maximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(ui->m_closeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == ui->m_minimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == ui->m_maximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
            if(pWindow->isMaximized()){
                ui->m_maximizeButton->setIcon(QIcon(":/最小化.svg"));
            }
            else{
                ui->m_maximizeButton->setIcon(QIcon(":/最大化.svg"));
            }
        }
        else if (pButton == ui->m_closeButton)
        {
            pWindow->close();
        }
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
   this->window()->move(event->globalPos()-m_start);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
  m_start = event->pos();
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{

}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    ui->m_maximizeButton->click();
}
