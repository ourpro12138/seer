#ifndef XIANRENQIU_H
#define XIANRENQIU_H
#include "partner.h"
#include "bullet.h"

class Xianrenqiu:public Partner
{
public:
    Xianrenqiu(int i,int j);
    ~Xianrenqiu();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
};

#endif // XIANRENQIU_H
