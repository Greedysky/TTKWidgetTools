#include "ttkheatmaplabelproperty.h"
#include "ttkheatmaplabel.h"

TTKHeatMapLabelProperty::TTKHeatMapLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKHeatMapLabel(this);
    TTKHeatMapLabel *widget = TTKStatic_cast(TTKHeatMapLabel*, m_item);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, widget->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *widthItem = m_intManager->addProperty("Radius");
    m_intManager->setMinimum(widthItem, 0);
    m_intManager->setValue(widthItem, 50);
    objectItem->addSubProperty(widthItem);
    //
    QtProperty *opacityItem = m_intManager->addProperty("Opacity");
    m_intManager->setRange(opacityItem, 0, 255);
    m_intManager->setValue(opacityItem, 128);
    objectItem->addSubProperty(opacityItem);
    //
    QtProperty *colorSchemeItem = m_enumManager->addProperty("ColorScheme");
    QStringList enumNames;
    enumNames << "Default";
    enumNames << "YlOrRd_discrete" << "YlOrRd_soft" << "YlOrRd_mixed" << "YlOrRd_mixed_exp";
    enumNames << "YlOrBr_discrete" << "YlOrBr_soft" << "YlOrBr_mixed" << "YlOrBr_mixed_exp";
    enumNames << "YlGnBu_discrete" << "YlGnBu_soft" << "YlGnBu_mixed" << "YlGnBu_mixed_exp";
    enumNames << "YlGn_discrete" << "YlGn_soft" << "YlGn_mixed" << "YlGn_mixed_exp";
    enumNames << "Spectral_discrete" << "Spectral_soft" << "Spectral_mixed" << "Spectral_mixed_exp";
    enumNames << "Reds_discrete" << "Reds_soft" << "Reds_mixed" << "Reds_mixed_exp";
    enumNames << "RdYlGn_discrete" << "RdYlGn_soft" << "RdYlGn_mixed" << "RdYlGn_mixed_exp";
    enumNames << "RdYlBu_discrete" << "RdYlBu_soft" << "RdYlBu_mixed" << "RdYlBu_mixed_exp";
    enumNames << "RdPu_discrete" << "RdPu_soft" << "RdPu_mixed" << "RdPu_mixed_exp";
    enumNames << "RdGy_discrete" << "RdGy_soft" << "RdGy_mixed" << "RdGy_mixed_exp";
    enumNames << "RdBu_discrete" << "RdBu_softRdBu_soft" << "RdBu_mixed" << "RdBu_mixed_exp";
    enumNames << "Purples_discrete" << "Purples_soft" << "Purples_mixed" << "Purples_mixed_exp";
    enumNames << "PuRd_discrete" << "PuRd_soft" << "PuRd_mixed" << "PuRd_mixed_exp";
    enumNames << "PuOr_discrete" << "PuOr_soft" << "PuOr_mixed" << "PuOr_mixed_exp";
    enumNames << "PuBuGn_discrete" << "PuBuGn_soft" << "PuBuGn_mixed" << "PuBuGn_mixed_exp";
    enumNames << "PuBu_discrete" << "PuBu_soft" << "PuBu_mixed" << "PuBu_mixed_exp";
    enumNames << "PRGn_discrete" << "PRGn_soft" << "PRGn_mixed" << "PRGn_mixed_exp";
    enumNames << "PiYG_discrete" << "PiYG_soft" << "PiYG_mixed" << "PiYG_mixed_exp";
    enumNames << "OrRd_discrete" << "OrRd_soft" << "OrRd_mixed" << "OrRd_mixed_exp";
    enumNames << "Oranges_discrete" << "Oranges_soft" << "Oranges_mixed" << "Oranges_mixed_exp";
    enumNames << "Greys_discrete" << "Greys_soft" << "Greys_mixed" << "Greys_mixed_exp";
    enumNames << "Greens_discrete" << "Greens_soft" << "Greens_mixed" << "Greens_mixed_exp";
    enumNames << "b2w" << "b2w_opaque" << "w2b" << "w2b_opaque";
    enumNames << "GnBu_discrete" << "GnBu_soft" << "GnBu_mixed" << "GnBu_mixed_exp";
    enumNames << "BuPu_discrete" << "BuPu_soft" << "BuPu_mixed" << "BuPu_mixed_exp";
    enumNames << "BuGn_discrete" << "BuGn_soft" << "BuGn_mixed" << "BuGn_mixed_exp";
    enumNames << "BrBG_discrete" << "BrBG_soft" << "BrBG_mixed" << "BrBG_mixed_exp";
    enumNames << "Blues_discrete" << "Blues_soft" << "Blues_mixed" << "Blues_mixed_exp";
    m_enumManager->setEnumNames(colorSchemeItem, enumNames);
    m_enumManager->setValue(colorSchemeItem, HeatMapper::Default);
    objectItem->addSubProperty(colorSchemeItem);
    //
    m_browser->addProperty(objectItem);
    //
    for(int i = 0; i < 10; ++i)
    {
        widget->addPoint(90 + i * i, 90 + i * i);
    }
    widget->renderImage();
}

void TTKHeatMapLabelProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKHeatMapLabel *widget = TTKStatic_cast(TTKHeatMapLabel*, m_item);
    if(property->propertyName() == "Radius")
    {
        widget->setRadius(value);
    }
    else if(property->propertyName() == "Opacity")
    {
        widget->setOpacity(value);
    }

    for(int i = 0; i < 10; ++i)
    {
        widget->addPoint(90 + i * i, 90 + i * i);
    }
    widget->renderImage();
}

void TTKHeatMapLabelProperty::enumPropertyChanged(QtProperty *property, int value)
{
    TTKHeatMapLabel *widget = TTKStatic_cast(TTKHeatMapLabel*, m_item);
    if(property->propertyName() == "ColorScheme")
    {
        widget->setColorScheme(TTKStatic_cast(HeatMapper::ColorScheme, value));
    }
}
