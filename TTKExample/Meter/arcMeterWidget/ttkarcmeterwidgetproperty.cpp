#include "ttkarcmeterwidgetproperty.h"
#include "ttkarcmeterwidget.h"

TTKArcMeterWidgetProperty::TTKArcMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKArcMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKArcMeterWidget*, m_item)->getClassName());
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
    QtProperty *pointerStyleItem = m_enumManager->addProperty("PointerStyle");
    QStringList enumNames;
    enumNames << "PointerStyleCircle" << "PointerStyleIndicator" << "PointerStyleIndicatorR" << "PointerStyleTriangle";
    m_enumManager->setEnumNames(pointerStyleItem, enumNames);
    m_enumManager->setValue(pointerStyleItem, TTKArcMeterWidget::PointerStyleIndicator);
    objectItem->addSubProperty(pointerStyleItem);
    //
    QtProperty *arcColorItem = m_colorManager->addProperty("ArcColor");
    m_colorManager->setValue(arcColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(arcColorItem);
    //
    QtProperty *scaleColorItem = m_colorManager->addProperty("ScaleColor");
    m_colorManager->setValue(scaleColorItem, QColor(233, 185, 110));
    objectItem->addSubProperty(scaleColorItem);
    //
    QtProperty *scaleNumColorItem = m_colorManager->addProperty("ScaleNumColor");
    m_colorManager->setValue(scaleNumColorItem, QColor(92, 53, 102));
    objectItem->addSubProperty(scaleNumColorItem);
    //
    QtProperty *pointerColorItem = m_colorManager->addProperty("PointerColor");
    m_colorManager->setValue(pointerColorItem, QColor(253, 107, 107));
    objectItem->addSubProperty(pointerColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(textColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKArcMeterWidgetProperty::~TTKArcMeterWidgetProperty()
{

}

void TTKArcMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKArcMeterWidget *widget = MStatic_cast(TTKArcMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKArcMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKArcMeterWidget *widget = MStatic_cast(TTKArcMeterWidget*, m_item);
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

void TTKArcMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKArcMeterWidget *widget = MStatic_cast(TTKArcMeterWidget*, m_item);
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

void TTKArcMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKArcMeterWidget *widget = MStatic_cast(TTKArcMeterWidget*, m_item);
    if(property->propertyName() == "PointerStyle")
    {
        widget->setPointerStyle(MStatic_cast(TTKArcMeterWidget::PointerStyle, value));
    }
}

void TTKArcMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKArcMeterWidget *widget = MStatic_cast(TTKArcMeterWidget*, m_item);
    if(property->propertyName() == "ArcColor")
    {
        widget->setArcColor(value);
    }
    else if(property->propertyName() == "ScaleColor")
    {
        widget->setScaleColor(value);
    }
    else if(property->propertyName() == "ScaleNumColor")
    {
        widget->setScaleNumColor(value);
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
