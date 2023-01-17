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
    void advance(int phase);
 bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
private:
    Bullet *bullet;
    int bulletCounter,bulletCreateTime;


};

#endif // YIYOU_H
