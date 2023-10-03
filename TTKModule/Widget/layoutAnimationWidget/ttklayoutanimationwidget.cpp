#include "ttklayoutanimationwidget.h"

#include <QPainter>
#include <QBoxLayout>
#include <QPropertyAnimation>

TTKLayoutAnimationWidget::TTKLayoutAnimationWidget(QWidget *parent)
    : QWidget(parent),
      m_isAnimating(false),
      m_currentValue(0)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    m_mainWidget = new QWidget(this);
    mainLayout->addWidget(m_mainWidget);
    setLayout(mainLayout);

    m_widgetLayout = new QVBoxLayout(m_mainWidget);
    m_widgetLayout->setContentsMargins(0, 0, 0, 0);
    m_widgetLayout->setSpacing(0);
    m_mainWidget->setLayout(m_widgetLayout);

    m_animation = new QPropertyAnimation(m_mainWidget, {}, this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(0.0f);
    m_animation->setEndValue(0.0f);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(valueChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));
}

TTKLayoutAnimationWidget::~TTKLayoutAnimationWidget()
{
    delete m_widgetLayout;
    delete m_mainWidget;
    delete m_animation;
}

void TTKLayoutAnimationWidget::start()
{
    if(m_isAnimating || m_widgetLayout->count() == 0)
    {
        return;
    }

    m_animation->setStartValue(0);
    m_animation->setEndValue(height()/m_widgetLayout->count());

    m_mainWidget->hide();
    m_isAnimating = true;
    m_animation->start();
}

void TTKLayoutAnimationWidget::stop()
{
    m_isAnimating = false;
    m_animation->stop();
    m_mainWidget->show();
}

void TTKLayoutAnimationWidget::addStretch(int stretch)
{
    m_widgetLayout->addStretch(stretch);
}

void TTKLayoutAnimationWidget::addWidget(QWidget *widget, int stretch, Qt::Alignment alignment)
{
    m_widgetLayout->addWidget(widget, stretch, alignment);
}

void TTKLayoutAnimationWidget::removeWidget(QWidget *widget)
{
    m_widgetLayout->removeWidget(widget);
}

QSize TTKLayoutAnimationWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKLayoutAnimationWidget::valueChanged(const QVariant &value)
{
    m_currentValue = -value.toFloat();
    update();
}

void TTKLayoutAnimationWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;
    m_mainWidget->show();
}

void TTKLayoutAnimationWidget::paintEvent(QPaintEvent *event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        QPixmap pix(size());
        pix.fill(Qt::transparent);
        m_mainWidget->setAttribute(Qt::WA_TranslucentBackground, true);
        m_mainWidget->render(&pix);
        m_mainWidget->setAttribute(Qt::WA_TranslucentBackground, false);

        painter.translate(0, m_currentValue);
        painter.drawPixmap(0, 0, pix);
        painter.drawPixmap(0, height(), pix);
    }
    else
    {
        QWidget::paintEvent(event);
    }
}
