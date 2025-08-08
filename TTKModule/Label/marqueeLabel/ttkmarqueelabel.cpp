#include "ttkmarqueelabel.h"

#include <QTimer>
#include <QPainter>

TTKMarqueeLabel::TTKMarqueeLabel(QWidget *parent)
    : QWidget(parent),
      m_step(2),
      m_interval(20),
      m_mouseHoverStop(false),
      m_mouseHover(false),
      m_moveRight(true),
      m_initX(0),
      m_initY(0),
      m_moveStyle(MoveStyle::LeftAndRight)
{
    setAutoFillBackground(true);

    m_labText = new QLabel(this);
    m_labText->setAlignment(Qt::AlignVCenter);
    m_labText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_timer = new QTimer(this);
    m_timer->setInterval(m_interval);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
    m_timer->start();

    setForegroundColor(QColor(100, 184, 255));
    setBackgroundColor(QColor(222, 222, 222));
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

        const int textWidth = QtFontWidth(fontMetrics(), text);
        const int textHeight = fontMetrics().height();
        m_labText->resize(QSize(textWidth + 15, textHeight + 5));

        if(m_moveStyle == MoveStyle::LeftAndRight)
        {
            m_initX = 0;
        }
        else if(m_moveStyle == MoveStyle::LeftToRight)
        {
            m_initX = -m_labText->width();
        }
        else if(m_moveStyle == MoveStyle::RightToLeft)
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

void TTKMarqueeLabel::setInterval(int msec)
{
    if(m_interval != msec)
    {
        m_interval = msec;
        m_timer->setInterval(msec);
    }
}

void TTKMarqueeLabel::setMouseHoverStop(bool mouseHoverStop)
{
    if(m_mouseHoverStop != mouseHoverStop)
    {
        m_mouseHoverStop = mouseHoverStop;
    }
}

void TTKMarqueeLabel::setForegroundColor(const QColor &foregroundColor)
{
    if(m_foregroundColor != foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        QPalette plt = m_labText->palette();
        plt.setColor(QPalette::WindowText, foregroundColor);
        m_labText->setPalette(plt);
    }
}

void TTKMarqueeLabel::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        QPalette plt = palette();
        plt.setColor(QPalette::Window, backgroundColor);
        setPalette(plt);
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

    const int textWidth = QtFontWidth(fontMetrics(), m_text);
    if(m_moveStyle == MoveStyle::LeftAndRight)
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
    else if(m_moveStyle == MoveStyle::LeftToRight)
    {
        if(m_initX > width())
        {
            m_initX = -textWidth;
        }

        m_initX += m_step;
        m_labText->move(m_initX, m_initY);
    }
    else if(m_moveStyle == MoveStyle::RightToLeft)
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

void TTKMarqueeLabel::enterEvent(QtEnterEvent *event)
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
