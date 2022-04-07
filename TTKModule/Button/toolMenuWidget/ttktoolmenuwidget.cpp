#include "ttktoolmenuwidget.h"

#include <QWidgetAction>

TTKToolMenu::TTKToolMenu(QWidget *parent)
    : QMenu(parent)
{

}

void TTKToolMenu::showEvent(QShowEvent *event)
{
    QMenu::showEvent(event);
    emit windowStateChanged(true);
}

void TTKToolMenu::hideEvent(QHideEvent *event)
{
    QMenu::hideEvent(event);
    emit windowStateChanged(false);
}


TTKToolMenuWidget::TTKToolMenuWidget(QWidget *parent)
    : QToolButton(parent)
{
    setCursor(Qt::PointingHandCursor);

    m_menu = new TTKToolMenu(this);
    QWidgetAction *actionWidget = new QWidgetAction(m_menu);
    m_containWidget = new QWidget(m_menu);

    actionWidget->setDefaultWidget(m_containWidget);
    m_menu->addAction(actionWidget);

    initialize();
    connect(this, SIGNAL(clicked()), SLOT(popupMenu()));
}

TTKToolMenuWidget::~TTKToolMenuWidget()
{
    delete m_containWidget;
    delete m_menu;
}

void TTKToolMenuWidget::setTranslucentBackground()
{
    const QString MenuStyle = " \
            QMenu{ padding:5px; border:none; background:rgba(0, 0, 0, 210); border-radius:4px;} \
            QMenu::icon{ margin-left:10px;} \
            QMenu::right-arrow{ background: url(:/tiny/lb_arrow_up_normal);} \
            QMenu::item{ color:#BBBBBB; padding:6px 30px 6px 30px; border:1px solid transparent;} \
            QMenu::item:disabled{ color:#555555;} \
            QMenu::item:selected{ color:white; background:rgba(0, 0, 0, 200);} \
            QMenu::separator{ height:1px; background:#BBBBBB; margin-top:5px; margin-bottom:5px;}";
    m_menu->setWindowFlags(m_menu->windowFlags() | Qt::FramelessWindowHint);
    m_menu->setAttribute(Qt::WA_TranslucentBackground);
    m_menu->setStyleSheet(MenuStyle);
}

void TTKToolMenuWidget::popupMenu()
{
    QPoint pos = mapToGlobal(QPoint(0, 0));
    pos.setY(pos.y() - m_containWidget->height() - 10);
    pos.setX(pos.x() - (m_containWidget->width() - width() - 30)/2);

    m_menu->exec(pos);
}

void TTKToolMenuWidget::initialize()
{
    setTranslucentBackground();
    m_containWidget->setFixedSize(140, 100);
    m_menu->removeAction(m_menu->actions().front());

    m_menu->addAction("One");
    m_menu->addAction("Two");
    m_menu->addAction("Three");
}
