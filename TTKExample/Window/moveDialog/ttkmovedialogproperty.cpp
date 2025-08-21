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
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKMoveDialog*, m_label)->metaObject()->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKMoveDialogProperty::showWidget()
{
    m_label->setFixedSize(200, 200);
    m_label->show();
}
