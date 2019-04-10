#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "animationStackedWidget/ttkanimationstackedwindow.h"
#include "animation2StackedWidget/ttkanimation2stackedwindow.h"
#include "transitionAnimationLabel/ttktransitionanimationwindow.h"
#include "gifLabelWidget/ttkgiflabelwindow.h"
#include "codeAreaWidget/ttkcodeareawindow.h"
#include "toastLabel/ttktoastwindow.h"
#include "marqueeWidget/ttkmarqueewindow.h"
#include "roundAnimationLabel/ttkroundanimationwindow.h"
#include "movingLabelSlider/ttkmovinglabelwindow.h"
#include "smoothMovingTableWidget/ttksmoothmovingtablewindow.h"
#include "colorDialog/ttkcolorwindow.h"
#include "layoutAnimationWidget/ttklayoutanimationwindow.h"
#include "shiningSlider/ttkshiningsliderwindow.h"
#include "splitItemLabel/ttksplititemwindow.h"
#include "grabItemWidget/ttkgrabitemwindow.h"
#include "functionAnimationHWidget/ttkfunctionanimationhwindow.h"
#include "functionAnimationVWidget/ttkfunctionanimationvwindow.h"
#include "toolMenuWidget/ttktoolmenuwindow.h"
#include "moveDialog/ttkmovedialogwindow.h"
#include "moveWidget/ttkmovewidgetwindow.h"
#include "moveResizeWidget/ttkmoveresizewidgetwindow.h"
#include "circleClickPlane/ttkcircleclickplanewindow.h"
#include "lineEditWidget/ttklineeditwindow.h"
#include "toggleWidget/ttktogglewindow.h"
#include "radioButtonWidget/ttkradiobuttonwindow.h"
#include "checkButtonWidget/ttkcheckbuttonwindow.h"
#include "progressWidget/ttkprogresswindow.h"
#include "flatButtonWidget/ttkflatbuttonwindow.h"
#include "circularProgressWidget/ttkcircularprogresswindow.h"
#include "sliderWidget/ttksliderwindow.h"
#include "colorTablePlane/ttkcolortableplanewindow.h"
#include "functionListHWidget/ttkfunctionlisthwindow.h"
#include "functionListVWidget/ttkfunctionlistvwindow.h"
#include "functionToolboxWidget/ttkfunctiontoolboxwindow.h"
#include "pictureFlowWidget/ttkpictureflowwindow.h"
#include "pictureBannerWidget/ttkpicturebannerwindow.h"
#include "speedMeterWidget/ttkspeedmeterwindow.h"
#include "timeMeterWidget/ttktimemeterwindow.h"
#include "paintMeterWidget/ttkpaintmeterwindow.h"
#include "radarMeterWidget/ttkradarmeterwindow.h"
#include "progressCircleWidget/ttkprogresscirclewindow.h"
#include "animationProgressWidget/ttkanimationprogresswindow.h"
#include "radiusProgressWidget/ttkradiusprogresswindow.h"
#include "ringsMapProgressWidget/ttkringsmapprogresswindow.h"
#include "ringsProgressWidget/ttkringsprogresswindow.h"
#include "roundProgressWidget/ttkroundprogresswindow.h"

