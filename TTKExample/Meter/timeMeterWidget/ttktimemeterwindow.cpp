#include "ttktimemeterwindow.h"
#include "ui_ttktimemeterwindow.h"

TTKTimeMeterWindow::TTKTimeMeterWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKTimeMeterWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), SLOT(update(int)));

}

TTKTimeMeterWindow::~TTKTimeMeterWindow()
{
    delete ui;
}

void TTKTimeMeterWindow::update(int value)
{
    ui->widget->setValue(value);
}
