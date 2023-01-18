#ifndef BUBUZHONGZI_H
#define BUBUZHONGZI_H

#include <QWidget>
#include "map.h"
#include "elf.h"
#include "enemy.h"
#include "partner.h"

class Bubuzhongzi : public Partner
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

   int treatCounter,treatCreateTime;


signals:

};
class BuBuCao : public Bubuzhongzi
{
public:
    BuBuCao(int i,int j);
    void evolution();
    void skill();
     ~BuBuCao();


};
class BuBuHua : public Bubuzhongzi
{
public:
    BuBuHua(int i,int j);
    void skill();
     ~BuBuHua();


};
#endif // BUBUZHONGZI_H
