#include "ttkroundprogresswindow.h"
#include "ui_ttkroundprogresswindow.h"

#include <QTimer>

TTKRoundProgressWindow::TTKRoundProgressWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKRoundProgressWindow)
{
    ui->setupUi(this);

    ui->label->setOutterBarWidth(20);
    ui->label->setInnerBarWidth(20);
    ui->label->setControlFlags(TTKRoundProgressWidget::All);

    ui->label2->setInnerDefaultTextStyle(TTKRoundProgressWidget::ValueAndMax);
    ui->label2->setOutterBarWidth(12);
    ui->label2->setInnerBarWidth(20);
    ui->label2->setOutterColor(QColor(150, 50, 240));
    ui->label2->setDefaultTextColor(QColor(255, 190, 57));
    ui->label2->setInnerColor(QColor(255, 190, 57), QColor(255, 230, 129));
    ui->label2->setControlFlags(TTKRoundProgressWidget::All);

    ui->label3->setInnerDefaultTextStyle(TTKRoundProgressWidget::Value);
    ui->label3->setOutterBarWidth(4);
    ui->label3->setInnerBarWidth(20);
    ui->label3->setOutterColor(QColor(250, 55, 56));
    ui->label3->setDefaultTextColor(QColor(255, 19, 157));
    ui->label3->setInnerColor(QColor(255, 19, 157), QColor(255, 230, 129));
    ui->label3->setControlFlags(TTKRoundProgressWidget::All);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->start(1000);
}

TTKRoundProgressWindow::~TTKRoundProgressWindow()
{
    delete ui;
}

void TTKRoundProgressWindow::updateRender()
{
    ui->label->setText(qrand() % 100 + 1);
    ui->label2->setText(qrand() % 100 + 1);
    ui->label3->setText(qrand() % 100 + 1);
}
