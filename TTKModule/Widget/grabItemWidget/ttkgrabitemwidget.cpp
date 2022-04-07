#include "ttkgrabitemwidget.h"

#include <qmath.h>
#include <QPainter>
#include <QMouseEvent>

#define PADDING          6

TTKGrabItemWidget::TTKGrabItemWidget(QWidget *parent)
    : QWidget(parent)
{
    m_direction = DirectionNo;
    m_isPressed = false;
    m_crossStretch = true;

    setMouseTracking(true);
}

QSize TTKGrabItemWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKGrabItemWidget::onMouseChange(int x, int y)
{
    if(x < 0 || y < 0)
    {
        return;
    }

    QPoint pt;
    switch(m_direction)
    {
        case DirectionNo:
        case DirectionRight:
        case DirectionBottom:
        case DirectionRightBottom:
            pt = m_originRect.topLeft();
            break;
        case DirectionRightTop:
            pt = m_originRect.bottomLeft();
            break;
        case DirectionLeft:
        case DirectionLeftBottom:
            pt = m_originRect.topRight();
            break;
        case DirectionLeftTop:
        case DirectionTop:
            pt = m_originRect.bottomRight();
            break;
    }

    const int rx = (x >= pt.x()) ? pt.x() : x;
    const int ry = (y >= pt.y()) ? pt.y() : y;
    const int rw = abs(x - pt.x());
    const int rh = abs(y - pt.y());

    m_currentRect = QRect(rx, ry, rw, rh);
    setGeometry(m_currentRect);
}

void TTKGrabItemWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_isPressed = true;
        if(m_direction != DirectionNo)
        {
            mouseGrabber();
        }
#if TTK_QT_VERSION_CHECK(6,0,0)
        m_movePos = event->globalPosition().toPoint() - pos();
#else
        m_movePos = event->globalPos() - pos();
#endif
    }
}

void TTKGrabItemWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_isPressed = false;
        if(m_direction != DirectionNo)
        {
            setCursor(QCursor(Qt::SizeAllCursor));
        }

        emit rectChanged();
    }
}

void TTKGrabItemWidget::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint &gloPoint = mapToParent(event->pos());
    const QPoint &pt_lu = mapToParent(rect().topLeft());
    const QPoint &pt_ll = mapToParent(rect().bottomLeft());
    const QPoint &pt_rl = mapToParent(rect().bottomRight());

    if(!m_isPressed)
    {
        m_direction = region(gloPoint);
        m_originRect = QRect(pt_lu, pt_rl);
    }
    else
    {
        if(m_direction != DirectionNo)
        {
            switch(m_direction)
            {
                case DirectionLeft:
                    return onMouseChange(gloPoint.x(), pt_ll.y() + 1);
                case DirectionRight:
                    return onMouseChange(gloPoint.x(), pt_rl.y() + 1);
                case DirectionTop:
                    return onMouseChange(pt_lu.x(), gloPoint.y());
                case DirectionBottom:
                    return onMouseChange(pt_rl.x() + 1, gloPoint.y());
                case DirectionLeftTop:
                case DirectionRightTop:
                case DirectionLeftBottom:
                case DirectionRightBottom:
                    if(m_crossStretch)
                    {
                        return onMouseChange(gloPoint.x(), gloPoint.y());
                    }
                    else
                    {
                        break;
                    }
                default: break;
            }
        }
        else
        {
#if TTK_QT_VERSION_CHECK(6,0,0)
            move(event->globalPosition().toPoint() - m_movePos);
            m_movePos = event->globalPosition().toPoint() - pos();
#else
            move(event->globalPos() - m_movePos);
            m_movePos = event->globalPos() - pos();
#endif
        }
    }
    m_currentRect = geometry();
}

void TTKGrabItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_listMarker.clear();
    m_listMarker.push_back(QPoint(0, 0));
    m_listMarker.push_back(QPoint(width(), 0));
    m_listMarker.push_back(QPoint(0, height()));
    m_listMarker.push_back(QPoint(width(), height()));

    m_listMarker.push_back(QPoint((width() >> 1), 0));
    m_listMarker.push_back(QPoint((width() >> 1), height()));
    m_listMarker.push_back(QPoint(0, (height() >> 1)));
    m_listMarker.push_back(QPoint(width(), (height() >> 1)));
}

void TTKGrabItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    QPen pen(QColor(0, 174, 255), 2);
    painter.setPen(pen);
    painter.drawRect(rect());

    pen.setWidth(4);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawPoints(m_listMarker);
}

TTKGrabItemWidget::Direction TTKGrabItemWidget::region(const QPoint &cursor)
{
    Direction ret_dir = DirectionNo;

    const QPoint &pt_lu = mapToParent(rect().topLeft());
    const QPoint &pt_rl = mapToParent(rect().bottomRight());

    const int x = cursor.x();
    const int y = cursor.y();

    if(pt_lu.x() + PADDING >= x && pt_lu.x() <= x && pt_lu.y() + PADDING >= y && pt_lu.y() <= y)
    {
        ret_dir = DirectionLeftTop;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if(x >= pt_rl.x() - PADDING && x <= pt_rl.x() && y >= pt_rl.y() - PADDING && y <= pt_rl.y())
    {
        ret_dir = DirectionRightBottom;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if(x <= pt_lu.x() + PADDING && x >= pt_lu.x() && y >= pt_rl.y() - PADDING && y <= pt_rl.y())
    {
        ret_dir = DirectionLeftBottom;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if(x <= pt_rl.x() && x >= pt_rl.x() - PADDING && y >= pt_lu.y() && y <= pt_lu.y() + PADDING)
    {
        ret_dir = DirectionRightTop;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if(x <= pt_lu.x() + PADDING && x >= pt_lu.x())
    {
        ret_dir = DirectionLeft;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if(x <= pt_rl.x() && x >= pt_rl.x() - PADDING)
    {
        ret_dir = DirectionRight;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if(y >= pt_lu.y() && y <= pt_lu.y() + PADDING)
    {
        ret_dir = DirectionTop;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if(y <= pt_rl.y() && y >= pt_rl.y() - PADDING)
    {
        ret_dir = DirectionBottom;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else
    {
        ret_dir = DirectionNo;
        setCursor(QCursor(Qt::SizeAllCursor));
    }

    return ret_dir;
}
