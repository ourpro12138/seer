#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>
#include <QPainter>
#include <QBitmap>

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
};

#endif // CHOOSESCENE_H
