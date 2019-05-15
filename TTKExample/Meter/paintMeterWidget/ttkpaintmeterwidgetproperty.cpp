#include "ttkpaintmeterwidgetproperty.h"
#include "ttkpaintmeterwidget.h"

TTKPaintMeterWidgetProperty::TTKPaintMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPaintMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKPaintMeterWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *thresholdItem = m_intManager->addProperty("Threshold");
    m_intManager->setRange(thresholdItem, 0, 100);
    m_intManager->setValue(thresholdItem, 80);
    objectItem->addSubProperty(thresholdItem);
    //
    QtProperty *valueItem = m_intManager->addProperty("Value");
    m_intManager->setRange(valueItem, 0, 100);
    m_intManager->setValue(valueItem, 50);
    objectItem->addSubProperty(valueItem);
    //
    m_browser->addProperty(objectItem);
}

TTKPaintMeterWidgetProperty::~TTKPaintMeterWidgetProperty()
{

}

void TTKPaintMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPaintMeterWidget *widget = MStatic_cast(TTKPaintMeterWidget*, m_item);
    if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
    else if(property->propertyName() == "Threshold")
    {
        widget->setThreshold(value);
    }
}
