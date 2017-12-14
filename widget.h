#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <player.h>
#include <QPainter>
#include <QTimer>
#include <bullet.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Player *player;
    QList <Bullet> bullets;
    QList <Bullet>::iterator iter;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *k);

public slots:
    void MoveAll();

private:
    Ui::Widget *ui;
    QTimer timer;
    bool shooted = false;
    int lastAction = 1;

};

#endif // WIDGET_H
