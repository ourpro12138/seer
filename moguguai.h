#ifndef MOGUGUAI_H
#define MOGUGUAI_H

#include "enemy.h"
#include"partner.h"

class MoGuGuai : public Enemy
{

public:

    MoGuGuai(int i);
    ~MoGuGuai();
    void advance(int phase);


};

#endif // MOGUGUAI_H
