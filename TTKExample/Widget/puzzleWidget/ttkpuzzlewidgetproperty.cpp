#include "ttkpuzzlewidgetproperty.h"
#include "ttkpuzzlewidget.h"

TTKPuzzleWidgetProperty::TTKPuzzleWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPuzzleWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKPuzzleWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, false);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *squareWidthItem = m_intManager->addProperty("SquareWidth");
    m_intManager->setMinimum(squareWidthItem, 0);
    m_intManager->setValue(squareWidthItem, 100);
    objectItem->addSubProperty(squareWidthItem);
    //
    QtProperty *squareRadiusItem = m_intManager->addProperty("SquareRadius");
    m_intManager->setMinimum(squareRadiusItem, 0);
    m_intManager->setValue(squareRadiusItem, 30);
    objectItem->addSubProperty(squareRadiusItem);
    //
    QtProperty *imageItem = m_pixmapManager->addProperty("Image");
    m_pixmapManager->setValue(imageItem, ":/res/1");
    objectItem->addSubProperty(imageItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKPuzzleWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPuzzleWidget *widget = TTKStatic_cast(TTKPuzzleWidget*, m_item);
    if(property->propertyName() == "SquareWidth")
    {
        widget->setSquareWidth(value);
    }
    else if(property->propertyName() == "SquareRadius")
    {
        widget->setSquareRadius(value);
    }
}

void TTKPuzzleWidgetProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKPuzzleWidget *widget = TTKStatic_cast(TTKPuzzleWidget*, m_item);
    if(property->propertyName() == "Image")
    {
        widget->setPixmap(value);
    }
}
