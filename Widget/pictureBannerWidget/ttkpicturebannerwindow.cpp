#include "ttkpicturebannerwindow.h"
#include "ui_ttkpicturebannerwindow.h"

TTKPictureBannerWindow::TTKPictureBannerWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKPictureBannerWindow)
{
    ui->setupUi(this);

    for(int i=0; i<5; i++)
    {
        ui->widget->addPage(QPixmap(QString(":/res/%1").arg(i)));
    }
}

TTKPictureBannerWindow::~TTKPictureBannerWindow()
{
    delete ui;
}
