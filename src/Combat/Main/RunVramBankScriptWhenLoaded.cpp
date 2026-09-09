#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;

struct StreamHeader;
extern "C" void func_02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3);

extern "C" {
}

extern int strDataBinVrambankBin;

struct Obj02097a04 {
    char pad0[0x18];
    int f18;
    unsigned char f1c;
    unsigned char f1d;
};

// USA: RunVramBankScriptWhenLoaded
// The only file path in this function's literal pool is "data/bin/vrambank.bin".
extern "C" ARM int RunVramBankScriptWhenLoaded(struct Obj02097a04* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    unsigned char f1c = obj->f1c;
    if (f1c == 0) {
        obj->f18 = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)&strDataBinVrambankBin), (SafeAllocator*)(0));
        obj->f1c = obj->f1c + 1;
        goto ret0;
    }
    if (f1c != 1 || !((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(obj->f18))) {
        goto ret0;
    }
    {
        int out1, out2;
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(obj->f18), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            func_02097ac0(obj, (void*)obj->f1d, (struct StreamHeader*)out1, out2);
        }
    }
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->f18));
    obj->f18 = -1;
    obj->f1c = 0;
    return 1;
ret0:
    return 0;
}
