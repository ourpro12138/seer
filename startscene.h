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


    //绘图事件
    void paintEvent(QPaintEvent *);


private:
    Ui::startscene *ui;
signals:
    void login();//登入信号
};

#endif // STARTSCENE_H
