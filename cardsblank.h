#ifndef CARDSBLANK_H
#define CARDSBLANK_H

#include <QWidget>
#include <QPainter>
#include "cards.h"
#include <QLabel>
namespace Ui {
class cardsblank;
}

class cardsblank : public QWidget
{
    Q_OBJECT

public:
    explicit cardsblank(QWidget *parent = nullptr);
    ~cardsblank();
    void paintEvent(QPaintEvent *);

    QLabel *diamond_view;

    int cards_num;

    Cards *cards[5];



private:
    Ui::cardsblank *ui;
};

#endif // CARDSBLANK_H
