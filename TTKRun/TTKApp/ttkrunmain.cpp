#include "ttkrunobject.h"

#ifdef _MSC_VER // do not show console window
#  pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

int main(int argc, char *argv[])
{
    TTKRunObject object;
    object.execute(argc, argv);
    return EXIT_SUCCESS;
}
