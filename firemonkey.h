#ifndef FIREMONKEY_H
#define FIREMONKEY_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Firemonkey : public partner
{
    Q_OBJECT
public:
   Firemonkey(int i,int j);
   ~Firemonkey();

   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);


signals:

};

#endif // FIREMONKEY_H
