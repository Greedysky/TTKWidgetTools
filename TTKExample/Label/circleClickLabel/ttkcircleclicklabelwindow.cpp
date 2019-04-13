#include "ttkcircleclicklabelwindow.h"
#include "ui_ttkcircleclicklabelwindow.h"

TTKCircleClickLabelWindow::TTKCircleClickLabelWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCircleClickLabelWindow)
{
    ui->setupUi(this);
}

TTKCircleClickLabelWindow::~TTKCircleClickLabelWindow()
{
    delete ui;
}
