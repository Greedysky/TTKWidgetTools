#include "ttkcustomringwidget.h"

#include <QPainter>

TTKCustomRingWidget::TTKCustomRingWidget(QWidget *parent)
    : QWidget(parent),
      m_backgroundColor(Qt::white),
      m_outCircleColor(Qt::red),
      m_midCircleColor(Qt::green),
      m_inCircleColor(Qt::blue)
{

}

void TTKCustomRingWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        update();
    }
}

void TTKCustomRingWidget::setOutCircleColor(const QColor &outCircleColor)
{
    if(m_outCircleColor != outCircleColor)
    {
        m_outCircleColor = outCircleColor;
        update();
    }
}

void TTKCustomRingWidget::setMidCircleColor(const QColor &midCircleColor)
{
    if(m_midCircleColor != midCircleColor)
    {
        m_midCircleColor = midCircleColor;
        update();
    }
}

void TTKCustomRingWidget::setInCircleColor(const QColor &inCircleColor)
{
    if(m_inCircleColor != inCircleColor)
    {
        m_inCircleColor = inCircleColor;
        update();
    }
}

QSize TTKCustomRingWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKCustomRingWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    const QRect rect(0, 0, width(), height());
    const int side = qMin(rect.width(), rect.height());
    const qreal scale = side / 200.0;

    drawBackground(&painter);

    painter.translate(rect.center());
    painter.scale(scale, scale);

    drawOutCircle(&painter);
    drawMidCircle(&painter);
    drawInCircle(&painter);
}

void TTKCustomRingWidget::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_backgroundColor);
    painter->drawRoundedRect(rect(), 5, 5);
    painter->restore();
}

void TTKCustomRingWidget::drawOutCircle(QPainter *painter)
{
    constexpr int radius = 90;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_outCircleColor);
    painter->drawEllipse(QPoint(0, 0), radius, radius);
    painter->restore();
}

void TTKCustomRingWidget::drawMidCircle(QPainter *painter)
{
    constexpr int radius = 50;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_midCircleColor);
    painter->drawEllipse(QPoint(0, 0), radius, radius);
    painter->restore();
}

void TTKCustomRingWidget::drawInCircle(QPainter *painter)
{
    constexpr int radius = 10;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_inCircleColor);
    painter->drawEllipse(QPoint(0, 0), radius, radius);
    painter->restore();
}
