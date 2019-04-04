#include "ttkfunctionlistvwindow.h"
#include "ui_ttkfunctionlistvwindow.h"

TTKFunctionListVWindow::TTKFunctionListVWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionListVWindow)
{
    ui->setupUi(this);

}

TTKFunctionListVWindow::~TTKFunctionListVWindow()
{
    delete ui;
}
