#include "ttkfunctionnavigationwidgetproperty.h"
#include "ttkfunctionnavigationwidget.h"

#include <QBoxLayout>

TTKFunctionNavigationAWidgetProperty::TTKFunctionNavigationAWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i=0; i<5; ++i)
    {
        TTKFunctionNavigationWidget *button = new TTKFunctionNavigationWidget(this);
        button->setText(QString("%1%1%1%1%1").arg(i));

        layout->addWidget(button);
        buttons_ << button;

        connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
    }
    buttons_[0]->setChecked(true);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFunctionNavigationWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 15);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 0, 0));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(0, 255, 0));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(0, 0, 255));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 32);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 6);
    objectItem->addSubProperty(lineSpaceItem);
    //
    m_browser->addProperty(objectItem);
}

TTKFunctionNavigationAWidgetProperty::~TTKFunctionNavigationAWidgetProperty()
{

}

void TTKFunctionNavigationAWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "ShowIcon")
        {
            buttons_[i]->setShowIcon(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSpace")
        {
            buttons_[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            buttons_[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            buttons_[i]->setLineSpace(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSize")
        {
            buttons_[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "NormalIcon")
        {
            buttons_[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            buttons_[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            buttons_[i]->setIconCheck(pixmap);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::buttonClicked()
{
    TTKFunctionNavigationWidget *button = MStatic_cast(TTKFunctionNavigationWidget*, sender());
    for(int i = 0; i < buttons_.count(); i++)
    {
        buttons_[i]->setChecked(buttons_[i] == button);
    }
}



TTKFunctionNavigationBWidgetProperty::TTKFunctionNavigationBWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i=0; i<5; ++i)
    {
        TTKFunctionNavigationWidget *button = new TTKFunctionNavigationWidget(this);
        button->setText(QString("%1%1%1%1%1").arg(i));

        layout->addWidget(button);
        buttons_ << button;

        connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
    }
    buttons_[0]->setChecked(true);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFunctionNavigationWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 10);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 0, 0));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(0, 255, 0));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(0, 0, 255));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 35);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 0);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 8);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(255, 107, 107));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor("#2D9191"));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor("#187294"));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor("#145C75"));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor("#FFFFFF"));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor("#FFFFFF"));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor("#FFFFFF"));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKFunctionNavigationBWidgetProperty::~TTKFunctionNavigationBWidgetProperty()
{

}

void TTKFunctionNavigationBWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "ShowIcon")
        {
            buttons_[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowTriangle")
        {
            buttons_[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSpace")
        {
            buttons_[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            buttons_[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            buttons_[i]->setLineSpace(value);
        }
        else if(property->propertyName() == "LineWidth")
        {
            buttons_[i]->setLineWidth(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSize")
        {
            buttons_[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "NormalIcon")
        {
            buttons_[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverlIcon")
        {
            buttons_[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            buttons_[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "LineColor")
        {
            buttons_[i]->setLineColor(value);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            buttons_[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            buttons_[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            buttons_[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            buttons_[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            buttons_[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            buttons_[i]->setCheckTextColor(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::buttonClicked()
{
    TTKFunctionNavigationWidget *button = MStatic_cast(TTKFunctionNavigationWidget*, sender());
    for(int i = 0; i < buttons_.count(); i++)
    {
        buttons_[i]->setChecked(buttons_[i] == button);
    }
}



TTKFunctionNavigationCWidgetProperty::TTKFunctionNavigationCWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i=0; i<5; ++i)
    {
        TTKFunctionNavigationWidget *button = new TTKFunctionNavigationWidget(this);
        button->setText(QString("%1%1%1%1%1").arg(i));

        layout->addWidget(button);
        buttons_ << button;

        connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
    }
    buttons_[0]->setChecked(true);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKFunctionNavigationWidget*, m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 10);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 0, 0));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(0, 255, 0));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(0, 0, 255));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 35);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 0);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *trianglePositionItem = m_enumManager->addProperty("TrianglePosition");
    QStringList trianglePositionNames;
    trianglePositionNames << "TrianglePositionLeft" << "TrianglePositionRight" << "TrianglePositionTop" << "TrianglePositionBottom";
    m_enumManager->setEnumNames(trianglePositionItem, trianglePositionNames);
    m_enumManager->setValue(trianglePositionItem, TTKFunctionNavigationWidget::TrianglePositionLeft);
    objectItem->addSubProperty(trianglePositionItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKFunctionNavigationWidget::LinePositionRight);
    objectItem->addSubProperty(linePositionItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 0);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 8);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor("#029FEA"));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor("#292F38"));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor("#1D2025"));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor("#1D2025"));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor("#54626F"));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor("#FDFDFD"));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor("#FDFDFD"));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKFunctionNavigationCWidgetProperty::~TTKFunctionNavigationCWidgetProperty()
{

}

void TTKFunctionNavigationCWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "ShowIcon")
        {
            buttons_[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowTriangle")
        {
            buttons_[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSpace")
        {
            buttons_[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            buttons_[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            buttons_[i]->setLineSpace(value);
        }
        else if(property->propertyName() == "LineWidth")
        {
            buttons_[i]->setLineWidth(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "IconSize")
        {
            buttons_[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "TextAlign")
        {
            TTKFunctionNavigationWidget::TextAlign style(TTKFunctionNavigationWidget::TextAlignRight);
            switch(value)
            {
                case 0: style = TTKFunctionNavigationWidget::TextAlignLeft; break;
                case 1: style = TTKFunctionNavigationWidget::TextAlignRight; break;
                case 2: style = TTKFunctionNavigationWidget::TextAlignTop; break;
                case 3: style = TTKFunctionNavigationWidget::TextAlignBottom; break;
                case 4: style = TTKFunctionNavigationWidget::TextAlignCenter; break;
            }
            buttons_[i]->setTextAlign(MStatic_cast(TTKFunctionNavigationWidget::TextAlign, style));
        }
        else if(property->propertyName() == "TrianglePosition")
        {
            buttons_[i]->setTrianglePosition(MStatic_cast(TTKFunctionNavigationWidget::TrianglePosition, value));
        }
        else if(property->propertyName() == "LinePosition")
        {
            buttons_[i]->setLinePosition(MStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < buttons_.count(); i++)
    {
        if(property->propertyName() == "NormalIcon")
        {
            buttons_[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverlIcon")
        {
            buttons_[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            buttons_[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "LineColor")
        {
            buttons_[i]->setLineColor(value);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            buttons_[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            buttons_[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            buttons_[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            buttons_[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            buttons_[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            buttons_[i]->setCheckTextColor(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::buttonClicked()
{
    TTKFunctionNavigationWidget *button = MStatic_cast(TTKFunctionNavigationWidget*, sender());
    for(int i = 0; i < buttons_.count(); i++)
    {
        buttons_[i]->setChecked(buttons_[i] == button);
    }
}
