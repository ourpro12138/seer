#ifndef LIEHUOHOU_H
#define LIEHUOHOU_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class LieHuoHou : public Partner
{

public:
    LieHuoHou(int i,int j);
  ~ LieHuoHou();

    void advance(int phase);
 bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();

};

#endif // LIEHUOHOU_H
