#include "ttkcustompiewidget.h"

#include <QPainter>

TTKCustomPieWidget::TTKCustomPieWidget(QWidget *parent)
    : QWidget(parent)
{
    m_explodedAll = true;
    m_explodedIndex = 0;
    m_showPercent = true;

    m_textColor = QColor(255, 255, 255);
    m_borderColor = QColor(0, 0, 0);
}

void TTKCustomPieWidget::setExplodedAll(bool explodedAll)
{
    if(m_explodedAll != explodedAll)
    {
        m_explodedAll = explodedAll;
        update();
    }
}

void TTKCustomPieWidget::setExplodedIndex(int index)
{
    if(m_explodedIndex != index)
    {
        m_explodedIndex = index;
        update();
    }
}

void TTKCustomPieWidget::setTextColor(const QColor &textColor)
{
    if(m_textColor != textColor)
    {
        m_textColor = textColor;
        update();
    }
}

void TTKCustomPieWidget::setBorderColor(const QColor &borderColor)
{
    if(m_borderColor != borderColor)
    {
        m_borderColor = borderColor;
        update();
    }
}

void TTKCustomPieWidget::setDataPie(const QList<PieData> &datas)
{
    m_datas = datas;
}

void TTKCustomPieWidget::appendPie(const QString &label, double value, const QColor &color)
{
    m_datas.push_back({color, label, value});
}

QSize TTKCustomPieWidget::sizeHint() const
{
    return QSize(180, 180);
}

void TTKCustomPieWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawPie(&painter);
}

void TTKCustomPieWidget::drawPie(QPainter *painter)
{
    painter->save();
    const int radius = 93;
    const QRect rect(-radius, -radius, radius * 2, radius * 2);
    double startAngle = 0;
    const double sum = getSumValue();

    const int count = m_datas.count();
    for(int i = 0; i < count; ++i)
    {
        const double value = m_datas[i].m_value;
        const double arcLength = value / sum * 360;
        const double percent = value / sum * 100;
        QRect pieRect = rect;

        painter->setPen(Qt::NoPen);
        if(m_explodedIndex == i || m_explodedAll)
        {
            painter->setPen(m_borderColor);
        }

        painter->setBrush(m_datas[i].m_color);
        painter->drawPie(pieRect, startAngle * 16, arcLength * 16);

        QString strValue = m_datas[i].m_text;
        if(m_showPercent && percent > 7)
        {
            strValue = QString("%1%2%3%").arg(strValue).arg(strValue.isEmpty() ? "" : "\n").arg(QString::number(percent, 'f', 0));
        }

        const int mid = startAngle + arcLength / 2;
        int offset = 60;
        if(percent >= 50)
        {
            offset = 45;
        }
        else if (percent >= 30)
        {
            offset = 55;
        }
        else if (percent >= 15)
        {
            offset = 60;
        }

        const QPoint &p = getOffsetPoint(mid, offset);
        QRect textRect;
        textRect.setX(p.x() - 40);
        textRect.setY(p.y() - 30);
        textRect.setWidth(80);
        textRect.setHeight(60);
        painter->setPen(Qt::black);

        QFont font;
        font.setPixelSize(strValue.isEmpty() ? 20 : 17);
        painter->setFont(font);
        painter->setPen(m_textColor);
        painter->drawText(textRect, Qt::AlignCenter, strValue);
        startAngle += arcLength;
    }
    painter->restore();
}

void TTKCustomPieWidget::clearPie()
{
    m_datas.clear();
    update();
}

double TTKCustomPieWidget::getSumValue()
{
    double sum = 0;
    foreach(const PieData& data, m_datas)
    {
        sum += data.m_value;

    }
    return sum;
}

QPoint TTKCustomPieWidget::getOffsetPoint(double angel, int offset)
{
    return QPoint(0, 0);
}
