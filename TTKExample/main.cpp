#include "ttkrunapplication.h"
#include "ttktoolsapplication.h"
#include "ttkobject.h"
#include "ttkdumper.h"
#include "ttkglobalhelper.h"
#include "ttkplatformsystem.h"

#include <QTextCodec>

#ifdef Q_OS_UNIX
#  include <malloc.h>
#endif

static void loadAppScaledFactor(int argc, char *argv[])
{
#if TTK_QT_VERSION_CHECK(6,0,0)
   // do nothing
#elif TTK_QT_VERSION_CHECK(5,4,0)
#  if TTK_QT_VERSION_CHECK(5,12,0)
      QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
      QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#    if TTK_QT_VERSION_CHECK(5,14,0)
        QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
#    endif
#  elif TTK_QT_VERSION_CHECK(5,6,0)
      TTKPlatformSystem platform;
      const float dpi = platform.logicalDotsPerInch() / 96.0;
      qputenv("QT_SCALE_FACTOR", QByteArray::number(dpi < 1.0 ? 1.0 : dpi));
#  else
      qputenv("QT_DEVICE_PIXEL_RATIO", "auto");
#  endif
#endif
    Q_UNUSED(argc);
    Q_UNUSED(argv);
}

int main(int argc, char *argv[])
{
    loadAppScaledFactor(argc, argv);

    TTKRunApplication app(argc, argv);

    QCoreApplication::setOrganizationName(TTK_APP_NAME);
    QCoreApplication::setOrganizationDomain(TTK_APP_COME_NAME);
    QCoreApplication::setApplicationName(TTK_APP_NAME);

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return -1;
    }

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#if !TTK_QT_VERSION_CHECK(5,0,0)
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    TTKDumper dumper;
    dumper.run();

    TTK::setApplicationFont(&app);

    TTKToolsApplication w;
    w.show();

#ifdef Q_OS_UNIX
    // memory free
    mallopt(M_MMAP_THRESHOLD, 1024 * 1024);   // 1MB mmap
    mallopt(M_TRIM_THRESHOLD, 2 * 1024 * 1024); // 2MB brk
#endif
    return app.exec();
}
