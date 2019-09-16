#include "ttkroundmeterwidgetproperty.h"
#include "ttkroundmeterwidget.h"

TTKRoundMeterWidgetProperty::TTKRoundMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRoundMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRoundMeterWidget*, m_item)->getClassName());
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
    QtProperty *angleItem = m_doubleManager->addProperty("Angle");
    m_doubleManager->setValue(angleItem, 40);
    objectItem->addSubProperty(angleItem);
    //
    QtProperty *precisionItem = m_intManager->addProperty("Precision");
    m_intManager->setValue(precisionItem, 0);
    m_intManager->setRange(precisionItem, 0, 2);
    objectItem->addSubProperty(precisionItem);
    //
    QtProperty *usedColorItem = m_colorManager->addProperty("UsedColor");
    m_colorManager->setValue(usedColorItem, QColor(100, 184, 255));
    objectItem->addSubProperty(usedColorItem);
    //
    QtProperty *freeColorItem = m_colorManager->addProperty("FreeColor");
    m_colorManager->setValue(freeColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(freeColorItem);
    //
    QtProperty *rangeTextColorItem = m_colorManager->addProperty("RangeTextColor");
    m_colorManager->setValue(rangeTextColorItem, QColor(137, 137, 137));
    objectItem->addSubProperty(rangeTextColorItem);
    //
    QtProperty *valueTextColorItem = m_colorManager->addProperty("ValueTextColor");
    m_colorManager->setValue(valueTextColorItem, QColor(52, 155, 218));
    objectItem->addSubProperty(valueTextColorItem);
    //
    QtProperty *valueBgColorItem = m_colorManager->addProperty("ValueBgColor");
    m_colorManager->setValue(valueBgColorItem, QColor(239, 239, 239));
    objectItem->addSubProperty(valueBgColorItem);
    //
    QtProperty *outBgColorItem = m_colorManager->addProperty("OutBgColor");
    m_colorManager->setValue(outBgColorItem, QColor(233, 233, 233));
    objectItem->addSubProperty(outBgColorItem);
    //
    QtProperty *centerBgColorStartItem = m_colorManager->addProperty("CenterBgColorStart");
    m_colorManager->setValue(centerBgColorStartItem, QColor(45, 204, 112));
    objectItem->addSubProperty(centerBgColorStartItem);
    //
    QtProperty *centerBgColorEndItem = m_colorManager->addProperty("CenterBgColorEnd");
    m_colorManager->setValue(centerBgColorEndItem, QColor(51, 152, 219));
    objectItem->addSubProperty(centerBgColorEndItem);
    //
    QtProperty *unitItem = m_stringManager->addProperty("Unit");
    m_stringManager->setValue(unitItem, "%");
    objectItem->addSubProperty(unitItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRoundMeterWidgetProperty::~TTKRoundMeterWidgetProperty()
{

}

void TTKRoundMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKRoundMeterWidget *widget = MStatic_cast(TTKRoundMeterWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
}

void TTKRoundMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKRoundMeterWidget *widget = MStatic_cast(TTKRoundMeterWidget*, m_item);
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
    else if(property->propertyName() == "Angle")
    {
        widget->setAngle(value);
    }
}

void TTKRoundMeterWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKRoundMeterWidget *widget = MStatic_cast(TTKRoundMeterWidget*, m_item);
    if(property->propertyName() == "Unit")
    {
        widget->setUnit(value);
    }
}

void TTKRoundMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKRoundMeterWidget *widget = MStatic_cast(TTKRoundMeterWidget*, m_item);
    if(property->propertyName() == "UsedColor")
    {
        widget->setUsedColor(value);
    }
    else if(property->propertyName() == "FreeColor")
    {
        widget->setFreeColor(value);
    }
    else if(property->propertyName() == "RangeTextColor")
    {
        widget->setRangeTextColor(value);
    }
    else if(property->propertyName() == "ValueTextColor")
    {
        widget->setValueTextColor(value);
    }
    else if(property->propertyName() == "ValueBgColor")
    {
        widget->setValueBgColor(value);
    }
    else if(property->propertyName() == "OutBgColor")
    {
        widget->setOutBgColor(value);
    }
    else if(property->propertyName() == "CenterBgColorStart")
    {
        widget->setCenterBgColorStart(value);
    }
    else if(property->propertyName() == "CenterBgColorEnd")
    {
        widget->setCenterBgColorEnd(value);
    }
}
