#include "ttkstylesliderproperty.h"
#include "ttkstyleslider.h"

TTKStyleSliderProperty::TTKStyleSliderProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKStyleSlider(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKStyleSlider*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *directionItem = m_enumManager->addProperty("Direction");
    QStringList enumNames;
    enumNames << "Horizontal" << "Vertical";
    m_enumManager->setEnumNames(directionItem, enumNames);
    m_enumManager->setValue(directionItem, 0);
    objectItem->addSubProperty(directionItem);
    //
    QtProperty *handleColorItem = m_colorManager->addProperty("HandleColor");
    m_colorManager->setValue(handleColorItem, QColor(0xFF, 0xFE, 0xA1));
    objectItem->addSubProperty(handleColorItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(0x4E, 0x4F, 0x4F));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(0xFF, 0xFE, 0xA1));
    objectItem->addSubProperty(backgroundColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKStyleSliderProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKStyleSlider *widget = TTKObjectCast(TTKStyleSlider*, m_item);
    if(property->propertyName() == "Direction")
    {
        Qt::Orientation orientation(Qt::Horizontal);
        switch(value)
        {
            case 0: orientation = Qt::Horizontal; break;
            case 1: orientation = Qt::Vertical; break;
        }
        widget->setOrientation(orientation);
    }
}

void TTKStyleSliderProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKStyleSlider *widget = TTKObjectCast(TTKStyleSlider*, m_item);
    if(property->propertyName() == "HandleColor")
    {
        widget->setHandleColor(value);
    }
    else if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
