#include "ttksmoothmovingtablewindow.h"
#include "ui_ttksmoothmovingtablewindow.h"

TTKSmoothMovingTableWindow::TTKSmoothMovingTableWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKSmoothMovingTableWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(500);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *it = new QTableWidgetItem(QString::number(i));
        ui->tableWidget->setItem(i, 0, it);
    }
    ui->tableWidget->setMovedScrollBar(ui->tableWidget->verticalScrollBar());
}

TTKSmoothMovingTableWindow::~TTKSmoothMovingTableWindow()
{
    delete ui;
}
