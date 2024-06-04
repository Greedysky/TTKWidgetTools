#include "ttkfunctiontoolboxwidget.h"

#include <QPainter>
#include <QScrollBar>
#include <QScrollArea>
#include <QMouseEvent>

static constexpr int RENAME_WIDTH = 220;

TTKFunctionToolBoxTopWidget::TTKFunctionToolBoxTopWidget(int index, const QString &text, QWidget *parent)
    : QWidget(parent),
      m_index(index)
{
    setAcceptDrops(true);
    setFixedHeight(40);

    QHBoxLayout *topLayout = new QHBoxLayout(this);
    topLayout->setContentsMargins(3, 0, 0, 0);
    topLayout->setSpacing(0);

    m_labelIcon = new QLabel(this);
    m_labelIcon->setPixmap(QPixmap(":/res/up"));
    m_labelText = new QLabel(this);
    m_labelText->setStyleSheet("color:#444444;");
    m_labelText->setText(text);

    topLayout->addWidget(m_labelIcon);
    topLayout->addWidget(m_labelText);
    topLayout->addStretch(1);

    setLayout(topLayout);
}

TTKFunctionToolBoxTopWidget::~TTKFunctionToolBoxTopWidget()
{
    delete m_labelIcon;
    delete m_labelText;
}

void TTKFunctionToolBoxTopWidget::setExpand(bool expand)
{
    m_labelIcon->setPixmap(QPixmap(expand ? ":/res/down" : ":/res/up"));
}

bool TTKFunctionToolBoxTopWidget::isExpand() const
{
    const QPixmap &pix = QtLablePixmap(m_labelIcon);
    return pix.cacheKey() == QPixmap(":/res/down").cacheKey();
}

void TTKFunctionToolBoxTopWidget::setTitle(const QString &text)
{
    m_labelText->setText(QFontMetrics(m_labelText->font()).elidedText(text, Qt::ElideRight, RENAME_WIDTH - 10));
    m_labelText->setToolTip(text);
}

QString TTKFunctionToolBoxTopWidget::title(bool suffix)
{
    QString text = m_labelText->toolTip().trimmed();
    if(!suffix)
    {
        const int index = text.lastIndexOf("[");
        m_suffixString = text.right(text.length() - index);
        text = text.left( index );
    }
    return text;
}

void TTKFunctionToolBoxTopWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        Q_EMIT itemIndexChanged(m_index);
    }
}

void TTKFunctionToolBoxTopWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 0.1, Qt::SolidLine));
    painter.drawLine(0, height(), width(), height());
}

bool TTKFunctionToolBoxTopWidget::isItemEnabled() const
{
    return true;
}



TTKFunctionToolBoxWidgetItem::TTKFunctionToolBoxWidgetItem(int index, const QString &text, QWidget *parent)
    : QWidget(parent)
{
    m_topWidget = new TTKFunctionToolBoxTopWidget(index, text, this);
    connect(m_topWidget, SIGNAL(itemIndexChanged(int)), parent, SLOT(itemIndexChanged(int)));

    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_topWidget);
    setLayout(m_layout);
}

TTKFunctionToolBoxWidgetItem::~TTKFunctionToolBoxWidgetItem()
{
    delete m_topWidget;
    delete m_layout;
}

QWidget *TTKFunctionToolBoxWidgetItem::item(int index)
{
    if(index < 0 || index >= m_itemList.count())
    {
        return nullptr;
    }
    return m_itemList[index];
}

void TTKFunctionToolBoxWidgetItem::addItem(QWidget *item)
{
    m_itemList.append(item);
    m_layout->addWidget(item);
}

void TTKFunctionToolBoxWidgetItem::removeItem(QWidget *item)
{
    m_itemList.removeAll(item);
    m_layout->removeWidget(item);
}

void TTKFunctionToolBoxWidgetItem::setTitle(const QString &text)
{
    m_topWidget->setTitle(text);
}

QString TTKFunctionToolBoxWidgetItem::title() const
{
    return m_topWidget->title();
}

