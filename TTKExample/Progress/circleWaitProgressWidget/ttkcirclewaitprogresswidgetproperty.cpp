#include "ttkcirclewaitprogresswidgetproperty.h"
#include "ttkcirclewaitprogresswidget.h"

TTKCircleWaitProgressWidgetProperty::TTKCircleWaitProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCircleWaitProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKCircleWaitProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *clockwiseRotateItem = m_boolManager->addProperty("ClockwiseRotate");
    m_boolManager->setValue(clockwiseRotateItem, true);
    objectItem->addSubProperty(clockwiseRotateItem);
    //
    QtProperty *rotateDeltaItem = m_intManager->addProperty("RotateDelta");
    m_intManager->setMinimum(rotateDeltaItem, 0);
    m_intManager->setValue(rotateDeltaItem, 36);
    objectItem->addSubProperty(rotateDeltaItem);
    //
    QtProperty *colorItem = m_colorManager->addProperty("Color");
    m_colorManager->setValue(colorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(colorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKCircleWaitProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKCircleWaitProgressWidget *widget = TTKObject_cast(TTKCircleWaitProgressWidget*, m_item);
    if(property->propertyName() == "ClockwiseRotate")
    {
        widget->setClockwiseRotate(value);
    }
}

void TTKCircleWaitProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCircleWaitProgressWidget *widget = TTKObject_cast(TTKCircleWaitProgressWidget*, m_item);
    if(property->propertyName() == "RotateDelta")
    {
        widget->setRotateDelta(value);
    }
}

void TTKCircleWaitProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCircleWaitProgressWidget *widget = TTKObject_cast(TTKCircleWaitProgressWidget*, m_item);
    if(property->propertyName() == "Color")
    {
        widget->setColor(value);
    }
}
