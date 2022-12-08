#include "ttkdonutwaitprogresswidget.h"

#include <QTimer>
#include <QPainter>

TTKDonutWaitProgressWidget::TTKDonutWaitProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_foregroundColor(Qt::yellow),
      m_backgroundColor(Qt::white),
      m_clockWise(true),
      m_rotateDelta(36),
      m_rotateAngle(0)
{
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(100);
}

void TTKDonutWaitProgressWidget::setForegroundColor(const QColor &foregroundColor)
{
    if(foregroundColor != m_foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        update();
    }
}

void TTKDonutWaitProgressWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if(backgroundColor != m_backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        update();
    }
}

void TTKDonutWaitProgressWidget::setClockWise(bool clockwise)
{
    if(clockwise != m_clockWise)
    {
        m_clockWise = clockwise;
        update();
    }
}

void TTKDonutWaitProgressWidget::setRotateDelta(int delta)
{
    if(delta != m_rotateDelta)
    {
        m_rotateDelta = delta;
        update();
    }
}

QSize TTKDonutWaitProgressWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKDonutWaitProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    const int side = qMin(width(), height());
    painter.scale(side / 100.0, side / 100.0);

    m_rotateAngle += m_clockWise ? m_rotateDelta : -m_rotateDelta;
    painter.rotate(m_rotateAngle);
    drawDonutWait(&painter);
    m_rotateAngle %= 360;
}

void TTKDonutWaitProgressWidget::drawDonutWait(QPainter *painter)
{
    constexpr int outRadious = 50;
    constexpr int inRadious = 30;
    const QRectF outRect(-outRadious, -outRadious, 2 * outRadious, 2 * outRadious);
    const QRectF inRect(-inRadious, -inRadious, 2 * inRadious, 2 * inRadious);

    painter->save();
    painter->setPen(Qt::NoPen);

    painter->setBrush(QBrush(m_backgroundColor));
    painter->drawEllipse(outRect);
    painter->setBrush(QBrush(m_foregroundColor));
    painter->drawPie(outRect, 0, 60 * 16);

    painter->setBrush(palette().window().color());
    painter->drawEllipse(inRect);

    painter->rotate(-m_rotateAngle);

    QFont font = painter->font();
    font.setBold(true);
    painter->setFont(font);
    painter->setPen(m_foregroundColor);
    painter->drawText(inRect, Qt::AlignCenter, QString::number(qAbs(1.0 * m_rotateAngle / 360 * 100), 'f', 0) + "%");

    painter->restore();
}
