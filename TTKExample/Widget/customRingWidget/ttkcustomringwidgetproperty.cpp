#include "ttkcustomringwidgetproperty.h"
#include "ttkcustomringwidget.h"

TTKCustomRingWidgetProperty::TTKCustomRingWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCustomRingWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCustomRingWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *outCircleColorItem = m_colorManager->addProperty("OutCircleColor");
    m_colorManager->setValue(outCircleColorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(outCircleColorItem);
    //
    QtProperty *midCircleColorItem = m_colorManager->addProperty("MidCircleColor");
    m_colorManager->setValue(midCircleColorItem, QColor(0, 255, 0));
    objectItem->addSubProperty(midCircleColorItem);
    //
    QtProperty *inCircleColorItem = m_colorManager->addProperty("InCircleColor");
    m_colorManager->setValue(inCircleColorItem, QColor(0, 0, 255));
    objectItem->addSubProperty(inCircleColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKCustomRingWidgetProperty::~TTKCustomRingWidgetProperty()
{

}

void TTKCustomRingWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCustomRingWidget *widget = MStatic_cast(TTKCustomRingWidget*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
    else if(property->propertyName() == "OutCircleColor")
    {
        widget->setOutCircleColor(value);
    }
    else if(property->propertyName() == "MidCircleColor")
    {
        widget->setMidCircleColor(value);
    }
    else if(property->propertyName() == "InCircleColor")
    {
        widget->setInCircleColor(value);
    }
}
