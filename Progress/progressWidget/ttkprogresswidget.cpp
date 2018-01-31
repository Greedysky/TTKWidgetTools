#include "ttkprogresswidget.h"

#include <QPainter>
#include <QPropertyAnimation>

TTKProgressDelegate::TTKProgressDelegate(TTKProgressWidget *parent)
    : QObject(parent),
      m_progress(parent),
      m_offset(0)
{

}

void TTKProgressDelegate::setOffset(qreal offset)
{
    m_offset = offset;
    m_progress->update();
}



TTKProgressWidget::TTKProgressWidget(QWidget *parent)
    : QProgressBar(parent)
{
    m_delegate = new TTKProgressDelegate(this);

    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(this);
    animation->setPropertyName("offset");
    animation->setTargetObject(m_delegate);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setDuration(1000);
    animation->setLoopCount(-1);
    animation->start();
}

TTKProgressWidget::~TTKProgressWidget()
{

}

void TTKProgressWidget::setProgressColor(const QColor &color)
{
    m_progressColor = color;
    update();
}

QColor TTKProgressWidget::progressColor() const
{
    return m_progressColor;
}

void TTKProgressWidget::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
    update();
}

QColor TTKProgressWidget::backgroundColor() const
{
    return m_backgroundColor;
}

void TTKProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor( backgroundColor() );
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    QPainterPath path;
    path.addRoundedRect(0, height()/2 - 3, width(), 6, 3, 3);
    painter.setClipPath(path);

    painter.drawRect(0, 0, width(), height());

    if(isEnabled())
    {
        brush.setColor(progressColor());
        painter.setBrush(brush);
        painter.drawRect(m_delegate->offset()*width()*2 - width(), 0, width(), height());
    }
}
