#include "ttkfunctiontoolboxwindow.h"
#include "ui_ttkfunctiontoolboxwindow.h"

TTKFunctionToolBoxWindow::TTKFunctionToolBoxWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionToolBoxWindow)
{
    ui->setupUi(this);

    QWidget *red = new QWidget(this);
    red->setStyleSheet("background:red");
    red->setFixedHeight(100);
    ui->widget->addItem(red, "red");

    QWidget *blue = new QWidget(this);
    blue->setStyleSheet("background:blue");
    blue->setFixedHeight(100);
    ui->widget->addItem(blue, "blue");

    QWidget *yellow = new QWidget(this);
    yellow->setStyleSheet("background:yellow");
    yellow->setFixedHeight(100);
    ui->widget->addItem(yellow, "yellow");
}

TTKFunctionToolBoxWindow::~TTKFunctionToolBoxWindow()
{
    delete ui;
}
