#include "ttkpanelmeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>

TTKPanelMeterWidget::TTKPanelMeterWidget(QWidget *parent)
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
    m_ringColor = QColor(60, 60, 60);
    m_scaleColor = QColor(100, 181, 200);
    m_pointerColor = QColor(0, 181, 200);
    m_bgColor = QColor(0, 0, 0);
    m_textColor = QColor(255, 255, 255);
    m_unit = "m";

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKPanelMeterWidget::~TTKPanelMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKPanelMeterWidget::setRange(double minValue, double maxValue)
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

void TTKPanelMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKPanelMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKPanelMeterWidget::setValue(double value)
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

void TTKPanelMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKPanelMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKPanelMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKPanelMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKPanelMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKPanelMeterWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKPanelMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKPanelMeterWidget::setRingWidth(int ringWidth)
{
    if(m_ringWidth != ringWidth)
    {
        m_ringWidth = ringWidth;
        update();
    }
}

void TTKPanelMeterWidget::setRingColor(const QColor &ringColor)
{
    if(m_ringColor != ringColor)
    {
        m_ringColor = ringColor;
        update();
    }
}

void TTKPanelMeterWidget::setScaleColor(const QColor &scaleColor)
{
    if(m_scaleColor != scaleColor)
    {
        m_scaleColor = scaleColor;
        update();
    }
}

void TTKPanelMeterWidget::setPointerColor(const QColor &pointerColor)
{
    if(m_pointerColor != pointerColor)
    {
        m_pointerColor = pointerColor;
        update();
    }
}

void TTKPanelMeterWidget::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

void TTKPanelMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKPanelMeterWidget::setUnit(const QString &unit)
{
    if(m_unit != unit)
    {
        m_unit = unit;
        update();
    }
}

void TTKPanelMeterWidget::setText(const QString &text)
{
    if(m_text != text)
    {
        m_text = text;
        update();
    }
}

QSize TTKPanelMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKPanelMeterWidget::updateValue()
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

void TTKPanelMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

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

    drawRing(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);
    drawPointer(&painter);
    drawValue(&painter);
}

void TTKPanelMeterWidget::drawRing(QPainter *painter)
{
    int radius = 70;
    painter->save();

    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(m_ringWidth);
    pen.setColor(m_ringColor);
    painter->setPen(pen);
    radius = radius - m_ringWidth;

    const QRectF &rect = QRectF(-radius, -radius, radius * 2, radius * 2);
    const double &angleAll = 360.0 - m_startAngle - m_endAngle;
    painter->drawArc(rect, (270 - m_startAngle - angleAll) * 16, angleAll * 16);
    painter->restore();
}

void TTKPanelMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 80;
    painter->save();
    painter->rotate(m_startAngle);

    const int steps = (m_scaleMajor * m_scaleMinor);
    const double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(m_scaleColor);

    for(int i = 0; i <= steps; i++)
    {
        if(i % m_scaleMinor == 0)
        {
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 8, 0, radius + 5);
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

void TTKPanelMeterWidget::drawScaleNum(QPainter *painter)
{
    const int radius = 95;
    painter->save();
    painter->setPen(m_scaleColor);

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

void TTKPanelMeterWidget::drawPointer(QPainter *painter)
{
    const int radius = 70;
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

void TTKPanelMeterWidget::drawValue(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(15);
    painter->setFont(font);

    QString strValue = QString("%1").arg(m_currentValue, 0, 'f', m_precision);
    strValue = QString("%1 %2").arg(strValue).arg(m_unit);

    const QRectF valueRect(-radius, radius / 3.5, radius * 2, radius / 3.5);
    painter->drawText(valueRect, Qt::AlignCenter, strValue);

    const QRectF textRect(-radius, radius / 2.5, radius * 2, radius / 2.5);
    font.setPixelSize(12);
    painter->setFont(font);
    painter->drawText(textRect, Qt::AlignCenter, m_text);
    painter->restore();
}
