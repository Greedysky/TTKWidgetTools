#include "ttkloadingprogresswidgetproperty.h"
#include "ttkloadingprogresswidget.h"

TTKLoadingProgressWidgetProperty::TTKLoadingProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLoadingProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKLoadingProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *dotCountItem = m_intManager->addProperty("DotCount");
    m_intManager->setMinimum(dotCountItem, 0);
    m_intManager->setMaximum(dotCountItem, 20);
    m_intManager->setValue(dotCountItem, 20);
    objectItem->addSubProperty(dotCountItem);
    //
    QtProperty *dotColorItem = m_colorManager->addProperty("DotColor");
    m_colorManager->setValue(dotColorItem, QColor(49, 177, 190));
    objectItem->addSubProperty(dotColorItem);
    //
    QtProperty *maxDiameterItem = m_doubleManager->addProperty("MaxDiameter");
    m_doubleManager->setMinimum(maxDiameterItem, 0);
    m_doubleManager->setValue(maxDiameterItem, 30);
    objectItem->addSubProperty(maxDiameterItem);
    //
    QtProperty *minDiameterItem = m_doubleManager->addProperty("MinDiameter");
    m_doubleManager->setMinimum(minDiameterItem, 0);
    m_doubleManager->setValue(minDiameterItem, 2);
    objectItem->addSubProperty(minDiameterItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKLoadingProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKLoadingProgressWidget *widget = TTKObjectCast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            widget->start();
        }
        else
        {
            widget->stop();
        }
    }
}

void TTKLoadingProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKLoadingProgressWidget *widget = TTKObjectCast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "DotCount")
    {
        widget->setDotCount(value);
    }
}

void TTKLoadingProgressWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKLoadingProgressWidget *widget = TTKObjectCast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "MaxDiameter")
    {
        widget->setMaxDiameter(value);
    }
    else if(property->propertyName() == "MinDiameter")
    {
        widget->setMinDiameter(value);
    }
}

void TTKLoadingProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLoadingProgressWidget *widget = TTKObjectCast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "DotColor")
    {
        widget->setDotColor(value);
    }
}
