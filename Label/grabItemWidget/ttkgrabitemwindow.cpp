#include "ttkgrabitemwindow.h"
#include "ui_ttkgrabitemwindow.h"

TTKGrabItemWindow::TTKGrabItemWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKGrabItemWindow)
{
    ui->setupUi(this);
}

TTKGrabItemWindow::~TTKGrabItemWindow()
{
    delete ui;
}
