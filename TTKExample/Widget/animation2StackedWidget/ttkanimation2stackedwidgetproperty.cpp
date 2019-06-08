#include "ttkanimation2stackedwidgetproperty.h"
#include "ttkanimation2stackedwidget.h"
#include <QPushButton>

TTKAnimation2StackedWidgetProperty::TTKAnimation2StackedWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKAnimation2StackedWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKAnimation2StackedWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "RollInOut" << "FadeInOut" << "BlackInOut" << "SlideInOut";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 0);
    objectItem->addSubProperty(directionItem);
    //
    m_browser->addProperty(objectItem);

    //
    QPushButton *w1 = new QPushButton(m_item);
    w1->setStyleSheet("border:none; background:red");
    QPushButton *w2 = new QPushButton(m_item);
    w2->setStyleSheet("border:none; background:yellow");

    TTKAnimation2StackedWidget *widget = MStatic_cast(TTKAnimation2StackedWidget*, m_item);
    widget->addWidget(w1);
    widget->addWidget(w2);
}

TTKAnimation2StackedWidgetProperty::~TTKAnimation2StackedWidgetProperty()
{

}

void TTKAnimation2StackedWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKAnimation2StackedWidget *widget = MStatic_cast(TTKAnimation2StackedWidget*, m_item);
    if(property->propertyName() == "Activity")
    {
        widget->start(value ? 0 : 1);
    }
}

void TTKAnimation2StackedWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKAnimation2StackedWidget *widget = MStatic_cast(TTKAnimation2StackedWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setLength(200, MStatic_cast(TTKAnimation2StackedWidget::AnimationType, value + 4));
    }
}
