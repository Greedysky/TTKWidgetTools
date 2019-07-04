#include "ttkledpagelabel.h"

#include <QPainter>

TTKLedPageLabel::TTKLedPageLabel(QWidget *parent)
    : QWidget(parent)
{
    setScale(0.6);
    setBackColor(QColor(85, 85, 85));
    setFrontColor(QColor(255, 255, 255));
    setLineColor(QColor(60, 60, 60));
    setText("2");
    setFontSize(40);
}

void TTKLedPageLabel::setFrontColor(const QColor &color)
{
    m_frontColor = color;
    update();
}

void TTKLedPageLabel::setBackColor(const QColor &color)
{
    m_backColor = color;
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

    drawBack(painter);
    drawText(painter);
    drawLine(painter);
}

void TTKLedPageLabel::drawBack(QPainter &painter)
{
    QPen pen(m_backColor,1);
    painter.setPen(pen);

    QPainterPath path;
    path.addRoundedRect(1, 1, m_width,  m_height, 10, 10);
    painter.fillPath(path, m_backColor);
    painter.drawPath(path);
}

void TTKLedPageLabel::drawText(QPainter &painter)
{
    QPen pen(m_frontColor);
    painter.setPen(pen);
    painter.setFont(QFont("Roboto", m_fontSize, 75));
    painter.drawText(0, 0, m_width, m_height, Qt::AlignCenter, m_text);
}

void TTKLedPageLabel::drawLine(QPainter &painter)
{
    QPen pen(m_lineColor, 3);
    painter.setPen(pen);
    painter.drawLine(1, m_height / 2, m_width + 1, m_height / 2);
}
