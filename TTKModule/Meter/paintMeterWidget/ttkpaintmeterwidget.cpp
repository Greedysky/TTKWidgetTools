#include "ttkpaintmeterwidget.h"

#include <cmath>
#include <QPainter>

static constexpr double PI = 3.1415926535;

TTKPaintMeterWidget::TTKPaintMeterWidget(QWidget *parent)
    : QWidget(parent),
      m_minValue(0),
      m_maxValue(100),
      m_precision(0),
      m_precisionNumeric(0),
      m_units("Km/h"),
      m_label("Speed"),
      m_steps(10),
      m_startAngle(225),
      m_endAngle(-45),
      m_enableValidWindow(false),
      m_beginValidValue(40.0),
      m_endValidValue(50.0),
      m_enableWarningWindow(false),
      m_beginWarningValue(30.0),
      m_endWarningValue(60.0),
      m_thresholdEnabled(true),
      m_numericIndicatorEnabled(true),
      m_foregroundColor(Qt::yellow),
      m_backgroundColor(Qt::black)
{
   setThreshold(80);
   setValue(0);

   setMinimumSize(QSize(80, 80));
}

void TTKPaintMeterWidget::setThreshold(double value)
{
    if(value > m_minValue && value < m_maxValue)
    {
        m_threshold = value;
        update();
    }
}

void TTKPaintMeterWidget::setValue(double value)
{
    if(value > m_maxValue)
    {
        m_value = m_maxValue;
    }
    else if(value < m_minValue)
    {
        m_value = m_minValue;
    }
    else
    {
        m_value = value;
    }

    if(m_thresholdEnabled)
    {
        thresholdManager();
    }
    update();
}

QSize TTKPaintMeterWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKPaintMeterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
	QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    const int side = std::min(width(), height());

    painter.setViewport((width() - side) / 2, (height() - side) / 2,side, side);
    painter.setWindow(-50, -50, 100, 100);

    drawBackground(&painter);
    drawCoverGlass(&painter);
    drawTicks(&painter);
    drawScale(&painter);
    drawUnits(&painter);
    drawThresholdLine(&painter);
    drawWarningWindow((&painter));
    drawValidWindow(&painter);
    drawNeedle(&painter);
    drawNumericValue(&painter);
    drawLabel(&painter);
    drawCrown(&painter);
}

void TTKPaintMeterWidget::drawCrown(QPainter *painter)
{
    painter->save();

    constexpr int startAngle = 30 * 16;
    constexpr int spanAngle = 390 * 16;

    QLinearGradient linearGrad(QPointF(-47, -47), QPointF(94, 94));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(0.3, QColor(60, 60, 60, 250));

    QPen pen;
    QBrush brush = QBrush(linearGrad);
    pen.setBrush(brush);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawArc(QRectF(-47, -47, 94, 94), startAngle, spanAngle);
    painter->restore();
}

void TTKPaintMeterWidget::drawBackground(QPainter *painter)
{
    painter->setBrush(m_backgroundColor);
    painter->drawEllipse(-45, -45, 90, 90);
}

void TTKPaintMeterWidget::drawTicks(QPainter *painter)
{
    painter->save();

    QPen pen = QPen(m_foregroundColor);
    pen.setWidth(0);
    painter->setPen(pen);

    painter->rotate(-m_startAngle);
    const double angleStep = (-m_endAngle + m_startAngle) / m_steps;
    for(int i = 0; i <= m_steps; ++i)
    {
        painter->drawLine(28, 0, 30, 0);
        painter->rotate(angleStep);
    }
    painter->restore();

    pen.setWidth(0);
    painter->setPen(pen);
    const double spanAngle = m_endAngle - m_startAngle;
    painter->drawArc(-28, -28, 56, 56, m_startAngle * 16, spanAngle * 16);
}

void TTKPaintMeterWidget::drawScale(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foregroundColor);

    const double startRad = m_startAngle * PI / 180.0 + PI / 2;
    const double deltaRad = (m_endAngle - m_startAngle) / m_steps * (PI / 180);
    double sina, cosa;
    for(int i=0; i <= m_steps; ++i)
    {
        sina = std::sin(TTKStaticCast(double, startRad + i * deltaRad));
        cosa = std::cos(TTKStaticCast(double, startRad + i * deltaRad));
        const double v = i * ((m_maxValue - m_minValue) / m_steps) + m_minValue;

        const QString &str = QString("%1").arg(v, 0, 'f', m_precision);
        const QFontMetricsF ftm(font());
        const double w = ftm.size(Qt::TextSingleLine, str).width();
        const double h = ftm.size(Qt::TextSingleLine, str).height();
        const int x = TTKStaticCast(int, (38 * sina) - (w / 2));
        const int y = TTKStaticCast(int, (38 * cosa) + (h / 4));
        painter->drawText(x, y, str);
    }
    painter->restore();
}

void TTKPaintMeterWidget::drawUnits(QPainter *painter)
{
    painter->setPen(m_foregroundColor);
    painter->setBrush(m_foregroundColor);
    painter->setPen(m_foregroundColor);
    painter->drawText(QRectF(-15, -20, 30, 10), Qt::AlignCenter, m_units);
}

