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
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKStyleSlider*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
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
    m_colorManager->setValue(handleColorItem, QColor("#FFFEA1"));
    objectItem->addSubProperty(handleColorItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor("#4E4F4F"));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor("#FFFEA1"));
    objectItem->addSubProperty(backgroundColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKStyleSliderProperty::~TTKStyleSliderProperty()
{

}

void TTKStyleSliderProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKStyleSlider *widget = MStatic_cast(TTKStyleSlider*, m_item);
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
    TTKStyleSlider *widget = MStatic_cast(TTKStyleSlider*, m_item);
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
