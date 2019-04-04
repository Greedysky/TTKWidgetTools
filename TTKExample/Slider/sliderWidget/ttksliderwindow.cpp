#include "ttksliderwindow.h"
#include "ui_ttksliderwindow.h"

TTKSliderWindow::TTKSliderWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKSliderWindow)
{
    ui->setupUi(this);

    ui->widget->setOrientation(Qt::Horizontal);

}

TTKSliderWindow::~TTKSliderWindow()
{
    delete ui;
}
