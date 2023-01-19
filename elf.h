#ifndef ELF_H
#define ELF_H

#define GRASS 1
#define WATER 2
#define FIRE 3
#define ORDINARY 4
#include <QGraphicsScene>
#include <QGraphicsItem>
#include<QPointF>
#include <QMovie>
class Bullet;
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
    qreal atk;
    //血量
    int hp;
    //行，列
    //int i,j;
    //攻击动画
    QMovie *atkmovie;
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    void advance(int phase);
//    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;

    //enemy-移动速度 partner-攻击速度
    qreal speed;

    int width;
    int height;


    ~Elf();
   int prepareTime,atkcounter,standTime,standcounter;
   int coolTime,coolcounter;
   bool atkStatus;
};
qreal Damage(Elf *in,Elf *out);
qreal Damage(Bullet *in,Elf *out);

#endif // ELF_H
