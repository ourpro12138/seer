#ifndef PARTNER_H
#define PARTNER_H
#include "elf.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>


class Enemy;
class Partner :public Elf
{
public:
    Partner();

    virtual void skill()=0;

    virtual void evolution()=0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;//鼠标按下
    int type() const;
    ~Partner();
    int i;
    int j;
    int setStatus;
    int nowStatus;

    int price;

    int price_ev;
    int price_skill;
    QString skillname;

    static QPushButton *skillButton;
    static QPushButton *evolutionButton;
    static QPushButton *capsuleButton;

    static QWidget *parent;

private:
    Enemy *enemy;
};

#endif // PARTNER_H
