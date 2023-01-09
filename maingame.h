#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include "cardsmenu.h"
#include "startscene.h"
#include "chooselevelscene.h"
#include <QDebug>

#include "pokedex.h"

#include "choosescene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class maingame; }
QT_END_NAMESPACE

class maingame : public QWidget
{
    Q_OBJECT

public:
    maingame(QWidget *parent = nullptr);
    ~maingame();
    void loginGet();
private:
    Ui::maingame *ui;
    cardsmenu *cm;
    ChooseLevelScene * sc;
    startscene *ss;

    pokedex *pd;

    choosescene *choose;

};
#endif // MAINGAME_H
