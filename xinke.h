#ifndef XINKE_H
#define XINKE_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Xinke : public Partner
{
public:
   Xinke(int i,int j);
    ~Xinke();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
    Bullet *bullet;
};
class Xinnasi:public Xinke
{
public:
    Xinnasi(int i,int j);
    ~Xinnasi();
    void skill();
};

#endif // XINKE_H
