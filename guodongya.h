#ifndef GUODONGYA_H
#define GUODONGYA_H

#include <QWidget>
#include "map.h"
#include "elf.h"
#include "enemy.h"
#include "partner.h"

class Guodongya : public Partner
{
public:
     Guodongya(int i,int j);
     ~ Guodongya();

//    QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void treatment(int i,int j);

    void skill();
    void evolution();


signals:

};
class BoLangYa:public Guodongya
{
public:
    void skill();
    void evolution();

    BoLangYa(int i,int j);
    ~BoLangYa();



};

class ShuiJingYa:public Guodongya
{
public:
    void skill();
    ShuiJingYa(int i,int j);
    ~ShuiJingYa();


};
#endif // GUODONGYA_H
