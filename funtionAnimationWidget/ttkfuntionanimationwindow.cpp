#include "ttkfuntionanimationwindow.h"
#include "ui_ttkfuntionanimationwindow.h"

TTKFunctionAnimationWindow::TTKFunctionAnimationWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKFunctionAnimationWindow)
{
    ui->setupUi(this);

    ui->widget_4->setAlignment(TTKBaseAnimationHWidget::Top);
    ui->widget_5->setAlignment(TTKBaseAnimationHWidget::Top);
    ui->widget_6->setAlignment(TTKBaseAnimationHWidget::Top);

}

TTKFunctionAnimationWindow::~TTKFunctionAnimationWindow()
{
    delete ui;
}
