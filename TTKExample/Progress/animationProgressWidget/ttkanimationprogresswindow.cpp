#include "ttkanimationprogresswindow.h"
#include "ui_ttkanimationprogresswindow.h"

TTKAnimationProgressWindow::TTKAnimationProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKAnimationProgressWindow)
{
    ui->setupUi(this);

    ui->label->start();
}

TTKAnimationProgressWindow::~TTKAnimationProgressWindow()
{
    delete ui;
}
