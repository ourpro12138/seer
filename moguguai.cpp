#include "moguguai.h"

MoGuGuai::MoGuGuai(int i)
{
    x=1566;
    this->i=i=2;
    hp=350;atk=5;speed=0.40;
    name="MoGuGuai";
    if(qrand()%2)
        movie=new  QMovie(":/enemy/resource/enemy/enemy_attack.gif");
    else
        movie=new  QMovie(":/enemy/resource/enemy/enemy.gif");
    movie->start();


}



MoGuGuai::~MoGuGuai()
{
    if(movie)
        delete movie;
}

void MoGuGuai::advance(int phase)
{

}

