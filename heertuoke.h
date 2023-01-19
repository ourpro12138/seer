#ifndef HEERTUOKE_H
#define HEERTUOKE_H

#include "enemy.h"
#include"partner.h"

class Heertoke : public Enemy
{

public:

    Heertoke(int i);
    ~Heertoke();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // MOGUGUAI_H
