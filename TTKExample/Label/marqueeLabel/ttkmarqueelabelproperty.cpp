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
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKMarqueeLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
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
    m_enumManager->setValue(moveStyleItem, TTKStatic_cast(int, TTKMarqueeLabel::MoveStyle::LeftAndRight));
    objectItem->addSubProperty(moveStyleItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(100, 184, 255));
    objectItem->addSubProperty(foregroundColorItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(222, 222, 222));
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *textItem = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textItem, "Hello word");
    objectItem->addSubProperty(textItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKMarqueeLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKMarqueeLabel *widget = TTKObject_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "MouseHoverStop")
    {
        widget->setMouseHoverStop(value);
    }
}

void TTKMarqueeLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKMarqueeLabel *widget = TTKObject_cast(TTKMarqueeLabel*, m_item);
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
    TTKMarqueeLabel *widget = TTKObject_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "Text")
    {
        widget->setText(value);
    }
}

void TTKMarqueeLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKMarqueeLabel *widget = TTKObject_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "MoveStyle")
    {
        widget->setMoveStyle(TTKStatic_cast(TTKMarqueeLabel::MoveStyle, value));
    }
}

void TTKMarqueeLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKMarqueeLabel *widget = TTKObject_cast(TTKMarqueeLabel*, m_item);
    if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
    else if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
