#ifndef CARDSMENU_H
#define CARDSMENU_H

#include <QWidget>

namespace Ui {
class cardsmenu;
}

class cardsmenu : public QWidget
{
    Q_OBJECT

public:
    explicit cardsmenu(QWidget *parent = nullptr);
    ~cardsmenu();

private:
    Ui::cardsmenu *ui;
};

#endif // CARDSMENU_H
