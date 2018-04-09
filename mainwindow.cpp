#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ttkwidgettools.h"

#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->pushButton, 0);
    group->addButton(ui->pushButton_1, 1);
    group->addButton(ui->pushButton_2, 2);
    group->addButton(ui->pushButton_3, 3);
    group->addButton(ui->pushButton_4, 4);
    group->addButton(ui->pushButton_5, 5);
    group->addButton(ui->pushButton_6, 6);
    group->addButton(ui->pushButton_7, 7);
    group->addButton(ui->pushButton_8, 8);
    group->addButton(ui->pushButton_9, 9);
    group->addButton(ui->pushButton_10, 10);
    group->addButton(ui->pushButton_11, 11);
    group->addButton(ui->pushButton_12, 12);
    group->addButton(ui->pushButton_13, 13);
    group->addButton(ui->pushButton_14, 14);
    group->addButton(ui->pushButton_15, 15);
    group->addButton(ui->pushButton_16, 16);
    group->addButton(ui->pushButton_17, 17);
    group->addButton(ui->pushButton_18, 18);
    group->addButton(ui->pushButton_19, 19);
    group->addButton(ui->pushButton_20, 20);
    group->addButton(ui->pushButton_21, 21);
    group->addButton(ui->pushButton_22, 22);
    group->addButton(ui->pushButton_23, 23);
    group->addButton(ui->pushButton_24, 24);
    group->addButton(ui->pushButton_25, 25);
    group->addButton(ui->pushButton_26, 26);
    group->addButton(ui->pushButton_27, 27);
    group->addButton(ui->pushButton_28, 28);
    group->addButton(ui->pushButton_29, 29);
    group->addButton(ui->pushButton_30, 30);
    group->addButton(ui->pushButton_31, 31);
    group->addButton(ui->pushButton_32, 32);
    group->addButton(ui->pushButton_33, 33);
    group->addButton(ui->pushButton_34, 34);
    group->addButton(ui->pushButton_35, 35);
    group->addButton(ui->pushButton_36, 36);
    group->addButton(ui->pushButton_37, 37);
    group->addButton(ui->pushButton_38, 38);
    group->addButton(ui->pushButton_39, 39);

    connect(group, SIGNAL(buttonClicked(int)), SLOT(changed(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changed(int index)
{
    switch(index)
    {
        case 0: (new TTKAnimationStackedWindow(this))->show();
            break;
        case 1: (new TTKTransitionAnimationWindow(this))->show();
            break;
        case 2: (new TTKGifLabelWindow(this))->show();
            break;
        case 3: (new TTKCodeAreaWindow(this))->show();
            break;
        case 4: (new TTKToastWindow(this))->show();
            break;
        case 5: (new TTKMarqueeWindow(this))->show();
            break;
        case 6: (new TTKRoundAnimationWindow(this))->show();
            break;
        case 7: (new TTKMovingLabelWindow(this))->show();
            break;
        case 8: (new TTKSmoothMovingTableWindow(this))->show();
            break;
        case 9: (new TTKColorWindow(this))->show();
            break;
        case 10:(new TTKLayoutAnimationWindow(this))->show();
            break;
        case 11:(new TTKShiningSliderWindow(this))->show();
            break;
        case 12:(new TTKSplitItemWindow(this))->show();
            break;
        case 13:(new TTKGrabItemWindow(this))->show();
            break;
        case 14:(new TTKFunctionAnimationHWindow(this))->show();
            break;
        case 15:(new TTKToolMenuWindow(this))->show();
            break;
        case 16:(new TTKMoveDialogWindow(this))->show();
            break;
        case 17:(new TTKMoveWidgetWindow(this))->show();
            break;
        case 18:(new TTKMoveResizeWidgetWindow(this))->show();
            break;
        case 19:(new TTKCircleClickPlaneWindow(this))->show();
            break;
        case 20:(new TTKLineEditWindow(this))->show();
            break;
        case 21:(new TTKToggleWindow(this))->show();
            break;
        case 22:(new TTKRadioButtonWindow(this))->show();
            break;
        case 23:(new TTKCheckButtonWindow(this))->show();
            break;
        case 24:(new TTKProgressWindow(this))->show();
            break;
        case 25:(new TTKFlatButtonWindow(this))->show();
            break;
        case 26:(new TTKCircularProgressWindow(this))->show();
            break;
        case 27:(new TTKSliderWindow(this))->show();
            break;
        case 28:(new TTKColorTablePlaneWindow(this))->show();
            break;
        case 29:(new TTKFunctionAnimationVWindow(this))->show();
            break;
        case 30:(new TTKFunctionListHWindow(this))->show();
            break;
        case 31:(new TTKFunctionListVWindow(this))->show();
            break;
        case 32:(new TTKFunctionToolBoxWindow(this))->show();
            break;
        case 33:(new TTKPictureFlowWindow(this))->show();
            break;
        case 34:(new TTKSpeedMeterWindow(this))->show();
            break;
        case 35:(new TTKTimeMeterWindow(this))->show();
            break;
        case 36:(new TTKPaintMeterWindow(this))->show();
            break;
        case 37:(new TTKRadarMeterWindow(this))->show();
            break;
        case 38:(new TTKPictureBannerWindow(this))->show();
            break;
        case 39:(new TTKProgressCircleWindow(this))->show();
            break;
        default:
            break;
    }
}
