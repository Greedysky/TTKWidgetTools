#include "ttkcircularprogresswindow.h"
#include "ui_ttkcircularprogresswindow.h"

TTKCircularProgressWindow::TTKCircularProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCircularProgressWindow)
{
    ui->setupUi(this);

    ui->widget->setSize(64);
    ui->widget->setColor(QColor(255, 0, 0));

    ui->widget_2->setLineWidth(8);
    ui->widget_2->setSize(74);
    ui->widget_2->setColor(QColor(0, 255, 0));

    ui->widget_3->setLineWidth(13);
    ui->widget_3->setSize(84);
    ui->widget_3->setColor(QColor(0, 0, 255));

}

TTKCircularProgressWindow::~TTKCircularProgressWindow()
{
    delete ui;
}
