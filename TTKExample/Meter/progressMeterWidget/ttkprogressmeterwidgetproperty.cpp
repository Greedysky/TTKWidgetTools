#include "ttkprogressmeterwidgetproperty.h"
#include "ttkprogressmeterwidget.h"

TTKProgressMeterWidgetProperty::TTKProgressMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKProgressMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKProgressMeterWidget*, m_item)->getClassName());
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
    QtProperty *showValueItem = m_boolManager->addProperty("ShowValue");
    m_boolManager->setValue(showValueItem, true);
    objectItem->addSubProperty(showValueItem);
    //
    QtProperty *showPointerItem = m_boolManager->addProperty("ShowPointer");
    m_boolManager->setValue(showPointerItem, true);
    objectItem->addSubProperty(showPointerItem);
    //
    QtProperty *pointerStyleItem = m_enumManager->addProperty("PointerStyle");
    QStringList enumNames;
    enumNames << "PointerStyleCircle" << "PointerStyleIndicator" << "PointerStyleIndicatorR" << "PointerStyleTriangle";
    m_enumManager->setEnumNames(pointerStyleItem, enumNames);
    m_enumManager->setValue(pointerStyleItem, TTKProgressMeterWidget::PointerStyleCircle);
    objectItem->addSubProperty(pointerStyleItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *progressColorItem = m_colorManager->addProperty("ProgressColor");
    m_colorManager->setValue(progressColorItem, QColor(7, 184, 13));
    objectItem->addSubProperty(progressColorItem);
    //
    QtProperty *progressBgColorItem = m_colorManager->addProperty("ProgressBgColor");
    m_colorManager->setValue(progressBgColorItem, QColor(15, 84, 100));
    objectItem->addSubProperty(progressBgColorItem);
    //
    QtProperty *circleColorStartItem = m_colorManager->addProperty("CircleColorStart");
    m_colorManager->setValue(circleColorStartItem, QColor(80, 80, 80));
    objectItem->addSubProperty(circleColorStartItem);
    //
    QtProperty *circleColorEndItem = m_colorManager->addProperty("CircleColorEnd");
    m_colorManager->setValue(circleColorEndItem, QColor(100, 100, 100));
    objectItem->addSubProperty(circleColorEndItem);
    //
    QtProperty *textColorEndItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorEndItem, QColor(255, 255, 255));
    objectItem->addSubProperty(textColorEndItem);
    //
    m_browser->addProperty(objectItem);
}

TTKProgressMeterWidgetProperty::~TTKProgressMeterWidgetProperty()
{

}

void TTKProgressMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKProgressMeterWidget *widget = MStatic_cast(TTKProgressMeterWidget*, m_item);
    if(property->propertyName() == "ShowValue")
    {
        widget->setShowValue(value);
    }
    else if(property->propertyName() == "ShowPointer")
    {
        widget->setShowPointer(value);
    }
}

void TTKProgressMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKProgressMeterWidget *widget = MStatic_cast(TTKProgressMeterWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
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

void TTKProgressMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKProgressMeterWidget *widget = MStatic_cast(TTKProgressMeterWidget*, m_item);
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
}

void TTKProgressMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKProgressMeterWidget *widget = MStatic_cast(TTKProgressMeterWidget*, m_item);
    if(property->propertyName() == "PointerStyle")
    {
        widget->setPointerStyle(MStatic_cast(TTKProgressMeterWidget::PointerStyle, value));
    }
}

void TTKProgressMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKProgressMeterWidget *widget = MStatic_cast(TTKProgressMeterWidget*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
    else if(property->propertyName() == "ProgressColor")
    {
        widget->setProgressColor(value);
    }
    else if(property->propertyName() == "ProgressBgColor")
    {
        widget->setProgressBgColor(value);
    }
    else if(property->propertyName() == "CircleColorStart")
    {
        widget->setCircleColorStart(value);
    }
    else if(property->propertyName() == "CircleColorEnd")
    {
        widget->setCircleColorEnd(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
