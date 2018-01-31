#include "ttklineeditwindow.h"
#include "ui_ttklineeditwindow.h"

TTKLineEditWindow::TTKLineEditWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKLineEditWindow)
{
    ui->setupUi(this);

    ui->widget->setColor(QColor(0, 0, 0));
    ui->widget_2->setColor(QColor(0x52, 0x11, 0x88));
}

TTKLineEditWindow::~TTKLineEditWindow()
{
    delete ui;
}
