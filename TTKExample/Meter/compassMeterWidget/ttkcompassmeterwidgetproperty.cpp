#include "ttkcompassmeterwidgetproperty.h"
#include "ttkcompassmeterwidget.h"

TTKCompassMeterWidgetProperty::TTKCompassMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCompassMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKCompassMeterWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
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
    QtProperty *animationItem = m_boolManager->addProperty("Animation");
    m_boolManager->setValue(animationItem, true);
    objectItem->addSubProperty(animationItem);
    //
    QtProperty *animationStepItem = m_doubleManager->addProperty("AnimationStep");
    m_doubleManager->setMinimum(animationStepItem, 0.0);
    m_doubleManager->setValue(animationStepItem, 0.5);
    objectItem->addSubProperty(animationStepItem);
    //
    QtProperty *crownColorStartItem = m_colorManager->addProperty("CrownColorStart");
    m_colorManager->setValue(crownColorStartItem, QColor(255, 255, 255));
    objectItem->addSubProperty(crownColorStartItem);
    //
    QtProperty *crownColorEndItem = m_colorManager->addProperty("CrownColorEnd");
    m_colorManager->setValue(crownColorEndItem, QColor(60, 60, 60));
    objectItem->addSubProperty(crownColorEndItem);
    //
    QtProperty *backgroundColorStartItem = m_colorManager->addProperty("BackgroundColorStart");
    m_colorManager->setValue(backgroundColorStartItem, QColor(50, 50, 50));
    objectItem->addSubProperty(backgroundColorStartItem);
    //
    QtProperty *backgroundColorEndItem = m_colorManager->addProperty("BackgroundColorEnd");
    m_colorManager->setValue(backgroundColorEndItem, QColor(20, 0, 20));
    objectItem->addSubProperty(backgroundColorEndItem);
    //
    QtProperty *darkColorItem = m_colorManager->addProperty("DarkColor");
    m_colorManager->setValue(darkColorItem, QColor(255, 170, 0));
    objectItem->addSubProperty(darkColorItem);
    //
    QtProperty *lightColorEndItem = m_colorManager->addProperty("LightColor");
    m_colorManager->setValue(lightColorEndItem, QColor(170, 255, 0));
    objectItem->addSubProperty(lightColorEndItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *northPointerColorItem = m_colorManager->addProperty("NorthPointerColor");
    m_colorManager->setValue(northPointerColorItem, QColor(253, 107, 107));
    objectItem->addSubProperty(northPointerColorItem);
    //
    QtProperty *southPointerColorItem = m_colorManager->addProperty("SouthPointerColor");
    m_colorManager->setValue(southPointerColorItem, QColor(0, 170, 255));
    objectItem->addSubProperty(southPointerColorItem);
    //
    QtProperty *centerColorStartItem = m_colorManager->addProperty("CenterColorStart");
    m_colorManager->setValue(centerColorStartItem, QColor(230, 230, 230));
    objectItem->addSubProperty(centerColorStartItem);
    //
    QtProperty *centerColorEndItem = m_colorManager->addProperty("CenterColorEnd");
    m_colorManager->setValue(centerColorEndItem, QColor(180, 180, 180));
    objectItem->addSubProperty(centerColorEndItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKCompassMeterWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKCompassMeterWidget *widget = TTKObjectCast(TTKCompassMeterWidget*, m_item);
    if(property->propertyName() == "Animation")
    {
        widget->setAnimation(value);
    }
}

void TTKCompassMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCompassMeterWidget *widget = TTKObjectCast(TTKCompassMeterWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
}

void TTKCompassMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKCompassMeterWidget *widget = TTKObjectCast(TTKCompassMeterWidget*, m_item);
    if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
    else if(property->propertyName() == "AnimationStep")
    {
        widget->setAnimationStep(value);
    }
}

void TTKCompassMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCompassMeterWidget *widget = TTKObjectCast(TTKCompassMeterWidget*, m_item);
    if(property->propertyName() == "CrownColorStart")
    {
        widget->setCrownColorStart(value);
    }
    else if(property->propertyName() == "CrownColorEnd")
    {
        widget->setCrownColorEnd(value);
    }
    else if(property->propertyName() == "BackgroundColorStart")
    {
        widget->setBackgroundColorStart(value);
    }
    else if(property->propertyName() == "BackgroundColorEnd")
    {
        widget->setBackgroundColorEnd(value);
    }
    else if(property->propertyName() == "DarkColor")
    {
        widget->setDarkColor(value);
    }
    else if(property->propertyName() == "LightColor")
    {
        widget->setLightColor(value);
    }
    else if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
    else if(property->propertyName() == "NorthPointerColor")
    {
        widget->setNorthPointerColor(value);
    }
    else if(property->propertyName() == "SouthPointerColor")
    {
        widget->setSouthPointerColor(value);
    }
    else if(property->propertyName() == "CenterColorStart")
    {
        widget->setCenterColorStart(value);
    }
    else if(property->propertyName() == "CenterColorEnd")
    {
        widget->setCenterColorEnd(value);
    }
}
