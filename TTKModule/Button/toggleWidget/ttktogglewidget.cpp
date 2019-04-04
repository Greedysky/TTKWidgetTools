#include "ttktogglewidget.h"

#include <QEvent>
#include <QPainter>
#include <QStateMachine>
#include <QCoreApplication>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

TTKToggleThumb::TTKToggleThumb(TTKToggleWidget *parent)
    : QWidget(parent), m_toggle(parent), m_shift(0), m_offset(0)
{
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(6);
    effect->setColor(QColor(0, 0, 0, 80));
    effect->setOffset(QPointF(0, 1));
    setGraphicsEffect(effect);

    parent->installEventFilter(this);
}

void TTKToggleThumb::setShift(qreal shift)
{
    if(m_shift == shift)
    {
        return;
    }

    m_shift = shift;
    updateOffset();
}

void TTKToggleThumb::setThumbColor(const QColor &color)
{
    m_thumbColor = color;
    update();
}

bool TTKToggleThumb::eventFilter(QObject *obj, QEvent *event)
{
    const QEvent::Type type = event->type();
    if(QEvent::Resize == type || QEvent::Move == type)
    {
        setGeometry(m_toggle->rect().adjusted(8, 8, -8, -8));
        updateOffset();
    }

    return QWidget::eventFilter(obj, event);
}

void TTKToggleThumb::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(m_toggle->isEnabled() ? m_thumbColor : Qt::white);

    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    int s;
    QRectF r;

    if(Qt::Horizontal == m_toggle->orientation())
    {
        s = height()-10;
        r = QRectF(5+m_offset, 5, s, s);
    }else
    {
        s = width()-10;
        r = QRectF(5, 5+m_offset, s, s);
    }

    painter.drawEllipse(r);

    if(!m_toggle->isEnabled())
    {
        brush.setColor(m_toggle->disabledColor());
        painter.setBrush(brush);
        painter.drawEllipse(r);
    }
}

void TTKToggleThumb::updateOffset()
{
    const QSize s(Qt::Horizontal == m_toggle->orientation() ? size() : QSize(height(), width()));
    m_offset = m_shift * static_cast<qreal>(s.width() - s.height());
    update();
}



TTKToggleTrack::TTKToggleTrack(TTKToggleWidget *parent)
    : QWidget(parent), m_toggle(parent)
{
    parent->installEventFilter(this);
}

void TTKToggleTrack::setTrackColor(const QColor &color)
{
    m_trackColor = color;
    update();
}

bool TTKToggleTrack::eventFilter(QObject *obj, QEvent *event)
{
    const QEvent::Type type = event->type();

    if(QEvent::Resize == type || QEvent::Move == type)
    {
        setGeometry(m_toggle->rect());
    }
    return QWidget::eventFilter(obj, event);
}

void TTKToggleTrack::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    if(m_toggle->isEnabled())
    {
        brush.setColor(m_trackColor);
        painter.setOpacity(0.8);
    }else
    {
        brush.setColor(m_toggle->disabledColor());
        painter.setOpacity(0.6);
    }

    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    if(Qt::Horizontal == m_toggle->orientation())
    {
        const int h = height()/2;
        const QRect r(0, h/2, width(), h);
        painter.drawRoundedRect(r.adjusted(14, 4, -14, -4), h/2-4, h/2-4);
    }
    else
    {
        const int w = width()/2;
        const QRect r(w/2, 0, w, height());
        painter.drawRoundedRect(r.adjusted(4, 14, -4, -14), w/2-4, w/2-4);
    }
}



TTKToggleWidget::TTKToggleWidget(QWidget *parent)
    : QAbstractButton(parent)
{
    m_track = new TTKToggleTrack(this);
    m_thumb = new TTKToggleThumb(this);
    m_stateMachine = new QStateMachine(this);
    m_offState = new QState;
    m_onState = new QState;
    m_orientation = Qt::Horizontal;

    setCheckable(true);
    setChecked(false);
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    m_stateMachine->addState(m_offState);
    m_stateMachine->addState(m_onState);
    m_stateMachine->setInitialState(m_offState);

    m_offState->assignProperty(m_thumb, "shift", 0);
    m_onState->assignProperty(m_thumb, "shift", 1);

    QSignalTransition *transition;
    QPropertyAnimation *animation;

    transition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    transition->setTargetState(m_onState);
    m_offState->addTransition(transition);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("shift");
    animation->setTargetObject(m_thumb);
    animation->setDuration(200);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    transition->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("trackColor");
    animation->setTargetObject(m_track);
    animation->setDuration(150);
    transition->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("thumbColor");
    animation->setTargetObject(m_thumb);
    animation->setDuration(150);
    transition->addAnimation(animation);

    transition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    transition->setTargetState(m_offState);
    m_onState->addTransition(transition);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("shift");
    animation->setTargetObject(m_thumb);
    animation->setDuration(200);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    transition->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("trackColor");
    animation->setTargetObject(m_track);
    animation->setDuration(150);
    transition->addAnimation(animation);

    animation = new QPropertyAnimation(this);
    animation->setPropertyName("thumbColor");
    animation->setTargetObject(m_thumb);
    animation->setDuration(150);
    transition->addAnimation(animation);

    setupProperties();
    m_stateMachine->start();

    QCoreApplication::processEvents();
}

TTKToggleWidget::~TTKToggleWidget()
{
    delete m_track;
    delete m_thumb;
    delete m_offState;
    delete m_onState;
    delete m_stateMachine;
}

void TTKToggleWidget::setDisabledColor(const QColor &color)
{
    m_disabledColor = color;
    setupProperties();
}

QColor TTKToggleWidget::disabledColor() const
{
    return m_disabledColor;
}

void TTKToggleWidget::setActiveColor(const QColor &color)
{
    m_activeColor = color;
    setupProperties();
}

QColor TTKToggleWidget::activeColor() const
{
    return m_activeColor;
}

void TTKToggleWidget::setInactiveColor(const QColor &color)
{
    m_inactiveColor = color;
    setupProperties();
}

QColor TTKToggleWidget::inactiveColor() const
{
    return m_inactiveColor;
}

void TTKToggleWidget::setTrackColor(const QColor &color)
{
    m_trackColor = color;
    setupProperties();
}

QColor TTKToggleWidget::trackColor() const
{
    return m_trackColor;
}

void TTKToggleWidget::setOrientation(Qt::Orientation orientation)
{
    if(m_orientation == orientation)
    {
        return;
    }

    m_orientation = orientation;
    updateGeometry();
}

Qt::Orientation TTKToggleWidget::orientation() const
{
    return m_orientation;
}

QSize TTKToggleWidget::sizeHint() const
{
    return Qt::Horizontal == m_orientation ? QSize(64, 48) : QSize(48, 64);
}

void TTKToggleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
}

void TTKToggleWidget::setupProperties()
{
    if(isEnabled())
    {
        const qreal shift = m_thumb->shift();
        if(qFuzzyCompare(shift, 1))
        {
            m_thumb->setThumbColor(activeColor());
            m_track->setTrackColor(activeColor().lighter(110));
        }
        else if(qFuzzyCompare(1 + shift, 1))
        {
            m_thumb->setThumbColor(inactiveColor());
            m_track->setTrackColor(trackColor());
        }
    }

    m_offState->assignProperty(m_track, "trackColor", trackColor().lighter(110));
    m_onState->assignProperty(m_track, "trackColor", activeColor().lighter(110));

    m_offState->assignProperty(m_thumb, "thumbColor", inactiveColor());
    m_onState->assignProperty(m_thumb, "thumbColor", activeColor());

    update();
}
