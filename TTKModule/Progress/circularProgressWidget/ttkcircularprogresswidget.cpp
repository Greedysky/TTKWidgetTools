#include "ttkcircularprogresswidget.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

TTKCircularProgressDelegate::TTKCircularProgressDelegate(TTKCircularProgressWidget *parent)
    : QObject(parent),
      m_progress(parent),
      m_dashOffset(0),
      m_dashLength(89),
      m_angle(0)
{

}

void TTKCircularProgressDelegate::setDashOffset(qreal offset)
{
    m_dashOffset = offset;
    m_progress->update();
}

void TTKCircularProgressDelegate::setDashLength(qreal length)
{
    m_dashLength = length;
    m_progress->update();
}

void TTKCircularProgressDelegate::setAngle(int angle)
{
    m_angle = angle;
    m_progress->update();
}



TTKCircularProgressWidget::TTKCircularProgressWidget(QWidget *parent)
    : QProgressBar(parent)
{
    m_delegate = new TTKCircularProgressDelegate(this);
    m_penWidth = 6.25;
    m_size = 64;
    setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->setLoopCount(-1);

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("dashLength");
    animation->setTargetObject(m_delegate);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->setStartValue(0.1);
    animation->setKeyValueAt(0.15, 0.2);
    animation->setKeyValueAt(0.6, 20);
    animation->setKeyValueAt(0.7, 20);
    animation->setEndValue(20);
    animation->setDuration(2050);

    group->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("dashOffset");
    animation->setTargetObject(m_delegate);
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setStartValue(0);
    animation->setKeyValueAt(0.15, 0);
    animation->setKeyValueAt(0.6, -7);
    animation->setKeyValueAt(0.7, -7);
    animation->setEndValue(-25);
    animation->setDuration(2050);

    group->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("angle");
    animation->setTargetObject(m_delegate);
    animation->setStartValue(0);
    animation->setEndValue(719);
    animation->setDuration(2050);

    group->addAnimation(animation);

    group->start();
}

TTKCircularProgressWidget::~TTKCircularProgressWidget()
{
    delete m_delegate;
}

void TTKCircularProgressWidget::setLineWidth(qreal width)
{
    m_penWidth = width;
    update();
    updateGeometry();
}

qreal TTKCircularProgressWidget::lineWidth() const
{
    return m_penWidth;
}

void TTKCircularProgressWidget::setSize(int size)
{
    m_size = size;
    update();
    updateGeometry();
}

int TTKCircularProgressWidget::size() const
{
    return m_size;
}

void TTKCircularProgressWidget::setColor(const QColor &color)
{
    m_color = color;
    update();
}

QColor TTKCircularProgressWidget::color() const
{
    return m_color;
}

QSize TTKCircularProgressWidget::sizeHint() const
{
    const qreal s = m_size + m_penWidth + 8;
    return QSize(s, s);
}

void TTKCircularProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width()/2, height()/2);
    painter.rotate(m_delegate->angle());

    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(m_penWidth);
    pen.setColor(color());

    QVector<qreal> pattern;
    pattern << m_delegate->dashLength()*m_size/50 << 30*m_size/50;

    pen.setDashOffset(m_delegate->dashOffset()*m_size/50);
    pen.setDashPattern(pattern);

    painter.setPen(pen);
    painter.drawEllipse(QPoint(0, 0), m_size/2, m_size/2);

}
