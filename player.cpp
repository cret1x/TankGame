#include "player.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>

Player::Player(int w,int h)
{
    point.setX(w/2);
    point.setY(h/2);
    vx = 15;
    vy = 15;
}

void Player::move(int w,int h,QKeyEvent *k)
{
    switch (k->key()) {
    case Qt::Key_S:
            point += QPoint(0,vy);
            break;
        case Qt::Key_W:
            point -= QPoint(0,vy);
            break;
        case Qt::Key_D:
            point += QPoint(vx,0);
            break;
        case Qt::Key_A:
            point -= QPoint(vx,0);
            break;
        default:
            break;
    }
    if(point.x()+r>=w)
    {
        point -= QPoint(vx,0);
    }
    if(point.y()+r>=h)
    {
        point -= QPoint(0,vy);
    }
    if(point.x()-r<=0)
    {
        point += QPoint(vx,0);
    }
    if(point.y()-r<=0)
    {
        point += QPoint(0,vy);
    }
}

void Player::draw(QPainter &painter)
{
    painter.drawEllipse(point,r,r);
}

QPoint Player::getPoint()
{
    return point;
}

