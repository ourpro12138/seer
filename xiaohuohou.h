#ifndef XIAOHUOHOU_H
#define XIAOHUOHOU_H
#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Xiaohuohou : public partner
{
public:
   Xiaohuohou(int i,int j);
   ~Xiaohuohou();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);

   void skill();
   void evolution();

private:
   int prepareTime,counter;
   bool atkStatus;
   


};

#endif // XIAOHUOHOU_H
