#include "ttkfunctionlistvwidget.h"

#include <QPainter>
#include <QBoxLayout>

TTKFunctionListVWidget::TTKFunctionListVWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 18, 0, 0);
    layout->setSpacing(0);

    for(int i=0; i<5; ++i)
    {
        TTKFunctionItemWidget *item = new TTKFunctionItemWidget(this);
        item->setLabelText("Hello World");
        item->setLabelIcon(QString(), QString());
        connect(item, SIGNAL(selectedChanged(TTKFunctionItemWidget*)), SLOT(selectedChanged(TTKFunctionItemWidget*)));
        layout->addWidget(item);
        m_items << item;
    }

    m_items.first()->setSelectedMode(true);

    layout->addStretch(1);
    setLayout(layout);
}

TTKFunctionListVWidget::~TTKFunctionListVWidget()
{
    qDeleteAll(m_items);
}

void TTKFunctionListVWidget::resizeMode(bool mode)
{
    foreach(TTKFunctionItemWidget *it, m_items)
    {
        it->resizeMode(mode);
    }
}

void TTKFunctionListVWidget::selectedChanged(TTKFunctionItemWidget *item)
{
    int index = m_items.indexOf(item);
    if(index == -1)
    {
        return;
    }

    emit currentIndexChanged(index);

    foreach(TTKFunctionItemWidget *it, m_items)
    {
        it->setSelectedMode(false);
    }
    m_items[index]->setSelectedMode(true);
}

void TTKFunctionListVWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
