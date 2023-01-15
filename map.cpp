#include "map.h"
Partner *Map::myptn[4][5];

Map::Map()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            myptn[i][j]=NULL;
        }
    }
    preparedPtn = NULL;
}
Map::~Map()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
           delete myptn[i][j];
        }
    }
    preparedPtn = NULL;
}
void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(0,0,0));
}
QRectF Map::boundingRect() const
{
    return QRectF(0,0,1367,912);
}
void Map::advance(int phase)
{
    if(!phase)
        return;
    update();

}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
qDebug()<<"鼠标点击map x:"<<event->pos().x()<<"y:"<<event->pos().y();
    if(preparedPtn&&event->button()==Qt::LeftButton)
    {
        qDebug()<<preparedPtn->No;
       int i=-1,j=-1;
       for(int h=0;h<4;h++)
       {
           if(235+112*h+48*h<event->pos().y()&&event->pos().y()<235+112*h+48*h+112)
           {
               i=h;break;
           }
       }
       for(int l=0;l<5;l++)
       {
           qDebug()<<"l是"<<l;
           if(52+215*l+20*l<event->pos().x()&&event->pos().x()<52+215*l+20*l+215)
           {
               j=l;break;
           }
       }
       qDebug()<<i<<" "<<j;
       if(i!=-1&&j!=-1&&!myptn[i][j])
       {
           switch(preparedPtn->No)
        {
        case 1:
               qDebug()<<"布布种子建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Bubuzhongzi(i,j); break;
        case 2:
               break;
        case 3:
               break;
        case 4:
               break;
        case 5:
            qDebug()<<"伊优建立 i= "<<i<<"j = "<<j;
                 myptn[i][j] = new Yiyou(i,j); break;
        case 6:
              break;
        case 7:
               break;
        case 8:
               break;
        case 9:
               qDebug()<<"小火猴建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Xiaohuohou(i,j); break;
               break;
        case 10:
               break;
        case 11:
               break;
        case 12:
               break;
        case 13:
               break;
        case 14:
               break;
        case 15:
               break;
        case 16:
               break;

        }
            //myptn[i][j]->setZValue(j);
                   scene()->addItem(myptn[i][j]);
                   QApplication::restoreOverrideCursor();
                   preparedPtn =NULL;
       }
    }
    else if(preparedPtn&&event->button()==Qt::RightButton)
    {
        preparedPtn =NULL;
        QApplication::restoreOverrideCursor();

    }
}
void Map::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //Q_UNUSED(event);
}
