#include "ttktilebackgroundlabel.h"

#include <QPainter>

TTKTileBackgroundLabel::TTKTileBackgroundLabel(QWidget *parent)
    : QWidget(parent)
{
    m_foreColor = QColor(0, 0, 0);
    m_backColor = QColor(250, 250, 250);
    m_pix = QPixmap(64, 64);
}

TTKTileBackgroundLabel::~TTKTileBackgroundLabel()
{

}

void TTKTileBackgroundLabel::setForeColor(const QColor &color)
{
    if(m_foreColor != color)
    {
        m_foreColor = color;
        drawBackground();
    }
}

void TTKTileBackgroundLabel::setBackColor(const QColor &color)
{
    if(m_backColor != color)
    {
        m_backColor = color;
        drawBackground();
    }
}

void TTKTileBackgroundLabel::setBackgroundPix(const QPixmap &pix)
{
    if(!pix.isNull())
    {
        m_pix = pix;
        update();
    }
}

QSize TTKTileBackgroundLabel::sizeHint() const
{
    return QSize(180, 180);
}

void TTKTileBackgroundLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if(m_pix.isNull())
    {
        return;
    }
    QPainter painter(this);
    painter.drawTiledPixmap(rect(), m_pix);
}

void TTKTileBackgroundLabel::drawBackground()
{
    m_pix.fill(m_backColor);

    QPainter painter(&m_pix);
    painter.fillRect(0, 0, 32, 32, m_foreColor);
    painter.fillRect(32, 32, 32, 32, m_foreColor);
    update();
}
