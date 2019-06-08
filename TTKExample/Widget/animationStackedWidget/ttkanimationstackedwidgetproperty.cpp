#include "ttkanimationstackedwidgetproperty.h"
#include "ttkanimationstackedwidget.h"
#include <QPushButton>

TTKAnimationStackedWidgetProperty::TTKAnimationStackedWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKAnimationStackedWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKAnimationStackedWidget*, m_item)->getClassName());
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
    enumNames << "LeftToRight" << "RightToLeft" << "TopToBottom" << "BottomToTop";
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

    TTKAnimationStackedWidget *widget = MStatic_cast(TTKAnimationStackedWidget*, m_item);
    widget->addWidget(w1);
    widget->addWidget(w2);
}

TTKAnimationStackedWidgetProperty::~TTKAnimationStackedWidgetProperty()
{

}

void TTKAnimationStackedWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKAnimationStackedWidget *widget = MStatic_cast(TTKAnimationStackedWidget*, m_item);
    if(property->propertyName() == "Activity")
    {
        widget->start(value ? 0 : 1);
    }
}

void TTKAnimationStackedWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKAnimationStackedWidget *widget = MStatic_cast(TTKAnimationStackedWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setLength(value < 2 ? 200 : 100, MStatic_cast(TTKAnimationStackedWidget::AnimationType, value));
    }
}
