#include "ttkbarrulerlabelproperty.h"
#include "ttkbarrulerlabel.h"

TTKBarRulerLabelProperty::TTKBarRulerLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKBarRulerLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKBarRulerLabel*, m_item)->getClassName());
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
    m_doubleManager->setValue(valueItem, 0);
    objectItem->addSubProperty(valueItem);
    //
    QtProperty *precisionItem = m_intManager->addProperty("Precision");
    m_intManager->setValue(precisionItem, 0);
    m_intManager->setRange(precisionItem, 0, 2);
    objectItem->addSubProperty(precisionItem);
    //
    QtProperty *longStepItem = m_intManager->addProperty("LongStep");
    m_intManager->setMinimum(longStepItem, 0);
    m_intManager->setValue(longStepItem, 10);
    objectItem->addSubProperty(longStepItem);
    //
    QtProperty *shortStepItem = m_intManager->addProperty("ShortStep");
    m_intManager->setMinimum(shortStepItem, 0);
    m_intManager->setValue(shortStepItem, 1);
    objectItem->addSubProperty(shortStepItem);
    //
    QtProperty *spaceItem = m_intManager->addProperty("Space");
    m_intManager->setValue(spaceItem, 20);
    objectItem->addSubProperty(spaceItem);
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
    QtProperty *bgColorStartItem = m_colorManager->addProperty("BgColorStart");
    m_colorManager->setValue(bgColorStartItem, QColor(100, 100, 100));
    objectItem->addSubProperty(bgColorStartItem);
    //
    QtProperty *bgColorEndItem = m_colorManager->addProperty("BgColorEnd");
    m_colorManager->setValue(bgColorEndItem, QColor(60, 60, 60));
    objectItem->addSubProperty(bgColorEndItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *barBgColorItem = m_colorManager->addProperty("BarBgColor");
    m_colorManager->setValue(barBgColorItem, QColor(220, 220, 220));
    objectItem->addSubProperty(barBgColorItem);
    //
    QtProperty *barColorItem = m_colorManager->addProperty("BarColor");
    m_colorManager->setValue(barColorItem, QColor(100, 184, 255));
    objectItem->addSubProperty(barColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKBarRulerLabelProperty::~TTKBarRulerLabelProperty()
{

}

void TTKBarRulerLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKBarRulerLabel *widget = MStatic_cast(TTKBarRulerLabel*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKBarRulerLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKBarRulerLabel *widget = MStatic_cast(TTKBarRulerLabel*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
    else if(property->propertyName() == "LongStep")
    {
        widget->setLongStep(value);
    }
    else if(property->propertyName() == "ShortStep")
    {
        widget->setShortStep(value);
    }
    else if(property->propertyName() == "Space")
    {
        widget->setSpace(value);
    }
}

void TTKBarRulerLabelProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKBarRulerLabel *widget = MStatic_cast(TTKBarRulerLabel*, m_item);
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

void TTKBarRulerLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKBarRulerLabel *widget = MStatic_cast(TTKBarRulerLabel*, m_item);
    if(property->propertyName() == "BgColorStart")
    {
        widget->setBgColorStart(value);
    }
    else if(property->propertyName() == "BgColorEnd")
    {
        widget->setBgColorEnd(value);
    }
    else if(property->propertyName() == "LineColor")
    {
        widget->setLineColor(value);
    }
    else if(property->propertyName() == "BarBgColor")
    {
        widget->setBarBgColor(value);
    }
    else if(property->propertyName() == "BarColor")
    {
        widget->setBarColor(value);
    }
}
