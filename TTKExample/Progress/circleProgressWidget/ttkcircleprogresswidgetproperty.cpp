#include "ttkcircleprogresswidgetproperty.h"
#include "ttkcircleprogresswidget.h"

TTKCircleProgressWidgetProperty::TTKCircleProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCircleProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCircleProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *innerRadiusItem = m_doubleManager->addProperty("InnerRadius");
    m_doubleManager->setMinimum(innerRadiusItem, 0);
    m_doubleManager->setValue(innerRadiusItem, 0.5);
    objectItem->addSubProperty(innerRadiusItem);
    //
    QtProperty *outerRadiusItem = m_doubleManager->addProperty("OuterRadius");
    m_doubleManager->setMinimum(outerRadiusItem, 0);
    m_doubleManager->setValue(outerRadiusItem, 1);
    objectItem->addSubProperty(outerRadiusItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCircleProgressWidgetProperty::~TTKCircleProgressWidgetProperty()
{

}

void TTKCircleProgressWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKCircleProgressWidget *widget = MStatic_cast(TTKCircleProgressWidget*, m_item);
    if(property->propertyName() == "InnerRadius")
    {
        widget->setInnerRadius(value);
    }
    else if(property->propertyName() == "OuterRadius")
    {
        widget->setOuterRadius(value);
    }
}

void TTKCircleProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCircleProgressWidget *widget = MStatic_cast(TTKCircleProgressWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
