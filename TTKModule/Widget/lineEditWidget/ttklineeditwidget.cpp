#include "ttklineeditwidget.h"

#include <QPainter>
#include <QPropertyAnimation>

TTKLineEditWidget::TTKLineEditWidget(QWidget *parent)
    : QLineEdit(parent)
{
    setStyleSheet("border:none");

    m_isAnimating = false;
    m_currentValue = 0;
    m_color = QColor(0, 0, 0);

    m_animation = new QPropertyAnimation(this, QByteArray());
    m_animation->setDuration(1000);
    m_animation->setEasingCurve(QEasingCurve::InCubic);
    m_animation->setStartValue(0.0f);
    m_animation->setEndValue(0.0f);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));
}

TTKLineEditWidget::~TTKLineEditWidget()
{
    delete m_animation;
}

void TTKLineEditWidget::setColor(const QColor &color)
{
    m_color = color;
}

void TTKLineEditWidget::valueChanged(const QVariant &value)
{
    m_currentValue = value.toFloat();
    update();
}

void TTKLineEditWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;
}

void TTKLineEditWidget::paintEvent(QPaintEvent * event)
{
    QLineEdit::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush(m_color), 1, Qt::SolidLine));

    if(m_isAnimating)
    {
        int hw = width()/2;
        painter.drawLine(hw - m_currentValue - 1, height() - 1, hw, height() - 1);
        painter.drawLine(hw + 1, height() - 1, hw + m_currentValue, height() - 1);
    }
    else
    {
        painter.drawLine(0, height() - 1, width(), height() - 1);
    }
}

void TTKLineEditWidget::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);

    m_isAnimating = true;
    m_animation->setStartValue(0);
    m_animation->setEndValue(width()/2);
    m_animation->start();
}
