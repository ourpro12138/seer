#ifndef ENEMY_H
#define ENEMY_H
#include "elf.h"
#include<QGraphicsItem>
#include <QGraphicsScene>
#include<QPainter>
#include<QRectF>
#include<QMovie>
#include<QDebug>
#include"partner.h"

class Enemy: public Elf
{
public:
    enum {Type=UserType+2};

    Enemy();
//    int atk;//攻击
//    int hp;//血
//    int attritube;//属性
    int i;//出现的位置
//    QString name;//名字

    int speedFactor;//移动系数
    qreal speed;//速度系数
    int setStatus;//设立状态
    int nowStatus;//现在状态
    //bool isSurvive;//是否存活




    void atkMovie(QString pic);
    //QMovie *movie;


    QRectF boundingRect() const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *opition,QWidget *widget) override;
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;
    int type() const;
    qreal posX;



    int benefit; //击破后得到的收益

    ~Enemy();
private:
        Partner *partner;
};

#endif // ENEMY_H
