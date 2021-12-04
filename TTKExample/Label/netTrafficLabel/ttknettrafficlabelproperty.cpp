#include "ttknettrafficlabelproperty.h"
#include "ttknettrafficlabel.h"

TTKNetTrafficLabelProperty::TTKNetTrafficLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKNetTrafficLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKNetTrafficLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    cards_ = TTKStatic_cast(TTKNetTrafficLabel*, m_item)->newtworkNames();
    QtProperty *typeItem = m_enumManager->addProperty("NetworkCard");
    QStringList enumNames;
    enumNames << "LabelPositionLeft" << "LabelPositionRight";
    m_enumManager->setEnumNames(typeItem, cards_);
    objectItem->addSubProperty(typeItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKNetTrafficLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKNetTrafficLabel *widget = TTKStatic_cast(TTKNetTrafficLabel*, m_item);
    if(property->propertyName() == "NetworkCard")
    {
        if(value < 0 || value >= cards_.count())
        {
            return;
        }
        widget->setAvailableNewtworkName(cards_[value]);
    }
}
