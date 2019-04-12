#include "ttktoolmenuwindow.h"
#include "ui_ttktoolmenuwindow.h"

TTKToolMenuWindow::TTKToolMenuWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKToolMenuWindow)
{
    ui->setupUi(this);
}

TTKToolMenuWindow::~TTKToolMenuWindow()
{
    delete ui;
}
