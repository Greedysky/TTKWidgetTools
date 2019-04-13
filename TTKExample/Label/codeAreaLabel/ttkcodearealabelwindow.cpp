#include "ttkcodearealabelwindow.h"
#include "ui_ttkcodearealabelwindow.h"

TTKCodeAreaLabelWindow::TTKCodeAreaLabelWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCodeAreaLabelWindow)
{
    ui->setupUi(this);

    ui->label->setCodeCount(6);
    ui->label->setNoisyPointCount(200);
    ui->label->renderPicture();
}

TTKCodeAreaLabelWindow::~TTKCodeAreaLabelWindow()
{
    delete ui;
}
