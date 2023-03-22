#include "ttkcalendarwidgetproperty.h"
#include "ttkcalendarwidget.h"

TTKCalendarWidgetProperty::TTKCalendarWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCalendarWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKCalendarWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    TTKObjectCast(TTKCalendarWidget*, m_item)->show();
}
