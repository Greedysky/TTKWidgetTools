#include "ttkcircleclickplane.h"

#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

TTKCircleClickPlane::TTKCircleClickPlane(QWidget *parent)
    : QWidget(parent)
{
    m_circleOn = false;
    m_crValue = 4;

    m_circleTimer = new QTimer(this);
    m_circleTimer->setInterval(20);
    connect(m_circleTimer, SIGNAL(timeout()), SLOT(updateValue()));
}

TTKCircleClickPlane::~TTKCircleClickPlane()
{
    delete m_circleTimer;
}

void TTKCircleClickPlane::updateValue()
{
    m_crValue += 2;
    if(m_crValue >= 40)
    {
        m_crValue = 4;
        m_circleOn = false;
        m_circleTimer->stop();
    }

    update();
}

void TTKCircleClickPlane::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    m_circleOn = true;
    m_pos = event->pos();
    m_crValue = 4;
    m_circleTimer->start();
}

void TTKCircleClickPlane::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if(m_circleOn)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(QPen(QColor(20, 203, 232, 50), 3));
        painter.drawEllipse(m_pos, m_crValue, m_crValue);
    }
}
