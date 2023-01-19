#ifndef SAILATU_H
#define SAILATU_H

#include <QWidget>
#include "enemy.h"

class Sailatu : public Enemy
{

public:
    Sailatu(int i);
    ~Sailatu();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;


};

#endif // SAILATU_H
