#include "ttkfunctionanimationhwindow.h"
#include "ui_ttkfunctionanimationhwindow.h"

TTKFunctionAnimationHWindow::TTKFunctionAnimationHWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionAnimationHWindow)
{
    ui->setupUi(this);

    ui->widget_4->setAlignment(TTKBaseAnimationWidget::Top);
    ui->widget_5->setAlignment(TTKBaseAnimationWidget::Top);
    ui->widget_6->setAlignment(TTKBaseAnimationWidget::Top);

}

TTKFunctionAnimationHWindow::~TTKFunctionAnimationHWindow()
{
    delete ui;
}
