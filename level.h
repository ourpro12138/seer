#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "enemy.h"
#include <QPainter>
#include "cardsblank.h"
#include "cardsmenu.h"
#include "pdbackpushbutton.h"
#include <QTimer>
#include "map.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QCursor>


namespace Ui {
class Level;
}

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    QGraphicsScene *scene;
    QGraphicsView *view;

    bool isLocked;
    QString levelName;
    int enemy_num;
    Enemy *E;
    cardsblank *cb;
    cardsmenu *cm;
    int x=-200;

   Map *map;

   pdbackPushButton *Back;
   void initlevel();
   void returnLevel();
   int levelMode;

   QTimer *gametime;


    void GameStart();
    void paintEvent(QPaintEvent *);
signals:
    void gamestart();
private:
    Ui::Level *ui;
signals:
    void back();
//    void choosecards();
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
