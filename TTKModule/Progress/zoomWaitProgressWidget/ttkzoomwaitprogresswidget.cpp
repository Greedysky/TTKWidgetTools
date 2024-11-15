#include "ttkzoomwaitprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKZoomWaitProgressWidget::TTKZoomWaitProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_color(Qt::black),
      m_zoomOut(false),
      m_zoomDelta(5),
      m_radious(0),
      m_minRadious(0)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(100);
}

void TTKZoomWaitProgressWidget::setColor(const QColor &color)
{
    if(color != m_color)
    {
        m_color = color;
        update();
    }
}

void TTKZoomWaitProgressWidget::setZoomOut(bool zoom)
{
    if(zoom != m_zoomOut)
    {
        m_zoomOut = zoom;
        update();
    }
}

void TTKZoomWaitProgressWidget::setZoomDelta(int delta)
{
    if(delta != m_zoomDelta)
    {
        m_zoomDelta = delta;
        update();
    }
}

void TTKZoomWaitProgressWidget::setMinRadious(int value)
{
    if(value > 0 && value != m_minRadious)
    {
        m_minRadious = value;
        update();
    }
}

void TTKZoomWaitProgressWidget::setRadious(int value)
{
    if(value != m_radious && value > m_minRadious)
    {
        m_radious = value;
        update();
    }
}

QSize TTKZoomWaitProgressWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKZoomWaitProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    const int side = qMin(width(), height());
    painter.scale(side / 100.0, side / 100.0);

    m_radious += m_zoomDelta;
    fixRadious(50);
    drawZoomWait(&painter);
}

void TTKZoomWaitProgressWidget::drawZoomWait(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(m_color));
    painter->drawEllipse(-m_radious, -m_radious, 2 * m_radious, 2 * m_radious);
    painter->restore();
}

void TTKZoomWaitProgressWidget::fixRadious(int max)
{
    if(m_radious < m_minRadious)
    {
        m_radious = m_minRadious;
        m_zoomDelta = qAbs(m_zoomDelta);
    }
    else if(m_radious > max)
    {
        if(m_zoomOut)
        {
            m_radious = max;
            m_zoomDelta = -qAbs(m_zoomDelta);
        }
        else
        {
            m_radious = m_minRadious;
            m_zoomDelta = qAbs(m_zoomDelta);
        }
    }
}
