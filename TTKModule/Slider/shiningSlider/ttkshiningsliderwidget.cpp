#include "ttkshiningsliderwidget.h"
#include "ttkgiflabelwidget.h"

#include <qmath.h>

TTKShiningSliderWidget::TTKShiningSliderWidget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new TTKGifLabelWidget(this);
    m_label->setType(TTKGifLabelWidget::Gif_Ballon_White);
    m_label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    m_label->move(15, 5);
    m_label->hide();

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setValue(0);
    m_slider->setGeometry(15, m_label->width()/2, width() - m_label->width(), 10);
    m_slider->setCursor(QCursor(Qt::PointingHandCursor));
    connect(m_slider, SIGNAL(sliderMoved(int)), SLOT(sliderMovedAt(int)));
}

TTKShiningSliderWidget::~TTKShiningSliderWidget()
{
    delete m_label;
    delete m_slider;
}

void TTKShiningSliderWidget::setPlayState(bool state)
{
    if(state)
    {
        m_label->show();
        m_label->raise();
        m_label->start();
    }
    else
    {
        m_label->stop();
        m_label->hide();
    }
}

void TTKShiningSliderWidget::setValue(qint64 value) const
{
    sliderMovedAt(value);
    m_slider->setValue(value);
}

void TTKShiningSliderWidget::setRange(int min, int max)
{
    m_slider->setRange(min, max);
}

void TTKShiningSliderWidget::sliderMovedAt(int pos) const
{
    int max = m_slider->maximum();
    if(max > 0)
    {
        float delta = m_slider->width()*(-0.015/800) + 0.0275;
        m_label->move(ceil(qint64(pos)*m_slider->width()*(1.0 - delta)/max) - 1, 5);
    }
}

void TTKShiningSliderWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_slider->setFixedWidth(width() - m_label->width());
    sliderMovedAt(m_slider->value());
}
