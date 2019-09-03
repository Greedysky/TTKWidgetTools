#include "ttknotifywindowproperty.h"
#include "ttknotifywindow.h"

#include <QToolButton>

TTKNotifyWindowProperty::TTKNotifyWindowProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_manager = new TTKNotifyManager(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKNotifyManager*, m_manager)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *titleItem = m_stringManager->addProperty("Title");
    m_stringManager->setValue(titleItem, "新消息");
    objectItem->addSubProperty(titleItem);
    //
    QtProperty *bodyItem = m_stringManager->addProperty("Body");
    m_stringManager->setValue(bodyItem, "这是测试页面");
    objectItem->addSubProperty(bodyItem);
    //
    QtProperty *maxCountItem = m_intManager->addProperty("MaxCount");
    m_intManager->setMinimum(maxCountItem, 0);
    m_intManager->setValue(maxCountItem, 10);
    objectItem->addSubProperty(maxCountItem);
    //
    QtProperty *displayTimetem = m_intManager->addProperty("DisplayTime");
    m_intManager->setMinimum(displayTimetem, 500);
    m_intManager->setValue(displayTimetem, 2000);
    objectItem->addSubProperty(displayTimetem);
    //
    QtProperty *pixmapItem = m_pixmapManager->addProperty("Pixmap");
    m_pixmapManager->setValue(pixmapItem, ":/res/lb_message");
    objectItem->addSubProperty(pixmapItem);
    //
    m_browser->addProperty(objectItem);
}

TTKNotifyWindowProperty::~TTKNotifyWindowProperty()
{

}

void TTKNotifyWindowProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKNotifyManager *widget = MStatic_cast(TTKNotifyManager*, m_manager);
    if(property->propertyName() == "MaxCount")
    {
        widget->setMaxCount(value);
    }
    else if(property->propertyName() == "DisplayTime")
    {
        widget->setDisplayTime(value);
    }
}

void TTKNotifyWindowProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    if(property->propertyName() == "Title")
    {
        m_title = value;
    }
    else if(property->propertyName() == "Body")
    {
        m_body = value;
    }
}

void TTKNotifyWindowProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    if(property->propertyName() == "Pixmap")
    {
        m_icon = value;
    }
}

void TTKNotifyWindowProperty::showWidget()
{
    TTKNotifyManager *manager = MStatic_cast(TTKNotifyManager*, m_manager);
    manager->notify(m_title, m_body, m_icon, "https://github.com/Greedysky/TTKWidgetTools");
}
