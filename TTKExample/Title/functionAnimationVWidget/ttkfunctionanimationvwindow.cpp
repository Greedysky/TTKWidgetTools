#include "ttkfunctionanimationvwindow.h"
#include "ui_ttkfunctionanimationvwindow.h"

TTKFunctionAnimationVWindow::TTKFunctionAnimationVWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionAnimationVWindow)
{
    ui->setupUi(this);

    ui->widget_4->setAlignment(TTKBaseAnimationWidget::Right);
    ui->widget_5->setAlignment(TTKBaseAnimationWidget::Right);
    ui->widget_6->setAlignment(TTKBaseAnimationWidget::Right);

}

TTKFunctionAnimationVWindow::~TTKFunctionAnimationVWindow()
{
    delete ui;
}
