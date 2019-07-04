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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKGifProgressWidget*, m_item)->getClassName());
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
    enumNames << "BallonWhite" << "CicleBlue" << "RiceFontWhite" << "RiceFontBlack"
              << "RiceFontBlackBig" << "HourglassWhite" << "RadioBlue" << "CheckBlue"
              << "Recordred" << "CloseWhite";
    m_enumManager->setEnumNames(typeItem, enumNames);
    objectItem->addSubProperty(typeItem);
    //
    m_browser->addProperty(objectItem);
}

TTKGifProgressWidgetProperty::~TTKGifProgressWidgetProperty()
{
}

void TTKGifProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKGifProgressWidget *widget = MStatic_cast(TTKGifProgressWidget*, m_item);
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
    TTKGifProgressWidget *widget = MStatic_cast(TTKGifProgressWidget*, m_item);
    if(property->propertyName() == "Type")
    {
        widget->setType(MStatic_cast(TTKGifProgressWidget::Type, value));
    }
}
