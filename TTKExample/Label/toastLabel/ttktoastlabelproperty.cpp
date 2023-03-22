#include "ttktoastlabelproperty.h"
#include "ttktoastlabel2.h"

#include <QToolButton>

TTKToastLabelProperty::TTKToastLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_label = new TTKToastLabel2(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKToastLabel2*, m_label)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKToastLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKToastLabel2 *widget = TTKObjectCast(TTKToastLabel2*, m_label);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKToastLabelProperty::showWidget()
{
    TTKToastLabel2 *widget = TTKObjectCast(TTKToastLabel2*, m_label);
    widget->popup(m_containItem);
}
