#include "ttktilebackgroundlabelproperty.h"
#include "ttktilebackgroundlabel.h"

TTKTileBackgroundLabelProperty::TTKTileBackgroundLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKTileBackgroundLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKTileBackgroundLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *foreColorItem = m_colorManager->addProperty("ForeColor");
    m_colorManager->setValue(foreColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(foreColorItem);
    //
    QtProperty *backColorItem = m_colorManager->addProperty("BackColor");
    m_colorManager->setValue(backColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(backColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKTileBackgroundLabelProperty::~TTKTileBackgroundLabelProperty()
{

}

void TTKTileBackgroundLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKTileBackgroundLabel *widget = MStatic_cast(TTKTileBackgroundLabel*, m_item);
    if(property->propertyName() == "ForeColor")
    {
        widget->setForeColor(value);
    }
    else if(property->propertyName() == "BackColor")
    {
        widget->setBackColor(value);
    }
}
