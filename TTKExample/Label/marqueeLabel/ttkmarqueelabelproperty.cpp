#include "ttkmarqueelabelproperty.h"
#include "ttkmarqueelabel.h"

TTKMarqueeLabelProperty::TTKMarqueeLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKMarqueeLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMarqueeLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKMarqueeLabelProperty::~TTKMarqueeLabelProperty()
{

}

void TTKMarqueeLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}
