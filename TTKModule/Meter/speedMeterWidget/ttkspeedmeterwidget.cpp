#include "ttkspeedmeterwidget.h"

#include <QTimer>
#include <QPainter>

#define S_LONG      10
#define S_SPAOK     7
#define S_SHORT     5
#define S_SPACE     3

TTKSpeedMeterWidget::TTKSpeedMeterWidget(QWidget *parent)
    : QWidget(parent)
{
    initialize();
}

void TTKSpeedMeterWidget::setValue(qreal value)
{
    if(value == m_value)
    {
        return;
    }

    m_bReverse = (value < m_value);
    m_value = value/m_ratio;
    if(!m_bAnimating)
    {
        m_currentValue = m_value;
    }
    m_updateTimer->start();
    update();
}

void TTKSpeedMeterWidget::setRatio(qreal value)
{
    m_ratio = value;
    update();
}

void TTKSpeedMeterWidget::setAnimating(bool enable)
{
    m_bAnimating = enable;
    update();
}

QSize TTKSpeedMeterWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKSpeedMeterWidget::updateRender()
{
    if(m_bReverse)
    {
        m_currentValue -= 0.5;
        if(m_currentValue <= m_value)
        {
            m_updateTimer->stop();
        }
    }
    else
    {
        m_currentValue += 0.5;
        if(m_currentValue >= m_value)
        {
            m_updateTimer->stop();
        }
    }
    update();
}

void TTKSpeedMeterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    resetVariables();
    drawOuterCircle(&painter);
    drawInnerCircle(&painter);
    drawColorPie(&painter);
    drawCoverCircle(&painter);
    drawMark(&painter);
    drawIndicator(&painter);
    drawCoverBall(&painter);
    drawTextRect(&painter);
    painter.end();
}

void TTKSpeedMeterWidget::initialize()
{
    resetVariables();

    m_value = 0;
    m_currentValue = 0;
    m_ratio = 1;
    m_units = "km/h";

    m_updateTimer = new QTimer(this);
    m_updateTimer->setInterval(10);
    connect(m_updateTimer, SIGNAL(timeout()), SLOT(updateRender()));
    m_singleTimer = new QTimer(this);
    m_singleTimer->setInterval(100);
    connect(m_singleTimer, SIGNAL(timeout()), SLOT(update()));
    m_singleTimer->start();
}

void TTKSpeedMeterWidget::resetVariables()
{
    m_outerRadius = width()>height() ? height() / 2 : width() / 2;
    m_innerRadius = m_outerRadius / 8 * 7;
    m_coverCircleRadius = m_outerRadius / 8 * 4 + 10;
    m_colorCircleRadius = m_outerRadius / 8 * 5;
    m_center = rect().center();
}

void TTKSpeedMeterWidget::drawOuterCircle(QPainter *painter)
{
    painter->save();

    QRadialGradient outerGradient(m_center,  m_outerRadius, m_center);
    outerGradient.setColorAt(0.0, QColor(200, 200, 200));
    outerGradient.setColorAt(0.9, QColor(80, 80, 80));
    outerGradient.setColorAt(0.95, QColor(180, 180, 180));
    outerGradient.setColorAt(1.0, QColor(80, 80, 80));

    painter->setPen(Qt::NoPen);
    painter->setBrush(outerGradient);
    painter->drawEllipse(m_center, m_outerRadius, m_outerRadius);
    painter->restore();
}

void TTKSpeedMeterWidget::drawInnerCircle(QPainter *painter)
{
    painter->save();
    QRadialGradient innerGradient(m_center, m_innerRadius, m_center);
    innerGradient.setColorAt(0.0, QColor(130, 130, 130));
    innerGradient.setColorAt(0.7, QColor(130, 130, 130));
    innerGradient.setColorAt(1.0, QColor(80, 80, 80));
    painter->setPen(Qt::NoPen);
    painter->setBrush(innerGradient);
    painter->drawEllipse(m_center, m_innerRadius, m_innerRadius);

    painter->restore();
}

void TTKSpeedMeterWidget::drawMark(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::white);
    painter->translate(m_center);

    const qreal dAngle = (qreal)270 / 100;
    qreal startAngle = 45;
    int value = 0;
    QString strValue;

    for(int i = 0; i <= 100; ++i)
    {
        painter->save();
        painter->rotate(startAngle);
        if(i % 10 == 0)
        {
            strValue = QString::number(value);
#if TTK_QT_VERSION_CHECK(5,11,0)
            const int textWidth = fontMetrics().horizontalAdvance(strValue);
#else
            const int textWidth = fontMetrics().width(strValue);
#endif
            const qreal textHeight = fontMetrics().height();
            const QPointF bottomPot(0, m_colorCircleRadius + S_SPACE);
            const QPointF topPot(0, m_colorCircleRadius + S_SPACE + S_LONG);
            painter->drawLine(bottomPot, topPot);
            value += 10 * m_ratio;

            painter->save();
            const QPointF textPot(0 - textWidth / 2, m_colorCircleRadius + S_SPACE + S_LONG + S_SPACE + textHeight);
            painter->translate(textPot);
            painter->rotate(180);
            painter->drawText(QPointF(-textWidth, textHeight / 2), strValue);
            painter->restore();
        }
        else if(i % 5 == 0)
        {
            const QPointF bottomPot(0, m_colorCircleRadius + S_SPACE);
            const QPointF topPot(0, m_colorCircleRadius + S_SPACE + S_SPAOK);
            painter->drawLine(bottomPot, topPot);

        }
        else
        {
            const QPointF bottomPot(0, m_colorCircleRadius + S_SPACE);
            const QPointF topPot(0, m_colorCircleRadius + S_SPACE + S_SHORT);
            painter->drawLine(bottomPot, topPot);
        }
        painter->restore();
        startAngle += dAngle;
    }
    painter->restore();
}

