#include "ttkcloudpanellabelproperty.h"
#include "ttkcloudpanellabel.h"

TTKCloudPanelLabelProperty::TTKCloudPanelLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCloudPanelLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCloudPanelLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *cloudStyleItem = m_enumManager->addProperty("CloudStyle");
    QStringList enumNames;
    enumNames << "CloudStyleBlack" << "CloudStyleWhite" << "CloudStyleBlue" << "CloudStylePurple";
    m_enumManager->setEnumNames(cloudStyleItem, enumNames);
    m_enumManager->setValue(cloudStyleItem, TTKCloudPanelLabel::CloudStyleBlack);
    objectItem->addSubProperty(cloudStyleItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *baseColorItem = m_colorManager->addProperty("BaseColor");
    m_colorManager->setValue(baseColorItem, QColor(80, 80, 80));
    objectItem->addSubProperty(baseColorItem);
    //
    QtProperty *arcColorItem = m_colorManager->addProperty("ArcColor");
    m_colorManager->setValue(arcColorItem, QColor(32, 32, 32));
    objectItem->addSubProperty(arcColorItem);
    //
    QtProperty *borderColorItem = m_colorManager->addProperty("BorderColor");
    m_colorManager->setValue(borderColorItem, QColor(0, 0x80, 0x80));
    objectItem->addSubProperty(borderColorItem);
    //
    QtProperty *iconColorItem = m_colorManager->addProperty("IconColor");
    m_colorManager->setValue(iconColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(iconColorItem);
    //
    QtProperty *pressColorItem = m_colorManager->addProperty("PressColor");
    m_colorManager->setValue(pressColorItem, QColor(0xc0, 0xc0, 0xc0));
    objectItem->addSubProperty(pressColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCloudPanelLabelProperty::~TTKCloudPanelLabelProperty()
{

}

void TTKCloudPanelLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKCloudPanelLabel *widget = MStatic_cast(TTKCloudPanelLabel*, m_item);
    if(property->propertyName() == "CloudStyle")
    {
        widget->setCloudStyle(MStatic_cast(TTKCloudPanelLabel::CloudStyle, value));
    }
}

void TTKCloudPanelLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCloudPanelLabel *widget = MStatic_cast(TTKCloudPanelLabel*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
    else if(property->propertyName() == "BaseColor")
    {
        widget->setBaseColor(value);
    }
    else if(property->propertyName() == "ArcColor")
    {
        widget->setArcColor(value);
    }
    else if(property->propertyName() == "BorderColor")
    {
        widget->setBorderColor(value);
    }
    else if(property->propertyName() == "IconColor")
    {
        widget->setIconColor(value);
    }
    else if(property->propertyName() == "PressColor")
    {
        widget->setPressColor(value);
    }
}
