#include "ttktemperaturemeterwidgetproperty.h"
#include "ttktemperaturemeterwidget.h"

TTKTemperatureMeterWidgetProperty::TTKTemperatureMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKTemperatureMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKTemperatureMeterWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *maxValueItem = m_doubleManager->addProperty("MaxValue");
    m_doubleManager->setMinimum(maxValueItem, 0);
    m_doubleManager->setValue(maxValueItem, 100);
    objectItem->addSubProperty(maxValueItem);
    //
    QtProperty *minValueItem = m_doubleManager->addProperty("MinValue");
    m_doubleManager->setMinimum(minValueItem, 0);
    m_doubleManager->setValue(minValueItem, 0);
    objectItem->addSubProperty(minValueItem);
    //
    QtProperty *valueItem = m_doubleManager->addProperty("Value");
    m_doubleManager->setValue(valueItem, 50);
    objectItem->addSubProperty(valueItem);
    //
    QtProperty *precisionItem = m_intManager->addProperty("Precision");
    m_intManager->setValue(precisionItem, 0);
    m_intManager->setRange(precisionItem, 0, 2);
    objectItem->addSubProperty(precisionItem);
    //
    QtProperty *startAngleItem = m_intManager->addProperty("StartAngle");
    m_intManager->setValue(startAngleItem, 40);
    m_intManager->setMinimum(startAngleItem, 0);
    objectItem->addSubProperty(startAngleItem);
    //
    QtProperty *endAngleItem = m_intManager->addProperty("EndAngle");
    m_intManager->setValue(endAngleItem, 40);
    m_intManager->setMinimum(endAngleItem, 0);
    objectItem->addSubProperty(endAngleItem);
    //
    QtProperty *animationItem = m_boolManager->addProperty("Animation");
    m_boolManager->setValue(animationItem, true);
    objectItem->addSubProperty(animationItem);
    //
    QtProperty *animationStepItem = m_doubleManager->addProperty("AnimationStep");
    m_doubleManager->setMinimum(animationStepItem, 0.0);
    m_doubleManager->setValue(animationStepItem, 0.5);
    objectItem->addSubProperty(animationStepItem);
    //
    QtProperty *outerCircleColorItem = m_colorManager->addProperty("OuterCircleColor");
    m_colorManager->setValue(outerCircleColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(outerCircleColorItem);
    //
    QtProperty *innerCircleColorItem = m_colorManager->addProperty("InnerCircleColor");
    m_colorManager->setValue(innerCircleColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(innerCircleColorItem);
    //
    QtProperty *centerCircleColorItem = m_colorManager->addProperty("CenterCircleColor");
    m_colorManager->setValue(centerCircleColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(centerCircleColorItem);
    //
    QtProperty *usedColorItem = m_colorManager->addProperty("UsedColor");
    m_colorManager->setValue(usedColorItem, QColor(24, 188, 154));
    objectItem->addSubProperty(usedColorItem);
    //
    QtProperty *freeColorItem = m_colorManager->addProperty("FreeColor");
    m_colorManager->setValue(freeColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(freeColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(textColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKTemperatureMeterWidgetProperty::~TTKTemperatureMeterWidgetProperty()
{

}

void TTKTemperatureMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKTemperatureMeterWidget *widget = MStatic_cast(TTKTemperatureMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKTemperatureMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKTemperatureMeterWidget *widget = MStatic_cast(TTKTemperatureMeterWidget*, m_item);
    if(property->propertyName() == "StartAngle")
    {
        widget->setStartAngle(value);
    }
    else if(property->propertyName() == "EndAngle")
    {
        widget->setEndAngle(value);
    }
}

void TTKTemperatureMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKTemperatureMeterWidget *widget = MStatic_cast(TTKTemperatureMeterWidget*, m_item);
    if(property->propertyName() == "MaxValue")
    {
        widget->setMaxValue(value);
    }
    else if(property->propertyName() == "MinValue")
    {
        widget->setMinValue(value);
    }
    else if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
    else if(property->propertyName() == "AnimationStep")
    {
        widget->setAnimationStep(value);
    }
}

void TTKTemperatureMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKTemperatureMeterWidget *widget = MStatic_cast(TTKTemperatureMeterWidget*, m_item);
    if(property->propertyName() == "OuterCircleColor")
    {
        widget->setOuterCircleColor(value);
    }
    else if(property->propertyName() == "InnerCircleColor")
    {
        widget->setInnerCircleColor(value);
    }
    else if(property->propertyName() == "CenterCircleColor")
    {
        widget->setCenterCircleColor(value);
    }
    else if(property->propertyName() == "UsedColor")
    {
        widget->setUsedColor(value);
    }
    else if(property->propertyName() == "FreeColor")
    {
        widget->setFreeColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
