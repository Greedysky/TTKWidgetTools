#include "ttkapplication.h"
#include "ttktoolsapplication.h"
#include "ttkinitialization.h"

int main(int argc, char *argv[])
{
    TTK::initialize(TTK::Attribute::All);

    TTKApplication app(argc, argv);
    TTKInitialization ttk;

    // parse command line args
    QStringList args;
    for(int i = 0; i < argc; ++i)
    {
        const QString &arg = QString::fromLocal8Bit(argv[i]);
        if(ttk.argumentValid(arg))
        {
            args << arg;
        }
    }

    ttk.execute(args);

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return EXIT_FAILURE;
    }

    ttk.generateFont();
    ttk.codecForLocale();

    TTKToolsApplication w;
    w.show();
    return app.exec();
}
