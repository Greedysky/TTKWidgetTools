#include "ttklightpointlabel.h"

#include <QTimer>
#include <QPainter>

TTKLightPointLabel::TTKLightPointLabel(QWidget *parent)
    : QWidget(parent),
      m_step(10),
      m_interval(100),
      m_backgroundColor(255, 179, 133),
      m_offset(0),
      m_add(true)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    m_timer->start(100);
}

TTKLightPointLabel::~TTKLightPointLabel()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKLightPointLabel::setStep(int step)
{
    if(m_step != step)
    {
        m_step = step;
        update();
    }
}

void TTKLightPointLabel::setInterval(int interval)
{
    if(m_interval != interval)
    {
        m_interval = interval;
        m_timer->setInterval(interval);
        update();
    }
}

void TTKLightPointLabel::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        update();
    }
}

QSize TTKLightPointLabel::sizeHint() const
{
    return QSize(200, 200);
}


void TTKLightPointLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBackground(&painter);
}

void TTKLightPointLabel::drawBackground(QPainter *painter)
{
    int radius = 99;
    painter->save();

    QRadialGradient g(QPoint(0, 0), radius);
    (m_offset < 70 && m_add) ? (m_offset += m_step) : (m_add = false);
    (m_offset > 0 && !m_add) ? (m_offset -= m_step) : (m_add = true);

    m_backgroundColor.setAlpha(255);
    g.setColorAt(0.1, m_backgroundColor);
    m_backgroundColor.setAlpha(100 + m_offset);
    g.setColorAt(0.3, m_backgroundColor);
    m_backgroundColor.setAlpha(50 + m_offset);
    g.setColorAt(0.6, m_backgroundColor);
    m_backgroundColor.setAlpha(0);
    g.setColorAt(1.0, m_backgroundColor);

    painter->setPen(Qt::NoPen);
    painter->setBrush(g);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}
