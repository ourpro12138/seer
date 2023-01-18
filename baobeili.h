#ifndef BAOBEILI_H
#define BAOBEILI_H

#include <QWidget>

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Baobeili : public Partner
{
public:
    Baobeili(int i,int j);
    ~Baobeili();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
private:
    Bullet *bullet;


};

#endif // BAOBEILI_H
