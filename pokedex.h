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


    void on_pushButtonfire_clicked();

    void on_pushButtonwater_clicked();

    void on_pushButtongrass_clicked();


    void on_pushButtonnormal_clicked();

    void on_pushButtonzip_clicked();

signals:
    void back();
private:
    Ui::pokedex *ui;
};

#endif // POKEDEX_H
