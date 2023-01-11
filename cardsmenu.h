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

    QPushButton *p_PB[16];

    void paintEvent(QPaintEvent *);


private:
    Ui::cardsmenu *ui;
};

#endif // CARDSMENU_H