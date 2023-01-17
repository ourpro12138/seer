#ifndef GANGYASHA_H
#define GANGYASHA_H


#include "enemy.h"
#include"partner.h"

class GangYaSha : public Enemy
{
public:

    GangYaSha(int i);
    ~GangYaSha();
     void advance(int phase);
 bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;
};

#endif // GANGYASHA_H
