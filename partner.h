#ifndef PARTNER_H
#define PARTNER_H
#include "elf.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QBitmap>
#include <QMovie>
#include <QTimer>

class Level;
class Enemy;
class Partner :public QObject,public Elf
{
     Q_OBJECT
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

    QPushButton *skillButton;
    QPushButton *evolutionButton;
    QPushButton *capsuleButton;

    QMovie *Skill;
    QLabel *Skillplayer;

    static Level *parent;

private:
    Enemy *enemy;
};
#endif // PARTNER_H
