#include "ttkroundmeterwidget.h"

#include <QTimer>
#include <QPainter>

TTKRoundMeterWidget::TTKRoundMeterWidget(QWidget *parent)
    : QWidget(parent)
{    
    m_minValue = 0;
    m_maxValue = 100;
    m_value = 0;
    m_precision = 0;

    m_angle = 40;
    m_unit = "";

    m_usedColor = QColor(100, 184, 255);
    m_freeColor = QColor(70, 70, 70);

    m_rangeTextColor = QColor(137, 137, 137);
    m_valueTextColor = QColor(52, 155, 218);

    m_valueBgColor = QColor(239, 239, 239);
    m_outBgColor = QColor(233, 233, 233);
    m_centerBgColorStart = QColor(45, 204, 112);
    m_centerBgColorEnd = QColor(51, 152, 219);

    m_currentPercent = 0;
    m_valuePercent = 0;

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));

    setFont(QFont("Arial", 7));
}

TTKRoundMeterWidget::~TTKRoundMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKRoundMeterWidget::setRange(double minValue, double maxValue)
{
    if(minValue >= maxValue)
    {
        return;
    }

    if(m_timer->isActive())
    {
        m_timer->stop();
    }

    m_currentPercent = 0;
    m_valuePercent = 100 * (m_value - m_minValue) / (m_maxValue - m_minValue);
    m_minValue = minValue;
    m_maxValue = maxValue;

    if(m_value < minValue || m_value > maxValue)
    {
        setValue(m_value);
    }
}

void TTKRoundMeterWidget::setMinValue(double minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKRoundMeterWidget::setMaxValue(double maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKRoundMeterWidget::setValue(double value)
{
    if(value < m_minValue)
    {
        m_value = m_minValue;
    }
    else if(value > m_maxValue)
    {
        m_value = m_maxValue;
    }
    else {
        m_value = value;
    }

    if(m_timer->isActive())
    {
        m_timer->stop();
    }

    m_currentPercent = 0;
    m_valuePercent = 100 * (m_value - m_minValue) / (m_maxValue - m_minValue);
    m_timer->start();
}

void TTKRoundMeterWidget::setAngle(double angle)
{
    if(m_angle != angle)
    {
        m_angle = angle;
        update();
    }
}

void TTKRoundMeterWidget::setPrecision(int precision)
{
    if(precision <= 3 && m_precision != precision)
    {
        m_precision = precision;
        update();
    }
}

void TTKRoundMeterWidget::setUnit(const QString &unit)
{
    if(m_unit != unit)
    {
        m_unit = unit;
        update();
    }
}

void TTKRoundMeterWidget::setUsedColor(const QColor &usedColor)
{
    if(m_usedColor != usedColor)
    {
        m_usedColor = usedColor;
        update();
    }
}

void TTKRoundMeterWidget::setFreeColor(const QColor &freeColor)
{
    if(m_freeColor != freeColor)
    {
        m_freeColor = freeColor;
        update();
    }
}

void TTKRoundMeterWidget::setRangeTextColor(const QColor &rangeTextColor)
{
    if(m_rangeTextColor != rangeTextColor)
    {
        m_rangeTextColor = rangeTextColor;
        update();
    }
}

void TTKRoundMeterWidget::setValueTextColor(const QColor &valueTextColor)
{
    if(m_valueTextColor != valueTextColor)
    {
        m_valueTextColor = valueTextColor;
        update();
    }
}

void TTKRoundMeterWidget::setValueBgColor(const QColor &valueBgColor)
{
    if(m_valueBgColor != valueBgColor)
    {
        m_valueBgColor = valueBgColor;
        update();
    }
}

void TTKRoundMeterWidget::setOutBgColor(const QColor &outBgColor)
{
    if(m_outBgColor != outBgColor)
    {
        m_outBgColor = outBgColor;
        update();
    }
}

void TTKRoundMeterWidget::setCenterBgColorStart(const QColor &centerBgColorStart)
{
    if(m_centerBgColorStart != centerBgColorStart)
    {
        m_centerBgColorStart = centerBgColorStart;
        update();
    }
}

void TTKRoundMeterWidget::setCenterBgColorEnd(const QColor &centerBgColorEnd)
{
    if(m_centerBgColorEnd != centerBgColorEnd)
    {
        m_centerBgColorEnd = centerBgColorEnd;
        update();
    }
}

QSize TTKRoundMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKRoundMeterWidget::updateValue()
{
    if(m_currentPercent >= m_valuePercent)
    {
        m_timer->stop();
        return;
    }

    m_currentPercent++;
    update();
}

void TTKRoundMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawDial(&painter);
    drawBgOut(&painter);
    drawBgRound(&painter);
    drawBgCenter(&painter);
    drawText(&painter);
}

void TTKRoundMeterWidget::drawDial(QPainter *painter)
{
    const int radius = 95;
    const double lineWidth = 2.5;
    painter->save();
    painter->rotate(m_angle);

    QPen pen = painter->pen();
    pen.setWidthF(lineWidth);
    pen.setCapStyle(Qt::RoundCap);

    const double rotate = (double)(360 - (m_angle * 2)) / 100;

    pen.setColor(m_usedColor);
    painter->setPen(pen);

    for(double i = 0; i < m_currentPercent; i++)
    {
        painter->drawLine(0, radius, 0, radius / 1.2);
        painter->rotate(rotate);
    }

    pen.setColor(m_freeColor);
    painter->setPen(pen);

    for(double i = m_currentPercent; i < 100; i++)
    {
        painter->drawLine(0, radius, 0, radius / 1.2);
        painter->rotate(rotate);
    }

    painter->restore();
}

void TTKRoundMeterWidget::drawBgOut(QPainter *painter)
{
    const int radius = 70;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_outBgColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRoundMeterWidget::drawBgRound(QPainter *painter)
{
    const int radius = 50;
    painter->save();

    QConicalGradient conicalGradient(radius, radius, 90);
    conicalGradient.setColorAt(0, m_centerBgColorStart);
    conicalGradient.setColorAt(1.0, m_centerBgColorEnd);

    painter->setPen(Qt::NoPen);
    painter->setBrush(conicalGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRoundMeterWidget::drawBgCenter(QPainter *painter)
{
    const int radius = 30;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_valueBgColor);

    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKRoundMeterWidget::drawText(QPainter *painter)
{
    const int radius = 100;
    painter->save();

    double currentValue = m_currentPercent * ((m_maxValue - m_minValue) / 100) + m_minValue;

    if(currentValue > m_value)
    {
        currentValue = m_value;
    }

    const QString &strValue = QString("%1%2").arg(QString::number(currentValue, 'f', m_precision)).arg(m_unit);
    const QString &strMinValue = QString("%1%2").arg(m_minValue).arg(m_unit);
    const QString &strMaxValue = QString("%1%2").arg(m_maxValue).arg(m_unit);

    painter->setFont(QFont("Arial", 13));
    painter->setPen(QPen(m_valueTextColor));

    const QRectF textRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(textRect, Qt::AlignCenter, strValue);

    painter->setFont(QFont("Arial", 8));
    painter->setPen(QPen(m_rangeTextColor));

    QSizeF size = painter->fontMetrics().size(Qt::TextSingleLine, strMinValue);
    painter->drawText(-radius / 2 - size.width() / 2 + 8, 80, strMinValue);
    size = painter->fontMetrics().size(Qt::TextSingleLine, strMaxValue);
    painter->drawText(radius / 2 - size.width() / 2 - 8, 80, strMaxValue);

    painter->restore();
}
