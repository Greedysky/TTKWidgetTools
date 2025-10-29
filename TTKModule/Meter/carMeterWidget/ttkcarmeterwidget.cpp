#include "ttkcarmeterwidget.h"

#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <qmath.h>

TTKCarMeterWidget::TTKCarMeterWidget(QWidget *parent)
    : QWidget(parent),
      m_minValue(0),
      m_maxValue(100),
      m_value(50),
      m_precision(0),
      m_scaleMajor(10),
      m_scaleMinor(10),
      m_startAngle(40),
      m_endAngle(40),
      m_animation(true),
      m_animationStep(0.5),
      m_outerCircleColor(60, 60, 60),
      m_innerCircleColor(80, 80, 80),
      m_pieColorStart(253, 107, 107),
      m_pieColorMid (217, 217, 0),
      m_pieColorEnd (24, 188, 154),
      m_coverCircleColor(100, 100, 100),
      m_scaleColor(255, 255, 255),
      m_pointerColor(253, 107, 107),
      m_centerCircleColor(255, 255, 255),
      m_textColor(0, 0, 0),
      m_showOverlay(true),
      m_overlayColor(255, 255, 255),
      m_pieStyle(PieStyle::Three),
      m_pointerStyle(PointerStyle::Indicator),
      m_reverse(false),
      m_currentValue(50)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10 * TTK_DN_MS);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKCarMeterWidget::~TTKCarMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKCarMeterWidget::setRange(double minValue, double maxValue)
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

void TTKCarMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKCarMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKCarMeterWidget::setValue(double value)
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

void TTKCarMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKCarMeterWidget::setScaleMajor(int scaleMajor)
{
    if(m_scaleMajor != scaleMajor)
    {
        m_scaleMajor = scaleMajor;
        update();
    }
}

void TTKCarMeterWidget::setScaleMinor(int scaleMinor)
{
    if(m_scaleMinor != scaleMinor)
    {
        m_scaleMinor = scaleMinor;
        update();
    }
}

void TTKCarMeterWidget::setStartAngle(int startAngle)
{
    if(m_startAngle != startAngle)
    {
        m_startAngle = startAngle;
        update();
    }
}

void TTKCarMeterWidget::setEndAngle(int endAngle)
{
    if(m_endAngle != endAngle)
    {
        m_endAngle = endAngle;
        update();
    }
}

void TTKCarMeterWidget::setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKCarMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKCarMeterWidget::setOuterCircleColor(const QColor &outerCircleColor)
{
    if(m_outerCircleColor != outerCircleColor)
    {
        m_outerCircleColor = outerCircleColor;
        update();
    }
}

void TTKCarMeterWidget::setInnerCircleColor(const QColor &innerCircleColor)
{
    if(m_innerCircleColor != innerCircleColor)
    {
        m_innerCircleColor = innerCircleColor;
        update();
    }
}

void TTKCarMeterWidget::setPieColorStart(const QColor &pieColorStart)
{
    if(m_pieColorStart != pieColorStart)
    {
        m_pieColorStart = pieColorStart;
        update();
    }
}

void TTKCarMeterWidget::setPieColorMid(const QColor &pieColorMid)
{
    if(m_pieColorMid != pieColorMid)
    {
        m_pieColorMid = pieColorMid;
        update();
    }
}

void TTKCarMeterWidget::setPieColorEnd(const QColor &pieColorEnd)
{
    if(m_pieColorEnd != pieColorEnd)
    {
        m_pieColorEnd = pieColorEnd;
        update();
    }
}

void TTKCarMeterWidget::setCoverCircleColor(const QColor &coverCircleColor)
{
    if(m_coverCircleColor != coverCircleColor)
    {
        m_coverCircleColor = coverCircleColor;
        update();
    }
}

void TTKCarMeterWidget::setScaleColor(const QColor &scaleColor)
{
    if(m_scaleColor != scaleColor)
    {
        m_scaleColor = scaleColor;
        update();
    }
}

