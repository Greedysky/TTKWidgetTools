#include "ttkanimation2stackedwindow.h"
#include "ui_ttkanimation2stackedwindow.h"

TTKAnimation2StackedWindow::TTKAnimation2StackedWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKAnimation2StackedWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setLength(200, TTKAnimation2StackedWidget::RollInOut);
    ui->stackedWidget_2->setLength(200, TTKAnimation2StackedWidget::FadeInOut);
    ui->stackedWidget_3->setLength(100, TTKAnimation2StackedWidget::BlackInOut);
    ui->stackedWidget_4->setLength(100, TTKAnimation2StackedWidget::SlideInOut);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changeToFirst()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(changeToSecond()));
}

TTKAnimation2StackedWindow::~TTKAnimation2StackedWindow()
{
    delete ui;
}

void TTKAnimation2StackedWindow::changeToFirst()
{
    ui->stackedWidget->start(0);
    ui->stackedWidget_2->start(0);
    ui->stackedWidget_3->start(0);
    ui->stackedWidget_4->start(0);
}

void TTKAnimation2StackedWindow::changeToSecond()
{
    ui->stackedWidget->start(1);
    ui->stackedWidget_2->start(1);
    ui->stackedWidget_3->start(1);
    ui->stackedWidget_4->start(1);
}
