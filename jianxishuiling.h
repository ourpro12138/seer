#ifndef jingxishuiling_H
#define jianxishuiling_H

#include "enemy.h"
#include"partner.h"

class Jianxishuiling : public Enemy
{

public:

    Jianxishuiling(int i);
    ~Jianxishuiling();
    void advance(int phase);
bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const override;

};

#endif // jianxishuiling_H
