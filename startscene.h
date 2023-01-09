#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QWidget>

namespace Ui {
class startscene;
}

class startscene : public QWidget
{
    Q_OBJECT

public:
    explicit startscene(QWidget *parent = nullptr);
    ~startscene();

private:
    Ui::startscene *ui;
};

#endif // STARTSCENE_H
