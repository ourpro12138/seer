#ifndef CARDSMENU_H
#define CARDSMENU_H

#include <QWidget>
#include <QPainter>



namespace Ui {
class cardsmenu;
}

class cardsmenu : public QWidget
{
    Q_OBJECT

public:
    explicit cardsmenu(QWidget *parent = nullptr);
    ~cardsmenu();

    void paintEvent(QPaintEvent *);

private:
    Ui::cardsmenu *ui;
};

#endif // CARDSMENU_H
