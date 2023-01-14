#ifndef PARTNER_H
#define PARTNER_H
#include "elf.h"
#include <QPainter>
class partner :public Elf
{
public:
    partner();

    virtual void skill()=0;

    virtual void evolution()=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    int type() const;
    ~partner();
    int i;
    int j;

    int width;
    int height;

};

#endif // PARTNER_H
