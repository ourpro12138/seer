#include "elf.h"

Elf::Elf()
{

}
Elf::~Elf()
{


}
//QRectF Elf::boundingRect()const
//{

//}
//void  Elf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

//}{}
//void  Elf::advance(int phase)
//{

//}
//bool  Elf::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
qreal Elf::Damage(Elf *in,Elf *out)
{
    if(out->attribute)
        return in->atk;
    switch(in->attribute)
    {
    case WATER:
    {
        switch(out->attribute)
        {
        case WATER:
            return in->atk;
        case FIRE:
            return in->atk*2;
        case GRASS:
            return in->atk*0.5;
        }
    }
    case FIRE:
    {
        switch(out->attribute)
        {
        case WATER:
            return in->atk*0.5;
        case FIRE:
            return in->atk;
        case GRASS:
            return in->atk*2;
        }
    }
    case GRASS:
    {
        switch(out->attribute)
        {case GRASS:
            return in->atk;
        case FIRE:
            return in->atk*0.5;
        case WATER:
            return in->atk*2;}
    }
    case ODINARY:
        return in->atk;
    }


}

