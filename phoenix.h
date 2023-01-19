#ifndef PHOENIX_H
#define PHOENIX_H

#include "enemy.h"
#include"partner.h"

class Phoenix : public Enemy
{

public:

    Phoenix(int i);
    ~Phoenix();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // MOGUGUAI_H
