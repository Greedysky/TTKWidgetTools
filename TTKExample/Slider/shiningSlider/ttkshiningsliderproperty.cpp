#include "ttkshiningsliderproperty.h"
#include "ttkshiningslider.h"

TTKShiningSliderProperty::TTKShiningSliderProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKShiningSlider(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKShiningSlider*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *rangeMinItem = m_intManager->addProperty("RangeMin");
    m_intManager->setMinimum(rangeMinItem, 0);
    m_intManager->setValue(rangeMinItem, 0);
    objectItem->addSubProperty(rangeMinItem);
    //
    QtProperty *rangeMaxItem = m_intManager->addProperty("RangeMax");
    m_intManager->setMinimum(rangeMaxItem, 0);
    m_intManager->setValue(rangeMaxItem, 200);
    objectItem->addSubProperty(rangeMaxItem);
    //
    QtProperty *valueItem = m_intManager->addProperty("Value");
    m_intManager->setMinimum(valueItem, 0);
    m_intManager->setValue(valueItem, 100);
    objectItem->addSubProperty(valueItem);
    //
    m_browser->addProperty(objectItem);
}

TTKShiningSliderProperty::~TTKShiningSliderProperty()
{

}

void TTKShiningSliderProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKShiningSlider *widget = MStatic_cast(TTKShiningSlider*, m_item);
    if(property->propertyName() == "Activity")
    {
        widget->setPlayState(value);
    }
}

void TTKShiningSliderProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKShiningSlider *widget = MStatic_cast(TTKShiningSlider*, m_item);
    if(property->propertyName() == "RangeMin")
    {
        widget->setMinimum(value);
    }
    else if(property->propertyName() == "RangeMax")
    {
        widget->setMaximum(value);
    }
    else if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
}
