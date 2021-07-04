#include "ttkbackgroundwidget.h"

#include <QPainter>

TTKBackgroundWidget::TTKBackgroundWidget(QWidget *parent)
    : QWidget(parent)
{
}

void TTKBackgroundWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    painter.setOpacity(0.5);
    painter.fillRect(rect(), Qt::white);
}
