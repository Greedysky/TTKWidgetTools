#include "ttktoolsapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TTKToolsApplication w;
    w.show();

    return a.exec();
}
