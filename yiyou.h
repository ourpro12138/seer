#ifndef YIYOU_H
#define YIYOU_H

#include "elf.h"
#include "partner.h"
#include "map.h"
#include "bullet.h"

class Yiyou : public partner
{
public:
    Yiyou(QPointF point);
    ~Yiyou();
    void advance(int phase);
private:
    Bullet *bullet;
    int bulletCounter,bulletCreateTime;

signals:


};

#endif // YIYOU_H
