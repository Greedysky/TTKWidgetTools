#include "ttkroundanimationwindow.h"
#include "ui_ttkroundanimationwindow.h"

TTKRoundAnimationWindow::TTKRoundAnimationWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRoundAnimationWindow)
{
    ui->setupUi(this);

    ui->widget->setPixmap(QPixmap(":/res/1"));
    ui->widget->start();
}

TTKRoundAnimationWindow::~TTKRoundAnimationWindow()
{
    delete ui;
}
