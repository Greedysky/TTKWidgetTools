#include "ttkarcmeterwidget.h"

#include <qmath.h>
#include <QTimer>
#include <QPainter>
#include <QDebug>

TTKArcMeterWidget::TTKArcMeterWidget(QWidget *parent)
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

    m_arcColor = QColor(60, 60, 60);
    m_scaleColor = QColor(233, 185, 110);
    m_scaleNumColor = QColor(92, 53, 102);
    m_pointerColor = QColor(253, 107, 107);
    m_textColor = QColor(0, 0, 0);

    m_pointerStyle = PointerStyleIndicator;

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKArcMeterWidget::~TTKArcMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKArcMeterWidget::setRange(double minValue, double maxValue)
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

void TTKArcMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKArcMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKArcMeterWidget::setValue(double value)
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

void TTKArcMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKArcMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKArcMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKArcMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKArcMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKArcMeterWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKArcMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKArcMeterWidget::setArcColor(const QColor &arcColor)
{
    if(m_arcColor != arcColor)
    {
        m_arcColor = arcColor;
        update();
    }
}

void TTKArcMeterWidget::setScaleColor(const QColor &scaleColor)
{
    if(m_scaleColor != scaleColor)
    {
        m_scaleColor = scaleColor;
        update();
    }
}

void TTKArcMeterWidget::setScaleNumColor(const QColor &scaleNumColor)
{
    if(m_scaleNumColor != scaleNumColor)
    {
        m_scaleNumColor = scaleNumColor;
        update();
    }
}

void TTKArcMeterWidget::setPointerColor(const QColor &pointerColor)
{
    if(m_pointerColor != pointerColor)
    {
        m_pointerColor = pointerColor;
        update();
    }
}

void TTKArcMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKArcMeterWidget::setPointerStyle(const PointerStyle &pointerStyle)
{
    if(m_pointerStyle != pointerStyle)
    {
        m_pointerStyle = pointerStyle;
        update();
    }
}

QSize TTKArcMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKArcMeterWidget::updateValue()
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

void TTKArcMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawArc(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);

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

    drawRoundCircle(&painter);
    drawCenterCircle(&painter);
    drawValue(&painter);
}

void TTKArcMeterWidget::drawArc(QPainter *painter)
{
    int radius = 98;
    painter->save();

    QPen pen;
    pen.setColor(m_arcColor);
    pen.setWidthF(2);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    double angleAll = 360.0 - m_startAngle - m_endAngle;
    double angleCurrent = angleAll * ((m_currentValue - m_minValue) / (m_maxValue - m_minValue));
    double angleOther = angleAll - angleCurrent;

    QRectF rect = QRectF(-radius, -radius, radius * 2, radius * 2);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);

    radius = 90;
    rect = QRectF(-radius, -radius, radius * 2, radius * 2);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);
    painter->drawArc(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    painter->restore();
}

void TTKArcMeterWidget::drawScale(QPainter *painter)
{
    int radius = 97;

    painter->save();
    painter->rotate(m_startAngle);

    int steps = (m_scaleMajor * m_scaleMinor);
    double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;
    QPen pen;
    pen.setColor(m_scaleColor);
    pen.setCapStyle(Qt::RoundCap);

    for(int i = 0; i <= steps; i++)
    {
        if(i % m_scaleMinor == 0)
        {
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 12, 0, radius);
        }
        else
        {
            pen.setWidthF(1.0);
            painter->setPen(pen);
            painter->drawLine(0, radius - 5, 0, radius);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKArcMeterWidget::drawScaleNum(QPainter *painter)
{
    int radius = 75;

    painter->save();
    painter->setPen(m_scaleNumColor);

    double startRad = (360 - m_startAngle - 90) * (M_PI / 180);
    double deltaRad = (360 - m_startAngle - m_endAngle) * (M_PI / 180) / m_scaleMajor;

    for(int i = 0; i <= m_scaleMajor; i++)
    {
        double sina = qSin(startRad - i * deltaRad);
        double cosa = qCos(startRad - i * deltaRad);
        double value = 1.0 * i * ((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        QString strValue = QString("%1").arg(value, 0, 'f', m_precision);
        double textWidth = fontMetrics().width(strValue);
        double textHeight = fontMetrics().height();
        int x = radius * cosa - textWidth / 2;
        int y = -radius * sina + textHeight / 4;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKArcMeterWidget::drawPointerCircle(QPainter *painter)
{
    int radius = 8;
    int offset = 30;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);
    painter->rotate(m_startAngle);

    double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->restore();
}

void TTKArcMeterWidget::drawPointerIndicator(QPainter *painter)
{
    int radius = 75;

    painter->save();
    painter->setOpacity(0.8);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);

    double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKArcMeterWidget::drawPointerIndicatorR(QPainter *painter)
{
    int radius = 75;

    painter->save();
    QPen pen;
    pen.setWidthF(1);
    pen.setColor(m_pointerColor);
    painter->setPen(pen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);

    double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(4);
    painter->setPen(pen);
    painter->drawLine(0, 0, 0, radius);
    painter->restore();
}

void TTKArcMeterWidget::drawPointerTriangle(QPainter *painter)
{
    int radius = 10;
    int offset = 55;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0 + offset, 5, 0 + offset, 0, radius + offset);
    painter->rotate(m_startAngle);
    double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);

    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKArcMeterWidget::drawRoundCircle(QPainter *painter)
{
    int radius = 12;
    painter->save();
    painter->setOpacity(0.5);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKArcMeterWidget::drawCenterCircle(QPainter *painter)
{
    int radius = 8;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKArcMeterWidget::drawValue(QPainter *painter)
{
    int radius = 100;

    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(30);
    painter->setFont(font);

    QRectF textRect(-radius, radius / 2, radius * 2, radius / 3);
    QString strValue = QString("%1").arg(m_currentValue, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
