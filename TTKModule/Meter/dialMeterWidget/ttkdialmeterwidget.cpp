#include "ttkdialmeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>

TTKDialMeterWidget::TTKDialMeterWidget(QWidget *parent)
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

    m_darkColor = QColor(60, 60, 60);
    m_lightColor = QColor(80, 80, 80);
    m_textColor = QColor(0, 0, 0);

    m_showValue = true;
    m_pointerStyle = PointerStyleCircle;
}

TTKDialMeterWidget::~TTKDialMeterWidget()
{

}

void TTKDialMeterWidget::setRange(double minValue, double maxValue)
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

void TTKDialMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKDialMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKDialMeterWidget::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue)
    {
        return;
    }

    if(m_value != value)
    {
        m_value = value;
        update();
    }
}

void TTKDialMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKDialMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKDialMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKDialMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKDialMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKDialMeterWidget::setDarkColor(const QColor &darkColor)
{
    if(m_darkColor != darkColor)
    {
        m_darkColor = darkColor;
        update();
    }
}

void TTKDialMeterWidget::setLightColor(const QColor &lightColor)
{
    if(m_lightColor != lightColor)
    {
        m_lightColor = lightColor;
        update();
    }
}

void TTKDialMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKDialMeterWidget::setShowValue(bool showValue)
{
    if(m_showValue != showValue)
    {
        m_showValue = showValue;
        update();
    }
}

void TTKDialMeterWidget::setPointerStyle(const PointerStyle &pointerStyle)
{
    if(m_pointerStyle != pointerStyle)
    {
        m_pointerStyle = pointerStyle;
        update();
    }
}

QSize TTKDialMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKDialMeterWidget::paintEvent(QPaintEvent *event)
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
    drawScaleNum(&painter);
    drawBorderCircle(&painter);
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

void TTKDialMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 80;
    painter->save();
    painter->rotate(m_startAngle);

    const int steps = (m_scaleMajor * m_scaleMinor);
    const double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(m_textColor);
    for(int i = 0; i <= steps; i++)
    {
        if(i % m_scaleMinor == 0)
        {
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 8, 0, radius);
        }
        else
        {
            pen.setWidthF(0.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 8, 0, radius - 3);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKDialMeterWidget::drawScaleNum(QPainter *painter)
{
    const int radius = 90;
    painter->save();
    painter->setPen(m_textColor);

    const double startRad = (360 - m_startAngle - 90) * (M_PI / 180);
    const double deltaRad = (360 - m_startAngle - m_endAngle) * (M_PI / 180) / m_scaleMajor;

    for(int i = 0; i <= m_scaleMajor; i++)
    {
        const double sina = qSin(startRad - i * deltaRad);
        const double cosa = qCos(startRad - i * deltaRad);
        const double value = 1.0 * i * ((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        const QString &strValue = QString("%1").arg(value, 0, 'f', m_precision);
        const double textWidth = fontMetrics().width(strValue);
        const double textHeight = fontMetrics().height();
        const int x = radius * cosa - textWidth / 2;
        const int y = -radius * sina + textHeight / 4;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKDialMeterWidget::drawBorderCircle(QPainter *painter)
{
    const int radius = 70;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient bgGradient(0, -radius, 0, radius);
    bgGradient.setColorAt(0.0, m_darkColor);
    bgGradient.setColorAt(1.0, m_lightColor);
    painter->setBrush(bgGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKDialMeterWidget::drawBgCircle(QPainter *painter)
{
    const int radius = 60;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient bgGradient(0, -radius, 0, radius);
    bgGradient.setColorAt(0.0, m_lightColor);
    bgGradient.setColorAt(1.0, m_darkColor);
    painter->setBrush(bgGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKDialMeterWidget::drawPointerCircle(QPainter *painter)
{
    const int radius = 15;
    const int offset = 10;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->rotate(m_startAngle);
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);

    painter->rotate(degRotate);
    QLinearGradient bgGradient(0, 0, radius * 2, radius * 2);
    bgGradient.setColorAt(0.0, m_darkColor);
    bgGradient.setColorAt(1.0, m_lightColor);

    painter->setBrush(bgGradient);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->setPen(QPen(m_darkColor, 2, Qt::SolidLine, Qt::RoundCap));
    painter->drawLine(0, radius * 2 + offset, 0, radius * 2 + 10 + offset);
    painter->restore();
}

void TTKDialMeterWidget::drawPointerIndicator(QPainter *painter)
{
    const int radius = 55;
    painter->save();
    painter->setOpacity(0.8);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_darkColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);

    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKDialMeterWidget::drawPointerIndicatorR(QPainter *painter)
{
    const int radius = 55;
    painter->save();
    painter->setOpacity(0.6);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_darkColor);
    painter->setPen(pen);
    painter->setBrush(m_darkColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(4);
    painter->setPen(pen);
    painter->drawLine(0, 0, 0, radius);
    painter->restore();
}

void TTKDialMeterWidget::drawPointerTriangle(QPainter *painter)
{
    const int radius = 10;
    const int offset = 45;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_darkColor);

    QPolygon pts;
    pts.setPoints(3, -radius / 2, offset, radius / 2, offset, 0, radius + offset);
    painter->rotate(m_startAngle);
    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);

    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKDialMeterWidget::drawCenterCircle(QPainter *painter)
{
    if(!m_showValue)
    {
        return;
    }
    const int radius = 15;

    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient bgGradient(0, -radius, 0, radius);
    bgGradient.setColorAt(0.0, m_darkColor);
    bgGradient.setColorAt(1.0, m_lightColor);

    painter->setBrush(bgGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKDialMeterWidget::drawValue(QPainter *painter)
{
    if(!m_showValue)
    {
        return;
    }

    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(12);
    font.setBold(true);
    painter->setFont(font);

    QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    QString strValue = QString("%1").arg(m_value, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
