#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>

namespace Ui {
class choosescene;
}

class choosescene : public QWidget
{
    Q_OBJECT

public:
    explicit choosescene(QWidget *parent = nullptr);
    ~choosescene();

private:
    Ui::choosescene *ui;
};

#endif // CHOOSESCENE_H
