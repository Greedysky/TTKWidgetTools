#include "ttkpuzzlewidget.h"
#if TTK_QT_VERSION_CHECK(5,10,0)
#include <QRandomGenerator>
#endif
#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <QBoxLayout>
#include <QDateTime>

static int random(int value)
{
#if TTK_QT_VERSION_CHECK(5,10,0)
    return QRandomGenerator::global()->bounded(value);
#else
    return qrand() % value;
#endif
}

TTKPuzzleItemWidget::TTKPuzzleItemWidget(QWidget *parent)
    : QWidget(parent)
{
    m_value = 0;
    m_squareWidth = 100;
    m_squareRadius = 30;

#if !TTK_QT_VERSION_CHECK(5,10,0)
    qsrand(QDateTime::currentMSecsSinceEpoch());
#endif
}

void TTKPuzzleItemWidget::setSquareWidth(int squareWidth)
{
    m_squareWidth = squareWidth;
    update();
}

void TTKPuzzleItemWidget::setSquareRadius(int squareRadius)
{
    m_squareRadius = squareRadius;
    update();
}

void TTKPuzzleItemWidget::setPixmap(const QString& pixmap)
{
    m_pixmap = pixmap;
    QTimer::singleShot(10, this, SLOT(updatePixmap()));
}

void TTKPuzzleItemWidget::updatePixmap()
{
    const int offset = m_squareWidth + m_squareRadius;
    m_offsetPoint.rx() = qBound(0, random(width()) + offset, width() - offset);
    m_offsetPoint.ry() = qBound(0, random(height()) + offset, height() - offset);
    update();
}

void TTKPuzzleItemWidget::setValue(int value)
{
    const int offset = m_squareWidth + m_squareRadius;
    m_value = qBound(0, value, width() - offset + m_offsetPoint.x());
    update();
}

void TTKPuzzleItemWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    QPainterPath clippath;
    clippath.addRoundedRect(rect(), 4, 4);
    painter.setClipPath(clippath);

    const QPixmap& pixmap = QPixmap(m_pixmap).scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(0, 0, width(), height(), pixmap);

    QPainterPath cutoutPath;
    cutoutPath.setFillRule(Qt::WindingFill);

    const QRect rect(m_offsetPoint, QSize(m_squareWidth, m_squareWidth));
    cutoutPath.addRoundedRect(rect, 2, 2);
    cutoutPath.addEllipse(rect.center().x() - m_squareRadius / 2, rect.top() - m_squareRadius + 6, m_squareRadius, m_squareRadius);

    QPainterPath subellipsePath;
    subellipsePath.addEllipse(rect.right() - m_squareRadius + 6, rect.center().y() - m_squareRadius / 2, m_squareRadius, m_squareRadius);
    cutoutPath -= subellipsePath;

    painter.setPen(QPen(QColor(80, 80, 80), 1));
    painter.setBrush(QColor(100, 100, 100, 220));
    painter.drawPath(cutoutPath);

    QPixmap puzzlePixmap(size());
    puzzlePixmap.fill(Qt::transparent);

    QPainter puzzlePainter(&puzzlePixmap);
    puzzlePainter.setRenderHints(QPainter::Antialiasing);
    puzzlePainter.setClipPath(cutoutPath);
    puzzlePainter.setPen(QPen(QColor(80, 80, 80), 2));
    puzzlePainter.setBrush(QColor(200, 200, 200, 100));
    puzzlePainter.drawPixmap(0, 0, width(), height(), pixmap);
    puzzlePainter.drawPath(cutoutPath);

    painter.drawPixmap(m_value - m_offsetPoint.x(), 0, width(), height(), puzzlePixmap);
}



TTKPuzzleWidget::TTKPuzzleWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500, 350);

    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    m_item = new TTKPuzzleItemWidget(this);
    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setRange(0, width());

    layout->addWidget(m_item);
    layout->addWidget(m_slider);

    m_item->setFixedSize(500, 300);

    connect(m_slider, SIGNAL(valueChanged(int)), m_item, SLOT(setValue(int)));
}

void TTKPuzzleWidget::setSquareWidth(int squareWidth)
{
    m_item->setSquareWidth(squareWidth);
}

void TTKPuzzleWidget::setSquareRadius(int squareRadius)
{
    m_item->setSquareRadius(squareRadius);
}

void TTKPuzzleWidget::setPixmap(const QString& pixmap)
{
    m_item->setPixmap(pixmap);
    m_slider->setValue(0);
}

QSize TTKPuzzleWidget::sizeHint() const
{
    return size();
}
