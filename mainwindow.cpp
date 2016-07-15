#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setLength(200, AnimationStackedWidget::LeftToRight);
    ui->stackedWidget_2->setLength(200, AnimationStackedWidget::RightToLeft);
    ui->stackedWidget_3->setLength(100, AnimationStackedWidget::TopToBottom);
    ui->stackedWidget_4->setLength(100, AnimationStackedWidget::BottomToTop);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changeToFirst()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(changeToSecond()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeToFirst()
{
    ui->stackedWidget->start(0);
    ui->stackedWidget_2->start(0);
    ui->stackedWidget_3->start(0);
    ui->stackedWidget_4->start(0);
}

void MainWindow::changeToSecond()
{
    ui->stackedWidget->start(1);
    ui->stackedWidget_2->start(1);
    ui->stackedWidget_3->start(1);
    ui->stackedWidget_4->start(1);
}
