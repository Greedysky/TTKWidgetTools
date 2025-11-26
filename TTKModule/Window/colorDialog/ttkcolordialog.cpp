#include "ttkcolordialog.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>

TTKHlPalette::TTKHlPalette(QWidget *parent)
    : QWidget(parent),
      m_dblSaturation(1.0)
{
    setMouseTracking(true);
    setMinimumSize(QSize(360, 120));
}

QColor TTKHlPalette::color() const
{
    return m_color;
}

void TTKHlPalette::setColor(const QColor &color)
{
    m_color = color;
#if TTK_QT_VERSION_CHECK(6,0,0)
    float vh, vs, vl = -100.0f;
#else
    qreal vh, vs, vl = -100.0f;
#endif
    m_color.getHslF(&vh, &vs, &vl);
    m_dblSaturation = vs;
    m_ptfVernierPercentPos.setX(vh);
    m_ptfVernierPercentPos.setY(1 - vl);
    Q_EMIT colorChanged(m_color);
}

void TTKHlPalette::initialize()
{
    m_ptVernierPos = rect().center();
    calculateColor();
    update();
}

void TTKHlPalette::setSaturation(double dblsaturation)
{
    m_dblSaturation = dblsaturation;
    calculateColor();
    update();
}

void TTKHlPalette::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::NoBrush);

    const int ntRight = rect().right();
    const int ntBottm = rect().bottom();
    QColor colorStart, colorDatum, colorFinal;

    for(int it = 0; it < ntRight + 1; ++it)
    {
        colorStart.setHslF(it / double(ntRight), m_dblSaturation, 1);
        colorDatum.setHslF(it / double(ntRight), m_dblSaturation, 0.5);
        colorFinal.setHslF(it / double(ntRight), m_dblSaturation, 0);

        QLinearGradient linearGradient;
        linearGradient.setStart(QPointF(it, 0));
        linearGradient.setFinalStop(QPointF(it, ntBottm));
        linearGradient.setColorAt(0.0, colorStart);
        linearGradient.setColorAt(0.5, colorDatum);
        linearGradient.setColorAt(1.0, colorFinal);

        painter.setPen(QPen(linearGradient, 1));
        painter.drawLine(QPointF(it, 0), QPointF(it, ntBottm));
    }

    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(m_ptVernierPos, 5, 5);

    painter.setPen(QPen(Qt::white, 2));
    painter.drawEllipse(m_ptVernierPos, 7, 7);
}

void TTKHlPalette::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_ptVernierPos.setX(rect().right() * m_ptfVernierPercentPos.rx());
    m_ptVernierPos.setY(rect().bottom() * m_ptfVernierPercentPos.ry());
    update();
}

void TTKHlPalette::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_ptVernierPos = event->pos();
        calculateColor();
        update();
    }
}

void TTKHlPalette::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton && !(event->buttons() & Qt::RightButton))
    {
        m_ptVernierPos = event->pos();
        if(rect().contains(m_ptVernierPos))
        {
            calculateColor();
            update();
        }
    }
    else
    {
        QPainterPath path;
        path.addEllipse(m_ptVernierPos, 7, 7);
    }
}

void TTKHlPalette::calculateColor()
{
    m_ptfVernierPercentPos.setX(m_ptVernierPos.x() / double(rect().right()));
    m_ptfVernierPercentPos.setY(m_ptVernierPos.y() / double(rect().bottom()));
    m_color.setHslF(m_ptfVernierPercentPos.rx(), m_dblSaturation, 1 - m_ptfVernierPercentPos.ry());
    Q_EMIT colorChanged(m_color);
}



TTKHlSaturationPalette::TTKHlSaturationPalette(QWidget *parent)
    : QWidget(parent),
      m_color(Qt::red),
      m_dblVernierX(0),
      m_dblVernierPercentX(0),
      m_dblSaturation(0)
{
    setMouseTracking(true);
    setMinimumWidth(360);
    setMinimumHeight(16);
    setMaximumHeight(24);
}

double TTKHlSaturationPalette::saturation() const
{
    return m_dblSaturation;
}

void TTKHlSaturationPalette::setSaturation(double dblsaturation)
{
    m_dblSaturation = dblsaturation;
    m_dblVernierPercentX = 1 - m_dblSaturation;
    m_dblVernierX = m_dblVernierPercentX * rect().right();
}

void TTKHlSaturationPalette::setBaseColor(const QColor &color)
{
    m_color = color;
    update();
}

void TTKHlSaturationPalette::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::NoBrush);

    const int ntRight = rect().right();
    const int ntBottm = rect().bottom();

#if TTK_QT_VERSION_CHECK(6,0,0)
    float vh, vs, vl = -100.0f;
#else
    qreal vh, vs, vl = -100.0f;
#endif
    m_color.getHslF(&vh, &vs, &vl);

    QColor colorCenter, colorStart, colorFinal;
    colorCenter.setHslF(vh, 0.5, vl);
    colorStart.setHslF(vh, 1, vl);
    colorFinal.setHslF(vh, 0, vl);

    QLinearGradient linearGradient;
    linearGradient.setStart(QPointF(0, 0));
    linearGradient.setFinalStop(QPointF(ntRight, 0));
    linearGradient.setColorAt(0.0, colorStart);
    linearGradient.setColorAt(1.0, colorFinal);

    painter.fillRect(rect(), linearGradient);

    const QPointF ptfCenter(m_dblVernierX, ntBottm/2.0);
    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(ptfCenter, 5, 5);

    painter.setPen(QPen(Qt::white, 2));
    painter.drawEllipse(ptfCenter, 7, 7);
}

void TTKHlSaturationPalette::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_dblVernierX = rect().right() * m_dblVernierPercentX;
    update();
}

void TTKHlSaturationPalette::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_dblVernierX = QtPositionX(event);
        calculateSuration();
        update();
    }
}

void TTKHlSaturationPalette::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton && !(event->buttons() & Qt::RightButton))
    {
        m_dblVernierX = QtPositionX(event);
        if(rect().contains(event->pos()))
        {
            calculateSuration();
            update();
        }
    }
    else
    {
        QPainterPath path;
        path.addEllipse(QPointF(m_dblVernierX, rect().bottom() / 2.0), 7, 7);
    }
}

void TTKHlSaturationPalette::calculateSuration()
{
    m_dblVernierPercentX = m_dblVernierX/rect().right();
    m_dblSaturation = 1 - m_dblVernierPercentX;
    m_color.setHslF(m_color.hslHueF(), m_dblSaturation, m_color.lightnessF());
    Q_EMIT saturationChanged(m_dblSaturation);
}
