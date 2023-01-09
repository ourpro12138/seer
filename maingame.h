#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include "startscene.h"
#include "chooselevelscene.h"
#include <QDebug>
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
    ChooseLevelScene * sc;
    startscene *ss;
};
#endif // MAINGAME_H
