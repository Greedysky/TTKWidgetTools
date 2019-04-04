#include "ttkfunctionlisthwindow.h"
#include "ui_ttkfunctionlisthwindow.h"

TTKFunctionListHWindow::TTKFunctionListHWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionListHWindow)
{
    ui->setupUi(this);

}

TTKFunctionListHWindow::~TTKFunctionListHWindow()
{
    delete ui;
}
