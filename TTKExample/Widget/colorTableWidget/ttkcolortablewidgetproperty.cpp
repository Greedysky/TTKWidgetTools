#include "ttkcolortablewidgetproperty.h"
#include "ttkcolortablewidget.h"

TTKColorTableWidgetProperty::TTKColorTableWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKColorTableWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKColorTableWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    TTKObject_cast(TTKColorTableWidget*, m_item)->initialize();
}
