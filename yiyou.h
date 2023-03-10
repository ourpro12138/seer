#ifndef YIYOU_H
#define YIYOU_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Yiyou : public Partner
{
public:
    Yiyou(int i,int j);
    ~Yiyou();
    Yiyou();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
    Bullet *bullet;
};
class YouLiAn : public Yiyou
{
public:
   YouLiAn(int i,int j);
   void skill();
   void evolution();
   ~YouLiAn();
};
class BaLuSi : public  Yiyou
{
public:
    BaLuSi(int i,int j);
    void skill();
    ~BaLuSi();

};
#endif // YIYOU_H
