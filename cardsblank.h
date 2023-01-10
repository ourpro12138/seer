#ifndef CARDSBLANK_H
#define CARDSBLANK_H

#include <QWidget>
#include <QPainter>
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




private:
    Ui::cardsblank *ui;
};

#endif // CARDSBLANK_H
