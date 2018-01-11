#include "ttkcircleclickplanewindow.h"
#include "ui_ttkcircleclickplanewindow.h"

TTKCircleClickPlaneWindow::TTKCircleClickPlaneWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCircleClickPlaneWindow)
{
    ui->setupUi(this);
}

TTKCircleClickPlaneWindow::~TTKCircleClickPlaneWindow()
{
    delete ui;
}
