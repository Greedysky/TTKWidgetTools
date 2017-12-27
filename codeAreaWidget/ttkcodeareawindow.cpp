#include "ttkcodeareawindow.h"
#include "ui_ttkcodeareawindow.h"

TTKCodeAreaWindow::TTKCodeAreaWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCodeAreaWindow)
{
    ui->setupUi(this);

    ui->label->setCodeCount(6);
    ui->label->setNoisyPointCount(200);
    ui->label->renderPicture();
}

TTKCodeAreaWindow::~TTKCodeAreaWindow()
{
    delete ui;
}
