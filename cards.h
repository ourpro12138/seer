#ifndef CARDS_H
#define CARDS_H

#include <QGraphicsItem>
#include <QPainter>

class Cards : public QGraphicsItem
{
public:
    int No,zuanshiNeed;//精灵编号，所需钻石
    int counter;//计时器
    QString name;//精灵名字
    bool isBuyed,startMode;//是否购买，记录是否开始游戏
    static int diamondTotal;//玩家的钻石总数

    int chooseNum;

    bool isLocked;

    QPixmap head;


    Cards();
    ~Cards();

    QRectF boundingRect() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;//鼠标按下
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;//鼠标释放
    void advance(int phase);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
protected:
    int coolTime;

signals:

};
//草系精灵
class bubuzhongzi:public Cards
{
  public:
    bubuzhongzi();
};
class xianrenqou:public Cards
{
public:
    xianrenqou();
};
class xiaodouya:public Cards
{
public:
    xiaodouya();
};
class yiyi:public Cards
{
public:
    yiyi();
};
//水系精灵
class yiyou:public Cards
{
public:
    yiyou();
};
class beier:public Cards
{
public:
    beier();
};
class guodongya:public Cards
{
public:
    guodongya();
};
class baobeili:public Cards
{
public:
    baobeili();
};
//火系精灵
class xiaohuohou:public Cards
{
public:
    xiaohuohou();
};
class jier:public Cards
{
public:
    jier();
};
class huliya:public Cards
{
public:
    huliya();
};
class dida:public Cards
{
public:
    dida();
};
//普通系
class dugulu:public Cards
{
public:
    dugulu();
};
class xinke:public Cards
{
public:
    xinke();
};
class agong:public Cards
{
public:
    agong();
};
class taida:public Cards
{
public:
    taida();
};

#endif // CARDS_H
