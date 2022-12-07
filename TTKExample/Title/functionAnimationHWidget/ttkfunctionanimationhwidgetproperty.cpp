#include "ttkfunctionanimationhwidgetproperty.h"
#include "ttkfunctionanimationwidget.h"

TTKOptionAnimationHWidgetProperty::TTKOptionAnimationHWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKOptionAnimationHWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKOptionAnimationHWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKOptionAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKOptionAnimationHWidget *widget = TTKObject_cast(TTKOptionAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKAbstractAnimationWidget::Alignment, value));
    }
}



TTKTableAnimationHWidgetProperty::TTKTableAnimationHWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKTableAnimationHWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKTableAnimationHWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKTableAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKTableAnimationHWidget *widget = TTKObject_cast(TTKTableAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKAbstractAnimationWidget::Alignment, value));
    }
}



TTKSkinAnimationHWidgetProperty::TTKSkinAnimationHWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSkinAnimationHWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKSkinAnimationHWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKSkinAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKSkinAnimationHWidget *widget = TTKObject_cast(TTKSkinAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(TTKStatic_cast(TTKAbstractAnimationWidget::Alignment, value));
    }
}
