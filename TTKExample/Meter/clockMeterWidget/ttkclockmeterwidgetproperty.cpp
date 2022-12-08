#include "ttkclockmeterwidgetproperty.h"
#include "ttkclockmeterwidget.h"

TTKClockMeterWidgetProperty::TTKClockMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKClockMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKClockMeterWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *secondStyletem = m_enumManager->addProperty("SecondStyle");
    QStringList enumNames;
    enumNames << "SecondStyleNormal" << "SecondStyleSpring" << "SecondStyleContinue" << "SecondStyleHide";
    m_enumManager->setEnumNames(secondStyletem, enumNames);
    m_enumManager->setValue(secondStyletem, TTKStatic_cast(int, TTKClockMeterWidget::SecondStyle::Normal));
    objectItem->addSubProperty(secondStyletem);
    //
    QtProperty *crownColorStartItem = m_colorManager->addProperty("CrownColorStart");
    m_colorManager->setValue(crownColorStartItem, QColor(255, 255, 255));
    objectItem->addSubProperty(crownColorStartItem);
    //
    QtProperty *crownColorEndItem = m_colorManager->addProperty("CrownColorEnd");
    m_colorManager->setValue(crownColorEndItem, QColor(166, 166,166));
    objectItem->addSubProperty(crownColorEndItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(100, 100, 100));
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *pointerHourColorItem = m_colorManager->addProperty("PointerHourColor");
    m_colorManager->setValue(pointerHourColorItem, QColor(180, 180, 180));
    objectItem->addSubProperty(pointerHourColorItem);
    //
    QtProperty *pointerMinColorItem = m_colorManager->addProperty("PointerMinColor");
    m_colorManager->setValue(pointerMinColorItem, QColor(180, 180, 180));
    objectItem->addSubProperty(pointerMinColorItem);
    //
    QtProperty *pointerSecColorItem = m_colorManager->addProperty("PointerSecColor");
    m_colorManager->setValue(pointerSecColorItem, QColor(180, 180, 180));
    objectItem->addSubProperty(pointerSecColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKClockMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKClockMeterWidget *widget = TTKObject_cast(TTKClockMeterWidget*, m_item);
    if(property->propertyName() == "SecondStyle")
    {
        widget->setSecondStyle(TTKStatic_cast(TTKClockMeterWidget::SecondStyle, value));
    }
}

void TTKClockMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKClockMeterWidget *widget = TTKObject_cast(TTKClockMeterWidget*, m_item);
    if(property->propertyName() == "CrownColorStart")
    {
        widget->setCrownColorStart(value);
    }
    else if(property->propertyName() == "CrownColorEnd")
    {
        widget->setCrownColorEnd(value);
    }
    else if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
    else if(property->propertyName() == "PointerHourColor")
    {
        widget->setPointerHourColor(value);
    }
    else if(property->propertyName() == "PointerMinColor")
    {
        widget->setPointerMinColor(value);
    }
    else if(property->propertyName() == "PointerSecColor")
    {
        widget->setPointerSecColor(value);
    }
}
