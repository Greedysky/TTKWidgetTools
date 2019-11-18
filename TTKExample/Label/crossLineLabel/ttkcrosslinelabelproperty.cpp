#include "ttkcrosslinelabelproperty.h"
#include "ttkcrosslinelabel.h"

TTKCrossLineLabelProperty::TTKCrossLineLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCrossLineLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCrossLineLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *widthItem = m_intManager->addProperty("Width");
    m_intManager->setMinimum(widthItem, 0);
    m_intManager->setValue(widthItem, 2);
    objectItem->addSubProperty(widthItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCrossLineLabelProperty::~TTKCrossLineLabelProperty()
{

}

void TTKCrossLineLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCrossLineLabel *widget = MStatic_cast(TTKCrossLineLabel*, m_item);
    if(property->propertyName() == "Width")
    {
        widget->setWidth(value);
    }
}

void TTKCrossLineLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCrossLineLabel *widget = MStatic_cast(TTKCrossLineLabel*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
