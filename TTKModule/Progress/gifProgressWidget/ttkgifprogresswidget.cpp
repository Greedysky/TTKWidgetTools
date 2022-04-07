#include "ttkgifprogresswidget.h"

#include <QTimer>
#include <QPainter>

#define GIF_BALLON_WHITE        35
#define GIF_CICLE_BLUE          58
#define GIF_RICE_FONT_WHITE     26
#define GIF_RICE_FONT_BLACK_BIG 42
#define GIF_RICE_FONT_BLACK     16
#define GIF_HOURGLASS_WHITE     38
#define GIF_RADIO_BLUE          14
#define GIF_CHECK_BLUE          93
#define GIF_RECORD_RED          30
#define GIF_CLOSE_WHITE_WIDTH   350
#define GIF_CLOSE_WHITE_HEIGHT  50

TTKGifProgressWidget::TTKGifProgressWidget(QWidget *parent)
    : QLabel(parent)
{
    m_index = -1;
    m_isRunning = false;
    m_infinited = true;

    setFixedSize(GIF_CICLE_BLUE, GIF_CICLE_BLUE);

    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));
}

TTKGifProgressWidget::TTKGifProgressWidget(Type type, QWidget *parent)
    : TTKGifProgressWidget(parent)
{
    setType(type);
}

TTKGifProgressWidget::~TTKGifProgressWidget()
{
    delete m_timer;
}

void TTKGifProgressWidget::setType(Type type)
{
    m_index = 0;
    switch(m_type = type)
    {
        case BallonWhite: setFixedSize(GIF_BALLON_WHITE, GIF_BALLON_WHITE); break;
        case CicleBlue: setFixedSize(GIF_CICLE_BLUE, GIF_CICLE_BLUE); break;
        case RiceFontWhite: setFixedSize(GIF_RICE_FONT_WHITE, GIF_RICE_FONT_WHITE); break;
        case RiceFontBlackBig: setFixedSize(GIF_RICE_FONT_BLACK_BIG, GIF_RICE_FONT_BLACK_BIG); break;
        case RiceFontBlack: setFixedSize(GIF_RICE_FONT_BLACK, GIF_RICE_FONT_BLACK); break;
        case HourglassWhite: setFixedSize(GIF_HOURGLASS_WHITE, GIF_HOURGLASS_WHITE); break;
        case RadioBlue: setFixedSize(GIF_RADIO_BLUE, GIF_RADIO_BLUE); break;
        case CheckBlue: setFixedSize(GIF_CHECK_BLUE, GIF_CHECK_BLUE); break;
        case Recordred: setFixedSize(GIF_RECORD_RED, GIF_RECORD_RED); break;
        case CloseWhite: setFixedSize(GIF_CLOSE_WHITE_WIDTH, GIF_CLOSE_WHITE_HEIGHT); break;
        default: break;
    }
    update();
}

TTKGifProgressWidget::Type TTKGifProgressWidget::type() const
{
    return m_type;
}

void TTKGifProgressWidget::setInterval(int value)
{
    m_timer->setInterval(value);
}

int TTKGifProgressWidget::interval() const
{
    return m_timer->interval();
}

void TTKGifProgressWidget::setInfinited(bool s)
{
    m_infinited = s;
}

bool TTKGifProgressWidget::infinited() const
{
    return m_infinited;
}

void TTKGifProgressWidget::run(bool run)
{
    if(run)
    {
        show();
        start();
    }
    else
    {
        hide();
        stop();
    }
}

void TTKGifProgressWidget::start()
{
    m_timer->start();
    m_isRunning = true;
}

void TTKGifProgressWidget::stop()
{
    m_timer->stop();
    m_isRunning = false;
}

void TTKGifProgressWidget::updateRender()
{
    ++m_index;
    switch(m_type)
    {
        case BallonWhite:
            {
                if(m_index == 40 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_ballon_white").copy(GIF_BALLON_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case CicleBlue:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_cicle_blue").copy(GIF_CICLE_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case RiceFontWhite:
            {
                if(m_index == 8 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_rice_font_white").copy(GIF_RICE_FONT_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case RiceFontBlackBig:
            {
                if(m_index == 8 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_rice_font_black_big").copy(GIF_RICE_FONT_BLACK_BIG*m_index, 0, width(), height());
                update();
                break;
            }
        case RiceFontBlack:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_rice_font_black").copy(GIF_RICE_FONT_BLACK*m_index, 0, width(), height());
                update();
                break;
            }
        case HourglassWhite:
            {
                if(m_index == 16 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_hourglass_white").copy(GIF_HOURGLASS_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case RadioBlue:
            {
                if(m_index == 10 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_radio_blue").copy(GIF_RADIO_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case CheckBlue:
            {
                if(m_index == 22 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_check_blue").copy(GIF_CHECK_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case Recordred:
            {
                if(m_index == 5 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_record_red").copy(GIF_RECORD_RED*m_index, 0, width(), height());
                update();
                break;
            }
        case CloseWhite:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/res/lb_close_white").copy(GIF_CLOSE_WHITE_WIDTH*m_index, 0, width(), height());
                update();
                break;
            }
        default: break;
    }
}

void TTKGifProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(0, 0, m_renderer);
}

bool TTKGifProgressWidget::infinitedModeCheck()
{
    m_index = 0;
    if(!m_infinited)
    {
        stop();
        return true;
    }
    else
    {
        return false;
    }
}
