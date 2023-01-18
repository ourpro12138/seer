#ifndef XIAOHUOHOU_H
#define XIAOHUOHOU_H
#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class Xiaohuohou : public Partner
{
public:
   Xiaohuohou(int i,int j);
   ~Xiaohuohou();

//   QRectF boundingRect() const;
//   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   void skill();
   void evolution();
};
class LieHuoHou : public Xiaohuohou
{
public:
   LieHuoHou(int i,int j);
   ~LieHuoHou();
};

class Lieyanxingxing : public Xiaohuohou
{
public:
   Lieyanxingxing(int i,int j);
   ~Lieyanxingxing();
};

#endif // XIAOHUOHOU_H
