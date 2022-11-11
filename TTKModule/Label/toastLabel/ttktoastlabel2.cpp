#include "ttktoastlabel2.h"

TTKToastLabel2::TTKToastLabel2(QWidget *parent)
    : TTKToastLabel(parent)
{
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_DeleteOnClose, false);
}

TTKToastLabel2::TTKToastLabel2(const QString &text, QWidget *parent)
    : TTKToastLabel(text, parent)
{

}

TTKToastLabel2::~TTKToastLabel2()
{

}
