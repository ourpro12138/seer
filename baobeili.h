#ifndef BAOBEILI_H
#define BAOBEILI_H


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
    Bullet *bullet;
};
class YuanGuYuLong:public Baobeili
{
public:
    YuanGuYuLong(int i,int j);
    ~YuanGuYuLong();
    void skill();
    void evolution();

};
class YuLongWang:public Baobeili
{
public:
    YuLongWang(int i,int j);
    ~YuLongWang();
    void skill();


};

#endif // BAOBEILI_H
