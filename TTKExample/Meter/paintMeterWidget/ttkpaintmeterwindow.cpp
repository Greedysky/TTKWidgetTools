#include "ttkpaintmeterwindow.h"
#include "ui_ttkpaintmeterwindow.h"

TTKPaintMeterWindow::TTKPaintMeterWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKPaintMeterWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), SLOT(update(int)));

}

TTKPaintMeterWindow::~TTKPaintMeterWindow()
{
    delete ui;
}

void TTKPaintMeterWindow::update(int value)
{
    ui->widget->setValue(value);
}
