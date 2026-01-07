#include "ttkpiewaitprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKPieWaitProgressWidget::TTKPieWaitProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_foregroundColor(Qt::black),
      m_backgroundColor(Qt::white),
      m_clockWise(true),
      m_rotateDelta(36),
      m_rotateAngle(0)
{
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(100);
}

void TTKPieWaitProgressWidget::setForegroundColor(const QColor &foregroundColor)
{
    if(foregroundColor != m_foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        update();
    }
}

void TTKPieWaitProgressWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if(backgroundColor != m_backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        update();
    }
}

void TTKPieWaitProgressWidget::setClockWise(bool clockwise)
{
    if(clockwise != m_clockWise)
    {
        m_clockWise = clockwise;
        update();
    }
}

void TTKPieWaitProgressWidget::setRotateDelta(int delta)
{
    if(delta != m_rotateDelta)
    {
        m_rotateDelta = delta;
        update();
    }
}

QSize TTKPieWaitProgressWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKPieWaitProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    const int side = qMin(width(), height());
    painter.scale(side / 100.0, side / 100.0);

    painter.rotate(m_rotateAngle);
    drawPieWait(&painter);

    m_rotateAngle += m_clockWise ? m_rotateDelta : -m_rotateDelta;
    m_rotateAngle %= 360;
}

void TTKPieWaitProgressWidget::drawPieWait(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(m_backgroundColor));
    painter->drawEllipse(-50, -50, 100, 100);
    painter->setBrush(QBrush(m_foregroundColor));
    painter->drawPie(-50, -50, 100, 100, 0 * 60, 16 * 60);
    painter->restore();
}
