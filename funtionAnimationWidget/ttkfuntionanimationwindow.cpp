#include "ttkfuntionanimationwindow.h"
#include "ui_ttkfuntionanimationwindow.h"

TTKFunctionAnimationWindow::TTKFunctionAnimationWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionAnimationWindow)
{
    ui->setupUi(this);
}

TTKFunctionAnimationWindow::~TTKFunctionAnimationWindow()
{
    delete ui;
}
