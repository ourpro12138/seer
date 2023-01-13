#include"enemy.h"

Enemy::Enemy()
{
    speedFactor=100;
    setStatus=1;  nowStatus=1;
    
}
Enemy::~Enemy()
{

}

QRectF Enemy::boundingRect() const
{
    return QRectF(180,0,150,150);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRect(boundingRect());

}
void Enemy::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(x()<=150)
        delete this;
}

bool Enemy::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==partner::Type && other->x()-x()<80 && other->x()-x()>15
            && other->y()-y()>0 && other->y()-y()<100;

}

int Enemy::type() const
{
    return Type;
}


void Enemy::moveMovie(QString pic)
{
    if(movie)
        delete movie;
    movie =new QMovie(pic);
    movie->setSpeed(speedFactor);
    movie->start();
}


