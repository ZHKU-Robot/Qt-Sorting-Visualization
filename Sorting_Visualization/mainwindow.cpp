#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <qpropertyanimation.h>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsProxyWidget>
#include <QParallelAnimationGroup>
#include <QMessageBox>
#include "ui_item.h"
#include "ui_titlebar.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    QTimer *t=new QTimer();
    connect(t,&QTimer::timeout,this,[=](){
        initItems();
    });
    t->setSingleShot(1);
    t->start(100);

    setWindowFlags(Qt::FramelessWindowHint);

    ui->verticalLayout_2->insertWidget(0,titlebar);

    initWidget();

    connect(titlebar->ui->m_closeButton,&QPushButton::clicked,this,[=](){
        on_stopSortingBtn_clicked();
        delete ui;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Sleep(int msec)
{

    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}




void MainWindow::unable()
{
    ui->shuffleBtn->setEnabled(0);
    ui->itemsNum->setEnabled(0);
    //        ui->aniDuration->setEnabled(0);
    ui->sortingBtn->setEnabled(0);
    ui->sortingtype->setEnabled(0);
    ui->restoreBtn->setEnabled(0);
}

void MainWindow::enable()
{
    ui->shuffleBtn->setEnabled(1);
    ui->itemsNum->setEnabled(1);
    //    ui->aniDuration->setEnabled(1);
    ui->sortingBtn->setEnabled(1);
    ui->sortingtype->setEnabled(1);
    ui->restoreBtn->setEnabled(1);
}

void MainWindow::initItems(QVector<RectProxyWidget* > proxyItems)
{
    for(int i=0;i<proxyItems.size();i++){
        proxyItems[i]->show();
    }
}

void MainWindow::initArrowLabel(QLabel *l,QGraphicsProxyWidget *arrow,QPixmap pix)
{

    l->setAlignment(Qt::AlignHCenter);
    l->setAttribute(Qt::WA_TranslucentBackground);

    arrow->setWidget(l);
    arrow->setZValue(1);

    l->setPixmap(pix);


    scene->addItem(arrow);



}

void MainWindow::initNumLabel(QString text,QString style,QPointF pos,QGraphicsProxyWidget *labelNum)
{
    QFont f("微软雅黑",20,QFont::Black);
    QLabel *ln1=new QLabel(text);
    ln1->setStyleSheet(style);

    ln1->setFont(f);
    ln1->setAlignment(Qt::AlignHCenter);
    ln1->setAttribute(Qt::WA_TranslucentBackground);
    ln1->adjustSize();

    labelNum->setWidget(ln1);
    labelNum->setZValue(1);
    labelNum->setPos(pos);

    scene->addItem(labelNum);

}

void MainWindow::removeItemsCopy()
{
    int count=rectProxyItemsCopy.size();

    for(int ix=0;ix<count;ix++){

        RectProxyWidget *r=rectProxyItemsCopy.at(0);
        rectProxyItemsCopy.removeFirst();
        r->deleteLater();
    }
}

void MainWindow::removeItems()
{

    for(int ix=0,count=rectProxyItems.size();ix<count;ix++){

        RectProxyWidget *r=rectProxyItems.at(0);
        rectProxyItems.removeFirst();
        scene->removeItem(r);
        r->deleteLater();
    }
}

void MainWindow::initItems()
{
    //我们先获得有多少个数据，根据scene的宽度来决定。
    //每个数据宽度是多少?


    viewWidth=ui->graphicsView->width();

    viewHeight=ui->graphicsView->height();

    double rectWidth=viewWidth/itemsNum;

    double intetvalX=(viewWidth-(rectWidth*itemsNum))/itemsNum;

    double space=viewHeight/itemsNum;

    double rectHeight;

    qDebug()<<viewHeight<<viewWidth;

    li->setFixedWidth(rectWidth);
    lj->setFixedWidth(rectWidth);
    lk->setFixedWidth(rectWidth);
    lGuard->setFixedWidth(rectWidth);

    //          scene->setSceneRect(0,0,viewWidth,viewHeight);
    Item::setThreshold(itemsNum/2);

    for(int i=0;i<itemsNum;i++){
        rectHeight=space*i;
        Item *rectItem=new Item();
        rectItem->setStandard(i);
        RectProxyWidget *p=new RectProxyWidget(rectItem);
        p->setWidget(rectItem);

        rectItem->setId(i);
        rectItem->setValue(i);
        p->setGeometry(QRectF((intetvalX+rectWidth)*i,viewHeight-rectHeight,rectWidth,rectHeight));
        rectProxyItems.append(p);
    }


    shuffle();
    if(rectProxyItems.size()==1){
        arrowLabelI->setPos(QPoint(rectProxyItems[0]->x(),rectProxyItems[0]->y()-li->height()));
        arrowLabelJ->setPos(QPoint(rectProxyItems[0]->x(),rectProxyItems[0]->y()-lj->height()-lk->height()));
        arrowLabelK->setPos(QPoint(rectProxyItems[0]->x(),rectProxyItems[0]->y()-lj->height()-lk->height()-lk->height()));
    }
    else if(rectProxyItems.size()>=2){
        arrowLabelI->setPos(QPoint(rectProxyItems[0]->x(),rectProxyItems[0]->y()-li->height()));
        arrowLabelJ->setPos(QPoint(rectProxyItems[0]->x(),rectProxyItems[0]->y()-lj->height()-lk->height()));
        arrowLabelK->setPos(QPoint(rectProxyItems[1]->x(),rectProxyItems[1]->y()-lj->height()));

    }
    for(int i=0;i<itemsNum;i++){
        scene->addItem(rectProxyItems.at(i));
    }


}

void MainWindow::shuffle()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    for(int i=0;i<itemsNum;i++){
        int r=qrand()%itemsNum;
        if(r==i){
            continue;
        }

        QRectF rectR1=rectProxyItems.at(i)->geometry();
        QRectF rectR2=rectProxyItems.at(r)->geometry();

        rectProxyItems[r]->setGeometry(QRectF(rectR1.x(),rectR2.y(),rectR2.width(),rectR2.height()).toRect());

        int tempid=rectProxyItems[i]->item->getId();
        rectProxyItems[i]->item->setId(rectProxyItems[r]->item->getId());
        rectProxyItems[r]->item->setId(tempid);

        rectProxyItems[i]->setGeometry(QRectF(rectR2.x(),rectR1.y(),rectR1.width(),rectR1.height()).toRect());



        RectProxyWidget *item=rectProxyItems.at(i);
        rectProxyItems[i]=rectProxyItems[r];
        rectProxyItems[r]=item;
    }


    removeItemsCopy();




    int c=rectProxyItems.size();
    for (int i=0;i<c;i++) {
        RectProxyWidget *copy=new RectProxyWidget(rectProxyItems.at(i));

        rectProxyItemsCopy.append(copy);
    }


}



void MainWindow::swapAni(int i, int j, QGraphicsProxyWidget *iw, QGraphicsProxyWidget *jw)
{

    aniStop=0;

    int temp=rectProxyItems[i]->item->getId();
    rectProxyItems[i]->item->setId(rectProxyItems[j]->item->getId());
    rectProxyItems[j]->item->setId(temp);


    QParallelAnimationGroup *aniGroup=new QParallelAnimationGroup;

    QPropertyAnimation *aniI =new QPropertyAnimation(iw,"pos");

    QPropertyAnimation *aniJ =new QPropertyAnimation(jw,"pos");


    QPropertyAnimation *ani =new QPropertyAnimation(rectProxyItems[i],"pos");

    QPointF r1(rectProxyItems[i]->geometry().x(),rectProxyItems[i]->geometry().y());
    QPointF r2(rectProxyItems[j]->geometry().x(),rectProxyItems[i]->geometry().y());

    aniI->setStartValue(iw->pos());
    aniI->setEndValue(QPointF(rectProxyItems[i]->geometry().x(),rectProxyItems[j]->geometry().y()-lj->height()));
    aniI->setDuration(durationAni);
    aniI->setEasingCurve(QEasingCurve::OutCirc);

    ani->setStartValue(r1);
    ani->setEndValue(r2);
    ani->setDuration(durationAni);

    ani->setEasingCurve(QEasingCurve::OutCirc);

    connect(ani,&QPropertyAnimation::finished,this,[=](){
        rectProxyItems[i]->setPos(r2);
    });

    QPropertyAnimation *ani2 =new QPropertyAnimation(rectProxyItems[j],"pos");
    r1=QPointF(rectProxyItems[j]->geometry().x(),rectProxyItems[j]->geometry().y());
    r2=QPointF(rectProxyItems[i]->geometry().x(),rectProxyItems[j]->geometry().y());

    aniJ->setStartValue(jw->pos());
    aniJ->setEndValue(QPointF(rectProxyItems[j]->geometry().x(),rectProxyItems[i]->geometry().y()-lj->height()));
    aniJ->setDuration(durationAni);
    aniJ->setEasingCurve(QEasingCurve::OutCirc);

    ani2->setStartValue(r1);
    ani2->setEndValue(r2);
    ani2->setDuration(durationAni);

    ani2->setEasingCurve(QEasingCurve::OutCirc);

    connect(ani2,&QPropertyAnimation::finished,this,[=](){
        rectProxyItems[j]->setPos(r2);

    });
    aniGroup->addAnimation(ani);
    aniGroup->addAnimation(ani2);
    aniGroup->addAnimation(aniI);
    aniGroup->addAnimation(aniJ);

    aniGroup->start(QAbstractAnimation::DeleteWhenStopped);

    connect(aniGroup,&QParallelAnimationGroup::finished,this,[=](){
        aniStop=1;
        RectProxyWidget *item=rectProxyItems[i];
        rectProxyItems[i]=rectProxyItems[j];
        rectProxyItems[j]=item;
    });



    while(!aniStop){
        Sleep(durationAni);
    }

}

void MainWindow::selectSorting()
{
    labelNumI->show();
    labelNumK->hide();
    arrowLabelK->hide();
    arrowLabelGuard->hide();
    for(int i=0;i<rectProxyItems.size();i++){
        static_cast<QLabel*>(labelNumI->widget())->setText("i="+QString::number(i)+",i<"+QString::number(rectProxyItems.size()));
        static_cast<QLabel*>(labelNumI->widget())->adjustSize();
        widgetSwapAni(arrowLabelI,rectProxyItems[i],1);
        for(int j=i+1;j<=rectProxyItems.size()-1;++totalStepCount,j++){
            static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<="+QString::number(rectProxyItems.size()-1));
            static_cast<QLabel*>(labelNumJ->widget())->adjustSize();

            widgetSwapAni(arrowLabelJ,rectProxyItems[j],1);
            if(!sorting){
                return;
            }
            if(smallToLarge){
                if(rectProxyItems[i]->item->getValue()>rectProxyItems[j]->item->getValue()){
                    swapAni(i,j,arrowLabelI,arrowLabelJ);
                    totalSwapCount++;
                }
                else{
                    totalCmpCount++;
                }
            }
            else{
                if(rectProxyItems[i]->item->getValue()<rectProxyItems[j]->item->getValue()){
                    swapAni(i,j,arrowLabelI,arrowLabelJ);
                    totalSwapCount++;
                }
                else{
                    totalCmpCount++;
                }
            }


            ui->lcdNumber->display(totalStepCount);
            ui->lcdNumber_2->display(totalCmpCount);
            ui->lcdNumber_3->display(totalSwapCount);

        }
    }
}

void MainWindow::bubbleSorting()
{
    labelNumK->show();
    arrowLabelK->show();
    arrowLabelI->hide();
    arrowLabelGuard->hide();
    for(int i=0;i<rectProxyItems.size()-1;i++){
        static_cast<QLabel*>(labelNumI->widget())->setText("i="+QString::number(i)+",i<"+QString::number(rectProxyItems.size()));
        static_cast<QLabel*>(labelNumI->widget())->adjustSize();
        for(int j=0;j<rectProxyItems.size()-i-1;++totalStepCount,j++){


            static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<"+QString::number(rectProxyItems.size()-i));
            static_cast<QLabel*>(labelNumJ->widget())->adjustSize();


            static_cast<QLabel*>(labelNumK->widget())->setText("k=j-1="+QString::number(j-1));
            static_cast<QLabel*>(labelNumK->widget())->adjustSize();

            widgetSwapAni(arrowLabelJ,rectProxyItems[j],0);
            widgetSwapAni(arrowLabelK,rectProxyItems[j+1],1);

            if(!sorting){
                return;
            }
            if(smallToLarge){
                if(rectProxyItems[j]->item->getValue()>rectProxyItems[j+1]->item->getValue()){
                    swapAni(j,j+1,arrowLabelK,arrowLabelJ);
                    totalSwapCount++;
                }
                else{
                    ++totalCmpCount;
                }
            }
            else{
                if(rectProxyItems[j]->item->getValue()<rectProxyItems[j+1]->item->getValue()){
                    swapAni(j,j+1,arrowLabelK,arrowLabelJ);
                    totalSwapCount++;
                }
                else{
                    ++totalCmpCount;
                }
            }
            ui->lcdNumber->display(totalStepCount);
            ui->lcdNumber_2->display(totalCmpCount);
            ui->lcdNumber_3->display(totalSwapCount);
        }
    }

}

void MainWindow::bubbleSortingEx()
{
    labelNumK->show();
    arrowLabelK->show();
    arrowLabelI->hide();
    arrowLabelGuard->hide();



    for(int i=0;i<rectProxyItems.size()-1;i++){
        bool isSorted=1;
        static_cast<QLabel*>(labelNumI->widget())->setText("i="+QString::number(i)+",i<"+QString::number(rectProxyItems.size()));
        static_cast<QLabel*>(labelNumI->widget())->adjustSize();

        for(int j=0;j<rectProxyItems.size()-i-1;++totalStepCount,j++){


            static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<"+QString::number(rectProxyItems.size()-i));
            static_cast<QLabel*>(labelNumJ->widget())->adjustSize();

            static_cast<QLabel*>(labelNumK->widget())->setText("k=j-1="+QString::number(j-1));
            static_cast<QLabel*>(labelNumK->widget())->adjustSize();

            widgetSwapAni(arrowLabelJ,rectProxyItems[j],0);
            widgetSwapAni(arrowLabelK,rectProxyItems[j+1],1);

            if(!sorting){
                return;
            }
            if(smallToLarge){
                if(rectProxyItems[j]->item->getValue()>rectProxyItems[j+1]->item->getValue()){
                    swapAni(j,j+1,arrowLabelK,arrowLabelJ);
                    totalSwapCount++;
                    isSorted = 0;
                }
                else{
                    ++totalCmpCount;
                }
            }
            else{
                if(rectProxyItems[j]->item->getValue()<rectProxyItems[j+1]->item->getValue()){
                    swapAni(j,j+1,arrowLabelK,arrowLabelJ);
                    totalSwapCount++;
                    isSorted = 0;
                }
                else{
                    ++totalCmpCount;
                }
            }

            ui->lcdNumber->display(totalStepCount);
            ui->lcdNumber_2->display(totalCmpCount);
            ui->lcdNumber_3->display(totalSwapCount);

        }
        if(isSorted)
            break;
    }
}

void MainWindow::insertSorting()
{

    labelNumK->show();
    arrowLabelK->show();
    arrowLabelI->hide();
    for(int i=1;i<rectProxyItems.size();i++){
        static_cast<QLabel*>(labelNumI->widget())->setText("i="+QString::number(i)+",i<"+QString::number(rectProxyItems.size()));
        static_cast<QLabel*>(labelNumI->widget())->adjustSize();
        for(int j=i;j>0;++totalStepCount,--j){

            static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<"+QString::number(rectProxyItems.size()-i));
            static_cast<QLabel*>(labelNumJ->widget())->adjustSize();
            static_cast<QLabel*>(labelNumK->widget())->setText("k=j-1="+QString::number(j-1));
            static_cast<QLabel*>(labelNumK->widget())->adjustSize();

            widgetSwapAni(arrowLabelJ,rectProxyItems[j],0);
            widgetSwapAni(arrowLabelK,rectProxyItems[j-1],1);

            if(!sorting){
                return;
            }
           if(smallToLarge){
            if(rectProxyItems[j]->item->getValue()<rectProxyItems[j-1]->item->getValue()){
                swapAni(j,j-1,arrowLabelK,arrowLabelJ);
                totalSwapCount++;
            }
            else{
                ++totalCmpCount;
            }
           }
           else{
               if(rectProxyItems[j]->item->getValue()>rectProxyItems[j-1]->item->getValue()){
                   swapAni(j,j-1,arrowLabelK,arrowLabelJ);
                   totalSwapCount++;
               }
               else{
                   ++totalCmpCount;
               }
           }
            ui->lcdNumber->display(totalStepCount);
            ui->lcdNumber_2->display(totalCmpCount);
            ui->lcdNumber_3->display(totalSwapCount);
        }
    }
}

void MainWindow::insertSortingEx()
{
    labelNumK->show();
    arrowLabelK->show();
    arrowLabelI->hide();
    arrowLabelGuard->show();
    int i,j;
    for(i=1;i<rectProxyItems.size();i++){
        static_cast<QLabel*>(labelNumI->widget())->setText("i="+QString::number(i)+",i<"+QString::number(rectProxyItems.size()));
        static_cast<QLabel*>(labelNumI->widget())->adjustSize();
        if(smallToLarge){
            if( rectProxyItems[i]->item->getValue()<rectProxyItems[i-1]->item->getValue())
            {
                //temp是哨兵
                int temp=rectProxyItems[i]->item->getValue();
                static_cast<QLabel*>(labelNumGuard->widget())->setText("g="+QString::number(temp));
                static_cast<QLabel*>(labelNumGuard->widget())->adjustSize();
                widgetSwapAni(arrowLabelGuard,rectProxyItems[i],1);
                for(j=i-1;j>=0;++totalStepCount,j--)
                {
                    if(rectProxyItems[j]->item->getValue()>temp){
                        static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<"+QString::number(rectProxyItems.size()-i));
                        static_cast<QLabel*>(labelNumJ->widget())->adjustSize();
                        static_cast<QLabel*>(labelNumK->widget())->setText("k=j-1="+QString::number(j-1));
                        static_cast<QLabel*>(labelNumK->widget())->adjustSize();
                        widgetSwapAni(arrowLabelJ,rectProxyItems[j],0);
                        widgetSwapAni(arrowLabelK,rectProxyItems[j+1],1);
                        if(!sorting){
                            return;
                        }
                        swapAni(j+1,j,arrowLabelK,arrowLabelJ);
                        widgetSwapAni(arrowLabelGuard,rectProxyItems[j+1],0);
                        totalSwapCount++;
                    }
                    else{
                        ++totalCmpCount;
                        break;
                    }
                    ui->lcdNumber->display(totalStepCount);
                    ui->lcdNumber_2->display(totalCmpCount);
                    ui->lcdNumber_3->display(totalSwapCount);
                }
                rectProxyItems[j+1]->item->setValue(temp);
            }
            else{
                ++totalCmpCount;
            }
        }
        else{
            if( rectProxyItems[i]->item->getValue()>rectProxyItems[i-1]->item->getValue())
            {
                //temp是哨兵
                int temp=rectProxyItems[i]->item->getValue();
                static_cast<QLabel*>(labelNumGuard->widget())->setText("g="+QString::number(temp));
                static_cast<QLabel*>(labelNumGuard->widget())->adjustSize();
                widgetSwapAni(arrowLabelGuard,rectProxyItems[i],1);
                for(j=i-1;j>=0;++totalStepCount,j--)
                {
                    if(rectProxyItems[j]->item->getValue()<temp){
                        static_cast<QLabel*>(labelNumJ->widget())->setText("j="+QString::number(j)+",j<"+QString::number(rectProxyItems.size()-i));
                        static_cast<QLabel*>(labelNumJ->widget())->adjustSize();
                        static_cast<QLabel*>(labelNumK->widget())->setText("k=j-1="+QString::number(j-1));
                        static_cast<QLabel*>(labelNumK->widget())->adjustSize();
                        widgetSwapAni(arrowLabelJ,rectProxyItems[j],0);
                        widgetSwapAni(arrowLabelK,rectProxyItems[j+1],1);
                        if(!sorting){
                            return;
                        }
                        swapAni(j+1,j,arrowLabelK,arrowLabelJ);
                        arrowLabelGuard->setPos(arrowLabelK->pos());
                        totalSwapCount++;
                    }
                    else{
                        ++totalCmpCount;
                        break;
                    }
                    ui->lcdNumber->display(totalStepCount);
                    ui->lcdNumber_2->display(totalCmpCount);
                    ui->lcdNumber_3->display(totalSwapCount);
                }
                rectProxyItems[j+1]->item->setValue(temp);
            }
            else{
                ++totalCmpCount;
            }
        }


    }
}



void MainWindow::widgetSwapAni(QGraphicsProxyWidget *w, RectProxyWidget *w2, bool wait)
{
    aniStop=0;
    QPropertyAnimation *aniW =new QPropertyAnimation(w,"pos");

    aniW->setStartValue(w->pos());
    aniW->setEndValue(QPointF(w2->geometry().x(),w2->geometry().y()-w->rect().height()));
    aniW->setDuration(durationAni);
    aniW->setEasingCurve(QEasingCurve::OutCirc);

    aniW->start(QAbstractAnimation::DeleteWhenStopped);

    connect(aniW,&QPropertyAnimation::finished,this,[=](){
        aniStop=1;

    });
    if(wait)
        while(!aniStop){
            Sleep(durationAni);
        }
}

void MainWindow::initWidget()
{
    durationAni=ui->aniDuration->text().toInt();
    itemsToNum=ui->itemsNum->text().toInt();

    initArrowLabel(li,arrowLabelI,QPixmap(":/箭头.svg"));
    initArrowLabel(lj,arrowLabelJ,QPixmap(":/箭头2.svg"));
    initArrowLabel(lk,arrowLabelK,QPixmap(":/箭头3.svg"));
    initArrowLabel(lGuard,arrowLabelGuard,QPixmap(":/哨兵_2.svg"));

    arrowLabelGuard->hide();

    initNumLabel("i=0,","color: rgb(212, 35, 122)",QPointF(0,0),labelNumI);
    initNumLabel("j=0,","color: rgb(18,150,219)",labelNumI->geometry().bottomLeft(),labelNumJ);
    initNumLabel("k=0,","color: rgb(19,34,122)",labelNumJ->geometry().bottomLeft(),labelNumK);
    initNumLabel("g=0","color: rgb(0,0,0)",labelNumK->geometry().bottomLeft(),labelNumGuard);
}

void MainWindow::on_sortingBtn_clicked()
{
    unable();
    sorting=1;
    switch (ui->sortingtype->currentIndex()) {
    case SELECT_SORTING:
        selectSorting();
        break;
    case BUBBLE_SORTING:
        bubbleSorting();
        break;
    case INSERT_SORTING:
        insertSorting();
        break;
    case BUBBLE_EX_SORTING:

        bubbleSortingEx();
        break;
    case INSERT_EX_SORTING:

        insertSortingEx();
        break;
    default:
        break;
    }
    //    for(int i=0;i<rectProxyItems.size();i++){
    //        qDebug()<<rectProxyItems[i]->item->value;
    //    }
    enable();

}

void MainWindow::on_shuffleBtn_clicked()
{
    totalStepCount=0;
    totalCmpCount=0;
    totalSwapCount=0;

    shuffle();
}


void MainWindow::on_stopSortingBtn_clicked()
{
    sorting=0;
    aniStop=1;
}

void MainWindow::on_itemsNum_textChanged(const QString &arg1)
{
    itemsToNum=ui->itemsNum->text().toInt();
    if(itemsToNum>0){
        removeItems();
        itemsNum=itemsToNum;
        initItems();
    }

    else{
        QMessageBox::warning(this,"一定要大于0","一定要大于0",QMessageBox::NoButton);
    }
}

void MainWindow::on_aniDuration_textChanged(const QString &arg1)
{
    if(ui->aniDuration->text().toInt()>=1)
        durationAni=ui->aniDuration->text().toInt();
    else{
        QMessageBox::warning(this,"一定要>=1","一定要大于>=1",QMessageBox::NoButton);
    }
}

void MainWindow::on_sortingtype_currentIndexChanged(int index)
{

    switch (index) {
    case SELECT_SORTING:

        break;
    case BUBBLE_SORTING:

        break;
    case INSERT_SORTING:

        break;
    default:
        break;
    }
    totalStepCount=0;
    totalCmpCount=0;
    totalSwapCount=0;
}

void MainWindow::on_restoreBtn_clicked()
{
    totalStepCount=0;
    totalCmpCount=0;
    totalSwapCount=0;

    removeItems();

    int c=rectProxyItemsCopy.size();
    for (int i=0;i<c;i++) {
        RectProxyWidget *copy=new RectProxyWidget(rectProxyItemsCopy.at(i));
        copy->show();
        scene->addItem(copy);
        rectProxyItems.append(copy);

    }

    if(rectProxyItems.size()>=2){
        arrowLabelI->setPos(QPoint(rectProxyItemsCopy[0]->x(),rectProxyItemsCopy[0]->y()-li->height()));
        arrowLabelJ->setPos(QPoint(rectProxyItemsCopy[0]->x(),rectProxyItemsCopy[0]->y()-lj->height()));
        arrowLabelK->setPos(QPoint(rectProxyItemsCopy[1]->x(),rectProxyItemsCopy[1]->y()-lj->height()));
    }


}

void MainWindow::on_checkBox_clicked(bool checked)
{
    smallToLarge=checked;
}
