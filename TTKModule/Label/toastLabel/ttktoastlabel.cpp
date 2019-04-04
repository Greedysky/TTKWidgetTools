#include "ttktoastlabel.h"

#include <QPainter>
#include <QPropertyAnimation>

TTKToastLabel::TTKToastLabel(QWidget *parent)
    : QLabel(parent)
{
    setWindowFlags( Qt::Window | Qt::FramelessWindowHint );
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_QuitOnClose);
    setAttribute(Qt::WA_DeleteOnClose);

    m_font = font();
    connect(&m_timer, SIGNAL(timeout()), SLOT(closeAnimation()));
    m_timer.setInterval(1500);
    m_timer.start();
}

TTKToastLabel::TTKToastLabel(const QString &text, QWidget *parent)
    : TTKToastLabel(parent)
{
    setText(text);
}

TTKToastLabel::~TTKToastLabel()
{
    m_timer.stop();
}

void TTKToastLabel::setFontMargin(int height, int width)
{
    m_margin.setX(height);
    m_margin.setY(width);
}

void TTKToastLabel::setTimerInterval(int msecond)
{
    m_timer.stop();
    m_timer.setInterval(msecond);
    m_timer.start();
}

int TTKToastLabel::getTimerInterval() const
{
    return m_timer.interval();
}

void TTKToastLabel::setFontSize(int size)
{
    m_font.setPointSize(size);
    setFont(m_font);
}

int TTKToastLabel::getFontSize() const
{
    return m_font.pointSize();
}

void TTKToastLabel::setBold(bool bold)
{
    m_font.setBold(bold);
    setFont(m_font);
}

bool TTKToastLabel::bold() const
{
    return m_font.bold();
}

void TTKToastLabel::popup(QWidget *parent)
{
    QPoint globalPoint = parent->mapToGlobal(QPoint(0, 0));
    move( globalPoint.x() + (parent->width() - width())/2,
          globalPoint.y() + (parent->height() - height())/2);
    show();

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(500);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

void TTKToastLabel::setText(const QString &text)
{
    QFontMetrics metrics = QFontMetrics(m_font);
    setFixedSize(metrics.width(text) + m_margin.x(), metrics.height() + m_margin.y());
    QLabel::setText(text);
}

void TTKToastLabel::closeAnimation()
{
    m_timer.stop();
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), SLOT(close()));
}

void TTKToastLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0, 0, 0, 175));
    painter.drawRoundRect(rect(), 6, 6);

    painter.setPen(QColor(255, 255, 255));
    painter.drawText(rect(), Qt::AlignCenter, text());
    painter.end();
}
