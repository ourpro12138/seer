#ifndef XIAODOUYA_H
#define XIAODOUYA_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Xiaodouya : public Partner
{
public:
   Xiaodouya(int i,int j);
   ~Xiaodouya();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   void skill();
   void evolution();
};
class DingDing:public Xiaodouya
{
public:
    DingDing(int i,int j);
    ~DingDing();
    void skill();
    void evolution();
};
class MoHuaXianZi:public Xiaodouya
{
public:
    MoHuaXianZi(int i,int j);
    ~MoHuaXianZi();
    void skill();
};

#endif // XIAODOUYA_H
