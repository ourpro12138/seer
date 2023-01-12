#include "map.h"

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


    }
}
