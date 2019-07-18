#include "ttkantlinelabel.h"

#include <QTimer>
#include <QPainter>

TTKAntLineLabel::TTKAntLineLabel(QWidget *parent)
    : QWidget(parent)
{
    m_lineLen = 3;
    m_lineWidth = 6;
    m_lineStep = 1;
    m_lineSpeed = 500;
    m_lineColor = QColor(60, 179, 133);
    m_lineStyle = LineStyleRect;

    m_dashes = m_lineLen;
    m_spaces = m_lineLen;
    m_dashPattern.clear();

    for(int i = 0; i < 20; ++i)
    {
        m_dashPattern << m_lineLen;
    }

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    m_timer->start(m_lineSpeed);
}

TTKAntLineLabel::~TTKAntLineLabel()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKAntLineLabel::setLineLen(int lineLen)
{
    if(m_lineLen != lineLen)
    {
        m_lineLen = lineLen;
        m_dashes = lineLen;
        m_spaces = lineLen;
        m_dashPattern.clear();

        for(int i = 0; i < 20; ++i)
        {
            m_dashPattern << lineLen;
        }
        update();
    }
}

void TTKAntLineLabel::setLineWidth(int lineWidth)
{
    if(m_lineWidth != lineWidth)
    {
        m_lineWidth = lineWidth;
        update();
    }
}

void TTKAntLineLabel::setLineStep(int lineStep)
{
    if(m_lineStep != lineStep)
    {
        m_lineStep = lineStep;
        update();
    }
}

void TTKAntLineLabel::setLineSpeed(int lineSpeed)
{
    if(m_lineSpeed != lineSpeed)
    {
        m_lineSpeed = lineSpeed;
        m_timer->start(m_lineSpeed);
    }
}

void TTKAntLineLabel::setLineColor(const QColor &lineColor)
{
    if(m_lineColor != lineColor)
    {
        m_lineColor = lineColor;
        update();
    }
}

void TTKAntLineLabel::setLineStyle(const TTKAntLineLabel::LineStyle &lineStyle)
{
    if(m_lineStyle != lineStyle)
    {
        m_lineStyle = lineStyle;
        update();
    }
}

QSize TTKAntLineLabel::sizeHint() const
{
    return QSize(180, 180);
}

void TTKAntLineLabel::updateValue()
{
    if(m_dashes == m_lineLen && m_spaces == m_lineLen)
    {
        m_dashes = 0;
        m_spaces = 0;
    }

    if(m_dashes == 0 && m_spaces < m_lineLen)
    {
        m_spaces = m_spaces + m_lineStep;
    }
    else if(m_spaces == m_lineLen && m_dashes < m_lineLen)
    {
        m_dashes = m_dashes + m_lineStep;
    }

    m_dashPattern[0] = m_dashes;
    m_dashPattern[1] = m_spaces;
    update();
}

void TTKAntLineLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QPen pen;
    pen.setWidth(m_lineWidth);
    pen.setColor(m_lineColor);
    pen.setDashPattern(m_dashPattern);
    painter.setPen(pen);

    if(m_lineStyle == LineStyleRect)
    {
        painter.drawRect(0, 0, w, h);
    }
    else if(m_lineStyle == LineStyleRoundedRect)
    {
        painter.drawRoundedRect(0, 0, w, h, 5, 5);
    }
    else if(m_lineStyle == LineStyleEllipse)
    {
        painter.drawEllipse(0, 0, w, h);
    }
    else if(m_lineStyle == LineStyleCircle)
    {
        painter.drawEllipse(w / 2 - side / 2, 0, side, side);
    }
}
