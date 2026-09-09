#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);

extern char strStrLgBin[];
extern char strStrTxtBin[];
extern char strStrWndBin[];

struct Obj0207f914 {
    char pad0[0x14];
    int field0x14;
    char pad1[0x20 - 0x18];
    int field0x20;
    int field0x24;
    int field0x28;
};

// USA: func_0207f914
// The file paths in this function's literal pool are "%s_<LG>.bin", "%s_txt.bin" and "%s_wnd.bin".
extern "C" ARM void QueueTextAndWindowFiles(struct Obj0207f914* obj, int p1, int p2, int p3) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->field0x14 = p1;
        int field4 = (int)BackgroundLoader::GetInstance();
        char bufA[0x20];
        __clear(bufA, 0x20);
        char bufB[0x20];
        __clear(bufB, 0x20);
        char bufC[0x20];
        __clear(bufC, 0x20);
        sprintf(bufC, strStrLgBin, p3);
        sprintf(bufB, strStrTxtBin, p3);
        sprintf(bufA, strStrWndBin, p3);
        obj->field0x20 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufC), (SafeAllocator*)(0));
        obj->field0x24 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufB), (SafeAllocator*)(0));
        obj->field0x28 = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufA), (SafeAllocator*)(0));
    }
}
