#include "ttkpictureflowwindow.h"
#include "ui_ttkpictureflowwindow.h"

TTKPictureFlowWindow::TTKPictureFlowWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKPictureFlowWindow)
{
    ui->setupUi(this);

    QImage img;
    for(int i=0; i<5; i++)
    {
        ui->widget->addSlide(img);
    }

    ui->widget->setSlideSize(QSize(120, 200));
    ui->widget->setCenterIndex(ui->widget->slideCount()/2);
    ui->widget->setBackgroundColor(Qt::white);
}

TTKPictureFlowWindow::~TTKPictureFlowWindow()
{
    delete ui;
}
