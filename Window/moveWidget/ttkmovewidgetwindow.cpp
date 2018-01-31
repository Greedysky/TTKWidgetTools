#include "ttkmovewidgetwindow.h"
#include "ui_ttkmovewidgetwindow.h"
#include "ttkmovewidget.h"

TTKMoveWidgetWindow::TTKMoveWidgetWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveWidgetWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
}

TTKMoveWidgetWindow::~TTKMoveWidgetWindow()
{
    delete ui;
}

void TTKMoveWidgetWindow::changed()
{
    TTKMoveWidget *w = new TTKMoveWidget(false);
    w->resize(200, 200);
    w->show();
}
