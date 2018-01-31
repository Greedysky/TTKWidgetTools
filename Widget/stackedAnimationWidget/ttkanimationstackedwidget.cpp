#include "ttkanimationstackedwidget.h"

#include <QPixmap>
#include <QTransform>

TTKAnimationStackedWidget::TTKAnimationStackedWidget(QWidget *parent)
    : QStackedWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);

    m_bRevert = false;
    m_eCurve = QEasingCurve::Linear;
    m_isAnimating = false;
    m_currentValue = 0;
    m_currentIndex = 0;
    m_previousIndex = 0;
    m_type = FadeExchange;

    m_bFade = true;
    m_bAnimat = true;


    m_pCoverPixmap = 0;
    m_pCoverPixmap = 0;

    m_animation = new QPropertyAnimation(this, "afValue", this);
    m_animation->setPropertyName("afValue");
    m_animation->setDuration(200);
    m_animation->setEasingCurve(m_eCurve);
    m_animation->setStartValue(0);
    m_animation->setEndValue(0);

    connect(m_animation, SIGNAL(finished()), this, SLOT(animationFinished()));

    setLength(500, m_type);
}

TTKAnimationStackedWidget::~TTKAnimationStackedWidget()
{
    delete m_animation;
}

void TTKAnimationStackedWidget::paintEvent(QPaintEvent * event)
{
    if(m_isAnimating)
    {
        QPainter painter(this);
        QTransform transform;

        renderPreviousWidget(painter, transform);
        renderCurrentWidget(painter, transform);
    }
    else
    {
        QWidget::paintEvent(event);
    }
}

