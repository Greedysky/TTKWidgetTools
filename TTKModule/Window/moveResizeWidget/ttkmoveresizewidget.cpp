#include "ttkmoveresizewidget.h"

TTKMoveResizeWidget::TTKMoveResizeWidget(QWidget *parent)
    : TTKAbstractMoveResizeWidget(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, false);
}
