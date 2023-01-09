#ifndef POKEDEX_H
#define POKEDEX_H

#include <QWidget>
#include "pdbackpushbutton.h"
#include <QPainter>

namespace Ui {
class pokedex;
}

class pokedex : public QWidget
{
    Q_OBJECT

public:
    explicit pokedex(QWidget *parent = nullptr);
    ~pokedex();
    void paintEvent(QPaintEvent *);

private slots:
//    void on_pushButton_clicked();
    void back();
private:
    Ui::pokedex *ui;
};

#endif // POKEDEX_H
