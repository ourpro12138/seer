#ifndef GANGYASHA_H
#define GANGYASHA_H


#include "enemy.h"
#include"partner.h"

class GangYaSha : public Enemy
{
public:
   GangYaSha(int i);
   ~GangYaSha();
    void advance(int phase);


};

#endif // GANGYASHA_H
