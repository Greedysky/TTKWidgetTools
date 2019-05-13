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
#include "ttksliderinclude.h"
#include "ttktitleinclude.h"
#include "ttkwidgetinclude.h"
#include "ttkwindowinclude.h"

#include <QButtonGroup>

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
        case 0: w = new TTKCheckButtonWidgetProperty;
            break;
        case 1: w = new TTKFlatButtonWidgetProperty;
            break;
        case 2: w = new TTKRadioButtonWidgetProperty;
            break;
        case 3: w = new TTKToggleWidgetProperty;
            break;
        case 4: w = new TTKToolMenuWidgetProperty;
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
    w->init();
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
        default:
            break;
    }

    ui->propertyWidget->addItem(w);
    ui->containerWidget->addItem(w->widget());
    w->init();
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
    w->init();
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
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKCheckButtonWidget");
    widget->addItem("red", "TTKFlatButtonWidget");
    widget->addItem("red", "TTKRadioButtonWidget");
    widget->addItem("red", "TTKToggleWidget");
    widget->addItem("red", "TTKToolMenuWidget");

    widget->setObjectName("buttonRow");
    widget->setStyleSheet("#buttonRow{background-color:rgba(255, 0, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(buttonModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Button");
}

void TTKToolsApplication::createLabelModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKCircleClickLabel");
    widget->addItem("red", "TTKCodeAreaLabel");
    widget->addItem("red", "TTKLedPageLabel");
    widget->addItem("red", "TTKMarqueeLabel");
    widget->addItem("red", "TTKRoundAnimationLabel");
    widget->addItem("red", "TTKSplitItemLabel");
    widget->addItem("red", "TTKToastLabel");
    widget->addItem("red", "TTKTransitionAnimationLabel");

    widget->setObjectName("labelRow");
    widget->setStyleSheet("#labelRow{background-color:rgba(255, 126, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(labelModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "Label");
}

void TTKToolsApplication::createLineEditModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKIpEditWidget");
    widget->addItem("red", "TTKLineEditWidget");

    widget->setObjectName("lineEidtRow");
    widget->setStyleSheet("#lineEidtRow{background-color:rgba(255, 255, 0, 50)}");

    connect(widget, SIGNAL(rowClicked(int)), SLOT(lineEditModuleChanged(int)));
    ui->functionListWidget->addItem(widget, "LineEdit");
}

void TTKToolsApplication::createMeterModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKPaintMeterWidget");
    widget->addItem("red", "TTKRadarMeterWidget");
    widget->addItem("red", "TTKSpeedMeterWidget");
    widget->addItem("red", "TTKTimeMeterWidget");

    widget->setObjectName("meterRow");
    widget->setStyleSheet("#meterRow{background-color:rgba(0, 255, 0, 50)}");
    ui->functionListWidget->addItem(widget, "Meter");
}

void TTKToolsApplication::createProgressModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKAnimationProgressWidget");
    widget->addItem("red", "TTKCircleProgressWidget");
    widget->addItem("red", "TTKCircularProgressWidget");
    widget->addItem("red", "TTKGifLabelWidget");
    widget->addItem("red", "TTKLoadingWidget");
    widget->addItem("red", "TTKProgressWidget");
    widget->addItem("red", "TTKRadiusProgressWidget");
    widget->addItem("red", "TTKRingsMapProgressWidget");
    widget->addItem("red", "TTKRingsProgressWidget");
    widget->addItem("red", "TTKRoundProgressWidget");

    widget->setObjectName("progressRow");
    widget->setStyleSheet("#progressRow{background-color:rgba(0, 0, 255, 50)}");
    ui->functionListWidget->addItem(widget, "Progress");
}

void TTKToolsApplication::createSliderModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKMovingLabelSlider");
    widget->addItem("red", "TTKShiningSlider");
    widget->addItem("red", "TTKStyleSlider");

    widget->setObjectName("sliderRow");
    widget->setStyleSheet("#sliderRow{background-color:rgba(0, 255, 255, 50)}");
    ui->functionListWidget->addItem(widget, "Silder");
}

void TTKToolsApplication::createTitleModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKOptionAnimationHWidget");
    widget->addItem("red", "TTKSkinAnimationHWidget");
    widget->addItem("red", "TTKTableAnimationHWidget");
    widget->addItem("red", "TTKOptionAnimationVWidget");
    widget->addItem("red", "TTKSkinAnimationVWidget");
    widget->addItem("red", "TTKTableAnimationVWidget");
    widget->addItem("red", "TTKFunctionListHWidget");
    widget->addItem("red", "TTKFunctionListVWidget");
    widget->addItem("red", "TTKFunctionNormalWidget");
    widget->addItem("red", "TTKFunctionToolBoxWidget");

    widget->setObjectName("titleRow");
    widget->setStyleSheet("#titleRow{background-color:rgba(255, 0, 255, 50)}");
    ui->functionListWidget->addItem(widget, "Title");
}

void TTKToolsApplication::createWidgetModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKAnimationStackedWidget");
    widget->addItem("red", "TTKAnimation2StackedWidget");
    widget->addItem("red", "TTKColorTableWidget");
    widget->addItem("red", "TTKGrabItemWidget");
    widget->addItem("red", "TTKLayoutAnimationWidget");
    widget->addItem("red", "TTKPictureBannerWidget");
    widget->addItem("red", "TTKPictureFlowWidget");
    widget->addItem("red", "TTKSmoothMovingTableWidget");

    widget->setObjectName("widgetRow");
    widget->setStyleSheet("#widgetRow{background-color:rgba(18, 35, 52, 50)}");
    ui->functionListWidget->addItem(widget, "Widget");
}

void TTKToolsApplication::createWindowModule()
{
    TTKFunctionItemRow *widget = new TTKFunctionItemRow(ui->functionListWidget);

    widget->addItem("red", "TTKHlSaturationPalette");
    widget->addItem("red", "TTKMoveDialog");
    widget->addItem("red", "TTKMoveResizeWidget");
    widget->addItem("red", "TTKMoveWidget");

    widget->setObjectName("windowRow");
    widget->setStyleSheet("#windowRow{background-color:rgba(255, 255, 255, 50)}");
    ui->functionListWidget->addItem(widget, "Window");
}
