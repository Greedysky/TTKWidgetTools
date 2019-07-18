#include "ttkpercentmeterwidget.h"

#include <qmath.h>
#include <QPainter>

TTKPercentMeterWidget::TTKPercentMeterWidget(QWidget *parent)
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

    m_arcColor = QColor(114, 159, 207);
    m_scaleColor = QColor(233, 185, 110);
    m_scaleNumColor = QColor(92, 53, 102);
    m_textColor = QColor(46, 52, 54);
    m_titleColor = QColor(0, 0, 0);
    m_baseColor = QColor(178, 221, 253);
    m_bgColor = Qt::transparent;

    m_title = "Hello";
}

void TTKPercentMeterWidget::setRange(double minValue, double maxValue)
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

void TTKPercentMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKPercentMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKPercentMeterWidget::setValue(double value)
{
    if(value < m_minValue || value > m_maxValue)
    {
        return;
    }

    m_value = value;
    update();
}

void TTKPercentMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKPercentMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKPercentMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKPercentMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKPercentMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKPercentMeterWidget::setArcColor(const QColor &arcColor)
{
    if(m_arcColor != arcColor)
    {
        m_arcColor = arcColor;
        update();
    }
}

void TTKPercentMeterWidget::setScaleColor(const QColor &scaleColor)
{
    if(m_scaleColor != scaleColor)
    {
        m_scaleColor = scaleColor;
        update();
    }
}

void TTKPercentMeterWidget::setScaleNumColor(const QColor &scaleNumColor)
{
    if(m_scaleNumColor != scaleNumColor)
    {
        m_scaleNumColor = scaleNumColor;
        update();
    }
}

void TTKPercentMeterWidget::setTitle(const QString &title)
{
    if(m_title != title)
    {
        m_title = title;
        update();
    }
}

void TTKPercentMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKPercentMeterWidget::setTitleColor(const QColor &titleColor)
{
    if(m_titleColor != titleColor)
    {
        m_titleColor = titleColor;
        update();
    }
}

void TTKPercentMeterWidget::setBaseColor(const QColor &baseColor)
{
    if(m_baseColor != baseColor)
    {
        m_baseColor = baseColor;
        update();
    }
}

void TTKPercentMeterWidget::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

QSize TTKPercentMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKPercentMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    if(m_bgColor != Qt::transparent)
    {
        painter.setPen(Qt::NoPen);
        painter.fillRect(rect(), m_bgColor);
    }
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawArc(&painter);
    drawCircle(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);
    drawValue(&painter);
    drawTitle(&painter);
}

void TTKPercentMeterWidget::drawArc(QPainter *painter)
{
    const int radius = 95;
    painter->save();
    painter->setBrush(Qt::NoBrush);

    QPen pen;
    pen.setWidthF(5);
    pen.setCapStyle(Qt::RoundCap);

    const double angleAll = 360.0 - m_startAngle - m_endAngle;
    const double angleCurrent = angleAll * ((m_value - m_minValue) / (m_maxValue - m_minValue));
    const double angleOther = angleAll - angleCurrent;
    const QRectF &rect = QRectF(-radius, -radius, radius * 2, radius * 2);

    pen.setColor(m_arcColor);
    painter->setPen(pen);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);

    pen.setColor(m_scaleColor);
    painter->setPen(pen);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    painter->restore();
}

void TTKPercentMeterWidget::drawCircle(QPainter *painter)
{
    const int radius = 6;
    const int offset = 83;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_arcColor);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue);
    painter->rotate(degRotate);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->restore();
}

void TTKPercentMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 90;
    painter->save();
    painter->rotate(m_startAngle);

    const int steps = (m_scaleMajor * m_scaleMinor);
    const double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    QPen pen;
    pen.setColor(m_scaleColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(1.0);
    painter->setPen(pen);

    for(int i = 0; i <= steps; i++)
    {
        painter->drawLine(0, radius - 5, 0, radius);
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKPercentMeterWidget::drawScaleNum(QPainter *painter)
{
    const int radius = 75;
    painter->save();
    painter->setPen(m_scaleNumColor);

    const double startRad = (360 - m_startAngle - 90) * (M_PI / 180);
    const double deltaRad = (360 - m_startAngle - m_endAngle) * (M_PI / 180) / m_scaleMajor;

    for(int i = 0; i <= m_scaleMajor; i++)
    {
        const double sina = qSin(startRad - i * deltaRad);
        const double cosa = qCos(startRad - i * deltaRad);
        const double value = 1.0 * i * ((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        const QString &strValue = QString("%1").arg((double)value, 0, 'f', m_precision);
        const double textWidth = fontMetrics().width(strValue);
        const double textHeight = fontMetrics().height();
        const int x = radius * cosa - textWidth / 2;
        const int y = -radius * sina + textHeight / 4;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKPercentMeterWidget::drawValue(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(30);
    painter->setFont(font);

    const QRectF textRect(-radius, 0, radius * 2, radius / 3);
    const QString &strValue = QString("%1%").arg(m_value, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}

void TTKPercentMeterWidget::drawTitle(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_titleColor);

    QFont font;
    font.setPixelSize(20);
    painter->setFont(font);

    const QRectF textRect(-radius, radius / 3, radius * 2, radius / 3);
    painter->drawText(textRect, Qt::AlignCenter, m_title);
    painter->restore();
}
