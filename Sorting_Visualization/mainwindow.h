#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QGraphicsScene>
#include <QMainWindow>
#include <qlabel.h>
#include "item.h"
#include "rectproxywidget.h"
#include "titlebar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    TitleBar *titlebar=new TitleBar();

    QGraphicsScene *scene = new QGraphicsScene();

    int viewWidth;
    int viewHeight;
    int itemsNum=10;
    int itemsToNum;
    int itemsIdFontSize=15;


    bool smallToLarge=1;

    QLabel *li=new QLabel();
    QLabel *lj=new QLabel();
    QLabel *lk=new QLabel();
    QLabel *lGuard=new QLabel();



    QGraphicsProxyWidget *labelNumI=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *labelNumJ=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *labelNumK=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *labelNumGuard=new QGraphicsProxyWidget();

    QGraphicsProxyWidget *arrowLabelI=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *arrowLabelJ=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *arrowLabelK=new QGraphicsProxyWidget();
    QGraphicsProxyWidget *arrowLabelGuard=new QGraphicsProxyWidget();

    int durationAni=1000;
    int totalStepCount=0;
    int totalCmpCount=0;
    int totalSwapCount=0;

    bool aniStop=0;
    bool sorting=0;

    enum {
        SELECT_SORTING,
        BUBBLE_SORTING,
        INSERT_SORTING,
        BUBBLE_EX_SORTING,
        INSERT_EX_SORTING

    };

    QVector<RectProxyWidget*> rectProxyItems;

    QVector<RectProxyWidget*> rectProxyItemsCopy;

    QVector<QRectF> rectRectF;

    void Sleep(int msec);

    void unable();
    void enable();

    void initItems();
    void initItems(QVector<RectProxyWidget*> proxyItems);
    void initArrowLabel(QLabel *l,QGraphicsProxyWidget *arrow,QPixmap pix);
    void initNumLabel(QString text,QString style,QPointF pos,QGraphicsProxyWidget *labelNum);

    void removeItemsCopy();
    void removeItems();

    void shuffle();
    void swapAni(int i,int j,QGraphicsProxyWidget *iw,QGraphicsProxyWidget *jw);

    void selectSorting();
    void bubbleSorting();
    void bubbleSortingEx();
    void insertSorting();
    void insertSortingEx();
    void widgetSwapAni(QGraphicsProxyWidget *w,RectProxyWidget *w2,bool wait);

    void initWidget();
private slots:
    void on_sortingBtn_clicked();

    void on_shuffleBtn_clicked();


    void on_stopSortingBtn_clicked();

    void on_itemsNum_textChanged(const QString &arg1);

    void on_aniDuration_textChanged(const QString &arg1);

    void on_sortingtype_currentIndexChanged(int index);

    void on_restoreBtn_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
