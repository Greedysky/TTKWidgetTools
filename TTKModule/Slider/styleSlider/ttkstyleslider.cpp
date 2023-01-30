#include "ttkstyleslider.h"

const QString SliderStyle01 = " \
        QSlider::groove:horizontal{ \
        height:3px; border-radius:1px;} \
        QSlider::sub-page:horizontal{ background:%1;} \
        QSlider::add-page:horizontal{ background:%2;} \
        QSlider::handle:horizontal{ background:%3; \
        width:9px; margin-top:-3px; margin-bottom:-3px; border-radius:4px;}";

const QString SliderStyle02 = " \
        QSlider::groove:vertical{ \
        width:3px; border-radius:1px;} \
        QSlider::sub-page:vertical{ background:%1;} \
        QSlider::add-page:vertical{ background:%2;} \
        QSlider::handle:vertical{ background:%3; \
        height:9px; margin-left:-3px; margin-right:-3px; border-radius:4px;}";

TTKStyleSlider::TTKStyleSlider(QWidget *parent)
    : QSlider(parent),
      m_handleColor(0xFF, 0xFE, 0xA1),
      m_backgroundColor(0x4E, 0x4F, 0x4F),
      m_foregroundColor(0xFF, 0xFE, 0xA1)
{
    setupProperties();
}

void TTKStyleSlider::setHandleColor(const QColor &color)
{
    m_handleColor = color;
    setupProperties();
    update();
}

void TTKStyleSlider::setForegroundColor(const QColor &color)
{
    m_foregroundColor = color;
    setupProperties();
    update();
}

void TTKStyleSlider::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
    setupProperties();
    update();
}

QSize TTKStyleSlider::sizeHint() const
{
    return QSize(200, 200);
}

void TTKStyleSlider::setOrientation(Qt::Orientation orientation)
{
    QSlider::setOrientation(orientation);
    setupProperties();
}

void TTKStyleSlider::setupProperties()
{
    if(orientation() == Qt::Vertical)
    {
        setStyleSheet(SliderStyle02.arg(m_foregroundColor.name(), m_backgroundColor.name(), m_handleColor.name()));
    }
    else
    {
        setStyleSheet(SliderStyle01.arg(m_backgroundColor.name(), m_foregroundColor.name(), m_handleColor.name()));
    }
}
