#ifndef JINGLING_H
#define JINGLING_H

#include <QWidget>
#include <QCursor>
#include <QGraphicsItem>
#include <

class jingling : public QWidget
{
    Q_OBJECT
public:
    explicit jingling(QWidget *parent = nullptr);
    int No,zuanshineed;//编号，所需钻石
    int counter;//计时器
    int coolTime;//冷却时间
    QString name;//精灵名字
    bool isBuy,StartGame;//记录购买，记录游戏开始
    static int zuanshiTotal;//记录拥有的钻石

    void buy(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void mouseReleaseEvent()



signals:

};

#endif // JINGLING_H
