#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>
#include <QPainter>
#include <QBitmap>
#include "pdbackpushbutton.h"

namespace Ui {
class choosescene;
}

class choosescene : public QWidget
{
    Q_OBJECT

public:
    explicit choosescene(QWidget *parent = nullptr);
    ~choosescene();
    void paintEvent(QPaintEvent *);

private:
    Ui::choosescene *ui;
signals:
    void back();
};

#endif // CHOOSESCENE_H