void TTKFunctionToolBoxWidgetItem::setExpand(bool expand)
{
    m_topWidget->setExpand(expand);
    for(QWidget *w : qAsConst(m_itemList))
    {
        w->setVisible(expand);
    }
}

bool TTKFunctionToolBoxWidgetItem::isExpand() const
{
    return !m_itemList.isEmpty() ? m_itemList.front()->isVisible() : false;
}

int TTKFunctionToolBoxWidgetItem::count() const
{
    return m_itemList.count();
}

void TTKFunctionToolBoxWidgetItem::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void TTKFunctionToolBoxWidgetItem::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event);
}


TTKFunctionToolBoxWidget::TTKFunctionToolBoxWidget(QWidget *parent)
    : QWidget(parent),
      m_singleExpand(false),
      m_currentIndex(-1),
      m_itemIndexRaise(0)
{
    setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    m_contentsWidget = new QWidget(this);
    m_contentsWidget->setObjectName("contentsWidget");
    m_contentsWidget->setStyleSheet(QString("#%1{ background-color:transparent; }").arg(m_contentsWidget->objectName()));

    m_layout = new QVBoxLayout(m_contentsWidget);
    m_layout->setContentsMargins(0, 0, 0 ,0);
    m_layout->setSpacing(0);
    m_contentsWidget->setLayout(m_layout);

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setFrameShape(QFrame::NoFrame);
    m_scrollArea->setFrameShadow(QFrame::Plain);
    m_scrollArea->setAlignment(Qt::AlignLeft);
    m_scrollArea->setWidget(m_contentsWidget);

    setTransparent(0);

    mainLayout->addWidget(m_scrollArea);
    setLayout(mainLayout);
}

TTKFunctionToolBoxWidget::~TTKFunctionToolBoxWidget()
{
    while(!m_itemList.isEmpty())
    {
        delete m_itemList.takeLast().m_widgetItem;
    }
    delete m_layout;
    delete m_scrollArea;
}

void TTKFunctionToolBoxWidget::addItem(QWidget *item, const QString &text)
{
    const int count = m_layout->count();
    if(count > 1)
    {
        m_layout->removeItem(m_layout->itemAt(count - 1));
    }

    //hide before widget
    for(const TTKFunctionToolBoxUnionItem &unionItem : qAsConst(m_itemList))
    {
        unionItem.m_widgetItem->setExpand(false);
    }

    // Add item and make sure it stretches the remaining space.
    TTKFunctionToolBoxWidgetItem *it = new TTKFunctionToolBoxWidgetItem(m_itemIndexRaise, text, this);
    it->addItem(item);
    it->setExpand(true);

    TTKFunctionToolBoxUnionItem widgetItem;
    widgetItem.m_widgetItem = it;
    widgetItem.m_itemIndex = m_itemIndexRaise++;
    m_itemList.append(widgetItem);

    m_currentIndex = m_itemList.count() - 1;

    m_layout->addWidget(it);
    m_layout->addStretch(5);
}

void TTKFunctionToolBoxWidget::removeItem(QWidget *item)
{
    for(int i = 0; i < m_itemList.count(); ++i)
    {
        TTKFunctionToolBoxWidgetItem *it = m_itemList[i].m_widgetItem;
        for(int j = 0; j < it->count(); ++j)
        {
            if(it->item(j) == item)
            {
                m_layout->removeWidget(item);
                m_itemList.takeAt(i).m_widgetItem->deleteLater();
                m_currentIndex = 0;
                return;
            }
        }
    }
}

void TTKFunctionToolBoxWidget::swapItem(int before, int after)
{
    TTKFunctionToolBoxUnionItem widgetItem = m_itemList.takeAt(before);
    m_itemList.insert(after, widgetItem);

    m_layout->removeWidget(widgetItem.m_widgetItem);

    const int count = m_layout->count();
    if(count > 1)
    {
        m_layout->removeItem(m_layout->itemAt(count - 1));
    }

    m_layout->insertWidget(after, widgetItem.m_widgetItem);
    m_layout->addStretch(5);
}

