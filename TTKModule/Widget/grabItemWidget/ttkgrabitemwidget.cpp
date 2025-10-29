#include "ttkgrabitemwidget.h"

#include <QPainter>
#include <QMouseEvent>

static constexpr int PADDING = 6;

TTKGrabItemWidget::TTKGrabItemWidget(QWidget *parent)
    : QWidget(parent),
      m_isPressed(false),
      m_crossStretch(true),
      m_direction(Direction::No)
{
    setMouseTracking(true);
}

QSize TTKGrabItemWidget::sizeHint() const
{
    return QSize(200, 200);
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
        case Direction::No:
        case Direction::Right:
        case Direction::Bottom:
        case Direction::RightBottom:
            pt = m_originRect.topLeft();
            break;
        case Direction::RightTop:
            pt = m_originRect.bottomLeft();
            break;
        case Direction::Left:
        case Direction::LeftBottom:
            pt = m_originRect.topRight();
            break;
        case Direction::LeftTop:
        case Direction::Top:
            pt = m_originRect.bottomRight();
            break;
    }

    const int rx = (x >= pt.x()) ? pt.x() : x;
    const int ry = (y >= pt.y()) ? pt.y() : y;
    const int rw = std::abs(x - pt.x());
    const int rh = std::abs(y - pt.y());

    m_currentRect = QRect(rx, ry, rw, rh);
    setGeometry(m_currentRect);
}

void TTKGrabItemWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_isPressed = true;
        if(m_direction != Direction::No)
        {
            mouseGrabber();
        }

        m_movePos = QtMouseGlobalPos(event) - pos();
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
        if(m_direction != Direction::No)
        {
            switch(m_direction)
            {
                case Direction::Left:
                    return onMouseChange(gloPoint.x(), pt_ll.y() + 1);
                case Direction::Right:
                    return onMouseChange(gloPoint.x(), pt_rl.y() + 1);
                case Direction::Top:
                    return onMouseChange(pt_lu.x(), gloPoint.y());
                case Direction::Bottom:
                    return onMouseChange(pt_rl.x() + 1, gloPoint.y());
                case Direction::LeftTop:
                case Direction::RightTop:
                case Direction::LeftBottom:
                case Direction::RightBottom:
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
            move(QtMouseGlobalPos(event) - m_movePos);
            m_movePos = QtMouseGlobalPos(event) - pos();
        }
    }
    m_currentRect = geometry();
}

void TTKGrabItemWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_isPressed = false;
        if(m_direction != Direction::No)
        {
            setCursor(QCursor(Qt::SizeAllCursor));
        }

        Q_EMIT rectChanged();
    }
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
    Direction ret_dir = Direction::No;

    const QPoint &pt_lu = mapToParent(rect().topLeft());
    const QPoint &pt_rl = mapToParent(rect().bottomRight());

    const int x = cursor.x();
    const int y = cursor.y();

    if(pt_lu.x() + PADDING >= x && pt_lu.x() <= x && pt_lu.y() + PADDING >= y && pt_lu.y() <= y)
    {
        ret_dir = Direction::LeftTop;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if(x >= pt_rl.x() - PADDING && x <= pt_rl.x() && y >= pt_rl.y() - PADDING && y <= pt_rl.y())
    {
        ret_dir = Direction::RightBottom;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if(x <= pt_lu.x() + PADDING && x >= pt_lu.x() && y >= pt_rl.y() - PADDING && y <= pt_rl.y())
    {
        ret_dir = Direction::LeftBottom;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if(x <= pt_rl.x() && x >= pt_rl.x() - PADDING && y >= pt_lu.y() && y <= pt_lu.y() + PADDING)
    {
        ret_dir = Direction::RightTop;
        setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if(x <= pt_lu.x() + PADDING && x >= pt_lu.x())
    {
        ret_dir = Direction::Left;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if(x <= pt_rl.x() && x >= pt_rl.x() - PADDING)
    {
        ret_dir = Direction::Right;
        setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if(y >= pt_lu.y() && y <= pt_lu.y() + PADDING)
    {
        ret_dir = Direction::Top;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if(y <= pt_rl.y() && y >= pt_rl.y() - PADDING)
    {
        ret_dir = Direction::Bottom;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    else
    {
        ret_dir = Direction::No;
        setCursor(QCursor(Qt::SizeAllCursor));
    }

    return ret_dir;
}
