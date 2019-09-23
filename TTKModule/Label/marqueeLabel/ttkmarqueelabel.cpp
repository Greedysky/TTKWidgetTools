#include "ttkmarqueelabel.h"

#include <QTimer>
#include <QPainter>

TTKMarqueeLabel::TTKMarqueeLabel(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);

    m_step = 2;
    m_interval = 20;

    m_mouseHoverStop = false;
    m_moveStyle = MoveStyleLeftAndRight;

    m_mouseHover = false;
    m_moveRight = true;
    m_initX = 0;
    m_initY = 0;

    m_labText = new QLabel(this);
    m_labText->setAlignment(Qt::AlignVCenter);
    m_labText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_timer = new QTimer(this);
    m_timer->setInterval(m_interval);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
    m_timer->start();

    setForeground(QColor(100, 184, 255));
    setBackground(QColor(222, 222, 222));
}

TTKMarqueeLabel::~TTKMarqueeLabel()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }
}

void TTKMarqueeLabel::setText(const QString &text)
{
    if(m_text != text)
    {
        m_text = text;
        m_labText->setText(text);

        const int textWidth = fontMetrics().width(text);
        const int textHeight = fontMetrics().height();
        m_labText->resize(QSize(textWidth + 15, textHeight + 5));

        if(m_moveStyle == MoveStyleLeftAndRight)
        {
            m_initX = 0;
        }
        else if(m_moveStyle == MoveStyleLeftToRight)
        {
            m_initX = -m_labText->width();
        }
        else if(m_moveStyle == MoveStyleRightToLeft)
        {
            m_initX = width();
        }
    }
}

void TTKMarqueeLabel::setStep(int step)
{
    if(m_step != step)
    {
        m_step = step;
    }
}

void TTKMarqueeLabel::setInterval(int interval)
{
    if(m_interval != interval)
    {
        m_interval = interval;
        m_timer->setInterval(interval);
    }
}

void TTKMarqueeLabel::setMouseHoverStop(bool mouseHoverStop)
{
    if(m_mouseHoverStop != mouseHoverStop)
    {
        m_mouseHoverStop = mouseHoverStop;
    }
}

void TTKMarqueeLabel::setForeground(const QColor &foreground)
{
    if(m_foreground != foreground)
    {
        m_foreground = foreground;
        QPalette pt = m_labText->palette();
        pt.setColor(QPalette::Foreground, foreground);
        m_labText->setPalette(pt);
    }
}

void TTKMarqueeLabel::setBackground(const QColor &background)
{
    if(m_background != background)
    {
        m_background = background;
        QPalette pt = palette();
        pt.setColor(QPalette::Background, background);
        setPalette(pt);
    }
}

void TTKMarqueeLabel::setMoveStyle(TTKMarqueeLabel::MoveStyle moveStyle)
{
    if(m_moveStyle != moveStyle)
    {
       m_moveStyle = moveStyle;
    }
}

QSize TTKMarqueeLabel::sizeHint() const
{
    return QSize(200, 30);
}

void TTKMarqueeLabel::timeout()
{
    if(m_mouseHoverStop && m_mouseHover)
    {
        return;
    }

    int textWidth = fontMetrics().width(m_text);
    if(m_moveStyle == MoveStyleLeftAndRight)
    {
        if(textWidth <= width())
        {
            if(m_initX + textWidth > width())
            {
                m_moveRight = false;
            }
            else if(m_initX <= 0)
            {
                m_moveRight = true;
            }
        }
        else
        {
            if(m_initX == 10)
            {
                m_moveRight = false;
            }
            else if(m_initX <= width() - textWidth - 10)
            {
                m_moveRight = true;
            }
        }

        if(m_moveRight)
        {
            m_initX += m_step;
        }
        else
        {
            m_initX -= m_step;
        }

        m_labText->move(m_initX, m_initY);
    }
    else if(m_moveStyle == MoveStyleLeftToRight)
    {
        if(m_initX > width())
        {
            m_initX = -textWidth;
        }

        m_initX += m_step;
        m_labText->move(m_initX, m_initY);
    }
    else if(m_moveStyle == MoveStyleRightToLeft)
    {
        if(m_initX < -textWidth)
        {
            m_initX = width();
        }

        m_initX -= m_step;
        m_labText->move(m_initX, m_initY);
    }
}

void TTKMarqueeLabel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_initY = (height() - fontMetrics().height()) / 2;
}

void TTKMarqueeLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_mouseHover = true;
    if(m_mouseHoverStop)
    {
        QFont font = m_labText->font();
        font.setUnderline(true);
        m_labText->setFont(font);
        setCursor(Qt::PointingHandCursor);
    }
}

void TTKMarqueeLabel::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_mouseHover = false;
    if(m_mouseHoverStop)
    {
        QFont font = m_labText->font();
        font.setUnderline(false);
        m_labText->setFont(font);
        setCursor(Qt::ArrowCursor);
    }
}
