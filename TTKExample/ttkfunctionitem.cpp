#include "ttkfunctionitem.h"

#include <QBoxLayout>
#include <QMouseEvent>

#define ITEM_ICON_SZIE      25
#define ITEM_ROW_HEIGHT     40

TTKFunctionItem::TTKFunctionItem(int index, const QString &path, const QString &text, QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 2, 2, 2);

    m_index = index;
    m_iconLabel = new QLabel(this);
    m_textLabel = new QLabel(this);
    m_textLabel->setAlignment(Qt::AlignVCenter);
    m_iconLabel->setFixedWidth(ITEM_ICON_SZIE);

    layout->addWidget(m_iconLabel);
    layout->addWidget(m_textLabel);

    setIcon(path);
    setText(text);
    setLayout(layout);
    setFixedHeight(ITEM_ICON_SZIE + 5);
}

TTKFunctionItem::~TTKFunctionItem()
{
    delete m_iconLabel;
    delete m_textLabel;
}

void TTKFunctionItem::setIcon(const QString &path)
{
    m_iconLabel->setPixmap(path);
}

void TTKFunctionItem::setText(const QString &text)
{
    m_textLabel->setText(text);
}

void TTKFunctionItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(m_index);
    }
}



TTKFunctionItemRow::TTKFunctionItemRow(QWidget *parent)
    : QLabel(parent)
{
    QVBoxLayout *widgetayout = new QVBoxLayout(this);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    setLayout(widgetayout);
}

TTKFunctionItemRow::~TTKFunctionItemRow()
{
    qDeleteAll(m_items);
}

void TTKFunctionItemRow::addItem(const QString &path, const QString &text)
{
    const int count = layout()->count();
    TTKFunctionItem *item = new TTKFunctionItem(count, path, text, this);
    connect(item, SIGNAL(clicked(int)), SIGNAL(rowClicked(int)));
    layout()->addWidget(item);

    m_items << item;
    setFixedHeight((count + 1) * ITEM_ROW_HEIGHT);
}
