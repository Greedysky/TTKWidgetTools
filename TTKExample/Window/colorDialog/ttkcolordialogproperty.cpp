#include "ttkcolordialogproperty.h"
#include "ttkcolordialog.h"

#include <QBoxLayout>

TTKColorDialogProperty::TTKColorDialogProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    TTKHlPalette *palette = new TTKHlPalette(m_item);
    TTKHlSaturationPalette *saturation = new TTKHlSaturationPalette(m_item);
    layout->addWidget(palette);
    layout->addWidget(saturation);

    connect(palette, SIGNAL(colorChanged(QColor)), saturation, SLOT(setBaseColor(QColor)));
    connect(saturation, SIGNAL(saturationChanged(double)),palette, SLOT(setSaturation(double)));
    palette->initialize();
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, "TTKColorDialog");
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}
