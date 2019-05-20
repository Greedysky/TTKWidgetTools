#include "ttkcircularprogresswidgetproperty.h"
#include "ttkcircularprogresswidget.h"

TTKCircularProgressWidgetProperty::TTKCircularProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCircularProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCircularProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *sizeItem = m_intManager->addProperty("Size");
    m_intManager->setMinimum(sizeItem, 0);
    m_intManager->setValue(sizeItem, 74);
    objectItem->addSubProperty(sizeItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 8);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCircularProgressWidgetProperty::~TTKCircularProgressWidgetProperty()
{

}

void TTKCircularProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCircularProgressWidget *widget = MStatic_cast(TTKCircularProgressWidget*, m_item);
    if(property->propertyName() == "Size")
    {
        widget->setSize(value);
    }
    else if(property->propertyName() == "LineWidth")
    {
        widget->setLineWidth(value);
    }
}

void TTKCircularProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCircularProgressWidget *widget = MStatic_cast(TTKCircularProgressWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
