#include "ttktransitionanimationlabelproperty.h"
#include "ttktransitionanimationlabel.h"

TTKTransitionAnimationLabelProperty::TTKTransitionAnimationLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKTransitionAnimationLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKTransitionAnimationLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
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

void TTKTransitionAnimationLabelProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKTransitionAnimationLabel *widget = TTKObject_cast(TTKTransitionAnimationLabel*, m_item);
    if(property->propertyName() == "Pixmap")
    {
        widget->setPixmap(value);
    }
}
