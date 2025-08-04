#include "ttkapplication.h"
#include "ttktoolsapplication.h"
#include "ttkinitialization.h"

int main(int argc, char *argv[])
{
    TTK::loadApplicationScaleFactor();

    TTKApplication app(argc, argv);
    TTKInitialization ttk;

    if(app.isRunning())
    {
        TTK_INFO_STREAM("One app has already run");
        return EXIT_FAILURE;
    }

    ttk.generateFont();
    ttk.codecForLocale();
    ttk.execute();

    TTKToolsApplication w;
    w.show();
    return app.exec();
}
