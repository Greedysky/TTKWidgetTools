#include "ttkmovewidgetwindow.h"
#include "ui_ttkmovewidgetwindow.h"
#include "ttkmovewidget.h"

TTKMoveWidgetWindow::TTKMoveWidgetWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveWidgetWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);
    m_widget = nullptr;

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(closeWidget()));
}

TTKMoveWidgetWindow::~TTKMoveWidgetWindow()
{
    delete ui;
    closeWidget();
}

void TTKMoveWidgetWindow::changed()
{
    if(!m_widget)
    {
        m_widget = new TTKMoveWidget(false);
        m_widget->resize(200, 200);
    }
    m_widget->show();
}

void TTKMoveWidgetWindow::closeWidget()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = nullptr;
    }
}
