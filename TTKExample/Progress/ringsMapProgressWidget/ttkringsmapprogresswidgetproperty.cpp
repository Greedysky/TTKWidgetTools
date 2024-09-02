#include "ttkringsmapprogresswidgetproperty.h"
#include "ttkringsmapprogresswidget.h"
#include "ttktime.h"
#include <QTimer>

TTKRingsMapProgressWidgetProperty::TTKRingsMapProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    TTK::initRandom();

    m_item = new TTKRingsMapProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(TTK_DN_S2MS / 2);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKRingsMapProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRingsMapProgressWidgetProperty::~TTKRingsMapProgressWidgetProperty()
{
    delete m_timer;
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
    TTKRingsMapProgressWidget *widget = TTKObjectCast(TTKRingsMapProgressWidget*, m_item);
    widget->setValue(TTK::random(100) + 1);
}
