#ifndef BEILAMI_H
#define BEILAMI_H

#include <QWidget>
#include "enemy.h"

class Beilami : public Enemy
{
public:

    Beilami(int i);
    ~Beilami();
    void advance(int phase);


};

#endif // BEILAMI_H
