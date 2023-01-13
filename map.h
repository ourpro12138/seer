#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "partner.h"
#include "cards.h"
class Map :public QGraphicsItem
{
public:
    Map();

    partner *myptn[4][5];//四行五列
    Cards *preparedPtn;


//    QRectF boundingRect() const override;;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;;
//    void advance(int phase) override;
//    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;

//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


   ~Map();
};

#endif // MAP_H
