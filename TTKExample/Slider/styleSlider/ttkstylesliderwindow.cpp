#include "ttkstylesliderwindow.h"
#include "ui_ttkstylesliderwindow.h"

TTKStyleSliderWindow::TTKStyleSliderWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKStyleSliderWindow)
{
    ui->setupUi(this);

    ui->widget->setOrientation(Qt::Horizontal);

}

TTKStyleSliderWindow::~TTKStyleSliderWindow()
{
    delete ui;
}
