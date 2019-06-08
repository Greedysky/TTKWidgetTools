#include "ttklayoutanimationwidgetproperty.h"
#include "ttklayoutanimationwidget.h"

TTKLayoutAnimationWidgetProperty::TTKLayoutAnimationWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLayoutAnimationWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKLayoutAnimationWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, false);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    //
    QWidget *w1 = new QWidget(m_item);
    w1->setStyleSheet("border:none; background:red");
    QWidget *w2 = new QWidget(m_item);
    w2->setStyleSheet("border:none; background:yellow");

    TTKLayoutAnimationWidget *widget = MStatic_cast(TTKLayoutAnimationWidget*, m_item);
    widget->addWidget(w1);
    widget->addWidget(w2);
}

TTKLayoutAnimationWidgetProperty::~TTKLayoutAnimationWidgetProperty()
{

}

void TTKLayoutAnimationWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKLayoutAnimationWidget *widget = MStatic_cast(TTKLayoutAnimationWidget*, m_item);
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
