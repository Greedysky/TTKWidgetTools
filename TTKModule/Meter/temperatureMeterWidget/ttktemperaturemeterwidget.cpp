#include "ttktemperaturemeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>

TTKTemperatureMeterWidget::TTKTemperatureMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_minValue = 0;
    m_maxValue = 100;
    m_value = 50;

    m_startAngle = 40;
    m_endAngle = 40;

    m_animation = true;
    m_animationStep = 0.5;

    m_outerCircleColor = QColor(80, 80, 80);
    m_innerCircleColor = QColor(60, 60, 60);
    m_centerCircleColor = QColor(60, 60, 60);
    m_usedColor = QColor(24, 188, 154);
    m_freeColor = QColor(255, 255, 255);
    m_textColor = QColor(255, 255, 255);

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKTemperatureMeterWidget::~TTKTemperatureMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKTemperatureMeterWidget::setRange(double minValue, double maxValue)
{
    if(minValue >= maxValue)
    {
        return;
    }

    m_minValue = minValue;
    m_maxValue = maxValue;

    if(m_value < m_minValue || m_value > m_maxValue)
    {
        setValue(m_value);
    }

    update();
}

void TTKTemperatureMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKTemperatureMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKTemperatureMeterWidget::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue)
    {
        return;
    }

    if(value > m_value)
    {
        m_reverse = false;
    }
    else if(value < m_value)
    {
        m_reverse = true;
    }

    m_value = value;

    if(!m_animation)
    {
        m_currentValue = value;
        update();
    }
    else
    {
        m_timer->start();
    }
}

void TTKTemperatureMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKTemperatureMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKTemperatureMeterWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKTemperatureMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKTemperatureMeterWidget::setOuterCircleColor(const QColor &outerCircleColor)
{
    if(m_outerCircleColor != outerCircleColor)
    {
        m_outerCircleColor = outerCircleColor;
        update();
    }
}

void TTKTemperatureMeterWidget::setInnerCircleColor(const QColor &innerCircleColor)
{
    if(m_innerCircleColor != innerCircleColor)
    {
        m_innerCircleColor = innerCircleColor;
        update();
    }
}

void TTKTemperatureMeterWidget::setCenterCircleColor(const QColor &centerCircleColor)
{
    if(m_centerCircleColor != centerCircleColor)
    {
        m_centerCircleColor = centerCircleColor;
        update();
    }
}

void TTKTemperatureMeterWidget::setUsedColor(const QColor &usedColor)
{
    if(m_usedColor != usedColor)
    {
        m_usedColor = usedColor;
        update();
    }
}

void TTKTemperatureMeterWidget::setFreeColor(const QColor &freeColor)
{
    if(m_freeColor != freeColor)
    {
        m_freeColor = freeColor;
        update();
    }
}

void TTKTemperatureMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

QSize TTKTemperatureMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKTemperatureMeterWidget::updateValue()
{
    if(!m_reverse)
    {
        if(m_currentValue >= m_value)
        {
            m_currentValue = m_value;
            m_timer->stop();
        }
        else
        {
            m_currentValue += m_animationStep;
        }
    }
    else
    {
        if(m_currentValue <= m_value)
        {
            m_currentValue = m_value;
            m_timer->stop();
        }
        else
        {
            m_currentValue -= m_animationStep;
        }
    }
    update();
}

void TTKTemperatureMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawOuterCircle(&painter);
    drawInnerCircle(&painter);
    drawProgress(&painter);
    drawCenterCircle(&painter);
    drawUnit(&painter);
}

void TTKTemperatureMeterWidget::drawOuterCircle(QPainter *painter)
{
    const int radius = 91;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_outerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKTemperatureMeterWidget::drawInnerCircle(QPainter *painter)
{
    const int radius = 80;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_innerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKTemperatureMeterWidget::drawProgress(QPainter *painter)
{
    const int radius = 75;
    painter->save();
    painter->setPen(Qt::NoPen);
    const QRectF rect(-radius, -radius, radius * 2, radius * 2);

    const double angleAll = 360.0 - m_startAngle - m_endAngle;
    const double angleCurrent = angleAll * ((m_currentValue - m_minValue) / (m_maxValue - m_minValue));
    const double angleOther = angleAll - angleCurrent;

    painter->setBrush(m_usedColor);
    painter->drawPie(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);

    painter->setBrush(m_freeColor);
    painter->drawPie(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    painter->restore();
}

void TTKTemperatureMeterWidget::drawCenterCircle(QPainter *painter)
{
    const int radius = 60;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_centerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKTemperatureMeterWidget::drawUnit(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(30);
    painter->setFont(font);

    const int offsetY = 80;
    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignCenter, QString::number(m_value));
    const QRectF unitRect(-radius, -radius + offsetY, radius * 2, radius * 2 - offsetY);
    painter->drawText(unitRect, Qt::AlignCenter, "°C");
    painter->restore();
}
