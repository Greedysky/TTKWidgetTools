#include "ttklinewaitprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKLineWaitProgressWidget::TTKLineWaitProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_color(Qt::black),
      m_clockWise(true),
      m_rotateDelta(36),
      m_rotateAngle(0)
{
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(100);
}

void TTKLineWaitProgressWidget::setColor(const QColor &color)
{
    if(color != m_color)
    {
        m_color = color;
        update();
    }
}

void TTKLineWaitProgressWidget::setClockWise(bool clockwise)
{
    if(clockwise != m_clockWise)
    {
        m_clockWise = clockwise;
        update();
    }
}

void TTKLineWaitProgressWidget::setRotateDelta(int delta)
{
    if(delta != m_rotateDelta)
    {
        m_rotateDelta = delta;
        update();
    }
}

QSize TTKLineWaitProgressWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKLineWaitProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    const int side = qMin(width(), height());
    painter.scale(side / 100.0, side / 100.0);

    painter.rotate(m_rotateAngle);
    drawLineWait(&painter);
    m_rotateAngle += m_clockWise ? m_rotateDelta : -m_rotateDelta;
    m_rotateAngle %= 360;
}

void TTKLineWaitProgressWidget::drawLineWait(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor color = m_color;
    for(int i = 0; i <= 10; ++i)
    {
        color.setAlphaF(1.0 * i / 10);
        painter->setBrush(QBrush(color));
        painter->drawRoundedRect(50 * 2 / 5, -3, 50 * 3 / 5, 6, 2, 2);
        painter->rotate(36);
    }
    painter->restore();
}
