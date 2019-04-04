#include "ttkmovedialogwindow.h"
#include "ui_ttkmovedialogwindow.h"
#include "ttkmovedialog.h"

TTKMoveDialogWindow::TTKMoveDialogWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveDialogWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
}

TTKMoveDialogWindow::~TTKMoveDialogWindow()
{
    delete ui;
}

void TTKMoveDialogWindow::changed()
{
    TTKMoveDialog w(false);
    w.resize(200, 200);
    w.exec();
}
