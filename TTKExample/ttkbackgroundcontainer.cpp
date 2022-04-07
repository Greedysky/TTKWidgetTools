#include "ttkbackgroundcontainer.h"

#include <qmath.h>
#include <QPainter>
#include <QBoxLayout>

#define PIX_HEIGHT          16
#define PIX_WIDTH           16
#define ITEM_ICON_SZIE      25
#define ITEM_SPACE          20

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
    TTKStatic_cast(QVBoxLayout*, layout())->addWidget(item, 0, Qt::AlignCenter);

    const QSize &hint = m_item->sizeHint();
    const int width = geometry().width();
    const int height = geometry().height();

    if(hint.width() > width)
    {
        QRect rect = geometry();
        rect.setWidth(hint.width() + ITEM_SPACE);
        setGeometry(rect);
    }
    if(hint.height() > height)
    {
        QRect rect = geometry();
        rect.setHeight(hint.height() + ITEM_SPACE);
        setGeometry(rect);
    }

}

void TTKBackgroundContainerItem::onMouseChange(int x, int y)
{
    const QSize &hint = m_item->sizeHint();

    switch(m_direction)
    {
        case DirectionNo:
        case DirectionRight:
        case DirectionBottom:
        case DirectionRightBottom:
            {
                const QPoint &topLeft = m_originRect.topLeft();
                if(x - topLeft.x() <= hint.width())
                {
                    m_currentRect = QRect(topLeft,
                                          QSize(hint.width(), y - topLeft.y() <= hint.height() ? hint.height() : y - topLeft.y()));
                    setGeometry(m_currentRect);
                    return;
                }
                else if(y - topLeft.y() <= hint.height())
                {
                    m_currentRect = QRect(topLeft,
                                          QSize(x - topLeft.x() <= hint.width() ? hint.width() : x - topLeft.x(), hint.height()));
                    setGeometry(m_currentRect);
                    return;
                }
                break;
            }
        case DirectionRightTop:
            {
                const QPoint &bottomLeft = m_originRect.bottomLeft();
                if(x - bottomLeft.x() <= hint.width())
                {
                    m_currentRect = QRect(QPoint(bottomLeft.x(), bottomLeft.y() - y <= hint.height() ? bottomLeft.y() - hint.height() : y),
                                          QSize(hint.width(), bottomLeft.y() - y <= hint.height() ? hint.height() : bottomLeft.y() - y));
                    setGeometry(m_currentRect);
                    return;
                }
                else if(bottomLeft.y() - y <= hint.height())
                {
                    m_currentRect = QRect(QPoint(bottomLeft.x(), bottomLeft.y() - y <= hint.height() ? bottomLeft.y() - hint.height() : y),
                                          QSize((x - bottomLeft.x() <= hint.width() ? hint.width() : x - bottomLeft.x()), hint.height()));
                    setGeometry(m_currentRect);
                    return;
                }
                break;
            }
        case DirectionLeft:
        case DirectionLeftBottom:
            {
                const QPoint &topRight = m_originRect.topRight();
                if(topRight.x() - x <= hint.width())
                {
                    m_currentRect = QRect(QPoint(topRight.x() - hint.width(), topRight.y()),
                                          QSize(hint.width(), y - topRight.y() <= hint.height() ? hint.height() : y - topRight.y()));
                    setGeometry(m_currentRect);
                    return;
                }
                else if(y - topRight.y() <= hint.height())
                {
                    m_currentRect = QRect(QPoint(x, topRight.y()),
                                          QSize(topRight.x() - x <= hint.width() ? hint.width() : topRight.x() - x, hint.height()));
                    setGeometry(m_currentRect);
                    return;
                }
                break;
            }
        case DirectionLeftTop:
        case DirectionTop:
            {
                const QPoint &bottomRight = m_originRect.bottomRight();
                if(bottomRight.x() - x <= hint.width())
                {
                    m_currentRect = QRect(QPoint(bottomRight.x() - hint.width(), bottomRight.y() - y <= hint.height() ? bottomRight.y() - hint.height() : y),
                                          QSize(hint.width(), bottomRight.y() - y <= hint.height() ? hint.height() : bottomRight.y() - y));
                    setGeometry(m_currentRect);
                    return;
                }
                else if(bottomRight.y() - y <= hint.height())
                {
                    m_currentRect = QRect(QPoint(x, bottomRight.y() - hint.height()),
                                          QSize(bottomRight.x() - x <= hint.width() ? hint.width() : bottomRight.x() - x, hint.height()));
                    setGeometry(m_currentRect);
                    return;
                }
                break;
            }
    }

    TTKGrabItemWidget::onMouseChange(x, y);
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
    m_item->setVisible(false);
}

TTKBackgroundContainer::~TTKBackgroundContainer()
{
    delete m_item;
}

void TTKBackgroundContainer::addItem(QWidget *item)
{
    m_item->setVisible(true);
    m_item->setGeometry(QRect(100, 170, 200, 200));
    m_item->addItem(item);
}

void TTKBackgroundContainer::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    QPixmap pix(":/image/lb_transparent");
    for(int i = 0; i <= ceil(width() / PIX_WIDTH); ++i)
    {
        for(int j = 0; j <= ceil(height() / PIX_HEIGHT); ++j)
        {
            painter.drawPixmap(i * PIX_WIDTH, j * PIX_HEIGHT, PIX_WIDTH, PIX_HEIGHT, pix);
        }
    }
}
