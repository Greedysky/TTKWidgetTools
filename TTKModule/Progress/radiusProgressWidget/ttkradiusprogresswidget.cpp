#include "ttkradiusprogresswidget.h"

#include <QPainter>

TTKRadiusProgressWidget::TTKRadiusProgressWidget(QWidget *parent)
    : QProgressBar(parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(0);
}

QSize TTKRadiusProgressWidget::sizeHint() const
{
    return QSize(150, 40);
}

void TTKRadiusProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    const QRect rect = QRect(0, 0, width(), height()/2);
    const QRect textRect = QRect(0, height()/2, width(), height()/2);

    const double k = (double)(value() - minimum()) / (maximum()-minimum());
    const int x = (int)(rect.width() * k);
    const QRect fillRect = rect.adjusted(0, 0, x - rect.width(), 0);

    painter.drawPixmap(rect, QPixmap(":/res/lb_rp_back"));
    painter.drawPixmap(fillRect, QPixmap(":/res/lb_rp_front"), fillRect);

    painter.setFont(QFont("Roboto", 15, QFont::Bold));
    painter.setPen(QColor("#555555"));
    painter.drawText(textRect, Qt::AlignCenter, QString("%1%").arg(value()));
}
