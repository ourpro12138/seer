#ifndef ENEMY_H
#define ENEMY_H
#include "elf.h"
#include<QGraphicsItem>
#include<QPainter>
#include<QRectF>
#include<QMovie>
class Enemy: public Elf
{
public:
    Enemy();
    int atk;//攻击
    int hp;//血
    int attritube;//属性
    int posX,posY;//位置
    QString name;//名字
    QMovie *movemovie;//移动动画
    int speedFactor;
    qreal speed;
    int setStatus;
    int nowStatus;




//   QRectF boundingRect() const override;
//    void paint(QPainter *painter,const QStyleOptionGraphicsItem *opition,QWidget *widget) override;
//    void advance(int phase);
//    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;


    int benefit;
    ~Enemy();
};

#endif // ENEMY_H
