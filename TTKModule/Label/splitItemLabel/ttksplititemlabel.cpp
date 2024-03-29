#include "ttksplititemlabel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QFontMetrics>

TTKSplitItemLabel::TTKSplitItemLabel(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignVCenter);
    setMouseTracking(true);
}

void TTKSplitItemLabel::setSplitString(const QString &str)
{
    m_splitString = str;
    update();
}

void TTKSplitItemLabel::enterEvent(QtEnterEvent *event)
{
    QLabel::enterEvent(event);
    m_lineGeometry = QRectF();
    m_currentString.clear();
    update();
}

void TTKSplitItemLabel::leaveEvent(QEvent *event)
{
    QLabel::leaveEvent(event);
    m_lineGeometry = QRectF();
    m_currentString.clear();
    update();
}

void TTKSplitItemLabel::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    if(event->button() == Qt::LeftButton && !m_currentString.isEmpty())
    {
        Q_EMIT changed(m_currentString);
    }
}

void TTKSplitItemLabel::mouseMoveEvent(QMouseEvent *event)
{
    QLabel::mouseMoveEvent(event);

    unsetCursor();
    m_lineGeometry = QRectF();
    m_currentString.clear();

    const QFontMetrics ftm(font());
    const QStringList data(text().split(" - "));
    int offset = 0;

    for(const QString &var : qAsConst(data))
    {
        const int fs = QtFontWidth(ftm, var.trimmed());
        if(offset <= event->pos().x() && event->pos().x() <= offset + fs)
        {
            setCursor(QCursor(Qt::PointingHandCursor));
            m_lineGeometry = QRectF(offset, height() - 3, fs, 0.5);
            m_currentString = var.trimmed();
            break;
        }

        offset += (fs + QtFontWidth(ftm, " - "));
    }
    update();
}

void TTKSplitItemLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.drawRect(m_lineGeometry);
}
