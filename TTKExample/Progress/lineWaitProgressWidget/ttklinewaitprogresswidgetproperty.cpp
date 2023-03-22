#include "ttklinewaitprogresswidgetproperty.h"
#include "ttklinewaitprogresswidget.h"

TTKLineWaitProgressWidgetProperty::TTKLineWaitProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLineWaitProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKLineWaitProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *clockWiseItem = m_boolManager->addProperty("ClockWise");
    m_boolManager->setValue(clockWiseItem, true);
    objectItem->addSubProperty(clockWiseItem);
    //
    QtProperty *rotateDeltaItem = m_intManager->addProperty("RotateDelta");
    m_intManager->setMinimum(rotateDeltaItem, 0);
    m_intManager->setValue(rotateDeltaItem, 36);
    objectItem->addSubProperty(rotateDeltaItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(46, 194, 164));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKLineWaitProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKLineWaitProgressWidget *widget = TTKObjectCast(TTKLineWaitProgressWidget*, m_item);
    if(property->propertyName() == "ClockWise")
    {
        widget->setClockWise(value);
    }
}

void TTKLineWaitProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKLineWaitProgressWidget *widget = TTKObjectCast(TTKLineWaitProgressWidget*, m_item);
    if(property->propertyName() == "RotateDelta")
    {
        widget->setRotateDelta(value);
    }
}

void TTKLineWaitProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLineWaitProgressWidget *widget = TTKObjectCast(TTKLineWaitProgressWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
