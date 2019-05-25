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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKOptionAnimationHWidget*, m_item)->getClassName());
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
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

TTKOptionAnimationHWidgetProperty::~TTKOptionAnimationHWidgetProperty()
{

}

void TTKOptionAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKOptionAnimationHWidget *widget = MStatic_cast(TTKOptionAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(MStatic_cast(TTKBaseAnimationWidget::Alignment, value));
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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKTableAnimationHWidget*, m_item)->getClassName());
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
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

TTKTableAnimationHWidgetProperty::~TTKTableAnimationHWidgetProperty()
{

}

void TTKTableAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKTableAnimationHWidget *widget = MStatic_cast(TTKTableAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(MStatic_cast(TTKBaseAnimationWidget::Alignment, value));
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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKSkinAnimationHWidget*, m_item)->getClassName());
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
    enumNames << "Top" << "Bottom";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 1);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);
}

TTKSkinAnimationHWidgetProperty::~TTKSkinAnimationHWidgetProperty()
{

}

void TTKSkinAnimationHWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKSkinAnimationHWidget *widget = MStatic_cast(TTKSkinAnimationHWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setAlignment(MStatic_cast(TTKBaseAnimationWidget::Alignment, value));
    }
}
