#include "ttkprogresswindow.h"
#include "ui_ttkprogresswindow.h"

TTKProgressWindow::TTKProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKProgressWindow)
{
    ui->setupUi(this);

    ui->widget->setProgressColor(QColor(255, 255, 0));
    ui->widget->setBackgroundColor(QColor(200, 200, 200));

}

TTKProgressWindow::~TTKProgressWindow()
{
    delete ui;
}
