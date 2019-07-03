#include "ttkcloudpanellabel.h"

#include <QPainter>
#include <QMouseEvent>

TTKCloudPanelLabel::TTKCloudPanelLabel(QWidget *parent)
    : QWidget(parent)
{
    m_enter = false;
    m_pressed = false;

    m_bgColor = Qt::black;
    m_baseColor = QColor(80, 80, 80);
    m_arcColor = QColor(32, 32, 32);
    m_borderColor = Qt::darkCyan;
    m_iconColor = Qt::white;
    m_pressColor = Qt::lightGray;
    m_cloudStyle = TTKCloudPanelLabel::CloudStyleBlack;

    setMinimumSize(100, 100);
}

TTKCloudPanelLabel::~TTKCloudPanelLabel()
{

}

void TTKCloudPanelLabel::setBgColor(const QColor &bgColor)
{
    if(m_bgColor != bgColor)
    {
        m_bgColor = bgColor;
        update();
    }
}

void TTKCloudPanelLabel::setBaseColor(const QColor &baseColor)
{
    if(m_baseColor != baseColor)
    {
        m_baseColor = baseColor;
        update();
    }
}

void TTKCloudPanelLabel::setArcColor(const QColor &arcColor)
{
    if(m_arcColor != arcColor)
    {
        m_arcColor = arcColor;
        update();
    }
}

void TTKCloudPanelLabel::setBorderColor(const QColor &borderColor)
{
    if(m_borderColor != borderColor)
    {
        m_borderColor = borderColor;
        update();
    }
}

void TTKCloudPanelLabel::setIconColor(const QColor &textColor)
{
    if(m_iconColor != textColor)
    {
        m_iconColor = textColor;
        update();
    }
}

void TTKCloudPanelLabel::setPressColor(const QColor &pressColor)
{
    if(m_pressColor != pressColor)
    {
        m_pressColor = pressColor;
        update();
    }
}

void TTKCloudPanelLabel::setCloudStyle(const CloudStyle cloudStyle)
{
    if(m_cloudStyle != cloudStyle)
    {
        m_cloudStyle = cloudStyle;
        update();
    }
}

void TTKCloudPanelLabel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    recalcLayout();
	update();
}

void TTKCloudPanelLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_enter = true;
	update();
}

void TTKCloudPanelLabel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_enter = false;
	update();
}

void TTKCloudPanelLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_lastPoint = event->pos();
    m_pressed = true;

    int bp;
    if(isPointIn(m_lastPoint, bp))
    {
        emit mousePressed(bp);
	}
	update();
}

void TTKCloudPanelLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_pressed = false;
	update();
}

void TTKCloudPanelLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QColor buttonColor = m_baseColor;

	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
	painter.scale(side / 200.0, side / 200.0);

    if(m_cloudStyle == CloudStyleBlack)
    {
        drawCircle(&painter, 99, m_bgColor);
        drawArc(&painter);
        drawCircle(&painter, 91, m_baseColor);
        drawCircle(&painter, 40, m_arcColor);
        drawCircle(&painter, 33, m_borderColor);
        drawCircle(&painter, 30, (m_pressed && m_centerRect.contains(m_lastPoint)) ? m_bgColor : m_baseColor);
	}
    else if(m_cloudStyle == CloudStyleWhite)
    {
        drawCircle(&painter, 99, QColor(249, 249, 249));

		QConicalGradient gradient(0, 0, 100);
		gradient.setColorAt(0, QColor(34, 163, 169));
		gradient.setColorAt(0.4, QColor(240, 201, 136));
		gradient.setColorAt(0.7, QColor(211, 77, 37));
		gradient.setColorAt(1, QColor(34, 163, 169));

        drawCircle(&painter, 90, gradient);
		buttonColor = QColor(245, 245, 245);
        drawCircle(&painter, 91, QColor(245, 245, 245));
        drawCircle(&painter, 33, QColor(208, 208, 208));
        drawCircle(&painter, 32, QColor(208, 208, 208));
        drawCircle(&painter, 30,(m_pressed && m_centerRect.contains(m_lastPoint)) ? QColor(255, 255, 255) : QColor(245, 245, 245));
	}
    else if(m_cloudStyle == CloudStyleBlue)
    {
		QConicalGradient gradient(0, 0, 100);
		gradient.setColorAt(0, QColor(34, 163, 169));
		gradient.setColorAt(0.4, QColor(240, 201, 136));
		gradient.setColorAt(0.7, QColor(211, 77, 37));
		gradient.setColorAt(1, QColor(34, 163, 169));
        drawCircle(&painter, 99, gradient);

		buttonColor = QColor(31, 66, 98);
        drawCircle(&painter, 91, QColor(31, 66, 98));
        drawCircle(&painter, 33, QColor(23, 54, 81));
        drawCircle(&painter, 30, QColor(150, 150, 150));
        drawCircle(&painter, 30, (m_pressed && m_centerRect.contains(m_lastPoint)) ? QColor(35, 82, 133) : QColor(34, 73, 115));
	}
    else if(m_cloudStyle == CloudStylePurple)
    {
		QConicalGradient gradient(0, 0, 100);
		gradient.setColorAt(0, QColor(87, 87, 155));
		gradient.setColorAt(0.4, QColor(129, 82, 130));
		gradient.setColorAt(0.7, QColor(54, 89, 166));
		gradient.setColorAt(1, QColor(87, 87, 155));
        drawCircle(&painter, 99, gradient);

		buttonColor = QColor(55, 55, 92);
        drawCircle(&painter, 91, QColor(55, 55, 92));
        drawCircle(&painter, 33, QColor(49, 48, 82));
        drawCircle(&painter, 30, QColor(82, 78, 131));
        drawCircle(&painter, 30, (m_pressed && m_centerRect.contains(m_lastPoint)) ? QColor(85, 81, 137) : QColor(62, 59, 103));
	}

    drawButton(&painter);

	painter.setPen(buttonColor.darker(110));
	double angleStep = 360.0 / 8.0;
	painter.rotate(angleStep / 2);
    for(int i = 0; i < 8; i++)
	{
		painter.rotate(angleStep);
		painter.drawLine(QPoint(33, 0), QPoint(90, 0));
	}
}