void TTKPaintMeterWidget::drawNumericValue(QPainter *painter)
{
    if(!m_numericIndicatorEnabled)
    {
        return;
    }
    painter->save();

    const QString &str = QString("%1").arg(m_value, 0, 'f', m_precisionNumeric);
    painter->setPen(!m_thresholdFlag ? Qt::white : Qt::red);
    QFont font = painter->font();
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(QRectF(-15, 25, 30, 10), Qt::AlignCenter, str);

    painter->restore();
}

void TTKPaintMeterWidget::drawNeedle(QPainter *painter)
{
    painter->save();

    painter->rotate(-90.0);
    QPolygon pts;
    pts.setPoints(3, -2, 0, 2, 0, 0, 30);
    QPolygon shadow;
    shadow.setPoints(3, -1, 0, 1, 0, 0, 29);

    const int degRotate = TTKStaticCast(int, m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_value - m_minValue));
    painter->rotate(-degRotate);

    QRadialGradient haloGradient(0, 0, 20, 0, 0);
    haloGradient.setColorAt(0.0, QColor(255, 120, 120));
    haloGradient.setColorAt(1.0, QColor(200, 20, 20));

    QColor color(Qt::darkRed);
    color.setAlpha(90);
    painter->setPen(color);
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon( pts );

    painter->setBrush(QColor(255, 120, 120));
    painter->drawConvexPolygon(shadow);

    painter->restore();

    QLinearGradient linearGrad(QPointF(-7, -7), QPointF(14, 14));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(1, Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(linearGrad);
    painter->drawEllipse(-7, -7, 14, 14);
}

void TTKPaintMeterWidget::drawThresholdLine(QPainter *painter)
{
    if(!m_thresholdEnabled)
    {
        return;
    }

    painter->save();
    const double threshold = (m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_threshold - m_minValue));

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawArc(-25, -25, 50, 50, TTKStaticCast(int, m_startAngle) * 16, TTKStaticCast(int, threshold - m_startAngle) * 16);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawArc(-25, -25, 50, 50, TTKStaticCast(int, threshold) * 16, TTKStaticCast(int, -threshold + m_endAngle) * 16);
    painter->restore();
}

void TTKPaintMeterWidget::drawCoverGlass(QPainter *painter)
{
    painter->save();
    QLinearGradient linearGrad(QPointF(-15, -45), QPointF(90, 75));
    linearGrad.setColorAt(0, QColor(255, 255, 255, 30));
    linearGrad.setColorAt(0.3, QColor(120, 120, 120, 20));
    QBrush brush(linearGrad);

    QPen pen(QColor(0, 0, 0, 0));
    pen.setBrush(brush);
    pen.setWidth(0);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(-45, -45, 90, 90);
    painter->restore();
}

void TTKPaintMeterWidget::drawLabel(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foregroundColor);
    painter->setBrush(m_foregroundColor);
    painter->setPen(m_foregroundColor);

    const QFontMetricsF ftm(font());
    const double w = ftm.size(Qt::TextSingleLine, m_label).width();

    QRectF labelRect(-20, 15, 40, 10);
    if(w > labelRect.width())
    {
        QFont font = painter->font();
        font.setPointSize(font.pointSize() - 1);
        setFont(font);
    }

    painter->drawText(labelRect, Qt::AlignCenter, m_label);
    painter->restore();
}

void TTKPaintMeterWidget::drawWarningWindow(QPainter *painter)
{
    if(m_enableWarningWindow)
    {
        QPen pen;
        const double beginAngle = (m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_beginWarningValue - m_minValue));
        const double endAngle = (m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_endWarningValue - m_minValue));

        pen.setWidth(2);
        pen.setColor(Qt::yellow);
        painter->setPen(pen);
        painter->drawArc(-25, -25, 50, 50,
                         beginAngle > endAngle ? endAngle * 16 : beginAngle * 16,
                         beginAngle > endAngle ? (beginAngle - endAngle) * 16 : (endAngle - beginAngle) * 16);
    }
}

void TTKPaintMeterWidget::thresholdManager()
{
    if(m_value > m_threshold && !m_thresholdFlag)
    {
        m_thresholdFlag = true;
    }
    else if(m_value < m_threshold && m_thresholdFlag)
    {
        m_thresholdFlag = false;
    }
}

void TTKPaintMeterWidget::drawValidWindow(QPainter *painter)
{
    if(m_enableValidWindow)
    {
        QPen pen;
        const double beginAngle = (m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_beginValidValue - m_minValue));
        const double endAngle = (m_startAngle + (m_endAngle - m_startAngle) / (m_maxValue - m_minValue) * (m_endValidValue - m_minValue));

        pen.setWidth(2);
        pen.setColor(Qt::green);
        painter->setPen(pen);
        painter->drawArc(-25, -25, 50, 50,
                         beginAngle > endAngle ? endAngle * 16 : beginAngle * 16,
                         beginAngle > endAngle ? (beginAngle - endAngle) * 16 : (endAngle - beginAngle) * 16);
    }
}
