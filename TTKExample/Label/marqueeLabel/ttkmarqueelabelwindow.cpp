#include "ttkmarqueelabelwindow.h"
#include "ui_ttkmarqueelabelwindow.h"

TTKMarqueeLabelWindow::TTKMarqueeLabelWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMarqueeLabelWindow)
{
    ui->setupUi(this);

    ui->widget->setText("Hello World!");
}

TTKMarqueeLabelWindow::~TTKMarqueeLabelWindow()
{
    delete ui;
}