void TTKCloudPanelLabel::recalcLayout()
{
    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    const QPointF &center = rect().center();
    const double centerSize = side * 1.0 / 4.3;
    const double iconSize = side * 1.0 / 5.4;
    const double offset1 = 2.3;
    const double offset2 = 1.7;

    m_centerRect = QRectF(center.x() - centerSize / 2, center.y() - centerSize / 2, centerSize, centerSize);
    m_leftRect = QRectF(center.x() - iconSize * offset1, center.y() - iconSize / 2, iconSize, iconSize);
    m_topRect = QRectF(center.x() - iconSize / 2, center.y() - iconSize * offset1, iconSize, iconSize);
    m_rightRect = QRectF(center.x() + iconSize * (offset1 - 1), center.y() - iconSize / 2, iconSize, iconSize);
    m_bottomRect = QRectF(center.x() - iconSize / 2, center.y() + iconSize * (offset1 - 1), iconSize, iconSize);
    m_leftTopRect = QRectF(center.x() - iconSize * offset2, center.y() - iconSize * offset2, iconSize, iconSize);
    m_rightTopRect = QRectF(center.x() + iconSize * (offset2 - 1), center.y() - iconSize * offset2, iconSize, iconSize);
    m_leftBottomRect = QRectF(center.x() - iconSize * offset2, center.y() + iconSize * (offset2 - 1), iconSize, iconSize);
    m_rightBottomRect = QRectF(center.x() + iconSize * (offset2 - 1), center.y() + iconSize * (offset2 - 1), iconSize, iconSize);
}

bool TTKCloudPanelLabel::isPointIn(const QPoint &pos, int &bp)
{
    bool bIsIn = false;
    if(m_rightRect.contains(pos))
    {
        bp = 0;
        bIsIn = true;
    }
    else if(m_rightTopRect.contains(pos))
    {
        bp = 1;
        bIsIn = true;
    }
    else if(m_topRect.contains(pos))
    {
        bp = 2;
        bIsIn = true;
    }
    else if(m_leftTopRect.contains(pos))
    {
        bp = 3;
        bIsIn = true;
    }
    else if(m_leftRect.contains(pos))
    {
        bp = 4;
        bIsIn = true;
    }
    else if(m_leftBottomRect.contains(pos))
    {
        bp = 5;
        bIsIn = true;
    }
    else if(m_bottomRect.contains(pos))
    {
        bp = 6;
        bIsIn = true;
    }

    else if(m_rightBottomRect.contains(pos))
    {
        bp = 7;
        bIsIn = true;
    }
    else if(m_centerRect.contains(pos))
    {
        bp = 8;
        bIsIn = true;
    }

    return bIsIn;
}

void TTKCloudPanelLabel::drawCircle(QPainter *painter, int radius, const QBrush &brush)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKCloudPanelLabel::drawArc(QPainter *painter)
{
    const int radius = 91;
    painter->save();
    painter->setBrush(Qt::NoBrush);

    QPen pen;
    pen.setWidthF(10);
    pen.setColor(m_arcColor);
    painter->setPen(pen);

    QRectF rect = QRectF(-radius, -radius, radius * 2, radius * 2);
    painter->drawArc(rect, 0 * 16, 360 * 16);
    painter->restore();
}

void TTKCloudPanelLabel::drawButton(QPainter *painter)
{
    int radius = 100;

    painter->save();
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    if(m_pressed && m_centerRect.contains(m_lastPoint))
    {
        pen.setColor(m_pressColor);
    }
    else
    {
        pen.setColor(m_iconColor);
    }

    pen.setWidth(3);
    painter->setPen(pen);
    QRectF centerRect(-radius, -radius, radius * 2, radius * 2);
    painter->drawArc(QRect(-10, -10, 20, 20), 30 * 16, 100 * 16);
    painter->drawArc(QRect(-10, -10, 20, 20), 210 * 16, 100 * 16);

    pen.setWidth(1);
    painter->setPen(pen);
    painter->setBrush(pen.color());

    QPainterPath arrow;
    arrow.moveTo(-5, -10);
    arrow.lineTo(0, -6);
    arrow.lineTo(0, -14);
    arrow.lineTo(-5, -10);

    painter->rotate(130);
    painter->drawPath(arrow);

    painter->rotate(180);
    painter->drawPath(arrow);
    painter->restore();

    painter->save();
    radius = 70;

    const int offset = 15;
    const int steps = 8;
    const double angleStep = 360.0 / steps;

    QRect iconRect(-offset / 2, radius - offset, offset, offset);
    int bp = 0;
    bool isIn = false;
    if(m_pressed)
    {
        isIn = isPointIn(m_lastPoint, bp);
    }

    for(int i = 0; i < steps; i++)
    {
        if(isIn && (bp == i))
        {
            painter->setPen(m_pressColor);
            painter->setBrush(QBrush(m_pressColor));
        }
        else
        {
            painter->setPen(m_iconColor);
            painter->setBrush(QBrush(m_iconColor));
        }
        QPainterPath path;
        path.moveTo(75, 0);
        path.lineTo(65, -10);
        path.lineTo(65, 10);
        path.lineTo(75, 0);
        painter->drawPath(path);
        painter->rotate(-angleStep);
    }
    painter->restore();
}
