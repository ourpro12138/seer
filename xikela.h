#ifndef XIKELA_H
#define XIKELA_H

#include <QWidget>
#include "enemy.h"

class Xikela : public Enemy
{

public:
    Xikela(int i);
    ~Xikela();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;


};

#endif // XIKELA_H
