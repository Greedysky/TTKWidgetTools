#include "ttkanimationprogresswidgetproperty.h"
#include "ttkanimationprogresswidget.h"

TTKAnimationProgressWidgetProperty::TTKAnimationProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKAnimationProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKAnimationProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}

TTKAnimationProgressWidgetProperty::~TTKAnimationProgressWidgetProperty()
{

}

void TTKAnimationProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKAnimationProgressWidget *widget = MStatic_cast(TTKAnimationProgressWidget*, m_item);
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
