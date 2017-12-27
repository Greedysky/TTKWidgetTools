#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>

#include "stackedAnimationWidget/ttkanimationstackedwindow.h"
#include "transitionAnimationLabel/ttktransitionanimationwindow.h"
#include "gifLabelWidget/ttkgiflabelwindow.h"
#include "codeAreaWidget/ttkcodeareawindow.h"
#include "toastLabel/ttktoastwindow.h"
#include "marqueeWidget/ttkmarqueewindow.h"
#include "roundAnimationLabel/ttkroundanimationwindow.h"
#include "movingLabelSlider/ttkmovinglabelwindow.h"

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
        default:
            break;
    }
}
