#include "ttkmovinglabelsliderproperty.h"
#include "ttkmovinglabelslider.h"

TTKMovingLabelSliderProperty::TTKMovingLabelSliderProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKMovingLabelSlider(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMovingLabelSlider*, m_item)->getClassName());
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
    m_intManager->setValue(rangeMaxItem, 1000 * 1000);
    objectItem->addSubProperty(rangeMaxItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Horizontal" << "Vertical";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 0);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

TTKMovingLabelSliderProperty::~TTKMovingLabelSliderProperty()
{

}

void TTKMovingLabelSliderProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKMovingLabelSlider *widget = MStatic_cast(TTKMovingLabelSlider*, m_item);
    if(property->propertyName() == "RangeMin")
    {
        widget->setMinimum(value);
    }
    else if(property->propertyName() == "RangeMax")
    {
        widget->setMaximum(value);
    }
}

void TTKMovingLabelSliderProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKMovingLabelSlider *widget = MStatic_cast(TTKMovingLabelSlider*, m_item);
    if(property->propertyName() == "Direction")
    {
        Qt::Orientation orientation(Qt::Horizontal);
        switch(value)
        {
            case 0: orientation = Qt::Horizontal; break;
            case 1: orientation = Qt::Vertical; break;
        }
        widget->setOrientation(orientation);
    }
}
