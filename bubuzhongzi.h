#ifndef BUBUZHONGZI_H
#define BUBUZHONGZI_H

#include <QWidget>
#include "map.h"
#include "elf.h"
#include "partner.h"

class Bubuzhongzi : public partner
{
public:
    Bubuzhongzi(int i,int j);
     ~Bubuzhongzi();

    QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

private:
   int prepareTime,counter;
   bool atkStatus;


signals:

};

#endif // BUBUZHONGZI_H
