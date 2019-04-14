#include "ttkmovedialogwindow.h"
#include "ui_ttkmovedialogwindow.h"
#include "ttkmovedialog.h"

TTKMoveDialogWindow::TTKMoveDialogWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMoveDialogWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);
    m_widget = nullptr;

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changed()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(closeWidget()));
}

TTKMoveDialogWindow::~TTKMoveDialogWindow()
{
    delete ui;
    closeWidget();
}

void TTKMoveDialogWindow::changed()
{
    if(!m_widget)
    {
        m_widget = new TTKMoveDialog(false);
        m_widget->resize(200, 200);
    }
    m_widget->show();
}

void TTKMoveDialogWindow::closeWidget()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = nullptr;
    }
}
