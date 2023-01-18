#ifndef YIYI_H
#define YIYI_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Yiyi : public Partner
{
public:
    Yiyi(int i,int j);
    ~Yiyi();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
    Bullet *bullet;


};
#endif // YIYI_H
