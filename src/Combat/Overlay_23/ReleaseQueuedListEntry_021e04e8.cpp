#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);
extern "C" void func_ov023_021e20f0(void* p, void* obj, int a, int b);

extern "C" void func_ov023_021dbd10(void* obj, void* p);

struct StructField8Nibble04e8 {
    char pad[8];
    unsigned int nibble : 4;
};

// USA: func_ov023_021e04e8  (semantic: ReleaseQueuedListEntry_021e04e8)
extern "C" ARM int func_ov023_021e04e8(void* obj) {
    if (*(int*)((char*)obj + 0x73c) == -1) {
        void* p4c = *(void**)((char*)obj + 0x4c);
        if (p4c != 0) {
            func_ov023_021dbd10((char*)obj + 0xcc, p4c);
        }
        return 7;
    }

    int listPtr = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(*(int*)((char*)obj + 0x73c)))) {
        int out1, out2;
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(*(int*)((char*)obj + 0x73c)), (void**)(&out1), (unsigned int*)(&out2));

        if (out1 != 0 && out2 != 0) {
            _ZN13SafeAllocator5ResetEv(obj);
            func_ov023_021e20f0((char*)obj + 0xcc, obj, out1, out2);
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(int*)((char*)obj + 0x73c)));
        *(int*)((char*)obj + 0x73c) = -1;

        void* p4c2 = *(void**)((char*)obj + 0x4c);
        if (p4c2 != 0) {
            func_ov023_021dbd10((char*)obj + 0xcc, p4c2);
            int cond = ((struct StructField8Nibble04e8*)*(void**)((char*)obj + 0x4c))->nibble <= 7;
            *(unsigned char*)((char*)obj + 0x79a) = cond != 0;
        }

        return 7;
    }

    return 5;
}
