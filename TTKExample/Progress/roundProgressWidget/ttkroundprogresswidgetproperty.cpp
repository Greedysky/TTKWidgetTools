#include "ttkroundprogresswidgetproperty.h"
#include "ttkroundprogresswidget.h"

#include <QTimer>

TTKRoundProgressWidgetProperty::TTKRoundProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKRoundProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(500);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKRoundProgressWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *innerDefaultTextStyleItem = m_enumManager->addProperty("InnerDefaultTextStyle");
    QStringList innerNames;
    innerNames << "Percent" << "Value" << "ValueAndMax";
    m_enumManager->setEnumNames(innerDefaultTextStyleItem, innerNames);
    m_enumManager->setValue(innerDefaultTextStyleItem, 1);
    objectItem->addSubProperty(innerDefaultTextStyleItem);
    //
    QtProperty *controlFlagsItem = m_enumManager->addProperty("ControlFlags");
    QStringList controlNames;
    controlNames << "Null" << "DefaultText" << "LinearColor" << "DecorateDot"
                 << "OutterCirle" << "Animation" << "All";
    m_enumManager->setEnumNames(controlFlagsItem, controlNames);
    m_enumManager->setValue(controlFlagsItem, 6);
    objectItem->addSubProperty(controlFlagsItem);
    //
    QtProperty *outterColorItem = m_colorManager->addProperty("OutterColor");
    m_colorManager->setValue(outterColorItem, QColor(250, 55, 56));
    objectItem->addSubProperty(outterColorItem);
    //
    QtProperty *innerColorItem = m_colorManager->addProperty("InnerColor");
    m_colorManager->setValue(innerColorItem, QColor(255, 19, 157));
    objectItem->addSubProperty(innerColorItem);
    //
    QtProperty *defaultTextColorItem = m_colorManager->addProperty("DefaultTextColor");
    m_colorManager->setValue(defaultTextColorItem, QColor(255, 230, 129));
    objectItem->addSubProperty(defaultTextColorItem);
    //
    QtProperty *innerBarWidthItem = m_intManager->addProperty("InnerBarWidth");
    m_intManager->setMinimum(innerBarWidthItem, 10);
    m_intManager->setValue(innerBarWidthItem, 10);
    objectItem->addSubProperty(innerBarWidthItem);
    //
    QtProperty *outterBarWidthItem = m_intManager->addProperty("OutterBarWidth");
    m_intManager->setMinimum(outterBarWidthItem, 0);
    m_intManager->setValue(outterBarWidthItem, 20);
    objectItem->addSubProperty(outterBarWidthItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRoundProgressWidgetProperty::~TTKRoundProgressWidgetProperty()
{

}

void TTKRoundProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            m_timer->start();
        }
        else
        {
            m_timer->stop();
        }
    }
}

void TTKRoundProgressWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKRoundProgressWidget *widget = MStatic_cast(TTKRoundProgressWidget*, m_item);
    if(property->propertyName() == "InnerBarWidth")
    {
        widget->setInnerBarWidth(value);
    }
    else if(property->propertyName() == "OutterBarWidth")
    {
        widget->setOutterBarWidth(value);
    }
}

void TTKRoundProgressWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKRoundProgressWidget *widget = MStatic_cast(TTKRoundProgressWidget*, m_item);
    if(property->propertyName() == "InnerDefaultTextStyle")
    {
        TTKRoundProgressWidget::InnerDefaultTextStyle style(TTKRoundProgressWidget::Value);
        switch(value)
        {
            case 0: style = TTKRoundProgressWidget::Percent; break;
            case 1: style = TTKRoundProgressWidget::Value; break;
            case 2: style = TTKRoundProgressWidget::ValueAndMax; break;
        }
        widget->setInnerDefaultTextStyle(style);
    }
    else if(property->propertyName() == "ControlFlags")
    {
        TTKRoundProgressWidget::SwitchFlags style(TTKRoundProgressWidget::All);
        switch(value)
        {
            case 0: style = TTKRoundProgressWidget::Null; break;
            case 1: style = TTKRoundProgressWidget::DefaultText; break;
            case 2: style = TTKRoundProgressWidget::LinearColor; break;
            case 3: style = TTKRoundProgressWidget::DecorateDot; break;
            case 4: style = TTKRoundProgressWidget::OutterCirle; break;
            case 5: style = TTKRoundProgressWidget::Animation; break;
            case 6: style = TTKRoundProgressWidget::All; break;
        }
        widget->setControlFlags(style);
    }
}

void TTKRoundProgressWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKRoundProgressWidget *widget = MStatic_cast(TTKRoundProgressWidget*, m_item);
    if(property->propertyName() == "OutterColor")
    {
        widget->setOutterColor(value);
    }
    else if(property->propertyName() == "InnerColor")
    {
        widget->setInnerColor(value);
    }
    else if(property->propertyName() == "DefaultTextColor")
    {
        widget->setDefaultTextColor(value);
    }
}

void TTKRoundProgressWidgetProperty::updateRender()
{
    TTKRoundProgressWidget *widget = MStatic_cast(TTKRoundProgressWidget*, m_item);
    widget->setText(qrand() % 100 + 1);
}
