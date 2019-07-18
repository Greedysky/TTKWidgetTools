#include "ttkloadingprogresswidget.h"

#include <qmath.h>
#include <QPainter>

TTKLoadingProgressWidget::TTKLoadingProgressWidget(QWidget *parent)
    : QWidget(parent)
{
    setDotColor(QColor(49, 177, 190));
    setDotCount(20);
    setMaxDiameter(30);
    setMinDiameter(2);

    m_interval = 50;
    m_index = 0;

    connect(&m_timer, SIGNAL(timeout()), SLOT(update()));
}

void TTKLoadingProgressWidget::setDotCount(int count)
{
    m_count = count;
    update();
}

void TTKLoadingProgressWidget::setDotColor(const QColor &color)
{
    m_dotColor = color;
    update();
}

void TTKLoadingProgressWidget::setMaxDiameter(float max)
{
    m_maxDiameter = max;
    update();
}

void TTKLoadingProgressWidget::setMinDiameter(float min)
{
    m_minDiameter = min;
    update();
}

void TTKLoadingProgressWidget::start()
{
    m_timer.setInterval(m_interval);
    m_timer.start();
}

void TTKLoadingProgressWidget::stop()
{
    m_timer.stop();
}

QSize TTKLoadingProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKLoadingProgressWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    const float half = qMin(width(), height()) / 2;
    const float centerDistance = half - m_maxDiameter / 2 - 1;

    const float gap = (m_maxDiameter - m_minDiameter) / (m_count - 1) / 2;
    const float angleGap = (float)360 / m_count;

    m_dots.clear();
    m_ranges.clear();

    for(int i=0; i<m_count; i++)
    {
        m_ranges << m_maxDiameter / 2 - i * gap;
        const float radian = -angleGap * i * M_PI / 180.0;
        m_dots.append({half + centerDistance * qCos(radian), half - centerDistance * qSin(radian)});
    }
}

void TTKLoadingProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(m_dotColor);
    painter.setBrush(m_dotColor);

    paintDot(painter);
}

void TTKLoadingProgressWidget::paintDot(QPainter &painter)
{
    for(int i=0; i<m_count; i++)
    {
        painter.setPen(m_dotColor);
        const float radian = m_ranges.at((m_index + m_count - i) % m_count);
        const Position &position = m_dots.at(i);
        painter.drawEllipse(QPointF(position.x, position.y), radian, radian);
    }
    m_index++;
}