void TTKCarMeterWidget::setPointerColor(const QColor &pointerColor)
{
    if(m_pointerColor != pointerColor)
    {
        m_pointerColor = pointerColor;
        update();
    }
}

void TTKCarMeterWidget::setCenterCircleColor(const QColor &centerCircleColor)
{
    if(m_centerCircleColor != centerCircleColor)
    {
        m_centerCircleColor = centerCircleColor;
        update();
    }
}

void TTKCarMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKCarMeterWidget::setShowOverlay(bool showOverlay)
{
    if(m_showOverlay != showOverlay)
    {
        m_showOverlay = showOverlay;
        update();
    }
}

void TTKCarMeterWidget::setOverlayColor(const QColor &overlayColor)
{
    if(m_overlayColor != overlayColor)
    {
        m_overlayColor = overlayColor;
        update();
    }
}

void TTKCarMeterWidget::setPieStyle(const PieStyle &pieStyle)
{
    if(m_pieStyle != pieStyle)
    {
        m_pieStyle = pieStyle;
        update();
    }
}

void TTKCarMeterWidget::setPointerStyle(const PointerStyle &pointerStyle)
{
    if(m_pointerStyle != pointerStyle)
    {
        m_pointerStyle = pointerStyle;
        update();
    }
}

QSize TTKCarMeterWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKCarMeterWidget::updateValue()
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

void TTKCarMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = std::min(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawOuterCircle(&painter);
    drawInnerCircle(&painter);
    drawColorPie(&painter);
    drawCoverCircle(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);

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

    drawRoundCircle(&painter);
    drawCenterCircle(&painter);
    drawValue(&painter);
    drawOverlay(&painter);
}

