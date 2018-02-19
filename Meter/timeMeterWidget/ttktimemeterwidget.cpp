#include "ttktimemeterwidget.h"

#include <QTimer>
#include <QPainter>

TTKTimeMeterWidget::TTKTimeMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_background = Qt::black;
    m_foreground = Qt::green;
    m_startAngle = 60;
    m_endAngle = 60;
    m_scaleMajor = 10;
    m_minValue = 0;
    m_maxValue = 100;
    m_scaleMajor = 10;
    m_scaleMinor = 10;
    m_units = "km/h";
    m_title = "Speed Meter";
    m_precision = 0;
    m_value = 0;
}

void TTKTimeMeterWidget::setValue(qreal value)
{
    m_value = value;
    update();
}

void TTKTimeMeterWidget::drawCrown(QPainter *painter)
{
    painter->save();

    int radius = 100;
    QLinearGradient linearGradient(0, -radius, 0, radius);
    linearGradient.setColorAt(0, Qt::white);
    linearGradient.setColorAt(1, Qt::gray);

    painter->setBrush(linearGradient);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(-radius, -radius, radius << 1, radius << 1);
    painter->setBrush(m_background = Qt::black);
    painter->drawEllipse(-92, -92, 184, 184);
    painter->restore();
}

void TTKTimeMeterWidget::drawScale(QPainter *painter)
{
    painter->save();
    painter->rotate(m_startAngle);

    int steps = (m_scaleMajor * m_scaleMinor);
    double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;

    QPen pen ;
    pen.setColor(Qt::green);
    for(int i=0; i<=steps; i++)
    {
        if(i % m_scaleMinor == 0)
        {
            pen.setWidth(1);
            painter->setPen(pen);
            painter->drawLine(0, 62, 0, 72);
        }
        else
        {
           pen.setWidth(0);
           painter->setPen(pen);
           painter->drawLine(0, 67, 0, 72);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void TTKTimeMeterWidget::drawScaleNum(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);

    double startRad = ( 270-m_startAngle) * (3.14 / 180);
    double deltaRad = (360 - m_startAngle - m_endAngle) * (3.14 / 180) / m_scaleMajor;
    double sina,cosa;
    int x, y;

    QFontMetricsF fm(this->font());
    double w, h, v;
    QString str;

    for(int i=0; i<=m_scaleMajor; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

        v = 1.0 * i *((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
        str = QString::number(v);
        w = fm.size(Qt::TextSingleLine, str).width();
        h = fm.size(Qt::TextSingleLine, str).height();
        x = 82 * cosa - w / 2;
        y = -82 * sina + h / 4;
        painter->drawText(x, y, str);
    }
    painter->restore();
}

void TTKTimeMeterWidget::drawTitle(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);

    QString str(m_title);
    QFontMetricsF fm(this->font());
    double w = fm.size(Qt::TextSingleLine, str).width();
    painter->drawText(-w / 2, -30, str);
    painter->restore();
}

void TTKTimeMeterWidget::drawNumericValue(QPainter *painter)
{
    QString str = QString("%1 %2").arg(m_value, 0, 'f', m_precision).arg(m_units);
    QFontMetricsF fm(font());
    double w = fm.size(Qt::TextSingleLine, str).width();
    painter->setPen(m_foreground);
    painter->drawText(-w / 2, 42, str);
}

void TTKTimeMeterWidget::drawIndicator(QPainter *painter)
{
    painter->save();

    QPolygon pts;
    pts.setPoints(3, -2, 0, 2, 0, 0, 60);

    painter->rotate(m_startAngle);
    double degRotate =  (360.0 - m_startAngle - m_endAngle)/(m_maxValue - m_minValue)*(m_value - m_minValue);

    painter->rotate(degRotate);
    QRadialGradient haloGradient(0, 0, 60, 0, 0);
    haloGradient.setColorAt(0, QColor(60, 60, 60));
    haloGradient.setColorAt(1, QColor(160, 160, 160));
    painter->setPen(Qt::white);
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon(pts);
    painter->restore();

    QColor niceBlue(150, 150, 200);
    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, Qt::darkGray);
    coneGradient.setColorAt(0.2, niceBlue);
    coneGradient.setColorAt(0.5, Qt::white);
    coneGradient.setColorAt(1.0, Qt::darkGray);
    painter->setPen(Qt::NoPen);
    painter->setBrush(coneGradient);
    painter->drawEllipse(-5, -5, 10, 10);
}

void TTKTimeMeterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    int side = qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);

    drawCrown(&painter);
    drawScaleNum(&painter);
    drawScale(&painter);
    drawTitle(&painter);
    drawNumericValue(&painter);
    drawIndicator(&painter);
}
