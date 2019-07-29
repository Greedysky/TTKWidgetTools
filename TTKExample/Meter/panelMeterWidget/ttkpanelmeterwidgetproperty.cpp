#include "ttkpanelmeterwidgetproperty.h"
#include "ttkpanelmeterwidget.h"

TTKPanelMeterWidgetProperty::TTKPanelMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPanelMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKPanelMeterWidget*, m_item)->getClassName());
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
    m_intManager->setValue(ringWidthItem, 10);
    m_intManager->setMinimum(ringWidthItem, 0);
    objectItem->addSubProperty(ringWidthItem);
    //
    QtProperty *ringColorItem = m_colorManager->addProperty("RingColor");
    m_colorManager->setValue(ringColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(ringColorItem);
    //
    QtProperty *scaleColorItem = m_colorManager->addProperty("ScaleColor");
    m_colorManager->setValue(scaleColorItem, QColor(100, 181, 200));
    objectItem->addSubProperty(scaleColorItem);
    //
    QtProperty *pointerColorItem = m_colorManager->addProperty("PointerColor");
    m_colorManager->setValue(pointerColorItem, QColor(0, 181, 200));
    objectItem->addSubProperty(pointerColorItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *unitItem = m_stringManager->addProperty("Unit");
    m_stringManager->setValue(unitItem, "m");
    objectItem->addSubProperty(unitItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "World");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKPanelMeterWidgetProperty::~TTKPanelMeterWidgetProperty()
{

}

void TTKPanelMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKPanelMeterWidget *widget = MStatic_cast(TTKPanelMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKPanelMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPanelMeterWidget *widget = MStatic_cast(TTKPanelMeterWidget*, m_item);
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
}

void TTKPanelMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKPanelMeterWidget *widget = MStatic_cast(TTKPanelMeterWidget*, m_item);
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

void TTKPanelMeterWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKPanelMeterWidget *widget = MStatic_cast(TTKPanelMeterWidget*, m_item);
    if(property->propertyName() == "Unit")
    {
        widget->setUnit(value);
    }
    else if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKPanelMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKPanelMeterWidget *widget = MStatic_cast(TTKPanelMeterWidget*, m_item);
    if(property->propertyName() == "RingColor")
    {
        widget->setRingColor(value);
    }
    else if(property->propertyName() == "ScaleColor")
    {
        widget->setScaleColor(value);
    }
    else if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
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
