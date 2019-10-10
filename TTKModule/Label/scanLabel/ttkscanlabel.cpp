#include "ttkscanlabel.h"

#include <QTimer>
#include <QPainter>

TTKScanLabel::TTKScanLabel(QWidget *parent)
    : QWidget(parent)
{
    m_imageRadius = 10;
    m_scanRadius = 50;
    m_scanWidth = 0;
    m_ringRadius = 10;
    m_ringWidth = 5;
    m_scanDeg = 0;
    m_imageBorderWidth = 5;

    QPixmap pix(1, 1);
    pix.fill(Qt::white);
    m_image = pix;

    m_imageBorderColor = QColor(255, 255, 255);
    m_scanColor = QColor(255, 100, 10);
    m_ringColor = QColor(255, 213, 110);

    m_circleTimer = new QTimer(this);
    m_circleTimer->setInterval(20);
    m_circleTimer->start();
    connect(m_circleTimer, SIGNAL(timeout()), SLOT(updateRender()));
}

TTKScanLabel::~TTKScanLabel()
{
    delete m_circleTimer;
}

void TTKScanLabel::setImage(const QPixmap &image)
{
    if(image.cacheKey() != m_image.cacheKey())
    {
        m_image = image;
    }
}

void TTKScanLabel::setImageRadius(int imageRadius)
{
    if(imageRadius != m_imageRadius)
    {
        m_imageRadius = imageRadius;
    }
}

void TTKScanLabel::setImageBorderWidth(int imageBorderWidth)
{
    if(imageBorderWidth != m_imageBorderWidth)
    {
        m_imageBorderWidth = imageBorderWidth;
    }
}

void TTKScanLabel::setImageBorderColor(const QColor &imageBorderColor)
{
    if(imageBorderColor != m_imageBorderColor)
    {
        m_imageBorderColor = imageBorderColor;
    }
}

void TTKScanLabel::setScanRadius(int scanRadius)
{
    if(scanRadius != m_scanRadius)
    {
        m_scanRadius = scanRadius;
    }
}

void TTKScanLabel::setScanWidth(int scanWidth)
{
    if(scanWidth != m_scanWidth)
    {
        m_scanWidth = scanWidth;
    }
}

void TTKScanLabel::setScanColor(const QColor &scanColor)
{
    if(scanColor != m_scanColor)
    {
        m_scanColor = scanColor;
    }
}

void TTKScanLabel::setRingRadius(int ringRadius)
{
    if(ringRadius != m_ringRadius)
    {
        m_ringRadius = ringRadius;
    }
}

void TTKScanLabel::setRingWidth(int ringWidth)
{
    if(ringWidth != m_ringWidth)
    {
        m_ringWidth = ringWidth;
    }
}

void TTKScanLabel::setRingColor(const QColor &ringColor)
{
    if(ringColor != m_ringColor)
    {
        m_ringColor = ringColor;
    }
}

QSize TTKScanLabel::sizeHint() const
{
    return QSize(180, 180);
}

void TTKScanLabel::updateRender()
{
    for(int i = 0; i < m_rings.count(); i++)
    {
        RingData *ring = &m_rings[i];
        ring->m_radius += 1;
        ring->m_alpha += 5;
        if(ring->m_alpha < 0)
        {
            ring->m_alpha = 0;
        }

        ring->m_width -= 0.05;
        if(ring->m_width < 0)
        {
            ring->m_width = 0;
        }
    }
    m_scanDeg -= 3;
    update();
}

void TTKScanLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_rings.push_back({m_ringRadius, m_ringWidth, 10});
}

void TTKScanLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawScan(&painter);
    drawRing(&painter);
    drawImage(&painter);
}

void TTKScanLabel::drawScan(QPainter *painter)
{
    painter->save();

    QConicalGradient conicalGradient(0, 0, m_scanDeg);

    QColor color = m_scanColor;
    color.setAlpha(50);
    conicalGradient.setColorAt(0, color);
    color.setAlpha(0);
    conicalGradient.setColorAt(1, color);

    QPen pen;
    pen.setWidth(m_scanWidth);
    pen.setBrush(conicalGradient);
    painter->setPen(pen);
    painter->setBrush(conicalGradient);

    QRect rect(-m_scanRadius, -m_scanRadius, m_scanRadius * 2, m_scanRadius * 2);
    painter->drawPie(rect, m_scanDeg * 16, 360 * 16);
    painter->restore();
}

void TTKScanLabel::drawRing(QPainter *painter)
{
    painter->save();
    painter->setBrush(Qt::NoBrush);

    for(int i = 0; i < m_rings.count(); i++)
    {
        const RingData &ring = m_rings.at(i);
        const int radius = ring.m_radius;
        const float width = ring.m_width;
        int alpha = 255 - ring.m_alpha;
        if(alpha < 0)
        {
            alpha = 0;
        }

        QColor color = m_ringColor;
        color.setAlpha(alpha);

        QPen pen;
        pen.setWidthF(width);
        pen.setColor(color);
        painter->setPen(pen);
        painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    }
    painter->restore();
}

void TTKScanLabel::drawImage(QPainter *painter)
{
    painter->save();

    QPainterPath path;
    path.addEllipse(QPoint(0, 0), m_imageRadius, m_imageRadius);
    painter->setClipPath(path);

    QRect rect(-m_imageRadius, -m_imageRadius, m_imageRadius * 2, m_imageRadius * 2);
    painter->drawPixmap(rect, m_image);

    QPen pen;
    pen.setWidth(m_imageBorderWidth);
    pen.setColor(m_imageBorderColor);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    painter->drawEllipse(rect);
    painter->restore();
}
