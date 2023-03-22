#include "ttkzoomwaitprogresswidgetproperty.h"
#include "ttkzoomwaitprogresswidget.h"

TTKZoomWaitProgressWidgetProperty::TTKZoomWaitProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKZoomWaitProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKZoomWaitProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *zoomOutItem = m_boolManager->addProperty("ZoomOut");
    m_boolManager->setValue(zoomOutItem, true);
    objectItem->addSubProperty(zoomOutItem);
    //
    QtProperty *zoomDeltaItem = m_intManager->addProperty("ZoomDelta");
    m_intManager->setMinimum(zoomDeltaItem, 0);
    m_intManager->setValue(zoomDeltaItem, 5);
    objectItem->addSubProperty(zoomDeltaItem);
    //
    QtProperty *minRadiousItem = m_intManager->addProperty("MinRadious");
    m_intManager->setMinimum(minRadiousItem, 0);
    m_intManager->setValue(minRadiousItem, 25);
    objectItem->addSubProperty(minRadiousItem);
    //
    QtProperty *radiousItem = m_intManager->addProperty("Radious");
    m_intManager->setMinimum(radiousItem, 0);
    m_intManager->setValue(radiousItem, 36);
    objectItem->addSubProperty(radiousItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(24, 189, 155));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKZoomWaitProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKZoomWaitProgressWidget *widget = TTKObjectCast(TTKZoomWaitProgressWidget*, m_item);
    if(property->propertyName() == "ZoomOut")
    {
        widget->setZoomOut(value);
    }
}

void TTKZoomWaitProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKZoomWaitProgressWidget *widget = TTKObjectCast(TTKZoomWaitProgressWidget*, m_item);
    if(property->propertyName() == "ZoomDelta")
    {
        widget->setZoomDelta(value);
    }
    else if(property->propertyName() == "MinRadious")
    {
        widget->setMinRadious(value);
    }
    else if(property->propertyName() == "Radious")
    {
        widget->setRadious(value);
    }
}

void TTKZoomWaitProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKZoomWaitProgressWidget *widget = TTKObjectCast(TTKZoomWaitProgressWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
