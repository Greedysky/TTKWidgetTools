#include "ttkcodearealabelproperty.h"
#include "ttkcodearealabel.h"

TTKCodeAreaLabelProperty::TTKCodeAreaLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCodeAreaLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCodeAreaLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *codeCountItem = m_intManager->addProperty("CodeCount");
    m_intManager->setMinimum(codeCountItem, 0);
    m_intManager->setValue(codeCountItem, 6);
    objectItem->addSubProperty(codeCountItem);
    //
    QtProperty *noisyCountItem = m_intManager->addProperty("NoisyPointCount");
    m_intManager->setMinimum(noisyCountItem, 0);
    m_intManager->setValue(noisyCountItem, 200);
    objectItem->addSubProperty(noisyCountItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCodeAreaLabelProperty::~TTKCodeAreaLabelProperty()
{

}

void TTKCodeAreaLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCodeAreaLabel *widget = MStatic_cast(TTKCodeAreaLabel*, m_item);
    if(property->propertyName() == "CodeCount")
    {
        widget->setCodeCount(value);
    }
    else if(property->propertyName() == "NoisyPointCount")
    {
        widget->setNoisyPointCount(value);
    }
}
