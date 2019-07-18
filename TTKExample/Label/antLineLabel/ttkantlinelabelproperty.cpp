#include "ttkantlinelabelproperty.h"
#include "ttkantlinelabel.h"

TTKAntLineLabelProperty::TTKAntLineLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKAntLineLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKAntLineLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *lineLenItem = m_intManager->addProperty("LineLen");
    m_intManager->setValue(lineLenItem, 3);
    m_intManager->setMinimum(lineLenItem, 1);
    objectItem->addSubProperty(lineLenItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setValue(lineWidthItem, 6);
    m_intManager->setMinimum(lineWidthItem, 1);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *lineStepItem = m_intManager->addProperty("LineStep");
    m_intManager->setValue(lineStepItem, 1);
    m_intManager->setMinimum(lineStepItem, 1);
    objectItem->addSubProperty(lineStepItem);
    //
    QtProperty *lineSpeedItem = m_intManager->addProperty("LineSpeed");
    m_intManager->setValue(lineSpeedItem, 500);
    m_intManager->setMinimum(lineSpeedItem,1);
    objectItem->addSubProperty(lineSpeedItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(60, 179, 133));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *lineStyleItem = m_enumManager->addProperty("LineStyle");
    QStringList enumNames;
    enumNames << "LineStyleRect" << "LineStyleRoundedRect" << "LineStyleEllipse" << "LineStyleCircle";
    m_enumManager->setEnumNames(lineStyleItem, enumNames);
    m_enumManager->setValue(lineStyleItem, TTKAntLineLabel::LineStyleRect);
    objectItem->addSubProperty(lineStyleItem);
    //
    m_browser->addProperty(objectItem);
}

TTKAntLineLabelProperty::~TTKAntLineLabelProperty()
{

}

void TTKAntLineLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKAntLineLabel *widget = MStatic_cast(TTKAntLineLabel*, m_item);
    if(property->propertyName() == "LineLen")
    {
        widget->setLineLen(value);
    }
    else if(property->propertyName() == "LineWidth")
    {
        widget->setLineWidth(value);
    }
    else if(property->propertyName() == "LineStep")
    {
        widget->setLineStep(value);
    }
    else if(property->propertyName() == "LineSpeed")
    {
        widget->setLineSpeed(value);
    }
}

void TTKAntLineLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKAntLineLabel *widget = MStatic_cast(TTKAntLineLabel*, m_item);
    if(property->propertyName() == "LineStyle")
    {
        widget->setLineStyle(MStatic_cast(TTKAntLineLabel::LineStyle, value));
    }
}

void TTKAntLineLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKAntLineLabel *widget = MStatic_cast(TTKAntLineLabel*, m_item);
    if(property->propertyName() == "LineColor")
    {
        widget->setLineColor(value);
    }
}
