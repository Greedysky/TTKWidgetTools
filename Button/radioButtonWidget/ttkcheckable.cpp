#include "ttkcheckable.h"

#include <QPainter>
#include <QStateMachine>
#include <QCoreApplication>
#include <QEventTransition>
#include <QSignalTransition>

TTKCheckableIcon::TTKCheckableIcon(const QIcon &icon, TTKCheckable *parent)
    : QWidget(parent),
      m_checkable(parent),
      m_color(Qt::black),
      m_icon(icon),
      m_iconSize(24),
      m_opacity(1.0)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

QSize TTKCheckableIcon::sizeHint() const
{
    return QSize(m_iconSize, m_iconSize);
}

void TTKCheckableIcon::setIcon(const QIcon &icon)
{
    m_icon = icon;
    update();
}

void TTKCheckableIcon::setColor(const QColor &color)
{
    m_color = color;
    update();
}

void TTKCheckableIcon::setIconSize(qreal size)
{
    m_iconSize = size;
    update();
}

void TTKCheckableIcon::setOpacity(qreal opacity)
{
    m_opacity = opacity;
    update();
}

void TTKCheckableIcon::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setOpacity(m_opacity);

    QPixmap pixmap = icon().pixmap(24, 24);

    if(!pixmap.isNull())
    {
        const qreal p = static_cast<qreal>((height()) - m_iconSize)/2;
        const qreal z = m_iconSize/24;

        QTransform t;
        if(TTKCheckable::LabelPositionLeft == m_checkable->labelPosition())
        {
            t.translate(p+width()-42, p);
        }
        else
        {
            t.translate(p, p);
        }
        t.scale(z, z);
        painter.setTransform(t);

        QPainter icon(&pixmap);
        icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon.fillRect(pixmap.rect(), color());
        painter.drawPixmap(0, 0, pixmap);
    }
}



TTKCheckable::TTKCheckable(QWidget *parent)
    : QAbstractButton(parent)
{
    m_checkedIcon = new TTKCheckableIcon(QIcon(":/res/check_box"), this);
    m_uncheckedIcon = new TTKCheckableIcon(QIcon(":/res/check_box_outline"), this);
    m_stateMachine = new QStateMachine(this);
    m_uncheckedState = new QState;
    m_checkedState = new QState;
    m_disabledUncheckedState = new QState;
    m_disabledCheckedState = new QState;
    m_uncheckedTransition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    m_checkedTransition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    m_labelPosition = TTKCheckable::LabelPositionRight;

    setCheckable(true);
    setFont(QFont("Roboto", 11, QFont::Normal));

    m_stateMachine->addState(m_uncheckedState);
    m_stateMachine->addState(m_checkedState);
    m_stateMachine->addState(m_disabledUncheckedState);
    m_stateMachine->addState(m_disabledCheckedState);
    m_stateMachine->setInitialState(m_uncheckedState);

    m_uncheckedTransition->setTargetState(m_checkedState);
    m_uncheckedState->addTransition(m_uncheckedTransition);

    m_checkedTransition->setTargetState(m_uncheckedState);
    m_checkedState->addTransition(m_checkedTransition);

    QAbstractTransition *transition;

    transition = new QEventTransition(this, QEvent::EnabledChange);
    transition->setTargetState(m_disabledUncheckedState);
    m_uncheckedState->addTransition(transition);

    transition = new QEventTransition(this, QEvent::EnabledChange);
    transition->setTargetState(m_uncheckedState);
    m_disabledUncheckedState->addTransition(transition);

    transition = new QEventTransition(this, QEvent::EnabledChange);
    transition->setTargetState(m_disabledCheckedState);
    m_checkedState->addTransition(transition);

    transition = new QEventTransition(this, QEvent::EnabledChange);
    transition->setTargetState(m_checkedState);
    m_disabledCheckedState->addTransition(transition);

    transition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    transition->setTargetState(m_disabledCheckedState);
    m_disabledUncheckedState->addTransition(transition);

    transition = new QSignalTransition(this, SIGNAL(toggled(bool)));
    transition->setTargetState(m_disabledUncheckedState);
    m_disabledCheckedState->addTransition(transition);

    m_checkedState->assignProperty(m_checkedIcon, "opacity", 1);
    m_checkedState->assignProperty(m_uncheckedIcon, "opacity", 0);

    m_uncheckedState->assignProperty(m_checkedIcon, "opacity", 0);
    m_uncheckedState->assignProperty(m_uncheckedIcon, "opacity", 1);

    m_disabledCheckedState->assignProperty(m_checkedIcon, "opacity", 1);
    m_disabledCheckedState->assignProperty(m_uncheckedIcon, "opacity", 0);

    m_disabledUncheckedState->assignProperty(m_checkedIcon, "opacity", 0);
    m_disabledUncheckedState->assignProperty(m_uncheckedIcon, "opacity", 1);

    m_checkedState->assignProperty(m_checkedIcon, "color", checkedColor());
    m_checkedState->assignProperty(m_uncheckedIcon, "color", checkedColor());

    m_uncheckedState->assignProperty(m_uncheckedIcon, "color", uncheckedColor());
    m_uncheckedState->assignProperty(m_uncheckedIcon, "color", uncheckedColor());

    m_disabledUncheckedState->assignProperty(m_uncheckedIcon, "color", disabledColor());
    m_disabledCheckedState->assignProperty(m_checkedIcon, "color", disabledColor());

    m_stateMachine->start();

    QCoreApplication::processEvents();
}

