#include "ttkgiflabelwindow.h"
#include "ui_ttkgiflabelwindow.h"

TTKGifLabelWindow::TTKGifLabelWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKGifLabelWindow)
{
    ui->setupUi(this);

    ui->label->setType(TTKGifLabelWidget::Gif_Ballon_White);
    ui->label_2->setType(TTKGifLabelWidget::Gif_Cicle_Blue);
    ui->label_3->setType(TTKGifLabelWidget::Gif_Rice_Font_White);
    ui->label_4->setType(TTKGifLabelWidget::Gif_Rice_Font_Black);
    ui->label_5->setType(TTKGifLabelWidget::Gif_Rice_Font_Black_Big);
    ui->label_6->setType(TTKGifLabelWidget::Gif_Hourglass_White);
    ui->label_7->setType(TTKGifLabelWidget::Gif_Radio_Blue);
    ui->label_8->setType(TTKGifLabelWidget::Gif_Check_Blue);
    ui->label_9->setType(TTKGifLabelWidget::Gif_Record_red);
    ui->label_10->setType(TTKGifLabelWidget::Gif_Close_White);

    ui->label->start();
    ui->label_2->start();
    ui->label_3->start();
    ui->label_4->start();
    ui->label_5->start();
    ui->label_6->start();
    ui->label_7->start();
    ui->label_8->start();
    ui->label_9->start();
    ui->label_10->start();

}

TTKGifLabelWindow::~TTKGifLabelWindow()
{
    delete ui;
}
