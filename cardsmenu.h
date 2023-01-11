#ifndef CARDSMENU_H
#define CARDSMENU_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include "cards.h"

namespace Ui {
class cardsmenu;
}

class cardsmenu : public QWidget
{
    Q_OBJECT

public:
    explicit cardsmenu(QWidget *parent = nullptr);
    ~cardsmenu();

    void paintEvent(QPaintEvent *);

    Cards *P_all[16];

private:
    Ui::cardsmenu *ui;
};

#endif // CARDSMENU_H
