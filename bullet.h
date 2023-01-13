#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QPointF>
#include <QTime>


class Bullet : public QGraphicsItem
{
public:
   Bullet(QPointF point);
   ~Bullet();
   QRectF boundingRect()const;
//   void release(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
   void advance(int phase);
   bool collideWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
   int type() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
   int posX,posY;
   int ATK;

signals:

};

#endif // BULLET_H
