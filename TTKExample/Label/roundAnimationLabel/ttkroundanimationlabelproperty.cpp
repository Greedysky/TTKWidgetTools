#include "ttkroundanimationlabelproperty.h"
#include "ttkroundanimationlabel.h"

TTKRoundAnimationLabelProperty::TTKRoundAnimationLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRoundAnimationLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRoundAnimationLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *pixmapItem = m_pixmapManager->addProperty("Pixmap");
    m_pixmapManager->setValue(pixmapItem, ":/res/1");
    objectItem->addSubProperty(pixmapItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRoundAnimationLabelProperty::~TTKRoundAnimationLabelProperty()
{

}

void TTKRoundAnimationLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKRoundAnimationLabel *widget = MStatic_cast(TTKRoundAnimationLabel*, m_item);
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            widget->start();
        }
        else
        {
            widget->stop();
        }
    }
}

void TTKRoundAnimationLabelProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKRoundAnimationLabel *widget = MStatic_cast(TTKRoundAnimationLabel*, m_item);
    if(property->propertyName() == "Pixmap")
    {
        widget->setPixmap(value);
    }
}
