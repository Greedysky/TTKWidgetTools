#include "ttktoolsapplication.h"
#include "ui_ttktoolsapplication.h"
#include "ttkfunctionitem.h"

//
#include "checkButtonWidget/ttkcheckbuttonwindow.h"
#include "flatButtonWidget/ttkflatbuttonwindow.h"
#include "radioButtonWidget/ttkradiobuttonwindow.h"
#include "toggleWidget/ttktogglewindow.h"
#include "toolMenuWidget/ttktoolmenuwindow.h"
//
#include "circleClickLabel/ttkcircleclicklabelwindow.h"
#include "codeAreaLabel/ttkcodearealabelwindow.h"
#include "marqueeLabel/ttkmarqueelabelwindow.h"
#include "roundAnimationLabel/ttkroundanimationwindow.h"
#include "splitItemLabel/ttksplititemwindow.h"
#include "toastLabel/ttktoastwindow.h"
#include "transitionAnimationLabel/ttktransitionanimationwindow.h"
#include "ledPageLabel/ttkledpagewindow.h"
//
#include "ipEditWidget/ttkipeditwindow.h"
#include "lineEditWidget/ttklineeditwindow.h"
//
#include "paintMeterWidget/ttkpaintmeterwindow.h"
#include "radarMeterWidget/ttkradarmeterwindow.h"
#include "speedMeterWidget/ttkspeedmeterwindow.h"
#include "timeMeterWidget/ttktimemeterwindow.h"
//
#include "animationProgressWidget/ttkanimationprogresswindow.h"
#include "circularProgressWidget/ttkcircularprogresswindow.h"
#include "gifLabelWidget/ttkgiflabelwindow.h"
#include "circleProgressWidget/ttkcircleprogresswindow.h"
#include "progressWidget/ttkprogresswindow.h"
#include "radiusProgressWidget/ttkradiusprogresswindow.h"
#include "ringsMapProgressWidget/ttkringsmapprogresswindow.h"
#include "ringsProgressWidget/ttkringsprogresswindow.h"
#include "roundProgressWidget/ttkroundprogresswindow.h"
#include "loadingWidget/ttkloadingwindow.h"
//
#include "movingLabelSlider/ttkmovinglabelwindow.h"
#include "shiningSlider/ttkshiningsliderwindow.h"
#include "styleSlider/ttkstylesliderwindow.h"
//
#include "functionAnimationHWidget/ttkfunctionanimationhwindow.h"
#include "functionAnimationVWidget/ttkfunctionanimationvwindow.h"
#include "functionListHWidget/ttkfunctionlisthwindow.h"
#include "functionListVWidget/ttkfunctionlistvwindow.h"
#include "functionToolboxWidget/ttkfunctiontoolboxwindow.h"
#include "functionNormalWidget/ttkfunctionnormalwindow.h"
//
#include "animationStackedWidget/ttkanimationstackedwindow.h"
#include "animation2StackedWidget/ttkanimation2stackedwindow.h"
#include "colorTableWidget/ttkcolortablewindow.h"
#include "grabItemWidget/ttkgrabitemwindow.h"
#include "layoutAnimationWidget/ttklayoutanimationwindow.h"
#include "pictureBannerWidget/ttkpicturebannerwindow.h"
#include "pictureFlowWidget/ttkpictureflowwindow.h"
#include "smoothMovingTableWidget/ttksmoothmovingtablewindow.h"
//
#include "colorDialog/ttkcolorwindow.h"
#include "moveDialog/ttkmovedialogwindow.h"
#include "moveResizeWidget/ttkmoveresizewidgetwindow.h"
#include "moveWidget/ttkmovewidgetwindow.h"

#define ITEM_ROW_HEIGHT     40
#include <QButtonGroup>
#include "ttkgrabitemwidget.h"

TTKToolsApplication::TTKToolsApplication(QWidget *parent)
    : TTKMoveResizeWidget(parent),
    ui(new Ui::TTKToolsApplication)
{
    ui->setupUi(this);
    //
    createButtonModule();
    //
    createLabelModule();
    //
    createLineEditModule();
    //
    createMeterModule();
    //
    createProgressModule();
    //
    createSliderModule();
    //
    createTitleModule();
    //
    createWidgetModule();
    //
    createWindowModule();

    TTKGrabItemWidget *ww = new TTKGrabItemWidget(ui->functionContainerWidget);
    ww->setGeometry(QRect(1, 170, 200, 200));
    ww->setStyleSheet("background:red");
}

TTKToolsApplication::~TTKToolsApplication()
{
    delete ui;
}

