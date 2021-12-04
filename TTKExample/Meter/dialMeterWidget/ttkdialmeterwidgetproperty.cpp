#include "ttkdialmeterwidgetproperty.h"
#include "ttkdialmeterwidget.h"

TTKDialMeterWidgetProperty::TTKDialMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKDialMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKDialMeterWidget*, m_item)->className());
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
    QtProperty *showValueItem = m_boolManager->addProperty("ShowValue");
    m_boolManager->setValue(showValueItem, true);
    objectItem->addSubProperty(showValueItem);
    //
    QtProperty *pointerStyleItem = m_enumManager->addProperty("PointerStyle");
    QStringList enumNames;
    enumNames << "PointerStyleCircle" << "PointerStyleIndicator" << "PointerStyleIndicatorR" << "PointerStyleTriangle";
    m_enumManager->setEnumNames(pointerStyleItem, enumNames);
    m_enumManager->setValue(pointerStyleItem, TTKDialMeterWidget::PointerStyleCircle);
    objectItem->addSubProperty(pointerStyleItem);
    //
    QtProperty *darkColorItem = m_colorManager->addProperty("DarkColor");
    m_colorManager->setValue(darkColorItem, QColor(60, 60, 60));
    objectItem->addSubProperty(darkColorItem);
    //
    QtProperty *lightColorItem = m_colorManager->addProperty("LightColor");
    m_colorManager->setValue(lightColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(lightColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(100, 100, 100));
    objectItem->addSubProperty(textColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKDialMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKDialMeterWidget *widget = TTKStatic_cast(TTKDialMeterWidget*, m_item);
    if(property->propertyName() == "ShowValue")
    {
        widget->setShowValue(value);
    }
}

void TTKDialMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKDialMeterWidget *widget = TTKStatic_cast(TTKDialMeterWidget*, m_item);
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

void TTKDialMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKDialMeterWidget *widget = TTKStatic_cast(TTKDialMeterWidget*, m_item);
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

void TTKDialMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKDialMeterWidget *widget = TTKStatic_cast(TTKDialMeterWidget*, m_item);
    if(property->propertyName() == "PointerStyle")
    {
        widget->setPointerStyle(TTKStatic_cast(TTKDialMeterWidget::PointerStyle, value));
    }
}

void TTKDialMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKDialMeterWidget *widget = TTKStatic_cast(TTKDialMeterWidget*, m_item);
    if(property->propertyName() == "DarkColor")
    {
        widget->setDarkColor(value);
    }
    else if(property->propertyName() == "LightColor")
    {
        widget->setLightColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
