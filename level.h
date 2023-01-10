#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "enemy.h"
#include <QPainter>
#include "cardsblank.h"
#include "cardsmenu.h"
#include "pdbackpushbutton.h"

namespace Ui {
class Level;
}

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();


    bool isLocked;
    QString levelName;
    int enemy_num;
    enemy *E;
    cardsblank *cb;
    cardsmenu *cm;


    void paintEvent(QPaintEvent *);

private:
    Ui::Level *ui;
signals:
    void back();
};



class kls:public Level
{
public:
    kls();
};

class hek:public Level
{
public:
    hek();
};
class hs:public Level
{
public:
    hs();
};
class hm:public Level
{
public:
    hm();
};
class alpha:public Level
{
public:
    alpha();
};
class final:public Level
{
public:
    final();
};

#endif // LEVEL_H
