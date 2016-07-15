#include "animationstackedwidget.h"

#include <QPixmap>
#include <QPainter>
#include <QTransform>
#include <QPropertyAnimation>

AnimationStackedWidget::AnimationStackedWidget(QWidget *parent)
    : QStackedWidget(parent)
{
    m_changeValue = 0;
    m_isAnimating = false;
    m_curIndex = 0;

    m_animation = new QPropertyAnimation(this, QByteArray());
    m_animation->setDuration(300);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(0);
    m_animation->setEndValue(0);
    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));

}

AnimationStackedWidget::~AnimationStackedWidget()
{
    delete m_animation;
}

void AnimationStackedWidget::paintEvent(QPaintEvent * event)
{
    if(m_isAnimating)
    {
        QWidget *w = widget(m_curIndex);
        QPixmap pixmap( w->size() );
        w->render(&pixmap);

        QPainter painter(this);
        QTransform transform;
        switch(m_type)
        {
            case BottomToTop :
                    {
                        transform.translate(0, m_changeValue);
                        painter.setTransform(transform);
                        painter.drawPixmap(0, -height()/2, pixmap);
                        break;
                    }
            case TopToBottom :
                    {
                        transform.translate(0, m_changeValue);
                        painter.setTransform(transform);
                        painter.drawPixmap(0, height()/2, pixmap);
                        break;
                    }
            case LeftToRight :
                    {
                        transform.translate(m_changeValue, 0);
                        painter.setTransform(transform);
                        painter.drawPixmap(-width()/2, 0, pixmap);
                        break;
                    }
            case RightToLeft :
                    {
                        transform.translate(m_changeValue, 0);
                        painter.setTransform(transform);
                        painter.drawPixmap(width()/2, 0, pixmap);
                        break;
                    }
            default: break;
        }
    }
    else
    {
        QWidget::paintEvent(event);
    }
}

void AnimationStackedWidget::start(int index)
{
    if(m_isAnimating)
    {
        return;
    }
    m_curIndex = index;

    int offsetx = frameRect().width();
    int offsety = frameRect().height();
    widget(m_curIndex)->setGeometry(0, 0, offsetx, offsety);

    currentWidget()->hide();
    m_isAnimating = true;
    m_animation->start();
}

void AnimationStackedWidget::setLength(int length, AnimationType type)
{
    switch(m_type = type)
    {
        case BottomToTop :
        case LeftToRight :
                {
                    m_animation->setStartValue(-length/2);
                    m_animation->setEndValue(length/2);
                    break;
                }
        case TopToBottom :
        case RightToLeft :
                {
                    m_animation->setStartValue(length/2);
                    m_animation->setEndValue(-length/2);
                    break;
                }
        default: break;
    }
}

void AnimationStackedWidget::setDuration(int duration)
{
    m_animation->setDuration(duration);
}

void AnimationStackedWidget::valueChanged(const QVariant &value)
{
    m_changeValue = value.toFloat();
    update();
}

void AnimationStackedWidget::animationFinished()
{
    m_changeValue = 0;
    m_isAnimating = false;
    QWidget *w = widget(m_curIndex);
    w->show();
    w->raise();
    setCurrentWidget( w );
    update();
}
