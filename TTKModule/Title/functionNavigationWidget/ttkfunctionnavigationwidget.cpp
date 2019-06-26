#include "ttkfunctionnavigationwidget.h"

#include <QPainter>

TTKFunctionNavigationWidget::TTKFunctionNavigationWidget(QWidget *parent)
    : QPushButton(parent)
{
    m_paddingLeft = 20;
    m_paddingRight = 5;
    m_paddingTop = 5;
    m_paddingBottom = 5;
    m_textAlign = TextAlignLeft;

    m_showTriangle = false;
    m_triangleLen = 5;
    m_trianglePosition = TrianglePositionRight;
    m_triangleColor = QColor(255, 255, 255);

    m_showIcon = false;
    m_iconSpace = 10;
    m_iconSize = QSize(16, 16);
    m_iconNormal = QPixmap();
    m_iconHover = QPixmap();
    m_iconCheck = QPixmap();

    m_showLine = true;
    m_lineSpace = 0;
    m_lineWidth = 5;
    m_linePosition = LinePositionLeft;
    m_lineColor = QColor(0, 187, 158);

    m_normalBgColor = QColor(230, 230, 230);
    m_hoverBgColor = QColor(130, 130, 130);
    m_checkBgColor = QColor(80, 80, 80);
    m_normalTextColor = QColor(100, 100, 100);
    m_hoverTextColor = QColor(255, 255, 255);
    m_checkTextColor = QColor(255, 255, 255);

    m_normalBgBrush = Qt::NoBrush;
    m_hoverBgBrush = Qt::NoBrush;
    m_checkBgBrush = Qt::NoBrush;

    m_hover = false;
    setCheckable(true);
}

void TTKFunctionNavigationWidget::setPaddingLeft(int paddingLeft)
{
    if(paddingLeft != m_paddingLeft)
    {
        m_paddingLeft = paddingLeft;
        update();
    }
}

void TTKFunctionNavigationWidget::setPaddingRight(int paddingRight)
{
    if(paddingRight != m_paddingRight)
    {
        m_paddingRight = paddingRight;
        update();
    }
}

void TTKFunctionNavigationWidget::setPaddingTop(int paddingTop)
{
    if(paddingTop != m_paddingTop)
    {
        m_paddingTop = paddingTop;
        update();
    }
}

void TTKFunctionNavigationWidget::setPaddingBottom(int paddingBottom)
{
    if(paddingBottom != m_paddingBottom)
    {
        m_paddingBottom = paddingBottom;
        update();
    }
}

void TTKFunctionNavigationWidget::setPadding(int padding)
{
    setPadding(padding, padding, padding, padding);
}

void TTKFunctionNavigationWidget::setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom)
{
    m_paddingLeft = paddingLeft;
    m_paddingRight = paddingRight;
    m_paddingTop = paddingTop;
    m_paddingBottom = paddingBottom;
    update();
}

void TTKFunctionNavigationWidget::setTextAlign(TextAlign textAlign)
{
    if(textAlign != m_textAlign)
    {
        m_textAlign = textAlign;
        update();
    }
}

void TTKFunctionNavigationWidget::setShowTriangle(bool showTriangle)
{
    if(showTriangle != m_showTriangle)
    {
        m_showTriangle = showTriangle;
        update();
    }
}

void TTKFunctionNavigationWidget::setTriangleLen(int triangleLen)
{
    if(triangleLen != m_triangleLen)
    {
        m_triangleLen = triangleLen;
        update();
    }
}

void TTKFunctionNavigationWidget::setTrianglePosition(TrianglePosition trianglePosition)
{
    if(trianglePosition != m_trianglePosition)
    {
        m_trianglePosition = trianglePosition;
        update();
    }
}