TTKCheckable::~TTKCheckable()
{
    delete m_checkedIcon;
    delete m_uncheckedIcon;
    delete m_uncheckedTransition;
    delete m_checkedTransition;
    delete m_uncheckedState;
    delete m_checkedState;
    delete m_disabledUncheckedState;
    delete m_disabledCheckedState;
    delete m_stateMachine;
}

void TTKCheckable::setLabelPosition(LabelPosition placement)
{
    m_labelPosition = placement;
    update();
}

TTKCheckable::LabelPosition TTKCheckable::labelPosition() const
{
    return m_labelPosition;
}

void TTKCheckable::setCheckedColor(const QColor &color)
{
    m_checkedColor = color;
    setupProperties();
}

QColor TTKCheckable::checkedColor() const
{
    return m_checkedColor;
}

void TTKCheckable::setUncheckedColor(const QColor &color)
{
    m_uncheckedColor = color;
    setupProperties();
}

QColor TTKCheckable::uncheckedColor() const
{
    return m_uncheckedColor;
}

void TTKCheckable::setTextColor(const QColor &color)
{
    m_textColor = color;
    setupProperties();
}

QColor TTKCheckable::textColor() const
{
    return m_textColor;
}

void TTKCheckable::setDisabledColor(const QColor &color)
{
    m_disabledColor = color;
    setupProperties();
}

QColor TTKCheckable::disabledColor() const
{
    return m_disabledColor;
}

void TTKCheckable::setCheckedIcon(const QIcon &icon)
{
    m_checkedIcon->setIcon(icon);
    update();
}

QIcon TTKCheckable::checkedIcon() const
{
    return m_checkedIcon->icon();
}

void TTKCheckable::setUncheckedIcon(const QIcon &icon)
{
    m_uncheckedIcon->setIcon(icon);
    update();
}

QIcon TTKCheckable::uncheckedIcon() const
{
    return m_uncheckedIcon->icon();
}

QSize TTKCheckable::sizeHint() const
{
    if(text().isEmpty())
    {
        return QSize(40, 40);
    }
    return QSize(fontMetrics().size(Qt::TextShowMnemonic, text()).width()+52, 40);
}

bool TTKCheckable::event(QEvent *event)
{
    switch (event->type())
    {
        case QEvent::Resize:
        case QEvent::Move:
            m_checkedIcon->setGeometry(rect());
            m_uncheckedIcon->setGeometry(rect());
            break;
        default: break;
    }
    return QAbstractButton::event(event);
}

void TTKCheckable::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if(!isEnabled())
    {
        return;
    }

    setChecked(!isChecked());
}

void TTKCheckable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);

    QPen pen;
    pen.setColor(isEnabled() ? textColor() : disabledColor());
    painter.setPen(pen);

    if(TTKCheckable::LabelPositionLeft == m_labelPosition)
    {
        painter.drawText(4, 25, text());
    }
    else
    {
        painter.drawText(48, 25, text());
    }
}

void TTKCheckable::setupProperties()
{
    m_checkedState->assignProperty(m_checkedIcon, "color", checkedColor());
    m_checkedState->assignProperty(m_uncheckedIcon, "color", checkedColor());
    m_uncheckedState->assignProperty(m_uncheckedIcon, "color", uncheckedColor());
    m_disabledUncheckedState->assignProperty(m_uncheckedIcon, "color", disabledColor());
    m_disabledCheckedState->assignProperty(m_checkedIcon, "color", disabledColor());

    if(isEnabled())
    {
        if (isChecked())
        {
            m_checkedIcon->setColor(checkedColor());
        }
        else
        {
            m_uncheckedIcon->setColor(uncheckedColor());
        }
    }
    else
    {
        m_checkedIcon->setColor(disabledColor());
        m_uncheckedIcon->setColor(disabledColor());
    }

    update();
}
