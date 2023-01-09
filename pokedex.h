#ifndef POKEDEX_H
#define POKEDEX_H

#include <QWidget>

namespace Ui {
class pokedex;
}

class pokedex : public QWidget
{
    Q_OBJECT

public:
    explicit pokedex(QWidget *parent = nullptr);
    ~pokedex();

private:
    Ui::pokedex *ui;
};

#endif // POKEDEX_H
