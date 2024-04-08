#include "ttkroundanimationlabel.h"

#include <QPainter>

TTKRoundAnimationLabel::TTKRoundAnimationLabel(QWidget *parent)
    : QWidget(parent),
      m_rotateAngle(0)
{
    m_timer.setInterval(50 * TTK_DN_MS);
    connect(&m_timer, SIGNAL(timeout()), SLOT(update()));
}

TTKRoundAnimationLabel::~TTKRoundAnimationLabel()
{
    stop();
}

void TTKRoundAnimationLabel::setPixmap(const QPixmap &pix)
{
    m_pixmap = pix;
    update();
}

void TTKRoundAnimationLabel::setInterval(int value)
{
    m_timer.setInterval(value);
}

void TTKRoundAnimationLabel::start()
{
    m_timer.start();
}

void TTKRoundAnimationLabel::stop()
{
    m_timer.stop();
}

QSize TTKRoundAnimationLabel::sizeHint() const
{
    return QSize(200, 200);
}

void TTKRoundAnimationLabel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    const QSize &self = size();
    const QRect rotatedRect(-self.width() / 2, -self.height() / 2, self.width(), self.height());
    const int cx = self.width() / 2;
    const int cy = self.height() / 2;

    if(++m_rotateAngle >= 360)
    {
        m_rotateAngle -= 360;
    }

    painter.save();
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.translate(cx, cy);
    painter.rotate(m_rotateAngle);
    painter.drawPixmap(rotatedRect, m_pixmap);
    painter.restore();
}
