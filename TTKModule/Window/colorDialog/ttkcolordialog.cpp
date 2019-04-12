#include "ttkcolordialog.h"

#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

TTKHlPalette::TTKHlPalette(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(QSize(360, 120));
    setMouseTracking(true);

    m_dblSaturation = 1.0;
}

QColor TTKHlPalette::color() const
{
    return m_color;
}

void TTKHlPalette::init()
{
    m_ptVernierPos = rect().center();
    calculateColor();
    update();
}

void TTKHlPalette::setSaturation(double dblsaturation)
{
    m_dblSaturation = dblsaturation;
    update();
    calculateColor();
}

void TTKHlPalette::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::NoBrush);

    int ntRight = rect().right();
    int ntBottm = rect().bottom();
    QColor colorStart, colorDatum, colorFinal;
    for(int it=0; it< ntRight + 1; it++)
    {
        colorStart.setHslF(it/double(ntRight), m_dblSaturation, 1);
        colorDatum.setHslF(it/double(ntRight), m_dblSaturation, 0.5);
        colorFinal.setHslF(it/double(ntRight), m_dblSaturation, 0);

        QLinearGradient linearGradient;
        linearGradient.setStart(QPointF(it, 0));
        linearGradient.setFinalStop(QPointF(it, ntBottm));
        linearGradient.setColorAt(0.0, colorStart);
        linearGradient.setColorAt(0.5, colorDatum);
        linearGradient.setColorAt(1.0, colorFinal);

        QBrush brush(linearGradient);
        painter.setPen(QPen(brush, 1));
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
        if(path.contains(event->pos()))
        {
            QToolTip::showText(mapToGlobal(event->pos()) + QPoint(0, 5), tr("Adjust Hue And Brightness"), this,
                               QRect(m_ptVernierPos - QPoint(8, 8), QSize(16, 16)));
        }
    }
}

void TTKHlPalette::calculateColor()
{
    m_ptfVernierPercentPos.setX(m_ptVernierPos.x()/double(rect().right()));
    m_ptfVernierPercentPos.setY(m_ptVernierPos.y()/double(rect().bottom()));
    m_color.setHslF(m_ptfVernierPercentPos.rx(), m_dblSaturation, 1 - m_ptfVernierPercentPos.ry());
    emit colorChanged(m_color);
}



TTKHlSaturationPalette::TTKHlSaturationPalette(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    setMinimumWidth(360);
    setMinimumHeight(16);
    setMaximumHeight(24);

    m_color = Qt::red;
    m_dblVernierX = 0;
    m_dblVernierPercentX = 0;
    m_dblSaturation = 0;
}

double TTKHlSaturationPalette::saturation() const
{
    return m_dblSaturation;
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
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::NoBrush);

    int ntRight = rect().right();
    int ntBottm = rect().bottom();

    double dblVH, dblVS, dblVL = -100.0;
    m_color.getHslF(&dblVH, &dblVS, &dblVL);
    QColor colorCenter; colorCenter.setHslF(dblVH, 0.5, dblVL);
    QColor colorStart;  colorStart.setHslF(dblVH, 1, dblVL);
    QColor colorFinal;  colorFinal.setHslF(dblVH, 0, dblVL);

    QLinearGradient linearGradient;
    linearGradient.setStart(QPointF(0, 0));
    linearGradient.setFinalStop(QPointF(ntRight, 0));
    linearGradient.setColorAt(0.0, colorStart);
    linearGradient.setColorAt(1.0, colorFinal);

    QBrush brush(linearGradient);
    painter.fillRect(rect(), brush);

    QPointF ptfCenter(m_dblVernierX, ntBottm/2.0);
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
        m_dblVernierX = event->pos().x();
        calculateSuration();
        update();
    }
}

void TTKHlSaturationPalette::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton && !(event->buttons() & Qt::RightButton))
    {
        m_dblVernierX = event->pos().x();
        if(rect().contains(event->pos()))
        {
            calculateSuration();
            update();
        }
    }
    else
    {
        QPointF ptfCenter(m_dblVernierX, rect().bottom()/2.0);
        QPainterPath path;
        path.addEllipse(ptfCenter, 7, 7);
        if(path.contains(event->pos()))
        {
            QToolTip::showText(mapToGlobal(event->pos()) + QPoint(0, 5), tr("Adjust Hue And Brightness"), this,
                               QRect(event->pos() - QPoint(8, 8), QSize(16, 16)));
        }
    }
}

void TTKHlSaturationPalette::calculateSuration()
{
    m_dblVernierPercentX = m_dblVernierX/rect().right();
    m_dblSaturation = 1- m_dblVernierPercentX;
    m_color.setHslF(m_color.hslHueF(), m_dblSaturation, m_color.lightnessF());

    emit saturationChanged(m_dblSaturation);
}