void TTKFunctionToolBoxWidget::setTitle(QWidget *item, const QString &text)
{
    for(const TTKFunctionToolBoxUnionItem &unionItem : qAsConst(m_itemList))
    {
        TTKFunctionToolBoxWidgetItem *it = unionItem.m_widgetItem;
        for(int j = 0; j < it->count(); ++j)
        {
            if(it->item(j) == item)
            {
                it->setTitle(text);
                return;
            }
        }
    }
}

QString TTKFunctionToolBoxWidget::title(QWidget *item) const
{
    for(const TTKFunctionToolBoxUnionItem &unionItem : qAsConst(m_itemList))
    {
        TTKFunctionToolBoxWidgetItem *it = unionItem.m_widgetItem;
        for(int j = 0; j < it->count(); ++j)
        {
            if(it->item(j) == item)
            {
                return it->title();
            }
        }
    }
    return {};
}

void TTKFunctionToolBoxWidget::resizeScrollIndex(int index) const
{
    QScrollBar *bar = m_scrollArea->verticalScrollBar();
    if(bar)
    {
        bar->setSliderPosition(index);
    }
}

int TTKFunctionToolBoxWidget::currentIndex() const
{
    return m_currentIndex;
}

int TTKFunctionToolBoxWidget::count() const
{
    return m_itemList.count();
}

void TTKFunctionToolBoxWidget::setSingleExpand(bool single)
{
    m_singleExpand = single;
}

bool TTKFunctionToolBoxWidget::singleExpand() const
{
    return m_singleExpand;
}

QSize TTKFunctionToolBoxWidget::sizeHint() const
{
    return QSize(200, 200);
}

void TTKFunctionToolBoxWidget::setCurrentIndex(int index)
{
    m_currentIndex = index;
    for(int i = 0; i < m_itemList.count(); ++i)
    {
        m_itemList[i].m_widgetItem->setExpand( i == index );
    }
}

void TTKFunctionToolBoxWidget::itemIndexChanged(int index)
{
    m_currentIndex = foundMappingIndex(index);

    if(m_singleExpand)
    {
        for(int i = 0; i < m_itemList.count(); ++i)
        {
            const bool hide = (i == m_currentIndex) ? !m_itemList[i].m_widgetItem->isExpand() : false;
            m_itemList[i].m_widgetItem->setExpand(hide);
        }
    }
    else
    {
        const bool hide = !m_itemList[m_currentIndex].m_widgetItem->isExpand();
        m_itemList[m_currentIndex].m_widgetItem->setExpand(hide);
    }
}

void TTKFunctionToolBoxWidget::setTransparent(int alpha)
{
    const QString &alphaStr = QString("background:rgba(255, 255, 255, %1)").arg(alpha);
    QWidget *view = m_scrollArea->viewport();
    view->setObjectName("viewport");
    view->setStyleSheet(QString("#%1{ %2 }").arg(view->objectName(), alphaStr));

    m_scrollArea->verticalScrollBar()->setStyleSheet(" \
            QScrollBar{ background:transparent; width:8px; padding-top:0px; padding-bottom:0px; } \
            QScrollBar::handle:vertical{ border-radius:4px; background:#CFCFCF; min-height: 30px; } \
            QScrollBar::handle:vertical::disabled{ background:#DBDBDB; } \
            QScrollBar::handle:vertical:hover{ background:#BBBBBB; } \
            QScrollBar::add-line, QScrollBar::sub-line{ background:none; border:none; } \
            QScrollBar::add-page, QScrollBar::sub-page{ background:none; }");
}

void TTKFunctionToolBoxWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void TTKFunctionToolBoxWidget::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event);
}

int TTKFunctionToolBoxWidget::foundMappingIndex(int index)
{
    int id = -1;
    for(int i = 0; i < m_itemList.count(); ++i)
    {
        if(m_itemList[i].m_itemIndex == index)
        {
            id = i;
            break;
        }
    }
    return id;
}
