#include "ttkmovedialogproperty.h"
#include "ttkmovedialog.h"

#include <QToolButton>

TTKMoveDialogProperty::TTKMoveDialogProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_label = new TTKMoveDialog(false, this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMoveDialog*, m_label)->getClassName());
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

TTKMoveDialogProperty::~TTKMoveDialogProperty()
{

}

void TTKMoveDialogProperty::showWidget()
{
    m_label->resize(200, 200);
    m_label->show();
}
