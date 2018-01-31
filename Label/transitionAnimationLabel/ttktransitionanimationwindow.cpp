#include "ttktransitionanimationwindow.h"
#include "ui_ttktransitionanimationwindow.h"

TTKTransitionAnimationWindow::TTKTransitionAnimationWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKTransitionAnimationWindow)
{
    ui->setupUi(this);
    m_changed = false;

    ui->label->setPixmap(QPixmap(":/res/1"));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(pixmapChanged()));
}

TTKTransitionAnimationWindow::~TTKTransitionAnimationWindow()
{
    delete ui;
}

void TTKTransitionAnimationWindow::pixmapChanged()
{
    m_changed = !m_changed;
    ui->label->setPixmap(QPixmap(QString(":/res/%1").arg(m_changed ? 2 : 1)));
}
