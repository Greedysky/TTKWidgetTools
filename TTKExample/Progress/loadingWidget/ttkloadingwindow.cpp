#include "ttkloadingwindow.h"
#include "ui_ttkloadingwindow.h"

TTKLoadingWindow::TTKLoadingWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKLoadingWindow)
{
    ui->setupUi(this);

    ui->label->start();
}

TTKLoadingWindow::~TTKLoadingWindow()
{
    delete ui;
}
