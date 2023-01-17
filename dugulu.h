#ifndef DUGULU_H
#define DUGULU_H

#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"

class DuGuLu : public Partner
{

public:
    DuGuLu(int i,int j);
    ~DuGuLu();

    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const;
    void skill();
    void evolution();


signals:

};

#endif // DUGULU_H
