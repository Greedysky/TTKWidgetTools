#include "ttkmoveresizewidgetproperty.h"
#include "ttkmoveresizewidget.h"

#include <QToolButton>

TTKMoveResizeWidgetProperty::TTKMoveResizeWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_label = new TTKMoveResizeWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMoveResizeWidget*, m_label)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}

TTKMoveResizeWidgetProperty::~TTKMoveResizeWidgetProperty()
{

}

void TTKMoveResizeWidgetProperty::showWidget()
{
    m_label->setStyleSheet("background:black;");
    m_label->setMinimumSize(50, 50);
    m_label->setMaximumSize(200, 200);
    m_label->resize(100, 100);
    m_label->show();
}
