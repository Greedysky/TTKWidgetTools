#include "ttkwaveprogresswidget.h"

#include <QTimer>
#include <qmath.h>
#include <QPainter>

TTKWaveProgressWidget::TTKWaveProgressWidget(QWidget *parent)
    : QWidget(parent)
{
    m_value = 45;
    m_minValue = 0;
    m_maxValue = 100;
    m_waterDensity = 2;
    m_waterHeight = 0.02;
    m_offset = 0;
    m_borderWidth = 2;
    m_bgColor = QColor(0, 100, 255);

    m_percentStyle = PercentStyleCircle;

    m_timer = new QTimer(this);
    connect(m_timer,  SIGNAL(timeout()), SLOT(timeout()));
    m_timer->start(100);
}

TTKWaveProgressWidget::~TTKWaveProgressWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKWaveProgressWidget::setRange(int minValue, int maxValue)
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

void TTKWaveProgressWidget::setMinValue(int minValue)
{
    setRange(minValue, m_maxValue);
}

void TTKWaveProgressWidget::setMaxValue(int maxValue)
{
    setRange(m_minValue, maxValue);
}

void TTKWaveProgressWidget::setValue(int value)
{
    if(m_value != value)
    {
        m_value = value;
        update();
    }
}

void TTKWaveProgressWidget::setWaterDensity(int waterDensity)
{
    if(m_waterDensity != waterDensity)
    {
        m_waterDensity = waterDensity;
        update();
    }
}

void TTKWaveProgressWidget::setWaterHeight(double waterHeight)
{
    if(m_waterHeight != waterHeight)
    {
        m_waterHeight = waterHeight;
        update();
    }
}

void TTKWaveProgressWidget::setOffset(int offset)
{
    if(m_offset != offset)
    {
        m_offset = offset;
        update();
    }
}

void TTKWaveProgressWidget::setBorderWidth(double borderWidth)
{
    if(m_borderWidth != borderWidth)
    {
        m_borderWidth = borderWidth;
        update();
    }
}

void TTKWaveProgressWidget::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

void TTKWaveProgressWidget::setPointerStyle(const PercentStyle &percentStyle)
{
    if(m_percentStyle != percentStyle)
    {
        m_percentStyle = percentStyle;
        update();
    }
}

QSize TTKWaveProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKWaveProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawValue(&painter);

    painter.setPen(QColor(255,255,255));
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(40);
    font.setBold(true);
    painter.setFont(font);

    const int textWidth = width() / 2 - 45;
    int textHeight = height() / 2;

    if(m_value < 50)
    {
        textHeight = textHeight + 40;
    }

    painter.drawText(textWidth, textHeight, QString::number(m_value) + "%");
}

void TTKWaveProgressWidget::drawValue(QPainter *painter)
{
    const int h = height();
    const int w = width();

    int side = qMin(h, w);
    int startX = m_borderWidth;
    int startY = m_borderWidth;
    int endX = w - m_borderWidth;
    int endY = h - m_borderWidth;

    if(m_percentStyle == PercentStyleCircle)
    {
        side = side - m_borderWidth * 2;
        startX = (w - side) / 2;
        startY = (h - side) / 2;
        endX = (w + side) / 2;
        endY = (h + side) / 2;
    }

    const double percent = 1 - (double)(m_value - m_minValue) / (m_maxValue - m_minValue);
    double W = m_waterDensity * M_PI / endX;
    double A = endY * m_waterHeight;
    double k = endY * percent;

    if(m_percentStyle == PercentStyleCircle)
    {
        k = (side * percent) + startY;
    }

    QPainterPath waterPath1;
    QPainterPath waterPath2;

    waterPath1.moveTo(startX,endY);
    waterPath2.moveTo(startX,endY);

    m_offset += 0.6;
    if(m_offset > (endX / 2))
    {
        m_offset = 0;
    }

    for(int x = startX; x <= endX; x++)
    {
        double waterY1 = (double)(A * sin(W * x + m_offset)) + k;
        double waterY2 = (double)(A * sin(W * x + m_offset + (endX / 2 * W))) + k;

        if(m_value == m_minValue)
        {
            waterY1 = endY;
            waterY2 = endY;
        }

        if(m_value == m_maxValue)
        {
            waterY1 = startY;
            waterY2 = startY;
        }

        waterPath1.lineTo(x,waterY1);
        waterPath2.lineTo(x,waterY2);
    }

    waterPath1.lineTo(endX,endY);
    waterPath2.lineTo(endX,endY);

    QPainterPath bigPath;
    if(m_percentStyle == PercentStyleRect)
    {
        bigPath.addRect(startX,startY,endX,endY);
    }
    else if(m_percentStyle == PercentStyleCircle)
    {
        bigPath.addEllipse(startX,startY,side,side);
    }
    else if(m_percentStyle == PercentStyleEllipse)
    {
        bigPath.addEllipse(startX, startY, w - m_borderWidth * 2, h - m_borderWidth * 2);
    }

    QPainterPath path;
    QColor waterColor1 = m_bgColor;
    waterColor1.setAlpha(100);
    QColor waterColor2 = m_bgColor;
    waterColor2.setAlpha(200);

    painter->save();
    painter->setPen(Qt::NoPen);

    path = bigPath.intersected(waterPath1);
    painter->setBrush(waterColor1);
    painter->drawPath(path);

    path = bigPath.intersected(waterPath2);
    painter->setBrush(waterColor2);
    painter->drawPath(path);

    painter->restore();
}

void TTKWaveProgressWidget::timeout()
{
    m_offset += 0.4;
    update();
}
