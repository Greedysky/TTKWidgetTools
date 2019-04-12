#include "ttkradiobuttonwindow.h"
#include "ui_ttkradiobuttonwindow.h"

TTKRadioButtonWindow::TTKRadioButtonWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRadioButtonWindow)
{
    ui->setupUi(this);

    ui->widget->setDisabledColor(QColor(0, 0, 0));
    ui->widget->setCheckedColor(QColor(255, 0, 0));
    ui->widget->setText("Hello World");

    ui->widget_2->setDisabledColor(QColor(0, 0, 0));
    ui->widget_2->setCheckedColor(QColor(255, 0, 0));
    ui->widget_2->setText("Hello World");

    ui->widget_3->setLabelPosition(TTKCheckable::LabelPositionLeft);
    ui->widget_3->setDisabledColor(QColor(0, 0, 0));
    ui->widget_3->setCheckedColor(QColor(255, 0, 0));
    ui->widget_3->setText("Hello World");

    ui->widget_4->setLabelPosition(TTKCheckable::LabelPositionLeft);
    ui->widget_4->setDisabledColor(QColor(0, 0, 0));
    ui->widget_4->setCheckedColor(QColor(255, 0, 0));
    ui->widget_4->setText("Hello World");
}

TTKRadioButtonWindow::~TTKRadioButtonWindow()
{
    delete ui;
}
