#ifndef AGONG_H
#define AGONG_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Agong : public Partner
{
public:
   Agong(int i,int j);
   ~Agong();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   void skill();
   void evolution();
};
class BoBoGong:public Agong
{
public:
    BoBoGong(int i,int j);
    ~BoBoGong();
    void skill();
    void evolution();
};
class AoLiGong:public Agong
{
public:
    AoLiGong(int i,int j);
    ~AoLiGong();
    void skill();

};

#endif // AGONG_H
