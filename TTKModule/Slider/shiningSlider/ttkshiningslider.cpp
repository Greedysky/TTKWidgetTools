#include "ttkshiningslider.h"
#include "ttkgifprogresswidget.h"

#include <qmath.h>

TTKShiningSlider::TTKShiningSlider(QWidget *parent)
    : QWidget(parent)
{
    m_label = new TTKGifProgressWidget(this);
    m_label->setType(TTKGifProgressWidget::BallonWhite);
    m_label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    m_label->move(15, 5);
    m_label->hide();

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setValue(0);
    m_slider->setGeometry(15, m_label->width()/2, width() - m_label->width(), 10);
    m_slider->setCursor(QCursor(Qt::PointingHandCursor));
    connect(m_slider, SIGNAL(sliderMoved(int)), SLOT(sliderMovedAt(int)));
}

TTKShiningSlider::~TTKShiningSlider()
{
    delete m_label;
    delete m_slider;
}

void TTKShiningSlider::setPlayState(bool state)
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
    update();
}

void TTKShiningSlider::setValue(qint64 value)
{
    sliderMovedAt(value);
    m_slider->setValue(value);
    update();
}

void TTKShiningSlider::setRange(int min, int max)
{
    m_slider->setRange(min, max);
    update();
}

void TTKShiningSlider::setMinimum(int min)
{
    m_slider->setMinimum(min);
    update();
}

void TTKShiningSlider::setMaximum(int max)
{
    m_slider->setMaximum(max);
    update();
}

QSize TTKShiningSlider::sizeHint() const
{
    return QSize(180, 40);
}

void TTKShiningSlider::sliderMovedAt(int pos) const
{
    int max = m_slider->maximum();
    if(max > 0)
    {
        float delta = m_slider->width()*(-0.015/800) + 0.0275;
        m_label->move(ceil(qint64(pos)*m_slider->width()*(1.0 - delta)/max) - 1, 5);
    }
}

void TTKShiningSlider::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_slider->setFixedWidth(width() - m_label->width());
    sliderMovedAt(m_slider->value());
}
