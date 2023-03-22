#include "ttkcustomringwidgetproperty.h"
#include "ttkcustomringwidget.h"

TTKCustomRingWidgetProperty::TTKCustomRingWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCustomRingWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKCustomRingWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *outCircleColorItem = m_colorManager->addProperty("OutCircleColor");
    m_colorManager->setValue(outCircleColorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(outCircleColorItem);
    //
    QtProperty *midCircleColorItem = m_colorManager->addProperty("MidCircleColor");
    m_colorManager->setValue(midCircleColorItem, QColor(0, 255, 0));
    objectItem->addSubProperty(midCircleColorItem);
    //
    QtProperty *inCircleColorItem = m_colorManager->addProperty("InCircleColor");
    m_colorManager->setValue(inCircleColorItem, QColor(0, 0, 255));
    objectItem->addSubProperty(inCircleColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKCustomRingWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCustomRingWidget *widget = TTKObjectCast(TTKCustomRingWidget*, m_item);
    if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
    else if(property->propertyName() == "OutCircleColor")
    {
        widget->setOutCircleColor(value);
    }
    else if(property->propertyName() == "MidCircleColor")
    {
        widget->setMidCircleColor(value);
    }
    else if(property->propertyName() == "InCircleColor")
    {
        widget->setInCircleColor(value);
    }
}
