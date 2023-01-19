#ifndef JIER_H
#define JIER_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Jier : public Partner
{
public:
    Jier(int i,int j);
    ~Jier();
    void advance(int phase);
// bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();
    void evolution();
private:
    Bullet *bullet;


};
class Linuo:public Jier
{
public:
    Linuo(int i,int j);
void skill();
void evolution();
    ~Linuo();
};

class Luojilasi:public Jier
{
public:
    Luojilasi(int i,int j);
void skill();
    ~Luojilasi();
};


#endif // JIER_H
