#include "ttkwaveprogresswidgetproperty.h"
#include "ttkwaveprogresswidget.h"

TTKWaveProgressWidgetProperty::TTKWaveProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKWaveProgressWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKWaveProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *maxValueItem = m_intManager->addProperty("MaxValue");
    m_intManager->setMinimum(maxValueItem, 0);
    m_intManager->setValue(maxValueItem, 100);
    objectItem->addSubProperty(maxValueItem);
    //
    QtProperty *minValueItem = m_intManager->addProperty("MinValue");
    m_intManager->setMinimum(minValueItem, 0);
    m_intManager->setValue(minValueItem, 0);
    objectItem->addSubProperty(minValueItem);
    //
    QtProperty *valueItem = m_intManager->addProperty("Value");
    m_intManager->setValue(valueItem, 45);
    objectItem->addSubProperty(valueItem);
    //
    QtProperty *waterDensityItem = m_intManager->addProperty("WaterDensity");
    m_intManager->setValue(waterDensityItem, 2);
    objectItem->addSubProperty(waterDensityItem);
    //
    QtProperty *waterHeightItem = m_doubleManager->addProperty("WaterHeight");
    m_doubleManager->setMaximum(waterHeightItem, 0.2);
    m_doubleManager->setMinimum(waterHeightItem, 0.02);
    m_doubleManager->setValue(waterHeightItem, 0.02);
    objectItem->addSubProperty(waterHeightItem);
    //
    QtProperty *offsetItem = m_intManager->addProperty("Offset");
    m_intManager->setValue(offsetItem, 0);
    objectItem->addSubProperty(offsetItem);
    //
    QtProperty *borderWidthItem = m_doubleManager->addProperty("BorderWidth");
    m_doubleManager->setMinimum(borderWidthItem, 0);
    m_doubleManager->setValue(borderWidthItem, 2);
    objectItem->addSubProperty(borderWidthItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, QColor(0, 100, 255));
    objectItem->addSubProperty(bgColorItem);
    //
    QtProperty *percentStyleItem = m_enumManager->addProperty("PercentStyle");
    QStringList enumNames;
    enumNames << "PercentStyleRect" << "PercentStyleCircle" << "PercentStyleEllipse";
    m_enumManager->setEnumNames(percentStyleItem, enumNames);
    m_enumManager->setValue(percentStyleItem, TTKWaveProgressWidget::PercentStyleCircle);
    objectItem->addSubProperty(percentStyleItem);
    //
    m_browser->addProperty(objectItem);
}

TTKWaveProgressWidgetProperty::~TTKWaveProgressWidgetProperty()
{

}

void TTKWaveProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKWaveProgressWidget *widget = MStatic_cast(TTKWaveProgressWidget*, m_item);
    if(property->propertyName() == "MaxValue")
    {
        widget->setMaxValue(value);
    }
    else if(property->propertyName() == "MinValue")
    {
        widget->setMinValue(value);
    }
    else if(property->propertyName() == "Value")
    {
        widget->setValue(value);
    }
    else if(property->propertyName() == "WaterDensity")
    {
        widget->setWaterDensity(value);
    }
    else if(property->propertyName() == "Offset")
    {
        widget->setOffset(value);
    }
}

void TTKWaveProgressWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKWaveProgressWidget *widget = MStatic_cast(TTKWaveProgressWidget*, m_item);
    if(property->propertyName() == "WaterHeight")
    {
        widget->setWaterHeight(value);
    }
    else if(property->propertyName() == "BorderWidth")
    {
        widget->setBorderWidth(value);
    }
}

void TTKWaveProgressWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKWaveProgressWidget *widget = MStatic_cast(TTKWaveProgressWidget*, m_item);
    if(property->propertyName() == "PercentStyle")
    {
        widget->setPointerStyle(MStatic_cast(TTKWaveProgressWidget::PercentStyle, value));
    }
}

void TTKWaveProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKWaveProgressWidget *widget = MStatic_cast(TTKWaveProgressWidget*, m_item);
    if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
}

