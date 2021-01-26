#ifndef ITEM_H
#define ITEM_H

#include <QWidget>

namespace Ui {
class Item;
}

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(QWidget *parent = 0);
    ~Item();
    Item(const Item *other);

    int id;
    int value;
    static int threshold;
    int standard;
    int brightness=1;
    int gradiantRMax=255,gradiantGMax=255,gradiantBMax=10;

    Ui::Item *ui;





static int getThreshold();
static void setThreshold(int value);

int getStandard() const;
void setStandard(int value);

int getBrightness() const;
void setBrightness(int value);

int getId() const;
void setId(int value);

int getValue() const;
void setValue(int value);
protected:
    void paintEvent(QPaintEvent *event);
private:

};

#endif // ITEM_H
