#include "ttkringprogresswidgetproperty.h"
#include "ttkringprogresswidget.h"

TTKRingProgressWidgetProperty::TTKRingProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRingProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRingProgressWidget*, m_item)->getClassName());
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
    QtProperty *clockWiseItem = m_boolManager->addProperty("ClockWise");
    m_boolManager->setValue(clockWiseItem, true);
    objectItem->addSubProperty(clockWiseItem);
    //
    QtProperty *showPercentItem = m_boolManager->addProperty("ShowPercent");
    m_boolManager->setValue(showPercentItem, true);
    objectItem->addSubProperty(showPercentItem);
    //
    QtProperty *alarmModeItem = m_boolManager->addProperty("AlarmMode");
    m_boolManager->setValue(alarmModeItem, true);
    objectItem->addSubProperty(alarmModeItem);
    //
    QtProperty *startAngleItem = m_intManager->addProperty("StartAngle");
    m_intManager->setValue(startAngleItem, 40);
    m_intManager->setMinimum(startAngleItem, 0);
    objectItem->addSubProperty(startAngleItem);
    //
    QtProperty *ringPaddingItem = m_intManager->addProperty("RingPadding");
    m_intManager->setValue(ringPaddingItem, 5);
    m_intManager->setMinimum(ringPaddingItem, 0);
    objectItem->addSubProperty(ringPaddingItem);
    //
    QtProperty *ringWidthItem = m_intManager->addProperty("RingWidth");
    m_intManager->setValue(ringWidthItem, 15);
    m_intManager->setMinimum(ringWidthItem, 0);
    objectItem->addSubProperty(ringWidthItem);
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
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *ringColorItem = m_colorManager->addProperty("RingColor");
    m_colorManager->setValue(ringColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(ringColorItem);
    //
    QtProperty *ringBgColortem = m_colorManager->addProperty("RingBgColor");
    m_colorManager->setValue(ringBgColortem, QColor(253, 107, 107));
    objectItem->addSubProperty(ringBgColortem);
    //
    QtProperty *circleColorItem = m_colorManager->addProperty("CircleColor");
    m_colorManager->setValue(circleColorItem, QColor(217, 217, 0));
    objectItem->addSubProperty(circleColorItem);
    //
    QtProperty *ringValueFItem = m_intManager->addProperty("RingValueF");
    m_intManager->setValue(ringValueFItem, 0);
    m_intManager->setMinimum(ringValueFItem, 40);
    objectItem->addSubProperty(ringValueFItem);
    //
    QtProperty *ringValueSItem = m_intManager->addProperty("RingValueS");
    m_intManager->setValue(ringValueSItem, 0);
    m_intManager->setMinimum(ringValueSItem, 40);
    objectItem->addSubProperty(ringValueSItem);
    //
    QtProperty *ringValueTItem = m_intManager->addProperty("RingValueT");
    m_intManager->setValue(ringValueTItem, 0);
    m_intManager->setMinimum(ringValueTItem, 40);
    objectItem->addSubProperty(ringValueTItem);
    //
    QtProperty *ringColorFItem = m_colorManager->addProperty("RingColorF");
    m_colorManager->setValue(ringColorFItem, QColor(24, 188, 154));
    objectItem->addSubProperty(ringColorFItem);
    //
    QtProperty *ringColorSItem = m_colorManager->addProperty("RingColorS");
    m_colorManager->setValue(ringColorSItem, QColor(100, 100, 100));
    objectItem->addSubProperty(ringColorSItem);
    //
    QtProperty *ringColorTItem = m_colorManager->addProperty("RingColorT");
    m_colorManager->setValue(ringColorTItem, QColor(255, 255, 255));
    objectItem->addSubProperty(ringColorTItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRingProgressWidgetProperty::~TTKRingProgressWidgetProperty()
{

}

void TTKRingProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKRingProgressWidget *widget = MStatic_cast(TTKRingProgressWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
    else if(property->propertyName() == "ClockWise")
    {
        widget->setClockWise(value);
    }
    else if(property->propertyName() == "ShowPercent")
    {
        widget->setShowPercent(value);
    }
    else if(property->propertyName() == "AlarmMode")
    {
        widget->setAlarmMode(value);
    }
}

void TTKRingProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKRingProgressWidget *widget = MStatic_cast(TTKRingProgressWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
    else if(property->propertyName() == "StartAngle")
    {
        widget->setStartAngle(value);
    }
    else if(property->propertyName() == "RingPadding")
    {
        widget->setRingPadding(value);
    }
    else if(property->propertyName() == "RingWidth")
    {
        widget->setRingWidth(value);
    }
    else if(property->propertyName() == "RingValueF")
    {
        widget->setRingValueF(value);
    }
    else if(property->propertyName() == "RingValueS")
    {
        widget->setRingValueS(value);
    }
    else if(property->propertyName() == "RingValueT")
    {
        widget->setRingValueT(value);
    }
}

void TTKRingProgressWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKRingProgressWidget *widget = MStatic_cast(TTKRingProgressWidget*, m_item);
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

void TTKRingProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKRingProgressWidget *widget = MStatic_cast(TTKRingProgressWidget*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
    else if(property->propertyName() == "RingColor")
    {
        widget->setRingColor(value);
    }
    else if(property->propertyName() == "RingBgColor")
    {
        widget->setRingBgColor(value);
    }
    else if(property->propertyName() == "CircleColor")
    {
        widget->setCircleColor(value);
    }
    else if(property->propertyName() == "RingColorF")
    {
        widget->setRingColorF(value);
    }
    else if(property->propertyName() == "RingColorS")
    {
        widget->setRingColorS(value);
    }
    else if(property->propertyName() == "RingColorT")
    {
        widget->setRingColorT(value);
    }
}
