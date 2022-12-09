#include "ttkpiewaitprogresswidgetproperty.h"
#include "ttkpiewaitprogresswidget.h"

TTKPieWaitProgressWidgetProperty::TTKPieWaitProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPieWaitProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKPieWaitProgressWidget*, m_item)->className());
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
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(24, 189, 155));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, Qt::white);
    objectItem->addSubProperty(backgroundColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKPieWaitProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKPieWaitProgressWidget *widget = TTKObject_cast(TTKPieWaitProgressWidget*, m_item);
    if(property->propertyName() == "ClockWise")
    {
        widget->setClockWise(value);
    }
}

void TTKPieWaitProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPieWaitProgressWidget *widget = TTKObject_cast(TTKPieWaitProgressWidget*, m_item);
    if(property->propertyName() == "RotateDelta")
    {
        widget->setRotateDelta(value);
    }
}

void TTKPieWaitProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKPieWaitProgressWidget *widget = TTKObject_cast(TTKPieWaitProgressWidget*, m_item);
    if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
