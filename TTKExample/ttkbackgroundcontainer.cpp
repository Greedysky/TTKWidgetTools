#include "ttkbackgroundcontainer.h"

#include <qmath.h>
#include <QPainter>
#include <QBoxLayout>

#define PIX_HEIGHT          16
#define PIX_WIDTH           16
#define ITEM_ICON_SZIE      25

TTKBackgroundContainerItem::TTKBackgroundContainerItem(QWidget *parent)
    : TTKGrabItemWidget(parent),
      m_item(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);
}

TTKBackgroundContainerItem::~TTKBackgroundContainerItem()
{
    delete m_item;
}

void TTKBackgroundContainerItem::addItem(QWidget *item)
{
    delete m_item;
    m_item = item;
    layout()->addWidget(item);
}

void TTKBackgroundContainerItem::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    QPen pen(QColor(255, 0, 0), 15);
    painter.setPen(pen);
    painter.drawPoints(m_listMarker);
}



TTKBackgroundContainer::TTKBackgroundContainer(QWidget *parent)
    : QWidget(parent)
{
    m_item = new TTKBackgroundContainerItem(this);
    m_item->setGeometry(QRect(100, 170, 200, 200));
    m_item->setVisible(false);
}

TTKBackgroundContainer::~TTKBackgroundContainer()
{
    delete m_item;
}

void TTKBackgroundContainer::addItem(QWidget *item)
{
    m_item->setVisible(true);
    m_item->addItem(item);
}

void TTKBackgroundContainer::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    QPixmap pix(":/image/lb_transparent");
    for(int i=0; i<ceil(width()/PIX_WIDTH); ++i)
    {
        for(int j=0; j<=ceil(height()/PIX_HEIGHT); ++j)
        {
            painter.drawPixmap(i*PIX_WIDTH, j*PIX_HEIGHT, PIX_WIDTH, PIX_HEIGHT, pix);
        }
    }
}
