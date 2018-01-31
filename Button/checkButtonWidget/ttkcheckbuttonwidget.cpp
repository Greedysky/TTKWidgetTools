#include "ttkcheckbuttonwidget.h"

#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>

TTKCheckButtonWidget::TTKCheckButtonWidget(QWidget *parent)
    : TTKCheckable(parent)
{
    m_checkedState->assignProperty(m_checkedIcon, "iconSize", 24);
    m_uncheckedState->assignProperty(m_checkedIcon, "iconSize", 0);

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(m_checkedIcon, "iconSize", this);
    animation->setDuration(300);
    m_uncheckedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_checkedIcon, "iconSize", this);
    animation->setDuration(1300);
    m_checkedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_checkedIcon, "opacity", this);
    animation->setDuration(440);
    m_checkedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_checkedIcon, "opacity", this);
    animation->setDuration(440);
    m_uncheckedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_uncheckedIcon, "opacity", this);
    animation->setDuration(440);
    m_checkedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_uncheckedIcon, "opacity", this);
    animation->setDuration(440);
    m_uncheckedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_uncheckedIcon, "color", this);
    animation->setDuration(440);
    m_checkedTransition->addAnimation(animation);

    animation = new QPropertyAnimation(m_uncheckedIcon, "color", this);
    animation->setDuration(440);
    m_uncheckedTransition->addAnimation(animation);
}
