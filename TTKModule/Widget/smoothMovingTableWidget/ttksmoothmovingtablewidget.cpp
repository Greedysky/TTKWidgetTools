#include "ttksmoothmovingtablewidget.h"

#include <QTimer>
#include <QScrollBar>
#include <QWheelEvent>
#include <QPropertyAnimation>

TTKSmoothMovingTableWidget::TTKSmoothMovingTableWidget(QWidget *parent)
    : QTableWidget(parent),
      m_initialized(true),
      m_previousValue(0),
      m_deltaValue(0),
      m_scrollBar(nullptr),
      m_moveAnimation(nullptr)
{
    m_animationTimer = new QTimer(this);
    m_animationTimer->setInterval(100 * TTK_DN_MS);

    connect(m_animationTimer, SIGNAL(timeout()), SLOT(timeToAnimation()));
}

TTKSmoothMovingTableWidget::~TTKSmoothMovingTableWidget()
{
    m_animationTimer->stop();
    delete m_animationTimer;
    delete m_moveAnimation;
}

void TTKSmoothMovingTableWidget::setMovedScrollBar(QScrollBar *bar)
{
    m_scrollBar = (bar == nullptr) ? verticalScrollBar() : bar;
    delete m_moveAnimation;

    m_moveAnimation = new QPropertyAnimation(m_scrollBar, "value", this);
    m_moveAnimation->setDuration(TTK_DN_S2MS);
    connect(m_scrollBar, SIGNAL(valueChanged(int)), SLOT(valueChanged(int)));
}

QSize TTKSmoothMovingTableWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKSmoothMovingTableWidget::timeToAnimation()
{
    if(!m_moveAnimation)
    {
        return;
    }

    m_initialized = true;
    m_animationTimer->stop();

    const float delta = (rowCount() > 0) ? (height() * 1.0 / rowCount()) : 0;
    m_deltaValue = (m_deltaValue / 480.0) * (m_deltaValue < 0 ? m_deltaValue + 120 : -m_deltaValue + 120);

    m_moveAnimation->setStartValue(m_previousValue);
    m_moveAnimation->setEndValue(m_scrollBar->value() + m_deltaValue * delta / 30);
    m_moveAnimation->start();
}

void TTKSmoothMovingTableWidget::valueChanged(int value)
{
    m_previousValue = value;
}

void TTKSmoothMovingTableWidget::wheelEvent(QWheelEvent *event)
{
    QTableWidget::wheelEvent(event);

    if(!m_moveAnimation)
    {
        return;
    }

    m_animationTimer->stop();
    m_moveAnimation->stop();

    if(m_initialized)
    {
        m_deltaValue = 0;
        m_previousValue = m_scrollBar->value();
        m_initialized = false;
    }

    m_deltaValue += QtWheelDelta(event);
    m_animationTimer->start();
}
