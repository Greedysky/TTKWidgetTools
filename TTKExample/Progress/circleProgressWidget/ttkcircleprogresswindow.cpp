#include "ttkcircleprogresswindow.h"
#include "ui_ttkcircleprogresswindow.h"

TTKCircleProgressWindow::TTKCircleProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCircleProgressWindow)
{
    ui->setupUi(this);

    ui->widget_2->setInnerRadius(0.5);
    ui->widget_2->setOuterRadius(1.0);
    ui->widget_2->setColor(QColor(255, 0, 0));

    ui->widget_3->setInnerRadius(0.9);
    ui->widget_3->setOuterRadius(1.0);
    ui->widget_3->setColor(QColor(0, 0, 255));
}

TTKCircleProgressWindow::~TTKCircleProgressWindow()
{
    delete ui;
}
