#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

struct StreamHeader;
void InitAndRunScriptIfValid02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3);

extern "C" {
}

extern int data_020f14ec;

struct Obj02097a04 {
    char pad0[0x18];
    int f18;
    unsigned char f1c;
    unsigned char f1d;
};

// USA: func_02097a04  (semantic: TryRunPendingScript02097a04)
extern "C" ARM int func_02097a04(struct Obj02097a04* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    unsigned char f1c = obj->f1c;
    if (f1c == 0) {
        obj->f18 = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)&data_020f14ec), (SafeAllocator*)(0));
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
            InitAndRunScriptIfValid02097ac0(obj, (void*)obj->f1d, (struct StreamHeader*)out1, out2);
        }
    }
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->f18));
    obj->f18 = -1;
    obj->f1c = 0;
    return 1;
ret0:
    return 0;
}
