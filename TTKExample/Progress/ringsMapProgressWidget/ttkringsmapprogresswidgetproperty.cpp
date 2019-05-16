#include "ttkringsmapprogresswidgetproperty.h"
#include "ttkringsmapprogresswidget.h"

#include <QTimer>

TTKRingsMapProgressWidgetProperty::TTKRingsMapProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRingsMapProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(500);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRingsMapProgressWidget*, m_item)->getClassName());
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

TTKRingsMapProgressWidgetProperty::~TTKRingsMapProgressWidgetProperty()
{

}

void TTKRingsMapProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
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

void TTKRingsMapProgressWidgetProperty::updateRender()
{
    TTKRingsMapProgressWidget *widget = MStatic_cast(TTKRingsMapProgressWidget*, m_item);
    widget->setValue(qrand() % 100 + 1);
}
