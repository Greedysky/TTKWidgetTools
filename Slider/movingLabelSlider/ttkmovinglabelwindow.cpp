#include "ttkmovinglabelwindow.h"
#include "ui_ttkmovinglabelwindow.h"

TTKMovingLabelWindow::TTKMovingLabelWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMovingLabelWindow)
{
    ui->setupUi(this);

    TTKMovingLabelSlider *v = new TTKMovingLabelSlider(Qt::Vertical, this);
    ui->verticalLayout->addWidget(v);

    ui->horizontalSlider->setRange(0, 1000000);
    v->setRange(0, 1000000);
}

TTKMovingLabelWindow::~TTKMovingLabelWindow()
{
    delete ui;
}
