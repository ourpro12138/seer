#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QApplication>
#include "yiyou.h"
#include "xiaohuohou.h"
#include "bubuzhongzi.h"
#include "dugulu.h"
#include "yiyi.h"
#include "dida.h"
#include <QDebug>
#include "taida.h"
#include "xinke.h"
#include "huliya.h"
#include "agong.h"
#include "jier.h"
#include "guodongya.h"
#include "xiaodouya.h"
#include "beier.h"
#include "baobeili.h"
#include "partner.h"
#include "cards.h"
#include "xianrenqiu.h"
class Map :public QGraphicsItem
{
public:
    Map();

    static Partner *myptn[4][5];//四行五列
    Cards *preparedPtn;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


    ~Map();
};

#endif // MAP_H
