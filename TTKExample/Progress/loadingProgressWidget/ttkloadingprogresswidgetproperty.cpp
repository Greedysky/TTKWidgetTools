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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKLoadingProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *dotCountItem = m_intManager->addProperty("DotCount");
    m_intManager->setMinimum(dotCountItem, 0);
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

TTKLoadingProgressWidgetProperty::~TTKLoadingProgressWidgetProperty()
{

}

void TTKLoadingProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKLoadingProgressWidget *widget = MStatic_cast(TTKLoadingProgressWidget*, m_item);
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
    TTKLoadingProgressWidget *widget = MStatic_cast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "DotCount")
    {
        widget->setDotCount(value);
    }
}

void TTKLoadingProgressWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKLoadingProgressWidget *widget = MStatic_cast(TTKLoadingProgressWidget*, m_item);
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
    TTKLoadingProgressWidget *widget = MStatic_cast(TTKLoadingProgressWidget*, m_item);
    if(property->propertyName() == "DotColor")
    {
        widget->setDotColor(value);
    }
}
