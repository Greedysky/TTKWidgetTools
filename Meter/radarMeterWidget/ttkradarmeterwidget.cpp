#include "ttkradarmeterwidget.h"

#include <QPainter>
#include <QTimerEvent>

TTKRadarMeterWidget::TTKRadarMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    m_pieRotate = 0;
    m_timerId = -1;
    m_nSpeed = 50;

    for(int i=0; i<5; ++i)
    {
        m_points << QPoint();
        m_pointsAlapha << 100;
    }

    m_timerId = startTimer(m_nSpeed);
    m_pointTimerId = startTimer(1200);
}

void TTKRadarMeterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor(15, 45, 188));

    int len = m_drawArea.width();
    painter.setPen(QPen(Qt::white));
    painter.drawLine(m_drawArea.topLeft() + QPoint(0, len/2), m_drawArea.topRight() + QPoint(0, len/2));
    painter.drawLine(m_drawArea.topLeft() + QPoint(len/2, 0), m_drawArea.bottomLeft() + QPoint(len/2, 0));
    painter.drawEllipse(m_drawArea.center(), len/2, len/2);
    painter.drawEllipse(m_drawArea.center(), len/3, len/3);
    painter.drawEllipse(m_drawArea.center(), len/6, len/6);

    qreal x = m_drawArea.center().x() + (qreal)len/2 * cos(-m_pieRotate*3.14159/180);
    qreal y = m_drawArea.center().y() + (qreal)len/2 * sin(-m_pieRotate*3.14159/180);
    painter.setPen(QPen(Qt::white));
    painter.drawLine(m_drawArea.center(),QPointF(x,y));

    QConicalGradient gradient;
    gradient.setCenter(m_drawArea.center());
    gradient.setAngle(m_pieRotate + 180);
    gradient.setColorAt(0.4, QColor(255, 255, 255, 100));
    gradient.setColorAt(0.8, QColor(255, 255, 255, 0));
    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    painter.drawPie(m_drawArea, m_pieRotate*16, 90*16);

    for(int i=0; i<m_points.count(); ++i)
    {
        int colorAlaph = m_pointsAlapha.at(i);
        painter.setPen(QPen(QColor(255, 255, 255, colorAlaph), 3));
        painter.drawPoint(m_points.at(i));
    }
}

void TTKRadarMeterWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if(width() > height())
    {
        m_drawArea = QRect((width() - height())/2, 0, height(), height());
    }
    else
    {
        m_drawArea = QRect(0, (height() - width())/2, width(), width());
    }
    m_drawArea.adjust(10, 10, -10, -10);
}

void TTKRadarMeterWidget::timerEvent(QTimerEvent *event)
{
    QWidget::timerEvent(event);

    if(m_timerId == event->timerId())
    {
        m_pieRotate -= 10;
        update();
    }
    else if(m_pointTimerId == event->timerId())
    {
        for(int i=0; i<m_points.count(); ++i)
        {
            int offsetX = rand()%m_drawArea.width();
            int offsetY = rand()%m_drawArea.width();
            int alapha = rand()%255;
            m_points.replace(i, QPoint(offsetX, offsetY) + m_drawArea.topLeft());
            m_pointsAlapha.replace(i, alapha);
        }
        update();
    }
}
