#include "ttklightpointlabelproperty.h"
#include "ttklightpointlabel.h"

TTKLightPointLabelProperty::TTKLightPointLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLightPointLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKLightPointLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *stepItem = m_intManager->addProperty("Step");
    m_intManager->setValue(stepItem, 10);
    m_intManager->setRange(stepItem, 0, 80);
    objectItem->addSubProperty(stepItem);
    //
    QtProperty *intervalItem = m_intManager->addProperty("Interval");
    m_intManager->setValue(intervalItem, 100);
    m_intManager->setMinimum(intervalItem, 1);
    objectItem->addSubProperty(intervalItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(255, 179, 133));
    objectItem->addSubProperty(backgroundColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKLightPointLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKLightPointLabel *widget = TTKObjectCast(TTKLightPointLabel*, m_item);
    if(property->propertyName() == "Step")
    {
        widget->setStep(value);
    }
    else if(property->propertyName() == "Interval")
    {
        widget->setInterval(value);
    }
}

void TTKLightPointLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLightPointLabel *widget = TTKObjectCast(TTKLightPointLabel*, m_item);
    if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
