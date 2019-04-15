#include "ttkfunctionnormalwindow.h"
#include "ui_ttkfunctionnormalwindow.h"

TTKFunctionNormalWindow::TTKFunctionNormalWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionNormalWindow)
{
    ui->setupUi(this);

    ui->widget_1->setSize(200, 200);
    ui->widget_1->addItem("11111111");
    ui->widget_1->addItem("22222222");
    ui->widget_1->addItem("33333333");
    ui->widget_1->addItem("44444444");
    ui->widget_1->addItem("55555555");
}

TTKFunctionNormalWindow::~TTKFunctionNormalWindow()
{
    delete ui;
}
