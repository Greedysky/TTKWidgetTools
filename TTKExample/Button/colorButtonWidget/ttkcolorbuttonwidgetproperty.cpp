#include "ttkcolorbuttonwidgetproperty.h"
#include "ttkcolorbuttonwidget.h"

TTKColorButtonWidgetProperty::TTKColorButtonWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKColorButtonWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKColorButtonWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *spaceItem = m_intManager->addProperty("Space");
    m_intManager->setMinimum(spaceItem, 0);
    m_intManager->setValue(spaceItem, 2);
    objectItem->addSubProperty(spaceItem);
    //
    QtProperty *columnCountItem = m_intManager->addProperty("ColumnCount");
    m_intManager->setMinimum(columnCountItem, 0);
    m_intManager->setValue(columnCountItem, 11);
    objectItem->addSubProperty(columnCountItem);
    //
    QtProperty *borderRadiusItem = m_intManager->addProperty("BorderRadius");
    m_intManager->setMinimum(borderRadiusItem, 0);
    m_intManager->setValue(borderRadiusItem, 0);
    objectItem->addSubProperty(borderRadiusItem);
    //
    QtProperty *borderWidthItem = m_intManager->addProperty("BorderWidth");
    m_intManager->setMinimum(borderWidthItem, 0);
    m_intManager->setValue(borderWidthItem, 2);
    objectItem->addSubProperty(borderWidthItem);
    //
    QtProperty *borderColorItem = m_colorManager->addProperty("BorderColor");
    m_colorManager->setValue(borderColorItem, QColor("#C0392B"));
    objectItem->addSubProperty(borderColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKColorButtonWidgetProperty::~TTKColorButtonWidgetProperty()
{

}

void TTKColorButtonWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKColorButtonWidget *widget = MStatic_cast(TTKColorButtonWidget*, m_item);
    if(property->propertyName() == "Space")
    {
        widget->setSpace(value);
    }
    else if(property->propertyName() == "ColumnCount")
    {
        widget->setColumnCount(value);
    }
    else if(property->propertyName() == "BorderRadius")
    {
        widget->setBorderRadius(value);
    }
    else if(property->propertyName() == "BorderWidth")
    {
        widget->setBorderWidth(value);
    }
}

void TTKColorButtonWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKColorButtonWidget *widget = MStatic_cast(TTKColorButtonWidget*, m_item);
    if(property->propertyName() == "BorderColor")
    {
        widget->setBorderColor(value);
    }
}
