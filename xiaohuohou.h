#ifndef XIAOHUOHOU_H
#define XIAOHUOHOU_H
#include "elf.h"
#include "map.h"

class Xiaohuohou : public Elf
{
public:
    Xiaohuohou(QPoint point);
    ~Xiaohuohou();
    //QRect boundingRect()const;
    void advance(int phase);

private:


signals:


};

#endif // XIAOHUOHOU_H
