#include "ttkspeedmeterwindow.h"
#include "ui_ttkspeedmeterwindow.h"

TTKSpeedMeterWindow::TTKSpeedMeterWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKSpeedMeterWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), SLOT(update(int)));

}

TTKSpeedMeterWindow::~TTKSpeedMeterWindow()
{
    delete ui;
}

void TTKSpeedMeterWindow::update(int value)
{
    ui->widget->setValue(value);
}
