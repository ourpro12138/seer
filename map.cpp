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
void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(!preparedPtn&&event->button()==Qt::LeftButton)
    {
       int i,j;
       for(int h=0;h<4;h++)
       {
           if(232+110*h+43*h<event->pos().y()<232+110*h+43*h+110)
               i=h;
       }
       for(int l=0;l<5;l++)
       {
           if(48+212*l+20*l<event->pos().x()<48+212*l+20*l+212)
               j=l;
       }
        switch(preparedPtn->No)
        {
        case 1:
            myptn[i][j] = new yiyou();
        case 2:

        case 3:

        case 4:

        case 5:

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

        case 16:

        }
    }
}
//    }
//}
