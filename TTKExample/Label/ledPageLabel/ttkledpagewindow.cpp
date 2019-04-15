#include "ttkledpagewindow.h"
#include "ui_ttkledpagewindow.h"

#include <QTimer>

TTKLedPageWindow::TTKLedPageWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKLedPageWindow)
{
    ui->setupUi(this);

    ui->widget_2->setBackColor(QColor(255, 85, 85));
    ui->widget_2->setLineColor(QColor(250, 250, 250));
    ui->widget_2->setFrontColor(QColor(50, 50, 50));

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->start(1000);
}

TTKLedPageWindow::~TTKLedPageWindow()
{
    delete ui;
}

void TTKLedPageWindow::updateRender()
{
    ui->widget->setText(QString::number(qrand() % 100 + 1));
    ui->widget_2->setText(QString::number(qrand() % 100 + 1));
}
