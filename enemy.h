#ifndef ENEMY_H
#define ENEMY_H
#include "elf.h"

class enemy: public Elf
{
public:
    enemy();
    int benefit;
    ~enemy();
};

#endif // ENEMY_H
