#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QPointF>
#include "enemy.h"
#include <QTime>


class Bullet : public QGraphicsItem
{
public:
    enum{Type=UserType+3};
   Bullet(int i,int j);
   ~Bullet();
   QRectF boundingRect()const;
   void advance(int phase);
   bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   int type() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
   int ATK;
private:
   int posX,posY;

};

#endif // BULLET_H
