#include "ttkanimation2stackedwidget.h"
#include "ttkdesktopscreen.h"

#include <cmath>
#include <QPixmap>
#include <QPainter>
#include <QTransform>

TTKAnimation2StackedWidget::TTKAnimation2StackedWidget(QWidget *parent)
   : QStackedWidget(parent),
      m_isAnimating(false),
      m_currentValue(0),
      m_fade(false),
      m_animat(false),
      m_curve(QEasingCurve::Linear),
      m_currentIndex(0),
      m_previousIndex(0),
      m_type(Module::FadeExchange),
      m_revert(false)
{
    setAttribute(Qt::WA_TranslucentBackground);

    m_animation = new QPropertyAnimation(this, "m_currentValue", this);
    m_animation->setPropertyName("m_currentValue");
    m_animation->setDuration(200);
    m_animation->setEasingCurve(m_curve);
    m_animation->setStartValue(0);
    m_animation->setEndValue(0);

    connect(m_animation, SIGNAL(finished()), SLOT(animationFinished()));

    setLength(500, m_type);
}

TTKAnimation2StackedWidget::~TTKAnimation2StackedWidget()
{
    delete m_animation;
}

void TTKAnimation2StackedWidget::paintEvent(QPaintEvent *event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        QTransform transform;
        renderPreviousWidget(&painter, transform);
        renderCurrentWidget(&painter, transform);
    }
    else
    {
        QStackedWidget::paintEvent(event);
    }
}

