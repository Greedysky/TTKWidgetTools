#include "ttkfunctionlistwindow.h"
#include "ui_ttkfunctionlistwindow.h"

TTKFunctionListWindow::TTKFunctionListWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionListWindow)
{
    ui->setupUi(this);

}

TTKFunctionListWindow::~TTKFunctionListWindow()
{
    delete ui;
}
