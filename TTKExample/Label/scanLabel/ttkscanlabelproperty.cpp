#include "ttkscanlabelproperty.h"
#include "ttkscanlabel.h"

TTKScanLabelProperty::TTKScanLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKScanLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKScanLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *scanRadiusItem = m_intManager->addProperty("ScanRadius");
    m_intManager->setValue(scanRadiusItem, 50);
    objectItem->addSubProperty(scanRadiusItem);
    //
    QtProperty *scanWidthItem = m_intManager->addProperty("ScanWidth");
    m_intManager->setValue(scanWidthItem, 0);
    objectItem->addSubProperty(scanWidthItem);
    //
    QtProperty *scanColorItem = m_colorManager->addProperty("ScanColor");
    m_colorManager->setValue(scanColorItem, QColor(255, 100, 10));
    objectItem->addSubProperty(scanColorItem);
    //
    QtProperty *ringRadiusItem = m_intManager->addProperty("RingRadius");
    m_intManager->setValue(ringRadiusItem, 10);
    objectItem->addSubProperty(ringRadiusItem);
    //
    QtProperty *ringWidthItem = m_intManager->addProperty("RingWidth");
    m_intManager->setValue(ringWidthItem, 5);
    objectItem->addSubProperty(ringWidthItem);
    //
    QtProperty *ringColorItem = m_colorManager->addProperty("RingColor");
    m_colorManager->setValue(ringColorItem, QColor(255, 213, 110));
    objectItem->addSubProperty(ringColorItem);
    //
    QtProperty *imageRadiusItem = m_intManager->addProperty("ImageRadius");
    m_intManager->setValue(imageRadiusItem, 10);
    objectItem->addSubProperty(imageRadiusItem);
    //
    QtProperty *imageBorderWidthItem = m_intManager->addProperty("ImageBorderWidth");
    m_intManager->setValue(imageBorderWidthItem, 5);
    objectItem->addSubProperty(imageBorderWidthItem);
    //
    QtProperty *imageBorderColorItem = m_colorManager->addProperty("ImageBorderColor");
    m_colorManager->setValue(imageBorderColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(imageBorderColorItem);
    //
    QtProperty *imageItem = m_pixmapManager->addProperty("Image");
    m_pixmapManager->setValue(imageItem, ":/res/1");
    objectItem->addSubProperty(imageItem);
    //
    m_browser->addProperty(objectItem);
}

TTKScanLabelProperty::~TTKScanLabelProperty()
{

}

void TTKScanLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKScanLabel *widget = MStatic_cast(TTKScanLabel*, m_item);
    if(property->propertyName() == "ImageRadius")
    {
        widget->setImageRadius(value);
    }
    else if(property->propertyName() == "ImageBorderWidth")
    {
        widget->setImageBorderWidth(value);
    }
    else if(property->propertyName() == "ScanRadius")
    {
        widget->setScanRadius(value);
    }
    else if(property->propertyName() == "ScanWidth")
    {
        widget->setScanWidth(value);
    }
    else if(property->propertyName() == "RingRadius")
    {
        widget->setRingRadius(value);
    }
    else if(property->propertyName() == "RingWidth")
    {
        widget->setRingWidth(value);
    }
}

void TTKScanLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKScanLabel *widget = MStatic_cast(TTKScanLabel*, m_item);
    if(property->propertyName() == "ImageBorderColor")
    {
        widget->setImageBorderColor(value);
    }
    else if(property->propertyName() == "ScanColor")
    {
        widget->setScanColor(value);
    }
    else if(property->propertyName() == "RingColor")
    {
        widget->setRingColor(value);
    }
}

void TTKScanLabelProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKScanLabel *widget = MStatic_cast(TTKScanLabel*, m_item);
    if(property->propertyName() == "Image")
    {
        widget->setImage(value);
    }
}
