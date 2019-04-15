#include "ttkringsprogresswindow.h"
#include "ui_ttkringsprogresswindow.h"

#include <QTimer>

TTKRingsProgressWindow::TTKRingsProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRingsProgressWindow),
    m_value(0)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->start(100);
}

TTKRingsProgressWindow::~TTKRingsProgressWindow()
{
    delete ui;
}

void TTKRingsProgressWindow::updateRender()
{
    if(m_value >= 100)
    {
        m_value = 0;
    }
    else
    {
        m_value += 5;
    }

    ui->label->setValue(m_value);
}
