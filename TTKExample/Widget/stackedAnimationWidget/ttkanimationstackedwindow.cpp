#include "ttkanimationstackedwindow.h"
#include "ui_ttkanimationstackedwindow.h"

TTKAnimationStackedWindow::TTKAnimationStackedWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKAnimationStackedWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setLength(200, TTKAnimationStackedWidget::LeftToRight);
    ui->stackedWidget_2->setLength(200, TTKAnimationStackedWidget::RightToLeft);
    ui->stackedWidget_3->setLength(100, TTKAnimationStackedWidget::TopToBottom);
    ui->stackedWidget_4->setLength(100, TTKAnimationStackedWidget::BottomToTop);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changeToFirst()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(changeToSecond()));
}

TTKAnimationStackedWindow::~TTKAnimationStackedWindow()
{
    delete ui;
}

void TTKAnimationStackedWindow::changeToFirst()
{
    ui->stackedWidget->start(0);
    ui->stackedWidget_2->start(0);
    ui->stackedWidget_3->start(0);
    ui->stackedWidget_4->start(0);
}

void TTKAnimationStackedWindow::changeToSecond()
{
    ui->stackedWidget->start(1);
    ui->stackedWidget_2->start(1);
    ui->stackedWidget_3->start(1);
    ui->stackedWidget_4->start(1);
}
