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

#endif // XIAODOUYA_H
