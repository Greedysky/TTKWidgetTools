#include "ttkipeditwindow.h"
#include "ui_ttkipeditwindow.h"

TTKIpEditWindow::TTKIpEditWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKIpEditWindow)
{
    ui->setupUi(this);
}

TTKIpEditWindow::~TTKIpEditWindow()
{
    delete ui;
}
