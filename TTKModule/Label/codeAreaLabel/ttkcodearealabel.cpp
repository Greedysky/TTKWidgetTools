#include "ttkcodearealabel.h"
#include "ttktime.h"
#include <QPainter>
#include <QPainterPath>

static constexpr int DEF_CODECOUNT = 4;
static constexpr int DEF_NOISYPOINTCOUNT = 60;
static constexpr int DEF_CONVERSEROTATE = 10;
static constexpr int DEF_CONVERSESCALE = 15;

TTKCodeAreaLabel::TTKCodeAreaLabel(QWidget *parent)
    : QLabel(parent),
      m_noisyPointCount(DEF_NOISYPOINTCOUNT),
      m_converseRotate(DEF_CONVERSEROTATE),
      m_converseScale(DEF_CONVERSESCALE),
      m_codeCount(DEF_CODECOUNT)
{
    TTK::initRandom();

    m_codeRange << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" <<
       "a" << "b" << "c" << "d" << "e" << "f" << "g" << "h" << "i" << "j" << "k" << "l" << "m" << "n" <<
       "o" << "p" << "q" << "r" << "s" << "t" << "u" << "v" << "w" << "x" << "y" << "z" <<
       "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "I" << "J" << "K" << "L" << "M" << "N" <<
       "O" << "P" << "Q" << "R" << "S" << "T" << "U" << "V" << "W" << "X" << "Y" << "Z";

    m_codeColor << Qt::darkRed << Qt::darkGreen << Qt::darkBlue << Qt::darkCyan
                << Qt::darkMagenta << Qt::darkYellow << Qt::darkGray;
}

void TTKCodeAreaLabel::renderPicture()
{
    QStringList number;
    for(int i = 0; i < m_codeCount; ++i)
    {
        number << m_codeRange[TTK::random(m_codeRange.count())];
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
        const QRect &fontBoundingRect = QFontMetrics(font).boundingRect(number[i]);
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
    return QSize(200, 200);
}

void TTKCodeAreaLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QBrush(Qt::white));

    painter.translate(0, 0);
    painter.save();
    painter.translate(rect().center().x() - m_codePic.count() / 2 * 6, rect().center().y());

    for(const QPainterPath &path :  qAsConst(m_codePic))
    {
        drawConversion(&painter);
        painter.fillPath(path, QBrush(m_codeColor[TTK::random(m_codeColor.count())]));
        painter.translate(10, 0);
    }
    painter.restore();

    drawOutline(&painter);
    drawNoisyPoint(&painter);
}

void TTKCodeAreaLabel::drawOutline(QPainter *painter)
{
    painter->setPen(Qt::darkGreen);
    painter->setPen(Qt::DashLine);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(rect());
}

void TTKCodeAreaLabel::drawNoisyPoint(QPainter *painter)
{
    painter->setPen(Qt::red);
    painter->setPen(Qt::DotLine);
    painter->setBrush(Qt::NoBrush);

    for(int i = 0; i < m_noisyPointCount; ++i)
    {
        painter->drawPoint(QPointF(TTK::random(size().width()), TTK::random(size().height())));
    }
}

void TTKCodeAreaLabel::drawConversion(QPainter *painter)
{
    if(TTK::random(2))
    {
        painter->rotate(TTK::random(m_converseRotate));
    }
    else
    {
        painter->rotate(-TTK::random(m_converseRotate));
    }
    painter->scale((TTK::random(m_converseScale + (100 - m_converseScale))) / 100.0, (TTK::random(m_converseScale + (100 - m_converseScale))) / 100.0);
}
