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
               qDebug()<<"仙人球建立 i ="<<i<<"j = "<<j;
               myptn[i][j] = new Xianrenqiu(i,j);break;
               break;
        case 3:
               qDebug()<<"小豆芽建立 i ="<<i<<"j = "<<j;
               myptn[i][j] = new Xiaodouya(i,j);break;
               break;
               break;
        case 4:
               qDebug()<<"依依建立 i ="<<i<<"j = "<<j;
               myptn[i][j] = new Yiyi(i,j);break;
               break;
        case 5:
            qDebug()<<"伊优建立 i= "<<i<<"j = "<<j;
                 myptn[i][j] = new BaLuSi(i,j); break;
                 myptn[i][j] = new Yiyou(i,j); break;
        case 6:
               qDebug()<<"贝尔建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Beier(i,j); break;
              break;
        case 7:
               qDebug()<<"果冻鸭建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Guodongya(i,j); break;
               break;
        case 8:
               qDebug()<<"宝贝鲤建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Baobeili(i,j); break;
               break;
        case 9:
               qDebug()<<"小火猴建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new LieHuoHou(i,j); break;
               break;
        case 10:
               qDebug()<<"吉尔建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Jier(i,j); break;
                    //myptn[i][j] = new Linuo(i,j); break;
                    //myptn[i][j] = new Luojilasi(i,j); break;
               break;
        case 11:
               qDebug()<<"胡利亚建立 i= "<<i<<"j = "<<j;
                    //myptn[i][j] = new Huliya(i,j); break;
                    myptn[i][j] = new Huliya(i,j); break;
               break;
        case 12:
               qDebug()<<"迪达建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Dida(i,j); break;
                    //myptn[i][j] = new Dierke(i,j); break;
               break;
        case 13:
               qDebug()<<"嘟咕噜建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new DuGuLu(i,j); break;
               break;
        case 14:
               qDebug()<<"辛克建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Xinke(i,j); break;
               break;
        case 15:
               qDebug()<<"阿贡建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Agong(i,j); break;
               break;
        case 16:
               qDebug()<<"泰达建立 i= "<<i<<"j = "<<j;
                    myptn[i][j] = new Taida(i,j); break;
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
