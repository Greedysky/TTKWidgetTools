#include "ttkcirclewaitprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKCircleWaitProgressWidget::TTKCircleWaitProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_color(Qt::black),
      m_clockwiseRotate(true),
      m_rotateDelta(36),
      m_rotateAngle(0)
{
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(100);
}

void TTKCircleWaitProgressWidget::setColor(const QColor &color)
{
    if(color != m_color)
    {
        m_color = color;
        update();
    }
}

void TTKCircleWaitProgressWidget::setClockwiseRotate(bool clockwise)
{
    if(clockwise != m_clockwiseRotate)
    {
        m_clockwiseRotate = clockwise;
        update();
    }
}

void TTKCircleWaitProgressWidget::setRotateDelta(int delta)
{
    if(delta != m_rotateDelta)
    {
        m_rotateDelta = delta;
        update();
    }
}

QSize TTKCircleWaitProgressWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKCircleWaitProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    const int side = qMin(width(), height());
    painter.scale(side / 100.0, side / 100.0);

    painter.rotate(m_rotateAngle);
    drawCircleWait(&painter);
    m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
    m_rotateAngle %= 360;
}

void TTKCircleWaitProgressWidget::drawCircleWait(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor color = m_color;
    for(int i = 0; i <= 10; ++i)
    {
        color.setAlphaF(1.0 * i / 10);
        painter->setBrush(QBrush(color));
        painter->drawEllipse(30, -10, 20, 20);
        painter->rotate(36);
    }
    painter->restore();
}