void TTKSpeedMeterWidget::drawCoverBall(QPainter *painter)
{
    painter->save();

    const qreal ballRadius = m_outerRadius / 7;
    m_coverBallRadius = ballRadius;
    QRadialGradient ballGradient(m_center, ballRadius, m_center);
    ballGradient.setColorAt(0.0, QColor(140, 140, 140));
    ballGradient.setColorAt(0.7, QColor(140, 140, 140));
    ballGradient.setColorAt(1.0, QColor(60, 60, 60));
    painter->setBrush(ballGradient);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(m_center, ballRadius, ballRadius);

    painter->restore();
}

void TTKSpeedMeterWidget::drawTextRect(QPainter *painter)
{
    painter->save();
    const qreal rectWidth = m_coverCircleRadius/5;

    const QPointF topLeftPot(m_center.x() -2.5 * rectWidth, m_center.y()+rectWidth * 2);
    const QPointF bottomRightPot(topLeftPot.x() + 5 * rectWidth, topLeftPot.y()+rectWidth * 2);
    const QRectF textRect(topLeftPot, bottomRightPot);

    const qreal fontSize = textRect.height()/2;
    QFont font;
    font.setPointSize(fontSize);
    painter->setFont(font);

    painter->setOpacity(1.0);
    painter->setPen(Qt::black);
    painter->drawText(textRect, Qt::AlignCenter, QString("%1 %2").arg(m_value*m_ratio).arg(m_units));
    painter->restore();
}

void TTKSpeedMeterWidget::drawCoverCircle(QPainter *painter)
{
    painter->save();
    painter->setBrush(QColor(130, 130, 130));
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(m_center, m_coverCircleRadius, m_coverCircleRadius);
    painter->restore();
}

void TTKSpeedMeterWidget::drawColorPie(QPainter *painter)
{
    painter->save();

    const QPointF topLeftPot(m_center.x() - m_colorCircleRadius, m_center.y() - m_colorCircleRadius);
    const QPointF bottomRightPot(m_center.x() + m_colorCircleRadius, m_center.y() + m_colorCircleRadius);
    m_colorCircleRect = QRectF(topLeftPot, bottomRightPot);
    painter->setPen(Qt::NoPen);

    QConicalGradient greenGradient(m_center, m_innerRadius);
    greenGradient.setColorAt(0.0, QColor(0, 30, 0));
    greenGradient.setColorAt(0.25, QColor(0, 230, 0));
    greenGradient.setColorAt(1.0, QColor(0, 230, 0));
    painter->setBrush(Qt::green);
    painter->drawPie(m_colorCircleRect, 45 * 16, 180 * 16);

    painter->setBrush(QColor(218, 218, 0));
    painter->drawPie(m_colorCircleRect, 0 * 16, 45 * 16);

    painter->setBrush(QColor(240, 50, 50));
    painter->drawPie(m_colorCircleRect, 0, -45 * 16);

    painter->restore();
}

void TTKSpeedMeterWidget::drawIndicator(QPainter *painter)
{
    painter->save();

    painter->translate(m_center);
    const qreal increment = (qreal)270 / 100;
    const qreal changedAngle = 45 + increment*m_currentValue;
    painter->rotate(changedAngle);

    const QPointF topPot(0, m_colorCircleRadius + S_LONG);
    const QPointF bottomLeftPot(-m_coverBallRadius / 3, 0);
    const QPointF bottomRightPot(m_coverBallRadius / 3, 0);
    painter->setPen(Qt::NoPen);

    QLinearGradient indicatorGradient(topPot, bottomLeftPot);
    indicatorGradient.setColorAt(0.0, QColor(236, 187, 62));
    indicatorGradient.setColorAt(0.5, QColor(220, 147, 0));
    indicatorGradient.setColorAt(1.0, QColor(236, 187, 62));

    painter->setBrush(indicatorGradient);
    QVector<QPointF> potVec;
    potVec.push_back(topPot);
    potVec.push_back(bottomLeftPot);
    potVec.push_back(bottomRightPot);

    painter->drawPolygon(potVec);
    painter->restore();
}
