#include "ttksplititemlabelproperty.h"
#include "ttksplititemlabel.h"

TTKSplitItemLabelProperty::TTKSplitItemLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSplitItemLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKSplitItemLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *splitItem = m_stringManager->addProperty("Split");
    m_stringManager->setValue(splitItem, TTK_DEFAULT_STR);
    objectItem->addSubProperty(splitItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello - World - Test");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKSplitItemLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKSplitItemLabel *widget = TTKStatic_cast(TTKSplitItemLabel*, m_item);
    if(property->propertyName() == "Split")
    {
        widget->setSplitString(value);
    }
    else if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}
