#include "ttkradiusprogresswindow.h"
#include "ui_ttkradiusprogresswindow.h"

#include <QTimer>

TTKRadiusProgressWindow::TTKRadiusProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRadiusProgressWindow),
    m_value(0)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->start(100);
}

TTKRadiusProgressWindow::~TTKRadiusProgressWindow()
{
    delete ui;
}

void TTKRadiusProgressWindow::updateRender()
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
