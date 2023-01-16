#include"enemy.h"

Enemy::Enemy()
{
    speedFactor=100;
    setStatus=1;nowStatus=1;
    
}
Enemy::~Enemy()
{
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),movie->currentImage());

}
void Enemy::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(posX<=150)
        delete this;
}

bool Enemy::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Partner::Type)
//    {
//        qDebug()<<"检测精灵";
//        qDebug()<<posX-other->x();
//        qDebug()<<other->y()-y();

//    }
    return other->type()==Partner::Type && posX-other->x()<150 && posX-other->x()>90
            && other->y()-y()>-20 && other->y()-y()<20;

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


