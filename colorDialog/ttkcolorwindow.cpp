#include "ttkcolorwindow.h"
#include "ui_ttkcolorwindow.h"

TTKColorWindow::TTKColorWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKColorWindow)
{
    ui->setupUi(this);

    connect(ui->wgtPalette, SIGNAL(colorChanged(QColor)), ui->wgtSaturationIndicator, SLOT(setBaseColor(QColor)));
    connect(ui->wgtSaturationIndicator, SIGNAL(saturationChanged(double)), ui->wgtPalette, SLOT(setSaturation(double)));

    ui->wgtPalette->init();
}

TTKColorWindow::~TTKColorWindow()
{
    delete ui;
}
