#include "ttkfunctionitem.h"

#include <QBoxLayout>

#define ITEM_ICON_SZIE      25

TTKFunctionItem::TTKFunctionItem(const QString &path, const QString &text, QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 2, 2, 2);

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
    QPixmap p(50, 50);
    p.fill(Qt::red);
    m_iconLabel->setPixmap(p);
}

void TTKFunctionItem::setText(const QString &text)
{
    m_textLabel->setText(text);
}
