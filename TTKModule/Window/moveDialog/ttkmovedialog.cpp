#include "ttkmovedialog.h"

#include <QMouseEvent>
#include <QPainter>

#define WIDTH  4
#define HEIGHT 4

TTKMoveDialog::TTKMoveDialog(QWidget *parent)
    : TTKMoveDialog(true, parent)
{

}

TTKMoveDialog::TTKMoveDialog(bool transparent, QWidget *parent)
    : QDialog(parent)
{
    ///Remove the title bar
    setWindowFlags( Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, transparent);

    m_moveOption = false;
    m_leftButtonPress = false;
    m_showShadow = true;
}

void TTKMoveDialog::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);

    if(m_showShadow)
    {
        QPainter painter(this);

        painter.drawPixmap(0, 0, WIDTH, HEIGHT, QPixmap(":/res/lb_left_top"));
        painter.drawPixmap(width() - WIDTH, 0, WIDTH, HEIGHT, QPixmap(":/res/lb_right_top"));
        painter.drawPixmap(0, height() - HEIGHT, WIDTH, HEIGHT, QPixmap(":/res/lb_left_bottom"));
        painter.drawPixmap(width() - WIDTH, height() - HEIGHT, WIDTH, HEIGHT, QPixmap(":/res/lb_right_bottom"));

        painter.drawPixmap(0, WIDTH, HEIGHT, height() - 2*WIDTH,
                           QPixmap(":/res/lb_left").scaled(WIDTH, height() - 2*HEIGHT));
        painter.drawPixmap(width() - WIDTH, WIDTH, HEIGHT, height() - 2*HEIGHT,
                           QPixmap(":/res/lb_right").scaled(WIDTH, height() - 2*HEIGHT));
        painter.drawPixmap(HEIGHT, 0, width() - 2*WIDTH, HEIGHT,
                           QPixmap(":/res/lb_top").scaled(width() - 2*WIDTH, HEIGHT));
        painter.drawPixmap(WIDTH, height() - HEIGHT, width() - 2*WIDTH, HEIGHT,
                           QPixmap(":/res/lb_bottom").scaled(width() - 2*WIDTH, HEIGHT));
    }
}

void TTKMoveDialog::mousePressEvent(QMouseEvent *event)
{
    QDialog::mousePressEvent(event);
    if( event->button() == Qt::LeftButton && !m_moveOption)///Press the left key
    {
        m_leftButtonPress = true;
    }
#if TTK_QT_VERSION_CHECK(6,0,0)
    m_pressAt = event->globalPosition().toPoint();
#else
    m_pressAt = event->globalPos();
#endif
}

void TTKMoveDialog::mouseMoveEvent(QMouseEvent *event)
{
    QDialog::mouseMoveEvent(event);
    if( !m_leftButtonPress )///Not press the left key
    {
        event->ignore();
        return;
    }

#if TTK_QT_VERSION_CHECK(6,0,0)
    const int xpos = event->globalPosition().x() - m_pressAt.x();
    const int ypos = event->globalPosition().y() - m_pressAt.y();
    m_pressAt = event->globalPosition().toPoint();
#else
    const int xpos = event->globalX() - m_pressAt.x();
    const int ypos = event->globalY() - m_pressAt.y();
    m_pressAt = event->globalPos();
#endif
    move( x() + xpos, y() + ypos);
}

void TTKMoveDialog::mouseReleaseEvent(QMouseEvent *event)
{
    QDialog::mouseReleaseEvent(event);
#if TTK_QT_VERSION_CHECK(6,0,0)
    m_pressAt = event->globalPosition().toPoint();
#else
    m_pressAt = event->globalPos();
#endif
    m_leftButtonPress = false;
}
