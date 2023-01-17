#ifndef MOGUGUAI_H
#define MOGUGUAI_H

#include "enemy.h"
#include"partner.h"

class MoGuGuai : public Enemy
{

public:

    MoGuGuai(int i);
    ~MoGuGuai();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // MOGUGUAI_H
