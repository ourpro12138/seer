#ifndef XINGJILA_H
#define XINGJILA_H

#include "enemy.h"
#include"partner.h"

class Xingjila : public Enemy
{

public:

    Xingjila(int i);
    ~Xingjila();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // XINGJILA_H
