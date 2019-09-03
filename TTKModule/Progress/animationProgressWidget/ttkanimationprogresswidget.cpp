#include "ttkanimationprogresswidget.h"

#include <QPainter>
#include <QPropertyAnimation>

#define MAX_SIZE    30

TTKAnimationProgressWidget::TTKAnimationProgressWidget(QWidget *parent)
    : QWidget(parent),
      m_index(0),
      m_value(0)
{
    QPixmap pix(":/res/lb_animate");

    for(int i=0; i<MAX_SIZE; i++)
    {
        m_ranges << pix.copy(i * (pix.width() / MAX_SIZE), 0, pix.width() / MAX_SIZE, pix.height());
    }

    m_animation = new QPropertyAnimation(this, QByteArray());
    m_animation->setStartValue(0);
    m_animation->setEndValue(MAX_SIZE - 1);
    m_animation->setDuration(2000);
    m_animation->setLoopCount(-1);
    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
}

void TTKAnimationProgressWidget::start()
{
    m_animation->start();
    update();
}

void TTKAnimationProgressWidget::stop()
{
    m_animation->stop();
    update();
}

QSize TTKAnimationProgressWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKAnimationProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    const int side = qMin(width(), height());
    painter.drawPixmap(QRect(0, 0, side, side), m_ranges.at(m_index));

    painter.setFont(QFont("Roboto", 15, QFont::Bold));
    painter.setPen(QColor("#555555"));
    painter.drawText(QRect(20, 20, side - 40, side - 40), Qt::AlignCenter, QString("%1%").arg(m_value));
}

void TTKAnimationProgressWidget::valueChanged(const QVariant &value)
{
    m_index = value.toInt();
    m_value = m_index*100 / MAX_SIZE;

    update();
}
