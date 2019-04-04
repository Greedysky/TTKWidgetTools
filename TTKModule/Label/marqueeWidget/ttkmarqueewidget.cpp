#include "ttkmarqueewidget.h"

#include <QPainter>
#include <QTimerEvent>

TTKMarqueeWidget::TTKMarqueeWidget(QWidget *parent)
    : QWidget(parent)
{
    m_offset = 0;
    m_myTimerId = 0;
}

void TTKMarqueeWidget::setText(const QString &newText)
{
    int length = fontMetrics().width( newText );
    length = (length >= width()) ? 45 : 25;
    m_myText = newText.leftJustified(length, ' ');

    update();
    updateGeometry();
}

QSize TTKMarqueeWidget::sizeHint() const
{
    return fontMetrics().size(0, m_myText);
}

void TTKMarqueeWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    QFont f(font());
    f.setBold(false);
    painter.setFont(f);

    int textWidth = fontMetrics().width(m_myText);
    if(textWidth < 1)
    {
        return;
    }
    int x = -m_offset;
    while(x < width())
    {
        painter.drawText(x, 0, textWidth, height(),
                         Qt::AlignLeft | Qt::AlignVCenter, m_myText);
        x += textWidth;
    }
    painter.end();
}

void TTKMarqueeWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    m_myTimerId = startTimer(30);
}

void TTKMarqueeWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_myTimerId)
    {
        ++m_offset;
        if (m_offset >= fontMetrics().width(m_myText))
        {
            m_offset = 0;
        }
        scroll(-1, 0);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void TTKMarqueeWidget::hideEvent(QHideEvent *event)
{
    QWidget::hideEvent(event);
    killTimer(m_myTimerId);
    m_myTimerId = 0;
}

void TTKMarqueeWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    setText( text() );
}
