#ifndef NISIKE_H
#define NISIKE_H

#include "enemy.h"
#include"partner.h"

class Nisike : public Enemy
{

public:

    Nisike(int i);
    ~Nisike();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // NISIKE_H
