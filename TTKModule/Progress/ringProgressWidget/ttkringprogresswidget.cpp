#include "ttkringprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKRingProgressWidget::TTKRingProgressWidget(QWidget *parent)
    : QWidget(parent)
{
    m_minValue = 0;
    m_maxValue = 100;
    m_value = 50;

    m_precision = 0;
    m_clockWise = true;
    m_showPercent = true;
    m_alarmMode = true;

    m_startAngle = 40;
    m_ringPadding = 5;
    m_ringWidth = 15;

    m_animation = true;
    m_animationStep = 0.5;

    m_bgColor = QColor(60, 60, 60);
    m_textColor = QColor(60, 60, 60);
    m_ringColor = QColor(60, 60, 60);
    m_ringBgColor = QColor(60, 60, 60);
    m_circleColor = QColor(60, 60, 60);

    m_ringValueF = 10;
    m_ringValueS = 20;
    m_ringValueT = 40;

    m_ringColorF = QColor(60, 60, 60);
    m_ringColorS = QColor(60, 60, 60);
    m_ringColorT = QColor(60, 60, 60);

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKRingProgressWidget::~TTKRingProgressWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKRingProgressWidget::setRange(double minValue, double maxValue)
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

void TTKRingProgressWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKRingProgressWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKRingProgressWidget::setValue(double value)
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

void TTKRingProgressWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKRingProgressWidget::setClockWise(bool clockWise)
{
    if(m_clockWise != clockWise)
    {
        m_clockWise = clockWise;
        update();
    }
}

void TTKRingProgressWidget::setShowPercent(bool showPercent)
{
    if(m_showPercent != showPercent)
    {
        m_showPercent = showPercent;
        update();
    }
}

void TTKRingProgressWidget::setAlarmMode(bool alarmMode)
{
    if(m_alarmMode != alarmMode)
    {
        m_alarmMode = alarmMode;
        update();
    }
}

void TTKRingProgressWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKRingProgressWidget::setRingPadding(int ringPadding)
{
    if(m_ringPadding != ringPadding)
    {
        m_ringPadding = ringPadding;
        update();
    }
}

void TTKRingProgressWidget::setRingWidth(int ringWidth)
{
    if(m_ringWidth != ringWidth)
    {
        m_ringWidth = ringWidth;
        update();
    }
}

void TTKRingProgressWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKRingProgressWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKRingProgressWidget::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

void TTKRingProgressWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKRingProgressWidget::setRingColor(const QColor &ringColor)
{
    if(m_ringColor != ringColor)
    {
        m_ringColor = ringColor;
        update();
    }
}

void TTKRingProgressWidget::setRingBgColor(const QColor &ringBgColor)
{
    if(m_ringBgColor != ringBgColor)
    {
        m_ringBgColor = ringBgColor;
        update();
    }
}

void TTKRingProgressWidget::setCircleColor(const QColor &circleColor)
{
    if(m_circleColor != circleColor)
    {
        m_circleColor = circleColor;
        update();
    }
}

void TTKRingProgressWidget::setRingValueF(int ringValueF)
{
    if(m_ringValueF != ringValueF)
    {
        m_ringValueF = ringValueF;
        update();
    }
}

void TTKRingProgressWidget::setRingValueS(int ringValueS)
{
    if(m_ringValueS != ringValueS)
    {
        m_ringValueS = ringValueS;
        update();
    }
}

void TTKRingProgressWidget::setRingValueT(int ringValueT)
{
    if(m_ringValueT != ringValueT)
    {
        m_ringValueT = ringValueT;
        update();
    }
}

void TTKRingProgressWidget::setRingColorF(const QColor &ringColorF)
{
    if(m_ringColorF != ringColorF)
    {
        m_ringColorF = ringColorF;
        update();
    }
}

void TTKRingProgressWidget::setRingColorS(const QColor &ringColorS)
{
    if(m_ringColorS != ringColorS)
    {
        m_ringColorS = ringColorS;
        update();
    }
}

void TTKRingProgressWidget::setRingColorT(const QColor &ringColorT)
{
    if(m_ringColorT != ringColorT)
    {
        m_ringColorT = ringColorT;
        update();
    }
}

QSize TTKRingProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKRingProgressWidget::updateValue()
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

void TTKRingProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBg(&painter);
    drawRing(&painter);

    if(m_ringPadding > 0)
    {
        drawPadding(&painter);
    }

    drawCircle(&painter);
    drawValue(&painter);
}

void TTKRingProgressWidget::drawBg(QPainter *painter)
{
    const int radius = 99;
    painter->save();
    painter->setPen(Qt::NoPen);

    painter->setBrush(m_ringPadding == 0 ? m_ringBgColor : m_bgColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRingProgressWidget::drawRing(QPainter *painter)
{
    const int radius = 99 - m_ringPadding;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_ringColor);
    QRectF rect(-radius, -radius, radius * 2, radius * 2);

    const double angleAll = 360.0;
    double angleCurrent = angleAll * ((m_currentValue - m_minValue) / (m_maxValue - m_minValue));
    double angleOther = angleAll - angleCurrent;

    if(!m_clockWise)
    {
        angleCurrent = -angleCurrent;
        angleOther = -angleOther;
    }

    QColor color = m_ringColor;
    if(m_alarmMode)
    {
        if(m_currentValue >= m_ringValueT)
        {
            color = m_ringColorT;
        }
        else if(m_currentValue >= m_ringValueS)
        {
            color = m_ringColorS;
        }
        else {
            color = m_ringColorF;
        }
    }
    else
    {
        if(m_currentValue <= m_ringValueF)
        {
            color = m_ringColorF;
        }
        else if(m_currentValue <= m_ringValueS)
        {
            color = m_ringColorS;
        }
        else {
            color = m_ringColorT;
        }
    }

    painter->setBrush(color);
    painter->drawPie(rect, (m_startAngle - angleCurrent) * 16, angleCurrent * 16);

    painter->setBrush(m_ringBgColor);
    painter->drawPie(rect, (m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    painter->restore();
}

void TTKRingProgressWidget::drawPadding(QPainter *painter)
{
    const int radius = 99 - m_ringWidth - m_ringPadding;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_bgColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRingProgressWidget::drawCircle(QPainter *painter)
{
    const int radius = 99 - m_ringWidth - (m_ringPadding * 2);
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_circleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRingProgressWidget::drawValue(QPainter *painter)
{
    const int radius = 99 - m_ringWidth - (m_ringPadding * 2);
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    const int fontSize = radius - (m_showPercent ? 20 : 6);
    font.setPixelSize(fontSize);
    painter->setFont(font);

    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    QString strValue;

    if(m_showPercent)
    {
        const double percent = (m_currentValue * 100) / (m_maxValue - m_minValue);
        strValue = QString("%1%").arg(percent, 0, 'f', m_precision);
    }
    else
    {
        strValue = QString("%1").arg(m_currentValue, 0, 'f', m_precision);
    }

    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
