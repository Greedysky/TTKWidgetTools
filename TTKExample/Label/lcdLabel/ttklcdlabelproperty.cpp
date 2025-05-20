#include "ttklcdlabelproperty.h"
#include "ttklcdlabel.h"

#include <QTimer>

TTKLcdLabelProperty::TTKLcdLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKLcdLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKLcdLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *pixelSizeItem = m_intManager->addProperty("PixelSize");
    m_intManager->setMinimum(pixelSizeItem, 0);
    m_intManager->setValue(pixelSizeItem, 2);
    objectItem->addSubProperty(pixelSizeItem);
    //
    QtProperty *spacingSizeItem = m_intManager->addProperty("SpacingSize");
    m_intManager->setMinimum(spacingSizeItem, 0);
    m_intManager->setValue(spacingSizeItem, 1);
    objectItem->addSubProperty(spacingSizeItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(backgroundColorItem, Qt::red);
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("PixelColor");
    m_colorManager->setValue(lineColorItem, QColor(32, 32, 32));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(foregroundColorItem, Qt::black);
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello World");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);

    QTimer::singleShot(1, this, SLOT(updateRender()));
}

void TTKLcdLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKLcdLabel *widget = TTKObjectCast(TTKLcdLabel*, m_item);
    if(property->propertyName() == "PixelSize")
    {
        widget->setPixelSize(value);
    }
    else if(property->propertyName() == "SpacingSize")
    {
        widget->setSpacingSize(value);
    }
}

void TTKLcdLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKLcdLabel *widget = TTKObjectCast(TTKLcdLabel*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKLcdLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLcdLabel *widget = TTKObjectCast(TTKLcdLabel*, m_item);
    if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
    else if(property->propertyName() == "PixelColor")
    {
        widget->setPixelColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}

void TTKLcdLabelProperty::updateRender()
{
    TTKLcdLabel *widget = TTKObjectCast(TTKLcdLabel*, m_item);
    widget->setText("Hello World");
}
