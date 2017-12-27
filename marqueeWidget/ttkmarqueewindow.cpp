#include "ttkmarqueewindow.h"
#include "ui_ttkmarqueewindow.h"

TTKMarqueeWindow::TTKMarqueeWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMarqueeWindow)
{
    ui->setupUi(this);

    ui->widget->setText("Hello World!");
}

TTKMarqueeWindow::~TTKMarqueeWindow()
{
    delete ui;
}
