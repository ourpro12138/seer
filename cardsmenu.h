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
    static Cards *P_all[16];

    int count=0;
    void paintEvent(QPaintEvent *);

signals:
    void bbzz();
    void xrq();
    void xdy();
    void yy();
    void yiy();
    void be();
    void gdy();
    void bbl();
    void xhh();
    void je();
    void hly();
    void dd();
    void dgl();
    void xk();
    void ag();
    void td();
private:
    Ui::cardsmenu *ui;
};

#endif // CARDSMENU_H
