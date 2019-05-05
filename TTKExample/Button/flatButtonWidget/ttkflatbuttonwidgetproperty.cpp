#include "ttkflatbuttonwidgetproperty.h"
#include "ttkflatbuttonwidget.h"

TTKFlatButtonWidgetProperty::TTKFlatButtonWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKFlatButtonWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFlatButtonWidget*, m_item)->getClassName());
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
    QtProperty *cornerRadiusItem = m_intManager->addProperty("CornerRadius");
    m_intManager->setMinimum(cornerRadiusItem, 0);
    m_intManager->setValue(cornerRadiusItem, 5);
    objectItem->addSubProperty(cornerRadiusItem);
    //
    QtProperty *iconItem = m_pixmapManager->addProperty("Icon");
    objectItem->addSubProperty(iconItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("IconAlignment");
    QStringList enumNames;
    enumNames << "LeftIcon" << "RightIcon";
    m_enumManager->setEnumNames(directionItem, enumNames);
    objectItem->addSubProperty(directionItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(0, 0, 200));
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKFlatButtonWidgetProperty::~TTKFlatButtonWidgetProperty()
{

}

void TTKFlatButtonWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "Enable")
    {
        widget->setEnabled(value);
    }
}

void TTKFlatButtonWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "CornerRadius")
    {
        widget->setCornerRadius(value);
    }
}

void TTKFlatButtonWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKFlatButtonWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "IconAlignment")
    {
        widget->setIconAlignment(MStatic_cast(TTKFlatButtonWidget::IconAlignment, value));
    }
}

void TTKFlatButtonWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}

void TTKFlatButtonWidgetProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKFlatButtonWidget *widget = MStatic_cast(TTKFlatButtonWidget*, m_item);
    if(property->propertyName() == "Icon")
    {
        widget->setIcon(QPixmap(value));
    }
}