#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    QButtonGroup *listGroup = new QButtonGroup(this);
    listGroup->addButton(ui->ButtonType, 0);
    listGroup->addButton(ui->LabelType, 1);
    listGroup->addButton(ui->MeterType, 2);
    listGroup->addButton(ui->ProgressType, 3);
    listGroup->addButton(ui->SliderType, 4);
    listGroup->addButton(ui->TitleType, 5);
    listGroup->addButton(ui->WidgetType, 6);
    listGroup->addButton(ui->WindowType, 7);
    connect(listGroup, SIGNAL(buttonClicked(int)), ui->containerWidget, SLOT(setCurrentIndex(int)));
    //
    QButtonGroup *buttonsGroup = new QButtonGroup(this);
    buttonsGroup->addButton(ui->checkButtonWidget, 0);
    buttonsGroup->addButton(ui->flatButtonWidget, 1);
    buttonsGroup->addButton(ui->radioButtonWidget, 2);
    buttonsGroup->addButton(ui->toggleWidget, 3);
    buttonsGroup->addButton(ui->toolMenuWidget, 4);
    connect(buttonsGroup, SIGNAL(buttonClicked(int)), SLOT(buttonModuleChanged(int)));
    //
    QButtonGroup *labelsGroup = new QButtonGroup(this);
    labelsGroup->addButton(ui->circleClickPlane, 0);
    labelsGroup->addButton(ui->codeAreaWidget, 1);
    labelsGroup->addButton(ui->grabItemWidget, 2);
    labelsGroup->addButton(ui->marqueeWidget, 3);
    labelsGroup->addButton(ui->roundAnimationLabel, 4);
    labelsGroup->addButton(ui->splitItemLabel, 5);
    labelsGroup->addButton(ui->toastLabel, 6);
    labelsGroup->addButton(ui->transitionAnimationLabel, 7);
    connect(labelsGroup, SIGNAL(buttonClicked(int)), SLOT(labelModuleChanged(int)));
    //
    QButtonGroup *metersGroup = new QButtonGroup(this);
    metersGroup->addButton(ui->paintMeterWidget, 0);
    metersGroup->addButton(ui->radarMeterWidget, 1);
    metersGroup->addButton(ui->speedMeterWidget, 2);
    metersGroup->addButton(ui->timeMeterWidget, 3);
    connect(metersGroup, SIGNAL(buttonClicked(int)), SLOT(meterModuleChanged(int)));
    //
    QButtonGroup *progressGroup = new QButtonGroup(this);
    progressGroup->addButton(ui->animationProgressWidget, 0);
    progressGroup->addButton(ui->circularProgressWidget, 1);
    progressGroup->addButton(ui->gifLabelWidget, 2);
    progressGroup->addButton(ui->progressCircleWidget, 3);
    progressGroup->addButton(ui->progressWidget, 4);
    progressGroup->addButton(ui->radiusProgressWidget, 5);
    progressGroup->addButton(ui->ringsMapProgressWidget, 6);
    progressGroup->addButton(ui->ringsProgressWidget, 7);
    progressGroup->addButton(ui->roundProgressWidget, 8);
    connect(progressGroup, SIGNAL(buttonClicked(int)), SLOT(progressModuleChanged(int)));
    //
    QButtonGroup *slidersGroup = new QButtonGroup(this);
    slidersGroup->addButton(ui->movingLabelSlider, 0);
    slidersGroup->addButton(ui->shiningSlider, 1);
    slidersGroup->addButton(ui->sliderWidget, 2);
    connect(slidersGroup, SIGNAL(buttonClicked(int)), SLOT(sliderModuleChanged(int)));
    //
    QButtonGroup *titlesGroup = new QButtonGroup(this);
    titlesGroup->addButton(ui->functionAnimationHWidget, 0);
    titlesGroup->addButton(ui->functionAnimationVWidget, 1);
    titlesGroup->addButton(ui->functionListHWidget, 2);
    titlesGroup->addButton(ui->functionListVWidget, 3);
    titlesGroup->addButton(ui->functionToolboxWidget, 4);
    connect(titlesGroup, SIGNAL(buttonClicked(int)), SLOT(titleModuleChanged(int)));
    //
    QButtonGroup *widgetsGroup = new QButtonGroup(this);
    widgetsGroup->addButton(ui->animationStackedWidget, 0);
    widgetsGroup->addButton(ui->animation2StackedWidget, 1);
    widgetsGroup->addButton(ui->colorTablePlane, 2);
    widgetsGroup->addButton(ui->layoutAnimationWidget, 3);
    widgetsGroup->addButton(ui->lineEditWidget, 4);
    widgetsGroup->addButton(ui->pictureBannerWidget, 5);
    widgetsGroup->addButton(ui->pictureFlowWidget, 6);
    widgetsGroup->addButton(ui->smoothMovingTableWidget, 7);
    connect(widgetsGroup, SIGNAL(buttonClicked(int)), SLOT(widgetModuleChanged(int)));
    //
    QButtonGroup *windowsGroup = new QButtonGroup(this);
    windowsGroup->addButton(ui->colorDialog, 0);
    windowsGroup->addButton(ui->moveDialog, 1);
    windowsGroup->addButton(ui->moveResizeWidget, 2);
    windowsGroup->addButton(ui->moveWidget, 3);
    connect(windowsGroup, SIGNAL(buttonClicked(int)), SLOT(windowModuleChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonModuleChanged(int index)
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

void MainWindow::labelModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKCircleClickPlaneWindow(this))->show();
            break;
        case 1: (new TTKCodeAreaWindow(this))->show();
            break;
        case 2: (new TTKGrabItemWindow(this))->show();
            break;
        case 3: (new TTKMarqueeWindow(this))->show();
            break;
        case 4: (new TTKRoundAnimationWindow(this))->show();
            break;
        case 5: (new TTKSplitItemWindow(this))->show();
            break;
        case 6: (new TTKToastWindow(this))->show();
            break;
        case 7: (new TTKTransitionAnimationWindow(this))->show();
            break;
        default:
            break;
    }
}

void MainWindow::meterModuleChanged(int index)
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

void MainWindow::progressModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKAnimationProgressWindow(this))->show();
            break;
        case 1: (new TTKCircularProgressWindow(this))->show();
            break;
        case 2: (new TTKGifLabelWindow(this))->show();
            break;
        case 3: (new TTKProgressCircleWindow(this))->show();
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
        default:
            break;
    }
}

void MainWindow::sliderModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKMovingLabelWindow(this))->show();
            break;
        case 1: (new TTKShiningSliderWindow(this))->show();
            break;
        case 2: (new TTKSliderWindow(this))->show();
            break;
        default:
            break;
    }
}

void MainWindow::titleModuleChanged(int index)
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
        default:
            break;
    }
}

void MainWindow::widgetModuleChanged(int index)
{
    switch(index)
    {
        case 0: (new TTKAnimationStackedWindow(this))->show();
            break;
        case 1: (new TTKAnimation2StackedWindow(this))->show();
            break;
        case 2: (new TTKColorTablePlaneWindow(this))->show();
            break;
        case 3: (new TTKLayoutAnimationWindow(this))->show();
            break;
        case 4: (new TTKLineEditWindow(this))->show();
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


void MainWindow::windowModuleChanged(int index)
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
