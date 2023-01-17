#ifndef TAQIDUOKE_H
#define TAQIDUOKE_H

#include <QWidget>
#include "enemy.h"

class Taqiduoke : public Enemy
{

public:
    Taqiduoke(int i);
    ~Taqiduoke();
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;


};

#endif // TAQIDUOKE_H
