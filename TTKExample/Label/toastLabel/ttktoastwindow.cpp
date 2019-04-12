#include "ttktoastwindow.h"
#include "ui_ttktoastwindow.h"
#include "ttktoastlabel.h"

TTKToastWindow::TTKToastWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKToastWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
}

TTKToastWindow::~TTKToastWindow()
{
    delete ui;
}

void TTKToastWindow::changed()
{
    TTKToastLabel *toast = new TTKToastLabel(this);
    toast->setFontSize(15);
    toast->setFontMargin(20, 20);
    toast->setText(tr("Hello World!"));
    toast->popup(this);
}
