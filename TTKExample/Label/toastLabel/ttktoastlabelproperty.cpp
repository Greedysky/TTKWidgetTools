#include "ttktoastlabelproperty.h"
#include "ttktoastlabel.h"

#include <QToolButton>

TTKToastLabelProperty::TTKToastLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_label = new TTKToastLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKToastLabel*, m_label)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *fontMarginItem = m_sizeManager->addProperty("FontMargin");
    m_sizeManager->setMinimum(fontMarginItem, QSize(0, 0));
    m_sizeManager->setValue(fontMarginItem, QSize(20, 20));
    objectItem->addSubProperty(fontMarginItem);
    //
    QtProperty *fontSizeItem = m_intManager->addProperty("FontSize");
    m_intManager->setMinimum(fontSizeItem, 0);
    m_intManager->setValue(fontSizeItem, 15);
    objectItem->addSubProperty(fontSizeItem);
    //
    QtProperty *boldtem = m_boolManager->addProperty("Bold");
    m_boolManager->setValue(boldtem, false);
    objectItem->addSubProperty(boldtem);
    //
    QtProperty *intervalItem = m_intManager->addProperty("Interval");
    m_intManager->setMinimum(intervalItem, 0);
    m_intManager->setValue(intervalItem, 1500);
    objectItem->addSubProperty(intervalItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKToastLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKToastLabel *widget = TTKStatic_cast(TTKToastLabel*, m_label);
    if(property->propertyName() == "Bold")
    {
        widget->setBold(value);
    }
}

void TTKToastLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKToastLabel *widget = TTKStatic_cast(TTKToastLabel*, m_label);
    if(property->propertyName() == "FontSize")
    {
        widget->setFontSize(value);
    }
    else if(property->propertyName() == "Interval")
    {
        widget->setTimerInterval(value);
    }
}

void TTKToastLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKToastLabel *widget = TTKStatic_cast(TTKToastLabel*, m_label);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKToastLabelProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    TTKToastLabel *widget = TTKStatic_cast(TTKToastLabel*, m_label);
    if(property->propertyName() == "FontMargin")
    {
        widget->setFontMargin(value.width(), value.height());
    }
}

void TTKToastLabelProperty::showWidget()
{
    TTKToastLabel *widget = TTKStatic_cast(TTKToastLabel*, m_label);
    widget->popup(m_containItem);
}
