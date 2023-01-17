#ifndef BEIER_H
#define BEIER_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Beier : public Partner
{
public:
   Beier(int i,int j);
   ~Beier();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   void skill();
   void evolution();




};

#endif // BEIER_H
