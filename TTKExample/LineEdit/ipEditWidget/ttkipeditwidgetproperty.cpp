#include "ttkipeditwidgetproperty.h"
#include "ttkipeditwidget.h"

TTKIpEditWidgetProperty::TTKIpEditWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKIpEditWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKIpEditWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "255.255.255.255");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKIpEditWidgetProperty::~TTKIpEditWidgetProperty()
{

}

void TTKIpEditWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKIpEditWidget *widget = MStatic_cast(TTKIpEditWidget*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}
