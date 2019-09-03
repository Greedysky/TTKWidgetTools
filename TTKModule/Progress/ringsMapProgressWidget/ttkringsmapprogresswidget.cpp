#include "ttkringsmapprogresswidget.h"

#include <QPainter>

TTKRingsMapProgressWidget::TTKRingsMapProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_angle(0),
      m_value(0)
{

}

void TTKRingsMapProgressWidget::setValue(int value)
{
    if(value != m_value)
    {
        m_value = value;
        update();
    }
}

QSize TTKRingsMapProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKRingsMapProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    m_angle = 360 * m_value / 100;

    const int side = qMin(width(), height());
    const QRectF outRect(0, 0, side, side);
    const QRectF inRect(20, 20, side - 40, side - 40);

    painter.setPen(Qt::NoPen);
    painter.drawPixmap(outRect, QPixmap(":/res/lb_back"), outRect);

    painter.setBrush(QBrush(QPixmap(":/res/lb_front")));
    painter.drawPie(outRect, (90 - m_angle) * 16, m_angle * 16);

    painter.setFont(QFont("Roboto", 15, QFont::Bold));
    painter.setPen(QColor("#DDDDDD"));
    painter.drawText(inRect, Qt::AlignCenter, QString("%1%").arg(m_value));
}