void TTKAnimationStackedWidget::renderPreviousWidget(QPainter &painter, QTransform &transform)
{
    //QWidget *w = widget(m_previousIndex);
    //QPixmap pixmap( w->size() );
    //w->render(&pixmap);

    painter.save();

    Q_UNUSED(transform);
    switch(m_type)
    {
        case BottomToTop :
                {
                    painter.translate(0, m_currentValue);
                    painter.drawPixmap(0, -height()/2, m_PrivPixmap);
                    break;
                }
        case TopToBottom :
                {
                    painter.translate(0, m_currentValue);
                    painter.drawPixmap(0, height()/2, m_PrivPixmap);
                    break;
                }
        case LeftToRight :
                {
                    if(m_previousIndex > m_currentIndex && m_bRevert == true)
                    {
                        transform.translate(0 - m_currentValue, 0);
                        painter.setTransform(transform);

                        if(m_bFade)
                            painter.setOpacity(1 - (m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(-width()/2, 0, m_PrivPixmap);
                    }
                    else
                    {
                        painter.translate(m_currentValue, 0);
                        if(m_bFade)
                            painter.setOpacity(1 - (m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(width()/2, 0, m_PrivPixmap);
                    }

                    break;
                }
        case RightToLeft :
                {
                    if(m_previousIndex > m_currentIndex && m_bRevert == true)
                    {
                        painter.translate(-m_currentValue, 0);
                        if(m_bFade)
                            painter.setOpacity((m_fEndValue - m_currentValue) / m_fRangeValue);

                        painter.drawPixmap(width()/2, 0, m_PrivPixmap);
                    }
                    else
                    {
                        painter.translate(m_currentValue, 0);

                        if(m_bFade)
                            painter.setOpacity(1 - (m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(-width()/2, 0, m_PrivPixmap);
                    }

                    break;
                }
        case RollInOut:
                {
                    if(m_bFade)
                        painter.setOpacity((float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue));

                   //painter.drawPixmap(m_currentValue - m_fStartValue , 0, m_PrivPixmap);
                    painter.drawPixmap(0 , m_fStartValue - m_currentValue, m_PrivPixmap);

                    break;
                }
        case FadeInOut:
                {
                    float fOpt = (float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue) /2.5;

                    if(m_bFade)
                        painter.setOpacity(fOpt);

                    painter.drawPixmap(0 , 0, m_PrivPixmap);

                    break;
                }
        case FadeExchange:
            {
                    float fOpt = (float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue);//(m_currentValue - (float)::abs(m_fRangeValue) / 2.0) / (float)((float)::abs(m_fRangeValue) / 2.0);

                    if(m_bFade)
                        painter.setOpacity(fOpt);

                    painter.drawPixmap(0 , 0, m_PrivPixmap);

                break;
            }
        case BlackInOut:
                {

                    painter.restore();

                    return;


                    float fOpt = (m_currentValue - (float)::abs(m_fRangeValue) / 2.0) / (float)((float)::abs(m_fRangeValue) / 2.0);//(float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue);

                    if(m_bFade)
                        painter.setOpacity(fOpt);
                    painter.drawPixmap(0 , 0, m_PrivPixmap);


                    //painter.fillRect(QRect(0, 0, width(), height()), QColor(128, 128, 128, 128 * (1 - fOpt)));

                    fOpt = fOpt < 0 ? 0 : (float)(1.0 - fOpt);

                    if(m_bFade)
                        painter.setOpacity(fOpt);
                    painter.drawPixmap(0 , 0, *m_pCoverPixmap);


                    break;
                }
        case CoverInOutRight:
                {

                    if(m_bFade)
                        painter.setOpacity(1 - (m_currentValue - m_fStartValue) / m_fRangeValue);

                    painter.drawPixmap(0 , 0, m_PrivPixmap);


                    break;
                }
        case CoverInOutLeft:
                {
                    if(m_bFade)
                        painter.setOpacity((m_currentValue - m_fStartValue) / m_fRangeValue);

                    painter.drawPixmap(0, 0, m_CurrentPixmap);

                    break;
                }
        case VerticalFlipRotate:
            {
                float lfDegree = ((m_currentValue - m_fStartValue)/ m_fRangeValue) * 180;
                if(lfDegree <= 90)
                {
                    if(m_bFade)
                        painter.setOpacity((90 - lfDegree) / 90);

                    painter.setTransform(QTransform().translate(width() / 2, height() /2).rotate(lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_PrivPixmap);
                }

                break;
            }
        case VerticalFlipRotateOut:
            {
                break;
            }
        case VerticalCubeRotateT2B:
            {
                float lfPercent = (m_currentValue - m_fStartValue)/ m_fRangeValue;//sin((m_currentValue - m_fStartValue)/ m_fRangeValue * 90 * 3.14 / 180);
                float lfDegree = lfPercent * 90;
                float lfPos = lfPercent * height();

                //qDebug() << QString::fromLocal8Bit("Previous") << lfReal << lfDeg << lfPercent << lfDegree << lfPos;

                //if(lfDegree <= 90)
                {
                    //if(m_bFade)
                    //	painter.setOpacity((90 - lfDegree) / 90);

                    painter.setTransform(QTransform().translate(0, lfPos/2).translate(width() / 2, height() /2).rotate(-lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_PrivPixmap);
                }


                break;
            }

        case VerticalCubeRotateB2T:
            {
                float lfPercent = (m_currentValue - m_fStartValue)/ m_fRangeValue;//sin((m_currentValue - m_fStartValue)/ m_fRangeValue * 90 * 3.14 / 180);
                float lfDegree = lfPercent * 90;
                float lfPos = lfPercent * height();

                painter.setTransform(QTransform().translate(0, -lfPos/2).translate(width() / 2, height() /2).rotate(lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                painter.drawPixmap(0, 0, m_PrivPixmap);

                break;
            }
        case HorizontalFlipRotate:
            {
                float lfDegree = ((m_currentValue - m_fStartValue)/ m_fRangeValue) * 180;
                if(lfDegree <= qAbs(90))
                {
                    if(m_bFade)
                        painter.setOpacity((90 - lfDegree) / 90);

                    painter.setTransform(QTransform().translate(width() / 2, height() /2).rotate(lfDegree, Qt::YAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_PrivPixmap);
                }

                break;
            }
        default: break;
    }

    painter.restore();
}

void TTKAnimationStackedWidget::renderCurrentWidget(QPainter &painter, QTransform &transform)
{
    //QWidget *w = widget(m_currentIndex);
    //QPixmap pixmap( w->size() );
    //w->render(&pixmap);

    painter.save();

    switch(m_type)
    {
        case BottomToTop :
                {
                    transform.translate(0, m_currentValue);
                    painter.setTransform(transform);
                    painter.drawPixmap(0, height()/2, m_CurrentPixmap);
                    break;
                }
        case TopToBottom :
                {
                    transform.translate(0, m_currentValue);
                    painter.setTransform(transform);
                    painter.drawPixmap(0, -height()/2, m_CurrentPixmap);
                    break;
                }
        case LeftToRight :
                {
                    if(m_previousIndex > m_currentIndex && m_bRevert == true)
                    {
                        painter.translate(-m_currentValue, 0);
                        if(m_bFade)
                            painter.setOpacity(1 - (m_fEndValue - m_currentValue) / m_fRangeValue);

                        painter.drawPixmap(width()/2, 0, m_CurrentPixmap);
                    }
                    else
                    {
                        transform.translate(m_currentValue, 0);
                        painter.setTransform(transform);

                        if(m_bFade)
                            painter.setOpacity((m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(-width()/2, 0, m_CurrentPixmap);
                    }

                    break;
                }
        case RightToLeft :
                {
                    if(m_previousIndex > m_currentIndex && m_bRevert == true)
                    {
                        transform.translate(0 - m_currentValue, 0);
                        painter.setTransform(transform);

                        if(m_bFade)
                            painter.setOpacity((m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(-width()/2, 0, m_CurrentPixmap);
                    }
                    else
                    {
                        painter.translate(m_currentValue, 0);

                        if(m_bFade)
                            painter.setOpacity((m_currentValue - m_fStartValue) / m_fRangeValue);

                        painter.drawPixmap(width()/2, 0, m_CurrentPixmap);
                    }

                    break;
                }
        case RollInOut:
                {
                    painter.translate(m_currentValue, 0);

                    if(m_bFade)
                        painter.setOpacity((m_fStartValue - m_currentValue) / (float)::abs(m_fRangeValue));

                    painter.drawPixmap(0, 0, m_CurrentPixmap);


                    break;
                }
        case FadeInOut:
                {
                    //float fOpt = ((float)::abs(m_fRangeValue) / 2.0 - m_currentValue) / ((float)::abs(m_fRangeValue) / 2.0);

                    float fOpt =  1.0 - (float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue);

                    if(m_bFade)
                        painter.setOpacity(fOpt);

                    painter.drawPixmap(0, 0, m_CurrentPixmap);

                    break;
                }
        case FadeExchange:
            {
                    float fOpt =  1.0 - (float)(m_currentValue - m_fEndValue) / (float)::abs(m_fRangeValue);

                    if(m_bFade)
                        painter.setOpacity(fOpt);

                    painter.drawPixmap(0, 0, m_CurrentPixmap);

                break;
            }
        case BlackInOut:
                {
                    float fOpt = ((float)::abs(m_fRangeValue) / 2.0 - m_currentValue) / ((float)::abs(m_fRangeValue) / 2.0);

                    if(m_bFade)
                        painter.setOpacity(fOpt);
                    painter.drawPixmap(0, 0, m_CurrentPixmap);

                    //painter.fillRect(QRect(0, 0, width(), height()), QColor(128, 128, 128, 128 * (1.0 - fOpt)));

                    fOpt = fOpt > 0 ? (float)(1.0 - fOpt) : 0;

                    if(m_bFade)
                        painter.setOpacity(fOpt);

                    painter.drawPixmap(0, 0, *m_pCoverPixmap);

                    break;
                }
            case CoverInOutRight:
                {
                    painter.translate(m_currentValue, 0);

                    if(m_bFade)
                        painter.setOpacity((m_currentValue - m_fStartValue) / m_fRangeValue);

                    painter.drawPixmap(width()/2, 0, m_CurrentPixmap);

                    break;
                }
            case CoverInOutLeft:
                {
                    painter.translate(m_currentValue, 0);
                    if(m_bFade)
                        painter.setOpacity(1 - (m_currentValue - m_fStartValue) / m_fRangeValue);

                    painter.drawPixmap(width()/2, 0, m_PrivPixmap);

                    break;
                }
        case VerticalFlipRotate:
            {
                float lfDegree = ((m_currentValue - m_fStartValue)/ m_fRangeValue) * 180;
                if(lfDegree > 90)
                {
                    if(m_bFade)
                        painter.setOpacity((lfDegree - 90) / 90);


                    painter.setTransform(QTransform().translate(width() / 2, height() /2).rotate(180- lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_CurrentPixmap);
                }

                break;
            }

        case VerticalFlipRotateOut:
            {
                float lfDegree = ((m_currentValue - m_fStartValue)/ m_fRangeValue) * 90;
                if(m_bFade)
                    painter.setOpacity((lfDegree) / 90);

                painter.setTransform(QTransform().translate(width() / 2, height() /2).rotate(90- lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                painter.drawPixmap(0, 0, m_CurrentPixmap);

                break;
            }

        case VerticalCubeRotateT2B:
            {
                float lfPercent = (m_currentValue - m_fStartValue)/ m_fRangeValue;
                float lfDegree = lfPercent * 90;
                float lfPos = (1 - lfPercent) * height();

                //qDebug() << lfPercent << lfDegree << lfPos;

                //if(lfDegree <= 90)
                {
                    //if(m_bFade)
                    //	painter.setOpacity((90 - lfDegree) / 90);

                    painter.setTransform(QTransform().translate(0, -lfPos / 2 ).translate(width() / 2, height() /2).rotate(90 - lfDegree, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_CurrentPixmap);
                }


                break;
            }

        case VerticalCubeRotateB2T:
            {
                float lfPercent = (m_currentValue - m_fStartValue)/ m_fRangeValue;
                float lfDegree = lfPercent * 90;
                float lfPos = (1 - lfPercent) * height();

                //qDebug() << lfPercent << lfDegree << lfPos;

                //if(lfDegree <= 90)
                {
                    //if(m_bFade)
                    //	painter.setOpacity((90 - lfDegree) / 90);

                    painter.setTransform(QTransform().translate(0, lfPos / 2 ).translate(width() / 2, height() /2).rotate(lfDegree - 90, Qt::XAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_CurrentPixmap);
                }


                break;
            }
        case HorizontalFlipRotate:
            {
                float lfDegree = ((m_currentValue - m_fStartValue)/ m_fRangeValue) * 180;
                if(lfDegree > qAbs(90))
                {
                    if(m_bFade)
                        painter.setOpacity((lfDegree - 90) / 90);


                    painter.setTransform(QTransform().translate(width() / 2, height() /2).rotate(lfDegree - 180, Qt::YAxis).translate(-width() / 2, -height() / 2), false);
                    painter.drawPixmap(0, 0, m_CurrentPixmap);
                }

                break;
            }

        default: break;
    }

    painter.restore();
}

void TTKAnimationStackedWidget::start(int index)
{
    if(index >= this->count())
        return;

    //m_previousIndex = m_currentIndex;
    m_previousIndex = this->currentIndex();

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
        case LeftToRight:
        case RightToLeft:
        case SlideInOut:
        case CoverInOutLeft:
        case CoverInOutRight:
        {
            m_fStartValue = width() / 2;
            break;
        }
        case TopToBottom:
        case BottomToTop:
        {
            m_fStartValue = height() / 2;
            break;
        }
        case VerticalCubeRotateT2B:
        {
            m_fStartValue = 0;
            m_fEndValue = height();
            break;
        }
        case VerticalCubeRotateB2T:
        {
            m_fStartValue = 0;
            m_fEndValue = height();
            break;
        }
        default:
        {
            break;
        }
    }

    if(m_type == RightToLeft || m_type == LeftToRight)
    {
        //if(m_previousIndex < m_currentIndex)
        //{
        //	if(m_bRevert == true)
        //		setLength(abs(m_fStartValue*2), LeftToRight);
        //	else
        //		setLength(abs(m_fStartValue*2), RightToLeft);
        //}
        //else if(m_previousIndex > m_currentIndex)
        //{
        //	if(m_bRevert == true)
        //		setLength(abs(m_fStartValue*2), RightToLeft);
        //	else
        //		setLength(abs(m_fStartValue*2), LeftToRight);
        //}

        setLength(abs(m_fStartValue*2), m_type);
    }
    else if(m_type == CoverInOutLeft || m_type == CoverInOutRight)
    {
        if(m_previousIndex < m_currentIndex)
        {
            setLength(abs(m_fStartValue*2), CoverInOutRight);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            setLength(abs(m_fStartValue*2), CoverInOutLeft);
        }
    }
    else if(m_type == VerticalCubeRotateT2B || m_type == VerticalCubeRotateB2T)
    {
        if(m_previousIndex < m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(abs(m_fEndValue), VerticalCubeRotateT2B);
            else
                setLength(abs(m_fEndValue), m_type);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(abs(m_fEndValue), VerticalCubeRotateB2T);
            else
                setLength(abs(m_fEndValue), m_type);
        }
    }
    else if(m_type == TopToBottom || m_type == BottomToTop)
    {
        //setLength(abs(m_fEndValue*2), m_type);
        if(m_previousIndex < m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(abs(m_fStartValue*2), TopToBottom);
            else
                setLength(abs(m_fStartValue*2), BottomToTop);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(abs(m_fEndValue*2), BottomToTop);
            else
                setLength(abs(m_fEndValue*2), TopToBottom);
        }
    }
    else if(m_type == HorizontalFlipRotate)
    {
        if(m_previousIndex < m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(0 - abs(m_fStartValue), HorizontalFlipRotate);
            else
                setLength(abs(m_fStartValue), HorizontalFlipRotate);
        }
        else if(m_previousIndex > m_currentIndex)
        {
            if(m_bRevert == true)
                setLength(abs(m_fStartValue), HorizontalFlipRotate);
            else
                setLength(0 - abs(m_fStartValue), HorizontalFlipRotate);
        }
    }

    int offsetx = frameRect().width();
    int offsety = frameRect().height();
    widget(m_currentIndex)->setGeometry(0, 0, offsetx, offsety);

    currentWidget()->hide();
    m_isAnimating = true;

    QWidget *w = widget(m_currentIndex);
    w->hide();
    QStackedWidget::setCurrentWidget( w );
    w->hide();

    QWidget *lpWidget = widget(m_previousIndex);
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
    m_PrivPixmap = lpWidget->grab(lpWidget->rect());
#else
    m_PrivPixmap = QPixmap::grabWidget(lpWidget);
#endif

    lpWidget = widget(m_currentIndex);
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
    m_PrivPixmap = lpWidget->grab(lpWidget->rect());
#else
    m_PrivPixmap = QPixmap::grabWidget(lpWidget);
#endif

    m_animation->start();
}

void TTKAnimationStackedWidget::setLength(int length, AnimationType type)
{
    switch(m_type = type)
    {
        case BottomToTop :
                {
                    m_animation->setStartValue(length/2);
                    m_animation->setEndValue(-length/2);
                    break;
                }
        case LeftToRight :
                {
                    m_animation->setStartValue(-length/2);
                    m_animation->setEndValue(length/2);
                    break;
                }
        case TopToBottom :
                {
                    m_animation->setStartValue(-length/2);
                    m_animation->setEndValue(length/2);
                    break;
                }
        case RightToLeft :
                {
                    m_animation->setStartValue(length/2);
                    m_animation->setEndValue(-length/2);
                    break;
                }
        case RollInOut:
                {
                    m_animation->setStartValue(length);
                    m_animation->setEndValue(0);
                    break;
                }
        case FadeInOut:
        case BlackInOut:
        case FadeExchange:
                {
                    m_animation->setStartValue(length);
                    m_animation->setEndValue(0);
                    break;
                }
        case SlideInOut:
                {
                    m_animation->setStartValue(-length/2);
                    m_animation->setEndValue(length/2);
                    break;
                }
        case CoverInOutRight:
                {
                    m_animation->setStartValue(length/2);
                    m_animation->setEndValue(-length/2);
                    break;
                }
        case CoverInOutLeft:
                {
                    m_animation->setStartValue(-length/2);
                    m_animation->setEndValue(length/2);
                    break;
                }
        case VerticalFlipRotate:
            {
                    m_animation->setStartValue(length);
                    m_animation->setEndValue(0);
                    break;
            }
        case VerticalFlipRotateOut:
            {
                    m_animation->setStartValue(0);
                    m_animation->setEndValue(length);
                    break;
            }
        case VerticalCubeRotateT2B:
            {
                    m_animation->setStartValue(0);
                    m_animation->setEndValue(length);
                    break;
            }
        case VerticalCubeRotateB2T:
            {
                    m_animation->setStartValue(0);
                    m_animation->setEndValue(length);
                    break;
            }
        case HorizontalFlipRotate:
            {
                    m_animation->setStartValue(length);
                    m_animation->setEndValue(0);
                    break;
            }

        default: break;
    }

    m_fRangeValue = m_animation->endValue().toFloat() - m_animation->startValue().toFloat();
    m_fStartValue = m_animation->startValue().toFloat();
    m_fEndValue = m_animation->endValue().toFloat();
}

void TTKAnimationStackedWidget::setDuration(int duration)
{
    m_animation->setDuration(duration);
}

int TTKAnimationStackedWidget::getDuration() const
{
    return m_animation->duration();
}

void TTKAnimationStackedWidget::setCurve(QEasingCurve::Type aeCurve)
{
    m_eCurve = aeCurve;
    m_animation->setEasingCurve(m_eCurve);
}

void TTKAnimationStackedWidget::setRevert(bool abRevert)
{
    m_bRevert = abRevert;
}

void TTKAnimationStackedWidget::setFadeEnable(bool abEnabled)
{
    m_bFade = abEnabled;
}

void TTKAnimationStackedWidget::setAnimatEnable(bool abEnabled)
{
    m_bAnimat = abEnabled;
}

bool TTKAnimationStackedWidget::isAnimating()
{
    return (m_animation->state() == QAbstractAnimation::Running);
}

void TTKAnimationStackedWidget::addWidget(QWidget *widget)
{
    widget->setAttribute(Qt::WA_TranslucentBackground);
    QStackedWidget::addWidget(widget);
}

void TTKAnimationStackedWidget::setCurrentIndex(int index)
{
    if(m_bAnimat == true && this->isVisible() == true && index != m_currentIndex)
        start(index);
    else
        QStackedWidget::setCurrentIndex(index);
}

float TTKAnimationStackedWidget::GetValue() const
{
    return m_currentValue;
}

void TTKAnimationStackedWidget::SetValue(const float &afValue)
{
    m_currentValue = afValue;
    update();
}

void TTKAnimationStackedWidget::animationFinished()
{
    m_currentValue = 0;
    m_isAnimating = false;
    QWidget *w = widget(m_currentIndex);
    if(w != NULL)
    {
        w->show();
        w->raise();
        QStackedWidget::setCurrentWidget( w );
    }

    update();

    emit page_changed(m_currentIndex);
}
