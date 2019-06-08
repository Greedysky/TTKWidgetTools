#include "ttkpictureflowwidgetproperty.h"
#include "ttkpictureflowwidget.h"

TTKPictureFlowWidgetProperty::TTKPictureFlowWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPictureFlowWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKPictureFlowWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, false);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *slideSizeItem = m_sizeManager->addProperty("SlideSize");
    m_sizeManager->setMinimum(slideSizeItem, QSize(0, 0));
    m_sizeManager->setValue(slideSizeItem, QSize(100, 160));
    objectItem->addSubProperty(slideSizeItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(255, 255, 255));
    objectItem->addSubProperty(backgroundColorItem);
    //
    TTKPictureFlowWidget *widget = MStatic_cast(TTKPictureFlowWidget*, m_item);
    QImage img;
    for(int i=0; i<5; i++)
    {
        widget->addSlide(img);
    }
    //
    QtProperty *codeCountItem = m_intManager->addProperty("CurrentIndex");
    m_intManager->setRange(codeCountItem, 0, widget->slideCount());
    m_intManager->setValue(codeCountItem, widget->slideCount()/2);
    objectItem->addSubProperty(codeCountItem);
    //
    m_browser->addProperty(objectItem);
}

TTKPictureFlowWidgetProperty::~TTKPictureFlowWidgetProperty()
{

}

void TTKPictureFlowWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKPictureFlowWidget *widget = MStatic_cast(TTKPictureFlowWidget*, m_item);
    if(property->propertyName() == "CurrentIndex")
    {
        widget->setCenterIndex(value);
    }
}

void TTKPictureFlowWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    TTKPictureFlowWidget *widget = MStatic_cast(TTKPictureFlowWidget*, m_item);
    if(property->propertyName() == "SlideSize")
    {
        widget->setSlideSize(value);
    }
}

void TTKPictureFlowWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKPictureFlowWidget *widget = MStatic_cast(TTKPictureFlowWidget*, m_item);
    if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
}
