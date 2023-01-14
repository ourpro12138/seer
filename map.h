#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QApplication>
#include "yiyou.h"
#include "xiaohuohou.h"
#include "bubuzhongzi.h"


#include "partner.h"
#include "cards.h"
class Map :public QGraphicsItem
{
public:
    Map();

    static partner *myptn[4][5];//四行五列
    Cards *preparedPtn;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


    ~Map();
};

#endif // MAP_H
