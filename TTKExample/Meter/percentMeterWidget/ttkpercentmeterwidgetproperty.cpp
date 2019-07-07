#include "ttkpercentmeterwidgetproperty.h"
#include "ttkpercentmeterwidget.h"

TTKPercentMeterWidgetProperty::TTKPercentMeterWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPercentMeterWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKPercentMeterWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *maxValueItem = m_doubleManager->addProperty("MaxValue");
    m_doubleManager->setMinimum(maxValueItem, 0);
    m_doubleManager->setValue(maxValueItem, 100);
    objectItem->addSubProperty(maxValueItem);
    //
    QtProperty *minValueItem = m_doubleManager->addProperty("MinValue");
    m_doubleManager->setMinimum(minValueItem, 0);
    m_doubleManager->setValue(minValueItem, 0);
    objectItem->addSubProperty(minValueItem);
    //
    QtProperty *valueItem = m_doubleManager->addProperty("Value");
    m_doubleManager->setValue(valueItem, 50);
    objectItem->addSubProperty(valueItem);
    //
    QtProperty *precisionItem = m_intManager->addProperty("Precision");
    m_intManager->setValue(precisionItem, 0);
    m_intManager->setRange(precisionItem, 0, 2);
    objectItem->addSubProperty(precisionItem);
    //
    QtProperty *scaleMajorItem = m_intManager->addProperty("ScaleMajor");
    m_intManager->setValue(scaleMajorItem, 10);
    m_intManager->setMinimum(scaleMajorItem, 1);
    objectItem->addSubProperty(scaleMajorItem);
    //
    QtProperty *scaleMinorItem = m_intManager->addProperty("ScaleMinor");
    m_intManager->setValue(scaleMinorItem, 10);
    m_intManager->setMinimum(scaleMinorItem, 1);
    objectItem->addSubProperty(scaleMinorItem);
    //
    QtProperty *startAngleItem = m_intManager->addProperty("StartAngle");
    m_intManager->setValue(startAngleItem, 40);
    m_intManager->setMinimum(startAngleItem, 0);
    objectItem->addSubProperty(startAngleItem);
    //
    QtProperty *endAngleItem = m_intManager->addProperty("EndAngle");
    m_intManager->setValue(endAngleItem, 40);
    m_intManager->setMinimum(endAngleItem, 0);
    objectItem->addSubProperty(endAngleItem);
    //
    QtProperty *arcColorItem = m_colorManager->addProperty("ArcColor");
    m_colorManager->setValue(arcColorItem, QColor(114, 159, 207));
    objectItem->addSubProperty(arcColorItem);
    //
    QtProperty *scaleColorItem = m_colorManager->addProperty("ScaleColor");
    m_colorManager->setValue(scaleColorItem, QColor(233, 185, 110));
    objectItem->addSubProperty(scaleColorItem);
    //
    QtProperty *scaleNumColorItem = m_colorManager->addProperty("ScaleNumColor");
    m_colorManager->setValue(scaleNumColorItem, QColor(92, 53, 102));
    objectItem->addSubProperty(scaleNumColorItem);
    //
    QtProperty *titleItem = m_stringManager->addProperty("Title");
    m_stringManager->setValue(titleItem, "Hello");
    objectItem->addSubProperty(titleItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(46, 52, 54));
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *titleColorItem = m_colorManager->addProperty("TitleColor");
    m_colorManager->setValue(titleColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(titleColorItem);
    //
    QtProperty *baseColorItem = m_colorManager->addProperty("BaseColor");
    m_colorManager->setValue(baseColorItem, QColor(178, 221, 253));
    objectItem->addSubProperty(baseColorItem);
    //
    QtProperty *bgColorItem = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorItem, Qt::transparent);
    objectItem->addSubProperty(bgColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKPercentMeterWidgetProperty::~TTKPercentMeterWidgetProperty()
{

}

void TTKPercentMeterWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPercentMeterWidget *widget = MStatic_cast(TTKPercentMeterWidget*, m_item);
    if(property->propertyName() == "Precision")
    {
        widget->setPrecision(value);
    }
    else if(property->propertyName() == "ScaleMajor")
    {
        widget->setScaleMajor(value);
    }
    else if(property->propertyName() == "ScaleMinor")
    {
        widget->setScaleMinor(value);
    }
    else if(property->propertyName() == "StartAngle")
    {
        widget->setStartAngle(value);
    }
    else if(property->propertyName() == "EndAngle")
    {
        widget->setEndAngle(value);
    }
}

void TTKPercentMeterWidgetProperty::doublePropertyChanged(QtProperty *property, double value)
{
    TTKPercentMeterWidget *widget = MStatic_cast(TTKPercentMeterWidget*, m_item);
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
}

void TTKPercentMeterWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKPercentMeterWidget *widget = MStatic_cast(TTKPercentMeterWidget*, m_item);
    if(property->propertyName() == "Title")
    {
        widget->setTitle(value);
    }
}

void TTKPercentMeterWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKPercentMeterWidget *widget = MStatic_cast(TTKPercentMeterWidget*, m_item);
    if(property->propertyName() == "ArcColor")
    {
        widget->setArcColor(value);
    }
    else if(property->propertyName() == "ScaleColor")
    {
        widget->setScaleColor(value);
    }
    else if(property->propertyName() == "ScaleNumColor")
    {
        widget->setScaleNumColor(value);
    }
    else if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
    else if(property->propertyName() == "TitleColor")
    {
        widget->setTitleColor(value);
    }
    else if(property->propertyName() == "BaseColor")
    {
        widget->setBaseColor(value);
    }
    else if(property->propertyName() == "BgColor")
    {
        widget->setBgColor(value);
    }
}
