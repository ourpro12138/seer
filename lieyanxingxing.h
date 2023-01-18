#ifndef LIEYANXINGXING_H
#define LIEYANXINGXING_H

#include <QWidget>
#include <QMovie>
#include "elf.h"
#include "partner.h"
#include "map.h"
class LieYanXingXing : public Partner
{

public:

    LieYanXingXing(int i,int j);
  ~ LieYanXingXing();

    void advance(int phase);
 bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void skill();

};

#endif // LIEYANXINGXING_H
