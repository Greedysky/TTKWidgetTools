#include "ttktoolsapplication.h"
#include "ui_ttktoolsapplication.h"
#include "ttkfunctionitem.h"
//
#include "ttkbuttoninclude.h"
#include "ttklabelinclude.h"
#include "ttklineeditinclude.h"
#include "ttkmeterinclude.h"
#include "ttkprogressinclude.h"
#include "ttksliderinclude.h"
#include "ttktitleinclude.h"
#include "ttkwidgetinclude.h"
#include "ttkwindowinclude.h"

const QString MBtnMinimum = " \
        QToolButton{ border:none; \
        background-image: url(:/image/btn_min_normal);} \
        QToolButton:hover{ background-image: url(:/image/btn_min_hover);}";

const QString MBtnTClose = " \
        QToolButton{ border:none; \
        background-image: url(:/image/btn_close_hover);} \
        QToolButton:hover{ background-image: url(:/image/btn_close_hover);}";


TTKToolsApplication::TTKToolsApplication(QWidget *parent)
    : TTKMoveResizeWidget(parent),
    ui(new Ui::TTKToolsApplication)
{
    ui->setupUi(this);

    //
    createButtonModule();
    createLabelModule();
    createLineEditModule();
    createMeterModule();
    createProgressModule();
    createSliderModule();
    createTitleModule();
    createWidgetModule();
    createWindowModule();
    //
    ui->background->installEventFilter(this);
    ui->background->setMouseTracking(true);

    ui->minimization->setStyleSheet(MBtnMinimum);
    ui->minimization->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->minimization, SIGNAL(clicked()), SLOT(showMinimized()));

    ui->windowClose->setStyleSheet(MBtnTClose);
    ui->windowClose->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->windowClose, SIGNAL(clicked()), SLOT(close()));
}

TTKToolsApplication::~TTKToolsApplication()
{
    delete ui;
}

void TTKToolsApplication::buttonModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKFlatButtonWidgetProperty;
            break;
        case 1: w = new TTKToolMenuWidgetProperty;
            break;
        case 2: w = new TTKColorButtonWidgetProperty;
            break;
#if !TTK_QT_VERSION_CHECK(6,0,0) || TTK_QT_VERSION_CHECK(6,1,0)
        case 3: w = new TTKCheckButtonWidgetProperty;
            break;
        case 4: w = new TTKRadioButtonWidgetProperty;
            break;
        case 5: w = new TTKToggleWidgetProperty;
            break;
