#include "ttkroundprogresswidget.h"

#include <qmath.h>
#include <QPainter>
#include <QPropertyAnimation>

TTKRoundProgressWidget::TTKRoundProgressWidget(QWidget *parent)
    : QWidget(parent)
{
    setdefault(90,true);
    setOutterBarWidth(18);
    setInnerBarWidth(16);
    setRange(0, 100);
    setValue(75);
    setOutterColor(QColor(233, 248, 248));
    setInnerColor(QColor(49, 177, 190), QColor(133, 243, 244));
    setDefaultTextColor(QColor(49, 177, 190));
    setPrecision(0);
    setInnerDefaultTextStyle(TTKRoundProgressWidget::Percent);

    m_min = 0;
    m_max = 100;
    m_value = 0;
    m_precision = 0;
    m_controlFlags = Null;
}

void TTKRoundProgressWidget::setdefault(int startAngle, bool clockWise)
{
    m_startAngle = startAngle;
    m_clockWise = clockWise;
    update();
}

void TTKRoundProgressWidget::setOutterBarWidth(float width)
{
    m_outterBarWidth = width;
    update();
}

void TTKRoundProgressWidget::setInnerBarWidth(float width)
{
    m_innerBarWidth = width;
    update();
}

void TTKRoundProgressWidget::setRange(float min, float max)
{
    if(max < min)
    {
        max = 100;
        min = 0;
    }

    m_max = max;
    m_min = min;
    update();
}

void TTKRoundProgressWidget::setText(float value)
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "m_value");
    animation->setDuration(500);
    animation->setStartValue(m_value);
    animation->setEndValue(value);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->start();
    update();
}

void TTKRoundProgressWidget::setValue(float value)
{
    m_value = value;
    update();
}

void TTKRoundProgressWidget::setOutterColor(const QColor &outterColor)
{
    m_outterColor = outterColor;
    update();
}

void TTKRoundProgressWidget::setInnerColor(const QColor &startColor, const QColor &endColor)
{
    m_startColor = startColor;
    m_endColor = endColor;
    update();
}

void TTKRoundProgressWidget::setInnerColor(const QColor &startColor)
{
    m_startColor = startColor;
    update();
}

void TTKRoundProgressWidget::setDefaultTextColor(const QColor &textColor)
{
    m_textColor=textColor;
    update();
}

void TTKRoundProgressWidget::setControlFlags(int flags)
{
    m_controlFlags |= flags;
    update();
}

void TTKRoundProgressWidget::setPrecision(int precision)
{
    m_precision = precision;
    update();
}

QSize TTKRoundProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKRoundProgressWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    if(m_outterBarWidth > m_innerBarWidth)
    {
        setMinimumSize(m_outterBarWidth * 8, m_outterBarWidth * 8);
    }
    else
    {
        setMinimumSize(m_innerBarWidth * 8, m_innerBarWidth * 8);
    }

    const int minWidth = qMin(width(), height());
    const float barWidth = qMax(m_outterBarWidth, m_innerBarWidth);
    m_squareWidth = minWidth - barWidth - 2;
    m_squareStart = barWidth / 2 + 1;
    m_dotX = m_squareStart + m_squareWidth / 2;
    m_dotY = m_squareStart;
}

void TTKRoundProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    paintOutterBar(painter);
    paintInnerBar(painter);
    paintDot(painter);
    paintText(painter);
}

void TTKRoundProgressWidget::paintOutterBar(QPainter &painter)
{
    if(!(m_controlFlags & OutterCirle))
    {
        return;
    }

    QPen pen;
    pen.setWidth(m_outterBarWidth);
    pen.setColor(m_outterColor);
    painter.setPen(pen);

    painter.drawEllipse(QRectF(m_squareStart, m_squareStart, m_squareWidth, m_squareWidth));
}

void TTKRoundProgressWidget::paintInnerBar(QPainter& painter)
{
    QPen pen;
    if(!(m_controlFlags & LinearColor))
    {
        pen.setColor(m_startColor);
    }
    else
    {
        QLinearGradient gradient(0, 0, 0, m_squareWidth);
        gradient.setColorAt(0, m_startColor);
        gradient.setColorAt(1, m_endColor);

        QBrush brush(gradient);
        pen.setBrush(brush);
    }

    pen.setWidth(m_innerBarWidth);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    const int startAngle = m_startAngle * 16;
    const int spanAngle = (m_value - m_min) / (m_max-m_min) * 360 * 16 * (m_clockWise ? - 1 : 1);
    painter.drawArc(QRectF(m_squareStart, m_squareStart, m_squareWidth, m_squareWidth), startAngle, spanAngle);
}

void TTKRoundProgressWidget::paintDot(QPainter& painter)
{
    if(!(m_controlFlags & DecorateDot))
    {
        return;
    }

    if(m_innerBarWidth < 3)
    {
        return;
    }

    painter.setPen(QColor(255, 255, 255));
    painter.setBrush(QColor(255, 255, 255));

    painter.drawEllipse(m_dotX - m_innerBarWidth / 6, m_dotY - m_innerBarWidth / 6, m_innerBarWidth / 3, m_innerBarWidth / 3);
}

void TTKRoundProgressWidget::paintText(QPainter& painter)
{
    if(!(m_controlFlags & DefaultText))
    {
        return;
    }

    painter.setPen(m_textColor);
    painter.setFont(QFont("Roboto", 22, 75));

    switch(m_innerDefaultTextStyle)
    {
        case Value:
            painter.drawText(m_squareStart, m_squareStart, m_squareWidth, m_squareWidth, Qt::AlignCenter, QString::number(m_value, 'f', m_precision));
            break;
        case ValueAndMax:
            painter.drawText(m_squareStart, m_squareStart, m_squareWidth, m_squareWidth, Qt::AlignCenter, QString::number(m_value, 'f', m_precision) + "/" + QString::number(m_max, 'f', m_precision));
            break;
        case Percent:
            painter.drawText(m_squareStart, m_squareStart, m_squareWidth, m_squareWidth, Qt::AlignCenter, QString::number(m_value / m_max * 100, 'f', m_precision) + "%");
            break;
        default:
            break;
    }
}


