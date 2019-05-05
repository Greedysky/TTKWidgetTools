#include "ttkradiobuttonwidgetproperty.h"
#include "ttkradiobuttonwidget.h"

TTKRadioButtonWidgetProperty::TTKRadioButtonWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRadioButtonWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRadioButtonWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *enableItem = m_boolManager->addProperty("Enable");
    m_boolManager->setValue(enableItem, true);
    objectItem->addSubProperty(enableItem);
    //
    QtProperty *checkedItem = m_boolManager->addProperty("Checked");
    objectItem->addSubProperty(checkedItem);
    //
    QtProperty *disabledColorItem = m_colorManager->addProperty("DisabledColor");
    m_colorManager->setValue(disabledColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(disabledColorItem);
    //
    QtProperty *checkedColorItem = m_colorManager->addProperty("CheckedColor");
    m_colorManager->setValue(checkedColorItem, QColor(255, 0, 0));
    objectItem->addSubProperty(checkedColorItem);
    //
    QtProperty *uncheckedColorItem = m_colorManager->addProperty("UncheckedColor");
    objectItem->addSubProperty(uncheckedColorItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "LabelPositionLeft" << "LabelPositionRight";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, TTKRadioButtonWidget::LabelPositionRight);
    objectItem->addSubProperty(directionItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRadioButtonWidgetProperty::~TTKRadioButtonWidgetProperty()
{

}

void TTKRadioButtonWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKRadioButtonWidget *widget = MStatic_cast(TTKRadioButtonWidget*, m_item);
    if(property->propertyName() == "Enable")
    {
        widget->setEnabled(value);
    }
    else if(property->propertyName() == "Checked")
    {
        widget->setChecked(value);
    }
}

void TTKRadioButtonWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKRadioButtonWidget *widget = MStatic_cast(TTKRadioButtonWidget*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKRadioButtonWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKRadioButtonWidget *widget = MStatic_cast(TTKRadioButtonWidget*, m_item);
    if(property->propertyName() == "Direction")
    {
        widget->setLabelPosition(MStatic_cast(TTKRadioButtonWidget::LabelPosition, value));
    }
}

void TTKRadioButtonWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKRadioButtonWidget *widget = MStatic_cast(TTKRadioButtonWidget*, m_item);
    if(property->propertyName() == "DisabledColor")
    {
        widget->setDisabledColor(value);
    }
    else if(property->propertyName() == "CheckedColor")
    {
        widget->setCheckedColor(value);
    }
    else if(property->propertyName() == "UncheckedColor")
    {
        widget->setUncheckedColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
}
