#include "item.h"
#include "ui_item.h"
#include "QDebug"
#include <QPainter>
int Item::threshold=0;
Item::Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item)
{
    ui->setupUi(this);
//    setAttribute(Qt::WA_DeleteOnClose);
}

Item::~Item()
{
    delete ui;
}

Item::Item(const Item *other)
{
//    setAttribute(Qt::WA_DeleteOnClose);
//    new(this) Item();

    setValue(other->value);
    setId(other->id);
    setStandard(other->standard);
    setThreshold(other->threshold);

    other->ui->setupUi(this);


}



int Item::getValue() const
{
    return value;
}

void Item::setValue(int value)
{
    this->value = value;
//    ui->v->setText("value:"+QString::number(value));
}

int Item::getId() const
{
    return id;
}

void Item::setId(int value)
{
    id = value;
//    ui->id->setText("ID:"+QString::number(id));
}

int Item::getBrightness() const
{
    return brightness;
}

void Item::setBrightness(int value)
{
    brightness = value;
}

int Item::getStandard() const
{
    return standard;
}

void Item::setStandard(int value)
{
    standard = value;
}

int Item::getThreshold()
{
    return threshold;
}

void Item::setThreshold(int value)
{
    threshold = value;
}






void Item::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int gradiant=standard*1.0/threshold*gradiantRMax;
    int gradiant2=(2-standard * 1.0 / threshold)* gradiantGMax;

    gradiant=(gradiantRMax>gradiant?gradiant:gradiantRMax )*brightness ;
    gradiant2=gradiantGMax>gradiant2?gradiant2:gradiantGMax;
    gradiant2=(0<gradiant2?gradiant2:0)*brightness;

    QColor color(gradiant,gradiant2,gradiantBMax);
    QPen pen;
    QBrush brush(color);

    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);

    QFont font("微软雅黑");
    font.setBold(1);
    font.setPixelSize(width()/5);
    painter.setFont(font);

    painter.fillRect(QRect(0,0,width(),height()),brush);

    painter.drawText(QRect(0,0,width(),height()), Qt::AlignCenter,"value:"+QString::number(value));
    painter.drawText(QRect(0,0,width(),height()/2), Qt::AlignCenter,"pos:"+QString::number(id));

    QWidget::paintEvent(event);
}

