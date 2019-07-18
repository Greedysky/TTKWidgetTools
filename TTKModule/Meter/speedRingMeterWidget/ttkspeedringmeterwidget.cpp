#include "ttkspeedringmeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>

TTKSpeedRingMeterWidget::TTKSpeedRingMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_minValue = 0;
    m_maxValue = 100;
    m_value = 50;

    m_precision = 0;
    m_scaleMajor = 10;
    m_scaleMinor = 10;
    m_startAngle = 40;
    m_endAngle = 40;

    m_animation = true;
    m_animationStep = 0.5;

    m_ringWidth = 10;
    m_ringStartPercent = 10;
    m_ringMidPercent = 10;
    m_ringEndPercent = 10;

    m_ringColorStart = QColor(60, 60, 60);
    m_ringColorMid = QColor(80, 80, 80);
    m_ringColorEnd = QColor(253, 107, 107);
    m_pointerColor = QColor(217, 217, 0);
    m_textColor = QColor(24, 188, 154);

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKSpeedRingMeterWidget::~TTKSpeedRingMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKSpeedRingMeterWidget::setRange(double minValue, double maxValue)
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

void TTKSpeedRingMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKSpeedRingMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKSpeedRingMeterWidget::setValue(double value)
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

void TTKSpeedRingMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKSpeedRingMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKSpeedRingMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKSpeedRingMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKSpeedRingMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKSpeedRingMeterWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKSpeedRingMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingWidth(int ringWidth)
{
    if(m_ringWidth != ringWidth)
    {
        m_ringWidth = ringWidth;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingStartPercent(int ringStartPercent)
{
    if(m_ringStartPercent != ringStartPercent)
    {
        m_ringStartPercent = ringStartPercent;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingMidPercent(int ringMidPercent)
{
    if(m_ringMidPercent != ringMidPercent)
    {
        m_ringMidPercent = ringMidPercent;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingEndPercent(int ringEndPercent)
{
    if(m_ringEndPercent != ringEndPercent)
    {
        m_ringEndPercent = ringEndPercent;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingColorStart(const QColor &ringColorStart)
{
    if(m_ringColorStart != ringColorStart)
    {
        m_ringColorStart = ringColorStart;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingColorMid(const QColor &ringColorMid)
{
    if(m_ringColorMid != ringColorMid)
    {
        m_ringColorMid = ringColorMid;
        update();
    }
}

void TTKSpeedRingMeterWidget::setRingColorEnd(const QColor &ringColorEnd)
{
    if(m_ringColorEnd != ringColorEnd)
    {
        m_ringColorEnd = ringColorEnd;
        update();
    }
}

void TTKSpeedRingMeterWidget::setPointerColor(const QColor &pointerColor)
{
    if(m_pointerColor != pointerColor)
    {
        m_pointerColor = pointerColor;
        update();
    }
}

void TTKSpeedRingMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

QSize TTKSpeedRingMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKSpeedRingMeterWidget::updateValue()
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

void TTKSpeedRingMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawRing(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);
    drawPointer(&painter);
    drawValue(&painter);
}

void TTKSpeedRingMeterWidget::drawRing(QPainter *painter)
{
    int radius = 100;
    painter->save();

    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(m_ringWidth);
    radius = radius - m_ringWidth;
    QRectF rect = QRectF(-radius, -radius, radius * 2, radius * 2);

    const double angleAll = 360.0 - m_startAngle - m_endAngle;
    const double angleStart = angleAll * m_ringStartPercent / 100;
    const double angleMid = angleAll * m_ringMidPercent / 100;
    const double angleEnd = angleAll * m_ringEndPercent / 100;

    pen.setColor(m_ringColorStart);
    painter->setPen(pen);
    painter->drawArc(rect, (270 - m_startAngle - angleStart) * 16, angleStart * 16);

    pen.setColor(m_ringColorMid);
    painter->setPen(pen);
    painter->drawArc(rect, (270 - m_startAngle - angleStart - angleMid) * 16, angleMid * 16);

    pen.setColor(m_ringColorEnd);
    painter->setPen(pen);
    painter->drawArc(rect, (270 - m_startAngle - angleStart - angleMid - angleEnd) * 16, angleEnd * 16);
    painter->restore();
}

void TTKSpeedRingMeterWidget::drawScale(QPainter *painter)
{
    int radius = 94;
    painter->save();

    QPen pen;
    pen.setColor(m_textColor);
    pen.setCapStyle(Qt::RoundCap);
    painter->rotate(m_startAngle);

    const int steps = (m_scaleMajor * m_scaleMinor);
    const double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    const int indexStart = steps * m_ringStartPercent / 100 + 1;
    const int indexMid = steps * m_ringMidPercent / 100 - 1;
    const int indexEnd = steps * m_ringEndPercent / 100 + 1;
    int index = 0;

    for(int i = 0; i <= steps; i++)
    {
        if(i % m_scaleMinor == 0)
        {
            if(index < indexStart)
            {
                pen.setColor(m_ringColorStart);
            }
            else if (index < (indexStart + indexMid))
            {
                pen.setColor(m_ringColorMid);
            }
            else if (index < (indexStart + indexMid + indexEnd))
            {
                pen.setColor(m_ringColorEnd);
            }
            index++;
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 13, 0, radius);
        }
        else
        {
            pen.setWidthF(0.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 5, 0, radius);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKSpeedRingMeterWidget::drawScaleNum(QPainter *painter)
{
    const int radius = 70;
    painter->save();
    painter->setPen(m_textColor);

    const double startRad = (360 - m_startAngle - 90) * (M_PI / 180);
    const double deltaRad = (360 - m_startAngle - m_endAngle) * (M_PI / 180) / m_scaleMajor;

    for(int i = 0; i <= m_scaleMajor; i++)
    {
        const double sina = qSin(startRad - i * deltaRad);
        const double cosa = qCos(startRad - i * deltaRad);
        const double value = 1.0 * i * ((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        const QString &strValue = QString("%1M").arg(value, 0, 'f', 0);
        const double textWidth = fontMetrics().width(strValue);
        const double textHeight = fontMetrics().height();
        const int x = radius * cosa - textWidth / 2;
        const int y = -radius * sina + textHeight / 4;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKSpeedRingMeterWidget::drawPointer(QPainter *painter)
{
    const int radius = 62;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(4, -5, 0, 0, -8, 5, 0, 0, radius);
    painter->rotate(m_startAngle);
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);

    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}


void TTKSpeedRingMeterWidget::drawValue(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(18);
    painter->setFont(font);

    QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    const QString &strValue = QString("%1").arg(m_currentValue, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
