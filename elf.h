#ifndef ELF_H
#define ELF_H

#define GRASS 1
#define WATER 2
#define FIRE 3
#define ODINARY 4
#include <QGraphicsScene>
#include <QGraphicsItem>
#include<QPointF>
#include <QMovie>

class Elf : public QGraphicsItem
{
public:
    Elf();
    //属性
    int attribute;
    //序号
    int No;
    //位置
    int posX,posY;
    //状态
    int state;
    //名字
    QString name;
    //攻击力
    int atk;
    //血量
    int hp;
    //行，列
    //int i,j;
    //攻击动画
    QMovie *atkmovie;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;

    //enemy-移动速度 partner-攻击速度
    qreal speed;

    int width;
    int height;


    ~Elf();
};

#endif // ELF_H
