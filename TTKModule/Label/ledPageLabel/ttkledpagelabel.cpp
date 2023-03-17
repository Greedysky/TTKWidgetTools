#include "ttkledpagelabel.h"

#include <QPainter>
#include <QPainterPath>

TTKLedPageLabel::TTKLedPageLabel(QWidget *parent)
    : QWidget(parent)
{
    setScale(0.6f);
    setBackgroundColor(QColor(85, 85, 85));
    setForegroundColor(QColor(255, 255, 255));
    setLineColor(QColor(60, 60, 60));
    setText("2");
    setFontSize(40);
}

void TTKLedPageLabel::setForegroundColor(const QColor &color)
{
    m_foregroundColor = color;
    update();
}

void TTKLedPageLabel::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
    update();
}

void TTKLedPageLabel::setLineColor(const QColor &color)
{
    m_lineColor = color;
    update();
}

void TTKLedPageLabel::setScale(float scale)
{
    m_scale = scale;
    update();
}

void TTKLedPageLabel::setText(const QString &text)
{
    m_text = text;
    update();
}

void TTKLedPageLabel::setFontSize(int size)
{
    m_fontSize = size;
    update();
}

QSize TTKLedPageLabel::sizeHint() const
{
    return QSize(100 * m_scale, 100);
}

void TTKLedPageLabel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    if((height() - 2) * m_scale > (width() - 2))
    {
        m_width = width() - 2;
        m_height = m_width / m_scale;
    }
    else
    {
        m_height = height() - 2;
        m_width = m_height * m_scale;
    }
    update();
}

void TTKLedPageLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(&painter);
    drawText(&painter);
    drawLine(&painter);
}

void TTKLedPageLabel::drawBackground(QPainter *painter)
{
    QPen pen(m_backgroundColor, 1);
    painter->setPen(pen);

    QPainterPath path;
    path.addRoundedRect(1, 1, m_width,  m_height, 10, 10);
    painter->fillPath(path, m_backgroundColor);
    painter->drawPath(path);
}

void TTKLedPageLabel::drawText(QPainter *painter)
{
    QPen pen(m_foregroundColor);
    painter->setPen(pen);
    setFont(QFont("Roboto", m_fontSize, QFont::Bold));
    painter->drawText(0, 0, m_width, m_height, Qt::AlignCenter, m_text);
}

void TTKLedPageLabel::drawLine(QPainter *painter)
{
    QPen pen(m_lineColor, 3);
    painter->setPen(pen);
    painter->drawLine(1, m_height / 2, m_width + 1, m_height / 2);
}
