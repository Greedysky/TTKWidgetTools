#include "ttkprogresswidgetproperty.h"
#include "ttkprogresswidget.h"

TTKProgressWidgetProperty::TTKProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *progressColorItem = m_colorManager->addProperty("ProgressColor");
    m_colorManager->setValue(progressColorItem, QColor(255, 255, 0));
    objectItem->addSubProperty(progressColorItem);
    //
    QtProperty *backgroundCItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundCItem, QColor(200, 200, 200));
    objectItem->addSubProperty(backgroundCItem);
    //
    m_browser->addProperty(objectItem);
}

TTKProgressWidgetProperty::~TTKProgressWidgetProperty()
{

}

void TTKProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKProgressWidget *widget = MStatic_cast(TTKProgressWidget*, m_item);
    if(property->propertyName() == "ProgressColor")
    {
        widget->setProgressColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