#endif
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::labelModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKCircleClickLabelProperty;
            break;
        case 1: w = new TTKCodeAreaLabelProperty;
            break;
        case 2: w = new TTKLedPageLabelProperty;
            break;
        case 3: w = new TTKMarqueeLabelProperty;
            break;
        case 4: w = new TTKRoundAnimationLabelProperty;
            break;
        case 5: w = new TTKSplitItemLabelProperty;
            break;
        case 6: w = new TTKToastLabelProperty;
            break;
        case 7: w = new TTKTransitionAnimationLabelProperty;
            break;
        case 8: w = new TTKBarRulerLabelProperty;
            break;
        case 9: w = new TTKBatteryLabelProperty;
            break;
        case 10: w = new TTKCloudPanelLabelProperty;
            break;
        case 11: w = new TTKCPUMemoryLabelProperty;
            break;
        case 12: w = new TTKAntLineLabelProperty;
            break;
        case 13: w = new TTKTileBackgroundLabelProperty;
            break;
        case 14: w = new TTKLightPointLabelProperty;
            break;
        case 15: w = new TTKScanLabelProperty;
            break;
        case 16: w = new TTKCrossLineLabelProperty;
            break;
        case 17: w = new TTKNetTrafficLabelProperty;
            break;
        case 18: w = new TTKHeatMapLabelProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::lineEditModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKIpEditWidgetProperty;
            break;
        case 1: w = new TTKLineEditWidgetProperty;
            break;
        default:
            break;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::meterModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKPaintMeterWidgetProperty;
            break;
        case 1: w = new TTKRadarMeterWidgetProperty;
            break;
        case 2: w = new TTKSpeedMeterWidgetProperty;
            break;
        case 3: w = new TTKTimeMeterWidgetProperty;
            break;
        case 4: w = new TTKCarMeterWidgetProperty;
            break;
        case 5: w = new TTKSpeedRingMeterWidgetProperty;
            break;
        case 6: w = new TTKDialMeterWidgetProperty;
            break;
        case 7: w = new TTKCompassMeterWidgetProperty;
            break;
        case 8: w = new TTKProgressMeterWidgetProperty;
            break;
        case 9: w = new TTKPercentMeterWidgetProperty;
            break;
        case 10: w = new TTKArcMeterWidgetProperty;
            break;
        case 11: w = new TTKPanelMeterWidgetProperty;
            break;
        case 12: w = new TTKMiniMeterWidgetProperty;
            break;
        case 13: w = new TTKRoundMeterWidgetProperty;
            break;
        case 14: w = new TTKClockMeterWidgetProperty;
            break;
        case 15: w = new TTKTemperatureMeterWidgetProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::progressModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKAnimationProgressWidgetProperty;
            break;
        case 1: w = new TTKCircleProgressWidgetProperty;
            break;
        case 2: w = new TTKCircularProgressWidgetProperty;
            break;
        case 3: w = new TTKGifProgressWidgetProperty;
            break;
        case 4: w = new TTKLoadingProgressWidgetProperty;
            break;
        case 5: w = new TTKProgressWidgetProperty;
            break;
        case 6: w = new TTKRadiusProgressWidgetProperty;
            break;
        case 7: w = new TTKRingsMapProgressWidgetProperty;
            break;
        case 8: w = new TTKRingsProgressWidgetProperty;
            break;
        case 9: w = new TTKRoundProgressWidgetProperty;
            break;
        case 10: w = new TTKRingProgressWidgetProperty;
            break;
        case 11: w = new TTKWaveProgressWidgetProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::sliderModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKMovingLabelSliderProperty;
            break;
        case 1: w = new TTKShiningSliderProperty;
            break;
        case 2: w = new TTKStyleSliderProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::titleModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKOptionAnimationHWidgetProperty;
            break;
        case 1: w = new TTKSkinAnimationHWidgetProperty;
            break;
        case 2: w = new TTKTableAnimationHWidgetProperty;
            break;
        case 3: w = new TTKOptionAnimationVWidgetProperty;
            break;
        case 4: w = new TTKSkinAnimationVWidgetProperty;
            break;
        case 5: w = new TTKTableAnimationVWidgetProperty;
            break;
        case 6: w = new TTKFunctionListHWidgetProperty;
            break;
        case 7: w = new TTKFunctionListVWidgetProperty;
            break;
        case 8: w = new TTKFunctionNormaWidgetProperty;
            break;
        case 9: w = new TTKFunctionToolBoxWidgetProperty;
            break;
        case 10: w = new TTKFunctionNavigationAWidgetProperty;
            break;
        case 11: w = new TTKFunctionNavigationBWidgetProperty;
            break;
        case 12: w = new TTKFunctionNavigationCWidgetProperty;
            break;
        case 13: w = new TTKFunctionNavigationDWidgetProperty;
            break;
        case 14: w = new TTKFunctionNavigationEWidgetProperty;
            break;
        case 15: w = new TTKFunctionNavigationFWidgetProperty;
            break;
        case 16: w = new TTKFunctionNavigationGWidgetProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::widgetModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKAnimationStackedWidgetProperty;
            break;
        case 1: w = new TTKAnimation2StackedWidgetProperty;
            break;
        case 2: w = new TTKColorTableWidgetProperty;
            break;
        case 3: w = new TTKGrabItemWidgetProperty;
            break;
        case 4: w = new TTKLayoutAnimationWidgetProperty;
            break;
        case 5: w = new TTKPictureBannerWidgetProperty;
            break;
        case 6: w = new TTKPictureFlowWidgetProperty;
            break;
        case 7: w = new TTKSmoothMovingTableWidgetProperty;
            break;
        case 8: w = new TTKCustomPieWidgetProperty;
            break;
        case 9: w = new TTKCustomRingWidgetProperty;
            break;
        case 10: w = new TTKCalendarWidgetProperty;
            break;
        case 11: w = new TTKPuzzleWidgetProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::windowModuleChanged(int index)
{
    TTKWidgetProperty *w = nullptr;
    switch(index)
    {
        case 0: w = new TTKColorDialogProperty;
            break;
        case 1: w = new TTKMoveDialogProperty;
            break;
        case 2: w = new TTKMoveResizeWidgetProperty;
            break;
        case 3: w = new TTKMoveWidgetProperty;
            break;
        case 4: w = new TTKSplashScreenProperty;
            break;
        case 5: w = new TTKAnSplashScreenProperty;
            break;
        case 6: w = new TTKNotifyWindowProperty;
            break;
        default:
            break;
    }

    if(!w)
    {
        return;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->initialize();
}

void TTKToolsApplication::createButtonModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/button", "TTKFlatButtonWidget");
    widget->addItem(":/icon/button", "TTKToolMenuWidget");
    widget->addItem(":/icon/button", "TTKColorButtonWidget");
#if !TTK_QT_VERSION_CHECK(6,0,0) || TTK_QT_VERSION_CHECK(6,1,0)
    widget->addItem(":/icon/button", "TTKCheckButtonWidget");
    widget->addItem(":/icon/button", "TTKRadioButtonWidget");
    widget->addItem(":/icon/button", "TTKToggleWidget");
#endif

    widget->setObjectName("buttonRow");
    widget->setStyleSheet("#buttonRow{background-color:rgba(255, 0, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(buttonModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Button");
}

