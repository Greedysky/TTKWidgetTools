#include "ttkmoveresizewidgetwindow.h"
#include "ui_ttkmoveresizewidgetwindow.h"
#include "ttkmoveresizewidget.h"

TTKMoveResizeWidgetWindow::TTKMoveResizeWidgetWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveResizeWidgetWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);
    m_widget = nullptr;

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(closeWidget()));
}

TTKMoveResizeWidgetWindow::~TTKMoveResizeWidgetWindow()
{
    delete ui;
    closeWidget();
}

void TTKMoveResizeWidgetWindow::changed()
{
    if(!m_widget)
    {
        m_widget = new TTKMoveResizeWidget;
        m_widget->setStyleSheet("background:black;");
        m_widget->setMinimumSize(50, 50);
        m_widget->setMaximumSize(200, 200);
        m_widget->resize(100, 100);
    }
    m_widget->show();
}

void TTKMoveResizeWidgetWindow::closeWidget()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = nullptr;
    }
}
