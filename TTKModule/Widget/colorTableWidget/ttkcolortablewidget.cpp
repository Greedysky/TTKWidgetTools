#include "ttkcolortablewidget.h"

#include <QFile>
#if TTK_QT_VERSION_CHECK(5,0,0)
#  include <QRegularExpression>
#else
#  include <QRegExp>
#endif

TTKColorTableWidget::TTKColorTableWidget(QWidget *parent)
    : QListWidget(parent)
{

}

void TTKColorTableWidget::initialize()
{
    QFile file(":/res/rgb");
    if(file.open(QFile::ReadOnly))
    {
        const QStringList items(QString(file.readAll()).split("\n"));
        for(const QString &item : qAsConst(items))
        {
            QListWidgetItem *it = new QListWidgetItem(this);
            it->setText(item);

            const QString pattern("RGB\\[(\\d+),(\\d+),(\\d+)\\]");
#if TTK_QT_VERSION_CHECK(5,0,0)
            QRegularExpression regx(pattern);
            int pos = 0;
            do
            {
                QRegularExpressionMatch match = regx.match(item, pos);
                if(!match.hasMatch())
                {
                    break;
                }

                it->setBackground(QColor(match.captured(1).toInt(),
                                         match.captured(2).toInt(),
                                         match.captured(3).toInt()));
                pos = match.capturedEnd();
            } while(pos < item.length());
#else
            QRegExp regx(pattern);
            int pos = 0;
            while((pos = regx.indexIn(item , pos)) != -1)
            {
                it->setBackground(QColor(regx.cap(1).toInt(),
                                         regx.cap(2).toInt(),
                                         regx.cap(3).toInt()));
                pos += regx.matchedLength();
            }
#endif
            addItem(it);
        }
        file.close();
    }
}
