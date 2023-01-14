#include "bubuzhongzi.h"

Bubuzhongzi::Bubuzhongzi(int i,int j)
{
    hp=500,atk=50,treatCounter=0;treatCreateTime=60;
    name="bubuzhongzi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_bubuzhongzi.gif");
    atkmovie->start();
    setPos(i*230+170,j*152+121);
}
Bubuzhongzi::~Bubuzhongzi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}
QRectF Bubuzhongzi::boundingRect() const
{
     return QRectF(180, 0, 100, 70);
}


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

