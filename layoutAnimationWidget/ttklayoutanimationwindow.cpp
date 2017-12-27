#include "ttklayoutanimationwindow.h"
#include "ui_ttklayoutanimationwindow.h"

TTKLayoutAnimationWindow::TTKLayoutAnimationWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKLayoutAnimationWindow)
{
    ui->setupUi(this);

    QWidget *o = new QWidget(this);
    o->setStyleSheet("background:red");
    QWidget *t = new QWidget(this);
    t->setStyleSheet("background:yellow");
    ui->widget->addWidget(o);
    ui->widget->addWidget(t);

    ui->widget->start();
}

TTKLayoutAnimationWindow::~TTKLayoutAnimationWindow()
{
    delete ui;
}
