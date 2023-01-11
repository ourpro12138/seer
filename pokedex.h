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

    void on_pushButtonfirem_clicked();

    void on_pushButtonfireh_clicked();

    void on_pushButtonfirex_clicked();

    void on_pushButtonfirej_clicked();

    void on_pushButtonfirel_clicked();

    void on_pushButtonfireljls_clicked();

    void on_pushButtonwateryy_clicked();


signals:
    void back();
private:
    Ui::pokedex *ui;
};

#endif // POKEDEX_H
