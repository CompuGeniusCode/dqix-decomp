#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);

extern char strStrLgBin[];
extern char strStrTxtBin[];
extern char strStrWndBin[];

struct WindowResource {
    char unknown0[0x14];
    int unknown14;
    char unknown18[0x20 - 0x18];
    int langTaskId;
    int textTaskId;
    int windowTaskId;
};

// USA: QueueTextAndWindowFiles
// The file paths in this function's literal pool are "%s_<LG>.bin", "%s_txt.bin" and "%s_wnd.bin".
// All three are queued out of the one GP2 archive the caller names, and their task ids land at
// +0x20, +0x24 and +0x28 in that order -- language, text, window -- the three handles
// ResetWindowElementById's comment identifies this object by; nothing decompiled reads them back,
// and the windows OpenWindowById opens come out of the layout records of the "%s_wnd.bin" one.
// What the second argument means is not established: it is only stored at +0x14 and required
// non-zero, and none of the eight callers, all of them in overlays, is decompiled.
extern "C" ARM void QueueTextAndWindowFiles(struct WindowResource* resource, int unknownArg2, int gp2Path, int baseName) {
    if (unknownArg2 != 0 && gp2Path != 0 && baseName != 0) {
        resource->unknown14 = unknownArg2;
        int loader = (int)BackgroundLoader::GetInstance();
        char windowFileName[0x20];
        __clear(windowFileName, 0x20);
        char textFileName[0x20];
        __clear(textFileName, 0x20);
        char langFileName[0x20];
        __clear(langFileName, 0x20);
        sprintf(langFileName, strStrLgBin, baseName);
        sprintf(textFileName, strStrTxtBin, baseName);
        sprintf(windowFileName, strStrWndBin, baseName);
        resource->langTaskId = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)(gp2Path), (const char*)((int)langFileName), (SafeAllocator*)(0));
        resource->textTaskId = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)(gp2Path), (const char*)((int)textFileName), (SafeAllocator*)(0));
        resource->windowTaskId = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)(gp2Path), (const char*)((int)windowFileName), (SafeAllocator*)(0));
    }
}
