#include "ttkminimeterwidgetproperty.h"
#include "ttkminimeterwidget.h"

TTKMiniMeterWidgetProperty::TTKMiniMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKMiniMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMiniMeterWidget*, m_item)->getClassName());
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
    QtProperty *stepItem = m_intManager->addProperty("Step");
    m_intManager->setValue(stepItem, 20);
    m_intManager->setMinimum(stepItem, 1);
    objectItem->addSubProperty(stepItem);
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
    m_boolManager->setValue(showValueItem, false);
    objectItem->addSubProperty(showValueItem);
    //
    QtProperty *pointerStyleItem = m_enumManager->addProperty("PointerStyle");
    QStringList enumNames;
    enumNames << "PointerStyleCircle" << "PointerStyleIndicator" << "PointerStyleIndicatorR" << "PointerStyleTriangle";
    m_enumManager->setEnumNames(pointerStyleItem, enumNames);
    m_enumManager->setValue(pointerStyleItem, TTKMiniMeterWidget::PointerStyleCircle);
    objectItem->addSubProperty(pointerStyleItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *borderColorItem = m_colorManager->addProperty("BorderColor");
    m_colorManager->setValue(borderColorItem, QColor(7, 184, 13));
    objectItem->addSubProperty(borderColorItem);
    //
    QtProperty *percentColorItem = m_colorManager->addProperty("PercentColor");
    m_colorManager->setValue(percentColorItem, QColor(15, 84, 100));
    objectItem->addSubProperty(percentColorItem);
    //
    QtProperty *textColorEndItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorEndItem, QColor(255, 255, 255));
    objectItem->addSubProperty(textColorEndItem);
    //
    m_browser->addProperty(objectItem);
}

TTKMiniMeterWidgetProperty::~TTKMiniMeterWidgetProperty()
{

}

void TTKMiniMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKMiniMeterWidget *widget = MStatic_cast(TTKMiniMeterWidget*, m_item);
    if(property->propertyName() == "ShowValue")
    {
        widget->setShowValue(value);
    }
}

void TTKMiniMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKMiniMeterWidget *widget = MStatic_cast(TTKMiniMeterWidget*, m_item);
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
    else if(property->propertyName() == "Step")
    {
        widget->setStep(value);
    }
}

void TTKMiniMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKMiniMeterWidget *widget = MStatic_cast(TTKMiniMeterWidget*, m_item);
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

void TTKMiniMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKMiniMeterWidget *widget = MStatic_cast(TTKMiniMeterWidget*, m_item);
    if(property->propertyName() == "PointerStyle")
    {
        widget->setPointerStyle(MStatic_cast(TTKMiniMeterWidget::PointerStyle, value));
    }
}

void TTKMiniMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKMiniMeterWidget *widget = MStatic_cast(TTKMiniMeterWidget*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
    else if(property->propertyName() == "BorderColor")
    {
        widget->setBorderColor(value);
    }
    else if(property->propertyName() == "PercentColor")
    {
        widget->setPercentColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
