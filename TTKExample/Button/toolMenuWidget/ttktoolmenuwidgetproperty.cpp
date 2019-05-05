#include "ttktoolmenuwidgetproperty.h"
#include "ttktoolmenuwidget.h"

TTKToolMenuWidgetProperty::TTKToolMenuWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKToolMenuWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKToolMenuWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *enableItem = m_boolManager->addProperty("Enable");
    m_boolManager->setValue(enableItem, true);
    objectItem->addSubProperty(enableItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKToolMenuWidgetProperty::~TTKToolMenuWidgetProperty()
{

}

void TTKToolMenuWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKToolMenuWidget *widget = MStatic_cast(TTKToolMenuWidget*, m_item);
    if(property->propertyName() == "Enable")
    {
        widget->setEnabled(value);
    }
}

void TTKToolMenuWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKToolMenuWidget *widget = MStatic_cast(TTKToolMenuWidget*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}
