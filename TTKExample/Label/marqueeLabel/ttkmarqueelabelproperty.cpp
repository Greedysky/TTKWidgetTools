#include "ttkmarqueelabelproperty.h"
#include "ttkmarqueelabel.h"

TTKMarqueeLabelProperty::TTKMarqueeLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKMarqueeLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKMarqueeLabel*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *stepItem = m_intManager->addProperty("Step");
    m_intManager->setValue(stepItem, 2);
    m_intManager->setMinimum(stepItem, 1);
    objectItem->addSubProperty(stepItem);
    //
    QtProperty *intervalItem = m_intManager->addProperty("Interval");
    m_intManager->setValue(intervalItem, 20);
    m_intManager->setMinimum(intervalItem, 1);
    objectItem->addSubProperty(intervalItem);
    //
    QtProperty *mouseHoverStopItem = m_boolManager->addProperty("MouseHoverStop");
    m_boolManager->setValue(mouseHoverStopItem, false);
    objectItem->addSubProperty(mouseHoverStopItem);
    //
    QtProperty *moveStyleItem = m_enumManager->addProperty("MoveStyle");
    QStringList enumNames;
    enumNames << "MoveStyleLeftAndRight" << "MoveStyleLeftToRight" << "MoveStyleRightToLeft";
    m_enumManager->setEnumNames(moveStyleItem, enumNames);
    m_enumManager->setValue(moveStyleItem, TTKMarqueeLabel::MoveStyleLeftAndRight);
    objectItem->addSubProperty(moveStyleItem);
    //
    QtProperty *foregroundItem = m_colorManager->addProperty("Foreground");
    m_colorManager->setValue(foregroundItem, QColor(100, 184, 255));
    objectItem->addSubProperty(foregroundItem);
    //
    QtProperty *backgroundItem = m_colorManager->addProperty("Background");
    m_colorManager->setValue(backgroundItem, QColor(222, 222, 222));
    objectItem->addSubProperty(backgroundItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

TTKMarqueeLabelProperty::~TTKMarqueeLabelProperty()
{

}

void TTKMarqueeLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "MouseHoverStop")
    {
        widget->setMouseHoverStop(value);
    }
}

void TTKMarqueeLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "Step")
    {
        widget->setStep(value);
    }
    else if(property->propertyName() == "Interval")
    {
        widget->setInterval(value);
    }
}

void TTKMarqueeLabelProperty::stringPropertyChanged(QtProperty *property, const QString &value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKMarqueeLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "MoveStyle")
    {
        widget->setMoveStyle(MStatic_cast(TTKMarqueeLabel::MoveStyle, value));
    }
}

void TTKMarqueeLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKMarqueeLabel *widget = MStatic_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "Foreground")
    {
        widget->setForeground(value);
    }
    else if(property->propertyName() == "Background")
    {
        widget->setBackground(value);
    }
}
