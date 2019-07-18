#include "ttkringsprogresswidget.h"
#include <QPainter>

TTKRingsProgressWidget::TTKRingsProgressWidget(QWidget *parent)
    : QWidget(parent),
    m_angle(0),
    m_value(0)
{

}

void TTKRingsProgressWidget::setValue(int value)
{
    if(value != m_value)
    {
        m_value = value;
        update();
    }
}

QSize TTKRingsProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKRingsProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    m_angle = 360 * m_value / 100;

    const int side = qMin(width(), height());
    const QRectF outRect(0, 0, side, side);
    const QRectF inRect(20, 20, side - 40, side - 40);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(97, 117, 118)));
    painter.drawEllipse(outRect);

    painter.setBrush(QBrush(QColor(255, 107, 107)));
    painter.drawPie(outRect, (90 - m_angle) * 16, m_angle * 16);

    painter.setBrush(palette().window().color());
    painter.drawEllipse(inRect);

    painter.setFont(QFont("Roboto", 15, QFont::Bold));
    painter.setPen(QColor("#555555"));
    painter.drawText(inRect, Qt::AlignCenter, QString("%1%").arg(m_value));
}
