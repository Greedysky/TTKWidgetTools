#include "ttkcircleclicklabelproperty.h"
#include "ttkcircleclicklabel.h"

TTKCircleClickLabelProperty::TTKCircleClickLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCircleClickLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCircleClickLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCircleClickLabelProperty::~TTKCircleClickLabelProperty()
{

}
