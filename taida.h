#ifndef TAIDA_H
#define TAIDA_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Taida : public Partner
{
public:
  Taida(int i,int j);
   ~Taida();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   void skill();
   void evolution();




};

#endif // TAIDA_H
