#include "ttktogglewidgetproperty.h"
#include "ttktogglewidget.h"

TTKToggleWidgetProperty::TTKToggleWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKToggleWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKToggleWidget*, m_item)->getClassName());
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
    QtProperty *checkedItem = m_boolManager->addProperty("Checked");
    objectItem->addSubProperty(checkedItem);
    //
    QtProperty *disabledColorItem = m_colorManager->addProperty("DisabledColor");
    m_colorManager->setValue(disabledColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(disabledColorItem);
    //
    QtProperty *activeColorItem = m_colorManager->addProperty("ActiveColor");
    m_colorManager->setValue(activeColorItem, QColor(255, 255, 0));
    objectItem->addSubProperty(activeColorItem);
    //
    QtProperty *inactiveColorItem = m_colorManager->addProperty("InactiveColor");
    m_colorManager->setValue(inactiveColorItem, QColor(0, 255, 255));
    objectItem->addSubProperty(inactiveColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TrackColor");
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *orientationItem = m_enumManager->addProperty("Orientation");
    QStringList enumNames;
    enumNames << "Vertical" << "Horizontal";
    m_enumManager->setEnumNames(orientationItem, enumNames);
    m_enumManager->setValue(orientationItem, Qt::Horizontal);
    objectItem->addSubProperty(orientationItem);
    //
    m_browser->addProperty(objectItem);
}

TTKToggleWidgetProperty::~TTKToggleWidgetProperty()
{

}

void TTKToggleWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKToggleWidget *widget = MStatic_cast(TTKToggleWidget*, m_item);
    if(property->propertyName() == "Enable")
    {
        widget->setEnabled(value);
    }
    else if(property->propertyName() == "Checked")
    {
        widget->setChecked(value);
    }
}

void TTKToggleWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKToggleWidget *widget = MStatic_cast(TTKToggleWidget*, m_item);
    if(property->propertyName() == "Orientation")
    {
        widget->setOrientation(MStatic_cast(Qt::Orientation, value));
    }
}

void TTKToggleWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKToggleWidget *widget = MStatic_cast(TTKToggleWidget*, m_item);
    if(property->propertyName() == "DisabledColor")
    {
        widget->setDisabledColor(value);
    }
    else if(property->propertyName() == "ActiveColor")
    {
        widget->setActiveColor(value);
    }
    else if(property->propertyName() == "InactiveColor")
    {
        widget->setInactiveColor(value);
    }
    else if(property->propertyName() == "TrackColor")
    {
        widget->setTrackColor(value);
    }
}
