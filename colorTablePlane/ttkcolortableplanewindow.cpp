#include "ttkcolortableplanewindow.h"
#include "ui_ttkcolortableplanewindow.h"

TTKColorTablePlaneWindow::TTKColorTablePlaneWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKColorTablePlaneWindow)
{
    ui->setupUi(this);

    ui->widget->init();

}

TTKColorTablePlaneWindow::~TTKColorTablePlaneWindow()
{
    delete ui;
}
