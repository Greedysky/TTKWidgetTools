#include "ttkfunctionnormalwidgetproperty.h"
#include "ttkfunctionnormalwidget.h"

TTKFunctionNormaWidgetProperty::TTKFunctionNormaWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKFunctionNormalWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFunctionNormalWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    //
    TTKFunctionNormalWidget *widget = MStatic_cast(TTKFunctionNormalWidget*, m_item);
    widget->addItem("111111");
    widget->addItem("222222");
    widget->addItem("333333");
}

TTKFunctionNormaWidgetProperty::~TTKFunctionNormaWidgetProperty()
{

}

void TTKFunctionNormaWidgetProperty::rectPropertyChanged(QtProperty *property, const QRect &value)
{
    TTKWidgetProperty::rectPropertyChanged(property, value);

    TTKFunctionNormalWidget *widget = MStatic_cast(TTKFunctionNormalWidget*, m_item);
    if(property->propertyName() == "Geometry")
    {
        widget->setSize(value.width(), value.height());
    }
}
