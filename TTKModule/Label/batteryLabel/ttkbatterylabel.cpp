#include "ttkbatterylabel.h"

#include <QTimer>
#include <QPainter>

TTKBatteryLabel::TTKBatteryLabel(QWidget *parent)
    : QWidget(parent),
      m_minValue(0),
      m_maxValue(100),
      m_value(0),
      m_alarmValue(30),
      m_step(0.5),
      m_borderColorStart(100, 100, 100),
      m_borderColorEnd(80, 80, 80),
      m_alarmColorStart(250, 118, 113),
      m_alarmColorEnd(204, 38, 38),
      m_normalColorStart(50, 205, 51),
      m_normalColorEnd(60, 179, 133),
      m_isForward(false),
      m_currentValue(0)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10 * TTK_DN_MS);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKBatteryLabel::~TTKBatteryLabel()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKBatteryLabel::setRange(double minValue, double maxValue)
{
    if(minValue >= maxValue)
    {
        return;
    }

    m_minValue = minValue;
    m_maxValue = maxValue;

    if(m_value < minValue || m_value > maxValue)
    {
        setValue(m_value);
    }

    update();
}

void TTKBatteryLabel::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKBatteryLabel::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKBatteryLabel::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue || value == m_value)
    {
        return;
    }

    m_value = value;

    if(value > m_currentValue)
    {
        m_isForward = false;
    }
    else if(value < m_currentValue)
    {
        m_isForward = true;
    }
    else
    {
        return;
    }

    m_timer->start();
    update();
}

void TTKBatteryLabel::setAlarmValue(double alarmValue)
{
    if(m_alarmValue != alarmValue)
    {
        m_alarmValue = alarmValue;
        update();
    }
}

void TTKBatteryLabel::setStep(double step)
{
    if(m_step != step)
    {
        m_step = step;
        update();
    }
}

void TTKBatteryLabel::setBorderColorStart(const QColor &borderColorStart)
{
    if(m_borderColorStart != borderColorStart)
    {
        m_borderColorStart = borderColorStart;
        update();
    }
}

void TTKBatteryLabel::setBorderColorEnd(const QColor &borderColorEnd)
{
    if(m_borderColorEnd != borderColorEnd)
    {
        m_borderColorEnd = borderColorEnd;
        update();
    }
}

void TTKBatteryLabel::setAlarmColorStart(const QColor &alarmColorStart)
{
    if(m_alarmColorStart != alarmColorStart)
    {
        m_alarmColorStart = alarmColorStart;
        update();
    }
}

void TTKBatteryLabel::setAlarmColorEnd(const QColor &alarmColorEnd)
{
    if(m_alarmColorEnd != alarmColorEnd)
    {
        m_alarmColorEnd = alarmColorEnd;
        update();
    }
}

void TTKBatteryLabel::setNormalColorStart(const QColor &normalColorStart)
{
    if(m_normalColorStart != normalColorStart)
    {
        m_normalColorStart = normalColorStart;
        update();
    }
}

void TTKBatteryLabel::setNormalColorEnd(const QColor &normalColorEnd)
{
    if(m_normalColorEnd != normalColorEnd)
    {
        m_normalColorEnd = normalColorEnd;
        update();
    }
}

QSize TTKBatteryLabel::sizeHint() const
{
    return QSize(150, 80);
}

void TTKBatteryLabel::updateValue()
{
    if(m_isForward)
    {
        m_currentValue -= m_step;
        if(m_currentValue <= m_value)
        {
            m_timer->stop();
        }
    }
    else
    {
        m_currentValue += m_step;
        if(m_currentValue >= m_value)
        {
            m_timer->stop();
        }
    }

    update();
}

void TTKBatteryLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    drawBorder(&painter);
    drawBackground(&painter);
}

void TTKBatteryLabel::drawBorder(QPainter *painter)
{
    painter->save();
    const double headWidth = width() / 10;
    const double batteryWidth = width() - headWidth;

    const QPointF topLeft(5, 5);
    const QPointF bottomRight(batteryWidth, height() - 5);
    m_batteryRect = QRectF(topLeft, bottomRight);

    painter->setPen(QPen(m_borderColorStart, 5));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(m_batteryRect, 10, 20);

    const QPointF headRectTopLeft(m_batteryRect.topRight().x(), height() / 3);
    const QPointF headRectBottomRight(width(), height() - height() / 3);
    const QRectF headRect(headRectTopLeft, headRectBottomRight);

    QLinearGradient headRectGradient(headRect.topLeft(), headRect.bottomLeft());
    headRectGradient.setColorAt(0.0, m_borderColorStart);
    headRectGradient.setColorAt(1.0, m_borderColorEnd);

    painter->setBrush(headRectGradient);
    painter->drawRoundedRect(headRect, 15, 25);
    painter->restore();
}

void TTKBatteryLabel::drawBackground(QPainter *painter)
{
    painter->save();
    QLinearGradient batteryGradient(QPointF(0, 0), QPointF(0, height()));

    if(m_currentValue <= m_alarmValue)
    {
        batteryGradient.setColorAt(0.0, m_alarmColorStart);
        batteryGradient.setColorAt(1.0, m_alarmColorEnd);
    }
    else
    {
        batteryGradient.setColorAt(0.0, m_normalColorStart);
        batteryGradient.setColorAt(1.0, m_normalColorEnd);
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(batteryGradient);

    const int margin = std::min(width(), height()) / 20;
    const double unit = (m_batteryRect.width() - (margin * 2)) / 100;
    const double width = m_currentValue * unit;
    const QPointF topLeft(m_batteryRect.topLeft().x() + margin, m_batteryRect.topLeft().y() + margin);
    const QPointF bottomRight(width + margin + 5, m_batteryRect.bottomRight().y() - margin);
    const QRectF rect(topLeft, bottomRight);

    painter->drawRoundedRect(rect, 10, 10);
    painter->restore();
}
