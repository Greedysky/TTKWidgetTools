#include "ttktilebackgroundlabel.h"

#include <QPainter>

TTKTileBackgroundLabel::TTKTileBackgroundLabel(QWidget *parent)
    : QWidget(parent),
      m_foregroundColor(0, 0, 0),
      m_backgroundColor(250, 250, 250),
      m_pix(64, 64)
{

}

void TTKTileBackgroundLabel::setForegroundColor(const QColor &foregroundColor)
{
    if(m_foregroundColor != foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        drawBackground();
    }
}

void TTKTileBackgroundLabel::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        drawBackground();
    }
}

void TTKTileBackgroundLabel::setBackgroundPixmap(const QPixmap &pix)
{
    if(!pix.isNull())
    {
        m_pix = pix;
        update();
    }
}

QSize TTKTileBackgroundLabel::sizeHint() const
{
    return QSize(200, 200);
}

void TTKTileBackgroundLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if(m_pix.isNull())
    {
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawTiledPixmap(rect(), m_pix);
}

void TTKTileBackgroundLabel::drawBackground()
{
    m_pix.fill(m_backgroundColor);

    QPainter painter(&m_pix);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(0, 0, 32, 32, m_foregroundColor);
    painter.fillRect(32, 32, 32, 32, m_foregroundColor);
    update();
}
