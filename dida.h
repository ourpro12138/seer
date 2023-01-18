#ifndef DIDA_H
#define DIDA_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Dida : public Partner
{
public:
     Dida(int i,int j);
    ~ Dida();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
private:
    Bullet *bullet;


};
class Dierke:public Dida
{
public:
     Dierke(int i,int j);
    ~ Dierke();
};

#endif // DIDA_H
