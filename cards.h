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
    
    
    Cards();
    ~Cards();



//    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;//鼠标按下
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;//鼠标释放
//    void advance(int phase);
//    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
protected:
    int coolTime;
    



signals:

};

class bubuzhongzi:public Cards
{
  public:
    bubuzhongzi();
    
};
/*class bubuzhongzi:public Cards
{
  public:
    bubuzhongzi();

}*/

#endif // CARDS_H
