#include "widget.h"
#include "ui_widget.h"
#include <player.h>
#include <QPainter>
#include <QDebug>
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    player = new Player(width(),height());
    timer.start(20);
    connect(&timer,SIGNAL(timeout()),this,SLOT(MoveAll()));
}

Widget::~Widget()
{
    delete ui;
    delete player;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    player->draw(painter);
    if(shooted)
    {
        if(!bullets.empty())
        for (iter = bullets.begin(); iter != bullets.end(); iter++)
        {
            iter->draw(painter);
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *k)
{
    player->move(width(),height(),k);
    switch (k->key()) {
    case Qt::Key_S:
           lastAction = 2;
            break;
        case Qt::Key_W:
           lastAction = 4;
            break;
        case Qt::Key_D:
            lastAction = 3;
            break;
        case Qt::Key_A:
            lastAction = 1;
            break;
        default:
            break;
    }
    if(k->key()==Qt::Key_Space)
    {
       Bullet ammo(player->getPoint(),lastAction);
       bullets.push_back(ammo);
       shooted = true;
    }

}


void Widget::MoveAll()
{
   if(shooted)
    {
        for (iter = bullets.begin(); iter != bullets.end(); iter++)
        {
            if(!iter->move(width(),height()))
            {
              iter = bullets.erase(iter);
              if(bullets.empty()) shooted = false;
              break;
            }
        }

    }
  // qDebug()<<shooted;
    this->repaint();
}
