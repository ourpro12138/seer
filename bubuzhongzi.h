#ifndef BUBUZHONGZI_H
#define BUBUZHONGZI_H

#include <QWidget>
#include "map.h"
#include "elf.h"
#include "enemy.h"
#include "partner.h"

class Bubuzhongzi : public partner
{
public:
    Bubuzhongzi(int i,int j);
     ~Bubuzhongzi();

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

#endif // BUBUZHONGZI_H
