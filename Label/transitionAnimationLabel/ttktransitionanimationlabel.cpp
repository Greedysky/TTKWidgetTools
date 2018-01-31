#include "ttktransitionanimationlabel.h"

#include <QPainter>
#include <QPropertyAnimation>

TTKTransitionAnimationLabel::TTKTransitionAnimationLabel(QWidget *parent)
    : QLabel(parent)
{
    m_isAnimating = false;
    m_currentValue = 0;
    m_noAnimationSet = false;

    m_animation = new QPropertyAnimation(this, QByteArray());
    m_animation->setDuration(500);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(0);
    m_animation->setEndValue(101);
    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));
}

TTKTransitionAnimationLabel::~TTKTransitionAnimationLabel()
{
    delete m_animation;
}

QPixmap TTKTransitionAnimationLabel::getRendererPixmap() const
{
    return m_rendererPixmap;
}

void TTKTransitionAnimationLabel::stop()
{
    if(m_animation->state() == QPropertyAnimation::Running)
    {
        m_animation->stop();
    }
}

void TTKTransitionAnimationLabel::setPixmap(const QPixmap &pix)
{
    if(m_noAnimationSet || !pixmap())
    {
        m_rendererPixmap = pix;
        QLabel::setPixmap(pix);
        return;
    }

    m_previousPixmap = *pixmap();
    m_currentPixmap = pix;
    m_isAnimating = true;
    m_animation->start();
}

void TTKTransitionAnimationLabel::valueChanged(const QVariant &value)
{
    m_currentValue = value.toFloat();
    update();
}

void TTKTransitionAnimationLabel::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;
    m_rendererPixmap = m_currentPixmap;

    QLabel::setPixmap(m_rendererPixmap);
}

void TTKTransitionAnimationLabel::paintEvent(QPaintEvent *event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), m_previousPixmap);

        QPixmap pixed( size() );
        pixed.fill(Qt::transparent);
        QPainter paint(&pixed);
        paint.fillRect(rect(), QColor(0xFF, 0xFF, 0xFF, 2.55*m_currentValue));
        paint.setCompositionMode(QPainter::CompositionMode_SourceIn);
        paint.drawPixmap(rect(), m_currentPixmap);
        paint.end();

        m_rendererPixmap = pixed;
        painter.drawPixmap(rect(), pixed);
    }
    else
    {
        QLabel::paintEvent(event);
    }
}
