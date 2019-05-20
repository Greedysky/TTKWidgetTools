#include "ttklineeditwidgetproperty.h"
#include "ttklineeditwidget.h"

TTKLineEditWidgetProperty::TTKLineEditWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLineEditWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKLineEditWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *inactiveColorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(inactiveColorItem, QColor(0x52, 0x11, 0x88));
    objectItem->addSubProperty(inactiveColorItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello World");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKLineEditWidgetProperty::~TTKLineEditWidgetProperty()
{

}

void TTKLineEditWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKLineEditWidget *widget = MStatic_cast(TTKLineEditWidget*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKLineEditWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLineEditWidget *widget = MStatic_cast(TTKLineEditWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
