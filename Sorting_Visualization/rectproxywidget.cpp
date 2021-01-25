#include "rectproxywidget.h"

RectProxyWidget::RectProxyWidget(Item *item, QGraphicsItem *parent, Qt::WindowFlags wFlags):QGraphicsProxyWidget(parent,wFlags)
{
    this->item=item;
    setWidget(item);
//    setAttribute(Qt::WA_DeleteOnClose);
}

RectProxyWidget::RectProxyWidget(const RectProxyWidget *other)
{
//    setAttribute(Qt::WA_DeleteOnClose);
    Item *it =new Item(other->item);
    new(this) RectProxyWidget(it);
    setGeometry(other->geometry());
    this->id=other->id;
    this->value=other->value;
}

RectProxyWidget::~RectProxyWidget()
{

}

int RectProxyWidget::getId() const
{
    return id;
}

void RectProxyWidget::setId(int value)
{
    id = value;
}

int RectProxyWidget::getValue() const
{
    return value;
}

void RectProxyWidget::setValue(int value)
{
    this->value = value;

}
