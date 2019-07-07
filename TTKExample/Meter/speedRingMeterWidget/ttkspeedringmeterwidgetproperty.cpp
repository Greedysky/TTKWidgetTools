#include "ttkspeedringmeterwidgetproperty.h"
#include "ttkspeedringmeterwidget.h"

TTKSpeedRingMeterWidgetProperty::TTKSpeedRingMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSpeedRingMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKSpeedRingMeterWidget*, m_item)->getClassName());
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
    QtProperty *scaleMajorItem = m_intManager->addProperty("ScaleMajor");
    m_intManager->setValue(scaleMajorItem, 10);
    m_intManager->setMinimum(scaleMajorItem, 1);
    objectItem->addSubProperty(scaleMajorItem);
    //
    QtProperty *scaleMinorItem = m_intManager->addProperty("ScaleMinor");
    m_intManager->setValue(scaleMinorItem, 10);
    m_intManager->setMinimum(scaleMinorItem, 1);
    objectItem->addSubProperty(scaleMinorItem);
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
    QtProperty *ringWidthItem = m_intManager->addProperty("RingWidth");
    m_intManager->setValue(ringWidthItem, 15);
    m_intManager->setMinimum(ringWidthItem, 1);
    objectItem->addSubProperty(ringWidthItem);
    //
    QtProperty *ringStartPercentItem = m_intManager->addProperty("RingStartPercent");
    m_intManager->setValue(ringStartPercentItem, 25);
    m_intManager->setMinimum(ringStartPercentItem, 1);
    objectItem->addSubProperty(ringStartPercentItem);
    //
    QtProperty *ringMidPercentItem = m_intManager->addProperty("RingMidPercent");
    m_intManager->setValue(ringMidPercentItem, 50);
    m_intManager->setMinimum(ringMidPercentItem, 1);
    objectItem->addSubProperty(ringMidPercentItem);
    //
    QtProperty *ringEndPercentItem = m_intManager->addProperty("RingEndPercent");
    m_intManager->setValue(ringEndPercentItem, 25);
    m_intManager->setMinimum(ringEndPercentItem, 1);
    objectItem->addSubProperty(ringEndPercentItem);
    //
    QtProperty *ringColorStartItem = m_colorManager->addProperty("RingColorStart");
    m_colorManager->setValue(ringColorStartItem, QColor(60, 60, 60));
    objectItem->addSubProperty(ringColorStartItem);
    //
    QtProperty *ringColorMidItem = m_colorManager->addProperty("RingColorMid");
    m_colorManager->setValue(ringColorMidItem, QColor(45, 196, 248));
    objectItem->addSubProperty(ringColorMidItem);
    //
    QtProperty *ringColorEndItem = m_colorManager->addProperty("RingColorEnd");
    m_colorManager->setValue(ringColorEndItem, QColor(254, 68, 138));
    objectItem->addSubProperty(ringColorEndItem);
    //
    QtProperty *pointerColorItem = m_colorManager->addProperty("PointerColor");
    m_colorManager->setValue(pointerColorItem, QColor(178, 221, 253));
    objectItem->addSubProperty(pointerColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(textColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKSpeedRingMeterWidgetProperty::~TTKSpeedRingMeterWidgetProperty()
{

}

void TTKSpeedRingMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKSpeedRingMeterWidget *widget = MStatic_cast(TTKSpeedRingMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKSpeedRingMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKSpeedRingMeterWidget *widget = MStatic_cast(TTKSpeedRingMeterWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
    else if(property->propertyName() == "ScaleMajor")
    {
        widget->setScaleMajor(value);
    }
    else if(property->propertyName() == "ScaleMinor")
    {
        widget->setScaleMinor(value);
    }
    else if(property->propertyName() == "StartAngle")
    {
        widget->setStartAngle(value);
    }
    else if(property->propertyName() == "EndAngle")
    {
        widget->setEndAngle(value);
    }
    else if(property->propertyName() == "RingWidth")
    {
        widget->setRingWidth(value);
    }
    else if(property->propertyName() == "RingStartPercent")
    {
        widget->setRingStartPercent(value);
    }
    else if(property->propertyName() == "RingMidPercent")
    {
        widget->setRingMidPercent(value);
    }
    else if(property->propertyName() == "RingEndPercent")
    {
        widget->setRingEndPercent(value);
    }
}

void TTKSpeedRingMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKSpeedRingMeterWidget *widget = MStatic_cast(TTKSpeedRingMeterWidget*, m_item);
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

void TTKSpeedRingMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKSpeedRingMeterWidget *widget = MStatic_cast(TTKSpeedRingMeterWidget*, m_item);
    if(property->propertyName() == "RingColorStart")
    {
        widget->setRingColorStart(value);
    }
    else if(property->propertyName() == "RingColorMid")
    {
        widget->setRingColorMid(value);
    }
    else if(property->propertyName() == "RingColorEnd")
    {
        widget->setRingColorEnd(value);
    }
    else if(property->propertyName() == "PointerColor")
    {
        widget->setPointerColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
