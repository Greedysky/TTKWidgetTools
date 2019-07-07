#include "ttkcarmeterwidgetproperty.h"
#include "ttkcarmeterwidget.h"

TTKCarMeterWidgetProperty::TTKCarMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCarMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCarMeterWidget*, m_item)->getClassName());
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
    QtProperty *showOverlayItem = m_boolManager->addProperty("ShowOverlay");
    m_boolManager->setValue(showOverlayItem, true);
    objectItem->addSubProperty(showOverlayItem);
    //
    QtProperty *overlayColorItem = m_colorManager->addProperty("OverlayColor");
    m_colorManager->setValue(overlayColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(overlayColorItem);
    //
    QtProperty *pieStyleItem = m_enumManager->addProperty("PieStyle");
    QStringList enumNames;
    enumNames << "PieStyleThree" << "PieStyleCurrent";
    m_enumManager->setEnumNames(pieStyleItem, enumNames);
    m_enumManager->setValue(pieStyleItem, TTKCarMeterWidget::PieStyleThree);
    objectItem->addSubProperty(pieStyleItem);
    //
    QtProperty *pointerStyleItem = m_enumManager->addProperty("PointerStyle");
    enumNames.clear();
    enumNames << "PointerStyleCircle" << "PointerStyleIndicator" << "PointerStyleIndicatorR" << "PointerStyleTriangle";
    m_enumManager->setEnumNames(pointerStyleItem, enumNames);
    m_enumManager->setValue(pointerStyleItem, TTKCarMeterWidget::PointerStyleIndicator);
    objectItem->addSubProperty(pointerStyleItem);
    //
    QtProperty *outerCircleColorItem = m_colorManager->addProperty("OuterCircleColor");
    m_colorManager->setValue(outerCircleColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(outerCircleColorItem);
    //
    QtProperty *innerCircleColorItem = m_colorManager->addProperty("InnerCircleColor");
    m_colorManager->setValue(innerCircleColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(innerCircleColorItem);
    //
    QtProperty *pieColorStartItem = m_colorManager->addProperty("PieColorStart");
    m_colorManager->setValue(pieColorStartItem, QColor(253, 107, 107));
    objectItem->addSubProperty(pieColorStartItem);
    //
    QtProperty *pieColorMidItem = m_colorManager->addProperty("PieColorMid");
    m_colorManager->setValue(pieColorMidItem, QColor(217, 217, 0));
    objectItem->addSubProperty(pieColorMidItem);
    //
    QtProperty *pieColorEndItem = m_colorManager->addProperty("PieColorEnd");
    m_colorManager->setValue(pieColorEndItem, QColor(24, 188, 154));
    objectItem->addSubProperty(pieColorEndItem);
    //
    QtProperty *coverCircleColorItem = m_colorManager->addProperty("CoverCircleColor");
    m_colorManager->setValue(coverCircleColorItem, QColor(100, 100, 100));
    objectItem->addSubProperty(coverCircleColorItem);
    //
    QtProperty *scaleColorItem = m_colorManager->addProperty("ScaleColor");
    m_colorManager->setValue(scaleColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(scaleColorItem);
    //
    QtProperty *pointerColorItem = m_colorManager->addProperty("PointerColor");
    m_colorManager->setValue(pointerColorItem, QColor(253, 107, 107));
    objectItem->addSubProperty(pointerColorItem);
    //
    QtProperty *centerCircleColorItem = m_colorManager->addProperty("CenterCircleColor");
    m_colorManager->setValue(centerCircleColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(centerCircleColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(textColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCarMeterWidgetProperty::~TTKCarMeterWidgetProperty()
{

}

void TTKCarMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKCarMeterWidget *widget = MStatic_cast(TTKCarMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
    else if(property->propertyName() == "ShowOverlay")
    {
        widget->setShowOverlay(value);
    }
}

void TTKCarMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCarMeterWidget *widget = MStatic_cast(TTKCarMeterWidget*, m_item);
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
}

void TTKCarMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKCarMeterWidget *widget = MStatic_cast(TTKCarMeterWidget*, m_item);
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

void TTKCarMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKCarMeterWidget *widget = MStatic_cast(TTKCarMeterWidget*, m_item);
    if(property->propertyName() == "PieStyle")
    {
        widget->setPieStyle(MStatic_cast(TTKCarMeterWidget::PieStyle, value));
    }
    else if(property->propertyName() == "PointerStyle")
    {
        widget->setPointerStyle(MStatic_cast(TTKCarMeterWidget::PointerStyle, value));
    }
}

void TTKCarMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCarMeterWidget *widget = MStatic_cast(TTKCarMeterWidget*, m_item);
    if(property->propertyName() == "OverlayColor")
    {
        widget->setOverlayColor(value);
    }
    else if(property->propertyName() == "OuterCircleColor")
    {
        widget->setOuterCircleColor(value);
    }
    else if(property->propertyName() == "InnerCircleColor")
    {
        widget->setInnerCircleColor(value);
    }
    else if(property->propertyName() == "PieColorStart")
    {
        widget->setPieColorStart(value);
    }
    else if(property->propertyName() == "PieColorMid")
    {
        widget->setPieColorMid(value);
    }
    else if(property->propertyName() == "PieColorEnd")
    {
        widget->setPieColorEnd(value);
    }
    else if(property->propertyName() == "CoverCircleColor")
    {
        widget->setCoverCircleColor(value);
    }
    else if(property->propertyName() == "ScaleColor")
    {
        widget->setScaleColor(value);
    }
    else if(property->propertyName() == "PointerColor")
    {
        widget->setPointerColor(value);
    }
    else if(property->propertyName() == "CenterCircleColor")
    {
        widget->setCenterCircleColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
