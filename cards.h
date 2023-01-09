#ifndef CARDS_H
#define CARDS_H
#include <QGraphicsItem>

class Cards : public QGraphicsItem
{
public:
    Cards();
    int No,price;
    int counter;
    int coolTime;
    QString name;
    bool isPlanted;

    int StartMode;

    static int diamondTotal;

    bool isLocated;

    ~Cards();
};

#endif // CARDS_H
