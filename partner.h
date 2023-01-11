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


};

#endif // PARTNER_H
