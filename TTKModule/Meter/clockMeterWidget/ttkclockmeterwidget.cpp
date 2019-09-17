#include "ttkclockmeterwidget.h"
#include "qmath.h"

#include <QTime>
#include <QTimer>
#include <QPainter>

TTKClockMeterWidget::TTKClockMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_crownColorStart = QColor(255, 255, 255);
    m_crownColorEnd = QColor(166, 166, 166);

    m_foreground = QColor(255, 255, 255);
    m_background = QColor(65, 65, 65);

    m_pointerHourColor = QColor(160, 160, 160);
    m_pointerMinColor = QColor(160, 160, 160);
    m_pointerSecColor = QColor(160, 160, 160);

    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    m_timer->start();

    m_timerSpring = new QTimer(this);
    m_timerSpring->setInterval(30);
    connect(m_timerSpring, SIGNAL(timeout()), this, SLOT(updateSpring()));
    m_angleSpring = 6.0 * (m_sec + m_msec / 1000);

    setSecondStyle(SecondStyleNormal);
    updateTime();

    setFont(QFont("Arial", 9));
}

TTKClockMeterWidget::~TTKClockMeterWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }

    if(m_timerSpring->isActive())
    {
        m_timerSpring->stop();
    }
}

void TTKClockMeterWidget::setCrownColorStart(const QColor &crownColorStart)
{
    if(m_crownColorStart != crownColorStart)
    {
        m_crownColorStart = crownColorStart;
        update();
    }
}

void TTKClockMeterWidget::setCrownColorEnd(const QColor &crownColorEnd)
{
    if(m_crownColorEnd != crownColorEnd)
    {
        m_crownColorEnd = crownColorEnd;
        update();
    }
}

void TTKClockMeterWidget::setForeground(const QColor &foreground)
{
    if(m_foreground != foreground)
    {
        m_foreground = foreground;
        update();
    }
}

void TTKClockMeterWidget::setBackground(const QColor &background)
{
    if(m_background != background)
    {
        m_background = background;
        update();
    }
}

void TTKClockMeterWidget::setPointerHourColor(const QColor &pointerHourColor)
{
    if(m_pointerHourColor != pointerHourColor)
    {
        m_pointerHourColor = pointerHourColor;
        update();
    }
}

void TTKClockMeterWidget::setPointerMinColor(const QColor &pointerMinColor)
{
    if(m_pointerMinColor != pointerMinColor)
    {
        m_pointerMinColor = pointerMinColor;
        update();
    }
}

void TTKClockMeterWidget::setPointerSecColor(const QColor &pointerSecColor)
{
    if(m_pointerSecColor != pointerSecColor)
    {
        m_pointerSecColor = pointerSecColor;
        update();
    }
}

void TTKClockMeterWidget::setSecondStyle(TTKClockMeterWidget::SecondStyle secondStyle)
{
    m_secondStyle = secondStyle;

    if(secondStyle == SecondStyleContinue)
    {
        m_timer->setInterval(100);
    }
    else
    {
        m_timer->setInterval(1000);
    }

    updateTime();
}

QSize TTKClockMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKClockMeterWidget::updateTime()
{
    QTime now = QTime::currentTime();
    m_hour = now.hour();
    m_min = now.minute();
    m_sec = now.second();
    m_msec = now.msec();

    if(m_secondStyle != SecondStyleHide)
    {
        m_angleSpring = 6.0 * (m_sec + m_msec / 1000);
        if(m_secondStyle == SecondStyleSpring)
        {
            m_angleSpring += 5;
            m_timerSpring->start();
        }
    }
    update();
}

void TTKClockMeterWidget::updateSpring()
{
    m_angleSpring = 6.0 * (m_sec + m_msec / 1000);
    update();
    m_timerSpring->stop();
}

void TTKClockMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawCrown(&painter);
    drawBg(&painter);
    drawScale(&painter);
    drawScaleNum(&painter);
    drawHour(&painter);
    drawMin(&painter);
    drawSec(&painter);
    drawDot(&painter);
}

void TTKClockMeterWidget::drawCrown(QPainter *painter)
{
    const int radius = 99;
    painter->save();
    painter->setPen(Qt::NoPen);

    QLinearGradient crownGradient(0, -radius, 0, radius);
    crownGradient.setColorAt(0, m_crownColorStart);
    crownGradient.setColorAt(1, m_crownColorEnd);

    painter->setBrush(crownGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKClockMeterWidget::drawBg(QPainter *painter)
{
    const int radius = 92;

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_background);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void TTKClockMeterWidget::drawScale(QPainter *painter)
{
    const int radius = 90;
    painter->save();
    painter->setPen(m_foreground);

    QPen pen = painter->pen();
    pen.setCapStyle(Qt::RoundCap);

    for(int i = 0; i <= 60; i++)
    {
        if(i % 5 == 0)
        {
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 10, 0, radius);
        }
        else
        {
            pen.setWidthF(0.5);
            painter->setPen(pen);
            painter->drawLine(0, radius - 5, 0, radius);
        }
        painter->rotate(6);
    }
    painter->restore();
}

void TTKClockMeterWidget::drawScaleNum(QPainter *painter)
{
    const int radius = 70;
    painter->save();
    painter->setPen(m_foreground);

    const double startRad = 60 * (M_PI / 180);
    const double deltaRad = 30 * (M_PI / 180);

    for(int i = 0; i < 12; i++)
    {
        const double sina = sin(startRad - i * deltaRad);
        const double cosa = cos(startRad - i * deltaRad);
        const QString &strValue = QString("%1").arg(i + 1);

        const double textWidth = fontMetrics().width(strValue);
        const double textHeight = fontMetrics().height();
        const int x = radius * cosa - textWidth / 2;
        const int y = -radius * sina + textHeight / 4;
        painter->drawText(x, y, strValue);
    }
    painter->restore();
}

void TTKClockMeterWidget::drawHour(QPainter *painter)
{
    painter->save();

    QPolygon pts;
    pts.setPoints(4, -3, 8, 3, 8, 2, -40, -2, -40);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::RoundCap);

    painter->rotate(30.0 * ((m_hour + m_min / 60.0)));
    painter->setPen(m_pointerHourColor);
    painter->setBrush(m_pointerHourColor);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKClockMeterWidget::drawMin(QPainter *painter)
{
    painter->save();

    QPolygon pts;
    pts.setPoints(4, -2, 8, 2, 8, 1, -60, -1, -60);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::RoundCap);

    painter->rotate(6.0 * (m_min + m_sec / 60.0));
    painter->setPen(m_pointerMinColor);
    painter->setBrush(m_pointerMinColor);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKClockMeterWidget::drawSec(QPainter *painter)
{
    if(m_secondStyle == SecondStyleHide)
    {
        return;
    }

    painter->save();

    QPolygon pts;
    pts.setPoints(3, -1, 10, 1, 10, 0, -70);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::RoundCap);

    painter->rotate(m_angleSpring);
    painter->setPen(m_pointerSecColor);
    painter->setBrush(m_pointerSecColor);
    painter->drawConvexPolygon(pts);
    painter->restore();
}

void TTKClockMeterWidget::drawDot(QPainter *painter)
{
    painter->save();

    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, m_background);
    coneGradient.setColorAt(0.5, m_foreground);
    coneGradient.setColorAt(1.0, m_background);

    painter->setOpacity(0.9);
    painter->setPen(Qt::NoPen);
    painter->setBrush(coneGradient);
    painter->drawEllipse(-5, -5, 10, 10);
    painter->restore();
}