void TTKFunctionNavigationWidget::setTriangleColor(const QColor &triangleColor)
{
    if(triangleColor != m_triangleColor)
    {
        m_triangleColor = triangleColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setShowIcon(bool showIcon)
{
    if(showIcon != m_showIcon)
    {
        m_showIcon = showIcon;
        update();
    }
}

void TTKFunctionNavigationWidget::setIconSpace(int iconSpace)
{
    if(iconSpace != m_iconSpace)
    {
        m_iconSpace = iconSpace;
        update();
    }
}

void TTKFunctionNavigationWidget::setIconSize(const QSize &iconSize)
{
    if(iconSize != m_iconSize)
    {
        m_iconSize = iconSize;
        update();
    }
}

void TTKFunctionNavigationWidget::setIconNormal(const QPixmap &iconNormal)
{
    m_iconNormal = iconNormal;
    update();
}

void TTKFunctionNavigationWidget::setIconHover(const QPixmap &iconHover)
{
    m_iconHover = iconHover;
    update();
}

void TTKFunctionNavigationWidget::setIconCheck(const QPixmap &iconCheck)
{
    m_iconCheck = iconCheck;
    update();
}

void TTKFunctionNavigationWidget::setShowLine(bool showLine)
{
    if(showLine != m_showLine)
    {
        m_showLine = showLine;
        update();
    }
}

void TTKFunctionNavigationWidget::setLineSpace(int lineSpace)
{
    if(lineSpace != m_lineSpace)
    {
        m_lineSpace = lineSpace;
        update();
    }
}

void TTKFunctionNavigationWidget::setLineWidth(int lineWidth)
{
    if(lineWidth != m_lineWidth)
    {
        m_lineWidth = lineWidth;
        update();
    }
}

void TTKFunctionNavigationWidget::setLinePosition(LinePosition linePosition)
{
    if(linePosition != m_linePosition)
    {
        m_linePosition = linePosition;
        update();
    }
}

void TTKFunctionNavigationWidget::setLineColor(const QColor &lineColor)
{
    if(lineColor != m_lineColor)
    {
        m_lineColor = lineColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setNormalBgColor(const QColor &normalBgColor)
{
    if(normalBgColor != m_normalBgColor)
    {
        m_normalBgColor = normalBgColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setHoverBgColor(const QColor &hoverBgColor)
{
    if(hoverBgColor != m_hoverBgColor)
    {
        m_hoverBgColor = hoverBgColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setCheckBgColor(const QColor &checkBgColor)
{
    if(checkBgColor != m_checkBgColor)
    {
        m_checkBgColor = checkBgColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setNormalTextColor(const QColor &normalTextColor)
{
    if(normalTextColor != m_normalTextColor)
    {
        m_normalTextColor = normalTextColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setHoverTextColor(const QColor &hoverTextColor)
{
    if(hoverTextColor != m_hoverTextColor)
    {
        m_hoverTextColor = hoverTextColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setCheckTextColor(const QColor &checkTextColor)
{
    if(checkTextColor != m_checkTextColor)
    {
        m_checkTextColor = checkTextColor;
        update();
    }
}

void TTKFunctionNavigationWidget::setNormalBgBrush(const QBrush &normalBgBrush)
{
    if(normalBgBrush != m_normalBgBrush)
    {
        m_normalBgBrush = normalBgBrush;
        update();
    }
}

void TTKFunctionNavigationWidget::setHoverBgBrush(const QBrush &hoverBgBrush)
{
    if(hoverBgBrush != m_hoverBgBrush)
    {
        m_hoverBgBrush = hoverBgBrush;
        update();
    }
}

void TTKFunctionNavigationWidget::setCheckBgBrush(const QBrush &checkBgBrush)
{
    if(checkBgBrush != m_checkBgBrush)
    {
        m_checkBgBrush = checkBgBrush;
        update();
    }
}

QSize TTKFunctionNavigationWidget::sizeHint() const
{
    return QSize(100, 30);
}

void TTKFunctionNavigationWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_hover = true;
    update();
}

void TTKFunctionNavigationWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_hover = false;
    update();
}

void TTKFunctionNavigationWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    drawBackground(&painter);
    drawText(&painter);
    drawIcon(&painter);
    drawLine(&painter);
    drawTriangle(&painter);
}

void TTKFunctionNavigationWidget::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    const int w = width();
    const int h = height();

    QRect bgRect;
    if(m_linePosition == LinePositionLeft)
    {
        bgRect = QRect(m_lineSpace, 0, w - m_lineSpace, h);
    }
    else if(m_linePosition == LinePositionRight)
    {
        bgRect = QRect(0, 0, w - m_lineSpace, h);
    }
    else if(m_linePosition == LinePositionTop)
    {
        bgRect = QRect(0, m_lineSpace, w, h - m_lineSpace);
    }
    else if(m_linePosition == LinePositionBottom)
    {
        bgRect = QRect(0, 0, w, h - m_lineSpace);
    }

    QBrush bgBrush;
    if(isChecked())
    {
        bgBrush = m_checkBgBrush;
    }
    else if(m_hover)
    {
        bgBrush = m_hoverBgBrush;
    }
    else
    {
        bgBrush = m_normalBgBrush;
    }

    if(bgBrush != Qt::NoBrush)
    {
        painter->setBrush(bgBrush);
    }
    else
    {
        QColor bgColor;
        if(isChecked())
        {
            bgColor = m_checkBgColor;
        }
        else if(m_hover){
            bgColor = m_hoverBgColor;
        }
        else
        {
            bgColor = m_normalBgColor;
        }

        painter->setBrush(bgColor);
    }

    painter->drawRect(bgRect);
    painter->restore();
}

void TTKFunctionNavigationWidget::drawText(QPainter *painter)
{
    painter->save();
    painter->setBrush(Qt::NoBrush);

    QColor textColor;
    if(isChecked())
    {
        textColor = m_checkTextColor;
    }
    else if(m_hover)
    {
        textColor = m_hoverTextColor;
    }
    else
    {
        textColor = m_normalTextColor;
    }

    const QRect &textRect = QRect(m_paddingLeft, m_paddingTop, width() - m_paddingLeft - m_paddingRight, height() - m_paddingTop - m_paddingBottom);
    painter->setPen(textColor);
    painter->drawText(textRect, m_textAlign | Qt::AlignVCenter, text());

    painter->restore();
}

void TTKFunctionNavigationWidget::drawIcon(QPainter *painter)
{
    if(!m_showIcon)
    {
        return;
    }

    painter->save();

    QPixmap pix;
    if(isChecked())
    {
        pix = m_iconCheck;
    }
    else if(m_hover)
    {
        pix = m_iconHover;
    }
    else
    {
        pix = m_iconNormal;
    }

    if(!pix.isNull())
    {
        pix = pix.scaled(m_iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter->drawPixmap(m_iconSpace, (height() - m_iconSize.height()) / 2, pix);
    }

    painter->restore();
}

void TTKFunctionNavigationWidget::drawLine(QPainter *painter)
{
    if(!m_showLine)
    {
        return;
    }

    if(!isChecked())
    {
        return;
    }

    painter->save();

    QPen pen;
    pen.setWidth(m_lineWidth);
    pen.setColor(m_lineColor);
    painter->setPen(pen);

    QPoint pointStart, pointEnd;
    if(m_linePosition == LinePositionLeft)
    {
        pointStart = QPoint(0, 0);
        pointEnd = QPoint(0, height());
    }
    else if(m_linePosition == LinePositionRight)
    {
        pointStart = QPoint(width(), 0);
        pointEnd = QPoint(width(), height());
    }
    else if(m_linePosition == LinePositionTop)
    {
        pointStart = QPoint(0, 0);
        pointEnd = QPoint(width(), 0);
    }
    else if(m_linePosition == LinePositionBottom)
    {
        pointStart = QPoint(0, height());
        pointEnd = QPoint(width(), height());
    }

    painter->drawLine(pointStart, pointEnd);
    painter->restore();
}

void TTKFunctionNavigationWidget::drawTriangle(QPainter *painter)
{
    if(!m_showTriangle)
    {
        return;
    }

    if(!m_hover && !isChecked())
    {
        return;
    }

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_triangleColor);

    const int w = width();
    const int h = height();
    const int midWidth = w / 2;
    const int midHeight = h / 2;

    QPolygon pts;
    if(m_trianglePosition == TrianglePositionLeft)
    {
        pts.setPoints(3, m_triangleLen, midHeight, 0, midHeight - m_triangleLen, 0, midHeight + m_triangleLen);
    }
    else if(m_trianglePosition == TrianglePositionRight)
    {
        pts.setPoints(3, w - m_triangleLen, midHeight, w, midHeight - m_triangleLen, w, midHeight + m_triangleLen);
    }
    else if(m_trianglePosition == TrianglePositionTop)
    {
        pts.setPoints(3, midWidth, m_triangleLen, midWidth - m_triangleLen, 0, midWidth + m_triangleLen, 0);
    }
    else if(m_trianglePosition == TrianglePositionBottom)
    {
        pts.setPoints(3, midWidth, h - m_triangleLen, midWidth - m_triangleLen, h, midWidth + m_triangleLen, h);
    }

    painter->drawPolygon(pts);
    painter->restore();
}
