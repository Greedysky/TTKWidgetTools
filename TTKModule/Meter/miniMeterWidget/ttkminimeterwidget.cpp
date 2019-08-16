#include "ttkminimeterwidget.h"

#include <qmath.h>
#include <QPainter>

TTKMiniMeterWidget::TTKMiniMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_minValue = 0;
    m_maxValue = 100;
    m_value = 50;

    m_step = 20;
    m_precision = 0;
    m_startAngle = 40;
    m_endAngle = 40;

    m_borderColor = QColor(60, 60, 60);
    m_bgColor = QColor(233, 185, 110);
    m_textColor = QColor(92, 53, 102);
    m_percentColor = QColor(253, 107, 107);

    m_showValue = false;

    m_pointerStyle = PointerStyleIndicator;
}

TTKMiniMeterWidget::~TTKMiniMeterWidget()
{

}

void TTKMiniMeterWidget::setRange(double minValue, double maxValue)
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

void TTKMiniMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKMiniMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKMiniMeterWidget::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue)
    {
        return;
    }

    m_value = value;
    update();
}

void TTKMiniMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKMiniMeterWidget::setStep(int step)
{
    if(m_step != step)
    {
        m_step = step;
        update();
    }
}

void TTKMiniMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKMiniMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKMiniMeterWidget::setBorderColor(const QColor &borderColor)
{
    if(m_borderColor != borderColor)
    {
        m_borderColor = borderColor;
        update();
    }
}

void TTKMiniMeterWidget::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

void TTKMiniMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKMiniMeterWidget::setPercentColor(const QColor &percentColor)
{
    if(m_percentColor != percentColor)
    {
        m_percentColor = percentColor;
        update();
    }
}

void TTKMiniMeterWidget::setShowValue(bool showValue)
{
    if(m_showValue != showValue)
    {
        m_showValue = showValue;
        update();
    }
}

void TTKMiniMeterWidget::setPointerStyle(const PointerStyle &pointerStyle)
{
    if(m_pointerStyle != pointerStyle)
    {
        m_pointerStyle = pointerStyle;
        update();
    }
}

QSize TTKMiniMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKMiniMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawScale(&painter);
    drawBgCircle(&painter);

    if(m_pointerStyle == PointerStyleCircle)
    {
        drawPointerCircle(&painter);
    }
    else if(m_pointerStyle == PointerStyleIndicator)
    {
        drawPointerIndicator(&painter);
    }
    else if(m_pointerStyle == PointerStyleIndicatorR)
    {
        drawPointerIndicatorR(&painter);
    }
    else if(m_pointerStyle == PointerStyleTriangle)
    {
        drawPointerTriangle(&painter);
    }

    drawCenterCircle(&painter);
    drawValue(&painter);
}

void TTKMiniMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 96;
    const int offset = 10;

    painter->save();
    painter->rotate(m_startAngle);

    const double angleStep = (360.0 - m_startAngle - m_endAngle) / m_step;
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);

    QPen pen;
    pen.setWidthF(5.0);
    pen.setCapStyle(Qt::RoundCap);
    double rotate = 0;

    for(int i = 0; i <= m_step; i++)
    {
        if(rotate <= degRotate)
        {
            pen.setColor(m_percentColor);
        }
        else
        {
            pen.setColor(m_textColor);
        }

        if(m_value == m_minValue)
        {
            pen.setColor(m_textColor);
        }

        painter->setPen(pen);
        painter->drawLine(0, radius - offset, 0, radius);
        painter->rotate(angleStep);
        rotate += angleStep;
    }
    painter->restore();
}

void TTKMiniMeterWidget::drawBgCircle(QPainter *painter)
{
    const int radius = 75;
    painter->save();

    QPen pen;
    pen.setWidthF(5.0);
    pen.setColor(m_borderColor);
    painter->setPen(pen);
    painter->setBrush(m_bgColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKMiniMeterWidget::drawCenterCircle(QPainter *painter)
{
    const int radius = 15;
    painter->save();

    painter->setPen(Qt::NoPen);
    painter->setBrush(m_borderColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKMiniMeterWidget::drawPointerCircle(QPainter *painter)
{
    const int radius = 15;
    const int offset = 20;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
    painter->rotate(degRotate);
    painter->setBrush(m_percentColor);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->restore();
}

void TTKMiniMeterWidget::drawPointerIndicator(QPainter *painter)
{
    int radius = 65;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_percentColor);

    QPolygon pts;
    pts.setPoints(3, -8, 0, 8, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    radius = radius / 4;
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKMiniMeterWidget::drawPointerIndicatorR(QPainter *painter)
{
    int radius = 65;
    painter->save();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_percentColor);
    painter->setPen(pen);
    painter->setBrush(m_percentColor);

    QPolygon pts;
    pts.setPoints(3, -8, 0, 8, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
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

void TTKMiniMeterWidget::drawPointerTriangle(QPainter *painter)
{
    const int radius = 20;
    const int offset = 55;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_percentColor);

    QPolygon pts;
    pts.setPoints(3, -radius / 2, offset, radius / 2, offset, 0, radius + offset);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKMiniMeterWidget::drawValue(QPainter *painter)
{
    if(!m_showValue)
    {
        return;
    }

    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(radius - 50);
    font.setBold(true);
    painter->setFont(font);

    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    QString strValue = QString("%1").arg(m_value, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