void TTKToolsApplication::buttonModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKCheckButtonWindow(this))->show();
            break;
        case 1: (new TTKFlatButtonWindow(this))->show();
            break;
        case 2: (new TTKRadioButtonWindow(this))->show();
            break;
        case 3: (new TTKToggleWindow(this))->show();
            break;
        case 4: (new TTKToolMenuWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::labelModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKCircleClickLabelWindow(this))->show();
            break;
        case 1: (new TTKCodeAreaLabelWindow(this))->show();
            break;
        case 2: (new TTKMarqueeLabelWindow(this))->show();
            break;
        case 3: (new TTKRoundAnimationWindow(this))->show();
            break;
        case 4: (new TTKSplitItemWindow(this))->show();
            break;
        case 5: (new TTKToastWindow(this))->show();
            break;
        case 6: (new TTKTransitionAnimationWindow(this))->show();
            break;
        case 7: (new TTKLedPageWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::lineEditModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKIpEditWindow(this))->show();
            break;
        case 1: (new TTKLineEditWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::meterModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKPaintMeterWindow(this))->show();
            break;
        case 1: (new TTKRadarMeterWindow(this))->show();
            break;
        case 2: (new TTKSpeedMeterWindow(this))->show();
            break;
        case 3: (new TTKTimeMeterWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::progressModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKAnimationProgressWindow(this))->show();
            break;
        case 1: (new TTKCircularProgressWindow(this))->show();
            break;
        case 2: (new TTKGifLabelWindow(this))->show();
            break;
        case 3: (new TTKCircleProgressWindow(this))->show();
            break;
        case 4: (new TTKProgressWindow(this))->show();
            break;
        case 5: (new TTKRadiusProgressWindow(this))->show();
            break;
        case 6: (new TTKRingsMapProgressWindow(this))->show();
            break;
        case 7: (new TTKRingsProgressWindow(this))->show();
            break;
        case 8: (new TTKRoundProgressWindow(this))->show();
            break;
        case 9: (new TTKLoadingWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::sliderModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKMovingLabelWindow(this))->show();
            break;
        case 1: (new TTKShiningSliderWindow(this))->show();
            break;
        case 2: (new TTKStyleSliderWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::titleModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKFunctionAnimationHWindow(this))->show();
            break;
        case 1: (new TTKFunctionAnimationVWindow(this))->show();
            break;
        case 2: (new TTKFunctionListHWindow(this))->show();
            break;
        case 3: (new TTKFunctionListVWindow(this))->show();
            break;
        case 4: (new TTKFunctionToolBoxWindow(this))->show();
            break;
        case 5: (new TTKFunctionNormalWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::widgetModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKAnimationStackedWindow(this))->show();
            break;
        case 1: (new TTKAnimation2StackedWindow(this))->show();
            break;
        case 2: (new TTKColorTableWindow(this))->show();
            break;
        case 3: (new TTKGrabItemWindow(this))->show();
            break;
        case 4: (new TTKLayoutAnimationWindow(this))->show();
            break;
        case 5: (new TTKPictureBannerWindow(this))->show();
            break;
        case 6: (new TTKPictureFlowWindow(this))->show();
            break;
        case 7: (new TTKSmoothMovingTableWindow(this))->show();
            break;
        default:
            break;
    }
}


void TTKToolsApplication::windowModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKColorWindow(this))->show();
            break;
        case 1: (new TTKMoveDialogWindow(this))->show();
            break;
        case 2: (new TTKMoveResizeWidgetWindow(this))->show();
            break;
        case 3: (new TTKMoveWidgetWindow(this))->show();
            break;
        default:
            break;
    }
}

void TTKToolsApplication::createButtonModule()
{
    QWidget *widget = new QWidget(ui->functionListWidget);
    widget->setObjectName("buttonRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKCheckButtonWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKFlatButtonWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRadioButtonWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKToggleWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKToolMenuWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#buttonRow{background-color:rgba(255, 0, 0, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Button");
}

void TTKToolsApplication::createLabelModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("labelRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKCircleClickLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKCodeAreaLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKLedPageLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKMarqueeLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRoundAnimationLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKSplitItemLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKToastLabel", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKTransitionAnimationLabel", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#labelRow{background-color:rgba(255, 126, 0, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Label");
}

void TTKToolsApplication::createLineEditModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("lineEidtRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKIpEditWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKLineEditWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#lineEidtRow{background-color:rgba(255, 255, 0, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "LineEdit");
}

void TTKToolsApplication::createMeterModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("meterRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKPaintMeterWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRadarMeterWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKSpeedMeterWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKTimeMeterWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#meterRow{background-color:rgba(0, 255, 0, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Meter");
}

void TTKToolsApplication::createProgressModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("progressRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKAnimationProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKCircleProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKCircularProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKGifLabelWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKLoadingWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRadiusProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRingsMapProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRingsProgressWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKRoundProgressWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#progressRow{background-color:rgba(0, 0, 255, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Progress");
}

void TTKToolsApplication::createSliderModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("sliderRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKMovingLabelSlider", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKShiningSlider", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKStyleSlider", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#sliderRow{background-color:rgba(0, 255, 255, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Silder");
}

void TTKToolsApplication::createTitleModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("titleRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKOptionAnimationHWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKSkinAnimationHWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKTableAnimationHWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKOptionAnimationVWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKSkinAnimationVWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKTableAnimationVWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKFunctionListHWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKFunctionListVWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKFunctionNormalWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKFunctionToolBoxWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#titleRow{background-color:rgba(255, 0, 255, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Title");
}

void TTKToolsApplication::createWidgetModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("widgetRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKAnimationStackedWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKAnimation2StackedWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKColorTableWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKGrabItemWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKLayoutAnimationWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKPictureBannerWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKPictureFlowWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKSmoothMovingTableWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#widgetRow{background-color:rgba(18, 35, 52, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Widget");
}

void TTKToolsApplication::createWindowModule()
{
    QWidget *widget = new QWidget(this);
    widget->setObjectName("windowRow");

    QVBoxLayout *widgetayout = new QVBoxLayout(widget);
    widgetayout->setContentsMargins(0, 0, 0, 0);
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKHlSaturationPalette", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKMoveDialog", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKMoveResizeWidget", widget));
    widgetayout->addWidget(new TTKFunctionItem("red", "TTKMoveWidget", widget));

    widget->setLayout(widgetayout);
    widget->setStyleSheet("#windowRow{background-color:rgba(255, 255, 255, 50)}");
    widget->setFixedHeight(widgetayout->count() * ITEM_ROW_HEIGHT);
    ui->functionListWidget->addItem(widget, "Window");
}