void TTKCarMeterWidget::drawOuterCircle(QPainter *painter)
{
    constexpr int radius = 99;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_outerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawInnerCircle(QPainter *painter)
{
    constexpr int radius = 90;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_innerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawColorPie(QPainter *painter)
{
    constexpr int radius = 60;

    painter->save();
    painter->setPen(Qt::NoPen);
    QRectF rect(-radius, -radius, radius * 2, radius * 2);

    if(m_pieStyle == PieStyle::Three)
    {
        const double angleAll = 360.0 - m_startAngle - m_endAngle;
        const double angleStart = angleAll * 0.7;
        const double angleMid = angleAll * 0.15;
        const double angleEnd = angleAll * 0.15;
        constexpr int offset = 3;

        painter->setBrush(m_pieColorStart);
        painter->drawPie(rect, (270 - m_startAngle - angleStart) * 16, angleStart * 16);

        painter->setBrush(m_pieColorMid);
        painter->drawPie(rect, (270 - m_startAngle - angleStart - angleMid) * 16 + offset, angleMid * 16);

        painter->setBrush(m_pieColorEnd);
        painter->drawPie(rect, (270 - m_startAngle - angleStart - angleMid - angleEnd) * 16 + offset * 2, angleEnd * 16);
    }
    else if(m_pieStyle == PieStyle::Current)
    {
        const double angleAll = 360.0 - m_startAngle - m_endAngle;
        const double angleCurrent = angleAll * ((m_currentValue - m_minValue) / (m_maxValue - m_minValue));
        const double angleOther = angleAll - angleCurrent;

        painter->setBrush(m_pieColorStart);
        painter->drawPie(rect, (270 - m_startAngle - angleCurrent) * 16, angleCurrent * 16);

        painter->setBrush(m_pieColorEnd);
        painter->drawPie(rect, (270 - m_startAngle - angleCurrent - angleOther) * 16, angleOther * 16);
    }
    painter->restore();
}

void TTKCarMeterWidget::drawCoverCircle(QPainter *painter)
{
    constexpr int radius = 50;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_coverCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawScale(QPainter *painter)
{
    constexpr int radius = 72;

    painter->save();
    painter->rotate(m_startAngle);

    const int steps = (m_scaleMajor * m_scaleMinor);
    const double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    QPen pen;
    pen.setColor(m_scaleColor);
    pen.setCapStyle(Qt::RoundCap);

    for(int i = 0; i <= steps; ++i)
    {
        if(i % m_scaleMinor == 0)
        {
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 10, 0, radius);
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

void TTKCarMeterWidget::drawScaleNum(QPainter *painter)
{
    constexpr int radius = 82;

    painter->save();
    painter->setPen(m_scaleColor);

    const double startRad = (360 - m_startAngle - 90) * (M_PI / 180);
    const double deltaRad = (360 - m_startAngle - m_endAngle) * (M_PI / 180) / m_scaleMajor;

    for(int i = 0; i <= m_scaleMajor; ++i)
    {
        const double sina = std::sin(startRad - i * deltaRad);
        const double cosa = std::cos(startRad - i * deltaRad);
        const double value = 1.0 * i * ((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        const QString &strValue = QString("%1").arg(value, 0, 'f', m_precision);
        const int textWidth = QtFontWidth(fontMetrics(), strValue);
        const int textHeight = fontMetrics().height();
        const int x = radius * cosa - textWidth / 2.0;
        const int y = -radius * sina + textHeight / 4.0;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKCarMeterWidget::drawPointerCircle(QPainter *painter)
{
    constexpr int radius = 6;
    constexpr int offset = 30;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawEllipse(-radius, radius + offset, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawPointerIndicator(QPainter *painter)
{
    constexpr int radius = 75;

    painter->save();
    painter->setOpacity(0.8);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKCarMeterWidget::drawPointerIndicatorR(QPainter *painter)
{
    constexpr int radius = 75;

    painter->save();
    painter->setOpacity(1.0);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_pointerColor);

    painter->setPen(pen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0, 5, 0, 0, radius);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);

    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(4);
    painter->setPen(pen);
    painter->drawLine(0, 0, 0, radius);
    painter->restore();
}

void TTKCarMeterWidget::drawPointerTriangle(QPainter *painter)
{
    constexpr int radius = 10;
    constexpr int offset = 38;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);

    QPolygon pts;
    pts.setPoints(3, -5, 0 + offset, 5, 0 + offset, 0, radius + offset);
    painter->rotate(m_startAngle);

    const double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue) * (m_currentValue - m_minValue);
    painter->rotate(degRotate);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKCarMeterWidget::drawRoundCircle(QPainter *painter)
{
    constexpr int radius = 18;

    painter->save();
    painter->setOpacity(0.8);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_pointerColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawCenterCircle(QPainter *painter)
{
    constexpr int radius = 15;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_centerCircleColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCarMeterWidget::drawValue(QPainter *painter)
{
    constexpr int radius = 100;

    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(18);
    painter->setFont(font);

    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(m_currentValue, 0, 'f', m_precision));
    painter->restore();
}

void TTKCarMeterWidget::drawOverlay(QPainter *painter)
{
    if(!m_showOverlay)
    {
        return;
    }

    int radius = 90;
    painter->save();
    painter->setPen(Qt::NoPen);

    QPainterPath smallCircle;
    QPainterPath bigCircle;

    radius -= 1;
    smallCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);
    radius *= 2;
    bigCircle.addEllipse(-radius, -radius + 140, radius * 2, radius * 2);

    const QPainterPath &highlight = smallCircle - bigCircle;
    QLinearGradient linearGradient(0, -radius / 2, 0, 0);
    m_overlayColor.setAlpha(100);
    linearGradient.setColorAt(0.0, m_overlayColor);
    m_overlayColor.setAlpha(30);
    linearGradient.setColorAt(1.0, m_overlayColor);
    painter->setBrush(linearGradient);
    painter->rotate(-20);
    painter->drawPath(highlight);
    painter->restore();
}