void TTKToolsApplication::createLabelModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/label", "TTKCircleClickLabel");
    widget->addItem(":/icon/label", "TTKCodeAreaLabel");
    widget->addItem(":/icon/label", "TTKLedPageLabel");
    widget->addItem(":/icon/label", "TTKMarqueeLabel");
    widget->addItem(":/icon/label", "TTKRoundAnimationLabel");
    widget->addItem(":/icon/label", "TTKSplitItemLabel");
    widget->addItem(":/icon/label", "TTKToastLabel");
    widget->addItem(":/icon/label", "TTKTransitionAnimationLabel");
    widget->addItem(":/icon/label", "TTKBarRulerLabel");
    widget->addItem(":/icon/label", "TTKBatteryLabel");
    widget->addItem(":/icon/label", "TTKCloudPanelLabel");
    widget->addItem(":/icon/label", "TTKCPUMemoryLabel");
    widget->addItem(":/icon/label", "TTKAntLineLabel");
    widget->addItem(":/icon/label", "TTKTileBackgroundLabel");
    widget->addItem(":/icon/label", "TTKLightPointLabel");
    widget->addItem(":/icon/label", "TTKScanLabel");
    widget->addItem(":/icon/label", "TTKCrossLineLabel");
    widget->addItem(":/icon/label", "TTKNetTrafficLabel");
    widget->addItem(":/icon/label", "TTKHeatMapLabelProperty");

    widget->setObjectName("labelRow");
    widget->setStyleSheet("#labelRow{background-color:rgba(255, 126, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(labelModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Label");
}

void TTKToolsApplication::createLineEditModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/lineedit", "TTKIpEditWidget");
    widget->addItem(":/icon/lineedit", "TTKLineEditWidget");

    widget->setObjectName("lineEidtRow");
    widget->setStyleSheet("#lineEidtRow{background-color:rgba(255, 255, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(lineEditModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "LineEdit");
}

void TTKToolsApplication::createMeterModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/meter", "TTKPaintMeterWidget");
    widget->addItem(":/icon/meter", "TTKRadarMeterWidget");
    widget->addItem(":/icon/meter", "TTKSpeedMeterWidget");
    widget->addItem(":/icon/meter", "TTKTimeMeterWidget");
    widget->addItem(":/icon/meter", "TTKCarMeterWidget");
    widget->addItem(":/icon/meter", "TTKSpeedRingMeterWidget");
    widget->addItem(":/icon/meter", "TTKDialMeterWidge");
    widget->addItem(":/icon/meter", "TTKCompassMeterWidget");
    widget->addItem(":/icon/meter", "TTKProgressMeterWidget");
    widget->addItem(":/icon/meter", "TTKPercentMeterWidget");
    widget->addItem(":/icon/meter", "TTKArcMeterWidget");
    widget->addItem(":/icon/meter", "TTKPanelMeterWidget");
    widget->addItem(":/icon/meter", "TTKMiniMeterWidget");
    widget->addItem(":/icon/meter", "TTKRoundMeterWidget");
    widget->addItem(":/icon/meter", "TTKClockMeterWidget");
    widget->addItem(":/icon/meter", "TTKTemperatureMeterWidget");

    widget->setObjectName("meterRow");
    widget->setStyleSheet("#meterRow{background-color:rgba(0, 255, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(meterModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Meter");
}

