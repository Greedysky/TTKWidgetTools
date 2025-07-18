#include "ttkapplication.h"
#include "ttktoolsapplication.h"
#include "ttkobject.h"
#include "ttkdumper.h"
#include "ttkdesktopscreen.h"
#include "ttkglobalinterface.h"

#ifdef Q_OS_LINUX
#  include <malloc.h>
#endif

#include <QTextCodec>

static void loadApplicationScaleFactor()
{
#if TTK_QT_VERSION_CHECK(6,0,0)
   // do nothing
#elif TTK_QT_VERSION_CHECK(5,4,0)
#  if TTK_QT_VERSION_CHECK(5,12,0)
      QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
      QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#    if TTK_QT_VERSION_CHECK(5,14,0)
        QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#    endif
#  elif TTK_QT_VERSION_CHECK(5,6,0)
      const float dpi = TTKDesktopScreen::dotsPerInch() / 96.0;
      qputenv("QT_SCALE_FACTOR", QByteArray::number(dpi < 1.0 ? 1.0 : dpi));
#  endif
#endif
}

int main(int argc, char *argv[])
{
    loadApplicationScaleFactor();

    TTKApplication app(argc, argv);

    QCoreApplication::setOrganizationName(TTK_APP_NAME);
    QCoreApplication::setOrganizationDomain(TTK_APP_COME_NAME);
    QCoreApplication::setApplicationName(TTK_APP_NAME);

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return EXIT_FAILURE;
    }

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#if !TTK_QT_VERSION_CHECK(5,0,0)
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    TTKDumper dumper;
    dumper.execute();

    TTK::setApplicationFont();

    TTKToolsApplication w;
    w.show();

#ifdef Q_OS_LINUX
    // memory free
    mallopt(M_MMAP_THRESHOLD, 1024 * 1024);   // 1MB mmap
    mallopt(M_TRIM_THRESHOLD, 2 * 1024 * 1024); // 2MB brk
#endif
    return app.exec();
}
