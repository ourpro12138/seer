#include "bubuzhongzi.h"

Bubuzhongzi::Bubuzhongzi(int i,int j)
{
    this->i = i; this->j = j;
    hp=500,atk=50;
    this->width = 91;this->height=141;
    name="bubuzhongzi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
}
Bubuzhongzi::~Bubuzhongzi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}
//QRectF Bubuzhongzi::boundingRect() const
//{
//     return QRectF(180, 0, 100, 70);
//}


void Bubuzhongzi::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp<=0)
    delete this;
}

void Bubuzhongzi::treatment(int i,int j)
{
    if(Map::myptn[i][j+1]!=NULL)
    {
        if(treatCounter<treatCreateTime)
            ++treatCounter;
        if(treatCounter==treatCreateTime)
        {
            Map::myptn[i][j+1]->hp+=atk;
            treatCounter=0;
        }
    }
}
void Bubuzhongzi::skill()
{

}
void Bubuzhongzi::evolution()
{

}
