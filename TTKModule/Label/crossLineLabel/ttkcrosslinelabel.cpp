#include "ttkcrosslinelabel.h"

#include <QPainter>
#include <QMouseEvent>

TTKCrossLineLabel::TTKCrossLineLabel(QWidget *parent)
    : QWidget(parent)
{
    m_width = 2;
    m_color = Qt::red;
    setMouseTracking(true);
}

void TTKCrossLineLabel::setWidth(int w)
{
    if(m_width != w)
    {
        m_width = w;
        update();
    }
}

void TTKCrossLineLabel::setColor(const QColor &color)
{
    if(m_color != color)
    {
        m_color = color;
        update();
    }
}

QSize TTKCrossLineLabel::sizeHint() const
{
    return QSize(180, 180);
}

void TTKCrossLineLabel::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_pos = event->pos();
    update();
}

void TTKCrossLineLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_pos = event->pos();
    update();
}

void TTKCrossLineLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPen pen;
    pen.setWidth(m_width);
    pen.setColor(m_color);
    painter.setPen(pen);

    painter.drawLine(0, m_pos.y(), width(), m_pos.y());
    painter.drawLine(m_pos.x(), 0, m_pos.x(), height());
}
