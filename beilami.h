#ifndef BEILAMI_H
#define BEILAMI_H

#include <QWidget>
#include "enemy.h"

class Beilami : public Enemy
{
public:

    Beilami(int i);
    ~Beilami();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;


};

#endif // BEILAMI_H
