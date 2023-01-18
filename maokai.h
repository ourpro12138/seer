#ifndef MAOKAI_H
#define MAOKAI_H

#include "enemy.h"

class Maokai : public Enemy
{

public:
    Maokai(int i);
    ~Maokai();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

signals:

};

#endif // MAOKAI_H
