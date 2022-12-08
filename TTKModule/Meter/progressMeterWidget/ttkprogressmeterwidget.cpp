#include "ttkprogressmeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>

TTKProgressMeterWidget::TTKProgressMeterWidget(QWidget *parent)
    : QWidget(parent),
      m_minValue(0),
      m_maxValue(100),
      m_value(50),
      m_precision(0),
      m_startAngle(40),
      m_endAngle(40),
      m_backgroundColor(50, 50, 50),
      m_progressColor(7, 184, 13),
      m_progressBackgroundColor(15, 84, 100),
      m_circleColorStart(80, 80, 80),
      m_circleColorEnd(100, 100, 100),
      m_textColor(255, 255, 255),
      m_showPointer(true),
      m_showValue(true),
      m_pointerStyle(PointerStyle::Circle),
      m_reverse(false),
      m_currentValue(50)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}


TTKProgressMeterWidget::~TTKProgressMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKProgressMeterWidget::setRange(double minValue, double maxValue)
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

void TTKProgressMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKProgressMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKProgressMeterWidget::setValue(double value)
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
    m_timer->start();
}

void TTKProgressMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKProgressMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKProgressMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKProgressMeterWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        update();
    }
}

void TTKProgressMeterWidget::setProgressColor(const QColor &progressColor)
{
    if(m_progressColor != progressColor)
    {
        m_progressColor = progressColor;
        update();
    }
}

void TTKProgressMeterWidget::setProgressBackgroundColor(const QColor &progressBackgroundColor)
{
    if(m_progressBackgroundColor != progressBackgroundColor)
    {
        m_progressBackgroundColor = progressBackgroundColor;
        update();
    }
}

void TTKProgressMeterWidget::setCircleColorStart(const QColor &circleColorStart)
{
    if(m_circleColorStart != circleColorStart)
    {
        m_circleColorStart = circleColorStart;
        update();
    }
}

void TTKProgressMeterWidget::setCircleColorEnd(const QColor &circleColorEnd)
{
    if(m_circleColorEnd != circleColorEnd)
    {
        m_circleColorEnd = circleColorEnd;
        update();
    }
}

void TTKProgressMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKProgressMeterWidget::setShowPointer(bool showPointer)
{
    if(m_showPointer != showPointer)
    {
        m_showPointer = showPointer;
        update();
    }
}

void TTKProgressMeterWidget::setShowValue(bool showValue)
{
    if(m_showValue != showValue)
    {
        m_showValue = showValue;
        update();
    }
}

void TTKProgressMeterWidget::setPointerStyle(const PointerStyle &pointerStyle)
{
    if(m_pointerStyle != pointerStyle)
    {
        m_pointerStyle = pointerStyle;
        update();
    }
}

QSize TTKProgressMeterWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKProgressMeterWidget::updateValue()
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
            m_currentValue += 0.5;
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
            m_currentValue -= 0.5;
        }
    }
    update();
}

void TTKProgressMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBackground(&painter);
    drawColorPie(&painter);
    drawCoverCircle(&painter);
    drawCircle(&painter);

    if(m_pointerStyle == PointerStyle::Circle)
    {
        drawPointerCircle(&painter);
    }
    else if(m_pointerStyle == PointerStyle::Indicator)
    {
        drawPointerIndicator(&painter);
    }
    else if(m_pointerStyle == PointerStyle::IndicatorR)
    {
        drawPointerIndicatorR(&painter);
    }
    else if(m_pointerStyle == PointerStyle::Triangle)
    {
        drawPointerTriangle(&painter);
    }

    drawValue(&painter);
}

void TTKProgressMeterWidget::drawBackground(QPainter *painter)
{
    constexpr int radius = 99;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_backgroundColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawColorPie(QPainter *painter)
{
    constexpr int radius = 95;
    painter->save();
    painter->setPen(Qt::NoPen);
    const QRectF rect(-radius, -radius, radius * 2, radius * 2);

    const double angleAll = 360.0 - m_startAngle - m_endAngle;
    const double angleCurrent = angleAll * ((m_currentValue - m_minValue) / (m_maxValue - m_minValue));
    const double angleOther = angleAll - angleCurrent;

    painter->setBrush(m_progressColor);
    painter->drawPie(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);

    painter->setBrush(m_progressBackgroundColor);
    painter->drawPie(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    painter->restore();
}

void TTKProgressMeterWidget::drawCoverCircle(QPainter *painter)
{
    constexpr int radius = 85;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_backgroundColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawCircle(QPainter *painter)
{
    constexpr int radius = 80;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient bgGradient(0, -radius, 0, radius);
    bgGradient.setColorAt(0.0, m_circleColorStart);
    bgGradient.setColorAt(1.0, m_circleColorEnd);
    painter->setBrush(bgGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawPointerCircle(QPainter *painter)
{
    if(!m_showPointer)
    {
        return;
    }

    constexpr int radius = 15;
    constexpr int offset = 20;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->setBrush(m_progressColor);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawPointerIndicator(QPainter *painter)
{
    if(!m_showPointer)
    {
        return;
    }

    int radius = 65;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_progressColor);

    QPolygon pts;
    pts.setPoints(3, -8, 0, 8, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    radius = radius / 4;
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawPointerIndicatorR(QPainter *painter)
{
    if(!m_showPointer)
    {
        return;
    }

    int radius = 65;
    painter->save();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_progressColor);
    painter->setPen(pen);
    painter->setBrush(m_progressColor);

    QPolygon pts;
    pts.setPoints(3, -8, 0, 8, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(4);
    painter->setPen(pen);
    painter->drawLine(0, 0, 0, radius);

    radius = radius / 4;
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKProgressMeterWidget::drawPointerTriangle(QPainter *painter)
{
    if(!m_showPointer)
    {
        return;
    }

    constexpr int radius = 20;
    constexpr int offset = 55;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_progressColor);

    QPolygon pts;
    pts.setPoints(3, -radius / 2, offset, radius / 2, offset, 0, radius + offset);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKProgressMeterWidget::drawValue(QPainter *painter)
{
    if(!m_showValue)
    {
        return;
    }

    constexpr int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(m_showPointer ? radius - 50 : radius - 15);
    font.setBold(true);
    painter->setFont(font);

    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(m_currentValue, 0, 'f', m_precision));
    painter->restore();
}
