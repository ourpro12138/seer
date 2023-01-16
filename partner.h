#ifndef PARTNER_H
#define PARTNER_H
#include "elf.h"
#include <QPainter>

class Enemy;
class Partner :public Elf
{
public:
    Partner();

    virtual void skill()=0;

    virtual void evolution()=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    int type() const;
    ~Partner();
    int i;
    int j;
    int setStatus;
    int nowStatus;


private:
    Enemy *enemy;
};

#endif // PARTNER_H
