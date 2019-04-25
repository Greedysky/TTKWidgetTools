#include "ttkbackgroundcontainer.h"

#include <qmath.h>
#include <QPainter>
#include <QBoxLayout>

#define PIX_HEIGHT          16
#define PIX_WIDTH           16
#define ITEM_ICON_SZIE      25

TTKbackgroundContainer::TTKbackgroundContainer(QWidget *parent)
    : QWidget(parent)
{

}

void TTKbackgroundContainer::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

//    painter.setOpacity(0.5);
    QPixmap pix(":/image/lb_transparent");
    for(int i=0; i<ceil(width()/PIX_WIDTH); ++i)
    {
        for(int j=0; j<=ceil(height()/PIX_HEIGHT); ++j)
        {
            painter.drawPixmap(i*PIX_WIDTH, j*PIX_HEIGHT, PIX_WIDTH, PIX_HEIGHT, pix);
        }
    }
}

//void TTKbackgroundContainer::mousePressEvent(QMouseEvent *event)
//{
//    Q_UNUSED(event);
//}

//void TTKbackgroundContainer::mouseReleaseEvent(QMouseEvent *event)
//{
//    Q_UNUSED(event);
//}

//void TTKbackgroundContainer::mouseMoveEvent(QMouseEvent *event)
//{
//    Q_UNUSED(event);
//}
