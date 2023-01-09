#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QWidget>
#include <QPainter>
class ChooseLevelScene : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);
signals:

};

#endif // CHOOSELEVELSCENE_H
