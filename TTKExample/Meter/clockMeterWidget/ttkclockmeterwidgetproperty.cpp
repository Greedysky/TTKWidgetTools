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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKClockMeterWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *secondStyletem = m_enumManager->addProperty("SecondStyle");
    QStringList enumNames;
    enumNames << "SecondStyleNormal" << "SecondStyleSpring" << "SecondStyleContinue" << "SecondStyleHide";
    m_enumManager->setEnumNames(secondStyletem, enumNames);
    m_enumManager->setValue(secondStyletem, TTKClockMeterWidget::SecondStyleNormal);
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
    QtProperty *foregroundItem = m_colorManager->addProperty("Foreground");
    m_colorManager->setValue(foregroundItem, QColor(255, 255, 255));
    objectItem->addSubProperty(foregroundItem);
    //
    QtProperty *backgroundItem = m_colorManager->addProperty("Background");
    m_colorManager->setValue(backgroundItem, QColor(100, 100, 100));
    objectItem->addSubProperty(backgroundItem);
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

TTKClockMeterWidgetProperty::~TTKClockMeterWidgetProperty()
{

}

void TTKClockMeterWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKClockMeterWidget *widget = MStatic_cast(TTKClockMeterWidget*, m_item);
    if(property->propertyName() == "SecondStyle")
    {
        widget->setSecondStyle(MStatic_cast(TTKClockMeterWidget::SecondStyle, value));
    }
}

void TTKClockMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKClockMeterWidget *widget = MStatic_cast(TTKClockMeterWidget*, m_item);
    if(property->propertyName() == "CrownColorStart")
    {
        widget->setCrownColorStart(value);
    }
    else if(property->propertyName() == "CrownColorEnd")
    {
        widget->setCrownColorEnd(value);
    }
    else if(property->propertyName() == "Foreground")
    {
        widget->setForeground(value);
    }
    else if(property->propertyName() == "Background")
    {
        widget->setBackground(value);
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
