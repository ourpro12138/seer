#ifndef HULIYA_H
#define HULIYA_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Huliya : public Partner
{
public:
   Huliya(int i,int j);
    ~Huliya();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
    Bullet *bullet;


};
class Liaosi : public Huliya
{
public:
    void skill();
   Liaosi(int i,int j);
   ~Liaosi();
};

#endif // HULIYA_H