void TTKToolsApplication::createProgressModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/progress", "TTKAnimationProgressWidget");
    widget->addItem(":/icon/progress", "TTKCircleProgressWidget");
    widget->addItem(":/icon/progress", "TTKCircularProgressWidget");
    widget->addItem(":/icon/progress", "TTKGifProgressWidget");
    widget->addItem(":/icon/progress", "TTKLoadingProgressWidget");
    widget->addItem(":/icon/progress", "TTKProgressWidget");
    widget->addItem(":/icon/progress", "TTKRadiusProgressWidget");
    widget->addItem(":/icon/progress", "TTKRingsMapProgressWidget");
    widget->addItem(":/icon/progress", "TTKRingsProgressWidget");
    widget->addItem(":/icon/progress", "TTKRoundProgressWidget");
    widget->addItem(":/icon/progress", "TTKRingProgressWidget");
    widget->addItem(":/icon/progress", "TTKWaveProgressWidget");

    widget->setObjectName("progressRow");
    widget->setStyleSheet("#progressRow{background-color:rgba(0, 0, 255, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(progressModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Progress");
}

void TTKToolsApplication::createSliderModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/slider", "TTKMovingLabelSlider");
    widget->addItem(":/icon/slider", "TTKShiningSlider");
    widget->addItem(":/icon/slider", "TTKStyleSlider");

    widget->setObjectName("sliderRow");
    widget->setStyleSheet("#sliderRow{background-color:rgba(0, 255, 255, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(sliderModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Silder");
}

void TTKToolsApplication::createTitleModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/title", "TTKOptionAnimationHWidget");
    widget->addItem(":/icon/title", "TTKSkinAnimationHWidget");
    widget->addItem(":/icon/title", "TTKTableAnimationHWidget");
    widget->addItem(":/icon/title", "TTKOptionAnimationVWidget");
    widget->addItem(":/icon/title", "TTKSkinAnimationVWidget");
    widget->addItem(":/icon/title", "TTKTableAnimationVWidget");
    widget->addItem(":/icon/title", "TTKFunctionListHWidget");
    widget->addItem(":/icon/title", "TTKFunctionListVWidget");
    widget->addItem(":/icon/title", "TTKFunctionNormalWidget");
    widget->addItem(":/icon/title", "TTKFunctionToolBoxWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationAWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationBWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationCWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationDWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationEWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationFWidget");
    widget->addItem(":/icon/title", "TTKFunctionNavigationGWidget");

    widget->setObjectName("titleRow");
    widget->setStyleSheet("#titleRow{background-color:rgba(255, 0, 255, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(titleModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Title");
}

void TTKToolsApplication::createWidgetModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/widget", "TTKAnimationStackedWidget");
    widget->addItem(":/icon/widget", "TTKAnimation2StackedWidget");
    widget->addItem(":/icon/widget", "TTKColorTableWidget");
    widget->addItem(":/icon/widget", "TTKGrabItemWidget");
    widget->addItem(":/icon/widget", "TTKLayoutAnimationWidget");
    widget->addItem(":/icon/widget", "TTKPictureBannerWidget");
    widget->addItem(":/icon/widget", "TTKPictureFlowWidget");
    widget->addItem(":/icon/widget", "TTKSmoothMovingTableWidget");
    widget->addItem(":/icon/widget", "TTKCustomPieWidget");
    widget->addItem(":/icon/widget", "TTKCustomRingWidget");
    widget->addItem(":/icon/widget", "TTKCalendarWidget");
    widget->addItem(":/icon/widget", "TTKPuzzleWidget");

    widget->setObjectName("widgetRow");
    widget->setStyleSheet("#widgetRow{background-color:rgba(18, 35, 52, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(widgetModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Widget");
}

void TTKToolsApplication::createWindowModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem(":/icon/window", "TTKHlSaturationPalette");
    widget->addItem(":/icon/window", "TTKMoveDialog");
    widget->addItem(":/icon/window", "TTKMoveResizeWidget");
    widget->addItem(":/icon/window", "TTKMoveWidget");
    widget->addItem(":/icon/window", "TTKSplashScreen");
    widget->addItem(":/icon/window", "TTKAnSplashScreen");
    widget->addItem(":/icon/window", "TTKNotifyWindow");

    widget->setObjectName("windowRow");
    widget->setStyleSheet("#windowRow{background-color:rgba(255, 255, 255, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(windowModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Window");
}
