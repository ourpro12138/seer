#ifndef YIYOU_H
#define YIYOU_H
#include"map.h"
#include"partner.h"
class yiyou : public partner
{
    Q_OBJECT
public:
    //explicit yiyou(QWidget *parent = nullptr);
     yiyou(QPointF point);
     ~yiyou();
     void advance(int phase);
private:

};

#endif // YIYOU_H
