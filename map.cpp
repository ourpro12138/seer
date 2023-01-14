#include "map.h"
partner *Map::myptn[4][5];

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

}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
qDebug()<<"鼠标点击map x:"<<event->pos().x()<<"y:"<<event->pos().y();
    if(preparedPtn&&event->button()==Qt::LeftButton)
    {
        qDebug()<<preparedPtn->No;
       int i,j;
       for(int h=0;h<4;h++)
       {
           if(235+112*h+48*h<event->pos().y()&&event->pos().y()<235+112*h+48*h+112)
           {
               i=h;break;
           }
           else i=-1;
       }
       for(int l=0;l<5;l++)
       {
           if(52+215*l+20*l<event->pos().x()&&event->pos().x()<52+215*l+20*l+215)
           {
               j=l;break;
           }
           else j=-1;
       }
       if(i!=-1&&j!=-1)
       {
           switch(preparedPtn->No)
        {
        case 1:

        case 2:

        case 3:

        case 4:

        case 5:
            qDebug()<<"伊优建立 i= "<<i<<"j = "<<j;
                 myptn[i][j] = new Yiyou(i,j); break;
        case 6:

        case 7:

        case 8:

        case 9:

        case 10:

        case 11:

        case 12:

        case 13:

        case 14:

        case 15:

        case 16: break;

        }
                   scene()->addItem(myptn[i][j]);
       }
    }
}
void Map::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
