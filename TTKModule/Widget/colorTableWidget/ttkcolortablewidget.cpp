#include "ttkcolortablewidget.h"
#include "ttkregularexpression.h"

#include <QFile>

TTKColorTableWidget::TTKColorTableWidget(QWidget *parent)
    : QListWidget(parent)
{

}

void TTKColorTableWidget::initialize()
{
    QFile file(":/res/rgb");
    if(file.open(QIODevice::ReadOnly))
    {
        const QStringList items(QString(file.readAll()).split(TTK_LINEFEED, QtSkipEmptyParts));
        for(const QString &item : qAsConst(items))
        {
            QListWidgetItem *it = new QListWidgetItem(this);
            it->setText(item);

            TTKRegularExpression regx("RGB\\[(\\d+),(\\d+),(\\d+)\\]");
            int pos = 0;
            do
            {
                pos = regx.match(item, pos);
                if(pos < 0)
                {
                    break;
                }

                it->setBackground(QColor(regx.captured(1).toInt(),
                                         regx.captured(2).toInt(),
                                         regx.captured(3).toInt()));
                pos += regx.capturedLength();
            } while(pos < item.length());

            addItem(it);
        }
        file.close();
    }
}
