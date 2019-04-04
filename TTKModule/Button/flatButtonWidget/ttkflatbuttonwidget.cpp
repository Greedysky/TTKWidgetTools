#include "ttkflatbuttonwidget.h"

#include <QPainter>

#define ICONPADDING     12

TTKFlatButtonWidget::TTKFlatButtonWidget(QWidget *parent)
    : QPushButton(parent)
{
    m_textAlignment = Qt::AlignCenter;
    m_iconAlignment = LeftIcon;
    m_backgroundColor = QColor(255, 0, 0);
    m_foregroundColor = QColor(0, 0, 0);
    m_cornerRadius = 5;
    m_fontSize = 10;
}

void TTKFlatButtonWidget::setForegroundColor(const QColor &color)
{
    m_foregroundColor = color;
}

void TTKFlatButtonWidget::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
}

void TTKFlatButtonWidget::setFontSize(qreal size)
{
    m_backgroundColor = size;
}

void TTKFlatButtonWidget::setIconAlignment(IconAlignment alignment)
{
    m_iconAlignment = alignment;
}

void TTKFlatButtonWidget::setCornerRadius(qreal radius)
{
    m_cornerRadius = radius;
}

void TTKFlatButtonWidget::setTextAlignment(Qt::Alignment alignment)
{
    m_textAlignment = alignment;
}

void TTKFlatButtonWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(m_cornerRadius > 0)
    {
        QPainterPath path;
        path.addRoundedRect(rect(), m_cornerRadius, m_cornerRadius);

        painter.setClipPath(path);
        painter.setClipping(true);
    }

    paintBackground(&painter);
    paintForeground(&painter);
}

void TTKFlatButtonWidget::paintBackground(QPainter *painter)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(backgroundColor());

    painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(rect());
}

void TTKFlatButtonWidget::paintForeground(QPainter *painter)
{
    if(isEnabled())
    {
        painter->setPen(foregroundColor());
    }

    if(icon().isNull())
    {
        if(Qt::AlignLeft == m_textAlignment)
        {
            painter->drawText(rect().adjusted(12, 0, 0, 0), Qt::AlignLeft | Qt::AlignVCenter, text());
        }
        else
        {
            painter->drawText(rect(), Qt::AlignCenter, text());
        }
        return;
    }

    QSize textSize(fontMetrics().size(Qt::TextSingleLine, text()));
    QSize base(size()-textSize);

    const int iw = iconSize().width() + ICONPADDING;
    QPoint pos(Qt::AlignLeft == m_textAlignment ? 12 : (base.width()-iw)/2, 0);

    QRect textGeometry(pos + QPoint(0, base.height()/2), textSize);
    QRect iconGeometry(pos + QPoint(0, (height()-iconSize().height())/2), iconSize());

    if(LeftIcon == m_iconAlignment)
    {
        textGeometry.translate(iw, 0);
    }
    else
    {
        iconGeometry.translate(textSize.width() + ICONPADDING, 0);
    }

    painter->drawText(textGeometry, Qt::AlignCenter, text());

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), painter->pen().color());
    painter->drawPixmap(iconGeometry, pixmap);
}
