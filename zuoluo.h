#ifndef ZUOLUO_H
#define ZUOLUO_H

#include"enemy.h"
#include"partner.h"

class ZuoLuo : public Enemy
{
public:
    ZuoLuo(int i);
    ~ZuoLuo();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;



};

#endif // ZUOLUO_H
