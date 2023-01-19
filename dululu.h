#ifndef DULULU_H
#define DULULU_H

#include <QWidget>
#include "enemy.h"

class Dululu : public Enemy
{

public:
    Dululu(int i);
    ~Dululu();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;


};

#endif // DULULU_H