void TTKAnimation2StackedWidget::renderPreviousWidget(QPainter *painter, QTransform &transform)
{
    painter->save();

    switch(m_type)
    {
        case Module::BottomToTop:
        {
            painter->translate(0, m_currentValue);
            painter->drawPixmap(0, -height() / 2, m_privPixmap);
            break;
        }
        case Module::TopToBottom:
        {
            painter->translate(0, m_currentValue);
            painter->drawPixmap(0, height() / 2, m_privPixmap);
            break;
        }
        case Module::LeftToRight:
        {
            if(m_previousIndex > m_currentIndex && m_revert)
            {
                transform.translate(0 - m_currentValue, 0);
                painter->setTransform(transform);

                if(m_fade)
                {
                    painter->setOpacity(1 - (m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(-width() / 2, 0, m_privPixmap);
            }
            else
            {
                painter->translate(m_currentValue, 0);
                if(m_fade)
                {
                    painter->setOpacity(1 - (m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(width() / 2, 0, m_privPixmap);
            }

            break;
        }
        case Module::RightToLeft:
        {
            if(m_previousIndex > m_currentIndex && m_revert)
            {
                painter->translate(-m_currentValue, 0);
                if(m_fade)
                {
                    painter->setOpacity((m_endValue - m_currentValue) / m_rangeValue);
                }

                painter->drawPixmap(width() / 2, 0, m_privPixmap);
            }
            else
            {
                painter->translate(m_currentValue, 0);
                if(m_fade)
                {
                    painter->setOpacity(1 - (m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(-width() / 2, 0, m_privPixmap);
            }

            break;
        }
        case Module::RollInOut:
        {
            if(m_fade)
            {
                painter->setOpacity((float)(m_currentValue - m_endValue) / (float)std::abs(m_rangeValue));
            }

            painter->drawPixmap(0 , m_startValue - m_currentValue, m_privPixmap);
            break;
        }
        case Module::FadeInOut:
        {
            const float opt = (float)(m_currentValue - m_endValue) / (float)std::abs(m_rangeValue) / 2.5;
            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0 , 0, m_privPixmap);
            break;
        }
        case Module::FadeExchange:
        {
            const float opt = (float)(m_currentValue - m_endValue) / (float)std::abs(m_rangeValue);
            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0 , 0, m_privPixmap);
            break;
        }
        case Module::BlackInOut:
        {
            float opt = (m_currentValue - (float)std::abs(m_rangeValue) / 2.0) / (float)((float)std::abs(m_rangeValue) / 2.0);
            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0 , 0, m_privPixmap);

            opt = opt < 0 ? 0: (float)(1.0 - opt);

            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0 , 0, m_privPixmap);
            break;
        }
        case Module::CoverInOutRight:
        {
            if(m_fade)
            {
                painter->setOpacity(1 - (m_currentValue - m_startValue) / m_rangeValue);
            }

            painter->drawPixmap(0 , 0, m_privPixmap);
            break;
        }
        case Module::CoverInOutLeft:
        {
            if(m_fade)
            {
                painter->setOpacity((m_currentValue - m_startValue) / m_rangeValue);
            }

            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::VerticalFlipRotate:
        {
            const float degree = ((m_currentValue - m_startValue) / m_rangeValue) * 180;
            if(degree <= 90)
            {
                if(m_fade)
                {
                    painter->setOpacity((90 - degree) / 90);
                }

                painter->setTransform(QTransform().translate(width() / 2, height() / 2).rotate(degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                painter->drawPixmap(0, 0, m_privPixmap);
            }
            break;
        }
        case Module::VerticalFlipRotateOut:
        {
            break;
        }
        case Module::VerticalCubeRotateT2B:
        {
            const float percent = (m_currentValue - m_startValue) / m_rangeValue;
            const float degree = percent * 90;
            const float pos = percent * height();

            painter->setTransform(QTransform().translate(0, pos/ 2).translate(width() / 2, height() / 2).rotate(-degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
            painter->drawPixmap(0, 0, m_privPixmap);
            break;
        }
        case Module::VerticalCubeRotateB2T:
        {
            const float percent = (m_currentValue - m_startValue) / m_rangeValue;
            const float degree = percent * 90;
            const float pos = percent * height();

            painter->setTransform(QTransform().translate(0, -pos/ 2).translate(width() / 2, height() / 2).rotate(degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
            painter->drawPixmap(0, 0, m_privPixmap);
            break;
        }
        case Module::HorizontalFlipRotate:
        {
            const float degree = ((m_currentValue - m_startValue) / m_rangeValue) * 180;
            if(degree <= std::abs(90))
            {
                if(m_fade)
                {
                    painter->setOpacity((90 - degree) / 90);
                }

                painter->setTransform(QTransform().translate(width() / 2, height() / 2).rotate(degree, Qt::YAxis).translate(-width() / 2, -height() / 2), false);
                painter->drawPixmap(0, 0, m_privPixmap);
            }
            break;
        }
        default: break;
    }

    painter->restore();
}

void TTKAnimation2StackedWidget::renderCurrentWidget(QPainter *painter, QTransform &transform)
{
    painter->save();

    switch(m_type)
    {
        case Module::BottomToTop:
        {
            transform.translate(0, m_currentValue);
            painter->setTransform(transform);
            painter->drawPixmap(0, height() / 2, m_currentPixmap);
            break;
        }
        case Module::TopToBottom:
        {
            transform.translate(0, m_currentValue);
            painter->setTransform(transform);
            painter->drawPixmap(0, -height() / 2, m_currentPixmap);
            break;
        }
        case Module::LeftToRight:
        {
            if(m_previousIndex > m_currentIndex && m_revert)
            {
                painter->translate(-m_currentValue, 0);

                if(m_fade)
                {
                    painter->setOpacity(1 - (m_endValue - m_currentValue) / m_rangeValue);
                }

                painter->drawPixmap(width() / 2, 0, m_currentPixmap);
            }
            else
            {
                transform.translate(m_currentValue, 0);
                painter->setTransform(transform);

                if(m_fade)
                {
                    painter->setOpacity((m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(-width() / 2, 0, m_currentPixmap);
            }
            break;
        }
        case Module::RightToLeft:
        {
            if(m_previousIndex > m_currentIndex && m_revert)
            {
                transform.translate(0 - m_currentValue, 0);
                painter->setTransform(transform);

                if(m_fade)
                {
                    painter->setOpacity((m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(-width() / 2, 0, m_currentPixmap);
            }
            else
            {
                painter->translate(m_currentValue, 0);

                if(m_fade)
                {
                    painter->setOpacity((m_currentValue - m_startValue) / m_rangeValue);
                }

                painter->drawPixmap(width() / 2, 0, m_currentPixmap);
            }
            break;
        }
        case Module::RollInOut:
        {
            painter->translate(m_currentValue, 0);

            if(m_fade)
            {
                painter->setOpacity((m_startValue - m_currentValue) / (float)std::abs(m_rangeValue));
            }

            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::FadeInOut:
        {
            const float opt = 1.0 - (float)(m_currentValue - m_endValue) / (float)std::abs(m_rangeValue);

            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::FadeExchange:
        {
            const float opt = 1.0 - (float)(m_currentValue - m_endValue) / (float)std::abs(m_rangeValue);

            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::BlackInOut:
        {
            float opt = ((float)std::abs(m_rangeValue) / 2.0 - m_currentValue) / ((float)std::abs(m_rangeValue) / 2.0);

            if(m_fade)
            {
                painter->setOpacity(opt);
            }
            painter->drawPixmap(0, 0, m_currentPixmap);

            opt = opt > 0 ? (float)(1.0 - opt) : 0;

            if(m_fade)
            {
                painter->setOpacity(opt);
            }

            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::CoverInOutRight:
        {
            painter->translate(m_currentValue, 0);

            if(m_fade)
            {
                painter->setOpacity((m_currentValue - m_startValue) / m_rangeValue);
            }

            painter->drawPixmap(width() / 2, 0, m_currentPixmap);
            break;
        }
        case Module::CoverInOutLeft:
        {
            painter->translate(m_currentValue, 0);
            if(m_fade)
            {
                painter->setOpacity(1 - (m_currentValue - m_startValue) / m_rangeValue);
            }

            painter->drawPixmap(width() / 2, 0, m_privPixmap);
            break;
        }
        case Module::VerticalFlipRotate:
        {
            const float degree = ((m_currentValue - m_startValue) / m_rangeValue) * 180;
            if(degree > 90)
            {
                if(m_fade)
                {
                    painter->setOpacity((degree - 90) / 90);
                }

                painter->setTransform(QTransform().translate(width() / 2, height() / 2).rotate(180 - degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                painter->drawPixmap(0, 0, m_currentPixmap);
            }
            break;
        }
        case Module::VerticalFlipRotateOut:
        {
            const float degree = ((m_currentValue - m_startValue) / m_rangeValue) * 90;
            if(m_fade)
            {
                painter->setOpacity(degree / 90);
            }

            painter->setTransform(QTransform().translate(width() / 2, height() / 2).rotate(90 - degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::VerticalCubeRotateT2B:
        {
            const float percent = (m_currentValue - m_startValue) / m_rangeValue;
            const float degree = percent * 90;
            const float pos = (1 - percent) * height();

            painter->setTransform(QTransform().translate(0, -pos / 2 ).translate(width() / 2, height() / 2).rotate(90 - degree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::VerticalCubeRotateB2T:
        {
            const float percent = (m_currentValue - m_startValue) / m_rangeValue;
            const float degree = percent * 90;
            const float pos = (1 - percent) * height();

            painter->setTransform(QTransform().translate(0, pos / 2 ).translate(width() / 2, height() / 2).rotate(degree - 90, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
            painter->drawPixmap(0, 0, m_currentPixmap);
            break;
        }
        case Module::HorizontalFlipRotate:
        {
            const float degree = ((m_currentValue - m_startValue) / m_rangeValue) * 180;
            if(degree > std::abs(90))
            {
                if(m_fade)
                {
                    painter->setOpacity((degree - 90) / 90);
                }

                painter->setTransform(QTransform().translate(width() / 2, height() / 2).rotate(degree - 180, Qt::YAxis).translate(-width() / 2, -height() / 2), false);
                painter->drawPixmap(0, 0, m_currentPixmap);
            }
            break;
        }
        default: break;
    }

    painter->restore();
}

void TTKAnimation2StackedWidget::start(int index)
{
    if(index >= count())
    {
        return;
    }

    m_previousIndex = currentIndex();
    m_currentIndex = index;

    if(m_isAnimating)
    {
        disconnect(m_animation, SIGNAL(finished()), this, SLOT(animationFinished()));
        m_animation->stop();
        animationFinished();
        connect(m_animation, SIGNAL(finished()), this, SLOT(animationFinished()));
    }

    switch(m_type)
    {
        case Module::LeftToRight:
        case Module::RightToLeft:
        case Module::SlideInOut:
        case Module::CoverInOutLeft:
        case Module::CoverInOutRight:
        {
            m_startValue = width() / 2;
            break;
        }
        case Module::TopToBottom:
        case Module::BottomToTop:
        {
            m_startValue = height() / 2;
            break;
        }
        case Module::VerticalCubeRotateT2B:
        {
            m_startValue = 0;
            m_endValue = height();
            break;
        }
        case Module::VerticalCubeRotateB2T:
        {
            m_startValue = 0;
            m_endValue = height();
            break;
        }
        default:
        {
            break;
        }
    }

    if(m_type == Module::RightToLeft || m_type == Module::LeftToRight)
    {
        setLength(std::abs(m_startValue * 2), m_type);
    }
    else if(m_type == Module::CoverInOutLeft || m_type == Module::CoverInOutRight)
    {
        if(m_previousIndex < m_currentIndex)
        {
            setLength(std::abs(m_startValue * 2), Module::CoverInOutRight);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            setLength(std::abs(m_startValue * 2), Module::CoverInOutLeft);
        }
    }
    else if(m_type == Module::VerticalCubeRotateT2B || m_type == Module::VerticalCubeRotateB2T)
    {
        if(m_previousIndex < m_currentIndex)
        {
            setLength(std::abs(m_endValue), m_revert ? Module::VerticalCubeRotateT2B: m_type);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            setLength(std::abs(m_endValue), m_revert ? Module::VerticalCubeRotateB2T: m_type);
        }
    }
    else if(m_type == Module::TopToBottom || m_type == Module::BottomToTop)
    {
        if(m_previousIndex < m_currentIndex)
        {
            setLength(std::abs(m_startValue * 2), m_revert ? Module::TopToBottom: Module::BottomToTop);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            setLength(std::abs(m_endValue * 2), m_revert ? Module::BottomToTop: Module::TopToBottom);
        }
    }
    else if(m_type == Module::HorizontalFlipRotate)
    {
        if(m_previousIndex < m_currentIndex)
        {
            setLength(m_revert ? -std::abs(m_startValue) : std::abs(m_startValue), Module::HorizontalFlipRotate);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            setLength(m_revert ? std::abs(m_startValue) : -std::abs(m_startValue), Module::HorizontalFlipRotate);
        }
    }

    const int offsetX = frameRect().width();
    const int offsetY = frameRect().height();
    widget(m_currentIndex)->setGeometry(0, 0, offsetX, offsetY);

    currentWidget()->hide();
    m_isAnimating = true;

    QWidget *w = widget(m_currentIndex);
    w->hide();
    QStackedWidget::setCurrentWidget(w);
    w->hide();

    QWidget *previousWidget = widget(m_previousIndex);
    m_privPixmap = TTKDesktopScreen::grabWidget(previousWidget, previousWidget->rect());

    previousWidget = widget(m_currentIndex);
    m_privPixmap = TTKDesktopScreen::grabWidget(previousWidget, previousWidget->rect());

    m_animation->start();
}

void TTKAnimation2StackedWidget::setLength(int length, Module type)
{
    switch(m_type = type)
    {
        case Module::BottomToTop:
        {
            m_animation->setStartValue(length / 2);
            m_animation->setEndValue(-length / 2);
            break;
        }
        case Module::LeftToRight:
        {
            m_animation->setStartValue(-length / 2);
            m_animation->setEndValue(length / 2);
            break;
        }
        case Module::TopToBottom:
        {
            m_animation->setStartValue(-length / 2);
            m_animation->setEndValue(length / 2);
            break;
        }
        case Module::RightToLeft:
        {
            m_animation->setStartValue(length / 2);
            m_animation->setEndValue(-length / 2);
            break;
        }
        case Module::RollInOut:
        {
            m_animation->setStartValue(length);
            m_animation->setEndValue(0);
            break;
        }
        case Module::FadeInOut:
        case Module::BlackInOut:
        case Module::FadeExchange:
        {
            m_animation->setStartValue(length);
            m_animation->setEndValue(0);
            break;
        }
        case Module::SlideInOut:
        {
            m_animation->setStartValue(-length / 2);
            m_animation->setEndValue(length / 2);
            break;
        }
        case Module::CoverInOutRight:
        {
            m_animation->setStartValue(length / 2);
            m_animation->setEndValue(-length / 2);
            break;
        }
        case Module::CoverInOutLeft:
        {
            m_animation->setStartValue(-length / 2);
            m_animation->setEndValue(length / 2);
            break;
        }
        case Module::VerticalFlipRotate:
        {
                m_animation->setStartValue(length);
                m_animation->setEndValue(0);
                break;
        }
        case Module::VerticalFlipRotateOut:
        {
                m_animation->setStartValue(0);
                m_animation->setEndValue(length);
                break;
        }
        case Module::VerticalCubeRotateT2B:
        {
                m_animation->setStartValue(0);
                m_animation->setEndValue(length);
                break;
        }
        case Module::VerticalCubeRotateB2T:
        {
                m_animation->setStartValue(0);
                m_animation->setEndValue(length);
                break;
        }
        case Module::HorizontalFlipRotate:
        {
                m_animation->setStartValue(length);
                m_animation->setEndValue(0);
                break;
        }
        default: break;
    }

    m_rangeValue = m_animation->endValue().toFloat() - m_animation->startValue().toFloat();
    m_startValue = m_animation->startValue().toFloat();
    m_endValue = m_animation->endValue().toFloat();
}

void TTKAnimation2StackedWidget::setDuration(int duration)
{
    m_animation->setDuration(duration);
}

int TTKAnimation2StackedWidget::duration() const
{
    return m_animation->duration();
}

void TTKAnimation2StackedWidget::setCurve(QEasingCurve::Type curve)
{
    m_curve = curve;
    m_animation->setEasingCurve(m_curve);
}

void TTKAnimation2StackedWidget::setRevert(bool revert)
{
    m_revert = revert;
}

void TTKAnimation2StackedWidget::setFadeEnabled(bool enabled)
{
    m_fade = enabled;
}

void TTKAnimation2StackedWidget::setAnimatEnabled(bool animat)
{
    m_animat = animat;
}

bool TTKAnimation2StackedWidget::isAnimating()
{
    return m_animation->state() == QAbstractAnimation::Running;
}

void TTKAnimation2StackedWidget::addWidget(QWidget *widget)
{
    widget->setAttribute(Qt::WA_TranslucentBackground);
    QStackedWidget::addWidget(widget);
}

void TTKAnimation2StackedWidget::setCurrentIndex(int index)
{
    if(m_animat && isVisible() && index != m_currentIndex)
    {
        start(index);
    }
    else
    {
        QStackedWidget::setCurrentIndex(index);
    }
}

float TTKAnimation2StackedWidget::value() const
{
    return m_currentValue;
}

void TTKAnimation2StackedWidget::setValue(const float value)
{
    m_currentValue = value;
    update();
}

QSize TTKAnimation2StackedWidget::sizeHint() const
{
    return QSize(200, 100);
}

void TTKAnimation2StackedWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;

    QWidget *w = widget(m_currentIndex);
    w->show();
    w->raise();
    QStackedWidget::setCurrentWidget( w );

    update();
    Q_EMIT pageChanged(m_currentIndex);
}
