#ifndef JIER_H
#define JIER_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Jier : public Partner
{
public:
    Jier(int i,int j);
    ~Jier();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
private:
    Bullet *bullet;


};
#endif // JIER_H
