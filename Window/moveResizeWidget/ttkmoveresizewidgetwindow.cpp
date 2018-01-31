#include "ttkmoveresizewidgetwindow.h"
#include "ui_ttkmoveresizewidgetwindow.h"
#include "ttkmoveresizewidget.h"

TTKMoveResizeWidgetWindow::TTKMoveResizeWidgetWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveResizeWidgetWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
}

TTKMoveResizeWidgetWindow::~TTKMoveResizeWidgetWindow()
{
    delete ui;
}

void TTKMoveResizeWidgetWindow::changed()
{
    TTKMoveResizeWidget *w = new TTKMoveResizeWidget;
    w->setStyleSheet("background:black;");
    w->setMinimumSize(50, 50);
    w->setMaximumSize(200, 200);
    w->resize(100, 100);
    w->show();
}
