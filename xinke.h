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


#endif // XINKE_H
