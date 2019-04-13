#include "ttkcolortablewindow.h"
#include "ui_ttkcolortablewindow.h"

TTKColorTableWindow::TTKColorTableWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKColorTableWindow)
{
    ui->setupUi(this);

    ui->widget->init();

}

TTKColorTableWindow::~TTKColorTableWindow()
{
    delete ui;
}
