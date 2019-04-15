#include "ttkringsmapprogresswindow.h"
#include "ui_ttkringsmapprogresswindow.h"

#include <QTimer>

TTKRingsMapProgressWindow::TTKRingsMapProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRingsMapProgressWindow),
    m_value(0)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->start(100);
}

TTKRingsMapProgressWindow::~TTKRingsMapProgressWindow()
{
    delete ui;
}

void TTKRingsMapProgressWindow::updateRender()
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
