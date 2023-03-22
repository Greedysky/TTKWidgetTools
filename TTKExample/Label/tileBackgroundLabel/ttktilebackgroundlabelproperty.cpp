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
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKTileBackgroundLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(backgroundColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKTileBackgroundLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKTileBackgroundLabel *widget = TTKObjectCast(TTKTileBackgroundLabel*, m_item);
    if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
