#include "ttkpropertycontainwidget.h"

#include <QBoxLayout>

TTKPropertyContainWidget::TTKPropertyContainWidget(QWidget *parent)
    : QWidget(parent),
      m_item(nullptr)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);
}

TTKPropertyContainWidget::~TTKPropertyContainWidget()
{
    delete m_item;
}

void TTKPropertyContainWidget::addItem(QWidget *item)
{
    delete m_item;
    m_item = item;
    layout()->addWidget(item);
}
