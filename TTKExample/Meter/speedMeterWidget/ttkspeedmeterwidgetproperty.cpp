#include "ttkspeedmeterwidgetproperty.h"
#include "ttkspeedmeterwidget.h"

TTKSpeedMeterWidgetProperty::TTKSpeedMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSpeedMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKSpeedMeterWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *valueItem = m_intManager->addProperty("Value");
    m_intManager->setRange(valueItem, 0, 100);
    m_intManager->setValue(valueItem, 50);
    objectItem->addSubProperty(valueItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKSpeedMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKSpeedMeterWidget *widget = TTKStatic_cast(TTKSpeedMeterWidget*, m_item);
    if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
}
