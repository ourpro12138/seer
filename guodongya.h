#ifndef GUODONGYA_H
#define GUODONGYA_H

#include <QWidget>
#include "map.h"
#include "elf.h"
#include "enemy.h"
#include "partner.h"

class Guodongya : public Partner
{
public:
     Guodongya(int i,int j);
     ~ Guodongya();

//    QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void treatment(int i,int j);

    void skill();
    void evolution();
private:
   int treatCounter,treatCreateTime;


signals:

};

#endif // GUODONGYA_H
