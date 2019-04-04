#include "ttkprogresscirclewidget.h"

#include <QPainter>
#include <QPixmapCache>
#include <QPropertyAnimation>

TTKProgressCircleWidget::TTKProgressCircleWidget(QWidget *parent)
    : QWidget(parent)
{
    m_color = QColor(110,190,235);
    m_value = 0;
    m_maximum= 0;
    m_visibleValue = 0;
    m_innerRadius = 0.6f;
    m_outerRadius= 1.0f;
    m_infiniteAnimationValue = 0.0f;

    m_valueAnimation = new QPropertyAnimation(this, "visibleValue");
    m_infiniteAnimation = new QPropertyAnimation(this, "infiniteAnimationValue");

    m_infiniteAnimation->setLoopCount(-1);
    m_infiniteAnimation->setDuration(1000);
    m_infiniteAnimation->setStartValue(0.0);
    m_infiniteAnimation->setEndValue(1.0);
    m_infiniteAnimation->start();
}

TTKProgressCircleWidget::~TTKProgressCircleWidget()
{
    delete m_valueAnimation;
    delete m_infiniteAnimation;
}

int TTKProgressCircleWidget::value() const
{
    return m_value;
}

int TTKProgressCircleWidget::maximum() const
{
    return m_maximum;
}

qreal TTKProgressCircleWidget::innerRadius() const
{
    return m_innerRadius;
}

qreal TTKProgressCircleWidget::outerRadius() const
{
    return m_outerRadius;
}

QColor TTKProgressCircleWidget::color() const
{
    return m_color;
}

void TTKProgressCircleWidget::setValue(int value)
{
    if(value < 0)
    {
        value = 0;
    }

    if(m_value != value)
    {
        m_valueAnimation->stop();
        m_valueAnimation->setEndValue(value);
        m_valueAnimation->setDuration(250);
        m_valueAnimation->start();

        m_value = value;
        emit valueChanged(value);
    }
}

void TTKProgressCircleWidget::setMaximum(int maximum)
{
    if(maximum < 0)
    {
        maximum = 0;
    }

    if(m_maximum != maximum)
    {
        m_maximum = maximum;
        update();
        emit maximumChanged(maximum);

        if(m_maximum == 0)
        {
            m_infiniteAnimation->start();
        }
        else
        {
            m_infiniteAnimation->stop();
        }
    }
}

void TTKProgressCircleWidget::setInnerRadius(qreal innerRadius)
{
    if(innerRadius > 1.0)
    {
        innerRadius = 1.0;
    }
    else if(innerRadius < 0.0)
    {
        innerRadius = 0.0;
    }

    if(m_innerRadius != innerRadius)
    {
        m_innerRadius = innerRadius;
        update();
    }
}

void TTKProgressCircleWidget::setOuterRadius(qreal outerRadius)
{
    if(outerRadius > 1.0)
    {
        outerRadius = 1.0;
    }
    else if(outerRadius < 0.0)
    {
        outerRadius = 0.0;
    }

    if(m_outerRadius != outerRadius)
    {
        m_outerRadius = outerRadius;
        update();
    }
}

void TTKProgressCircleWidget::setColor(const QColor &color)
{
    if(color != m_color)
    {
        m_color = color;
        update();
    }
}

QRectF squared(QRectF rect)
{
    if(rect.width() > rect.height())
    {
        qreal diff = rect.width() - rect.height();
        return rect.adjusted(diff/2, 0, -diff/2, 0);
    }
    else
    {
        qreal diff = rect.height() - rect.width();
        return rect.adjusted(0, diff/2, 0, -diff/2);
    }
}

void TTKProgressCircleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPixmap pixmap;
    if(!QPixmapCache::find(key(), pixmap))
    {
        pixmap = generatePixmap();
        QPixmapCache::insert(key(), pixmap);
    }

    QPainter painter(this);
    painter.drawPixmap( 0.5 * ( width() - pixmap.width() ), 0.5 * ( height() - pixmap.height() ), pixmap );
}

void TTKProgressCircleWidget::setInfiniteAnimationValue(qreal value)
{
    m_infiniteAnimationValue = value;
    update();
}

void TTKProgressCircleWidget::setVisibleValue(int value)
{
    if(m_visibleValue != value)
    {
        m_visibleValue = value;
        update();
    }
}

QString TTKProgressCircleWidget::key() const
{
    return QString("%1,%2,%3,%4,%5,%6,%7,%8")
            .arg(m_infiniteAnimationValue)
            .arg(m_visibleValue)
            .arg(m_maximum)
            .arg(m_innerRadius)
            .arg(m_outerRadius)
            .arg(width())
            .arg(height())
            .arg(m_color.rgb())
            ;
}

QPixmap TTKProgressCircleWidget::generatePixmap() const
{
    QPixmap pixmap(squared(rect()).size().toSize());
    pixmap.fill(QColor(0,0,0,0));
    QPainter painter(&pixmap);

    painter.setRenderHint(QPainter::Antialiasing, true);

    QRectF rect = pixmap.rect().adjusted(1,1,-1,-1);
    qreal margin = rect.width()*(1.0 - m_outerRadius)/2.0;
    rect.adjust(margin,margin,-margin,-margin);
    qreal innerRadius = m_innerRadius*rect.width()/2.0;

    painter.setBrush(QColor(225, 225, 225));
    painter.setPen(QColor(225, 225, 225));
    painter.drawPie(rect, 0, 360*16);

    painter.setBrush(m_color);
    painter.setPen(m_color);

    if(m_maximum == 0)
    {
        int startAngle = -m_infiniteAnimationValue * 360 * 16;
        int spanAngle = 0.15 * 360 * 16;
        painter.drawPie(rect, startAngle, spanAngle);
    }
    else
    {
        int value = qMin(m_visibleValue, m_maximum);
        int startAngle = 90 * 16;
        int spanAngle = -qreal(value) * 360 * 16 / m_maximum;

        painter.drawPie(rect, startAngle, spanAngle);
    }

    painter.setBrush(QColor(255,255,255));
    painter.setPen(QColor(0,0,0, 60));
    painter.drawEllipse(rect.center(), innerRadius, innerRadius);

    painter.drawArc(rect, 0, 360*16);

    return pixmap;
}

qreal TTKProgressCircleWidget::infiniteAnimationValue() const
{
    return m_infiniteAnimationValue;
}

int TTKProgressCircleWidget::visibleValue() const
{
    return m_visibleValue;
}
