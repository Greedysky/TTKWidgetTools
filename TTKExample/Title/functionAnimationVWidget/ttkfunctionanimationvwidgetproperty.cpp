#include "ttkfunctionanimationvwidgetproperty.h"
#include "ttkfunctionanimationwidget.h"

TTKOptionAnimationVWidgetProperty::TTKOptionAnimationVWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKOptionAnimationVWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKOptionAnimationVWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Left" << "Right";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKOptionAnimationVWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKOptionAnimationVWidget *widget = TTKStatic_cast(TTKOptionAnimationVWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKBaseAnimationWidget::Alignment, value));
    }
}



TTKTableAnimationVWidgetProperty::TTKTableAnimationVWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKTableAnimationVWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKTableAnimationVWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Left" << "Right";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKTableAnimationVWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKTableAnimationVWidget *widget = TTKStatic_cast(TTKTableAnimationVWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKBaseAnimationWidget::Alignment, value));
    }
}



TTKSkinAnimationVWidgetProperty::TTKSkinAnimationVWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSkinAnimationVWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKSkinAnimationVWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Left" << "Right";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKSkinAnimationVWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKSkinAnimationVWidget *widget = TTKStatic_cast(TTKSkinAnimationVWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKBaseAnimationWidget::Alignment, value));
    }
}
