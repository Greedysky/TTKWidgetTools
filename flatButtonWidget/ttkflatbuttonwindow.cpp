#include "ttkflatbuttonwindow.h"
#include "ui_ttkflatbuttonwindow.h"

TTKFlatButtonWindow::TTKFlatButtonWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFlatButtonWindow)
{
    ui->setupUi(this);

    QPixmap p(1, 1);
    p.fill(QColor(0, 0, 0));

    ui->widget->setCornerRadius(12);
    ui->widget->setText("Hello World");

    ui->widget_2->setIcon(QIcon(p));
    ui->widget_2->setText("Hello World");

    ui->widget_3->setIcon(QIcon(p));
    ui->widget_3->setIconAlignment(TTKFlatButtonWidget::RightIcon);
    ui->widget_3->setText("Hello World");

    ui->widget_4->setText("Hello World");

}

TTKFlatButtonWindow::~TTKFlatButtonWindow()
{
    delete ui;
}
