#include "ttkpicturebannerwidgetproperty.h"
#include "ttkpicturebannerwidget.h"

TTKPictureBannerWidgetProperty::TTKPictureBannerWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKPictureBannerWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKPictureBannerWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, false);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    //
    for(int i=0; i<5; i++)
    {
        MStatic_cast(TTKPictureBannerWidget*, m_item)->addPage(QPixmap(QString(":/res/%1").arg(i)));
    }
}

TTKPictureBannerWidgetProperty::~TTKPictureBannerWidgetProperty()
{

}
