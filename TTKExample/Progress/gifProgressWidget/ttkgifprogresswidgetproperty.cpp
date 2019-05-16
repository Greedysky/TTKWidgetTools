#include "ttkgifprogresswidgetproperty.h"
#include "ttkgifprogresswidget.h"

TTKGifProgressWidgetProperty::TTKGifProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKGifLabelWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKGifLabelWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *typeItem = m_enumManager->addProperty("Type");
    QStringList enumNames;
    enumNames << "Ballon_White" << "Cicle_Blue" << "Rice_Font_White" << "Rice_Font_Black"
              << "Rice_Font_Black_Big" << "Hourglass_White" << "Radio_Blue" << "Check_Blue"
              << "Record_red" << "Close_White";
    m_enumManager->setEnumNames(typeItem, enumNames);
    objectItem->addSubProperty(typeItem);
    //
    m_browser->addProperty(objectItem);
}

TTKGifProgressWidgetProperty::~TTKGifProgressWidgetProperty()
{


void TTKGifProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKGifLabelWidget *widget = MStatic_cast(TTKGifLabelWidget*, m_item);
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

void TTKGifProgressWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKGifLabelWidget *widget = MStatic_cast(TTKGifLabelWidget*, m_item);
    if(property->propertyName() == "Type")
    {
        widget->setType((TTKGifLabelWidget::Type)value);
    }
}
