#include "ttkfunctionnormalwidget.h"

#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

#define ITEM_HIGHT      40
#define ITEM_LEGHT      100

TTKFunctionNormalWidget::TTKFunctionNormalWidget(QWidget *parent)
    : QWidget(parent)
{
    m_itemOffset = 0;
    m_backGroundColor = 0;
    m_oldChooseBackGround = 0;
    m_newChooseBackGround = 0;
    m_chooseIndex = 0;

    setSize(0, 0);
    setMouseTracking(true);

    m_timer = new QTimer(this);
    m_timer->setInterval(1);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateRender()));
}

void TTKFunctionNormalWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    drawListWidget(&painter);
    drawChooseItem(&painter);
    drawItem(&painter);
}

void TTKFunctionNormalWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if((event->pos().x() < m_width) && (event->pos().y()))
    {
        if(event->pos().y() <= m_items.count() * ITEM_HIGHT)
        {
            m_backGroundColor = event->pos().y() / ITEM_HIGHT;
            update();
        }
    }
}

void TTKFunctionNormalWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(event->button() == Qt::LeftButton)
    {
        if((event->pos().x() < m_width) && (event->pos().y()))
        {
            if(event->pos().y() <= m_items.count() * ITEM_HIGHT)
            {
                m_newChooseBackGround = event->pos().y() / ITEM_HIGHT;
                m_timer->start();
            }
        }
    }
}

void TTKFunctionNormalWidget::setSize(qreal w, qreal h)
{
    setFixedSize(w, h);
    m_width = w;
    m_height = h;
}

void TTKFunctionNormalWidget::addItem(const QString &text)
{
    m_items.push_back(text);
}

void TTKFunctionNormalWidget::drawItem(QPainter *painter)
{
    for(int i=0; i < m_items.count(); i++)
    {
        if(i == m_backGroundColor)
        {
            if(m_backGroundColor != m_newChooseBackGround)
            {
                painter->setPen(Qt::NoPen);
                QBrush brush(QColor(50, 50, 50), Qt::SolidPattern);
                painter->setBrush(brush);
                painter->drawRect(0, m_backGroundColor*ITEM_HIGHT, m_width, ITEM_HIGHT);
            }
            painter->setPen(QPen(QColor(0, 188, 212), 3));

            QFont font("Roboto", 13, 10, false);
            painter->setFont(font);
            painter->drawText(QRectF(0, m_backGroundColor * ITEM_HIGHT, m_width, ITEM_HIGHT), m_items[i], Qt::AlignVCenter | Qt::AlignHCenter);

            if(i + 1 < m_items.count())
            {
                m_itemOffset += ITEM_HIGHT;
            }

            painter->setPen(QPen(QBrush("white"), 3));
        }
        else
        {
            QFont font("Roboto", 13, 10, false);
            painter->setFont(font);
            painter->setPen(QPen(QBrush("white"), 3));
            painter->drawText(QRectF(0, m_itemOffset, m_width, ITEM_HIGHT), m_items[i], Qt::AlignVCenter | Qt::AlignHCenter);

            if(i + 1 < m_items.count())
            {
                m_itemOffset += ITEM_HIGHT;
            }
        }
    }
    m_itemOffset = 0;
}

void TTKFunctionNormalWidget::drawChooseItem(QPainter* painter)
{
    painter->setPen(Qt::NoPen);

    QBrush brush(QColor(88, 86, 86), Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRect(0, m_chooseIndex, m_width - 5, ITEM_HIGHT);

    brush.setColor(QColor(0, 188, 212));
    painter->setBrush(brush);
    painter->drawRect(m_width - 5, m_chooseIndex, 5, ITEM_HIGHT);
}

void TTKFunctionNormalWidget::drawListWidget(QPainter* painter)
{
    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);

    QLinearGradient linerGradient(QPointF(0, 0), QPointF(0, m_height));
    linerGradient.setColorAt(0.0, QColor(30, 30, 39));
    linerGradient.setColorAt(1.0, QColor(35, 36, 40));
    painter->setBrush(linerGradient);
    painter->drawRect(0, 0, m_width, m_height);
}

void TTKFunctionNormalWidget::updateRender()
{
    if(m_chooseIndex != m_newChooseBackGround * ITEM_HIGHT)
    {
        if(m_chooseIndex > m_newChooseBackGround * ITEM_HIGHT)
        {
            m_chooseIndex--;
        }
        else
        {
            m_chooseIndex++;
        }
    }
    else
    {
        m_oldChooseBackGround = m_newChooseBackGround;
        m_timer->stop();
    }
    update();
}
