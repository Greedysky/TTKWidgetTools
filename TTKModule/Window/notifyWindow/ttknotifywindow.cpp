#include "ttknotifywindow.h"

#include <QUrl>
#include <QTimer>
#include <QBoxLayout>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include <QApplication>
#include <QDesktopWidget>
#include <QDesktopServices>

#define RIGHT  10
#define BOTTOM 10
#define HEIGHT 60
#define WIDTH  300
#define SPACE  20

TTKNotify::TTKNotify(int time, QWidget *parent)
    : QWidget(parent),
      m_displayTime(time)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    m_backgroundLabel = new QLabel(this);
    m_backgroundLabel->move(0, 0);
    m_backgroundLabel->setObjectName("notify-background");

    QHBoxLayout *mainLayout = new QHBoxLayout(m_backgroundLabel);
    QVBoxLayout *contentLayout = new QVBoxLayout();

    m_iconLabel = new QLabel(m_backgroundLabel);
    m_iconLabel->setFixedWidth(40);
    m_iconLabel->setAlignment(Qt::AlignCenter);

    m_titleLabel = new QLabel(m_backgroundLabel);
    m_titleLabel->setObjectName("notify-title");

    m_bodyLabel = new QLabel(m_backgroundLabel);
    m_bodyLabel->setObjectName("notify-body");

    QFont font = m_bodyLabel->font();
    font.setPixelSize(12);
    m_bodyLabel->setFont(font);

    contentLayout->addWidget(m_titleLabel);
    contentLayout->addWidget(m_bodyLabel);

    mainLayout->addWidget(m_iconLabel);
    mainLayout->addSpacing(5);
    mainLayout->addLayout(contentLayout);

    m_closeBtn = new QPushButton("×", m_backgroundLabel);
    m_closeBtn->setObjectName("notify-close-btn");
    m_closeBtn->setFixedSize(24, 24);
    connect(m_closeBtn, SIGNAL(clicked()), SIGNAL(disappeared()));
    setStyleSheet("#notify-background {border: 1px solid #ccc; background:white;border-radius: 4px;} "
                  "#notify-title{font-weight: bold;color: #333;font-size: 14px;}"
                  "#notify-body{color: #444;}"
                  "#notify-close-btn{border: 0;color: #999;}"
                  "#notify-close-btn:hover{background: #ccc;}");
}

void TTKNotify::setIcon(const QString &icon)
{
    m_icon = icon;
}

void TTKNotify::setTitle(const QString &title)
{
    m_title = title;
}

void TTKNotify::setBody(const QString &body)
{
    m_body = body;
}

void TTKNotify::setUrl(const QString &url)
{
    m_url = url;
}

void TTKNotify::showGriant()
{
    show();
    m_titleLabel->setText(m_title);

    QPixmap pix = QPixmap(m_icon);
    pix = pix.scaled(QSize(30, 30), Qt::KeepAspectRatio);
    m_iconLabel->setPixmap(pix);

    m_backgroundLabel->setFixedSize(size());
    m_closeBtn->move(m_backgroundLabel->width() - m_closeBtn->width(), 0);

    QFontMetrics elidfont(m_bodyLabel->font());
    const QString &text = elidfont.elidedText(m_body, Qt::ElideRight, m_bodyLabel->width() - 5);
    m_bodyLabel->setText(text);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    connect(animation, SIGNAL(finished()), SLOT(showGriantChanged()));
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setDuration(200);
    animation->start();
}

void TTKNotify::hideGriant()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    connect(animation, SIGNAL(finished()), SLOT(hideGriantChanged()));
    animation->setStartValue(this->windowOpacity());
    animation->setEndValue(0);
    animation->setDuration(200);
    animation->start();
}

void TTKNotify::showGriantChanged()
{
    QPropertyAnimation *animation = qobject_cast<QPropertyAnimation*>(sender());
    animation->deleteLater();
    QTimer::singleShot(m_displayTime, this, SLOT(hideGriant()));
}

void TTKNotify::hideGriantChanged()
{
    QPropertyAnimation *animation = qobject_cast<QPropertyAnimation*>(sender());
    hide();
    animation->deleteLater();
    emit disappeared();
}

void TTKNotify::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(!m_url.isEmpty())
        {
            QDesktopServices::openUrl(QUrl(m_url));
        }
        hideGriant();
    }
}



TTKNotifyManager::TTKNotifyManager(QObject *parent)
    : QObject(parent),
      m_maxCount(6),
      m_displayTime(5000)
{

}

void TTKNotifyManager::notify(const QString &title, const QString &body, const QString &icon, const QString &url)
{
    m_dataQueue.enqueue({title, body, icon, url});
    showNext();
}

void TTKNotifyManager::setMaxCount(int count)
{
    m_maxCount = count;
}

void TTKNotifyManager::setDisplayTime(int ms)
{
    m_displayTime = ms;
}

void TTKNotifyManager::disappeared()
{
   TTKNotify *notify = qobject_cast<TTKNotify*>(sender());
    m_notifyList.removeAll(notify);
    rearrange();

    if(m_notifyList.size() == m_maxCount - 1)
    {
        QTimer::singleShot(300, this, SLOT(showNext()));
    }
    else
    {
        showNext();
    }
    notify->deleteLater();
}

void TTKNotifyManager::rearrange()
{
    QDesktopWidget *desktop = QApplication::desktop();
    const QRect &desktopRect = desktop->availableGeometry();
    const QPoint &bottomRignt = desktopRect.bottomRight();

    for(auto itr = m_notifyList.begin(); itr != m_notifyList.end(); ++itr)
    {
        TTKNotify *notify = *itr;
        const int index = m_notifyList.indexOf(notify);

        const QPoint &pos = bottomRignt - QPoint(WIDTH + RIGHT, (HEIGHT + SPACE) * (index + 1) - SPACE + BOTTOM);
        QPropertyAnimation *animation = new QPropertyAnimation(notify, "pos", this);
        connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));
        animation->setStartValue(notify->pos());
        animation->setEndValue(pos);
        animation->setDuration(300);
        animation->start();
    }
}


void TTKNotifyManager::showNext()
{
    if(m_notifyList.size() >= m_maxCount || m_dataQueue.isEmpty())
    {
        return;
    }

    const TTKNotifyData &data = m_dataQueue.dequeue();
    TTKNotify *notify = new TTKNotify(m_displayTime);
    connect(notify, SIGNAL(disappeared()), SLOT(disappeared()));
    notify->setIcon(data.m_icon);
    notify->setTitle(data.m_title);
    notify->setBody(data.m_body);
    notify->setUrl(data.m_url);
    notify->setFixedSize(WIDTH, HEIGHT);

    QDesktopWidget *desktop = QApplication::desktop();
    const QRect &desktopRect = desktop->availableGeometry();
    const QPoint &bottomRignt = desktopRect.bottomRight();
    const QPoint &pos = bottomRignt - QPoint(notify->width() + RIGHT, (HEIGHT + SPACE) * (m_notifyList.size() + 1) - SPACE + BOTTOM);

    notify->move(pos);
    notify->showGriant();
    m_notifyList.append(notify);
}
