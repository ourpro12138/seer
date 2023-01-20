#ifndef BOGE_H
#define BOGE_H

#include "enemy.h"
#include"partner.h"

class Boge : public Enemy
{

public:

    Boge(int i);
    ~Boge();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // BOGE_H
