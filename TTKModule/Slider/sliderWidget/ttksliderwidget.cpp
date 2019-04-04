#include "ttksliderwidget.h"

QString MSliderStyle01 = " \
        QSlider::groove:horizontal{ \
        height:3px; border-radius:1px;} \
        QSlider::sub-page:horizontal{ background:%1;} \
        QSlider::add-page:horizontal{ background:%2;} \
        QSlider::handle:horizontal{ background:%3; \
        width:9px; margin-top:-3px; margin-bottom:-3px; border-radius:4px;}";

QString MSliderStyle02 = " \
        QSlider::groove:vertical{ \
        width:3px; border-radius:1px;} \
        QSlider::sub-page:vertical{ background:%1;} \
        QSlider::add-page:vertical{ background:%2;} \
        QSlider::handle:vertical{ background:%3; \
        height:9px; margin-left:-3px; margin-right:-3px; border-radius:4px;}";

TTKSliderWidget::TTKSliderWidget(QWidget *parent)
    : QSlider(parent)
{
    m_handleColor = QColor("#FFFEA1");
    m_backgroundColor = QColor("#4E4F4F");
    m_foregroundColor = QColor("#FFFEA1;");

    setupProperties();
}

void TTKSliderWidget::setHandleColor(const QColor &color)
{
    m_handleColor = color;
    setupProperties();
}

void TTKSliderWidget::setForegroundColor(const QColor &color)
{
    m_foregroundColor = color;
    setupProperties();
}

void TTKSliderWidget::setBackgroundColor(const QColor &color)
{
    m_backgroundColor = color;
    setupProperties();
}

void TTKSliderWidget::setOrientation(Qt::Orientation orientation)
{
    QSlider::setOrientation(orientation);
    setupProperties();
}

void TTKSliderWidget::setupProperties()
{
    if(orientation() == Qt::Vertical)
    {
        setStyleSheet(MSliderStyle02
                      .arg(m_foregroundColor.name())
                      .arg(m_backgroundColor.name())
                      .arg(m_handleColor.name()));
    }
    else
    {
        setStyleSheet(MSliderStyle01
                      .arg(m_backgroundColor.name())
                      .arg(m_foregroundColor.name())
                      .arg(m_handleColor.name()));
    }
}
