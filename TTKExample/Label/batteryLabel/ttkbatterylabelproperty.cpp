#include "ttkbatterylabelproperty.h"
#include "ttkbatterylabel.h"

TTKBatteryLabelProperty::TTKBatteryLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKBatteryLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKBatteryLabel*, m_item)->getClassName());
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
    QtProperty *alarmValueItem = m_doubleManager->addProperty("AlarmValue");
    m_doubleManager->setMinimum(alarmValueItem, 0);
    m_doubleManager->setValue(alarmValueItem, 30);
    objectItem->addSubProperty(alarmValueItem);
    //
    QtProperty *stepItem = m_doubleManager->addProperty("Step");
    m_doubleManager->setMinimum(stepItem, 0);
    m_doubleManager->setValue(stepItem, 0.5);
    objectItem->addSubProperty(stepItem);
    //
    QtProperty *borderColorStartItem = m_colorManager->addProperty("BorderColorStart");
    m_colorManager->setValue(borderColorStartItem, QColor(100, 100, 100));
    objectItem->addSubProperty(borderColorStartItem);
    //
    QtProperty *borderColorEndItem = m_colorManager->addProperty("BorderColorEnd");
    m_colorManager->setValue(borderColorEndItem, QColor(80, 80, 80));
    objectItem->addSubProperty(borderColorEndItem);
    //
    QtProperty *alarmColorStartItem = m_colorManager->addProperty("AlarmColorStart");
    m_colorManager->setValue(alarmColorStartItem, QColor(250, 118, 113));
    objectItem->addSubProperty(alarmColorStartItem);
    //
    QtProperty *alarmColorEndItem = m_colorManager->addProperty("AlarmColorEnd");
    m_colorManager->setValue(alarmColorEndItem, QColor(204, 38, 38));
    objectItem->addSubProperty(alarmColorEndItem);
    //
    QtProperty *normalColorStartItem = m_colorManager->addProperty("NormalColorStart");
    m_colorManager->setValue(normalColorStartItem, QColor(50, 205, 51));
    objectItem->addSubProperty(normalColorStartItem);
    //
    QtProperty *normalColorEndItem = m_colorManager->addProperty("NormalColorEnd");
    m_colorManager->setValue(normalColorEndItem, QColor(60, 179, 133));
    objectItem->addSubProperty(normalColorEndItem);
    //
    m_browser->addProperty(objectItem);
}

TTKBatteryLabelProperty::~TTKBatteryLabelProperty()
{

}

void TTKBatteryLabelProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKBatteryLabel *widget = MStatic_cast(TTKBatteryLabel*, m_item);
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
    else if(property->propertyName() == "AlarmValue")
    {
        widget->setAlarmValue(value);
    }
    else if(property->propertyName() == "Step")
    {
        widget->setStep(value);
    }
}

void TTKBatteryLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKBatteryLabel *widget = MStatic_cast(TTKBatteryLabel*, m_item);
    if(property->propertyName() == "BorderColorStart")
    {
        widget->setBorderColorStart(value);
    }
    else if(property->propertyName() == "BorderColorEnd")
    {
        widget->setBorderColorEnd(value);
    }
    else if(property->propertyName() == "AlarmColorStart")
    {
        widget->setAlarmColorStart(value);
    }
    else if(property->propertyName() == "AlarmColorEnd")
    {
        widget->setAlarmColorEnd(value);
    }
    else if(property->propertyName() == "NormalColorStart")
    {
        widget->setNormalColorStart(value);
    }
    else if(property->propertyName() == "NormalColorEnd")
    {
        widget->setNormalColorEnd(value);
    }
}
