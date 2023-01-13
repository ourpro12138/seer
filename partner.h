#ifndef PARTNER_H
#define PARTNER_H
#include "elf.h"

class partner :public Elf
{
public:
    partner();

    virtual void skill()=0;

    virtual void evolution()=0;

    ~partner();
    int i;
    int j;


};

#endif // PARTNER_H
