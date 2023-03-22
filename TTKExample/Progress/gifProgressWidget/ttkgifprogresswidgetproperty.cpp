#include "ttkgifprogresswidgetproperty.h"
#include "ttkgifprogresswidget.h"

TTKGifProgressWidgetProperty::TTKGifProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKGifProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKGifProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *typeItem = m_enumManager->addProperty("Type");
    QStringList enumNames;
    enumNames << "BallonWhite" << "CicleBlue" << "RiceFontWhite" << "RiceFontBlack"
              << "RiceFontBlackBig" << "HourglassWhite" << "RadioBlue" << "CheckBlue"
              << "Recordred" << "CloseWhite";
    m_enumManager->setEnumNames(typeItem, enumNames);
    objectItem->addSubProperty(typeItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKGifProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKGifProgressWidget *widget = TTKObjectCast(TTKGifProgressWidget*, m_item);
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
    TTKGifProgressWidget *widget = TTKObjectCast(TTKGifProgressWidget*, m_item);
    if(property->propertyName() == "Type")
    {
        widget->setType(TTKStaticCast(TTKGifProgressWidget::Module, value));
    }
}
