#include "ttksplititemwindow.h"
#include "ui_ttksplititemwindow.h"

TTKSplitItemWindow::TTKSplitItemWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKSplitItemWindow)
{
    ui->setupUi(this);

    ui->label->setText("Hello - World - Test!");
    connect(ui->label, SIGNAL(changed(QString)), SLOT(changed(QString)));
}

TTKSplitItemWindow::~TTKSplitItemWindow()
{
    delete ui;
}

void TTKSplitItemWindow::changed(const QString &value)
{
    ui->info->setText(ui->info->text() + " " + value);
}
