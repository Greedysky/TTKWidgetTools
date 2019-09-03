#include "ttksplashscreen.h"

#include <QTimer>
#include <QProgressBar>

#define PROGRESS_STYLESHEET \
    "QProgressBar{ color:white;border:none; background:rgb(68,69,73);font:30px; text-align:center;}"\
    "QProgressBar::chunk{background-color: rgb(0, 160, 230);}"

TTKSplashScreen::TTKSplashScreen(QWidget *parent)
    : TTKSplashScreen(0, parent)
{

}

TTKSplashScreen::TTKSplashScreen(int mstime, QWidget *parent)
    : QSplashScreen(parent),
      m_elapseTime(mstime),
      m_mainWidget(nullptr)
{
    m_progressBar = new QProgressBar(this);
    m_progressBar->setStyleSheet(PROGRESS_STYLESHEET);
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(0);

    m_timer = new QTimer(this);
    m_timer->setInterval(mstime / 100);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateProgress()));
}

TTKSplashScreen::TTKSplashScreen(const QPixmap &pixmap, int mstime, QWidget *parent)
    : TTKSplashScreen(mstime, parent)
{
    setPixmap(pixmap);
}

TTKSplashScreen::~TTKSplashScreen()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
    }

    delete m_timer;
    delete m_progressBar;
}

void TTKSplashScreen::setWidget(QWidget *main)
{
    m_mainWidget = main;
}

QWidget *TTKSplashScreen::widget()
{
    return m_mainWidget;
}

void TTKSplashScreen::setElapseTime(int mstime)
{
    m_elapseTime = mstime;
    m_timer->setInterval(mstime / 100);
}

void TTKSplashScreen::setPixmap(const QPixmap &pixmap)
{
    QSplashScreen::setPixmap(pixmap);
    m_progressBar->setGeometry(0, pixmap.height() - 30, pixmap.width(), 30);
}

void TTKSplashScreen::start()
{
    m_timer->start();
    show();
}

void TTKSplashScreen::updateProgress()
{
    if(m_progressBar->value() >= 100)
    {
        if(m_timer->isActive())
        {
            m_timer->stop();
        }
        m_progressBar->setValue(0);

        emit finish();

        close();
        if(m_mainWidget)
        {
            m_mainWidget->show();
        }
    }
    m_progressBar->setValue(m_progressBar->value() + 1);
}

void TTKSplashScreen::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
