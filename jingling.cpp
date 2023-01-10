#include "jingling.h"

jingling::jingling(QWidget *parent) : QWidget(parent)
{
    counter=0;StartGame=1;
    isBuy=0;
    setCursor(Qt::PointingHandCursor);
    //setZValue(0);
}
