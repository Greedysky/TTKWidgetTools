#include "ttkcustompiewidgetproperty.h"
#include "ttkcustompiewidget.h"

TTKCustomPieWidgetProperty::TTKCustomPieWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKCustomPieWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKCustomPieWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *explodedAllItem = m_boolManager->addProperty("ExplodedAll");
    m_boolManager->setValue(explodedAllItem, true);
    objectItem->addSubProperty(explodedAllItem);
    //
    QtProperty *explodedIndexItem = m_intManager->addProperty("ExplodedIndex");
    m_intManager->setValue(explodedIndexItem, 0);
    m_intManager->setMinimum(explodedIndexItem, 0);
    objectItem->addSubProperty(explodedIndexItem);
    //
    QtProperty *textColorItem = m_colorManager->addProperty("TextColor");
    m_colorManager->setValue(textColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(textColorItem);
    //
    QtProperty *borderColorItem = m_colorManager->addProperty("BorderColor");
    m_colorManager->setValue(borderColorItem, QColor(0, 0, 0));
    objectItem->addSubProperty(borderColorItem);
    //
    m_browser->addProperty(objectItem);
    //
    TTKCustomPieWidget *w = MStatic_cast(TTKCustomPieWidget*, m_item);
    w->appendPie("111", 10, Qt::blue);
    w->appendPie("222", 10, Qt::red);
    w->appendPie("333", 10, Qt::yellow);
    w->appendPie("444", 10, Qt::black);
}

TTKCustomPieWidgetProperty::~TTKCustomPieWidgetProperty()
{

}

void TTKCustomPieWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    TTKCustomPieWidget *widget = MStatic_cast(TTKCustomPieWidget*, m_item);
    if(property->propertyName() == "ExplodedAll")
    {
        widget->setExplodedAll(value);
    }
}

void TTKCustomPieWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKCustomPieWidget *widget = MStatic_cast(TTKCustomPieWidget*, m_item);
    if(property->propertyName() == "ExplodedIndex")
    {
        widget->setExplodedIndex(value);
    }
}

void TTKCustomPieWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKCustomPieWidget *widget = MStatic_cast(TTKCustomPieWidget*, m_item);
    if(property->propertyName() == "TextColor")
    {
        widget->setTextColor(value);
    }
    else if(property->propertyName() == "BorderColor")
    {
        widget->setBorderColor(value);
    }
}
