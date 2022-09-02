#include "ttkmovewidget.h"

#include <QPainter>
#include <QBoxLayout>

#define WIDTH  4
#define HEIGHT 4

TTKMoveWidget::TTKMoveWidget(QWidget *parent)
    : TTKMoveWidget(true, parent)
{

}

TTKMoveWidget::TTKMoveWidget(bool transparent, QWidget *parent)
    : QWidget(parent),
      m_moveOption(false),
      m_showShadow(true),
      m_leftButtonPress(false)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, transparent);
}

void TTKMoveWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if(m_showShadow)
    {
        QPainter painter(this);

        painter.drawPixmap(0, 0, WIDTH, HEIGHT, QPixmap(":/res/lb_left_top"));
        painter.drawPixmap(width() - WIDTH, 0, WIDTH, HEIGHT, QPixmap(":/res/lb_right_top"));
        painter.drawPixmap(0, height() - HEIGHT, WIDTH, HEIGHT, QPixmap(":/res/lb_left_bottom"));
        painter.drawPixmap(width() - WIDTH, height() - HEIGHT, WIDTH, HEIGHT, QPixmap(":/res/lb_right_bottom"));

        painter.drawPixmap(0, WIDTH, HEIGHT, height() - 2 * WIDTH, QPixmap(":/res/lb_left").scaled(WIDTH, height() - 2 * HEIGHT));
        painter.drawPixmap(width() - WIDTH, WIDTH, HEIGHT, height() - 2 * HEIGHT, QPixmap(":/res/lb_right").scaled(WIDTH, height() - 2 * HEIGHT));
        painter.drawPixmap(HEIGHT, 0, width() - 2 * WIDTH, HEIGHT, QPixmap(":/res/lb_top").scaled(width() - 2 * WIDTH, HEIGHT));
        painter.drawPixmap(WIDTH, height() - HEIGHT, width() - 2 * WIDTH, HEIGHT, QPixmap(":/res/lb_bottom").scaled(width() - 2 * WIDTH, HEIGHT));
    }
}

void TTKMoveWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton && !m_moveOption)
    {
        m_leftButtonPress = true;
    }

    m_pressAt = QtMouseEventGlobalPos(event);
}

void TTKMoveWidget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    if(!m_leftButtonPress )
    {
        event->ignore();
        return;
    }

    const int xpos = QtMouseEventGlobalX(event) - m_pressAt.x();
    const int ypos = QtMouseEventGlobalY(event) - m_pressAt.y();
    m_pressAt = QtMouseEventGlobalPos(event);
    move(x() + xpos, y() + ypos);
}

void TTKMoveWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    m_pressAt = QtMouseEventGlobalPos(event);
    m_leftButtonPress = false;
}
