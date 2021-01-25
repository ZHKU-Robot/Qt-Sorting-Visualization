#ifndef RECTPROXYWIDGET_H
#define RECTPROXYWIDGET_H

#include <QObject>
#include <QWidget>
#include <qgraphicsproxywidget.h>
#include "item.h"
class RectProxyWidget : public QGraphicsProxyWidget
{
public:
    RectProxyWidget(Item *item,QGraphicsItem *parent = Q_NULLPTR, Qt::WindowFlags wFlags = Qt::WindowFlags());
    RectProxyWidget(const RectProxyWidget *other);
    ~RectProxyWidget();
    int id;
    int value;
    Item *item;

    int getValue() const;
    void setValue(int value);
    int getId() const;
    void setId(int value);
};

#endif // RECTPROXYWIDGET_H
