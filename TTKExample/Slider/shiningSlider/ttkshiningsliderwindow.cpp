#include "ttkshiningsliderwindow.h"
#include "ui_ttkshiningsliderwindow.h"

TTKShiningSliderWindow::TTKShiningSliderWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKShiningSliderWindow)
{
    ui->setupUi(this);

    ui->widget->setRange(0, 2000);
    ui->widget->setValue(1000);
    ui->widget->setPlayState(true);
}

TTKShiningSliderWindow::~TTKShiningSliderWindow()
{
    delete ui;
}
