#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H
#define Level_num 6

#include <QWidget>
#include <QPainter>
#include <QBitmap>
#include "pdbackpushbutton.h"
#include "level.h"

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
