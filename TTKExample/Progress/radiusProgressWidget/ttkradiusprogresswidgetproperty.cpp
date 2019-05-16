#include "ttkradiusprogresswidgetproperty.h"
#include "ttkradiusprogresswidget.h"

#include <QTimer>

TTKRadiusProgressWidgetProperty::TTKRadiusProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRadiusProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(500);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRadiusProgressWidget*, m_item)->getClassName());
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

TTKRadiusProgressWidgetProperty::~TTKRadiusProgressWidgetProperty()
{

}

void TTKRadiusProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            m_timer->start();
        }
        else
        {
            m_timer->stop();
        }
    }
}

void TTKRadiusProgressWidgetProperty::updateRender()
{
    TTKRadiusProgressWidget *widget = MStatic_cast(TTKRadiusProgressWidget*, m_item);
    widget->setValue(qrand() % 100 + 1);
}
