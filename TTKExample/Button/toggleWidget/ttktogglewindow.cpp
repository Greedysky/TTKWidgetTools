#include "ttktogglewindow.h"
#include "ui_ttktogglewindow.h"

TTKToggleWindow::TTKToggleWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKToggleWindow)
{
    ui->setupUi(this);

    ui->widget->setDisabledColor(QColor(0, 0, 0));
    ui->widget->setActiveColor(QColor(255, 0, 0));
    ui->widget->setInactiveColor(QColor(0, 255, 0));
    ui->widget->setTrackColor(QColor(0, 0, 255));

    ui->widget_2->setDisabledColor(QColor(0, 0, 0));
    ui->widget_2->setActiveColor(QColor(255, 255, 0));
    ui->widget_2->setInactiveColor(QColor(0, 255, 255));
    ui->widget_2->setTrackColor(QColor(255, 0, 255));

    ui->widget_3->setOrientation(Qt::Vertical);
    ui->widget_3->setDisabledColor(QColor(0, 0, 0));
    ui->widget_3->setActiveColor(QColor(255, 0, 0));
    ui->widget_3->setInactiveColor(QColor(0, 255, 0));
    ui->widget_3->setTrackColor(QColor(0, 0, 255));

    ui->widget_4->setOrientation(Qt::Vertical);
    ui->widget_4->setDisabledColor(QColor(0, 0, 0));
    ui->widget_4->setActiveColor(QColor(255, 255, 0));
    ui->widget_4->setInactiveColor(QColor(0, 255, 255));
    ui->widget_4->setTrackColor(QColor(255, 0, 255));
}

TTKToggleWindow::~TTKToggleWindow()
{
    delete ui;
}
