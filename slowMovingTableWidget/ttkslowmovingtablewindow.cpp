#include "ttkslowmovingtablewindow.h"
#include "ui_ttkslowmovingtablewindow.h"

TTKSlowMovingTableWindow::TTKSlowMovingTableWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKSlowMovingTableWindow)
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

TTKSlowMovingTableWindow::~TTKSlowMovingTableWindow()
{
    delete ui;
}
