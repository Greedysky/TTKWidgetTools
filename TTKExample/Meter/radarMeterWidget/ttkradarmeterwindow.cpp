#include "ttkradarmeterwindow.h"
#include "ui_ttkradarmeterwindow.h"

TTKRadarMeterWindow::TTKRadarMeterWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRadarMeterWindow)
{
    ui->setupUi(this);
}

TTKRadarMeterWindow::~TTKRadarMeterWindow()
{
    delete ui;
}
