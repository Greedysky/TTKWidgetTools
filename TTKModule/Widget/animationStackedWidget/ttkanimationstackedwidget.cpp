#include "ttkanimationstackedwidget.h"

#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>

TTKAnimationStackedWidget::TTKAnimationStackedWidget(QWidget *parent)
    : QStackedWidget(parent),
      m_isAnimating(false),
      m_currentValue(0),
      m_currentIndex(0),
      m_previousIndex(0),
      m_type(Module::LeftToRight)
{
    m_animation = new QPropertyAnimation(this, {});
    m_animation->setDuration(TTK_DN_S2MS / 2);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(0);
    m_animation->setEndValue(0);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));

    setLength(200, m_type);
}

TTKAnimationStackedWidget::~TTKAnimationStackedWidget()
{
    delete m_animation;
}

void TTKAnimationStackedWidget::start(int current)
{
    start(m_currentIndex, current);
}

void TTKAnimationStackedWidget::start(int previous, int current)
{
    if(m_isAnimating)
    {
        return;
    }

    m_previousIndex = previous;
    m_currentIndex = current;

    QWidget *w = widget(m_currentIndex);
    if(!w)
    {
        return;
    }

    const int offsetx = frameRect().width();
    const int offsety = frameRect().height();
    w->setGeometry(0, 0, offsetx, offsety);

    currentWidget()->hide();
    m_isAnimating = true;
    m_animation->start();
}

void TTKAnimationStackedWidget::setLength(int length, Module type)
{
    m_type = type;
    m_animation->setStartValue(0);
    m_animation->setEndValue(length);
}

void TTKAnimationStackedWidget::setDuration(int duration)
{
    m_animation->setDuration(duration);
}

int TTKAnimationStackedWidget::duration() const
{
    return m_animation->duration();
}

QSize TTKAnimationStackedWidget::sizeHint() const
{
    return QSize(200, 100);
}

void TTKAnimationStackedWidget::valueChanged(const QVariant &value)
{
    m_currentValue = value.toFloat();
    update();
}

void TTKAnimationStackedWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;

    QWidget *w = widget(m_currentIndex);
    w->show();
    w->raise();

    setCurrentWidget(w);
    update();
}

void TTKAnimationStackedWidget::paintEvent(QPaintEvent *event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        renderPreviousWidget(&painter);
        renderCurrentWidget(&painter);
    }
    else
    {
        QWidget::paintEvent(event);
    }
}

void TTKAnimationStackedWidget::renderPreviousWidget(QPainter *painter)
{
    QWidget *w = widget(m_previousIndex);
    QPixmap pix(w->size());
    pix.fill(Qt::transparent);
    w->setAttribute(Qt::WA_TranslucentBackground, true);
    w->render(&pix);
    w->setAttribute(Qt::WA_TranslucentBackground, false);

    switch(m_type)
    {
        case Module::BottomToTop: painter->translate(0, -m_currentValue); break;
        case Module::TopToBottom: painter->translate(0, m_currentValue); break;
        case Module::LeftToRight: painter->translate(m_currentValue, 0); break;
        case Module::RightToLeft: painter->translate(-m_currentValue, 0); break;
        default: break;
    }

    painter->drawPixmap(0, 0, pix);
}

void TTKAnimationStackedWidget::renderCurrentWidget(QPainter *painter)
{
    QWidget *w = widget(m_currentIndex);
    QPixmap pix(w->size());
    pix.fill(Qt::transparent);
    w->setAttribute(Qt::WA_TranslucentBackground, true);
    w->render(&pix);
    w->setAttribute(Qt::WA_TranslucentBackground, false);

    switch(m_type)
    {
        case Module::BottomToTop: painter->drawPixmap(0, height(), pix); break;
        case Module::TopToBottom: painter->drawPixmap(0, -height(), pix); break;
        case Module::LeftToRight: painter->drawPixmap(-width(), 0, pix); break;
        case Module::RightToLeft: painter->drawPixmap(width(), 0, pix); break;
        default: break;
    }
}
