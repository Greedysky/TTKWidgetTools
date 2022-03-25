#include "ttkcodearealabel.h"
#if TTK_QT_VERSION_CHECK(5,10,0)
#  include <QRandomGenerator>
#endif
#include <QDateTime>
#include <QPainter>
#include <QPainterPath>

static int random(int value)
{
#if TTK_QT_VERSION_CHECK(5,10,0)
    return QRandomGenerator::global()->bounded(value);
#else
    return qrand() % value;
#endif
}

#define DEF_CODECOUNT       4
#define DEF_NOISYPOINTCOUNT 60
#define DEF_CONVERSEROTATE  10
#define DEF_CONVERSESCALE   15

TTKCodeAreaLabel::TTKCodeAreaLabel(QWidget *parent)
    : QLabel(parent)
{
#if !TTK_QT_VERSION_CHECK(5,10,0)
    qsrand(QDateTime::currentMSecsSinceEpoch());
#endif
    m_codeRange << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" <<
       "a" << "b" << "c" << "d" << "e" << "f" << "g" << "h" << "i" << "j" << "k" << "l" << "m" << "n" <<
       "o" << "p" << "q" << "r" << "s" << "t" << "u" << "v" << "w" << "x" << "y" << "z" <<
       "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "I" << "J" << "K" << "L" << "M" << "N" <<
       "O" << "P" << "Q" << "R" << "S" << "T" << "U" << "V" << "W" << "X" << "Y" << "Z";

    m_codeColor << Qt::darkRed << Qt::darkGreen << Qt::darkBlue << Qt::darkCyan
                 << Qt::darkMagenta << Qt::darkYellow << Qt::darkGray;

    m_noisyPointCount = DEF_NOISYPOINTCOUNT;
    m_converseRotate = DEF_CONVERSEROTATE;
    m_converseScale = DEF_CONVERSESCALE;
    m_codeCount = DEF_CODECOUNT;
}

void TTKCodeAreaLabel::renderPicture()
{
    QStringList number;
    for(int i = 0; i < m_codeCount; ++i)
    {
        number << m_codeRange[random(m_codeRange.count())];
    }

    m_code.clear();
    m_codePic.clear();

    QFont font;
    font.setBold(true);
    font.setPixelSize(25);

    for(int i = 0; i < m_codeCount; ++i)
    {
        m_code.append(number[i]);
        QPainterPath path(QPointF(0, 0));
        QRect fontBoundingRect = QFontMetrics(font).boundingRect(number[i]);
        path.addText(-QPointF(fontBoundingRect.center()), font, number[i]);
        m_codePic << path;
    }
    update();
}

void TTKCodeAreaLabel::setCodeCount(int nCount)
{
    m_codeCount = nCount;
    renderPicture();
}

void TTKCodeAreaLabel::setNoisyPointCount(int nCount)
{
    m_noisyPointCount = nCount;
    renderPicture();
}

QSize TTKCodeAreaLabel::sizeHint() const
{
    return QSize(180, 180);
}

void TTKCodeAreaLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.fillRect(rect(), QBrush(Qt::white));

    painter.translate(0, 0);
    painter.save();
    painter.translate(rect().center().x() - m_codePic.count() / 2 * 6, rect().center().y());

    for(int i = 0; i < m_codePic.count(); ++i)
    {
        drawConversion(painter);
        painter.fillPath(m_codePic[i], QBrush(m_codeColor[random(m_codeColor.count())]));
        painter.translate(10, 0);
    }
    painter.restore();

    drawOutline(painter);
    drawNoisyPoint(painter);
}

void TTKCodeAreaLabel::drawOutline(QPainter &painter)
{
    painter.setPen(Qt::darkGreen);
    painter.setPen(Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(rect());
}

void TTKCodeAreaLabel::drawNoisyPoint(QPainter &painter)
{
    painter.setPen(Qt::red);
    painter.setPen(Qt::DotLine);
    painter.setBrush(Qt::NoBrush);

    for(int i = 0; i < m_noisyPointCount; ++i)
    {
        painter.drawPoint(QPointF(random(size().width()), random(size().height())));
    }
}

void TTKCodeAreaLabel::drawConversion(QPainter &painter)
{
    if(random(2))
    {
        painter.rotate(random(m_converseRotate));
    }
    else
    {
        painter.rotate(-random(m_converseRotate));
    }
    painter.scale((random(m_converseScale + (100 - m_converseScale))) / 100.0 ,
                  (random(m_converseScale + (100 - m_converseScale))) / 100.0);
}
