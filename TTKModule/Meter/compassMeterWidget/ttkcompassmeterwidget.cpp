#include "ttkcompassmeterwidget.h"

#include <QTimer>
#include <QPainter>

TTKCompassMeterWidget::TTKCompassMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_value = 50;
    m_precision = 0;

    m_animation = true;
    m_animationStep = 0.5;

    m_crownColorStart = QColor(255, 255, 255);
    m_crownColorEnd = QColor(60, 60, 60);
    m_bgColorStart = QColor(50, 50, 50);
    m_bgColorEnd = QColor(20, 20, 20);
    m_darkColor = QColor(255, 170, 0);
    m_lightColor = QColor(170, 255, 0);
    m_foreground = QColor(255, 255, 255);
    m_northPointerColor = QColor(253, 107, 107);
    m_southPointerColor = QColor(0, 170, 255);
    m_centerColorStart = QColor(230, 230, 230);
    m_centerColorEnd = QColor(180, 180, 180);
    m_textColor = QColor(0, 0, 0);

    m_reverse = false;
    m_currentValue = 50;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

TTKCompassMeterWidget::~TTKCompassMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKCompassMeterWidget::setValue(double value)
{
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

void TTKCompassMeterWidget::setPrecision(int precision)
{
    if(precision <= 2 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKCompassMeterWidget:: setAnimation(bool animation)
{
    if(m_animation != animation)
    {
        m_animation = animation;
        update();
    }
}

void TTKCompassMeterWidget::setAnimationStep(double animationStep)
{
    if(m_animationStep != animationStep)
    {
        m_animationStep = animationStep;
        update();
    }
}

void TTKCompassMeterWidget::setCrownColorStart(const QColor &crownColorStart)
{
    if(m_crownColorStart != crownColorStart)
    {
        m_crownColorStart = crownColorStart;
        update();
    }
}

void TTKCompassMeterWidget::setCrownColorEnd(const QColor &crownColorEnd)
{
    if(m_crownColorEnd != crownColorEnd)
    {
        m_crownColorEnd = crownColorEnd;
        update();
    }
}

void TTKCompassMeterWidget::setBgColorStart(const QColor &bgColorStart)
{
    if(m_bgColorStart != bgColorStart)
    {
        m_bgColorStart = bgColorStart;
        update();
    }
}

void TTKCompassMeterWidget::setBgColorEnd(const QColor &bgColorEnd)
{
    if(m_bgColorEnd != bgColorEnd)
    {
        m_bgColorEnd = bgColorEnd;
        update();
    }
}

void TTKCompassMeterWidget::setDarkColor(const QColor &darkColor)
{
    if(m_darkColor != darkColor)
    {
        m_darkColor = darkColor;
        update();
    }
}

void TTKCompassMeterWidget::setLightColor(const QColor &lightColor)
{
    if(m_lightColor != lightColor)
    {
        m_lightColor = lightColor;
        update();
    }
}

void TTKCompassMeterWidget::setForeground(const QColor &foreground)
{
    if(m_foreground != foreground)
    {
        m_foreground = foreground;
        update();
    }
}

void TTKCompassMeterWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKCompassMeterWidget::setNorthPointerColor(const QColor &northPointerColor)
{
    if(m_northPointerColor != northPointerColor)
    {
        m_northPointerColor = northPointerColor;
        update();
    }
}

void TTKCompassMeterWidget::setSouthPointerColor(const QColor &southPointerColor)
{
    if(m_southPointerColor != southPointerColor)
    {
        m_southPointerColor = southPointerColor;
        update();
    }
}

void TTKCompassMeterWidget::setCenterColorStart(const QColor &centerColorStart)
{
    if(m_centerColorStart != centerColorStart)
    {
        m_centerColorStart = centerColorStart;
        update();
    }
}

void TTKCompassMeterWidget::setCenterColorEnd(const QColor &centerColorEnd)
{
    if(m_centerColorEnd != centerColorEnd)
    {
        m_centerColorEnd = centerColorEnd;
        update();
    }
}

QSize TTKCompassMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKCompassMeterWidget::updateValue()
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

void TTKCompassMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawCrownCircle(&painter);
    drawBgCircle(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);
    drawCoverOuterCircle(&painter);
    drawCoverInnerCircle(&painter);
    drawCoverCenterCircle(&painter);
    drawPointer(&painter);
    drawCenterCircle(&painter);
    drawValue(&painter);
}

void TTKCompassMeterWidget::drawCrownCircle(QPainter *painter)
{
    const int radius = 99;

    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_crownColorStart);
    lineGradient.setColorAt(1, m_crownColorEnd);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawBgCircle(QPainter *painter)
{
    const int radius = 90;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_bgColorStart);
    lineGradient.setColorAt(1, m_bgColorEnd);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 85;
    painter->save();

    const int steps = 8;
    const double angleStep = 360.0 / steps;

    QPen pen;
    pen.setColor(m_foreground);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(4);
    painter->setPen(pen);

    for(int i = 0; i <= steps; i++)
    {
        if(i % 2 != 0)
        {
            painter->drawLine(0, radius - 10, 0, radius);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKCompassMeterWidget::drawScaleNum(QPainter *painter)
{
    int radius = 88;
    painter->save();
    painter->setPen(m_foreground);

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
    painter->setFont(font);

    QRect textRect = QRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignTop | Qt::AlignHCenter, "N");
    painter->drawText(textRect, Qt::AlignBottom | Qt::AlignHCenter, "S");
    radius -= 2;

    textRect = QRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, "W");
    radius -= 2;

    textRect = QRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignRight | Qt::AlignVCenter, "E");
    painter->restore();
}

void TTKCompassMeterWidget::drawCoverOuterCircle(QPainter *painter)
{
    const int radius = 68;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_lightColor);
    lineGradient.setColorAt(1, m_darkColor);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawCoverInnerCircle(QPainter *painter)
{
    const int radius = 60;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_darkColor);
    lineGradient.setColorAt(1, m_lightColor);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawCoverCenterCircle(QPainter *painter)
{
    const int radius = 15;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setOpacity(0.8);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_lightColor);
    lineGradient.setColorAt(1, m_darkColor);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawPointer(QPainter *painter)
{
    const int radius = 75;

    painter->save();
    painter->setOpacity(0.7);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_northPointerColor);

    QPolygon pts;
    pts.setPoints(3, -10, 0, 10, 0, 0, radius);
    painter->rotate(m_currentValue + 180);
    painter->drawConvexPolygon(pts);
    painter->restore();
    painter->save();
    painter->setOpacity(0.7);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_southPointerColor);

    pts.setPoints(3, -10, 0, 10, 0, 0, radius);
    painter->rotate(m_currentValue);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKCompassMeterWidget::drawCenterCircle(QPainter *painter)
{
    const int radius = 12;
    painter->save();
    painter->setOpacity(1.0);
    painter->setPen(Qt::NoPen);

    QLinearGradient lineGradient(0, -radius, 0, radius);
    lineGradient.setColorAt(0, m_centerColorStart);
    lineGradient.setColorAt(1, m_centerColorEnd);

    painter->setBrush(lineGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCompassMeterWidget::drawValue(QPainter *painter)
{
    const int radius = 100;
    painter->save();
    painter->setPen(m_textColor);

    QFont font;
    font.setPixelSize(11);
    font.setBold(true);
    painter->setFont(font);

    QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    QString strValue = QString("%1").arg(m_value, 0, 'f', m_precision);
    painter->drawText(textRect, Qt::AlignCenter, strValue);
    painter->restore();
}
