#include "ttkfunctiontoolboxwidgetproperty.h"
#include "ttkfunctiontoolboxwidget.h"

TTKFunctionToolBoxWidgetProperty::TTKFunctionToolBoxWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKFunctionToolBoxWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFunctionToolBoxWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    TTKFunctionToolBoxWidget *widget = MStatic_cast(TTKFunctionToolBoxWidget*, m_item);
    QWidget *red = new QWidget(this);
    red->setStyleSheet("background:red");
    red->setFixedHeight(100);
    widget->addItem(red, "red");

    QWidget *blue = new QWidget(this);
    blue->setStyleSheet("background:blue");
    blue->setFixedHeight(100);
    widget->addItem(blue, "blue");

    QWidget *yellow = new QWidget(this);
    yellow->setStyleSheet("background:yellow");
    yellow->setFixedHeight(100);
    widget->addItem(yellow, "yellow");
}

TTKFunctionToolBoxWidgetProperty::~TTKFunctionToolBoxWidgetProperty()
{

}
