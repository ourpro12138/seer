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
    myptn[1][1]=new Yiyou(1,1);
}
Map::~Map()
{

}
//void Map::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{

//    if(!preparedPtn&&event->button()==Qt::LeftButton)
//    {


//    }
//}
