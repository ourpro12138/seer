#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include "cardsmenu.h"


QT_BEGIN_NAMESPACE
namespace Ui { class maingame; }
QT_END_NAMESPACE

class maingame : public QWidget
{
    Q_OBJECT

public:
    maingame(QWidget *parent = nullptr);
    ~maingame();

private:
    Ui::maingame *ui;
    cardsmenu *cm;
};
#endif // MAINGAME_H
