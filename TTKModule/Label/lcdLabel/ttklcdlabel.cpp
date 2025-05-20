#include "ttklcdlabel.h"

#include <QPainter>

TTKLcdLabel::TTKLcdLabel(QWidget *parent)
    : QLabel(parent),
      m_pixelSize(2),
      m_spacingSize(1),
      m_textColor(Qt::red),
      m_pixelColor(32, 32, 32),
      m_backgroundColor(Qt::black)
{

}

void TTKLcdLabel::setText(const QString &text)
{
    m_textImage = generateDotMatrix(text);
    update();
}

void TTKLcdLabel::setPixelSize(int size)
{
    m_pixelSize = size;
    update();
}

void TTKLcdLabel::setSpacingSize(int size)
{
    m_spacingSize = size;
    update();
}

void TTKLcdLabel::setTextColor(const QColor &color)
{
    m_textColor = color;
    update();
}

void TTKLcdLabel::setPixelColor(const QColor &color)
{
    m_pixelColor = color;
    update();
}

void TTKLcdLabel::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
    update();
}

QSize TTKLcdLabel::sizeHint() const
{
    return QSize(300, 100);
}

void TTKLcdLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawImage(0, 0, generateBackgroundDotMatrixImage());

    if(m_textImage.isNull())
    {
        return;
    }

    const QImage &image = generateDotMatrixImage(m_textImage);
    const int startX = (width() - image.width()) / 2;
    const int offsetY = (height() - image.height()) / 2;
    painter.drawImage(startX, offsetY, image);
}

QImage TTKLcdLabel::generateDotMatrix(const QString &text)
{
    QFont font;
    font.setFamily("宋体");
    font.setBold(true);
    // font.setItalic(true);

    const int targetHeight = height() * 0.2;
    const int pointSize = targetHeight / 2.0;
    font.setPointSize(pointSize);

    QFontMetrics fm(font);
    const int textWidth = QtFontWidth(fm, text);
    const int textHeight = fm.height();

    if(textWidth <= 0 || textHeight <= 0)
    {
        return QImage();
    }

    QImage image(textWidth, textHeight, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(image.rect(), Qt::AlignLeft | Qt::AlignVCenter, text);
    painter.end();
    return image;
}

QImage TTKLcdLabel::generateDotMatrixImage(const QImage &source)
{
    const int matrixWidth = source.width() * (m_pixelSize + m_spacingSize) - m_spacingSize;
    const int matrixHeight = source.height() * (m_pixelSize + m_spacingSize) - m_spacingSize;

    QImage image(matrixWidth, matrixHeight, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    for(int y = 0; y < source.height(); ++y)
    {
        for(int x = 0; x < source.width(); ++x)
        {
            const QRgb rgb = source.pixel(x, y);
            if(qAlpha(rgb) > 128)
            {
                const int rectX = x * (m_pixelSize + m_spacingSize);
                const int rectY = y * (m_pixelSize + m_spacingSize);
                const QRect rect(rectX, rectY, m_pixelSize, m_pixelSize);
                painter.fillRect(rect, m_textColor);
            }
        }
    }
    return image;
}

QImage TTKLcdLabel::generateBackgroundDotMatrixImage()
{
    QImage image(width(), height(), QImage::Format_ARGB32);
    image.fill(m_backgroundColor);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    for(int y = 0; y < height(); y += (m_pixelSize + m_spacingSize))
    {
        for(int x = 0; x < width(); x += (m_pixelSize + m_spacingSize))
        {
            QRect rect(x, y, m_pixelSize, m_pixelSize);
            painter.fillRect(rect, m_pixelColor);
        }
    }
    return image;
}
